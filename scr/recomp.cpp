#include "recomp.h"
#include <stdio.h>
#include <algorithm>
#include <map>
#include <thread>
#include <chrono>
#include <queue>
#include <cstring>
#include <filesystem>
//#include "psx/libcd.h" 
#include "psx/libetc.h"
#include "psx/libapi.h"
#include "psx/gtereg.h"

#include <unordered_map>


namespace fs = std::filesystem;

#include "st/recomp_overlays.inl"

bool g_vsync_pending = false;
uint32_t g_CdReadCbAddr = 0;
uint32_t g_CdReadyCbAddr = 0;
uint32_t g_CdSyncCbAddr = 0;


extern std::map<uint32_t, recomp_func_t> function_table;
extern recomp_context * g_ctx = nullptr;
volatile  uint32_t global_vsync_count = 0;
std::map<uint32_t, recomp_func_t> function_table;

static uint32_t g_interp_target = 0;

//stream data
extern std::unordered_map<uint32_t, uint32_t> g_stream_file_sizes;


struct DirEntry {
    char name[20];
    uint32_t attr;
    uint32_t size;
    uint32_t next;  // для nextfile
    // 40 байт всего
};
static std::vector<std::string> g_dirEntries;
static int g_dirIndex = 0;

extern std::string g_redirectFrom;  // оригинальный путь
extern std::string g_redirectTo;    // перенаправленный путь

// bu00:BESCES-00510SAVE1 → memcard/BESCES-00510SAVE1
std::string McPathToLocal(const char* ps1path) 
{
    const char* name = ps1path;
    if (strncmp(name, "bu00:", 5) == 0 || strncmp(name, "bu10:", 5) == 0)
        name += 5;
    std::string result = name;
    // Убираем пробелы в конце
    while (!result.empty() && (result.back() == ' ' || result.back() == '\0'))
        result.pop_back();
    return std::string(MC_SAVE_DIR) + result;
}

void EnsureMcDir() 
{
    std::filesystem::create_directories(MC_SAVE_DIR);
}



void mips_interpret(uint8_t* rdram, recomp_context* ctx, uint32_t start_pc);
void interp_wrapper(uint8_t* rdram, recomp_context* ctx) {
    mips_interpret(rdram, ctx, g_interp_target);
}




void init_function_table() 
{
    size_t count = sizeof(section_1_text_funcs) / sizeof(FuncEntry);

    for (size_t i = 0; i < count; i++) {
        // Базовый адрес секции кода в PS1 - 0x80010000
        uint32_t ram = 0x80010000 + section_1_text_funcs[i].offset;

        // Маскируем адрес, чтобы игнорировать KSEG (0x80/0xA0/0x00)
        uint32_t phys_addr = ram & 0x1FFFFFFF;

        function_table[phys_addr] = section_1_text_funcs[i].func;
    }

    printf("[CORE] Function table initialized: %zu functions mapped.\n", count);
}

void _recompbcopy(uint8_t* rdram, recomp_context* ctx)
{
    uint32_t function_id = ctx->r9;
    printf("[CORE] Call _recompbcopy 0x%02X (a0: 0x%08X)\n", function_id, ctx->r4);
}


recomp_func_t lookup_recomp_func(uint32_t fvram)
{
    // Отбрасываем сегментные биты перед поиском
    uint32_t phys_addr = fvram & 0x1FFFFFFF;

    if (phys_addr == 0xA0) return ps1_bios_dispatcher_A;
    if (phys_addr == 0xB0) return ps1_bios_dispatcher_B;
    if (phys_addr == 0xC0) return ps1_bios_dispatcher_C;

    // Ищем функцию по физическому адресу
    auto it = function_table.find(phys_addr);
    if (it != function_table.end()) return it->second;

    if (phys_addr >= 0x00180000 && phys_addr <= 0x001FFFFF) {
        g_interp_target = fvram;
        return interp_wrapper;
    }

    printf("[FATAL] JUMP TO NULL OR UNKNOWN: 0x%08X (Phys: 0x%08X)\n", fvram, phys_addr);
    return dummy_safe_func;
}

