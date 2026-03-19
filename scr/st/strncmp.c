#include "recomp.h"
#include "disable_warnings.h"
#include <string.h>

void strncmp(uint8_t* rdram, recomp_context* ctx) 
{

    const char* s1 = (const char*)GET_PTR(ctx->r4);
    const char* s2 = (const char*)GET_PTR(ctx->r5);
    int n = (int)ctx->r6;
    int result = strncmp(s1, s2, n);

    //// Лог только для мемкарты
    //if (n == 12) {
    //    printf("[strncmp] '%.20s' vs '%.12s' n=%d → %d\n", s1, s2, n, result);
    //}
    ctx->r2 = (uint32_t)result;

    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// addiu       $t2, $zero, 0xA0
    //ctx->r10 = ADD32(0, 0XA0);
    //// jr          $t2
    //// addiu       $t1, $zero, 0x18
    //ctx->r9 = ADD32(0, 0X18);
    //LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    //return;
    //// addiu       $t1, $zero, 0x18
    //ctx->r9 = ADD32(0, 0X18);
;}
