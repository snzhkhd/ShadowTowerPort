#include "recomp.h"
#include "disable_warnings.h"

void sub_80052894(uint8_t* rdram, recomp_context* ctx) 
{
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // addiu       $a0, $zero, 0xF0
    ctx->r4 = ADD32(0, 0XF0);
    // addiu       $a2, $zero, 0xED
    ctx->r6 = ADD32(0, 0XED);
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x2230
    ctx->r2 = ADD32(ctx->r2, 0X2230);
    // addiu       $v1, $v0, 0x50
    ctx->r3 = ADD32(ctx->r2, 0X50);
    // sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
L_800528DC:
    // lbu         $v0, -0x4B($v1)
    ctx->r2 = MEM_BU(-0X4B, ctx->r3);
    // nop

    // bne         $v0, $a2, L_800528F0
    if (ctx->r2 != ctx->r6) {
        // nop
    
        goto L_800528F0;
    }
    // nop

    // sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
L_800528F0:
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $zero, L_800528DC
    if (ctx->r4 != 0) {
        // addiu       $v1, $v1, 0x58
        ctx->r3 = ADD32(ctx->r3, 0X58);
        goto L_800528DC;
    }
    // addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // lbu         $s3, 0x1($s2)
    ctx->r19 = MEM_BU(0X1, ctx->r18);
    // lbu         $s5, 0x2($s2)
    ctx->r21 = MEM_BU(0X2, ctx->r18);
    // lbu         $s4, 0x3($s2)
    ctx->r20 = MEM_BU(0X3, ctx->r18);
    // jal         0x80057C54
    // lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    sub_80057C54(rdram, ctx);
    goto after_0;
    // lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    after_0:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    // jal         0x800500AC
    // addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    sub_800500AC(rdram, ctx);
    goto after_1;
    // addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_1:
    // lbu         $s6, 0x0($s2)
    ctx->r22 = MEM_BU(0X0, ctx->r18);
L_80052928:
    // jal         0x8001531C
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x800456F8
    // nop

    sub_800456F8(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lh          $v0, 0x5920($s0)
    ctx->r2 = MEM_HS(0X5920, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80052928
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80052928;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $v0, -0x70D8
    ctx->r17 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0xA($s2)
    ctx->r3 = MEM_HU(0XA, ctx->r18);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // sh          $zero, 0x278($s1)
    MEM_H(0X278, ctx->r17) = 0;
    // sh          $v1, 0x27A($s1)
    MEM_H(0X27A, ctx->r17) = ctx->r3;
    // lbu         $v0, 0x5924($v0)
    ctx->r2 = MEM_BU(0X5924, ctx->r2);
    // andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    // beq         $a2, $v0, L_800529A4
    if (ctx->r6 == ctx->r2) {
        // addu        $a1, $a2, $zero
        ctx->r5 = ADD32(ctx->r6, 0);
        goto L_800529A4;
    }
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // jal         0x80045044
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    sub_80045044(rdram, ctx);
    goto after_4;
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_4:
    // j           L_80052A08
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    goto L_80052A08;
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
L_800529A4:
    // addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // jal         0x80045044
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    sub_80045044(rdram, ctx);
    goto after_5;
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_5:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x8004E2D8
    // sb          $v0, 0x21C($s1)
    MEM_B(0X21C, ctx->r17) = ctx->r2;
    sub_8004E2D8(rdram, ctx);
    goto after_6;
    // sb          $v0, 0x21C($s1)
    MEM_B(0X21C, ctx->r17) = ctx->r2;
    after_6:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // sh          $s0, 0x615E($v0)
    MEM_H(0X615E, ctx->r2) = ctx->r16;
    // sh          $s0, 0x615C($v0)
    MEM_H(0X615C, ctx->r2) = ctx->r16;
    // sh          $s0, 0x615A($v0)
    MEM_H(0X615A, ctx->r2) = ctx->r16;
    // sh          $s0, 0x6158($v0)
    MEM_H(0X6158, ctx->r2) = ctx->r16;
    // sb          $v1, 0x6103($v0)
    MEM_B(0X6103, ctx->r2) = ctx->r3;
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
L_80052A08:
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // sb          $zero, 0x218($s0)
    MEM_B(0X218, ctx->r16) = 0;
    // sh          $zero, 0x28C($s0)
    MEM_H(0X28C, ctx->r16) = 0;
    // sh          $zero, 0x28A($s0)
    MEM_H(0X28A, ctx->r16) = 0;
    // sh          $zero, 0x288($s0)
    MEM_H(0X288, ctx->r16) = 0;
    // lwl         $v0, 0x27B($s0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X27B, ctx->r16);
    // lwr         $v0, 0x278($s0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X278, ctx->r16);
    // lwl         $v1, 0x27F($s0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X27F, ctx->r16);
    // lwr         $v1, 0x27C($s0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X27C, ctx->r16);
    // swl         $v0, 0x26B($s0)
    do_swl(rdram, 0X26B, ctx->r16, ctx->r2);
    // swr         $v0, 0x268($s0)
    do_swr(rdram, 0X268, ctx->r16, ctx->r2);
    // swl         $v1, 0x26F($s0)
    do_swl(rdram, 0X26F, ctx->r16, ctx->r3);
    // swr         $v1, 0x26C($s0)
    do_swr(rdram, 0X26C, ctx->r16, ctx->r3);
    // lh          $v1, 0x4($s2)
    ctx->r3 = MEM_HS(0X4, ctx->r18);
    // sll         $v0, $s3, 12
    ctx->r2 = S32(ctx->r19) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->r2;
    // lh          $v1, 0x8($s2)
    ctx->r3 = MEM_HS(0X8, ctx->r18);
    // sll         $v0, $s4, 12
    ctx->r2 = S32(ctx->r20) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->r2;
    // lh          $v1, 0x6($s2)
    ctx->r3 = MEM_HS(0X6, ctx->r18);
    // sll         $v0, $s5, 12
    ctx->r2 = S32(ctx->r21) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x8003EAD0
    // sw          $v0, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->r2;
    sub_8003EAD0(rdram, ctx);
    goto after_7;
    // sw          $v0, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->r2;
    after_7:
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $a0, $v0, -0x1CE8
    ctx->r4 = ADD32(ctx->r2, -0X1CE8);
    // addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x310
    ctx->r2 = ADD32(ctx->r2, 0X310);
    // sh          $zero, 0x71A8($v0)
    MEM_H(0X71A8, ctx->r2) = 0;
    // sh          $zero, 0x71A6($v0)
    MEM_H(0X71A6, ctx->r2) = 0;
    // sh          $zero, 0x71A4($v0)
    MEM_H(0X71A4, ctx->r2) = 0;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, 0x5948
    ctx->r2 = ADD32(ctx->r2, 0X5948);
    // sh          $zero, 0x47D2($v0)
    MEM_H(0X47D2, ctx->r2) = 0;
    // sh          $zero, 0x47D0($v0)
    MEM_H(0X47D0, ctx->r2) = 0;
    // sh          $zero, 0x47CE($v0)
    MEM_H(0X47CE, ctx->r2) = 0;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // sh          $zero, 0x6164($v0)
    MEM_H(0X6164, ctx->r2) = 0;
    // sh          $zero, 0x6162($v0)
    MEM_H(0X6162, ctx->r2) = 0;
    // sh          $zero, 0x6160($v0)
    MEM_H(0X6160, ctx->r2) = 0;
    // sh          $zero, 0x1D0($s0)
    MEM_H(0X1D0, ctx->r16) = 0;
    // sh          $zero, 0x1CE($s0)
    MEM_H(0X1CE, ctx->r16) = 0;
    // sh          $zero, 0x1CC($s0)
    MEM_H(0X1CC, ctx->r16) = 0;
L_80052ACC:
    // sb          $a2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r6;
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $a1, L_80052ACC
    if (ctx->r3 != ctx->r5) {
        // addiu       $a0, $a0, 0x58
        ctx->r4 = ADD32(ctx->r4, 0X58);
        goto L_80052ACC;
    }
    // addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
L_80052AE0:
    // jal         0x8001531C
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // jal         0x800456F8
    // nop

    sub_800456F8(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lh          $v0, 0x5920($s0)
    ctx->r2 = MEM_HS(0X5920, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80052AE0
    if (ctx->r2 != 0) {
        // andi        $v0, $s7, 0xFF
        ctx->r2 = ctx->r23 & 0XFF;
        goto L_80052AE0;
    }
    // andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // bne         $v0, $zero, L_80052B6C
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
        goto L_80052B6C;
    }
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $v0, -0x6E90
    ctx->r17 = ADD32(ctx->r2, -0X6E90);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $s0, $v0, 0x5948
    ctx->r16 = ADD32(ctx->r2, 0X5948);
    // jal         0x80046270
    // sh          $zero, 0x44CA($s0)
    MEM_H(0X44CA, ctx->r16) = 0;
    sub_80046270(rdram, ctx);
    goto after_10;
    // sh          $zero, 0x44CA($s0)
    MEM_H(0X44CA, ctx->r16) = 0;
    after_10:
    // lhu         $v0, 0x44CA($s0)
    ctx->r2 = MEM_HU(0X44CA, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80052B60
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052B60;
    }
    // nop

    // lhu         $v0, 0x44CE($s0)
    ctx->r2 = MEM_HU(0X44CE, ctx->r16);
    // nop

    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x4130
    ctx->r2 = ADD32(ctx->r2, -0X4130);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, -0xD4($s1)
    MEM_W(-0XD4, ctx->r17) = ctx->r3;
L_80052B60:
    // jal         0x8004E324
    // nop

    sub_8004E324(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80052B6C:
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x800500AC
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_800500AC(rdram, ctx);
    goto after_12;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_12:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // jal         0x80057C54
    // nop

    sub_80057C54(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x800500AC
    // addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    sub_800500AC(rdram, ctx);
    goto after_15;
    // addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    after_15:
    // andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // bne         $v0, $zero, L_80052BE4
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
        goto L_80052BE4;
    }
    // addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // jal         0x80045044
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    sub_80045044(rdram, ctx);
    goto after_16;
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_16:
    // jal         0x800330F0
    // nop

    sub_800330F0(rdram, ctx);
    goto after_17;
    // nop

    after_17:
L_80052BE4:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // jal         0x80042C10
    // nop

    sub_80042C10(rdram, ctx);
    goto after_19;
    // nop

    after_19:
    // lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(0X50, ctx->r29);
    // lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(0X4C, ctx->r29);
    // lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(0X48, ctx->r29);
    // lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(0X44, ctx->r29);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
