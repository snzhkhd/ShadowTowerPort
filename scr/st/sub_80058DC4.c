#include "recomp.h"
#include "disable_warnings.h"

void sub_80058DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addiu       $s4, $zero, 0x100
    ctx->r20 = ADD32(0, 0X100);
    // addiu       $v1, $zero, 0x230
    ctx->r3 = ADD32(0, 0X230);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sh          $v0, 0x2E6($s3)
    MEM_H(0X2E6, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x1EF
    ctx->r2 = ADD32(0, 0X1EF);
    // sh          $v0, 0x2EC($s3)
    MEM_H(0X2EC, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // sh          $v0, 0x2EE($s3)
    MEM_H(0X2EE, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x1F1
    ctx->r2 = ADD32(0, 0X1F1);
    // sh          $v0, 0x2F4($s3)
    MEM_H(0X2F4, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // sh          $s4, 0x2E8($s3)
    MEM_H(0X2E8, ctx->r19) = ctx->r20;
    // sh          $v1, 0x2EA($s3)
    MEM_H(0X2EA, ctx->r19) = ctx->r3;
    // sh          $s4, 0x2F0($s3)
    MEM_H(0X2F0, ctx->r19) = ctx->r20;
    // sh          $v1, 0x2F2($s3)
    MEM_H(0X2F2, ctx->r19) = ctx->r3;
    // sh          $v0, 0x2F6($s3)
    MEM_H(0X2F6, ctx->r19) = ctx->r2;
    // jal         0x80015AD4
    // sh          $s4, 0x2F8($s3)
    MEM_H(0X2F8, ctx->r19) = ctx->r20;
    sub_80015AD4(rdram, ctx);
    goto after_0;
    // sh          $s4, 0x2F8($s3)
    MEM_H(0X2F8, ctx->r19) = ctx->r20;
    after_0:
    // lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // addiu       $s0, $s1, -0x7378
    ctx->r16 = ADD32(ctx->r17, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_1;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    sub_80014CFC(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_2:
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // ori         $a1, $a1, 0x2E6
    ctx->r5 = ctx->r5 | 0X2E6;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // ori         $a2, $a2, 0x2EA
    ctx->r6 = ctx->r6 | 0X2EA;
    // lw          $v0, -0x7378($s1)
    ctx->r2 = MEM_W(-0X7378, ctx->r17);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // jal         0x8003EC5C
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_3;
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // jal         0x80058C04
    // nop

    PadChkVsync(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // sb          $zero, 0x2E5($s3)
    MEM_B(0X2E5, ctx->r19) = 0;
    // beq         $s2, $zero, L_80058EA0
    if (ctx->r18 == 0) {
        // sw          $zero, 0x208($s3)
        MEM_W(0X208, ctx->r19) = 0;
        goto L_80058EA0;
    }
    // sw          $zero, 0x208($s3)
    MEM_W(0X208, ctx->r19) = 0;
    // j           L_80058EA8
    // sh          $s4, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = ctx->r20;
    goto L_80058EA8;
    // sh          $s4, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = ctx->r20;
L_80058EA0:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = ctx->r2;
L_80058EA8:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_5;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_5:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
