#include "recomp.h"
#include "disable_warnings.h"

void sub_80031674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // lui         $t0, 0x1F80
    ctx->r8 = S32(0X1F80 << 16);
    // sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x2E0($t0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r8);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bgez        $v1, L_800316C0
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800316C0;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
L_800316C0:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_80031700
    if (ctx->r2 == 0) {
        // addiu       $t1, $zero, 0x14E
        ctx->r9 = ADD32(0, 0X14E);
        goto L_80031700;
    }
    // addiu       $t1, $zero, 0x14E
    ctx->r9 = ADD32(0, 0X14E);
    // sh          $t1, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r9;
    // addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // sh          $t1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r9;
    // addiu       $t1, $zero, 0x87
    ctx->r9 = ADD32(0, 0X87);
    // sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x20($sp)
    ctx->r9 = MEM_HU(0X20, ctx->r29);
    // j           L_80031720
    // addiu       $s4, $zero, 0x156
    ctx->r20 = ADD32(0, 0X156);
    goto L_80031720;
    // addiu       $s4, $zero, 0x156
    ctx->r20 = ADD32(0, 0X156);
L_80031700:
    // addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // sh          $t1, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r9;
    // addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // sh          $t1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r9;
    // addiu       $t1, $zero, 0x87
    ctx->r9 = ADD32(0, 0X87);
    // sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x20($sp)
    ctx->r9 = MEM_HU(0X20, ctx->r29);
    // addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_80031720:
    // sh          $t1, 0x350($t0)
    MEM_H(0X350, ctx->r8) = ctx->r9;
    // lhu         $t1, 0x28($sp)
    ctx->r9 = MEM_HU(0X28, ctx->r29);
    // addiu       $v0, $zero, 0xC0
    ctx->r2 = ADD32(0, 0XC0);
    // sh          $v0, 0x354($t0)
    MEM_H(0X354, ctx->r8) = ctx->r2;
    // addiu       $v0, $zero, 0x7C
    ctx->r2 = ADD32(0, 0X7C);
    // sh          $v0, 0x356($t0)
    MEM_H(0X356, ctx->r8) = ctx->r2;
    // sh          $t1, 0x352($t0)
    MEM_H(0X352, ctx->r8) = ctx->r9;
    // lhu         $v0, 0x2E0($t0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r8);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bgez        $v1, L_80031758
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80031758;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
L_80031758:
    // sra         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2) >> 3;
    // sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4) << 3;
    // subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_80031798
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80031798;
    }
    // nop

    // lh          $v0, 0x0($t0)
    ctx->r2 = MEM_HS(0X0, ctx->r8);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(0X4, ctx->r8);
    // j           L_800317C0
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    goto L_800317C0;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
L_80031798:
    // lhu         $v0, 0x2($t0)
    ctx->r2 = MEM_HU(0X2, ctx->r8);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lw          $v1, 0x8($t0)
    ctx->r3 = MEM_W(0X8, ctx->r8);
