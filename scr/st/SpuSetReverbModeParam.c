#include "recomp.h"
#include "disable_warnings.h"

void SpuSetReverbModeParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // lw          $s3, 0x0($s2)
    ctx->r19 = MEM_W(0X0, ctx->r18);
    // addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // sltiu       $s5, $s3, 0x1
    ctx->r21 = ctx->r19 < 0X1 ? 1 : 0;
    // bne         $s5, $zero, L_8006F674
    if (ctx->r21 != 0) {
        // sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
        goto L_8006F674;
    }
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // andi        $v0, $s3, 0x1
    ctx->r2 = ctx->r19 & 0X1;
    // beq         $v0, $zero, L_8006F77C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006F77C;
    }
    // nop

L_8006F674:
    // lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(0X4, ctx->r18);
    // nop

    // andi        $v0, $s0, 0x100
    ctx->r2 = ctx->r16 & 0X100;
    // beq         $v0, $zero, L_8006F694
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x101
        ctx->r2 = ADD32(0, -0X101);
        goto L_8006F694;
    }
    // addiu       $v0, $zero, -0x101
    ctx->r2 = ADD32(0, -0X101);
    // and         $s0, $s0, $v0
    ctx->r16 = ctx->r16 & ctx->r2;
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
L_8006F694:
    // sltiu       $v0, $s0, 0xA
    ctx->r2 = ctx->r16 < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_8006F6C0
    if (ctx->r2 == 0) {
        // sll         $v0, $s0, 2
        ctx->r2 = S32(ctx->r16) << 2;
        goto L_8006F6C0;
    }
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0xE30($a0)
    ctx->r4 = MEM_W(0XE30, ctx->r4);
    // lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // jal         0x8006FB74
    // addiu       $s1, $s1, 0xE30
    ctx->r17 = ADD32(ctx->r17, 0XE30);
    _SpuIsInAllocateArea_(rdram, ctx);
    goto after_0;
    // addiu       $s1, $s1, 0xE30
    ctx->r17 = ADD32(ctx->r17, 0XE30);
    after_0:
    // beq         $v0, $zero, L_8006F6C8
    if (ctx->r2 == 0) {
        // addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
        goto L_8006F6C8;
    }
    // addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_8006F6C0:
    // j           L_8006FAB8
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8006FAB8;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006F6C8:
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $s0, 0xDC4($at)
    MEM_W(0XDC4, ctx->r1) = ctx->r16;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xDC4($v1)
    ctx->r3 = MEM_W(0XDC4, ctx->r3);
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3) << 2;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0x12C0
    ctx->r3 = ADD32(ctx->r3, 0X12C0);
    // lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(0X0, ctx->r4);
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $a0, 0xDBC($at)
    MEM_W(0XDBC, ctx->r1) = ctx->r4;
L_8006F710:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // bne         $a1, $a3, L_8006F710
    if (ctx->r5 != ctx->r7) {
        // addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8006F710;
    }
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, 0xDC4
    ctx->r4 = ADD32(ctx->r4, 0XDC4);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // beq         $v1, $v0, L_8006F750
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_8006F750;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // beq         $v1, $v0, L_8006F760
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x7F
        ctx->r2 = ADD32(0, 0X7F);
        goto L_8006F760;
    }
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // j           L_8006F76C
    // nop

    goto L_8006F76C;
    // nop

L_8006F750:
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // j           L_8006F77C
    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    goto L_8006F77C;
    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
L_8006F760:
    // sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // j           L_8006F77C
    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    goto L_8006F77C;
    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
L_8006F76C:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0xDD0
    ctx->r2 = ADD32(ctx->r2, 0XDD0);
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
L_8006F77C:
    // bne         $s5, $zero, L_8006F78C
    if (ctx->r21 != 0) {
        // andi        $v0, $s3, 0x8
        ctx->r2 = ctx->r19 & 0X8;
        goto L_8006F78C;
    }
    // andi        $v0, $s3, 0x8
    ctx->r2 = ctx->r19 & 0X8;
    // beq         $v0, $zero, L_8006F89C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006F89C;
    }
    // nop

