#include "recomp.h"
#include "disable_warnings.h"

void sub_8001D264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // sltiu       $v0, $v0, 0x56
    ctx->r2 = ctx->r2 < 0X56 ? 1 : 0;
    // bne         $v0, $zero, L_8001D280
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x55
        ctx->r2 = ADD32(0, 0X55);
        goto L_8001D280;
    }
    // addiu       $v0, $zero, 0x55
    ctx->r2 = ADD32(0, 0X55);
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_8001D280:
    // lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(0X0, ctx->r5);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // jr          $ra
    // sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    return;
    // sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
;}
