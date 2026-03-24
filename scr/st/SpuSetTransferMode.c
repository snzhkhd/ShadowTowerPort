#include "recomp.h"
#include "disable_warnings.h"

void SpuSetTransferMode(uint8_t* rdram, recomp_context* ctx) 
{
    printf("ST_SpuSetTransferMode\n");
    ctx->r2 = 0;
    return;

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // beq         $a0, $zero, L_8007426C
    if (ctx->r4 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007426C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $a0, $v0, L_80074270
    if (ctx->r4 != ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80074270;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_80074270
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_80074270;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007426C:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80074270:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $a0, 0xDB0($at)
    MEM_W(0XDB0, ctx->r1) = ctx->r4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // jr          $ra
    // sw          $v0, 0xD5C($at)
    MEM_W(0XD5C, ctx->r1) = ctx->r2;
    return;
    // sw          $v0, 0xD5C($at)
    MEM_W(0XD5C, ctx->r1) = ctx->r2;
;}
