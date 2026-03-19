#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libapi.h"

void OpenEvent(uint8_t* rdram, recomp_context* ctx) 
{
    uint32_t desc = (uint32_t)ctx->r4; // Класс события (напр. 0xF2000001)
    int spec = (int)ctx->r5;      // Спецификация
    int mode = (int)ctx->r6;      // Режим (0x2000 - callback, 0x1000 - flag)
    uint32_t func = (uint32_t)ctx->r7; // Адрес функции в памяти PS1 (если есть)

    ctx->r2 = (uint32_t)OpenEvent(desc, spec, mode, NULL);

    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// addiu       $t2, $zero, 0xB0
    //ctx->r10 = ADD32(0, 0XB0);
    //// jr          $t2
    //// addiu       $t1, $zero, 0x8
    //ctx->r9 = ADD32(0, 0X8);
    //LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    //return;
    //// addiu       $t1, $zero, 0x8
    //ctx->r9 = ADD32(0, 0X8);
;}
