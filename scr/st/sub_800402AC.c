#include "recomp.h"
#include "disable_warnings.h"

void sub_800402AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // sw          $s6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // sw          $s3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r19;
    // andi        $s3, $s6, 0xFF
    ctx->r19 = ctx->r22 & 0XFF;
    // sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19) << 2;
    // addu        $a3, $s3, $a2
    ctx->r7 = ADD32(ctx->r19, ctx->r6);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sw          $ra, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r31;
    // sw          $fp, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r30;
    // sw          $s7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r23;
    // sw          $s5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r21;
    // sw          $s4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r20;
    // sw          $s2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r18;
    // sw          $s1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r17;
    // sw          $s0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r16;
    // lbu         $a1, 0x148($a3)
    ctx->r5 = MEM_BU(0X148, ctx->r7);
    // lw          $s0, 0xE8($v0)
    ctx->r16 = MEM_W(0XE8, ctx->r2);
    // slti        $v1, $a1, 0x23
    ctx->r3 = SIGNED(ctx->r5) < 0X23 ? 1 : 0;
    // beq         $v1, $zero, L_80040320
    if (ctx->r3 == 0) {
        // slti        $v0, $a1, 0x1F
        ctx->r2 = SIGNED(ctx->r5) < 0X1F ? 1 : 0;
        goto L_80040320;
    }
    // slti        $v0, $a1, 0x1F
    ctx->r2 = SIGNED(ctx->r5) < 0X1F ? 1 : 0;
    // beq         $v0, $zero, L_8004071C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004071C;
    }
    // nop

    // bltz        $a1, L_80040ED0
    if (SIGNED(ctx->r5) < 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040ED0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // j           L_80040A4C
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    goto L_80040A4C;
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
L_80040320:
    // slti        $v0, $a1, 0x24
    ctx->r2 = SIGNED(ctx->r5) < 0X24 ? 1 : 0;
    // bne         $v0, $zero, L_80040ED0
    if (ctx->r2 != 0) {
        // slti        $v0, $a1, 0x37
        ctx->r2 = SIGNED(ctx->r5) < 0X37 ? 1 : 0;
        goto L_80040ED0;
    }
    // slti        $v0, $a1, 0x37
    ctx->r2 = SIGNED(ctx->r5) < 0X37 ? 1 : 0;
    // beq         $v0, $zero, L_80040ED0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040ED0;
    }
    // nop

    // lhu         $v0, 0x2DE($a2)
    ctx->r2 = MEM_HU(0X2DE, ctx->r6);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // beq         $v0, $zero, L_8004034C
    if (ctx->r2 == 0) {
        // sra         $v0, $v0, 17
        ctx->r2 = S32(ctx->r2) >> 17;
        goto L_8004034C;
    }
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0x2DE($a2)
    MEM_H(0X2DE, ctx->r6) = ctx->r2;
L_8004034C:
    // lhu         $v0, 0x2E2($a2)
    ctx->r2 = MEM_HU(0X2E2, ctx->r6);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // beq         $v0, $zero, L_80040364
    if (ctx->r2 == 0) {
        // sra         $v0, $v0, 17
        ctx->r2 = S32(ctx->r2) >> 17;
        goto L_80040364;
    }
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0x2E2($a2)
    MEM_H(0X2E2, ctx->r6) = ctx->r2;
L_80040364:
    // lhu         $a3, 0x2E0($a2)
    ctx->r7 = MEM_HU(0X2E0, ctx->r6);
    // nop

    // sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7) << 16;
    // sra         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3) >> 16;
    // beq         $a1, $zero, L_8004039C
    if (ctx->r5 == 0) {
        // lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
        goto L_8004039C;
    }
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v0, $t1, 3
    ctx->r2 = S32(ctx->r9) >> 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // subu        $v0, $a3, $v0
    ctx->r2 = SUB32(ctx->r7, ctx->r2);
    // sh          $v0, 0x2E0($a2)
    MEM_H(0X2E0, ctx->r6) = ctx->r2;
L_8004039C:
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // addu        $a3, $v0, $a2
    ctx->r7 = ADD32(ctx->r2, ctx->r6);
    // lh          $v0, 0x130($a3)
    ctx->r2 = MEM_HS(0X130, ctx->r7);
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // beq         $v0, $t0, L_80040ED0
    if (ctx->r2 == ctx->r8) {
        // lui         $v1, 0x51EB
        ctx->r3 = S32(0X51EB << 16);
        goto L_80040ED0;
    }
    // lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // lhu         $a1, 0x4($s0)
    ctx->r5 = MEM_HU(0X4, ctx->r16);
    // lh          $v0, 0x64($a2)
    ctx->r2 = MEM_HS(0X64, ctx->r6);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v1, $t1, 9
    ctx->r3 = S32(ctx->r9) >> 9;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // xori        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 ^ 0X1;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // lh          $v0, 0x130($v0)
    ctx->r2 = MEM_HS(0X130, ctx->r2);
    // nop

    // beq         $v0, $t0, L_8004040C
    if (ctx->r2 == ctx->r8) {
        // addu        $a1, $a1, $v1
        ctx->r5 = ADD32(ctx->r5, ctx->r3);
        goto L_8004040C;
    }
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x14F($a2)
    MEM_B(0X14F, ctx->r6) = ctx->r2;
