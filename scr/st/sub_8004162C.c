#include "recomp.h"
#include "disable_warnings.h"

void sub_8004162C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // jal         0x80078AB4
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    memset_recomp(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $t2, $v0, -0x70D8
    ctx->r10 = ADD32(ctx->r2, -0X70D8);
    // lh          $v0, 0x2C8($t2)
    ctx->r2 = MEM_HS(0X2C8, ctx->r10);
    // nop

    // beq         $v0, $zero, L_8004168C
    if (ctx->r2 == 0) {
        // addu        $s5, $s6, $zero
        ctx->r21 = ADD32(ctx->r22, 0);
        goto L_8004168C;
    }
    // addu        $s5, $s6, $zero
    ctx->r21 = ADD32(ctx->r22, 0);
    // lbu         $v0, 0x21E($t2)
    ctx->r2 = MEM_BU(0X21E, ctx->r10);
    // nop

    // beq         $v0, $zero, L_800419E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800419E4;
    }
    // nop

L_8004168C:
    // lh          $a1, 0x1CC($t2)
    ctx->r5 = MEM_HS(0X1CC, ctx->r10);
    // nop

    // mult        $a1, $a1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // mflo        $t3
    ctx->r11 = lo;
    // lh          $a0, 0x1D0($t2)
    ctx->r4 = MEM_HS(0X1D0, ctx->r10);
    // addiu       $v1, $a2, 0x5948
    ctx->r3 = ADD32(ctx->r6, 0X5948);
    // mult        $a0, $a0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x248($t2)
    ctx->r2 = MEM_W(0X248, ctx->r10);
    // lw          $a3, 0x24C($t2)
    ctx->r7 = MEM_W(0X24C, ctx->r10);
    // lw          $t0, 0x250($t2)
    ctx->r8 = MEM_W(0X250, ctx->r10);
    // lw          $t1, 0x254($t2)
    ctx->r9 = MEM_W(0X254, ctx->r10);
    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // sw          $a3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r7;
    // sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // sw          $t1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r9;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x640
    ctx->r2 = ADD32(0, 0X640);
    // sh          $v0, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r2;
    // lh          $v1, 0x2D4($t2)
    ctx->r3 = MEM_HS(0X2D4, ctx->r10);
    // addiu       $v0, $zero, 0x432
    ctx->r2 = ADD32(0, 0X432);
    // sw          $v0, 0x5948($a2)
    MEM_W(0X5948, ctx->r6) = ctx->r2;
    // sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // mflo        $t4
    ctx->r12 = lo;
    // jal         0x800746C4
    // addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    SquareRoot0(rdram, ctx);
    goto after_1;
    // addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(0X10, ctx->r29);
    // jal         0x80076EA4
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    ratan2(rdram, ctx);
    goto after_2;
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    after_2:
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_80041714:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x10($sp)
    ctx->r3 = MEM_HU(0X10, ctx->r29);
    // lhu         $a0, 0x14($sp)
    ctx->r4 = MEM_HU(0X14, ctx->r29);
    // lhu         $a1, 0x18($sp)
    ctx->r5 = MEM_HU(0X18, ctx->r29);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $s2, $v0, 0x5948
    ctx->r18 = ADD32(ctx->r2, 0X5948);
    // addiu       $v0, $zero, 0x270F
    ctx->r2 = ADD32(0, 0X270F);
    // sh          $v0, 0x20($s2)
    MEM_H(0X20, ctx->r18) = ctx->r2;
    // sh          $v1, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r3;
    // sh          $a0, 0x16($s2)
    MEM_H(0X16, ctx->r18) = ctx->r4;
    // sh          $a1, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r5;
    // mflo        $a3
    ctx->r7 = lo;
    // jal         0x800746C4
    // addu        $a0, $a2, $a3
    ctx->r4 = ADD32(ctx->r6, ctx->r7);
    SquareRoot0(rdram, ctx);
    goto after_3;
    // addu        $a0, $a2, $a3
    ctx->r4 = ADD32(ctx->r6, ctx->r7);
    after_3:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sh          $v0, 0x22($s2)
    MEM_H(0X22, ctx->r18) = ctx->r2;
    // sh          $zero, 0x47CE($s2)
    MEM_H(0X47CE, ctx->r18) = 0;
    // sh          $zero, 0x47D0($s2)
    MEM_H(0X47D0, ctx->r18) = 0;
    // jal         0x80049544
    // sh          $zero, 0x47D2($s2)
    MEM_H(0X47D2, ctx->r18) = 0;
    sub_80049544(rdram, ctx);
    goto after_4;
    // sh          $zero, 0x47D2($s2)
    MEM_H(0X47D2, ctx->r18) = 0;
    after_4:
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // bne         $a3, $zero, L_800417C8
    if (ctx->r7 != 0) {
        // andi        $v0, $a3, 0x1
        ctx->r2 = ctx->r7 & 0X1;
        goto L_800417C8;
    }
    // andi        $v0, $a3, 0x1
    ctx->r2 = ctx->r7 & 0X1;
