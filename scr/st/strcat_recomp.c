#include "recomp.h"
#include "disable_warnings.h"
#include <string>

void strcat_recomp(uint8_t* rdram, recomp_context* ctx) 
{
    char* dst = (char*)GET_PTR(ctx->r4);
    char* src = (char*)GET_PTR(ctx->r5);

    if (dst && src) {
        strcat(dst, src);
        //printf("[HLE STR] strcat(dst=\"%s\")\n", dst);
    }

    ctx->r2 = ctx->r4; // strcat возвращает dst

    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// addiu       $t2, $zero, 0xA0
    //ctx->r10 = ADD32(0, 0XA0);
    //// jr          $t2
    //// addiu       $t1, $zero, 0x15
    //ctx->r9 = ADD32(0, 0X15);
    //LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    //return;
    //// addiu       $t1, $zero, 0x15
    //ctx->r9 = ADD32(0, 0X15);
;}