L_8006F78C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xDC4($v1)
    ctx->r3 = MEM_W(0XDC4, ctx->r3);
    // nop

    // slti        $v0, $v1, 0x9
    ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // beq         $v0, $zero, L_8006F89C
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x7
        ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
        goto L_8006F89C;
    }
    // slti        $v0, $v1, 0x7
    ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // bne         $v0, $zero, L_8006F89C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006F89C;
    }
    // nop

    // bne         $s4, $zero, L_8006F804
    if (ctx->r20 != 0) {
        // addiu       $s6, $zero, 0x1
        ctx->r22 = ADD32(0, 0X1);
        goto L_8006F804;
    }
    // addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xDC4($v0)
    ctx->r2 = MEM_W(0XDC4, ctx->r2);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0x12C0
    ctx->r2 = ADD32(ctx->r2, 0X12C0);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_8006F7E0:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // bne         $a0, $a2, L_8006F7E0
    if (ctx->r4 != ctx->r6) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_8006F7E0;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // lui         $v0, 0xC01
    ctx->r2 = S32(0XC01 << 16);
    // ori         $v0, $v0, 0x1C00
    ctx->r2 = ctx->r2 | 0X1C00;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_8006F804:
    // lui         $a0, 0x8102
    ctx->r4 = S32(0X8102 << 16);
    // lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(0XC, ctx->r18);
    // ori         $a0, $a0, 0x409
    ctx->r4 = ctx->r4 | 0X409;
    // sll         $v1, $v0, 13
    ctx->r3 = S32(ctx->r2) << 13;
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $a3
    ctx->r7 = hi;
    // sll         $a1, $v0, 12
    ctx->r5 = S32(ctx->r2) << 12;
    // nop

    // mult        $a1, $a0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xDCC($at)
    MEM_W(0XDCC, ctx->r1) = ctx->r2;
    // addu        $v0, $a3, $v1
    ctx->r2 = ADD32(ctx->r7, ctx->r3);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lhu         $a0, 0x14($sp)
    ctx->r4 = MEM_HU(0X14, ctx->r29);
    // lhu         $v1, 0x36($sp)
    ctx->r3 = MEM_HU(0X36, ctx->r29);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x16($sp)
    ctx->r2 = MEM_HU(0X16, ctx->r29);
    // mfhi        $a2
    ctx->r6 = hi;
    // addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
    // sra         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4) >> 6;
    // sra         $a1, $a1, 31
    ctx->r5 = S32(ctx->r5) >> 31;
    // subu        $a0, $a0, $a1
    ctx->r4 = SUB32(ctx->r4, ctx->r5);
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x2E($sp)
    ctx->r2 = MEM_HU(0X2E, ctx->r29);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r3;
    // lhu         $v1, 0x4E($sp)
    ctx->r3 = MEM_HU(0X4E, ctx->r29);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x4C($sp)
    ctx->r2 = MEM_HU(0X4C, ctx->r29);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v1, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r2;
L_8006F89C:
    // bne         $s5, $zero, L_8006F8AC
    if (ctx->r21 != 0) {
        // andi        $v0, $s3, 0x10
        ctx->r2 = ctx->r19 & 0X10;
        goto L_8006F8AC;
    }
    // andi        $v0, $s3, 0x10
    ctx->r2 = ctx->r19 & 0X10;
    // beq         $v0, $zero, L_8006F970
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006F970;
    }
    // nop

L_8006F8AC:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xDC4($v1)
    ctx->r3 = MEM_W(0XDC4, ctx->r3);
    // nop

    // slti        $v0, $v1, 0x9
    ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // beq         $v0, $zero, L_8006F970
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x7
        ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
        goto L_8006F970;
    }
    // slti        $v0, $v1, 0x7
    ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // bne         $v0, $zero, L_8006F970
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006F970;
    }
    // nop

    // bne         $s4, $zero, L_8006F934
    if (ctx->r20 != 0) {
        // addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
        goto L_8006F934;
    }
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // bne         $s6, $zero, L_8006F924
    if (ctx->r22 != 0) {
        // addiu       $a1, $sp, 0x10
        ctx->r5 = ADD32(ctx->r29, 0X10);
        goto L_8006F924;
    }
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xDC4($v0)
    ctx->r2 = MEM_W(0XDC4, ctx->r2);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0x12C0
    ctx->r2 = ADD32(ctx->r2, 0X12C0);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_8006F904:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // bne         $a0, $a2, L_8006F904
    if (ctx->r4 != ctx->r6) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_8006F904;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // j           L_8006F930
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    goto L_8006F930;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_8006F924:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
L_8006F930:
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_8006F934:
    // lui         $a0, 0x8102
    ctx->r4 = S32(0X8102 << 16);
    // lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(0X10, ctx->r18);
    // ori         $a0, $a0, 0x409
    ctx->r4 = ctx->r4 | 0X409;
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, 0xDD0($at)
    MEM_W(0XDD0, ctx->r1) = ctx->r3;
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // sra         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) >> 6;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
L_8006F970:
    // beq         $s4, $zero, L_8006F9B0
    if (ctx->r20 == 0) {
        // nop
    
        goto L_8006F9B0;
    }
    // nop

    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // nop

    // srl         $v0, $v0, 7
    ctx->r2 = S32(U32(ctx->r2) >> 7);
    // andi        $s7, $v0, 0x1
    ctx->r23 = ctx->r2 & 0X1;
    // beq         $s7, $zero, L_8006FA14
    if (ctx->r23 == 0) {
        // nop
    
        goto L_8006FA14;
    }
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // nop

    // andi        $v0, $v0, 0xFF7F
    ctx->r2 = ctx->r2 & 0XFF7F;
    // j           L_8006FA14
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
    goto L_8006FA14;
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
L_8006F9B0:
    // bne         $s5, $zero, L_8006F9C0
    if (ctx->r21 != 0) {
        // andi        $v0, $s3, 0x2
        ctx->r2 = ctx->r19 & 0X2;
        goto L_8006F9C0;
    }
    // andi        $v0, $s3, 0x2
    ctx->r2 = ctx->r19 & 0X2;
    // beq         $v0, $zero, L_8006F9E0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006F9E0;
    }
    // nop

