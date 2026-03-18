#include "recomp.h"
#include "disable_warnings.h"

void sub_80033DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // ori         $v1, $zero, 0x834C
    ctx->r3 = 0 | 0X834C;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // sltiu       $a0, $a0, 0x70
    ctx->r4 = ctx->r4 < 0X70 ? 1 : 0;
    // bne         $a0, $zero, L_80033E1C
    if (ctx->r4 != 0) {
        // sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
        goto L_80033E1C;
    }
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // beq         $v0, $zero, L_80033E18
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80033E18;
    }
    // nop

    // jal         0x80015258
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    sub_80015258(rdram, ctx);
    goto after_0;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_0:
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80033E1C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80033E1C;
    }
    // nop

L_80033E18:
    // sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80033E1C:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