L_8004040C:
    // lbu         $v0, 0x14F($a2)
    ctx->r2 = MEM_BU(0X14F, ctx->r6);
    // nop

    // beq         $v0, $zero, L_80040430
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80040430;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lhu         $v0, 0x130($a3)
    ctx->r2 = MEM_HU(0X130, ctx->r7);
    // nop

    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // j           L_800406DC
    // sh          $v0, 0x130($a3)
    MEM_H(0X130, ctx->r7) = ctx->r2;
    goto L_800406DC;
    // sh          $v0, 0x130($a3)
    MEM_H(0X130, ctx->r7) = ctx->r2;
L_80040430:
    // addiu       $v1, $v0, -0x2E80
    ctx->r3 = ADD32(ctx->r2, -0X2E80);
    // lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(0X2, ctx->r3);
    // lhu         $v0, 0x32($v1)
    ctx->r2 = MEM_HU(0X32, ctx->r3);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // bne         $v0, $zero, L_80040454
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80040454;
    }
    // nop

    // beq         $s3, $zero, L_80040470
    if (ctx->r19 == 0) {
        // nop
    
        goto L_80040470;
    }
    // nop

L_80040454:
    // lhu         $v0, 0x34($v1)
    ctx->r2 = MEM_HU(0X34, ctx->r3);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // bne         $v0, $zero, L_8004049C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8004049C;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // beq         $s3, $zero, L_800404A0
    if (ctx->r19 == 0) {
        // addiu       $s2, $v0, -0x70D8
        ctx->r18 = ADD32(ctx->r2, -0X70D8);
        goto L_800404A0;
    }
    // addiu       $s2, $v0, -0x70D8
    ctx->r18 = ADD32(ctx->r2, -0X70D8);
L_80040470:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // andi        $v1, $s6, 0xFF
    ctx->r3 = ctx->r22 & 0XFF;
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lhu         $v0, 0x130($v1)
    ctx->r2 = MEM_HU(0X130, ctx->r3);
    // nop

    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sh          $v0, 0x130($v1)
    MEM_H(0X130, ctx->r3) = ctx->r2;
    // j           L_800406DC
    // sb          $zero, 0x189($a0)
    MEM_B(0X189, ctx->r4) = 0;
    goto L_800406DC;
    // sb          $zero, 0x189($a0)
    MEM_B(0X189, ctx->r4) = 0;
L_8004049C:
    // addiu       $s2, $v0, -0x70D8
    ctx->r18 = ADD32(ctx->r2, -0X70D8);
L_800404A0:
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // lh          $a0, 0x134($v0)
    ctx->r4 = MEM_HS(0X134, ctx->r2);
    // lh          $v1, 0x130($v0)
    ctx->r3 = MEM_HS(0X130, ctx->r2);
    // subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_800406A4
    if (ctx->r2 == 0) {
        // slt         $v0, $a0, $v1
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_800406A4;
    }
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_800406A8
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800406A8;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $s2, 0x298
    ctx->r4 = ADD32(ctx->r18, 0X298);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x189($s2)
    MEM_B(0X189, ctx->r18) = ctx->r2;
    // sh          $zero, 0x18($sp)
    MEM_H(0X18, ctx->r29) = 0;
    // sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // jal         0x80074CA4
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    ApplyMatrix(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
    // lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(0X2, ctx->r16);
    // lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(0X3C, ctx->r29);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $v0, 0x91A2
    ctx->r2 = S32(0X91A2 << 16);
    // ori         $v0, $v0, 0xB3C5
    ctx->r2 = ctx->r2 | 0XB3C5;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(0X38, ctx->r29);
    // mfhi        $t1
    ctx->r9 = hi;
    // addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // sra         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) >> 10;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
    // bgez        $a0, L_80040540
    if (SIGNED(ctx->r4) >= 0) {
        // sw          $v1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r3;
        goto L_80040540;
    }
    // sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
L_80040540:
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // bgez        $v0, L_80040558
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80040558;
    }
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
L_80040558:
    // lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(0X40, ctx->r29);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // bgez        $a2, L_8004056C
    if (SIGNED(ctx->r6) >= 0) {
        // sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
        goto L_8004056C;
    }
    // sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
L_8004056C:
    // ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // addiu       $s4, $zero, 0x400
    ctx->r20 = ADD32(0, 0X400);
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s5, $v0, -0x5EC8
    ctx->r21 = ADD32(ctx->r2, -0X5EC8);
    // lw          $v1, 0x248($s2)
    ctx->r3 = MEM_W(0X248, ctx->r18);
    // lw          $a0, 0x24C($s2)
    ctx->r4 = MEM_W(0X24C, ctx->r18);
    // lw          $a1, 0x250($s2)
    ctx->r5 = MEM_W(0X250, ctx->r18);
    // sra         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6) >> 2;
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    // sw          $a0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r4;
    // sw          $a1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r5;
    // addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
L_800405A8:
    // addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(0X90, ctx->r29);
    // lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(0X38, ctx->r29);
    // lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(0X3C, ctx->r29);
    // lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(0X40, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(0X94, ctx->r29);
    // lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(0X98, ctx->r29);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // sw          $v1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r3;
    // lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(0X90, ctx->r29);
    // lw          $v1, 0x94($sp)
    ctx->r3 = MEM_W(0X94, ctx->r29);
    // lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(0X98, ctx->r29);
    // lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(0X9C, ctx->r29);
    // sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    // sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    // sh          $s4, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r20;
    // jal         0x8004BB88
    // sh          $s4, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r20;
    sub_8004BB88(rdram, ctx);
    goto after_1;
    // sh          $s4, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r20;
    after_1:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $s3, L_80040660
    if (ctx->r3 == ctx->r19) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_80040660;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lh          $v1, 0x26A($s2)
    ctx->r3 = MEM_HS(0X26A, ctx->r18);
    // lh          $v0, 0x56($v0)
    ctx->r2 = MEM_HS(0X56, ctx->r2);
    // nop

    // subu        $s0, $v1, $v0
    ctx->r16 = SUB32(ctx->r3, ctx->r2);
    // slti        $v0, $s0, 0x801
    ctx->r2 = SIGNED(ctx->r16) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_80040654
    if (ctx->r2 != 0) {
        // slti        $v0, $s0, -0x800
        ctx->r2 = SIGNED(ctx->r16) < -0X800 ? 1 : 0;
        goto L_80040654;
    }
    // slti        $v0, $s0, -0x800
    ctx->r2 = SIGNED(ctx->r16) < -0X800 ? 1 : 0;
    // addiu       $s0, $s0, -0x1000
    ctx->r16 = ADD32(ctx->r16, -0X1000);
    // slti        $v0, $s0, -0x800
    ctx->r2 = SIGNED(ctx->r16) < -0X800 ? 1 : 0;
