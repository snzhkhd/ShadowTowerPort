#include "recomp.h"
#include "disable_warnings.h"

void sub_800552BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x7590
    ctx->r2 = ADD32(ctx->r2, 0X7590);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v1, $v0, 0x7F
    ctx->r3 = ctx->r2 & 0X7F;
    // bne         $v1, $zero, L_800552E4
    if (ctx->r3 != 0) {
        // addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
        goto L_800552E4;
    }
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // j           L_800552F8
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_800552F8;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800552E4:
    // andi        $v1, $v1, 0x7F
    ctx->r3 = ctx->r3 & 0X7F;
    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800552F8:
    // jr          $ra
    // nop

    return;
    // nop

;}
