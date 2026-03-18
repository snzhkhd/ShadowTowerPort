#include "recomp.h"
#include "disable_warnings.h"

void sub_80041150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // jal         0x800744C4
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    rcos(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    after_0:
    // mult        $v0, $s5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // addu        $s6, $fp, $zero
    ctx->r22 = ADD32(ctx->r30, 0);
    // addu        $s7, $s6, $zero
    ctx->r23 = ADD32(ctx->r22, 0);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_800411A8
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $s3, $s6, $zero
        ctx->r19 = ADD32(ctx->r22, 0);
        goto L_800411A8;
    }
    // addu        $s3, $s6, $zero
    ctx->r19 = ADD32(ctx->r22, 0);
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_800411A8:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x800743F4
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    rsin(rdram, ctx);
    goto after_1;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_1:
    // mult        $v0, $s5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // bgez        $t1, L_800411CC
    if (SIGNED(ctx->r9) >= 0) {
        // nop
    
        goto L_800411CC;
    }
    // nop

    // addiu       $t1, $t1, 0xFFF
    ctx->r9 = ADD32(ctx->r9, 0XFFF);
L_800411CC:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // addiu       $v1, $a1, 0x5948
    ctx->r3 = ADD32(ctx->r5, 0X5948);
    // lw          $v0, 0x248($a0)
    ctx->r2 = MEM_W(0X248, ctx->r4);
    // lw          $a2, 0x24C($a0)
    ctx->r6 = MEM_W(0X24C, ctx->r4);
    // lw          $a3, 0x250($a0)
    ctx->r7 = MEM_W(0X250, ctx->r4);
    // lw          $t0, 0x254($a0)
    ctx->r8 = MEM_W(0X254, ctx->r4);
    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // sw          $a2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r6;
    // sw          $a3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r7;
    // sw          $t0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r8;
    // sra         $v0, $t1, 12
    ctx->r2 = S32(ctx->r9) >> 12;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x640
    ctx->r2 = ADD32(0, 0X640);
    // sh          $v0, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r2;
    // lh          $v1, 0x2D4($a0)
    ctx->r3 = MEM_HS(0X2D4, ctx->r4);
    // addiu       $v0, $zero, 0x432
    ctx->r2 = ADD32(0, 0X432);
    // sw          $v0, 0x5948($a1)
    MEM_W(0X5948, ctx->r5) = ctx->r2;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