L_80040654:
    // beq         $v0, $zero, L_80040660
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040660;
    }
    // nop

    // addiu       $s0, $s0, 0x1000
    ctx->r16 = ADD32(ctx->r16, 0X1000);
L_80040660:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s3, L_800405A8
    if (ctx->r17 != ctx->r19) {
        // addiu       $a0, $sp, 0x68
        ctx->r4 = ADD32(ctx->r29, 0X68);
        goto L_800405A8;
    }
    // addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $s0, $v0, L_800406DC
    if (ctx->r16 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800406DC;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lh          $v0, 0x2E0($a0)
    ctx->r2 = MEM_HS(0X2E0, ctx->r4);
    // lhu         $v1, 0x2E0($a0)
    ctx->r3 = MEM_HU(0X2E0, ctx->r4);
    // subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // bgez        $v0, L_80040694
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80040694;
    }
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
L_80040694:
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // j           L_800406DC
    // sh          $v0, 0x2E0($a0)
    MEM_H(0X2E0, ctx->r4) = ctx->r2;
    goto L_800406DC;
    // sh          $v0, 0x2E0($a0)
    MEM_H(0X2E0, ctx->r4) = ctx->r2;
L_800406A4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_800406A8:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v0, 0x154($a0)
    ctx->r2 = MEM_BU(0X154, ctx->r4);
    // nop

    // beq         $v0, $zero, L_800406C4
    if (ctx->r2 == 0) {
        // andi        $v1, $s6, 0xFF
        ctx->r3 = ctx->r22 & 0XFF;
        goto L_800406C4;
    }
    // andi        $v1, $s6, 0xFF
    ctx->r3 = ctx->r22 & 0XFF;
    // j           L_800406DC
    // sb          $zero, 0x154($a0)
    MEM_B(0X154, ctx->r4) = 0;
    goto L_800406DC;
    // sb          $zero, 0x154($a0)
    MEM_B(0X154, ctx->r4) = 0;
L_800406C4:
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lhu         $v0, 0x130($v1)
    ctx->r2 = MEM_HU(0X130, ctx->r3);
    // nop

    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v0, 0x130($v1)
    MEM_H(0X130, ctx->r3) = ctx->r2;