static bool is_printable_string(const char* s, int max_len = 64) {
    if (!s || *s == '\0') return false;
    for (int i = 0; i < max_len; i++) {
        unsigned char c = (unsigned char)s[i];
        if (c == '\0') return i > 0; // Нашли конец строки, и она не пустая
        if (c < 32 || c > 126) return false; // Встретили непечатный символ (бинарные данные)
    }
    return false; // Строка слишком длинная или не имеет конца
}
void ps1_bios_dispatcher_A(uint8_t* rdram, recomp_context* ctx)
{
    uint32_t func_id = ctx->r9; // $t1

    //(Memory & Strings)
    switch (func_id) 
    {
        case 0x10: // FlushCache
            ctx->r2 = 0;
            return;

        case 0x15: // strlen (char *src)
            //printf("strlen\n");
            ctx->r2 = strlen((const char*)GET_PTR(ctx->r4));
            return;
        case 0x16: // strcpy (char *dst, const char *src)
            //printf("strcpy\n");
            strcpy((char*)GET_PTR(ctx->r4), (const char*)GET_PTR(ctx->r5));
            ctx->r2 = ctx->r4;
            return;
        case 0x1A: // strcat (char *dst, const char *src)
            //printf("strcat\n");
            strcat((char*)GET_PTR(ctx->r4), (const char*)GET_PTR(ctx->r5));
            ctx->r2 = ctx->r4;
            return;
        case 0x2A: // memcpy (void *dst, void *src, int len)
           // printf("memcpy\n");
            memcpy(GET_PTR(ctx->r4), GET_PTR(ctx->r5), ctx->r6);
            ctx->r2 = ctx->r4;
            return;
        case 0x2B: // memset (void *dst, int fill, int len)
            //printf("memset\n");
            memset(GET_PTR(ctx->r4), ctx->r5, ctx->r6);
            ctx->r2 = ctx->r4;
            return;
        case 0x2F: // rand()
            ctx->r2 = rand();
            return;
        case 0x17: //ps1_strcmp
        {
            char* s1 = (char*)GET_PTR(ctx->r4);
            char* s2 = (char*)GET_PTR(ctx->r5);
            if (s1 && s2) {
                ctx->r2 = strcmp(s1, s2);
            }
            else {
                ctx->r2 = 0;
            }
            return;
        }
        case 0x18: // strncmp
        {
            char* s1 = (char*)GET_PTR(ctx->r4);
            char* s2 = (char*)GET_PTR(ctx->r5);
            uint32_t n = ctx->r6; // 3-й аргумент: лимит символов (в данном случае 5)

            if (s1 && s2) {
                ctx->r2 = strncmp(s1, s2, n);
            }
            else {
                ctx->r2 = 0;
            }
            return;
        }

        case 0x19: // strncmp (const char *s1, const char *s2, int n)
        {
            const char* s1 = (const char*)GET_PTR(ctx->r4);
            const char* s2 = (const char*)GET_PTR(ctx->r5);
            uint32_t n = ctx->r6;
            ctx->r2 = strncmp(s1, s2, n);
            return;
        }
        case 0x3F: // printf
        {
            uint32_t fmt_ptr = ctx->r4; // $a0
            if (fmt_ptr < 0x80000000 || fmt_ptr >= 0x80200000) return;

            const char* fmt = (const char*)&rdram[fmt_ptr & 0x1FFFFF];

            // Извлекаем следующие 3 аргумента из регистров и 4-й из стека
            uint32_t arg1 = ctx->r5; // $a1
            uint32_t arg2 = ctx->r6; // $a2
            uint32_t arg3 = ctx->r7; // $a3
            uint32_t arg4 = *(uint32_t*)&rdram[(ctx->r29 + 0x10) & 0x1FFFFF]; // arg4 со стека

            printf("[GAME] ");

            // Магия C: передаем аргументы как есть. 
            // Если в строке только один %d, printf возьмет только arg1, остальное безопасно отбросит.
            // Чтобы не крашнуло на %s, если игра передала строку, нужно проверять адреса, 
            // но для базовых логов игры PS1 обычно это работает отлично.
            // Для максимальной безопасности преобразуем адреса RAM в реальные указатели:

            auto safe_arg = [&](uint32_t val) -> uint32_t {
                if (val >= 0x80000000 && val < 0x80200000) {
                    // Превращаем 32-битный адрес PS1 в реальный 64-битный указатель на ПК
                    return (uintptr_t)&rdram[val & 0x1FFFFF];
                }
                // Если это просто число, оно безопасно расширится нулями до 64 бит
                return (uintptr_t)val;
            };

            // Заглушаем варнинги компилятора, мы знаем что делаем
#pragma warning(suppress: 4774)
            printf(fmt, safe_arg(arg1), safe_arg(arg2), safe_arg(arg3), safe_arg(arg4));

            // Добавляем перенос строки, если его не было
            if (strlen(fmt) > 0 && fmt[strlen(fmt) - 1] != '\n') {
                printf("\n");
            }

            ctx->r2 = 0; // Возвращаем количество напечатанных символов (неважно)
            return;
        }
        case 0x3C: // Exit
            printf("[BIOS A] Game called Exit!\n");
            return;

        case 0x72: // CdRemove
            printf("[BIOS A] CdRemove\n");
            ctx->r2 = 1;
            return;

        case 0x44: // FlushCache
            printf("[BIOS A] FlushCache\n");
            ctx->r2 = 0;
            return;

        case 0x70: // _bu_init (memory card)
            printf("[BIOS A] _bu_init\n");
            ctx->r2 = 0;
            return;
        case 0x28: // SetDefaultExitFromException  
            printf("[BIOS A] SetDefaultExitFromException\n");
            ctx->r2 = 0;
            return;
        default:
            // ВАЖНО: Выводим в лог функции, которые мы еще не реализовали!
            // Например, если игра использует sprintf (0x3E), ты сразу это увидишь.
            printf("[BIOS] WARNING: Unhandled A-function: 0x%02X\n", func_id);
            ctx->r2 = 1;
            return;
    }


    ctx->r2 = 1; // Успех 
}

