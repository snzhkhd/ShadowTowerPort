#include "recomp.h"
#include "disable_warnings.h"

void sub_8001B558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(0X2, ctx->r5);
    // nop

    // sltiu       $v0, $v0, 0x56
    ctx->r2 = ctx->r2 < 0X56 ? 1 : 0;
    // bne         $v0, $zero, L_8001B574
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x55
        ctx->r2 = ADD32(0, 0X55);
        goto L_8001B574;
    }
    // addiu       $v0, $zero, 0x55
    ctx->r2 = ADD32(0, 0X55);
    // sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
L_8001B574:
    // lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(0X2, ctx->r5);
    // nop

    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // jr          $ra
    // sb          $a0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r4;
    return;
    // sb          $a0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r4;
;}