L_800406DC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x130($v1)
    ctx->r2 = MEM_HU(0X130, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_80040ED0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80040ED0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $v0, 0x130($v1)
    MEM_H(0X130, ctx->r3) = ctx->r2;
    // sb          $zero, 0x14F($a0)
    MEM_B(0X14F, ctx->r4) = 0;
    // sh          $zero, 0x2DE($a0)
    MEM_H(0X2DE, ctx->r4) = 0;
    // sh          $zero, 0x2E0($a0)
    MEM_H(0X2E0, ctx->r4) = 0;
    // j           L_80040ED0
    // sh          $zero, 0x2E2($a0)
    MEM_H(0X2E2, ctx->r4) = 0;
    goto L_80040ED0;
    // sh          $zero, 0x2E2($a0)
    MEM_H(0X2E2, ctx->r4) = 0;
L_8004071C:
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // addu        $s1, $v0, $a2
    ctx->r17 = ADD32(ctx->r2, ctx->r6);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lh          $a1, 0x130($s1)
    ctx->r5 = MEM_HS(0X130, ctx->r17);
    // lhu         $a0, 0x130($s1)
    ctx->r4 = MEM_HU(0X130, ctx->r17);
    // beq         $a1, $v0, L_80040A44
    if (ctx->r5 == ctx->r2) {
        // lui         $v1, 0x51EB
        ctx->r3 = S32(0X51EB << 16);
        goto L_80040A44;
    }
    // lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // lhu         $s2, 0x4($s0)
    ctx->r18 = MEM_HU(0X4, ctx->r16);
    // lh          $v0, 0x64($a2)
    ctx->r2 = MEM_HS(0X64, ctx->r6);
    // nop

    // mult        $s2, $v0
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v1, $t1, 9
    ctx->r3 = S32(ctx->r9) >> 9;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x21F($a2)
    ctx->r2 = MEM_BU(0X21F, ctx->r6);
    // nop

    // beq         $v0, $zero, L_80040818
    if (ctx->r2 == 0) {
        // addu        $s2, $s2, $v1
        ctx->r18 = ADD32(ctx->r18, ctx->r3);
        goto L_80040818;
    }
    // addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
    // lh          $v0, 0x138($s1)
    ctx->r2 = MEM_HS(0X138, ctx->r17);
    // nop

    // subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8004079C
    if (ctx->r2 != 0) {
        // addu        $v0, $a0, $s2
        ctx->r2 = ADD32(ctx->r4, ctx->r18);
        goto L_8004079C;
    }
    // addu        $v0, $a0, $s2
    ctx->r2 = ADD32(ctx->r4, ctx->r18);
    // subu        $v0, $a0, $s2
    ctx->r2 = SUB32(ctx->r4, ctx->r18);
    // j           L_800409F0
    // sh          $v0, 0x130($s1)
    MEM_H(0X130, ctx->r17) = ctx->r2;
    goto L_800409F0;
    // sh          $v0, 0x130($s1)
    MEM_H(0X130, ctx->r17) = ctx->r2;
L_8004079C:
    // sh          $v0, 0x130($s1)
    MEM_H(0X130, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lh          $a0, 0x134($s1)
    ctx->r4 = MEM_HS(0X134, ctx->r17);
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_800409F0
    if (ctx->r2 == 0) {
        // addu        $v0, $a0, $s2
        ctx->r2 = ADD32(ctx->r4, ctx->r18);
        goto L_800409F0;
    }
    // addu        $v0, $a0, $s2
    ctx->r2 = ADD32(ctx->r4, ctx->r18);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_800409F4
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800409F4;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // lbu         $a0, 0x1D4($a3)
    ctx->r4 = MEM_BU(0X1D4, ctx->r7);
    // lbu         $s0, 0x148($a3)
    ctx->r16 = MEM_BU(0X148, ctx->r7);
    // addiu       $a0, $a0, -0x18
    ctx->r4 = ADD32(ctx->r4, -0X18);
    // srl         $v0, $a0, 31
    ctx->r2 = S32(U32(ctx->r4) >> 31);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sra         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) >> 1;
    // addiu       $a0, $a0, 0x16
    ctx->r4 = ADD32(ctx->r4, 0X16);
    // jal         0x800582F0
    // addiu       $s0, $s0, 0xD
    ctx->r16 = ADD32(ctx->r16, 0XD);
    sub_800582F0(rdram, ctx);
    goto after_2;
    // addiu       $s0, $s0, 0xD
    ctx->r16 = ADD32(ctx->r16, 0XD);
    after_2:
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // lhu         $v0, 0x130($s1)
    ctx->r2 = MEM_HU(0X130, ctx->r17);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // jal         0x80040F04
    // sh          $v0, 0x130($s1)
    MEM_H(0X130, ctx->r17) = ctx->r2;
    sub_80040F04(rdram, ctx);
    goto after_3;
    // sh          $v0, 0x130($s1)
    MEM_H(0X130, ctx->r17) = ctx->r2;
    after_3:
    // lhu         $v0, 0x130($s1)
    ctx->r2 = MEM_HU(0X130, ctx->r17);
    // nop

    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // j           L_800409F0
    // sh          $v0, 0x130($s1)
    MEM_H(0X130, ctx->r17) = ctx->r2;
    goto L_800409F0;
    // sh          $v0, 0x130($s1)
    MEM_H(0X130, ctx->r17) = ctx->r2;
L_80040818:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v1, $v0, -0x2E80
    ctx->r3 = ADD32(ctx->r2, -0X2E80);
    // lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(0X2, ctx->r3);
    // lhu         $v0, 0x32($v1)
    ctx->r2 = MEM_HU(0X32, ctx->r3);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // bne         $v0, $zero, L_80040840
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80040840;
    }
    // nop

    // beq         $s3, $zero, L_8004085C
    if (ctx->r19 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8004085C;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80040840:
    // lhu         $v0, 0x34($v1)
    ctx->r2 = MEM_HU(0X34, ctx->r3);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // bne         $v0, $zero, L_80040878
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040878;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // beq         $s3, $zero, L_8004087C
    if (ctx->r19 == 0) {
        // addiu       $a1, $v0, -0x70D8
        ctx->r5 = ADD32(ctx->r2, -0X70D8);
        goto L_8004087C;
    }
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
L_8004085C:
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lhu         $a0, 0x17E($v0)
    ctx->r4 = MEM_HU(0X17E, ctx->r2);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x21F($v0)
    MEM_B(0X21F, ctx->r2) = ctx->r3;
    // sh          $zero, 0x17E($v0)
    MEM_H(0X17E, ctx->r2) = 0;
    // j           L_800409F0
    // sh          $a0, 0x180($v0)
    MEM_H(0X180, ctx->r2) = ctx->r4;
    goto L_800409F0;
    // sh          $a0, 0x180($v0)
    MEM_H(0X180, ctx->r2) = ctx->r4;
L_80040878:
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
L_8004087C:
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lh          $a0, 0x134($v0)
    ctx->r4 = MEM_HS(0X134, ctx->r2);
    // lh          $v1, 0x130($v0)
    ctx->r3 = MEM_HS(0X130, ctx->r2);
    // subu        $v0, $a0, $s2
    ctx->r2 = SUB32(ctx->r4, ctx->r18);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80040904
    if (ctx->r2 == 0) {
        // slt         $v0, $a0, $v1
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_80040904;
    }
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80040908
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040908;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v1, 0x64($a1)
    ctx->r3 = MEM_HS(0X64, ctx->r5);
    // addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v0, $t1, 8
    ctx->r2 = S32(ctx->r9) >> 8;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $a0, $v0, 0x60
    ctx->r4 = ADD32(ctx->r2, 0X60);
    // lhu         $v0, 0x17E($a1)
    ctx->r2 = MEM_HU(0X17E, ctx->r5);
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x17E($a1)
    MEM_H(0X17E, ctx->r5) = ctx->r2;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x1401
    ctx->r2 = ctx->r2 < 0X1401 ? 1 : 0;
    // bne         $v0, $zero, L_800409F4
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800409F4;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $zero, 0x1400
    ctx->r2 = ADD32(0, 0X1400);
    // j           L_800409F0
    // sh          $v0, 0x17E($a1)
    MEM_H(0X17E, ctx->r5) = ctx->r2;
    goto L_800409F0;
    // sh          $v0, 0x17E($a1)
    MEM_H(0X17E, ctx->r5) = ctx->r2;
L_80040904:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80040908:
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x130($v0)
    ctx->r2 = MEM_HS(0X130, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80040944
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040944;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, 0x154($v1)
    ctx->r2 = MEM_BU(0X154, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80040944
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040944;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sb          $zero, 0x154($v1)
    MEM_B(0X154, ctx->r3) = 0;
    // j           L_800409F4
    // sb          $zero, 0x21F($v1)
    MEM_B(0X21F, ctx->r3) = 0;
    goto L_800409F4;
    // sb          $zero, 0x21F($v1)
    MEM_B(0X21F, ctx->r3) = 0;
L_80040944:
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lh          $v0, 0x64($s0)
    ctx->r2 = MEM_HS(0X64, ctx->r16);
    // addiu       $v1, $zero, 0x60
    ctx->r3 = ADD32(0, 0X60);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v1, $t1, 8
    ctx->r3 = S32(ctx->r9) >> 8;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x17E($s0)
    ctx->r2 = MEM_HU(0X17E, ctx->r16);
    // addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x17E($s0)
    MEM_H(0X17E, ctx->r16) = ctx->r2;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x1401
    ctx->r2 = ctx->r2 < 0X1401 ? 1 : 0;
    // bne         $v0, $zero, L_8004099C
    if (ctx->r2 != 0) {
        // andi        $a1, $s6, 0xFF
        ctx->r5 = ctx->r22 & 0XFF;
        goto L_8004099C;
    }
    // andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // addiu       $v0, $zero, 0x1400
    ctx->r2 = ADD32(0, 0X1400);
    // sh          $v0, 0x17E($s0)
    MEM_H(0X17E, ctx->r16) = ctx->r2;
L_8004099C:
    // sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5) << 1;
    // addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // lhu         $v0, 0x130($v1)
    ctx->r2 = MEM_HU(0X130, ctx->r3);
    // lh          $a0, 0x138($v1)
    ctx->r4 = MEM_HS(0X138, ctx->r3);
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sh          $v0, 0x130($v1)
    MEM_H(0X130, ctx->r3) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // subu        $v0, $a0, $s2
    ctx->r2 = SUB32(ctx->r4, ctx->r18);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_800409F0
    if (ctx->r2 == 0) {
        // slt         $v0, $a0, $v1
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_800409F0;
    }
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_800409F4
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800409F4;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addu        $v0, $a1, $s0
    ctx->r2 = ADD32(ctx->r5, ctx->r16);
    // lbu         $a0, 0x1D4($v0)
    ctx->r4 = MEM_BU(0X1D4, ctx->r2);
    // jal         0x800582F0
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    sub_800582F0(rdram, ctx);
    goto after_4;
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_4:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // jal         0x8003D104
    // addiu       $a1, $s0, 0x3E
    ctx->r5 = ADD32(ctx->r16, 0X3E);
    sub_8003D104(rdram, ctx);
    goto after_5;
    // addiu       $a1, $s0, 0x3E
    ctx->r5 = ADD32(ctx->r16, 0X3E);
    after_5:
L_800409F0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_800409F4:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x130($v1)
    ctx->r2 = MEM_HU(0X130, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_80040A2C
    if (ctx->r2 != 0) {
        // xori        $v0, $s6, 0x1
        ctx->r2 = ctx->r22 ^ 0X1;
        goto L_80040A2C;
    }
    // xori        $v0, $s6, 0x1
    ctx->r2 = ctx->r22 ^ 0X1;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $v0, 0x130($v1)
    MEM_H(0X130, ctx->r3) = ctx->r2;
    // sb          $zero, 0x14E($a0)
    MEM_B(0X14E, ctx->r4) = 0;
    // sb          $zero, 0x21F($a0)
    MEM_B(0X21F, ctx->r4) = 0;
    // xori        $v0, $s6, 0x1
    ctx->r2 = ctx->r22 ^ 0X1;
L_80040A2C:
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lhu         $v1, 0x130($v1)
    ctx->r3 = MEM_HU(0X130, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // j           L_80040ED0
    // sh          $v1, 0x130($v0)
    MEM_H(0X130, ctx->r2) = ctx->r3;
    goto L_80040ED0;
    // sh          $v1, 0x130($v0)
    MEM_H(0X130, ctx->r2) = ctx->r3;
L_80040A44:
    // j           L_80040ED0
    // sb          $zero, 0x187($a2)
    MEM_B(0X187, ctx->r6) = 0;
    goto L_80040ED0;
    // sb          $zero, 0x187($a2)
    MEM_B(0X187, ctx->r6) = 0;
L_80040A4C:
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $a3, $v0, $a2
    ctx->r7 = ADD32(ctx->r2, ctx->r6);
    // lh          $v1, 0x130($a3)
    ctx->r3 = MEM_HS(0X130, ctx->r7);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_80040E00
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x51EB
        ctx->r2 = S32(0X51EB << 16);
        goto L_80040E00;
    }
    // lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // lhu         $s1, 0x4($s0)
    ctx->r17 = MEM_HU(0X4, ctx->r16);
    // lh          $v1, 0x64($a2)
    ctx->r3 = MEM_HS(0X64, ctx->r6);
    // nop

    // mult        $s1, $v1
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v0, $t1, 9
    ctx->r2 = S32(ctx->r9) >> 9;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a0, $v0, -0x2E80
    ctx->r4 = ADD32(ctx->r2, -0X2E80);
    // lhu         $a1, 0x4($a0)
    ctx->r5 = MEM_HU(0X4, ctx->r4);
    // lhu         $v1, 0x32($a0)
    ctx->r3 = MEM_HU(0X32, ctx->r4);
    // lhu         $s2, 0x8($s0)
    ctx->r18 = MEM_HU(0X8, ctx->r16);
    // and         $v0, $a1, $v1
    ctx->r2 = ctx->r5 & ctx->r3;
    // beq         $v0, $zero, L_80040AC4
    if (ctx->r2 == 0) {
        // nor         $v0, $zero, $v1
        ctx->r2 = ~(0 | ctx->r3);
        goto L_80040AC4;
    }
    // nor         $v0, $zero, $v1
    ctx->r2 = ~(0 | ctx->r3);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
L_80040AC4:
    // lbu         $v0, 0x14E($a2)
    ctx->r2 = MEM_BU(0X14E, ctx->r6);
    // nop

    // beq         $v0, $zero, L_80040AFC
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040AFC;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lh          $v0, 0x134($a3)
    ctx->r2 = MEM_HS(0X134, ctx->r7);
    // lh          $v1, 0x130($a3)
    ctx->r3 = MEM_HS(0X130, ctx->r7);
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // lhu         $v1, 0x130($a3)
    ctx->r3 = MEM_HU(0X130, ctx->r7);
    // bne         $v0, $zero, L_80040AFC
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040AFC;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // subu        $v0, $v1, $s1
    ctx->r2 = SUB32(ctx->r3, ctx->r17);
    // j           L_80040B3C
    // sh          $v0, 0x130($a3)
    MEM_H(0X130, ctx->r7) = ctx->r2;
    goto L_80040B3C;
    // sh          $v0, 0x130($a3)
    MEM_H(0X130, ctx->r7) = ctx->r2;
L_80040AFC:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v0, 0x154($a0)
    ctx->r2 = MEM_BU(0X154, ctx->r4);
    // nop

    // beq         $v0, $zero, L_80040B24
    if (ctx->r2 == 0) {
        // andi        $v1, $s6, 0xFF
        ctx->r3 = ctx->r22 & 0XFF;
        goto L_80040B24;
    }
    // andi        $v1, $s6, 0xFF
    ctx->r3 = ctx->r22 & 0XFF;
    // lhu         $v0, 0x17E($a0)
    ctx->r2 = MEM_HU(0X17E, ctx->r4);
    // sh          $zero, 0x17E($a0)
    MEM_H(0X17E, ctx->r4) = 0;
    // sb          $zero, 0x154($a0)
    MEM_B(0X154, ctx->r4) = 0;
    // j           L_80040B3C
    // sh          $v0, 0x180($a0)
    MEM_H(0X180, ctx->r4) = ctx->r2;
    goto L_80040B3C;
    // sh          $v0, 0x180($a0)
    MEM_H(0X180, ctx->r4) = ctx->r2;
L_80040B24:
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lhu         $v0, 0x130($v1)
    ctx->r2 = MEM_HU(0X130, ctx->r3);
    // nop

    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // sh          $v0, 0x130($v1)
    MEM_H(0X130, ctx->r3) = ctx->r2;
L_80040B3C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $s0, $v0, $a2
    ctx->r16 = ADD32(ctx->r2, ctx->r6);
    // lh          $a0, 0x138($s0)
    ctx->r4 = MEM_HS(0X138, ctx->r16);
    // lh          $v1, 0x130($s0)
    ctx->r3 = MEM_HS(0X130, ctx->r16);
    // subu        $v0, $a0, $s1
    ctx->r2 = SUB32(ctx->r4, ctx->r17);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80040BA0
    if (ctx->r2 == 0) {
        // slt         $v0, $a0, $v1
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_80040BA0;
    }
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80040BA4
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040BA4;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addu        $v0, $a1, $a2
    ctx->r2 = ADD32(ctx->r5, ctx->r6);
    // lbu         $a0, 0x1D4($v0)
    ctx->r4 = MEM_BU(0X1D4, ctx->r2);
    // jal         0x800582F0
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    sub_800582F0(rdram, ctx);
    goto after_6;
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_6:
    // lh          $v0, 0x138($s0)
    ctx->r2 = MEM_HS(0X138, ctx->r16);
    // lhu         $v1, 0x138($s0)
    ctx->r3 = MEM_HU(0X138, ctx->r16);
    // slt         $v0, $v0, $s2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // bne         $v0, $zero, L_80040B9C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1388
        ctx->r2 = ADD32(0, 0X1388);
        goto L_80040B9C;
    }
    // addiu       $v0, $zero, 0x1388
    ctx->r2 = ADD32(0, 0X1388);
    // j           L_80040BA0
    // sh          $v0, 0x138($s0)
    MEM_H(0X138, ctx->r16) = ctx->r2;
    goto L_80040BA0;
    // sh          $v0, 0x138($s0)
    MEM_H(0X138, ctx->r16) = ctx->r2;
L_80040B9C:
    // sh          $v1, 0x138($s0)
    MEM_H(0X138, ctx->r16) = ctx->r3;
L_80040BA0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80040BA4:
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // addu        $v0, $a1, $a2
    ctx->r2 = ADD32(ctx->r5, ctx->r6);
    // lbu         $v0, 0x148($v0)
    ctx->r2 = MEM_BU(0X148, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x24
    ctx->r2 = ADD32(ctx->r2, -0X24);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0xDB
    ctx->r2 = ctx->r2 < 0XDB ? 1 : 0;
    // bne         $v0, $zero, L_80040ED0
    if (ctx->r2 != 0) {
        // sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5) << 1;
        goto L_80040ED0;
    }
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // lh          $a0, 0x134($v0)
    ctx->r4 = MEM_HS(0X134, ctx->r2);
    // lh          $v1, 0x130($v0)
    ctx->r3 = MEM_HS(0X130, ctx->r2);
    // subu        $v0, $a0, $s1
    ctx->r2 = SUB32(ctx->r4, ctx->r17);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80040DCC
    if (ctx->r2 == 0) {
        // slt         $v0, $a0, $v1
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_80040DCC;
    }
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80040DD0
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040DD0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s1, $v0, -0x5EC8
    ctx->r17 = ADD32(ctx->r2, -0X5EC8);
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // addu        $s4, $s3, $zero
    ctx->r20 = ADD32(ctx->r19, 0);
    // addu        $fp, $s3, $zero
    ctx->r30 = ADD32(ctx->r19, 0);
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // lw          $v0, 0xE8($v0)
    ctx->r2 = MEM_W(0XE8, ctx->r2);
    // addu        $s5, $s1, $zero
    ctx->r21 = ADD32(ctx->r17, 0);
    // lhu         $s7, 0x2($v0)
    ctx->r23 = MEM_HU(0X2, ctx->r2);
    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // sw          $zero, 0x6144($s1)
    MEM_W(0X6144, ctx->r17) = 0;
L_80040C24:
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80040CA4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80040CA4;
    }
    // nop

    // jal         0x8004C03C
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_8004C03C(rdram, ctx);
    goto after_7;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_7:
    // lbu         $v1, 0x5($s0)
    ctx->r3 = MEM_BU(0X5, ctx->r16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80040CA4
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80040CA4;
    }
    // nop

    // lbu         $v0, 0x1F($s0)
    ctx->r2 = MEM_BU(0X1F, ctx->r16);
    // nop

    // beq         $v0, $v1, L_80040CA4
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80040CA4;
    }
    // nop

    // lhu         $v0, 0x2C($s0)
    ctx->r2 = MEM_HU(0X2C, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80040CA4
    if (ctx->r2 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_80040CA4;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23) << 16;
    // jal         0x8004DB9C
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8004DB9C(rdram, ctx);
    goto after_8;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_8:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // beq         $a0, $zero, L_80040CA4
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80040CA4;
    }
    // nop

    // lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(0X3C, ctx->r16);
    // nop

    // sltu        $v0, $v1, $s2
    ctx->r2 = ctx->r3 < ctx->r18 ? 1 : 0;
    // beq         $v0, $zero, L_80040CA4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040CA4;
    }
    // nop

    // addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
L_80040CA4:
    // addiu       $s0, $s0, 0xD4
    ctx->r16 = ADD32(ctx->r16, 0XD4);
    // lw          $v0, 0x6144($s5)
    ctx->r2 = MEM_W(0X6144, ctx->r21);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x6144($s5)
    MEM_W(0X6144, ctx->r21) = ctx->r2;
    // slti        $v0, $v0, 0x40
    ctx->r2 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_80040C24
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0xD4
        ctx->r17 = ADD32(ctx->r17, 0XD4);
        goto L_80040C24;
    }
    // addiu       $s1, $s1, 0xD4
    ctx->r17 = ADD32(ctx->r17, 0XD4);
    // beq         $s3, $zero, L_80040CF8
    if (ctx->r19 == 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_80040CF8;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // addiu       $a3, $a3, -0x70D8
    ctx->r7 = ADD32(ctx->r7, -0X70D8);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // lhu         $a2, 0x180($a3)
    ctx->r6 = MEM_HU(0X180, ctx->r7);
    // addiu       $a3, $a3, 0xBA
    ctx->r7 = ADD32(ctx->r7, 0XBA);
    // jal         0x8004DEF8
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sub_8004DEF8(rdram, ctx);
    goto after_9;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // jal         0x80026A88
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    sub_80026A88(rdram, ctx);
    goto after_10;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    after_10:
L_80040CF8:
    // beq         $s4, $zero, L_80040DCC
    if (ctx->r20 == 0) {
        // sll         $v0, $fp, 16
        ctx->r2 = S32(ctx->r30) << 16;
        goto L_80040DCC;
    }
    // sll         $v0, $fp, 16
    ctx->r2 = S32(ctx->r30) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a0, $v0, L_80040DD0
    if (ctx->r4 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040DD0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v1, 0x2($s3)
    ctx->r3 = MEM_BU(0X2, ctx->r19);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x29C8
    ctx->r3 = ADD32(ctx->r3, -0X29C8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x32($v0)
    ctx->r3 = MEM_HU(0X32, ctx->r2);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80040D58
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040D58;
    }
    // nop

    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lbu         $v0, 0x21B($v1)
    ctx->r2 = MEM_BU(0X21B, ctx->r3);
    // j           L_80040D98
    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    goto L_80040D98;
    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
L_80040D58:
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80040D7C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040D7C;
    }
    // nop

    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lbu         $v0, 0x21B($v1)
    ctx->r2 = MEM_BU(0X21B, ctx->r3);
    // j           L_80040D98
    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    goto L_80040D98;
    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_80040D7C:
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80040D9C
    if (ctx->r2 == 0) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_80040D9C;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lbu         $v0, 0x21B($v1)
    ctx->r2 = MEM_BU(0X21B, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80040D98:
    // sb          $v0, 0x21B($v1)
    MEM_B(0X21B, ctx->r3) = ctx->r2;
L_80040D9C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v1, 0x21B($a1)
    ctx->r3 = MEM_BU(0X21B, ctx->r5);
    // nop

    // sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // bne         $v0, $zero, L_80040DD0
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040DD0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v1, -0x7
    ctx->r2 = ADD32(ctx->r3, -0X7);
    // sb          $v0, 0x21B($a1)
    MEM_B(0X21B, ctx->r5) = ctx->r2;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // jal         0x8003D104
    // addiu       $a1, $a1, 0x3E
    ctx->r5 = ADD32(ctx->r5, 0X3E);
    sub_8003D104(rdram, ctx);
    goto after_11;
    // addiu       $a1, $a1, 0x3E
    ctx->r5 = ADD32(ctx->r5, 0X3E);
    after_11:
L_80040DCC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80040DD0:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x130($v1)
    ctx->r2 = MEM_HU(0X130, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_80040ED0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80040ED0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $v0, 0x130($v1)
    MEM_H(0X130, ctx->r3) = ctx->r2;
    // j           L_80040ED0
    // sb          $zero, 0x14E($a0)
    MEM_B(0X14E, ctx->r4) = 0;
    goto L_80040ED0;
    // sb          $zero, 0x14E($a0)
    MEM_B(0X14E, ctx->r4) = 0;
L_80040E00:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // lhu         $v0, 0x32($v0)
    ctx->r2 = MEM_HU(0X32, ctx->r2);
    // nop

    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // bne         $v1, $zero, L_80040ED0
    if (ctx->r3 != 0) {
        // sb          $zero, 0x14E($a2)
        MEM_B(0X14E, ctx->r6) = 0;
        goto L_80040ED0;
    }
    // sb          $zero, 0x14E($a2)
    MEM_B(0X14E, ctx->r6) = 0;
    // lbu         $v0, 0x187($a2)
    ctx->r2 = MEM_BU(0X187, ctx->r6);
    // nop

    // bne         $v0, $zero, L_80040ECC
    if (ctx->r2 != 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80040ECC;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lh          $v0, 0x64($a2)
    ctx->r2 = MEM_HS(0X64, ctx->r6);
    // nop

    // addiu       $v1, $v0, 0x3E8
    ctx->r3 = ADD32(ctx->r2, 0X3E8);
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_80040E4C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80040E4C;
    }
    // nop

    // break       7
    do_break(2147749448);
L_80040E4C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80040E64
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80040E64;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80040E64
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80040E64;
    }
    // nop

    // break       6
    do_break(2147749472);
L_80040E64:
    // mflo        $v0
    ctx->r2 = lo;
    // addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x58($a2)
    ctx->r3 = MEM_HU(0X58, ctx->r6);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // mflo        $t1
    ctx->r9 = lo;
    // beq         $v1, $v0, L_80040E9C
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $t1, 0x60
        ctx->r4 = ADD32(ctx->r9, 0X60);
        goto L_80040E9C;
    }
    // addiu       $a0, $t1, 0x60
    ctx->r4 = ADD32(ctx->r9, 0X60);
    // lh          $v0, 0x132($a2)
    ctx->r2 = MEM_HS(0X132, ctx->r6);
    // nop

    // bltz        $v0, L_80040EA0
    if (SIGNED(ctx->r2) < 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040EA0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sra         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) >> 1;
L_80040E9C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80040EA0:
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x17E($a1)
    ctx->r2 = MEM_HU(0X17E, ctx->r5);
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x17E($a1)
    MEM_H(0X17E, ctx->r5) = ctx->r2;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x1401
    ctx->r2 = ctx->r2 < 0X1401 ? 1 : 0;
    // bne         $v0, $zero, L_80040ED0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1400
        ctx->r2 = ADD32(0, 0X1400);
        goto L_80040ED0;
    }
    // addiu       $v0, $zero, 0x1400
    ctx->r2 = ADD32(0, 0X1400);
    // j           L_80040ED0
    // sh          $v0, 0x17E($a1)
    MEM_H(0X17E, ctx->r5) = ctx->r2;
    goto L_80040ED0;
    // sh          $v0, 0x17E($a1)
    MEM_H(0X17E, ctx->r5) = ctx->r2;
