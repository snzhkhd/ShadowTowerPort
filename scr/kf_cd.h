#pragma once
#include "_context.h"
#include <stdint.h>
#include <stdio.h>
#include "psx/libcd.h" 
//#define SECTOR_SIZE 2048
#define RAW_SECTOR_SIZE 2352

//typedef struct {
//    uint8_t minute;
//    uint8_t second;
//    uint8_t sector;
//} CdlLOC;

typedef struct {
    int active;
    uint32_t sector;
    uint32_t count;
    uint8_t* dst;
} KF_CD_Request;


typedef struct  {
    uint32_t lba;
    uint32_t size;
}CdFile;

#pragma pack(push, 1) // Гарантируем отсутствие паддинга (выравнивания)
struct PSXHeader {
    char id[8];             // "PS-X EXE"
    uint32_t text_off;      // Не используется (обычно 0)
    uint32_t data_off;      // Не используется (обычно 0)
    uint32_t pc0;           // Начальный PC (Program Counter)
    uint32_t gp0;           // Начальный GP (Global Pointer)
    uint32_t t_addr;        // Адрес загрузки в RAM (обычно 0x80010000 или выше)
    uint32_t t_size;        // Размер кода (в байтах)
    uint32_t d_addr;        // Обычно 0
    uint32_t d_size;        // Обычно 0
    uint32_t b_addr;        // Адрес начала BSS (секции, которую надо занулить)
    uint32_t b_size;        // Размер BSS
    uint32_t s_addr;        // Начальный SP (Stack Pointer) Base
    uint32_t s_size;        // Смещение стека (SP Offset)
    uint32_t SavedSP;       // (Обычно мусор или ASCII маркер Sony)
    uint32_t SavedFP;
    uint32_t SavedGP;
    uint32_t SavedRA;
    uint32_t SavedS0;
    char ascii_marker[2048 - 0x4C]; // Остаток заголовка (обычно текст "Sony Computer...")
};
#pragma pack(pop)

extern FILE* g_cdImage;
extern uint32_t g_cdCurrentSector;
extern KF_CD_Request g_cdReq;
extern int g_cdReading;

static uint32_t g_cd_pass_count = 0;
static uint32_t g_cd_last_stream = 0;
static uint32_t g_cd_initial_dst = 0;
static int      g_cd_base_lba = -1;


#ifdef __cplusplus
extern "C"
{
#endif

bool KFCD_FindFile(const char* filename, CdFile* out);
bool LoadGameEXEFromCD(recomp_context* ctx);


int KFCD_CdPosToInt(CdlLOC* p);

int KFCD_Init(const char* path);


void KFCD_CdControl(uint8_t* rdram, recomp_context* ctx);
void KFCD_CdlReadN(uint8_t* rdram, recomp_context* ctx);
int KFCD_CdRead(int sectors, uint32_t* buf);
int KFCD_CdReadSync(int mode);
int KFCD_CdSync(int mode);

void KFCD_CdReadyCallback(uint8_t* rdram, recomp_context* ctx);
void KFCD_CdSyncCallback(uint8_t* rdram, recomp_context* ctx);

void KFCD_InvokeCallback(uint8_t* rdram,recomp_context* ctx,uint32_t cbAddr,uint8_t status);

void KDCD_SetupDmaTransfer(uint8_t* rdram, recomp_context* ctx);

void KFCD_ResetReadState();
#ifdef __cplusplus
}
#endif