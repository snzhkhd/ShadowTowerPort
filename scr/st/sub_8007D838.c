#include "recomp.h"
#include "disable_warnings.h"

void sub_8007D838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E78($v1)
    ctx->r3 = MEM_W(0X7E78, ctx->r3);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7E7C($a0)
    ctx->r4 = MEM_W(0X7E7C, ctx->r4);
    // addiu       $v0, $zero, -0x81
    ctx->r2 = ADD32(0, -0X81);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8007D89C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D89C;
    }
    // nop

L_8007D86C:
    // jal         0x8007F344
    // nop

    chkRC2wait(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // bne         $v0, $zero, L_8007D8B8
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007D8B8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E7C($v0)
    ctx->r2 = MEM_W(0X7E7C, ctx->r2);
    // nop

    // lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(0X4, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // bne         $v0, $zero, L_8007D86C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007D86C;
    }
    // nop

L_8007D89C:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7E7C($a0)
    ctx->r4 = MEM_W(0X7E7C, ctx->r4);
    // nop

    // lhu         $v1, 0xA($a0)
    ctx->r3 = MEM_HU(0XA, ctx->r4);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // sh          $v1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r3;
L_8007D8B8:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
