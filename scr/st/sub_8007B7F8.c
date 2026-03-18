#include "recomp.h"
#include "disable_warnings.h"

void sub_8007B7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $a2, $a1, -0x1
    ctx->r6 = ADD32(ctx->r5, -0X1);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DC8($v1)
    ctx->r3 = MEM_W(0X7DC8, ctx->r3);
    // lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // beq         $a1, $zero, L_8007B830
    if (ctx->r5 == 0) {
        // sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8007B830;
    }
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8007B814:
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC4($v0)
    ctx->r2 = MEM_W(0X7DC4, ctx->r2);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $a1, L_8007B814
    if (ctx->r6 != ctx->r5) {
        // sw          $v1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r3;
        goto L_8007B814;
    }
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_8007B830:
    // jr          $ra
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
