#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libspu.h"


void _spu_getInTransfer(uint8_t* rdram, recomp_context* ctx) 
{
    ctx->r2 = (uint32_t)_SpuGetInTransfer();
    return;


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD74($v0)
    ctx->r2 = MEM_W(0XD74, ctx->r2);
    // nop

    // xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // jr          $ra
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