void ps1_bios_dispatcher_B(uint8_t* rdram, recomp_context* ctx)
{
    uint32_t func_id = ctx->r9;
    switch (func_id)
    {
        case 0x17: // ReturnFromException
            printf("[BIOS] B-Call : ReturnFromException\n");
            ctx->r2 = 0;
            return;

        case 0x19: // SetDefaultExitFromException
            printf("[BIOS] B-Call : SetDefaultExitFromException\n");
            ctx->r2 = 0;
            return;

        case 0x57: // StartPAD2 / PadInitDirect
            printf("[BIOS] B-Call : StartPAD2\n");
            ctx->r2 = 1;
            return;

        case 0x5B: // ChangeClearPad
            printf("[BIOS] B-Call : ChangeClearPad\n");
            ctx->r2 = 0;
            return;

        case 0x3F: // Это внутренний диспетчер в некоторых SDK
        case 0x78: // СТАНДАРТНЫЙ CdControl
        {
            printf("[BIOS] B-Call : CdControl\n");
            // Если r4 содержит 0x78, значит аргументы сдвинуты!
            if (ctx->r4 == 0x78 || ctx->r4 == 0x3F) {
                // Временный хак: перекладываем регистры для обертки
                uint32_t saved_a0 = ctx->r4;
                ctx->r4 = ctx->r5; // Команда CD (CdlSetloc и т.д.)
                ctx->r5 = ctx->r6; // Указатель на CdlLOC
                printf("");
                KFCD_CdControl(rdram, ctx);

                ctx->r4 = saved_a0; // Возвращаем как было
            }
            else {
                KFCD_CdControl(rdram, ctx);
            }
            return;
        }

        case 0x7B: // CdReadSync
        {
            printf("[BIOS] B-Call: CdReadSync\n");
            ctx->r2 = KFCD_CdReadSync(ctx->r4);
            return;
        }
        case 0x4A: // InitPAD
        {
            // Настоящий InitPAD из Psy-X
            InitPAD((char*)GET_PTR(ctx->r4), ctx->r5, (char*)GET_PTR(ctx->r6), ctx->r7);
            ctx->r2 = 1;
            return;
        }
        case 0x4B: // StartPAD
        {
            // Запуск опроса геймпада, видимо не вызывается
            StartPAD();
            ctx->r2 = 1;
            return;
        }
        case 0x4C: // puts
        {
            const char* str = (const char*)GET_PTR(ctx->r4);
            printf("[BIOS puts] %s\n", str);
            ctx->r2 = 0;
            return;
        }
        case 0x56: // PadRead
        {
            int mode = (int)ctx->r4;
            PadRead(mode);
            // Возвращаем, что джойстик подключен, но кнопки не нажаты.
        // 0xFFFF - стандарт для PS1 (инвертированные биты)
            //ctx->r2 = 0xFFFF; // Нажат START (для теста) или просто 0xFFFF  0xFFFB
            return;
        }
        //mem card
        case 0x32: // open(filename, mode)
        {
            const char* filename = (const char*)GET_PTR(ctx->r4);
            uint32_t mode = ctx->r5;
            EnsureMcDir();
            std::string path = McPathToLocal(filename);

            const char* fmode = "rb";
            if (mode & 0x200) fmode = "wb";
            else if (mode & 0x02) fmode = "r+b";

            FILE* f = fopen(path.c_str(), fmode);
            if (!f && (mode & 0x200))
                f = fopen(path.c_str(), "wb");

            if (f) {
                int fd = g_mcNextFd++;
                if (g_mcNextFd >= 16) g_mcNextFd = 1;
                g_mcFiles[fd] = f;
              /*  printf("[MC] open '%s' → '%s' fd=%d mode=%X\n",
                    filename, path.c_str(), fd, mode);*/
                ctx->r2 = fd;
            }
            else {
                printf("[MC] open FAIL '%s'\n", filename);
                ctx->r2 = (uint32_t)-1;
            }
            return;
        }

        case 0x33: // lseek(fd, offset, seektype)
        {
            int fd = ctx->r4;
            int offset = (int)ctx->r5;
            int whence = ctx->r6;
            if (fd > 0 && fd < 16 && g_mcFiles[fd]) {
                int w = (whence == 0) ? SEEK_SET : (whence == 1) ? SEEK_CUR : SEEK_END;
                fseek(g_mcFiles[fd], offset, w);
                ctx->r2 = (uint32_t)ftell(g_mcFiles[fd]);
            }
            else {
                ctx->r2 = (uint32_t)-1;
            }
            return;
        }

        case 0x34: // read(fd, dst, length)
        {
            int fd = ctx->r4;
            uint8_t* dst = (uint8_t*)GET_PTR(ctx->r5);
            uint32_t len = ctx->r6;
            if (fd > 0 && fd < 16 && g_mcFiles[fd]) {
                size_t read = fread(dst, 1, len, g_mcFiles[fd]);
                /*printf("[MC] read fd=%d len=%d got=%zu\n", fd, len, read);*/
                ctx->r2 = (uint32_t)read;
            }
            else {
                ctx->r2 = (uint32_t)-1;
            }
            return;
        }
        case 0x35: // write(fd, src, length)
        {
            int fd = ctx->r4;
            uint8_t* src = (uint8_t*)GET_PTR(ctx->r5);
            uint32_t len = ctx->r6;
            if (fd > 0 && fd < 16 && g_mcFiles[fd]) {
                size_t written = fwrite(src, 1, len, g_mcFiles[fd]);
                fflush(g_mcFiles[fd]);
                /*printf("[MC] write fd=%d len=%d wrote=%zu\n", fd, len, written);*/
                ctx->r2 = (uint32_t)written;
            }
            else {
                printf("[MC] write FAIL fd=%d\n", fd);
                ctx->r2 = (uint32_t)-1;
            }
            return;
        }

        case 0x36: // close(fd)
        {
            int fd = ctx->r4;
            if (fd > 0 && fd < 16 && g_mcFiles[fd]) {
                fclose(g_mcFiles[fd]);
                g_mcFiles[fd] = nullptr;
               /* printf("[MC] close fd=%d\n", fd);*/
            }
            ctx->r2 = 0;
            return;
        }

        case 0x37: // write(fd, src, length)
        {
            int fd = ctx->r4;
            uint8_t* src = (uint8_t*)GET_PTR(ctx->r5);
            uint32_t len = ctx->r6;
            if (fd > 0 && fd < 16 && g_mcFiles[fd]) {
                size_t written = fwrite(src, 1, len, g_mcFiles[fd]);
                fflush(g_mcFiles[fd]);
                /*printf("[MC] write fd=%d len=%d wrote=%zu\n", fd, len, written);*/
                ctx->r2 = (uint32_t)written;
            }
            else {
                ctx->r2 = (uint32_t)-1;
            }
            return;
        }
        case 0x41: // erase(filename)
        {
            const char* filename = (const char*)GET_PTR(ctx->r4);
            std::string path = McPathToLocal(filename);
            /*printf("[MC] erase '%s'\n", filename);*/
            try {
                if (std::filesystem::exists(path))
                    std::filesystem::remove(path);
                ctx->r2 = 0;
            }
            catch (...) {
                ctx->r2 = 0;
            }
            return;
        }
        case 0x42: // firstfile(pattern, direntry)
        {
            const char* pattern = (const char*)GET_PTR(ctx->r4);
            uint8_t* direntry = (uint8_t*)GET_PTR(ctx->r5);
            EnsureMcDir();

            g_dirEntries.clear();
            g_dirIndex = 0;

            if (std::filesystem::exists(MC_SAVE_DIR)) {
                for (auto& entry : std::filesystem::directory_iterator(MC_SAVE_DIR)) {
                    if (!entry.is_regular_file()) continue;
                    std::string fname = entry.path().filename().string();
                    if (fname.find("TEMP") != std::string::npos) continue;
                    if (fname.find("BESCES") == 0) {
                        g_dirEntries.push_back(fname);
                    }
                }
            }
            // Сортируем по имени
            std::sort(g_dirEntries.begin(), g_dirEntries.end());

            if (g_dirEntries.empty()) {
                ctx->r2 = 0;
                return;
            }

            // PS1 direntry format: 40 bytes
            // 0-19:  filename (без "bu00:")
            // 20-23: attr
            // 24-27: size (в байтах)
            // 28-31: next ptr (не используется)
            memset(direntry, 0, 40);
            // БЕЗ "bu00:"!
            strncpy((char*)direntry, g_dirEntries[0].c_str(), 20);

            auto fsize = std::filesystem::file_size(
                std::string(MC_SAVE_DIR) + g_dirEntries[0]);
            *(uint32_t*)(direntry + 24) = (uint32_t)fsize;

            g_dirIndex = 1;
           /* printf("[MC] firstfile '%s' → '%s' (%d files)\n",
                pattern, g_dirEntries[0].c_str(), (int)g_dirEntries.size());*/

            ctx->r2 = ctx->r5;
            return;
        }

        case 0x43: // nextfile(direntry)
        {
            uint8_t* direntry = (uint8_t*)GET_PTR(ctx->r4);

            if (g_dirIndex >= (int)g_dirEntries.size()) {
                ctx->r2 = 0;
                return;
            }

            memset(direntry, 0, 40);
            strncpy((char*)direntry, g_dirEntries[g_dirIndex].c_str(), 20);

            auto fsize = std::filesystem::file_size(
                std::string(MC_SAVE_DIR) + g_dirEntries[g_dirIndex]);
            *(uint32_t*)(direntry + 24) = (uint32_t)fsize;

            //printf("[MC] nextfile → '%s'\n", g_dirEntries[g_dirIndex].c_str());
            g_dirIndex++;
            ctx->r2 = ctx->r4;
            return;
        }

        case 0x47: // card_info(port)
        {
            printf("[MC] card_info port=%d\n", ctx->r4);
            ctx->r2 = 2; // 2 = карта вставлена и готова
            return;
        }

    default:
        break;
    }
    printf("[BIOS] B-Call: 0x%02X (a0=0x%08X)\n", func_id, ctx->r4);
    ctx->r2 = 0;
}