L_80041224:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $v0, -0x70D8
    ctx->r17 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x1D0($s1)
    ctx->r3 = MEM_HU(0X1D0, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x264($s1)
    MEM_H(0X264, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x10($sp)
    ctx->r2 = MEM_HU(0X10, ctx->r29);
    // lhu         $v1, 0x1CC($s1)
    ctx->r3 = MEM_HU(0X1CC, ctx->r17);
    // lh          $a0, 0x264($s1)
    ctx->r4 = MEM_HS(0X264, ctx->r17);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x260($s1)
    MEM_H(0X260, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x14($sp)
    ctx->r2 = MEM_HU(0X14, ctx->r29);
    // lh          $a1, 0x260($s1)
    ctx->r5 = MEM_HS(0X260, ctx->r17);
    // sh          $v0, 0x262($s1)
    MEM_H(0X262, ctx->r17) = ctx->r2;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $s2, $v0, 0x5948
    ctx->r18 = ADD32(ctx->r2, 0X5948);
    // lwl         $v0, 0x263($s1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X263, ctx->r17);
    // lwr         $v0, 0x260($s1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X260, ctx->r17);
    // lwl         $v1, 0x267($s1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X267, ctx->r17);
    // lwr         $v1, 0x264($s1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X264, ctx->r17);
    // swl         $v0, 0x17($s2)
    do_swl(rdram, 0X17, ctx->r18, ctx->r2);
    // swr         $v0, 0x14($s2)
    do_swr(rdram, 0X14, ctx->r18, ctx->r2);
    // swl         $v1, 0x1B($s2)
    do_swl(rdram, 0X1B, ctx->r18, ctx->r3);
    // swr         $v1, 0x18($s2)
    do_swr(rdram, 0X18, ctx->r18, ctx->r3);
    // jal         0x80076EA4
    // nop

    ratan2(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(0X10, ctx->r29);
    // nop

    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // nop

    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $v0, 0x20($s2)
    MEM_H(0X20, ctx->r18) = ctx->r2;
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
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
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // bne         $s0, $zero, L_80041320
    if (ctx->r16 != 0) {
        // addu        $v0, $s3, $zero
        ctx->r2 = ADD32(ctx->r19, 0);
        goto L_80041320;
    }
    // addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
L_800412E0:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
L_800412E4:
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
    // j           L_80041598
    // sw          $a0, 0x250($v1)
    MEM_W(0X250, ctx->r3) = ctx->r4;
    goto L_80041598;
    // sw          $a0, 0x250($v1)
    MEM_W(0X250, ctx->r3) = ctx->r4;
L_80041320:
    // slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_80041598
    if (ctx->r2 == 0) {
        // addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80041598;
    }
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // andi        $v0, $s0, 0x1
    ctx->r2 = ctx->r16 & 0X1;
    // beq         $v0, $zero, L_80041344
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_80041344;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // and         $v0, $s0, $v0
    ctx->r2 = ctx->r16 & ctx->r2;
    // beq         $v0, $zero, L_800412E4
    if (ctx->r2 == 0) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_800412E4;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
L_80041344:
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
    // beq         $v0, $zero, L_800413C8
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0x101
        ctx->r3 = ADD32(0, 0X101);
        goto L_800413C8;
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
    // bgez        $v0, L_80041370
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80041370;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80041370:
    // lh          $a0, 0x90($s2)
    ctx->r4 = MEM_HS(0X90, ctx->r18);
    // nop

    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80041390
    if (SIGNED(ctx->r3) >= 0) {
        // sw          $v0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r2;
        goto L_80041390;
    }
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80041390:
    // sra         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3) >> 12;
    // bne         $fp, $zero, L_800412E0
    if (ctx->r30 != 0) {
        // sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_800412E0;
    }
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // jal         0x80076EA4
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    ratan2(rdram, ctx);
    goto after_5;
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    after_5:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sw          $v0, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r2;
    // addiu       $a0, $s4, -0x400
    ctx->r4 = ADD32(ctx->r20, -0X400);
    // jal         0x800744C4
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    rcos(rdram, ctx);
    goto after_6;
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    after_6:
    // j           L_80041520
    // mult        $s5, $v0
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    goto L_80041520;
    // mult        $s5, $v0
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_800413C8:
    // andi        $v0, $s0, 0x8
    ctx->r2 = ctx->r16 & 0X8;
    // beq         $v0, $zero, L_8004144C
    if (ctx->r2 == 0) {
        // andi        $v0, $s0, 0x50
        ctx->r2 = ctx->r16 & 0X50;
        goto L_8004144C;
    }
    // andi        $v0, $s0, 0x50
    ctx->r2 = ctx->r16 & 0X50;
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
    // bgez        $v0, L_800413F4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800413F4;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_800413F4:
    // lh          $a0, 0xA0($s2)
    ctx->r4 = MEM_HS(0XA0, ctx->r18);
    // nop

    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80041414
    if (SIGNED(ctx->r3) >= 0) {
        // sw          $v0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r2;
        goto L_80041414;
    }
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80041414:
    // sra         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3) >> 12;
    // bne         $s6, $zero, L_800412E0
    if (ctx->r22 != 0) {
        // sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_800412E0;
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
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sw          $v0, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r2;
    // addiu       $a0, $s4, -0x400
    ctx->r4 = ADD32(ctx->r20, -0X400);
    // jal         0x800744C4
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    rcos(rdram, ctx);
    goto after_8;
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    after_8:
    // j           L_80041520
    // mult        $s5, $v0
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    goto L_80041520;
    // mult        $s5, $v0
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8004144C:
    // beq         $v0, $zero, L_8004159C
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8004159C;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // jal         0x800492F4
    // addiu       $a0, $s1, 0x248
    ctx->r4 = ADD32(ctx->r17, 0X248);
    sub_800492F4(rdram, ctx);
    goto after_9;
    // addiu       $a0, $s1, 0x248
    ctx->r4 = ADD32(ctx->r17, 0X248);
    after_9:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // lw          $v0, 0x248($s1)
    ctx->r2 = MEM_W(0X248, ctx->r17);
    // lw          $a2, 0xAC($s2)
    ctx->r6 = MEM_W(0XAC, ctx->r18);
    // lw          $v1, 0x250($s1)
    ctx->r3 = MEM_W(0X250, ctx->r17);
    // lw          $a3, 0xB4($s2)
    ctx->r7 = MEM_W(0XB4, ctx->r18);
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // subu        $v1, $v1, $a3
    ctx->r3 = SUB32(ctx->r3, ctx->r7);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // jal         0x800747E0
    // sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    VectorNormalS(rdram, ctx);
    goto after_10;
    // sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_10:
    // lhu         $v1, 0x44C0($s2)
    ctx->r3 = MEM_HU(0X44C0, ctx->r18);
    // lw          $v0, 0xBC($s2)
    ctx->r2 = MEM_W(0XBC, ctx->r18);
    // nop

    // subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
    // andi        $v0, $s0, 0x10
    ctx->r2 = ctx->r16 & 0X10;
    // beq         $v0, $zero, L_800414AC
    if (ctx->r2 == 0) {
        // addiu       $a0, $v1, -0x100
        ctx->r4 = ADD32(ctx->r3, -0X100);
        goto L_800414AC;
    }
    // addiu       $a0, $v1, -0x100
    ctx->r4 = ADD32(ctx->r3, -0X100);
    // addiu       $a0, $v1, -0x300
    ctx->r4 = ADD32(ctx->r3, -0X300);
L_800414AC:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lh          $v1, 0x30($sp)
    ctx->r3 = MEM_HS(0X30, ctx->r29);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_800414CC
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_800414CC;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_800414CC:
    // lh          $v0, 0x34($sp)
    ctx->r2 = MEM_HS(0X34, ctx->r29);
    // nop

    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3) >> 12;
    // mflo        $a0
    ctx->r4 = lo;
    // bgez        $a0, L_800414EC
    if (SIGNED(ctx->r4) >= 0) {
        // sw          $v0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r2;
        goto L_800414EC;
    }
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $a0, $a0, 0xFFF
    ctx->r4 = ADD32(ctx->r4, 0XFFF);
L_800414EC:
    // sra         $v0, $a0, 12
    ctx->r2 = S32(ctx->r4) >> 12;
    // bne         $s7, $zero, L_80041598
    if (ctx->r23 != 0) {
        // sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_80041598;
    }
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(0X28, ctx->r29);
    // lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(0X20, ctx->r29);
    // jal         0x80076EA4
    // addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    ratan2(rdram, ctx);
    goto after_11;
    // addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    after_11:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // addiu       $a0, $s4, -0x400
    ctx->r4 = ADD32(ctx->r20, -0X400);
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    // jal         0x800744C4
    // sw          $s1, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r17;
    rcos(rdram, ctx);
    goto after_12;
    // sw          $s1, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r17;
    after_12:
    // mult        $s5, $v0
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80041520:
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80041534
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $s0, $v0, 12
        ctx->r16 = S32(ctx->r2) >> 12;
        goto L_80041534;
    }
    // sra         $s0, $v0, 12
    ctx->r16 = S32(ctx->r2) >> 12;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
    // sra         $s0, $v0, 12
    ctx->r16 = S32(ctx->r2) >> 12;
L_80041534:
    // beq         $s0, $zero, L_80041224
    if (ctx->r16 == 0) {
        // sh          $s0, 0x44C6($s2)
        MEM_H(0X44C6, ctx->r18) = ctx->r16;
        goto L_80041224;
    }
    // sh          $s0, 0x44C6($s2)
    MEM_H(0X44C6, ctx->r18) = ctx->r16;
    // addiu       $s1, $s1, 0x400
    ctx->r17 = ADD32(ctx->r17, 0X400);
    // jal         0x800744C4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    rcos(rdram, ctx);
    goto after_13;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_13:
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8004155C
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8004155C;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8004155C:
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
    goto after_14;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_14:
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80041584
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80041584;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80041584:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_80041224
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    goto L_80041224;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_80041598:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_8004159C:
    // addiu       $a0, $v0, 0x5948
    ctx->r4 = ADD32(ctx->r2, 0X5948);
    // lh          $v1, 0x47CE($a0)
    ctx->r3 = MEM_HS(0X47CE, ctx->r4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // bgez        $v1, L_800415B4
    if (SIGNED(ctx->r3) >= 0) {
        // addiu       $a3, $v0, -0x70D8
        ctx->r7 = ADD32(ctx->r2, -0X70D8);
        goto L_800415B4;
    }
    // addiu       $a3, $v0, -0x70D8
    ctx->r7 = ADD32(ctx->r2, -0X70D8);
    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_800415B4:
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // lhu         $v0, 0x1CC($a3)
    ctx->r2 = MEM_HU(0X1CC, ctx->r7);
    // lh          $a0, 0x47D2($a0)
    ctx->r4 = MEM_HS(0X47D2, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // bgez        $a0, L_800415D0
    if (SIGNED(ctx->r4) >= 0) {
        // sh          $v0, 0x1CC($a3)
        MEM_H(0X1CC, ctx->r7) = ctx->r2;
        goto L_800415D0;
    }
    // sh          $v0, 0x1CC($a3)
    MEM_H(0X1CC, ctx->r7) = ctx->r2;
    // addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
L_800415D0:
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
    // lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(0X5C, ctx->r29);
    // lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(0X58, ctx->r29);
    // lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(0X54, ctx->r29);
    // lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(0X50, ctx->r29);
    // lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(0X4C, ctx->r29);
    // lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(0X48, ctx->r29);
    // lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(0X44, ctx->r29);
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // jr          $ra
    // nop

    return;
    // nop

;}