L_800317C0:
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $s3, 0x0($v0)
    ctx->r19 = MEM_HU(0X0, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_800317E4
    if (ctx->r3 != ctx->r2) {
        // addu        $v0, $a2, $zero
        ctx->r2 = ADD32(ctx->r6, 0);
        goto L_800317E4;
    }
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_800317E4:
    // bne         $v0, $zero, L_80031958
    if (ctx->r2 != 0) {
        // addiu       $s0, $t0, 0x358
        ctx->r16 = ADD32(ctx->r8, 0X358);
        goto L_80031958;
    }
    // addiu       $s0, $t0, 0x358
    ctx->r16 = ADD32(ctx->r8, 0X358);
    // addiu       $s1, $t0, 0x350
    ctx->r17 = ADD32(ctx->r8, 0X350);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // sh          $v0, 0x358($t0)
    MEM_H(0X358, ctx->r8) = ctx->r2;
    // sh          $zero, 0x35A($t0)
    MEM_H(0X35A, ctx->r8) = 0;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // jal         0x80028364
    // sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    sub_80028364(rdram, ctx);
    goto after_0;
    // sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_0:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(0X38, ctx->r29);
    // addu        $s6, $s4, $zero
    ctx->r22 = ADD32(ctx->r20, 0);
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // lhu         $v1, 0x350($t0)
    ctx->r3 = MEM_HU(0X350, ctx->r8);
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // sh          $v0, 0x354($t0)
    MEM_H(0X354, ctx->r8) = ctx->r2;
    // addiu       $v0, $zero, 0x340
    ctx->r2 = ADD32(0, 0X340);
    // sh          $v0, 0x358($t0)
    MEM_H(0X358, ctx->r8) = ctx->r2;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // addiu       $v1, $v1, 0xC0
    ctx->r3 = ADD32(ctx->r3, 0XC0);
    // jal         0x80028364
    // sh          $v1, 0x350($t0)
    MEM_H(0X350, ctx->r8) = ctx->r3;
    sub_80028364(rdram, ctx);
    goto after_1;
    // sh          $v1, 0x350($t0)
    MEM_H(0X350, ctx->r8) = ctx->r3;
    after_1:
    // sll         $v1, $s3, 16
    ctx->r3 = S32(ctx->r19) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x7820
    ctx->r3 = ADD32(ctx->r3, 0X7820);
    // addu        $s4, $v0, $v1
    ctx->r20 = ADD32(ctx->r2, ctx->r3);
    // lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(0X38, ctx->r29);
L_80031890:
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // addiu       $t1, $s6, 0x2A
    ctx->r9 = ADD32(ctx->r22, 0X2A);
    // sll         $v0, $fp, 1
    ctx->r2 = S32(ctx->r30) << 1;
    // sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // addiu       $t1, $t1, 0xD50
    ctx->r9 = ADD32(ctx->r9, 0XD50);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // addu        $s1, $v0, $t1
    ctx->r17 = ADD32(ctx->r2, ctx->r9);
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
L_800318B4:
    // addiu       $s7, $zero, 0xE
    ctx->r23 = ADD32(0, 0XE);
    // beq         $s5, $s7, L_80031958
    if (ctx->r21 == ctx->r23) {
        // nop
    
        goto L_80031958;
    }
    // nop

    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // nop

    // beq         $v0, $zero, L_8003191C
    if (ctx->r2 == 0) {
        // addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
        goto L_8003191C;
    }
    // addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // andi        $s0, $s2, 0xFFFF
    ctx->r16 = ctx->r18 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $a3, $t0, 0x300
    ctx->r7 = ADD32(ctx->r8, 0X300);
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // lhu         $a1, 0x30($sp)
    ctx->r5 = MEM_HU(0X30, ctx->r29);
    // lhu         $a0, 0x190($s1)
    ctx->r4 = MEM_HU(0X190, ctx->r17);
    // addiu       $t1, $t1, 0x1950
    ctx->r9 = ADD32(ctx->r9, 0X1950);
    // sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // jal         0x8002732C
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    sub_8002732C(rdram, ctx);
    goto after_2;
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    after_2:
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lui         $a0, 0x1300
    ctx->r4 = S32(0X1300 << 16);
    // lhu         $a1, 0x34($sp)
    ctx->r5 = MEM_HU(0X34, ctx->r29);
    // lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(0X38, ctx->r29);
    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // addiu       $a3, $t0, 0x310
    ctx->r7 = ADD32(ctx->r8, 0X310);
    // jal         0x80027440
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    sub_80027440(rdram, ctx);
    goto after_3;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    after_3:
    // lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(0X38, ctx->r29);
L_8003191C:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slti        $v0, $s3, 0x4
    ctx->r2 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_800318B4
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0xF
        ctx->r18 = ADD32(ctx->r18, 0XF);
        goto L_800318B4;
    }
    // addiu       $s2, $s2, 0xF
    ctx->r18 = ADD32(ctx->r18, 0XF);
    // beq         $s5, $s7, L_80031958
    if (ctx->r21 == ctx->r23) {
        // nop
    
        goto L_80031958;
    }
    // nop

    // lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(0X1C, ctx->r29);
    // addiu       $s6, $s6, 0x46
    ctx->r22 = ADD32(ctx->r22, 0X46);
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // slti        $v0, $t1, 0x4
    ctx->r2 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_80031890
    if (ctx->r2 != 0) {
        // sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
        goto L_80031890;
    }
    // sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
L_80031958:
    // lhu         $t1, 0x20($sp)
    ctx->r9 = MEM_HU(0X20, ctx->r29);
    // addiu       $a2, $zero, 0x128
    ctx->r6 = ADD32(0, 0X128);
    // addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
    // lhu         $t1, 0x28($sp)
    ctx->r9 = MEM_HU(0X28, ctx->r29);
    // addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    // jal         0x80029548
    // addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
    sub_80029548(rdram, ctx);
    goto after_4;
    // addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
    after_4:
    // lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(0X64, ctx->r29);
    // lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(0X60, ctx->r29);
    // lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(0X5C, ctx->r29);
    // lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(0X58, ctx->r29);
    // lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(0X54, ctx->r29);
    // lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(0X50, ctx->r29);
    // lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(0X4C, ctx->r29);
    // lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(0X48, ctx->r29);
    // lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(0X44, ctx->r29);
    // lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // jr          $ra
    // nop

    return;
    // nop

;}