void ps1_bios_dispatcher_C(uint8_t* rdram, recomp_context* ctx)
{
    uint32_t func_id = ctx->r9;

    switch (func_id) {
    case 0x02: // CdInit
        printf("[BIOS C] CdInit called -> Forcing Success!\n");
        ctx->r2 = 1; // Возвращаем 1 (успех)
        return;

    case 0x0A: // ChangeClearRCnt
        // Таймеры, просто игнорируем пока
        printf("[BIOS C] ChangeClearRCnt Forcing -> 1!\n");
        ctx->r2 = 1;
        return;
    case 0x03: // SysDeqIntRP
        printf("[BIOS C] SysDeqIntRP\n");
        ctx->r2 = 0;
        return;
    }

    printf("[BIOS] C-Call: 0x%02X (a0=0x%08X)\n", func_id, ctx->r4);
}


void recomp_vram_call(uint8_t* rdram, recomp_context* ctx, uint32_t vram)
{
    recomp_func_t f = lookup_recomp_func(vram);
    if (f)
    {
        printf(" -> Calling function at 0x%08X\n", vram);
        f(rdram, ctx);
    }
    else {
        // Если функция не найдена, просто выходим, чтобы не упасть
        printf("Unknown VRAM call: 0x%08X\n", vram);
    }
}