L_80041788:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lw          $v0, 0x248($v1)
    ctx->r2 = MEM_W(0X248, ctx->r3);
    // lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(0X10, ctx->r29);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x248($v1)
    MEM_W(0X248, ctx->r3) = ctx->r2;
    // lw          $v0, 0x24C($v1)
    ctx->r2 = MEM_W(0X24C, ctx->r3);
    // lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(0X14, ctx->r29);
    // lw          $a0, 0x250($v1)
    ctx->r4 = MEM_W(0X250, ctx->r3);
    // lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(0X18, ctx->r29);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // sw          $v0, 0x24C($v1)
    MEM_W(0X24C, ctx->r3) = ctx->r2;
    // j           L_80041984
    // sw          $a0, 0x250($v1)
    MEM_W(0X250, ctx->r3) = ctx->r4;
    goto L_80041984;
    // sw          $a0, 0x250($v1)
    MEM_W(0X250, ctx->r3) = ctx->r4;
L_800417C8:
    // beq         $v0, $zero, L_80041808
    if (ctx->r2 == 0) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_80041808;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lw          $v0, 0x248($v1)
    ctx->r2 = MEM_W(0X248, ctx->r3);
    // lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(0X10, ctx->r29);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x248($v1)
    MEM_W(0X248, ctx->r3) = ctx->r2;
    // lw          $v0, 0x24C($v1)
    ctx->r2 = MEM_W(0X24C, ctx->r3);
    // lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(0X14, ctx->r29);
    // lw          $a0, 0x250($v1)
    ctx->r4 = MEM_W(0X250, ctx->r3);
    // lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(0X18, ctx->r29);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // sw          $v0, 0x24C($v1)
    MEM_W(0X24C, ctx->r3) = ctx->r2;
    // sw          $a0, 0x250($v1)
    MEM_W(0X250, ctx->r3) = ctx->r4;
