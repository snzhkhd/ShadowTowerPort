#include "recomp.h"
#include "disable_warnings.h"

void sub_8002F97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x7F80
    ctx->r6 = ADD32(ctx->r2, 0X7F80);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r3);
    // swr         $v1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r3);
    // addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x98
    ctx->r2 = ADD32(0, 0X98);
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // lbu         $v1, 0x303($s3)
    ctx->r3 = MEM_BU(0X303, ctx->r19);
    // lhu         $v0, 0x2BE($s3)
    ctx->r2 = MEM_HU(0X2BE, ctx->r19);
    // ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sb          $v1, 0x303($s3)
    MEM_B(0X303, ctx->r19) = ctx->r3;
    // lw          $v1, 0x2CC($s3)
    ctx->r3 = MEM_W(0X2CC, ctx->r19);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $a0, 0x400($v0)
    ctx->r4 = MEM_HU(0X400, ctx->r2);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_0;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_0:
    // lui         $v1, 0xF
    ctx->r3 = S32(0XF << 16);
    // ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // ori         $a2, $a2, 0x4
    ctx->r6 = ctx->r6 | 0X4;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // lbu         $v0, 0x303($s3)
    ctx->r2 = MEM_BU(0X303, ctx->r19);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // jal         0x8002F1F8
    // sb          $v0, 0x303($s3)
    MEM_B(0X303, ctx->r19) = ctx->r2;
    sub_8002F1F8(rdram, ctx);
    goto after_1;
    // sb          $v0, 0x303($s3)
    MEM_B(0X303, ctx->r19) = ctx->r2;
    after_1:
    // lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // lhu         $t0, 0x2BE($s3)
    ctx->r8 = MEM_HU(0X2BE, ctx->r19);
    // ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    // sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8) << 16;
    // sra         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8) >> 16;
    // mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // ori         $a0, $a0, 0x330
    ctx->r4 = ctx->r4 | 0X330;
    // addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addiu       $a2, $zero, 0x201
    ctx->r6 = ADD32(0, 0X201);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // addiu       $s2, $zero, 0x30
    ctx->r18 = ADD32(0, 0X30);
    // addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // sh          $s2, 0x334($s3)
    MEM_H(0X334, ctx->r19) = ctx->r18;
    // sh          $s1, 0x336($s3)
    MEM_H(0X336, ctx->r19) = ctx->r17;
    // sra         $t0, $t0, 31
    ctx->r8 = S32(ctx->r8) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // subu        $t0, $t2, $t0
    ctx->r8 = SUB32(ctx->r10, ctx->r8);
    // sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0xB
    ctx->r2 = ADD32(ctx->r2, 0XB);
    // sh          $v0, 0x330($s3)
    MEM_H(0X330, ctx->r19) = ctx->r2;
    // sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8) << 1;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) << 16;
    // sra         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) >> 16;
    // sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9) << 1;
    // addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // jal         0x80027D18
    // sh          $v0, 0x332($s3)
    MEM_H(0X332, ctx->r19) = ctx->r2;
    sub_80027D18(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x332($s3)
    MEM_H(0X332, ctx->r19) = ctx->r2;
    after_2:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // ori         $a0, $a0, 0x330
    ctx->r4 = ctx->r4 | 0X330;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // lhu         $v0, 0x330($s3)
    ctx->r2 = MEM_HU(0X330, ctx->r19);
    // lhu         $v1, 0x332($s3)
    ctx->r3 = MEM_HU(0X332, ctx->r19);
    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // sh          $v0, 0x330($s3)
    MEM_H(0X330, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x334($s3)
    ctx->r2 = MEM_HU(0X334, ctx->r19);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sh          $v1, 0x332($s3)
    MEM_H(0X332, ctx->r19) = ctx->r3;
    // lhu         $v1, 0x336($s3)
    ctx->r3 = MEM_HU(0X336, ctx->r19);
    // addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // sh          $v0, 0x334($s3)
    MEM_H(0X334, ctx->r19) = ctx->r2;
    // jal         0x80028220
    // sh          $v1, 0x336($s3)
    MEM_H(0X336, ctx->r19) = ctx->r3;
    sub_80028220(rdram, ctx);
    goto after_3;
    // sh          $v1, 0x336($s3)
    MEM_H(0X336, ctx->r19) = ctx->r3;
    after_3:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_4;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_4:
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // sh          $s2, 0x354($s3)
    MEM_H(0X354, ctx->r19) = ctx->r18;
    // sh          $s1, 0x356($s3)
    MEM_H(0X356, ctx->r19) = ctx->r17;
    // sh          $v0, 0x352($s3)
    MEM_H(0X352, ctx->r19) = ctx->r2;
    // sh          $zero, 0x35A($s3)
    MEM_H(0X35A, ctx->r19) = 0;
L_8002FB44:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F80
    ctx->r6 = ADD32(ctx->r2, 0X7F80);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r3);
    // swr         $v1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r3);
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addu        $s0, $s4, $zero
    ctx->r16 = ADD32(ctx->r20, 0);
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // sh          $v0, 0x350($s3)
    MEM_H(0X350, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // sh          $v0, 0x358($s3)
    MEM_H(0X358, ctx->r19) = ctx->r2;
L_8002FB78:
    // lw          $v0, 0x2D4($s3)
    ctx->r2 = MEM_W(0X2D4, ctx->r19);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // sllv        $v1, $v1, $s0
    ctx->r3 = S32(ctx->r3) << (ctx->r16 & 31);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8002FBB4
    if (ctx->r2 != 0) {
        // addiu       $a0, $s3, 0x350
        ctx->r4 = ADD32(ctx->r19, 0X350);
        goto L_8002FBB4;
    }
    // addiu       $a0, $s3, 0x350
    ctx->r4 = ADD32(ctx->r19, 0X350);
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // jal         0x80028220
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_80028220(rdram, ctx);
    goto after_5;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_6;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_6:
    // addiu       $a0, $s3, 0x350
    ctx->r4 = ADD32(ctx->r19, 0X350);
L_8002FBB4:
    // addiu       $a1, $s3, 0x358
    ctx->r5 = ADD32(ctx->r19, 0X358);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_7;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_7:
    // addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // lhu         $v0, 0x350($s3)
    ctx->r2 = MEM_HU(0X350, ctx->r19);
    // lhu         $v1, 0x358($s3)
    ctx->r3 = MEM_HU(0X358, ctx->r19);
    // addiu       $v0, $v0, 0x31
    ctx->r2 = ADD32(ctx->r2, 0X31);
    // addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // sh          $v0, 0x350($s3)
    MEM_H(0X350, ctx->r19) = ctx->r2;
    // slti        $v0, $s1, 0x6
    ctx->r2 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_8002FB78
    if (ctx->r2 != 0) {
        // sh          $v1, 0x358($s3)
        MEM_H(0X358, ctx->r19) = ctx->r3;
        goto L_8002FB78;
    }
    // sh          $v1, 0x358($s3)
    MEM_H(0X358, ctx->r19) = ctx->r3;
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // lhu         $v0, 0x352($s3)
    ctx->r2 = MEM_HU(0X352, ctx->r19);
    // lhu         $v1, 0x35A($s3)
    ctx->r3 = MEM_HU(0X35A, ctx->r19);
    // addiu       $v0, $v0, 0x19
    ctx->r2 = ADD32(ctx->r2, 0X19);
    // addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // sh          $v0, 0x352($s3)
    MEM_H(0X352, ctx->r19) = ctx->r2;
    // slti        $v0, $s4, 0x2
    ctx->r2 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8002FB44
    if (ctx->r2 != 0) {
        // sh          $v1, 0x35A($s3)
        MEM_H(0X35A, ctx->r19) = ctx->r3;
        goto L_8002FB44;
    }
    // sh          $v1, 0x35A($s3)
    MEM_H(0X35A, ctx->r19) = ctx->r3;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_8;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_8:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
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
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
