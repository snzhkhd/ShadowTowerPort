#include "recomp.h"
#include "disable_warnings.h"

void SsUtSetReverbType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // bgez        $v0, L_80070298
    if (SIGNED(ctx->r2) >= 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_80070298;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
L_80070298:
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_800702FC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800702FC;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x6A00
    ctx->r4 = ADD32(ctx->r4, -0X6A00);
    // beq         $a1, $zero, L_800702C4
    if (ctx->r5 == 0) {
        // sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_800702C4;
    }
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // ori         $v0, $v1, 0x100
    ctx->r2 = ctx->r3 | 0X100;
    // j           L_800702C8
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    goto L_800702C8;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
L_800702C4:
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
L_800702C8:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2) >> 16;
    // bne         $s0, $zero, L_800702E8
    if (ctx->r16 != 0) {
        // nop
    
        goto L_800702E8;
    }
    // nop

    // jal         0x80070324
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    SpuSetReverb(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
L_800702E8:
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // jal         0x8006F614
    // addiu       $a0, $a0, -0x6A00
    ctx->r4 = ADD32(ctx->r4, -0X6A00);
    SpuSetReverbModeParam(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, -0x6A00
    ctx->r4 = ADD32(ctx->r4, -0X6A00);
    after_1:
    // j           L_80070300
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_80070300;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_800702FC:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80070300:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