L_80041808:
    // andi        $v0, $a3, 0x2
    ctx->r2 = ctx->r7 & 0X2;
    // beq         $v0, $zero, L_8004188C
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0x101
        ctx->r3 = ADD32(0, 0X101);
        goto L_8004188C;
    }
    // addiu       $v1, $zero, 0x101
    ctx->r3 = ADD32(0, 0X101);
    // lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(0X3C, ctx->r18);
    // lh          $a1, 0x8C($s2)
    ctx->r5 = MEM_HS(0X8C, ctx->r18);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80041834
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80041834;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80041834:
    // lh          $a0, 0x90($s2)
    ctx->r4 = MEM_HS(0X90, ctx->r18);
    // nop

    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80041854
    if (SIGNED(ctx->r3) >= 0) {
        // sw          $v0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r2;
        goto L_80041854;
    }
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80041854:
    // sra         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3) >> 12;
    // bne         $s5, $zero, L_80041788
    if (ctx->r21 != 0) {
        // sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_80041788;
    }
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x80076EA4
    // addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    ratan2(rdram, ctx);
    goto after_5;
    // addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    after_5:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // sw          $s1, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r17;
    // sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // jal         0x800744C4
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    rcos(rdram, ctx);
    goto after_6;
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    after_6:
    // j           L_8004190C
    // mult        $s4, $v0
    result = S64(S32(ctx->r20)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    goto L_8004190C;
    // mult        $s4, $v0
    result = S64(S32(ctx->r20)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8004188C:
    // andi        $v0, $a3, 0x8
    ctx->r2 = ctx->r7 & 0X8;
    // beq         $v0, $zero, L_80041988
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80041988;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v0, 0x44($s2)
    ctx->r2 = MEM_W(0X44, ctx->r18);
    // lh          $a1, 0x9C($s2)
    ctx->r5 = MEM_HS(0X9C, ctx->r18);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_800418B8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800418B8;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_800418B8:
    // lh          $a0, 0xA0($s2)
    ctx->r4 = MEM_HS(0XA0, ctx->r18);
    // nop

    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_800418D8
    if (SIGNED(ctx->r3) >= 0) {
        // sw          $v0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r2;
        goto L_800418D8;
    }
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_800418D8:
    // sra         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3) >> 12;
    // bne         $s6, $zero, L_80041788
    if (ctx->r22 != 0) {
        // sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_80041788;
    }
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x80076EA4
    // addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    ratan2(rdram, ctx);
    goto after_7;
    // addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    after_7:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // sw          $s1, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r17;
    // sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // jal         0x800744C4
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    rcos(rdram, ctx);
    goto after_8;
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    after_8:
    // mult        $s4, $v0
    result = S64(S32(ctx->r20)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8004190C:
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80041920
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $s0, $v0, 12
        ctx->r16 = S32(ctx->r2) >> 12;
        goto L_80041920;
    }
    // sra         $s0, $v0, 12
    ctx->r16 = S32(ctx->r2) >> 12;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
    // sra         $s0, $v0, 12
    ctx->r16 = S32(ctx->r2) >> 12;
L_80041920:
    // beq         $s0, $zero, L_80041714
    if (ctx->r16 == 0) {
        // sh          $s0, 0x44C6($s2)
        MEM_H(0X44C6, ctx->r18) = ctx->r16;
        goto L_80041714;
    }
    // sh          $s0, 0x44C6($s2)
    MEM_H(0X44C6, ctx->r18) = ctx->r16;
    // addiu       $s1, $s1, 0x400
    ctx->r17 = ADD32(ctx->r17, 0X400);
    // jal         0x800744C4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    rcos(rdram, ctx);
    goto after_9;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_9:
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80041948
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_80041948;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80041948:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x800743F4
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    rsin(rdram, ctx);
    goto after_10;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_10:
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80041970
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80041970;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80041970:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_80041714
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    goto L_80041714;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_80041984:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80041988:
    // addiu       $a0, $v0, 0x5948
    ctx->r4 = ADD32(ctx->r2, 0X5948);
    // lh          $v1, 0x47CE($a0)
    ctx->r3 = MEM_HS(0X47CE, ctx->r4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // bgez        $v1, L_800419A0
    if (SIGNED(ctx->r3) >= 0) {
        // addiu       $a3, $v0, -0x70D8
        ctx->r7 = ADD32(ctx->r2, -0X70D8);
        goto L_800419A0;
    }
    // addiu       $a3, $v0, -0x70D8
    ctx->r7 = ADD32(ctx->r2, -0X70D8);
    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_800419A0:
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // lhu         $v0, 0x1CC($a3)
    ctx->r2 = MEM_HU(0X1CC, ctx->r7);
    // lh          $a0, 0x47D2($a0)
    ctx->r4 = MEM_HS(0X47D2, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // bgez        $a0, L_800419BC
    if (SIGNED(ctx->r4) >= 0) {
        // sh          $v0, 0x1CC($a3)
        MEM_H(0X1CC, ctx->r7) = ctx->r2;
        goto L_800419BC;
    }
    // sh          $v0, 0x1CC($a3)
    MEM_H(0X1CC, ctx->r7) = ctx->r2;
    // addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
L_800419BC:
    // sra         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) >> 2;
    // lhu         $v0, 0x1D0($a3)
    ctx->r2 = MEM_HU(0X1D0, ctx->r7);
    // lhu         $a0, 0x10($sp)
    ctx->r4 = MEM_HU(0X10, ctx->r29);
    // lhu         $a1, 0x14($sp)
    ctx->r5 = MEM_HU(0X14, ctx->r29);
    // lhu         $a2, 0x18($sp)
    ctx->r6 = MEM_HU(0X18, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1D0($a3)
    MEM_H(0X1D0, ctx->r7) = ctx->r2;
    // sh          $a0, 0x260($a3)
    MEM_H(0X260, ctx->r7) = ctx->r4;
    // sh          $a1, 0x262($a3)
    MEM_H(0X262, ctx->r7) = ctx->r5;
    // sh          $a2, 0x264($a3)
    MEM_H(0X264, ctx->r7) = ctx->r6;
L_800419E4:
    // jal         0x8003BDB0
    // nop

    sub_8003BDB0(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $a3, $v0, 0x5948
    ctx->r7 = ADD32(ctx->r2, 0X5948);
    // lw          $a2, 0x2C($a3)
    ctx->r6 = MEM_W(0X2C, ctx->r7);
    // nop

    // addiu       $a1, $a2, -0x640
    ctx->r5 = ADD32(ctx->r6, -0X640);
    // bgez        $a1, L_80041AAC
    if (SIGNED(ctx->r5) >= 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80041AAC;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lh          $a0, 0x2D4($s0)
    ctx->r4 = MEM_HS(0X2D4, ctx->r16);
    // lhu         $v1, 0x2D4($s0)
    ctx->r3 = MEM_HU(0X2D4, ctx->r16);
    // blez        $a0, L_80041A3C
    if (SIGNED(ctx->r4) <= 0) {
        // nop
    
        goto L_80041A3C;
    }
    // nop

    // jal         0x80057B48
    // nop

    sub_80057B48(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lhu         $v0, 0x2D4($s0)
    ctx->r2 = MEM_HU(0X2D4, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 18
    ctx->r2 = S32(ctx->r2) >> 18;
    // j           L_80041B50
    // sh          $v0, 0x2D4($s0)
    MEM_H(0X2D4, ctx->r16) = ctx->r2;
    goto L_80041B50;
    // sh          $v0, 0x2D4($s0)
    MEM_H(0X2D4, ctx->r16) = ctx->r2;
L_80041A3C:
    // bgez        $a0, L_80041A84
    if (SIGNED(ctx->r4) >= 0) {
        // slti        $v0, $a1, -0x1F
        ctx->r2 = SIGNED(ctx->r5) < -0X1F ? 1 : 0;
        goto L_80041A84;
    }
    // slti        $v0, $a1, -0x1F
    ctx->r2 = SIGNED(ctx->r5) < -0X1F ? 1 : 0;
    // slti        $v0, $a1, -0x400
    ctx->r2 = SIGNED(ctx->r5) < -0X400 ? 1 : 0;
    // bne         $v0, $zero, L_80041A54
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x30
        ctx->r2 = ADD32(ctx->r3, -0X30);
        goto L_80041A54;
    }
    // addiu       $v0, $v1, -0x30
    ctx->r2 = ADD32(ctx->r3, -0X30);
    // sw          $zero, 0x2E4($s0)
    MEM_W(0X2E4, ctx->r16) = 0;
L_80041A54:
    // sh          $v0, 0x2D4($s0)
    MEM_H(0X2D4, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // subu        $v0, $a2, $v0
    ctx->r2 = SUB32(ctx->r6, ctx->r2);
    // slti        $v0, $v0, 0x641
    ctx->r2 = SIGNED(ctx->r2) < 0X641 ? 1 : 0;
    // bne         $v0, $zero, L_80041B54
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80041B54;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, 0x2C($a3)
    ctx->r2 = MEM_HU(0X2C, ctx->r7);
    // nop

    // addiu       $v0, $v0, -0x640
    ctx->r2 = ADD32(ctx->r2, -0X640);
    // j           L_80041B50
    // sh          $v0, 0x2D4($s0)
    MEM_H(0X2D4, ctx->r16) = ctx->r2;
    goto L_80041B50;
    // sh          $v0, 0x2D4($s0)
    MEM_H(0X2D4, ctx->r16) = ctx->r2;
L_80041A84:
    // bne         $v0, $zero, L_80041A98
    if (ctx->r2 != 0) {
        // slti        $v0, $a1, -0x400
        ctx->r2 = SIGNED(ctx->r5) < -0X400 ? 1 : 0;
        goto L_80041A98;
    }
    // slti        $v0, $a1, -0x400
    ctx->r2 = SIGNED(ctx->r5) < -0X400 ? 1 : 0;
    // subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // j           L_80041B50
    // sh          $v0, 0x2D4($s0)
    MEM_H(0X2D4, ctx->r16) = ctx->r2;
    goto L_80041B50;
    // sh          $v0, 0x2D4($s0)
    MEM_H(0X2D4, ctx->r16) = ctx->r2;
L_80041A98:
    // bne         $v0, $zero, L_80041AA4
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x10
        ctx->r2 = ADD32(ctx->r3, -0X10);
        goto L_80041AA4;
    }
    // addiu       $v0, $v1, -0x10
    ctx->r2 = ADD32(ctx->r3, -0X10);
    // sw          $zero, 0x2E4($s0)
    MEM_W(0X2E4, ctx->r16) = 0;
L_80041AA4:
    // j           L_80041B50
    // sh          $v0, 0x2D4($s0)
    MEM_H(0X2D4, ctx->r16) = ctx->r2;
    goto L_80041B50;
    // sh          $v0, 0x2D4($s0)
    MEM_H(0X2D4, ctx->r16) = ctx->r2;
L_80041AAC:
    // blez        $a1, L_80041B40
    if (SIGNED(ctx->r5) <= 0) {
        // addiu       $a2, $v0, -0x70D8
        ctx->r6 = ADD32(ctx->r2, -0X70D8);
        goto L_80041B40;
    }
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // lhu         $a0, 0x2D4($a2)
    ctx->r4 = MEM_HU(0X2D4, ctx->r6);
    // nop

    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // blez        $v1, L_80041AFC
    if (SIGNED(ctx->r3) <= 0) {
        // nop
    
        goto L_80041AFC;
    }
    // nop

    // slti        $v0, $a1, 0x401
    ctx->r2 = SIGNED(ctx->r5) < 0X401 ? 1 : 0;
    // beq         $v0, $zero, L_80041ADC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041ADC;
    }
    // nop

    // sw          $zero, 0x2E4($a2)
    MEM_W(0X2E4, ctx->r6) = 0;
L_80041ADC:
    // lw          $v0, 0x74($a3)
    ctx->r2 = MEM_W(0X74, ctx->r7);
    // addiu       $v1, $zero, -0x10
    ctx->r3 = ADD32(0, -0X10);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_80041B54
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80041B54;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $a0, 0x30
    ctx->r2 = ADD32(ctx->r4, 0X30);
    // j           L_80041B50
    // sh          $v0, 0x2D4($a2)
    MEM_H(0X2D4, ctx->r6) = ctx->r2;
    goto L_80041B50;
    // sh          $v0, 0x2D4($a2)
    MEM_H(0X2D4, ctx->r6) = ctx->r2;
L_80041AFC:
    // bgez        $v1, L_80041B14
    if (SIGNED(ctx->r3) >= 0) {
        // srl         $v0, $v0, 31
        ctx->r2 = S32(U32(ctx->r2) >> 31);
        goto L_80041B14;
    }
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // j           L_80041B50
    // sh          $v0, 0x2D4($a2)
    MEM_H(0X2D4, ctx->r6) = ctx->r2;
    goto L_80041B50;
    // sh          $v0, 0x2D4($a2)
    MEM_H(0X2D4, ctx->r6) = ctx->r2;
L_80041B14:
    // slti        $v0, $a1, 0x20
    ctx->r2 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_80041B28
    if (ctx->r2 == 0) {
        // addu        $v0, $a0, $a1
        ctx->r2 = ADD32(ctx->r4, ctx->r5);
        goto L_80041B28;
    }
    // addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // j           L_80041B50
    // sh          $v0, 0x2D4($a2)
    MEM_H(0X2D4, ctx->r6) = ctx->r2;
    goto L_80041B50;
    // sh          $v0, 0x2D4($a2)
    MEM_H(0X2D4, ctx->r6) = ctx->r2;
L_80041B28:
    // slti        $v0, $a1, 0x401
    ctx->r2 = SIGNED(ctx->r5) < 0X401 ? 1 : 0;
    // beq         $v0, $zero, L_80041B38
    if (ctx->r2 == 0) {
        // addiu       $v0, $a0, 0x10
        ctx->r2 = ADD32(ctx->r4, 0X10);
        goto L_80041B38;
    }
    // addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // sw          $zero, 0x2E4($a2)
    MEM_W(0X2E4, ctx->r6) = 0;
L_80041B38:
    // j           L_80041B50
    // sh          $v0, 0x2D4($a2)
    MEM_H(0X2D4, ctx->r6) = ctx->r2;
    goto L_80041B50;
    // sh          $v0, 0x2D4($a2)
    MEM_H(0X2D4, ctx->r6) = ctx->r2;
L_80041B40:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sb          $zero, 0x239($v0)
    MEM_B(0X239, ctx->r2) = 0;
    // sh          $zero, 0x2D4($v0)
    MEM_H(0X2D4, ctx->r2) = 0;
L_80041B50:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80041B54:
    // lh          $v1, -0x6E04($v0)
    ctx->r3 = MEM_HS(-0X6E04, ctx->r2);
    // nop

    // slti        $v0, $v1, 0x81
    ctx->r2 = SIGNED(ctx->r3) < 0X81 ? 1 : 0;
    // bne         $v0, $zero, L_80041B70
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, -0x80
        ctx->r2 = SIGNED(ctx->r3) < -0X80 ? 1 : 0;
        goto L_80041B70;
    }
    // slti        $v0, $v1, -0x80
    ctx->r2 = SIGNED(ctx->r3) < -0X80 ? 1 : 0;
    // j           L_80041B78
    // addiu       $v0, $v1, -0x80
    ctx->r2 = ADD32(ctx->r3, -0X80);
    goto L_80041B78;
    // addiu       $v0, $v1, -0x80
    ctx->r2 = ADD32(ctx->r3, -0X80);
L_80041B70:
    // beq         $v0, $zero, L_80041B90
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x80
        ctx->r2 = ADD32(ctx->r3, 0X80);
        goto L_80041B90;
    }
    // addiu       $v0, $v1, 0x80
    ctx->r2 = ADD32(ctx->r3, 0X80);
L_80041B78:
    // srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0x17C($gp)
    MEM_H(0X17C, ctx->r28) = ctx->r2;
    // j           L_80041BB4
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    goto L_80041BB4;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80041B90:
    // lhu         $v0, 0x17C($gp)
    ctx->r2 = MEM_HU(0X17C, ctx->r28);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sh          $v1, 0x17C($gp)
    MEM_H(0X17C, ctx->r28) = ctx->r3;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80041BB4:
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x17C($gp)
    ctx->r2 = MEM_HU(0X17C, ctx->r28);
    // lbu         $v1, 0x239($s0)
    ctx->r3 = MEM_BU(0X239, ctx->r16);
    // nop

    // bne         $v1, $zero, L_80041CD4
    if (ctx->r3 != 0) {
        // sh          $v0, 0x290($s0)
        MEM_H(0X290, ctx->r16) = ctx->r2;
        goto L_80041CD4;
    }
    // sh          $v0, 0x290($s0)
    MEM_H(0X290, ctx->r16) = ctx->r2;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, -0x2EDE($v0)
    ctx->r2 = MEM_BU(-0X2EDE, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80041C1C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041C1C;
    }
    // nop

    // lhu         $a0, 0x2D0($s0)
    ctx->r4 = MEM_HU(0X2D0, ctx->r16);
    // lhu         $v0, 0x2C8($s0)
    ctx->r2 = MEM_HU(0X2C8, ctx->r16);
    // nop

    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // jal         0x800743F4
    // sh          $a0, 0x2D0($s0)
    MEM_H(0X2D0, ctx->r16) = ctx->r4;
    rsin(rdram, ctx);
    goto after_13;
    // sh          $a0, 0x2D0($s0)
    MEM_H(0X2D0, ctx->r16) = ctx->r4;
    after_13:
    // sra         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) >> 5;
    // bgez        $v1, L_80041C10
    if (SIGNED(ctx->r3) >= 0) {
        // sra         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) >> 2;
        goto L_80041C10;
    }
    // sra         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) >> 2;
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // sra         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) >> 2;
L_80041C10:
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_80041C20
    // sh          $v0, 0x2CE($s0)
    MEM_H(0X2CE, ctx->r16) = ctx->r2;
    goto L_80041C20;
    // sh          $v0, 0x2CE($s0)
    MEM_H(0X2CE, ctx->r16) = ctx->r2;
L_80041C1C:
    // sh          $zero, 0x2CE($s0)
    MEM_H(0X2CE, ctx->r16) = 0;
L_80041C20:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v0, 0x239($a1)
    ctx->r2 = MEM_BU(0X239, ctx->r5);
    // nop

    // bne         $v0, $zero, L_80041CD4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80041CD4;
    }
    // nop

    // lh          $v0, 0x2D4($a1)
    ctx->r2 = MEM_HS(0X2D4, ctx->r5);
    // nop

    // slti        $v0, $v0, 0x100
    ctx->r2 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // beq         $v0, $zero, L_80041CD4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041CD4;
    }
    // nop

    // lw          $v1, 0x2E4($a1)
    ctx->r3 = MEM_W(0X2E4, ctx->r5);
    // lh          $a0, 0x2C8($a1)
    ctx->r4 = MEM_HS(0X2C8, ctx->r5);
    // sra         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) >> 2;
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80041C70
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_80041C70;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // lw          $v1, 0x244($a1)
    ctx->r3 = MEM_W(0X244, ctx->r5);
    // j           L_80041C94
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    goto L_80041C94;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_80041C70:
    // sra         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) >> 1;
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80041CA0
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_80041CA0;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x244($a1)
    ctx->r3 = MEM_W(0X244, ctx->r5);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
L_80041C94:
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // j           L_80041CB0
    // sw          $v1, 0x244($a1)
    MEM_W(0X244, ctx->r5) = ctx->r3;
    goto L_80041CB0;
    // sw          $v1, 0x244($a1)
    MEM_W(0X244, ctx->r5) = ctx->r3;
L_80041CA0:
    // lw          $v0, 0x244($a1)
    ctx->r2 = MEM_W(0X244, ctx->r5);
    // nop

    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sw          $v0, 0x244($a1)
    MEM_W(0X244, ctx->r5) = ctx->r2;
L_80041CB0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $v0, 0x244($v1)
    ctx->r2 = MEM_W(0X244, ctx->r3);
    // nop

    // bgez        $v0, L_80041CD4
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v0, $zero, 0x800
        ctx->r2 = ADD32(0, 0X800);
        goto L_80041CD4;
    }
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // lh          $a0, 0x2C8($v1)
    ctx->r4 = MEM_HS(0X2C8, ctx->r3);
    // jal         0x80057BAC
    // sw          $v0, 0x244($v1)
    MEM_W(0X244, ctx->r3) = ctx->r2;
    sub_80057BAC(rdram, ctx);
    goto after_14;
    // sw          $v0, 0x244($v1)
    MEM_W(0X244, ctx->r3) = ctx->r2;
    after_14:
L_80041CD4:
    // jal         0x8003BE10
    // nop

    sub_8003BE10(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // lh          $a1, -0x61F0($v0)
    ctx->r5 = MEM_HS(-0X61F0, ctx->r2);
    // lhu         $a2, -0x61F0($v0)
    ctx->r6 = MEM_HU(-0X61F0, ctx->r2);
    // beq         $a1, $v1, L_80041D20
    if (ctx->r5 == ctx->r3) {
        // lui         $a0, 0x801A
        ctx->r4 = S32(0X801A << 16);
        goto L_80041D20;
    }
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x4130
    ctx->r3 = ADD32(ctx->r3, -0X4130);
    // lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(0X174, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x174($a0)
    MEM_W(0X174, ctx->r4) = ctx->r2;
    // sh          $a2, 0x178($a0)
    MEM_H(0X178, ctx->r4) = ctx->r6;
    // sw          $a1, 0x170($a0)
    MEM_W(0X170, ctx->r4) = ctx->r5;
L_80041D20:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