// LWL - Load Word Left (Little Endian)
uint32_t do_lwl(uint8_t* rdram, uint32_t reg, uint32_t offset, uint32_t base) {
    uint32_t addr = base + offset;
    uint32_t mem = *(uint32_t*)GET_PTR(addr & ~3);
    switch (addr & 3) {
    case 0: return (reg & 0x00FFFFFF) | (mem << 24);
    case 1: return (reg & 0x0000FFFF) | (mem << 16);
    case 2: return (reg & 0x000000FF) | (mem << 8);
    case 3: return mem;
    }
    return reg;
}

// LWR - Load Word Right (Little Endian)
uint32_t do_lwr(uint8_t* rdram, uint32_t reg, uint32_t offset, uint32_t base) {
    uint32_t addr = base + offset;
    uint32_t mem = *(uint32_t*)GET_PTR(addr & ~3);
    switch (addr & 3) {
    case 0: return mem;
    case 1: return (reg & 0xFF000000) | (mem >> 8);
    case 2: return (reg & 0xFFFF0000) | (mem >> 16);
    case 3: return (reg & 0xFFFFFF00) | (mem >> 24);
    }
    return reg;
}

// SWL - Store Word Left (Little Endian)
void do_swl(uint8_t* rdram, uint32_t offset, uint32_t base, uint32_t reg) {
    uint32_t addr = base + offset;
    uint32_t* mem_ptr = (uint32_t*)GET_PTR(addr & ~3);
    uint32_t v = *mem_ptr;
    switch (addr & 3) {
    case 0: v = (v & 0xFFFFFF00) | (reg >> 24); break;
    case 1: v = (v & 0xFFFF0000) | (reg >> 16); break;
    case 2: v = (v & 0xFF000000) | (reg >> 8); break;
    case 3: v = reg; break;
    }
    *mem_ptr = v;
}

// SWR - Store Word Right (Little Endian)
void do_swr(uint8_t* rdram, uint32_t offset, uint32_t base, uint32_t reg) {
    uint32_t addr = base + offset;
    uint32_t* mem_ptr = (uint32_t*)GET_PTR(addr & ~3);
    uint32_t v = *mem_ptr;
    switch (addr & 3) {
    case 0: v = reg; break;
    case 1: v = (v & 0x000000FF) | (reg << 8); break;
    case 2: v = (v & 0x0000FFFF) | (reg << 16); break;
    case 3: v = (v & 0x00FFFFFF) | (reg << 24); break;
    }
    *mem_ptr = v;
}




void recomp_syscall_handler(uint8_t* rdram, recomp_context* ctx, uint32_t addr1)
{
    uint32_t a0 = ctx->r4;
   

    if (a0 == 1) { // EnterCriticalSection
        // Игра отключает прерывания
        SwEnterCriticalSection();
        //printf("EnterCriticalSection\n");
        return;
    }

    if (a0 == 2) // ExitCriticalSection
    {
        SwExitCriticalSection();
        //printf("ExitCriticalSection\n");
        //// Гасим DMA
        //uint32_t* gpu_dma = (uint32_t*)GET_PTR(0x1F8010A8);
        //if (*gpu_dma & 0x01000000) *gpu_dma &= ~0x01000000;
        //uint32_t* cd_dma = (uint32_t*)GET_PTR(0x1F8010B8);
        //if (*cd_dma & 0x01000000) *cd_dma &= ~0x01000000;
        //uint32_t* otc_dma = (uint32_t*)GET_PTR(0x1F8010E8);
        //if (*otc_dma & 0x01000000) *otc_dma &= ~0x01000000;

        //// --- ОБРАБОТКА ОЧЕРЕДИ ЗДЕСЬ ТОЖЕ ---
        //// Если игра застряла в цикле и не вызывает VSync, 
        //// этот код спасет ситуацию!
        //process_cd_tasks(rdram, ctx);
        //std::this_thread::yield();
        return;
    }

    // Если это какой-то другой Syscall
    printf("Syscall hit! a0: 0x%08X\n", a0);
}