L_8006F9C0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // lhu         $v1, 0x8($s2)
    ctx->r3 = MEM_HU(0X8, ctx->r18);
    // nop

    // sh          $v1, 0x184($v0)
    MEM_H(0X184, ctx->r2) = ctx->r3;
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v0, 0xDC8($at)
    MEM_H(0XDC8, ctx->r1) = ctx->r2;
L_8006F9E0:
    // bne         $s5, $zero, L_8006F9F0
    if (ctx->r21 != 0) {
        // andi        $v0, $s3, 0x4
        ctx->r2 = ctx->r19 & 0X4;
        goto L_8006F9F0;
    }
    // andi        $v0, $s3, 0x4
    ctx->r2 = ctx->r19 & 0X4;
    // beq         $v0, $zero, L_8006FA38
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FA38;
    }
    // nop

L_8006F9F0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // lhu         $v1, 0xA($s2)
    ctx->r3 = MEM_HU(0XA, ctx->r18);
    // nop

    // sh          $v1, 0x186($v0)
    MEM_H(0X186, ctx->r2) = ctx->r3;
    // lhu         $v0, 0xA($s2)
    ctx->r2 = MEM_HU(0XA, ctx->r18);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // j           L_8006FA38
    // sh          $v0, 0xDCA($at)
    MEM_H(0XDCA, ctx->r1) = ctx->r2;
    goto L_8006FA38;
    // sh          $v0, 0xDCA($at)
    MEM_H(0XDCA, ctx->r1) = ctx->r2;
L_8006FA14:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // nop

    // sh          $zero, 0x184($v0)
    MEM_H(0X184, ctx->r2) = 0;
    // sh          $zero, 0x186($v0)
    MEM_H(0X186, ctx->r2) = 0;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0xDC8
    ctx->r2 = ADD32(ctx->r2, 0XDC8);
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
L_8006FA38:
    // bne         $s4, $zero, L_8006FA50
    if (ctx->r20 != 0) {
        // nop
    
        goto L_8006FA50;
    }
    // nop

    // bne         $s6, $zero, L_8006FA50
    if (ctx->r22 != 0) {
        // nop
    
        goto L_8006FA50;
    }
    // nop

    // beq         $fp, $zero, L_8006FA58
    if (ctx->r30 == 0) {
        // nop
    
        goto L_8006FA58;
    }
    // nop

L_8006FA50:
    // jal         0x8006FC04
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    _spu_setReverbAttr(rdram, ctx);
    goto after_1;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
L_8006FA58:
    // lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(0X58, ctx->r29);
    // nop

    // beq         $t0, $zero, L_8006FA78
    if (ctx->r8 == 0) {
        // nop
    
        goto L_8006FA78;
    }
    // nop

    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xDC4($a0)
    ctx->r4 = MEM_W(0XDC4, ctx->r4);
    // jal         0x800700D4
    // nop

    SpuClearReverbWorkArea(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_8006FA78:
    // beq         $s4, $zero, L_8006FAB4
    if (ctx->r20 == 0) {
        // addiu       $a0, $zero, 0xD1
        ctx->r4 = ADD32(0, 0XD1);
        goto L_8006FAB4;
    }
    // addiu       $a0, $zero, 0xD1
    ctx->r4 = ADD32(0, 0XD1);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xDBC($a1)
    ctx->r5 = MEM_W(0XDBC, ctx->r5);
    // jal         0x8006C5B0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    _spu_FsetRXX(rdram, ctx);
    goto after_3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // beq         $s7, $zero, L_8006FAB8
    if (ctx->r23 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8006FAB8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
L_8006FAB4:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006FAB8:
    // lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(0X84, ctx->r29);
    // lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(0X80, ctx->r29);
    // lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(0X7C, ctx->r29);
    // lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(0X78, ctx->r29);
    // lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(0X74, ctx->r29);
    // lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(0X70, ctx->r29);
    // lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(0X6C, ctx->r29);
    // lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(0X68, ctx->r29);
    // lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(0X64, ctx->r29);
    // lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(0X60, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
