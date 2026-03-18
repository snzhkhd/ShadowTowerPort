#include "recomp.h"
#include "disable_warnings.h"

void sub_8005A3A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // beq         $s1, $zero, L_8005A3CC
    if (ctx->r17 == 0) {
        // sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
        goto L_8005A3CC;
    }
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x8005975C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8005975C(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
L_8005A3CC:
    // jal         0x80059DC0
    // nop

    sub_80059DC0(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // lhu         $v0, 0x1B4($s0)
    ctx->r2 = MEM_HU(0X1B4, ctx->r16);
    // addiu       $a2, $t1, -0x70D8
    ctx->r6 = ADD32(ctx->r9, -0X70D8);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x1B6($s0)
    ctx->r2 = MEM_HU(0X1B6, ctx->r16);
    // lhu         $a0, 0x1B8($s0)
    ctx->r4 = MEM_HU(0X1B8, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lhu         $v0, 0x1BA($s0)
    ctx->r2 = MEM_HU(0X1BA, ctx->r16);
    // lhu         $a1, 0x1BC($s0)
    ctx->r5 = MEM_HU(0X1BC, ctx->r16);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // lhu         $v0, 0x1BE($s0)
    ctx->r2 = MEM_HU(0X1BE, ctx->r16);
    // lhu         $v1, 0x1C0($s0)
    ctx->r3 = MEM_HU(0X1C0, ctx->r16);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $a1, 0xCCCC
    ctx->r5 = S32(0XCCCC << 16);
    // ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // sh          $v1, -0x70D8($t1)
    MEM_H(-0X70D8, ctx->r9) = ctx->r3;
    // lhu         $v0, 0x1C2($s0)
    ctx->r2 = MEM_HU(0X1C2, ctx->r16);
    // lhu         $a0, 0x1C6($s0)
    ctx->r4 = MEM_HU(0X1C6, ctx->r16);
    // lhu         $t0, -0x70D8($t1)
    ctx->r8 = MEM_HU(-0X70D8, ctx->r9);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x1C4($s0)
    ctx->r2 = MEM_HU(0X1C4, ctx->r16);
    // multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lhu         $v0, 0x1C8($s0)
    ctx->r2 = MEM_HU(0X1C8, ctx->r16);
    // lhu         $v1, 0x1CA($s0)
    ctx->r3 = MEM_HU(0X1CA, ctx->r16);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x1CC($s0)
    ctx->r2 = MEM_HU(0X1CC, ctx->r16);
    // lhu         $a0, 0x1CE($s0)
    ctx->r4 = MEM_HU(0X1CE, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sh          $a0, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r4;
    // mfhi        $a3
    ctx->r7 = hi;
    // lhu         $v0, 0x4($a2)
    ctx->r2 = MEM_HU(0X4, ctx->r6);
    // nop

    // multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(0X2C, ctx->r6);
    // srl         $v1, $a3, 6
    ctx->r3 = S32(U32(ctx->r7) >> 6);
    // sh          $v1, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r3;
    // andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // mfhi        $a1
    ctx->r5 = hi;
    // srl         $a1, $a1, 6
    ctx->r5 = S32(U32(ctx->r5) >> 6);
    // beq         $v0, $zero, L_8005A4C4
    if (ctx->r2 == 0) {
        // sh          $a1, 0xB8($a2)
        MEM_H(0XB8, ctx->r6) = ctx->r5;
        goto L_8005A4C4;
    }
    // sh          $a1, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r5;
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // sh          $v0, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r2;
    // andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // sh          $v0, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r2;
L_8005A4C4:
    // bne         $t0, $zero, L_8005A4D8
    if (ctx->r8 != 0) {
        // andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
        goto L_8005A4D8;
    }
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, -0x70D8($t1)
    MEM_H(-0X70D8, ctx->r9) = ctx->r2;
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_8005A4D8:
    // bne         $v0, $zero, L_8005A4E4
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8005A4E4;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r2;
L_8005A4E4:
    // lhu         $v0, 0xB6($a2)
    ctx->r2 = MEM_HU(0XB6, ctx->r6);
    // nop

    // bne         $v0, $zero, L_8005A4F8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8005A4F8;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r2;
L_8005A4F8:
    // lhu         $v0, 0xB8($a2)
    ctx->r2 = MEM_HU(0XB8, ctx->r6);
    // nop

    // bne         $v0, $zero, L_8005A50C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8005A50C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r2;
L_8005A50C:
    // lhu         $v1, 0x3E($a2)
    ctx->r3 = MEM_HU(0X3E, ctx->r6);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8005A5E4
    if (ctx->r3 == ctx->r2) {
        // addiu       $a1, $a2, 0xC0
        ctx->r5 = ADD32(ctx->r6, 0XC0);
        goto L_8005A5E4;
    }
    // addiu       $a1, $a2, 0xC0
    ctx->r5 = ADD32(ctx->r6, 0XC0);
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // lhu         $v0, 0x1D8($s0)
    ctx->r2 = MEM_HU(0X1D8, ctx->r16);
    // lhu         $a0, 0xB6($a2)
    ctx->r4 = MEM_HU(0XB6, ctx->r6);
    // lhu         $v1, 0x1DA($s0)
    ctx->r3 = MEM_HU(0X1DA, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 17
    ctx->r3 = S32(ctx->r3) >> 17;
    // sh          $v0, 0xBA($a2)
    MEM_H(0XBA, ctx->r6) = ctx->r2;
    // lhu         $v0, 0x1DC($s0)
    ctx->r2 = MEM_HU(0X1DC, ctx->r16);
    // addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // sh          $v1, 0xBC($a2)
    MEM_H(0XBC, ctx->r6) = ctx->r3;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sh          $a0, 0xBE($a2)
    MEM_H(0XBE, ctx->r6) = ctx->r4;
L_8005A560:
    // lbu         $v0, 0x69($s0)
    ctx->r2 = MEM_BU(0X69, ctx->r16);
    // nop

    // bne         $v0, $t0, L_8005A5C8
    if (ctx->r2 != ctx->r8) {
        // nop
    
        goto L_8005A5C8;
    }
    // nop

    // lhu         $v0, 0x6A($s0)
    ctx->r2 = MEM_HU(0X6A, ctx->r16);
    // lhu         $v1, 0xB8($a2)
    ctx->r3 = MEM_HU(0XB8, ctx->r6);
    // lbu         $a0, 0x29($s0)
    ctx->r4 = MEM_BU(0X29, ctx->r16);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // bne         $a0, $t0, L_8005A5A0
    if (ctx->r4 != ctx->r8) {
        // sh          $v1, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r3;
        goto L_8005A5A0;
    }
    // sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    // lhu         $v0, 0x2A($s0)
    ctx->r2 = MEM_HU(0X2A, ctx->r16);
    // nop

    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_8005A5A0:
    // lbu         $v0, 0x129($s0)
    ctx->r2 = MEM_BU(0X129, ctx->r16);
    // nop

    // bne         $v0, $t0, L_8005A5CC
    if (ctx->r2 != ctx->r8) {
        // nop
    
        goto L_8005A5CC;
    }
    // nop

    // lhu         $v0, 0x12A($s0)
    ctx->r2 = MEM_HU(0X12A, ctx->r16);
    // lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(0X0, ctx->r5);
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_8005A5CC
    // sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    goto L_8005A5CC;
    // sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_8005A5C8:
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_8005A5CC:
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // slti        $v0, $t0, 0x6
    ctx->r2 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_8005A608
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005A608;
    }
    // nop

    // j           L_8005A560
    // nop

    goto L_8005A560;
    // nop

L_8005A5E4:
    // sh          $zero, 0xCA($a2)
    MEM_H(0XCA, ctx->r6) = 0;
    // sh          $zero, 0xC8($a2)
    MEM_H(0XC8, ctx->r6) = 0;
    // sh          $zero, 0xC6($a2)
    MEM_H(0XC6, ctx->r6) = 0;
    // sh          $zero, 0xC4($a2)
    MEM_H(0XC4, ctx->r6) = 0;
    // sh          $zero, 0xC2($a2)
    MEM_H(0XC2, ctx->r6) = 0;
    // sh          $zero, 0xC0($a2)
    MEM_H(0XC0, ctx->r6) = 0;
    // sh          $zero, 0xBE($a2)
    MEM_H(0XBE, ctx->r6) = 0;
    // sh          $zero, 0xBC($a2)
    MEM_H(0XBC, ctx->r6) = 0;
    // sh          $zero, 0xBA($a2)
    MEM_H(0XBA, ctx->r6) = 0;
L_8005A608:
    // lhu         $v1, 0x16C($s0)
    ctx->r3 = MEM_HU(0X16C, ctx->r16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8005A668
    if (ctx->r3 == ctx->r2) {
        // lui         $a0, 0x2AAA
        ctx->r4 = S32(0X2AAA << 16);
        goto L_8005A668;
    }
    // lui         $a0, 0x2AAA
    ctx->r4 = S32(0X2AAA << 16);
    // lhu         $v0, 0x16C($s0)
    ctx->r2 = MEM_HU(0X16C, ctx->r16);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lhu         $v0, 0x1CA($v0)
    ctx->r2 = MEM_HU(0X1CA, ctx->r2);
    // ori         $a0, $a0, 0xAAAB
    ctx->r4 = ctx->r4 | 0XAAAB;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // lhu         $v1, 0xB8($a1)
    ctx->r3 = MEM_HU(0XB8, ctx->r5);
    // lhu         $a0, 0x16E($s0)
    ctx->r4 = MEM_HU(0X16E, ctx->r16);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // mfhi        $t6
    ctx->r14 = hi;
    // subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_8005A670
    // sh          $v1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r3;
    goto L_8005A670;
    // sh          $v1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r3;
L_8005A668:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sh          $zero, -0x70CA($v0)
    MEM_H(-0X70CA, ctx->r2) = 0;
L_8005A670:
    // lhu         $v1, 0x170($s0)
    ctx->r3 = MEM_HU(0X170, ctx->r16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8005A6D0
    if (ctx->r3 == ctx->r2) {
        // lui         $a0, 0x2AAA
        ctx->r4 = S32(0X2AAA << 16);
        goto L_8005A6D0;
    }
    // lui         $a0, 0x2AAA
    ctx->r4 = S32(0X2AAA << 16);
    // lhu         $v0, 0x170($s0)
    ctx->r2 = MEM_HU(0X170, ctx->r16);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lhu         $v0, 0x1CA($v0)
    ctx->r2 = MEM_HU(0X1CA, ctx->r2);
    // ori         $a0, $a0, 0xAAAB
    ctx->r4 = ctx->r4 | 0XAAAB;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // lhu         $v1, 0xB8($a1)
    ctx->r3 = MEM_HU(0XB8, ctx->r5);
    // lhu         $a0, 0x172($s0)
    ctx->r4 = MEM_HU(0X172, ctx->r16);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // mfhi        $t6
    ctx->r14 = hi;
    // subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_8005A6D8
    // sh          $v1, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r3;
    goto L_8005A6D8;
    // sh          $v1, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r3;
L_8005A6D0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sh          $zero, -0x70C8($v0)
    MEM_H(-0X70C8, ctx->r2) = 0;
L_8005A6D8:
    // lhu         $v0, 0x27A($s0)
    ctx->r2 = MEM_HU(0X27A, ctx->r16);
    // lui         $t0, 0xCCCC
    ctx->r8 = S32(0XCCCC << 16);
    // ori         $t0, $t0, 0xCCCD
    ctx->r8 = ctx->r8 | 0XCCCD;
    // multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t5
    ctx->r13 = hi;
    // lhu         $v0, 0x27C($s0)
    ctx->r2 = MEM_HU(0X27C, ctx->r16);
    // nop

    // multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x1B8($s0)
    ctx->r3 = MEM_HU(0X1B8, ctx->r16);
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // lhu         $v0, 0x150($s0)
    ctx->r2 = MEM_HU(0X150, ctx->r16);
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // mfhi        $t4
    ctx->r12 = hi;
    // lhu         $v0, 0x27E($s0)
    ctx->r2 = MEM_HU(0X27E, ctx->r16);
    // lhu         $a0, 0x1C6($s0)
    ctx->r4 = MEM_HU(0X1C6, ctx->r16);
    // multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a3, $a3, -0x70D8
    ctx->r7 = ADD32(ctx->r7, -0X70D8);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // lhu         $v0, 0xB6($a3)
    ctx->r2 = MEM_HU(0XB6, ctx->r7);
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x15E($s0)
    ctx->r2 = MEM_HU(0X15E, ctx->r16);
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // mfhi        $t3
    ctx->r11 = hi;
    // lhu         $v0, 0x280($s0)
    ctx->r2 = MEM_HU(0X280, ctx->r16);
    // nop

    // multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $t1, 0x9249
    ctx->r9 = S32(0X9249 << 16);
    // lhu         $a1, 0x150($s0)
    ctx->r5 = MEM_HU(0X150, ctx->r16);
    // lhu         $a2, 0x15E($s0)
    ctx->r6 = MEM_HU(0X15E, ctx->r16);
    // lhu         $v1, 0x1BA($s0)
    ctx->r3 = MEM_HU(0X1BA, ctx->r16);
    // lhu         $v0, 0xB8($a3)
    ctx->r2 = MEM_HU(0XB8, ctx->r7);
    // sra         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) >> 2;
    // sh          $a1, 0x16($a3)
    MEM_H(0X16, ctx->r7) = ctx->r5;
    // sh          $a2, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r6;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x14($a3)
    MEM_H(0X14, ctx->r7) = ctx->r2;
    // mfhi        $t2
    ctx->r10 = hi;
    // lhu         $a0, 0x282($s0)
    ctx->r4 = MEM_HU(0X282, ctx->r16);
    // ori         $t1, $t1, 0x2493
    ctx->r9 = ctx->r9 | 0X2493;
    // multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 20
    ctx->r3 = S32(ctx->r3) >> 20;
    // lhu         $v0, 0x1C8($s0)
    ctx->r2 = MEM_HU(0X1C8, ctx->r16);
    // addiu       $v1, $v1, 0x32
    ctx->r3 = ADD32(ctx->r3, 0X32);
    // sh          $v1, 0x1E($a3)
    MEM_H(0X1E, ctx->r7) = ctx->r3;
    // lhu         $v1, 0x1B6($s0)
    ctx->r3 = MEM_HU(0X1B6, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 20
    ctx->r2 = S32(ctx->r2) >> 20;
    // addiu       $v0, $v0, 0x32
    ctx->r2 = ADD32(ctx->r2, 0X32);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sh          $v0, 0x20($a3)
    MEM_H(0X20, ctx->r7) = ctx->r2;
    // mfhi        $a2
    ctx->r6 = hi;
    // lhu         $a0, 0x284($s0)
    ctx->r4 = MEM_HU(0X284, ctx->r16);
    // sra         $v1, $v1, 19
    ctx->r3 = S32(ctx->r3) >> 19;
    // multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x1C4($s0)
    ctx->r2 = MEM_HU(0X1C4, ctx->r16);
    // addiu       $v1, $v1, 0x64
    ctx->r3 = ADD32(ctx->r3, 0X64);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 19
    ctx->r2 = S32(ctx->r2) >> 19;
    // addiu       $v0, $v0, 0x64
    ctx->r2 = ADD32(ctx->r2, 0X64);
    // sh          $v1, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r3;
    // sh          $v0, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = ctx->r2;
    // lhu         $v1, 0x1CA($s0)
    ctx->r3 = MEM_HU(0X1CA, ctx->r16);
    // lhu         $v0, 0x286($s0)
    ctx->r2 = MEM_HU(0X286, ctx->r16);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 18
    ctx->r3 = S32(ctx->r3) >> 18;
    // mfhi        $a1
    ctx->r5 = hi;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // srl         $v0, $t4, 2
    ctx->r2 = S32(U32(ctx->r12) >> 2);
    // mult        $v1, $t1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $v0, 0xCE($a3)
    MEM_H(0XCE, ctx->r7) = ctx->r2;
    // srl         $v0, $t3, 2
    ctx->r2 = S32(U32(ctx->r11) >> 2);
    // sh          $v0, 0xD0($a3)
    MEM_H(0XD0, ctx->r7) = ctx->r2;
    // srl         $v0, $t2, 2
    ctx->r2 = S32(U32(ctx->r10) >> 2);
    // sh          $v0, 0xD2($a3)
    MEM_H(0XD2, ctx->r7) = ctx->r2;
    // srl         $a0, $t5, 2
    ctx->r4 = S32(U32(ctx->r13) >> 2);
    // srl         $v0, $a2, 2
    ctx->r2 = S32(U32(ctx->r6) >> 2);
    // sh          $a0, 0xCC($a3)
    MEM_H(0XCC, ctx->r7) = ctx->r4;
    // sh          $v0, 0xD4($a3)
    MEM_H(0XD4, ctx->r7) = ctx->r2;
    // srl         $v0, $a1, 2
    ctx->r2 = S32(U32(ctx->r5) >> 2);
    // sh          $v0, 0xD6($a3)
    MEM_H(0XD6, ctx->r7) = ctx->r2;
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0xD8($a3)
    MEM_H(0XD8, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x1CA($s0)
    ctx->r2 = MEM_HU(0X1CA, ctx->r16);
    // lhu         $v1, 0x288($s0)
    ctx->r3 = MEM_HU(0X288, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 18
    ctx->r2 = S32(ctx->r2) >> 18;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $a1, 0x1CC($s0)
    ctx->r5 = MEM_HU(0X1CC, ctx->r16);
    // nop

    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // lhu         $v1, 0x28A($s0)
    ctx->r3 = MEM_HU(0X28A, ctx->r16);
    // mfhi        $t7
    ctx->r15 = hi;
    // sra         $a1, $a1, 18
    ctx->r5 = S32(ctx->r5) >> 18;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // mult        $a1, $t1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $a2, 0x1CC($s0)
    ctx->r6 = MEM_HU(0X1CC, ctx->r16);
    // nop

    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // lhu         $v1, 0x28C($s0)
    ctx->r3 = MEM_HU(0X28C, ctx->r16);
    // mfhi        $t3
    ctx->r11 = hi;
    // sra         $a2, $a2, 18
    ctx->r6 = S32(ctx->r6) >> 18;
    // addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // mult        $a2, $t1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $t2, $a3, $zero
    ctx->r10 = ADD32(ctx->r7, 0);
    // lbu         $t5, 0x149($s0)
    ctx->r13 = MEM_BU(0X149, ctx->r16);
    // lhu         $a0, 0x1CE($s0)
    ctx->r4 = MEM_HU(0X1CE, ctx->r16);
    // lhu         $a3, 0x28E($s0)
    ctx->r7 = MEM_HU(0X28E, ctx->r16);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 18
    ctx->r4 = S32(ctx->r4) >> 18;
    // addu        $a0, $a0, $a3
    ctx->r4 = ADD32(ctx->r4, ctx->r7);
    // mfhi        $t4
    ctx->r12 = hi;
    // addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // mult        $a0, $t1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sh          $v1, 0xDA($t2)
    MEM_H(0XDA, ctx->r10) = ctx->r3;
    // lhu         $v1, 0x1CE($s0)
    ctx->r3 = MEM_HU(0X1CE, ctx->r16);
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // addu        $v0, $t3, $a1
    ctx->r2 = ADD32(ctx->r11, ctx->r5);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // sra         $a1, $a1, 31
    ctx->r5 = S32(ctx->r5) >> 31;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // lhu         $a1, 0x290($s0)
    ctx->r5 = MEM_HU(0X290, ctx->r16);
    // mfhi        $a3
    ctx->r7 = hi;
    // sra         $v1, $v1, 18
    ctx->r3 = S32(ctx->r3) >> 18;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // mult        $v1, $t1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $v0, 0xDC($t2)
    MEM_H(0XDC, ctx->r10) = ctx->r2;
    // addu        $v0, $t4, $a2
    ctx->r2 = ADD32(ctx->r12, ctx->r6);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // sra         $a2, $a2, 31
    ctx->r6 = S32(ctx->r6) >> 31;
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // sh          $v0, 0xDE($t2)
    MEM_H(0XDE, ctx->r10) = ctx->r2;
    // addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sh          $v0, 0xE0($t2)
    MEM_H(0XE0, ctx->r10) = ctx->r2;
    // mfhi        $a1
    ctx->r5 = hi;
    // addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0xE2($t2)
    MEM_H(0XE2, ctx->r10) = ctx->r2;
L_8005A95C:
    // bne         $t5, $t0, L_8005A988
    if (ctx->r13 != ctx->r8) {
        // srl         $v0, $t0, 31
        ctx->r2 = S32(U32(ctx->r8) >> 31);
        goto L_8005A988;
    }
    // srl         $v0, $t0, 31
    ctx->r2 = S32(U32(ctx->r8) >> 31);
    // addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lhu         $v1, 0x14A($s0)
    ctx->r3 = MEM_HU(0X14A, ctx->r16);
    // lhu         $v0, 0x1CA($v0)
    ctx->r2 = MEM_HU(0X1CA, ctx->r2);
    // srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0xE4($t2)
    MEM_H(0XE4, ctx->r10) = ctx->r2;
L_8005A988:
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // slti        $v0, $t0, 0x6
    ctx->r2 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_8005A95C
    if (ctx->r2 != 0) {
        // ori         $a2, $zero, 0xFFFF
        ctx->r6 = 0 | 0XFFFF;
        goto L_8005A95C;
    }
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // addiu       $a3, $t0, -0x70D8
    ctx->r7 = ADD32(ctx->r8, -0X70D8);
    // lhu         $v1, 0xBA($a3)
    ctx->r3 = MEM_HU(0XBA, ctx->r7);
    // nop

    // andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // beq         $a0, $zero, L_8005A9B8
    if (ctx->r4 == 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8005A9B8;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_8005A9B8:
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8005A9CC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005A9CC;
    }
    // nop

    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_8005A9CC:
    // lhu         $v1, 0xBC($a3)
    ctx->r3 = MEM_HU(0XBC, ctx->r7);
    // nop

    // andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // sltu        $v0, $a1, $a0
    ctx->r2 = ctx->r5 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_8005A9E8
    if (ctx->r2 == 0) {
        // sltu        $v0, $a0, $a2
        ctx->r2 = ctx->r4 < ctx->r6 ? 1 : 0;
        goto L_8005A9E8;
    }
    // sltu        $v0, $a0, $a2
    ctx->r2 = ctx->r4 < ctx->r6 ? 1 : 0;
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_8005A9E8:
    // beq         $v0, $zero, L_8005A9F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005A9F4;
    }
    // nop

    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_8005A9F4:
    // lhu         $v1, 0xBE($a3)
    ctx->r3 = MEM_HU(0XBE, ctx->r7);
    // nop

    // andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // sltu        $v0, $a1, $a0
    ctx->r2 = ctx->r5 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_8005AA10
    if (ctx->r2 == 0) {
        // sltu        $v0, $a0, $a2
        ctx->r2 = ctx->r4 < ctx->r6 ? 1 : 0;
        goto L_8005AA10;
    }
    // sltu        $v0, $a0, $a2
    ctx->r2 = ctx->r4 < ctx->r6 ? 1 : 0;
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_8005AA10:
    // beq         $v0, $zero, L_8005AA1C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005AA1C;
    }
    // nop

    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_8005AA1C:
    // lhu         $v1, -0x70D8($t0)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r8);
    // lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x2BC($s0)
    ctx->r2 = MEM_HU(0X2BC, ctx->r16);
    // sh          $a2, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r6;
    // sh          $a1, 0xC($a3)
    MEM_H(0XC, ctx->r7) = ctx->r5;
    // sh          $v0, 0x22($a3)
    MEM_H(0X22, ctx->r7) = ctx->r2;
    // mfhi        $t6
    ctx->r14 = hi;
    // srl         $v0, $t6, 3
    ctx->r2 = S32(U32(ctx->r14) >> 3);
    // addiu       $v0, $v0, 0x78
    ctx->r2 = ADD32(ctx->r2, 0X78);
    // beq         $s1, $zero, L_8005AA60
    if (ctx->r17 == 0) {
        // sh          $v0, 0x24($a3)
        MEM_H(0X24, ctx->r7) = ctx->r2;
        goto L_8005AA60;
    }
    // sh          $v0, 0x24($a3)
    MEM_H(0X24, ctx->r7) = ctx->r2;
    // jal         0x80059CEC
    // nop

    sub_80059CEC(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_8005AA68
    // nop

    goto L_8005AA68;
    // nop

L_8005AA60:
    // jal         0x8005A36C
    // nop

    sub_8005A36C(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_8005AA68:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
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