uint32_t cop0_status_read(recomp_context* ctx)
{
    printf("cop0_status_read\n");
    return (ctx->cop0_status == 0) ? 0x401 : ctx->cop0_status;
}

void cop0_status_write(recomp_context* ctx, uint32_t val)
{
    ctx->cop0_status = val;
    printf("cop0_status_write\n");
}

int32_t setjmp_recomp(uint8_t* rdram, recomp_context* ctx)
{
    printf("setjmp_recomp\n");
    return 0;
}

void do_break(uint32_t code)
{
    printf("[PS1] BREAK instruction hit! Code: %d\n", code);
}

void dummy_safe_func(uint8_t* rdram, recomp_context* ctx)
{
   // uint32_t phys_addr = *rdram & 0x1FFFFFFF;
   // printf("dummy_safe_func call  0x%08X\n", phys_addr);
}



//debug
void check_tmd_integrity(const char* where) {
    uint32_t tmd_base = MEM_W(0, 0x80190250);
    if (tmd_base < 0x80000000 || tmd_base > 0x801FFFFF) {
        printf("[TMD CHECK %s] base INVALID: %08X\n", where, tmd_base);
        return;
    }
    uint8_t* p = (uint8_t*)GET_PTR(tmd_base + 12);
    uint32_t vnum = *(uint32_t*)(p + 4);
    printf("[TMD CHECK %s] base=%08X vertNum_obj0=%d\n", where, tmd_base, vnum);
}



inline bool is_valid_ps1_addr(uint32_t addr) {
    uint32_t phys = addr & 0x1FFFFFFF;
    return phys < 0x200000; // 2MB PS1 RAM
}

/*
[INTERP] Unknown opcode 22 at 801A19D4 instr=88A20003
[INTERP] Unknown opcode 26 at 801A19D8 instr=98A20000
[INTERP] Unknown opcode 22 at 801A19DC instr=88A30007
[INTERP] Unknown opcode 26 at 801A19E0 instr=98A30004
[INTERP] Unknown opcode 2A at 801A19E4 instr=A8820003
[INTERP] Unknown opcode 2E at 801A19E8 instr=B8820000
[INTERP] Unknown opcode 2A at 801A19EC instr=A8830007
[INTERP] Unknown opcode 2E at 801A19F0 instr=B8830004
*/

