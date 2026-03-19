#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "kf_cd.h"
#include "gte.h"
#include <intrin.h>
#include <stdio.h>

#include "psx/libcd.h" 
#include "st/funcs.h"



inline uint32_t g_spu_transfer_addr = 0;
inline uint32_t g_spu_total_size = 0;
inline uint32_t g_spu_transferred = 0;
inline uint32_t g_spu_actual_written = 0;

inline uint32_t g_heapBase = 0;
inline uint32_t g_heapPtr = 0;
inline uint32_t g_heapEnd = 0;


inline int frame = 0;
inline int calls_per_frame = 0;

extern uint8_t g_pad1_buf[34];
extern uint8_t g_pad2_buf[34];

extern uint32_t g_CdReadCbAddr;
extern uint32_t g_CdReadyCbAddr;
extern uint32_t g_CdSyncCbAddr;
extern bool g_vsync_pending;

extern struct recomp_context* g_ctx;


/////////////////////////////////////////////////////
// Мемкарта — простая файловая эмуляция
extern const char* MC_SAVE_DIR;
extern FILE* g_mcFiles[16];
extern int g_mcNextFd;




void EnsureMcDir();
/////////////////////////////////////////////////////


#define LOOKUP_FUNC(fvram) lookup_recomp_func(fvram)

void recomp_syscall_handler(uint8_t* rdram, recomp_context* ctx, uint32_t addr1);
recomp_func_t lookup_recomp_func(uint32_t fvram);
void recomp_vram_call(uint8_t* rdram, recomp_context* ctx, uint32_t vram);


void ps1_bios_dispatcher_A(uint8_t* rdram, recomp_context* ctx);
void ps1_bios_dispatcher_B(uint8_t* rdram, recomp_context* ctx);
void ps1_bios_dispatcher_C(uint8_t* rdram, recomp_context* ctx);



void gte_command(recomp_context* ctx, uint32_t cmd);
void gte_lwc2(uint8_t* rdram, recomp_context* ctx, int rt, int rs, int imm);
void gte_swc2(uint8_t* rdram, recomp_context* ctx, int rt, int rs, int imm);
void gte_mtc2(recomp_context* ctx, int rt, int rd);
uint32_t gte_mfc2(recomp_context* ctx, int rd);
void gte_ctc2(recomp_context* ctx, int rt, int rd);
uint32_t gte_cfc2(recomp_context* ctx, int rd);
    


   // Процессорные  функции
uint32_t do_lwl(uint8_t* rdram, uint32_t reg, uint32_t offset, uint32_t base);
uint32_t do_lwr(uint8_t* rdram, uint32_t reg, uint32_t offset, uint32_t base);
void do_swl(uint8_t* rdram, uint32_t offset, uint32_t base, uint32_t reg);
void do_swr(uint8_t* rdram, uint32_t offset, uint32_t base, uint32_t reg);


    
    // Системные функции

uint32_t cop0_status_read(recomp_context* ctx);
void cop0_status_write(recomp_context* ctx, uint32_t val);
int32_t setjmp_recomp(uint8_t* rdram, recomp_context* ctx);

void do_break(uint32_t code);

static void switch_error(const char* func_name, uint32_t addr1, uint32_t addr2) {
    printf("Switch error in %s at %08X, target %08X\n", func_name, addr1, addr2);
        // KF_exit(1); // по желанию
}
    //
void dummy_safe_func(uint8_t* rdram, recomp_context* ctx);
    

void init_function_table(); 


//debug
void check_tmd_integrity(const char* where);