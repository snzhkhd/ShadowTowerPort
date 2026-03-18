#include "recomp.h"
#include "disable_warnings.h"

void sub_80050288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(0X44, ctx->r29);
    // addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // lbu         $s6, 0x40($sp)
    ctx->r22 = MEM_BU(0X40, ctx->r29);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // jal         0x8004F994
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    sub_8004F994(rdram, ctx);
    goto after_0;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    after_0:
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // sh          $s0, 0xA($s4)
    MEM_H(0XA, ctx->r20) = ctx->r16;
    // sb          $zero, 0x48($s4)
    MEM_B(0X48, ctx->r20) = 0;
    // lhu         $v0, 0x8($s5)
    ctx->r2 = MEM_HU(0X8, ctx->r21);
    // sb          $s2, 0x5($s4)
    MEM_B(0X5, ctx->r20) = ctx->r18;
    // sh          $s3, 0x50($s4)
    MEM_H(0X50, ctx->r20) = ctx->r19;
    // sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) << 16;
    // sh          $v0, 0x8($s4)
    MEM_H(0X8, ctx->r20) = ctx->r2;
    // sh          $s6, 0xC($s4)
    MEM_H(0XC, ctx->r20) = ctx->r22;
    // lh          $a0, 0x36($s5)
    ctx->r4 = MEM_HS(0X36, ctx->r21);
    // sra         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) >> 16;
    // jal         0x800744C4
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    rcos(rdram, ctx);
    goto after_1;
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    after_1:
    // bgez        $v0, L_80050318
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80050318;
    }
    // nop

    // addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
L_80050318:
    // lh          $a0, 0x36($s5)
    ctx->r4 = MEM_HS(0X36, ctx->r21);
    // sra         $s0, $v0, 4
    ctx->r16 = S32(ctx->r2) >> 4;
    // jal         0x800743F4
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    rsin(rdram, ctx);
    goto after_2;
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    after_2:
    // bgez        $v0, L_80050334
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80050334;
    }
    // nop

    // addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
L_80050334:
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // sh          $v0, 0x56($s4)
    MEM_H(0X56, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sb          $v0, 0x4($s4)
    MEM_B(0X4, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sh          $s0, 0x52($s4)
    MEM_H(0X52, ctx->r20) = ctx->r16;
    // sh          $zero, 0x54($s4)
    MEM_H(0X54, ctx->r20) = 0;
    // sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
    // sb          $v0, 0x2($s4)
    MEM_B(0X2, ctx->r20) = ctx->r2;
    // jal         0x80078AC4
    // sh          $zero, 0x34($s4)
    MEM_H(0X34, ctx->r20) = 0;
    rand_recomp(rdram, ctx);
    goto after_3;
    // sh          $zero, 0x34($s4)
    MEM_H(0X34, ctx->r20) = 0;
    after_3:
    // bgez        $v0, L_8005036C
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8005036C;
    }
    // nop

    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
L_8005036C:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x38($s4)
    MEM_H(0X38, ctx->r20) = ctx->r2;
    // lhu         $v0, 0x36($s5)
    ctx->r2 = MEM_HU(0X36, ctx->r21);
    // andi        $s0, $s6, 0xFF
    ctx->r16 = ctx->r22 & 0XFF;
    // sh          $v0, 0x36($s4)
    MEM_H(0X36, ctx->r20) = ctx->r2;
    // lhu         $v1, 0x14($s5)
    ctx->r3 = MEM_HU(0X14, ctx->r21);
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // sb          $v0, 0x3($s4)
    MEM_B(0X3, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x6($s4)
    MEM_B(0X6, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // sh          $v0, 0x16($s4)
    MEM_H(0X16, ctx->r20) = ctx->r2;
    // sll         $v0, $s0, 10
    ctx->r2 = S32(ctx->r16) << 10;
    // sh          $v0, 0x40($s4)
    MEM_H(0X40, ctx->r20) = ctx->r2;
    // sh          $v0, 0x3E($s4)
    MEM_H(0X3E, ctx->r20) = ctx->r2;
    // sh          $v0, 0x3C($s4)
    MEM_H(0X3C, ctx->r20) = ctx->r2;
    // sh          $v1, 0x14($s4)
    MEM_H(0X14, ctx->r20) = ctx->r3;
    // lh          $a0, 0x36($s5)
    ctx->r4 = MEM_HS(0X36, ctx->r21);
    // jal         0x800744C4
    // sll         $s0, $s0, 8
    ctx->r16 = S32(ctx->r16) << 8;
    rcos(rdram, ctx);
    goto after_4;
    // sll         $s0, $s0, 8
    ctx->r16 = S32(ctx->r16) << 8;
    after_4:
    // lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(0X48, ctx->r29);
    // nop

    // subu        $v1, $s0, $v1
    ctx->r3 = SUB32(ctx->r16, ctx->r3);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_800503DC
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_800503DC;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_800503DC:
    // lw          $v0, 0x24($s5)
    ctx->r2 = MEM_W(0X24, ctx->r21);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->r2;
    // lw          $v0, 0x28($s5)
    ctx->r2 = MEM_W(0X28, ctx->r21);
    // lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(0X4C, ctx->r29);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->r2;
    // lh          $a0, 0x36($s5)
    ctx->r4 = MEM_HS(0X36, ctx->r21);
    // jal         0x800743F4
    // nop

    rsin(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(0X50, ctx->r29);
    // nop

    // subu        $v1, $s0, $v1
    ctx->r3 = SUB32(ctx->r16, ctx->r3);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // bgez        $a0, L_8005042C
    if (SIGNED(ctx->r4) >= 0) {
        // addu        $v0, $s4, $zero
        ctx->r2 = ADD32(ctx->r20, 0);
        goto L_8005042C;
    }
    // addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // addiu       $a0, $a0, 0xFFF
    ctx->r4 = ADD32(ctx->r4, 0XFFF);
L_8005042C:
    // lw          $v1, 0x2C($s5)
    ctx->r3 = MEM_W(0X2C, ctx->r21);
    // sra         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4) >> 12;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
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
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