void mips_interpret(uint8_t* rdram, recomp_context* ctx, uint32_t start_pc) {
    uint32_t pc = start_pc;
    uint32_t return_addr = ctx->r31;
    uint32_t* r = &ctx->r0;
    //printf("[INTERP] ENTER pc=%08X ra=%08X\n", start_pc, ctx->r31);

    //if (pc == 0x801A132C)
    //{
    //    printf("[SCRIPT 132C] args: r4=%08X r5=%08X r6=%08X r7=%08X\n",
    //        ctx->r4, ctx->r5, ctx->r6, ctx->r7);
    //    printf("[SCRIPT 132C] disasm:\n");
    //    for (int i = 0; i < 160; i += 4) {
    //        printf("  %08X: %08X\n", 0x801A132C + i, MEM_W(0, 0x801A132C + i));
    //    }
    //}


    for (int steps = 0; steps < 100000; steps++) 
    {
        if (!is_valid_ps1_addr(pc)) {
            printf("[INTERP] PC out of range: %08X, aborting\n", pc);
            return;
        }

        uint32_t instr = MEM_W(0, pc);
        uint32_t op = (instr >> 26) & 0x3F;
        uint32_t rs = (instr >> 21) & 0x1F;
        uint32_t rt = (instr >> 16) & 0x1F;
        uint32_t rd = (instr >> 11) & 0x1F;
        uint32_t shamt = (instr >> 6) & 0x1F;
        uint32_t funct = instr & 0x3F;
        int16_t imm = (int16_t)(instr & 0xFFFF);
        uint16_t uimm = (uint16_t)(instr & 0xFFFF);
        uint32_t target = (pc & 0xF0000000) | ((instr & 0x3FFFFFF) << 2);

        bool do_branch = false;
        uint32_t branch_target = 0;
        bool is_link = false;

        switch (op) {
        case 0x00: // SPECIAL
            switch (funct) {
            case 0x00: r[rd] = r[rt] << shamt; break;
            case 0x02: r[rd] = r[rt] >> shamt; break;
            case 0x03: r[rd] = (int32_t)r[rt] >> shamt; break;
            case 0x04: r[rd] = r[rt] << (r[rs] & 31); break;
            case 0x06: r[rd] = r[rt] >> (r[rs] & 31); break;
            case 0x07: r[rd] = (int32_t)r[rt] >> (r[rs] & 31); break;
            case 0x08: // jr
            {
                do_branch = true;
                branch_target = r[rs];
                if (!is_valid_ps1_addr(branch_target) && branch_target != return_addr) {
                    printf("[INTERP] BAD JR target=%08X rs=%d at PC=%08X\n", branch_target, rs, pc);
                    return;
                }
            }
                break;
            case 0x09: do_branch = true; branch_target = r[rs]; is_link = true; r[rd ? rd : 31] = pc + 8;  break; // jalr
            case 0x0C: break; // syscall
            case 0x0D: break; // break
            case 0x10: r[rd] = ctx->hi; break;
            case 0x11: ctx->hi = r[rs]; break; // mthi
            case 0x12: r[rd] = ctx->lo; break;
            case 0x13: ctx->lo = r[rs]; break; // mtlo
            case 0x18: { int64_t res = (int64_t)(int32_t)r[rs] * (int64_t)(int32_t)r[rt]; ctx->lo = (uint32_t)res; ctx->hi = (uint32_t)(res >> 32); } break;
            case 0x19: { uint64_t res = (uint64_t)r[rs] * (uint64_t)r[rt]; ctx->lo = (uint32_t)res; ctx->hi = (uint32_t)(res >> 32); } break;
            case 0x1A: if (r[rt]) { ctx->lo = (uint32_t)((int32_t)r[rs] / (int32_t)r[rt]); ctx->hi = (uint32_t)((int32_t)r[rs] % (int32_t)r[rt]); } break;
            case 0x1B: if (r[rt]) { ctx->lo = r[rs] / r[rt]; ctx->hi = r[rs] % r[rt]; } break;
            case 0x20: case 0x21: r[rd] = r[rs] + r[rt]; break;
            case 0x22: case 0x23: r[rd] = r[rs] - r[rt]; break;
            case 0x24: r[rd] = r[rs] & r[rt]; break;
            case 0x25: r[rd] = r[rs] | r[rt]; break;
            case 0x26: r[rd] = r[rs] ^ r[rt]; break;
            case 0x27: r[rd] = ~(r[rs] | r[rt]); break;
            case 0x2A: r[rd] = ((int32_t)r[rs] < (int32_t)r[rt]) ? 1 : 0; break;
            case 0x2B: r[rd] = (r[rs] < r[rt]) ? 1 : 0; break;
            default: printf("[INTERP] Unknown SPECIAL funct %02X at %08X\n", funct, pc); break;
            }
            break;
        case 0x01: // REGIMM
            switch (rt) {
            case 0x00: if ((int32_t)r[rs] < 0) { do_branch = true; branch_target = pc + 4 + (imm << 2); } break;
            case 0x01: if ((int32_t)r[rs] >= 0) { do_branch = true; branch_target = pc + 4 + (imm << 2); } break;
            case 0x10: r[31] = pc + 8; if ((int32_t)r[rs] < 0) { do_branch = true; branch_target = pc + 4 + (imm << 2); } is_link = true; break;
            case 0x11: r[31] = pc + 8; if ((int32_t)r[rs] >= 0) { do_branch = true; branch_target = pc + 4 + (imm << 2); } is_link = true; break;
            }
            break;
        case 0x02: do_branch = true; branch_target = target; break;
        case 0x03: r[31] = pc + 8; do_branch = true; branch_target = target; is_link = true; break;
        case 0x04: if (r[rs] == r[rt]) { do_branch = true; branch_target = pc + 4 + (imm << 2); } break;
        case 0x05: if (r[rs] != r[rt]) { do_branch = true; branch_target = pc + 4 + (imm << 2); } break;
        case 0x06: if ((int32_t)r[rs] <= 0) { do_branch = true; branch_target = pc + 4 + (imm << 2); } break;
        case 0x07: if ((int32_t)r[rs] > 0) { do_branch = true; branch_target = pc + 4 + (imm << 2); } break;
        case 0x08: case 0x09: r[rt] = r[rs] + imm; break; // addi/addiu
        case 0x0A: r[rt] = ((int32_t)r[rs] < imm) ? 1 : 0; break;
        case 0x0B: r[rt] = (r[rs] < (uint32_t)(int32_t)imm) ? 1 : 0; break;
        case 0x0C: r[rt] = r[rs] & uimm; break;
        case 0x0D: r[rt] = r[rs] | uimm; break;
        case 0x0E: r[rt] = r[rs] ^ uimm; break;
        case 0x0F: r[rt] = (uint32_t)uimm << 16; break;
        case 0x10: // COP0
            if (rs == 0x00) r[rt] = ctx->cop0_status;
            else if (rs == 0x04) ctx->cop0_status = r[rt];
            break;
        case 0x12: // COP2 (GTE)
            if (rs >= 0x10) { // GTE command
                ctx_to_gte(ctx);
                GTE_operator(instr & 0x1FFFFFF);
                gte_to_ctx(ctx);
            }
            else if (rs == 0x00) { r[rt] = ctx->cp2d[rd]; } // mfc2
            else if (rs == 0x02) { r[rt] = ctx->cp2c[rd]; } // cfc2
            else if (rs == 0x04) { ctx->cp2d[rd] = r[rt]; } // mtc2
            else if (rs == 0x06) { ctx->cp2c[rd] = r[rt]; } // ctc2
            break;
        case 0x20: r[rt] = (int32_t)(int8_t)MEM_B(imm, r[rs]); break;
        case 0x21: r[rt] = (int32_t)(int16_t)MEM_H(imm, r[rs]); break;
        case 0x23: r[rt] = MEM_W(imm, r[rs]); break;
        case 0x24: r[rt] = MEM_BU(imm, r[rs]); break;
        case 0x25: r[rt] = (uint16_t)MEM_H(imm, r[rs]); break;
        case 0x28:
        {   uint32_t addr = r[rs] + imm;
            if (is_valid_ps1_addr(addr)) {

                MEM_B(imm, r[rs]) = (uint8_t)r[rt];
        }
        } break;
        case 0x29: 
        {   uint32_t addr = r[rs] + imm;
            if (is_valid_ps1_addr(addr)) {
                uint32_t phys = addr & 0x1FFFFFFF;

                MEM_H(imm, r[rs]) = (uint16_t)r[rt];
            }
        } break;
        case 0x2B: // sw
        { uint32_t addr = r[rs] + imm;
        if (is_valid_ps1_addr(addr)) {
            uint32_t phys = addr & 0x1FFFFFFF;

            MEM_W(imm, r[rs]) = r[rt];
        }
        } break;
        case 0x32: ctx->cp2d[rt] = MEM_W(imm, r[rs]); break; // lwc2
        case 0x3A: MEM_W(imm, r[rs]) = ctx->cp2d[rt]; break; // swc2
        default:
            printf("[INTERP] Unknown opcode %02X at %08X instr=%08X\n", op, pc, instr);
            break;
        }

        r[0] = 0;

        if (do_branch) {
            // Execute delay slot
            uint32_t ds_instr = MEM_W(0, pc + 4);
            uint32_t ds_op = (ds_instr >> 26) & 0x3F;
            uint32_t ds_rs = (ds_instr >> 21) & 0x1F;
            uint32_t ds_rt = (ds_instr >> 16) & 0x1F;
            uint32_t ds_rd = (ds_instr >> 11) & 0x1F;
            uint32_t ds_shamt = (ds_instr >> 6) & 0x1F;
            uint32_t ds_funct = ds_instr & 0x3F;
            int16_t ds_imm = (int16_t)(ds_instr & 0xFFFF);
            uint16_t ds_uimm = (uint16_t)(ds_instr & 0xFFFF);

            // Simplified delay slot - covers common cases
            switch (ds_op) {
            case 0x00:
                switch (ds_funct) {
                case 0x00: r[ds_rd] = r[ds_rt] << ds_shamt; break;
                case 0x02: r[ds_rd] = r[ds_rt] >> ds_shamt; break;
                case 0x03: r[ds_rd] = (int32_t)r[ds_rt] >> ds_shamt; break;
                case 0x21: r[ds_rd] = r[ds_rs] + r[ds_rt]; break;
                case 0x23: r[ds_rd] = r[ds_rs] - r[ds_rt]; break;
                case 0x24: r[ds_rd] = r[ds_rs] & r[ds_rt]; break;
                case 0x25: r[ds_rd] = r[ds_rs] | r[ds_rt]; break;
                case 0x2A: r[ds_rd] = ((int32_t)r[ds_rs] < (int32_t)r[ds_rt]) ? 1 : 0; break;
                case 0x2B: r[ds_rd] = (r[ds_rs] < r[ds_rt]) ? 1 : 0; break;
                case 0x0D: break; // break in delay slot
                }
                break;
            case 0x08: case 0x09: r[ds_rt] = r[ds_rs] + ds_imm; break;
            case 0x0C: r[ds_rt] = r[ds_rs] & ds_uimm; break;
            case 0x0D: r[ds_rt] = r[ds_rs] | ds_uimm; break;
            case 0x0F: r[ds_rt] = (uint32_t)ds_uimm << 16; break;
            case 0x23: r[ds_rt] = MEM_W(ds_imm, r[ds_rs]); break;
            case 0x2B: MEM_W(ds_imm, r[ds_rs]) = r[ds_rt]; break;
            case 0x20: r[ds_rt] = (int32_t)(int8_t)MEM_B(ds_imm, r[ds_rs]); break;
            case 0x24: r[ds_rt] = MEM_BU(ds_imm, r[ds_rs]); break;
            case 0x25: r[ds_rt] = (uint16_t)MEM_H(ds_imm, r[ds_rs]); break;
            case 0x28: MEM_B(ds_imm, r[ds_rs]) = (uint8_t)r[ds_rt]; break;
            case 0x29: MEM_H(ds_imm, r[ds_rs]) = (uint16_t)r[ds_rt]; break;
            default: break; // nop in delay slot
            }
            r[0] = 0;

            // jr $ra — return
            if (branch_target == return_addr)
            {
                //printf("[INTERP] EXIT pc=%08X\n", pc);
                return;
            }

            // jal/jalr to known recompiled function
            if (is_link) {
                recomp_func_t fn = lookup_recomp_func(branch_target);
                if (fn && fn != dummy_safe_func && fn != interp_wrapper) {
                    uint32_t saved_ra = ctx->r31;
                    ctx->r31 = pc + 8; // return address
                    fn(rdram, ctx);
                    pc = pc + 8; // continue after jal + delay slot
                    continue;
                }
            }

            pc = branch_target;
        }
        else {
            pc = pc + 4;
        }
    }
}