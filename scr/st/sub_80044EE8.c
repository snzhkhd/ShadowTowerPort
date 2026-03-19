#include "recomp.h"
#include "disable_warnings.h"

void sub_80044EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // addiu       $v0, $s1, 0x5920
    ctx->r2 = ADD32(ctx->r17, 0X5920);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addiu       $s2, $zero, 0xF0
    ctx->r18 = ADD32(0, 0XF0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sh          $v0, 0x5920($s1)
    MEM_H(0X5920, ctx->r17) = ctx->r2;
    // lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(0X4, ctx->r16);
    // lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(0X5, ctx->r16);
    // lbu         $a1, 0x6($s0)
    ctx->r5 = MEM_BU(0X6, ctx->r16);
    // lbu         $a2, 0x7($s0)
    ctx->r6 = MEM_BU(0X7, ctx->r16);
    // lbu         $a3, 0x8($s0)
    ctx->r7 = MEM_BU(0X8, ctx->r16);
    // addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
    // sb          $v0, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r2;
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // sb          $v0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r2;
    // sb          $v0, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r2;
    // sb          $v0, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r2;
    // sb          $zero, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = 0;
    // sb          $v1, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r3;
    // sb          $a0, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r4;
    // sb          $a1, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r5;
    // sb          $a2, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r6;
    // sb          $a3, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r7;
L_80044F70:
    // jal         0x8001531C
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x800456F8
    // nop

    sub_800456F8(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lh          $v0, 0x5920($s1)
    ctx->r2 = MEM_HS(0X5920, ctx->r17);
    // nop

    // beq         $v0, $zero, L_80044FC4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80044FC4;
    }
    // nop

    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_80044F70
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80044F70;
    }
    // nop

    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // beq         $v0, $s2, L_80044F70
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_80044F70;
    }
    // nop

L_80044FC4:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // addiu       $v0, $v0, -0x3B78
    ctx->r2 = ADD32(ctx->r2, -0X3B78);
    // sw          $v0, 0x308($v1)
    MEM_W(0X308, ctx->r3) = ctx->r2;
    // lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // addiu       $v0, $v0, 0x2C88
    ctx->r2 = ADD32(ctx->r2, 0X2C88);
    // sw          $v0, 0x30C($v1)
    MEM_W(0X30C, ctx->r3) = ctx->r2;
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