L_80040ECC:
    // sb          $v0, 0x187($a2)
    MEM_B(0X187, ctx->r6) = ctx->r2;
L_80040ED0:
    // lw          $ra, 0xCC($sp)
    ctx->r31 = MEM_W(0XCC, ctx->r29);
    // lw          $fp, 0xC8($sp)
    ctx->r30 = MEM_W(0XC8, ctx->r29);
    // lw          $s7, 0xC4($sp)
    ctx->r23 = MEM_W(0XC4, ctx->r29);
    // lw          $s6, 0xC0($sp)
    ctx->r22 = MEM_W(0XC0, ctx->r29);
    // lw          $s5, 0xBC($sp)
    ctx->r21 = MEM_W(0XBC, ctx->r29);
    // lw          $s4, 0xB8($sp)
    ctx->r20 = MEM_W(0XB8, ctx->r29);
    // lw          $s3, 0xB4($sp)
    ctx->r19 = MEM_W(0XB4, ctx->r29);
    // lw          $s2, 0xB0($sp)
    ctx->r18 = MEM_W(0XB0, ctx->r29);
    // lw          $s1, 0xAC($sp)
    ctx->r17 = MEM_W(0XAC, ctx->r29);
    // lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(0XA8, ctx->r29);
    // addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    // jr          $ra
    // nop

    return;
    // nop

;}
