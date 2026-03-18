#include "recomp.h"
#include "disable_warnings.h"

void sub_8003D788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addiu       $s0, $s1, -0x70D8
    ctx->r16 = ADD32(ctx->r17, -0X70D8);
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // lbu         $v1, 0x218($s0)
    ctx->r3 = MEM_BU(0X218, ctx->r16);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_8003DBB0
    if (ctx->r3 == ctx->r2) {
        // addu        $s7, $a2, $zero
        ctx->r23 = ADD32(ctx->r6, 0);
        goto L_8003DBB0;
    }
    // addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // beq         $s5, $zero, L_8003DBB0
    if (ctx->r21 == 0) {
        // nop
    
        goto L_8003DBB0;
    }
    // nop

    // jal         0x8003D288
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_8003D288(rdram, ctx);
    goto after_0;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_0:
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // subu        $s4, $v0, $s5
    ctx->r20 = SUB32(ctx->r2, ctx->r21);
    // bgtz        $s4, L_8003D7F4
    if (SIGNED(ctx->r20) > 0) {
        // nop
    
        goto L_8003D7F4;
    }
    // nop

    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_8003D7F4:
    // sh          $s4, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r20;
    // lhu         $v1, -0x70D8($s1)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r17);
    // andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
    // sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8003D810
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003D810;
    }
    // nop

    // sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
L_8003D810:
    // lhu         $v1, -0x70D8($s1)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r17);
    // sll         $v0, $s5, 12
    ctx->r2 = S32(ctx->r21) << 12;
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8003D828
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8003D828;
    }
    // nop

    // break       7
    do_break(2147735588);
L_8003D828:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8003D840
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003D840;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003D840
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003D840;
    }
    // nop

    // break       6
    do_break(2147735612);
L_8003D840:
    // mflo        $s2
    ctx->r18 = lo;
    // nop

    // slti        $v0, $s2, 0x3B7
    ctx->r2 = SIGNED(ctx->r18) < 0X3B7 ? 1 : 0;
    // bne         $v0, $zero, L_8003D858
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003D858;
    }
    // nop

    // addiu       $s2, $zero, 0x3B6
    ctx->r18 = ADD32(0, 0X3B6);
L_8003D858:
    // beq         $s7, $zero, L_8003D8F4
    if (ctx->r23 == 0) {
        // sra         $s1, $s2, 2
        ctx->r17 = S32(ctx->r18) >> 2;
        goto L_8003D8F4;
    }
    // sra         $s1, $s2, 2
    ctx->r17 = S32(ctx->r18) >> 2;
    // addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // lw          $v0, 0x248($s0)
    ctx->r2 = MEM_W(0X248, ctx->r16);
    // lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(0X0, ctx->r23);
    // lw          $v1, 0x24C($s0)
    ctx->r3 = MEM_W(0X24C, ctx->r16);
    // lw          $a1, 0x4($s7)
    ctx->r5 = MEM_W(0X4, ctx->r23);
    // lw          $a2, 0x8($s7)
    ctx->r6 = MEM_W(0X8, ctx->r23);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lw          $v0, 0x250($s0)
    ctx->r2 = MEM_W(0X250, ctx->r16);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x8004A390
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    sub_8004A390(rdram, ctx);
    goto after_1;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_1:
    // slti        $v0, $s1, 0x50
    ctx->r2 = SIGNED(ctx->r17) < 0X50 ? 1 : 0;
    // beq         $v0, $zero, L_8003D8A0
    if (ctx->r2 == 0) {
        // slti        $v0, $s1, 0x1C3
        ctx->r2 = SIGNED(ctx->r17) < 0X1C3 ? 1 : 0;
        goto L_8003D8A0;
    }
    // slti        $v0, $s1, 0x1C3
    ctx->r2 = SIGNED(ctx->r17) < 0X1C3 ? 1 : 0;
    // addiu       $s1, $zero, 0x50
    ctx->r17 = ADD32(0, 0X50);
    // slti        $v0, $s1, 0x1C3
    ctx->r2 = SIGNED(ctx->r17) < 0X1C3 ? 1 : 0;
L_8003D8A0:
    // bne         $v0, $zero, L_8003D8AC
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_8003D8AC;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $s1, $zero, 0x1C2
    ctx->r17 = ADD32(0, 0X1C2);
L_8003D8AC:
    // addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // jal         0x80049F08
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80049F08(rdram, ctx);
    goto after_2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x8004A0F8
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8004A0F8(rdram, ctx);
    goto after_3;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
    // lh          $v1, 0x1A($sp)
    ctx->r3 = MEM_HS(0X1A, ctx->r29);
    // nop

    // slti        $v0, $v1, 0xC9
    ctx->r2 = SIGNED(ctx->r3) < 0XC9 ? 1 : 0;
    // bne         $v0, $zero, L_8003D8E4
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, -0xC8
        ctx->r2 = SIGNED(ctx->r3) < -0XC8 ? 1 : 0;
        goto L_8003D8E4;
    }
    // slti        $v0, $v1, -0xC8
    ctx->r2 = SIGNED(ctx->r3) < -0XC8 ? 1 : 0;
    // addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // j           L_8003D900
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    goto L_8003D900;
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
L_8003D8E4:
    // beq         $v0, $zero, L_8003D900
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0xC8
        ctx->r2 = ADD32(0, -0XC8);
        goto L_8003D900;
    }
    // addiu       $v0, $zero, -0xC8
    ctx->r2 = ADD32(0, -0XC8);
    // j           L_8003D900
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    goto L_8003D900;
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
L_8003D8F4:
    // sh          $zero, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = 0;
    // sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    // sh          $zero, 0x18($sp)
    MEM_H(0X18, ctx->r29) = 0;
L_8003D900:
    // sra         $v1, $s2, 1
    ctx->r3 = S32(ctx->r18) >> 1;
    // addiu       $v0, $zero, 0x514
    ctx->r2 = ADD32(0, 0X514);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x47
    ctx->r2 = SIGNED(ctx->r2) < 0X47 ? 1 : 0;
    // beq         $v0, $zero, L_8003D92C
    if (ctx->r2 == 0) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_8003D92C;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $s6, $zero, 0x46
    ctx->r22 = ADD32(0, 0X46);
L_8003D92C:
    // addiu       $a0, $v1, -0x70D8
    ctx->r4 = ADD32(ctx->r3, -0X70D8);
    // lhu         $v0, 0x1E($a0)
    ctx->r2 = MEM_HU(0X1E, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8003D9C4
    if (ctx->r2 == 0) {
        // sll         $v0, $s5, 2
        ctx->r2 = S32(ctx->r21) << 2;
        goto L_8003D9C4;
    }
    // sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21) << 2;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lhu         $v1, -0x70D8($v1)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8003D96C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8003D96C;
    }
    // nop

    // break       7
    do_break(2147735912);
L_8003D96C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8003D984
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003D984;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003D984
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003D984;
    }
    // nop

    // break       6
    do_break(2147735936);
L_8003D984:
    // mflo        $v0
    ctx->r2 = lo;
    // lhu         $v1, 0x1E($a0)
    ctx->r3 = MEM_HU(0X1E, ctx->r4);
    // addiu       $v0, $v0, 0x1F4
    ctx->r2 = ADD32(ctx->r2, 0X1F4);
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8003D9A0
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8003D9A0;
    }
    // nop

    // break       7
    do_break(2147735964);
L_8003D9A0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8003D9B8
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003D9B8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003D9B8
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003D9B8;
    }
    // nop

    // break       6
    do_break(2147735988);
L_8003D9B8:
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_8003D9CC
    // sw          $v0, 0x2F4($a0)
    MEM_W(0X2F4, ctx->r4) = ctx->r2;
    goto L_8003D9CC;
    // sw          $v0, 0x2F4($a0)
    MEM_W(0X2F4, ctx->r4) = ctx->r2;
L_8003D9C4:
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // sw          $v0, 0x2F4($a0)
    MEM_W(0X2F4, ctx->r4) = ctx->r2;
L_8003D9CC:
    // lui         $s3, 0x801A
    ctx->r19 = S32(0X801A << 16);
    // addiu       $s1, $s3, -0x70D8
    ctx->r17 = ADD32(ctx->r19, -0X70D8);
    // lw          $v0, 0x2F4($s1)
    ctx->r2 = MEM_W(0X2F4, ctx->r17);
    // nop

    // bgez        $v0, L_8003D9F8
    if (SIGNED(ctx->r2) >= 0) {
        // slti        $v0, $v0, 0x1F
        ctx->r2 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
        goto L_8003D9F8;
    }
    // slti        $v0, $v0, 0x1F
    ctx->r2 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x2F4($s1)
    MEM_W(0X2F4, ctx->r17) = ctx->r2;
    // lw          $v0, 0x2F4($s1)
    ctx->r2 = MEM_W(0X2F4, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x1F
    ctx->r2 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
L_8003D9F8:
    // bne         $v0, $zero, L_8003DA08
    if (ctx->r2 != 0) {
        // sll         $s0, $s5, 8
        ctx->r16 = S32(ctx->r21) << 8;
        goto L_8003DA08;
    }
    // sll         $s0, $s5, 8
    ctx->r16 = S32(ctx->r21) << 8;
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // sw          $v0, 0x2F4($s1)
    MEM_W(0X2F4, ctx->r17) = ctx->r2;
L_8003DA08:
    // lhu         $a0, -0x70D8($s3)
    ctx->r4 = MEM_HU(-0X70D8, ctx->r19);
    // subu        $s0, $s0, $s5
    ctx->r16 = SUB32(ctx->r16, ctx->r21);
    // div         $zero, $s0, $a0
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_8003DA20
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8003DA20;
    }
    // nop

    // break       7
    do_break(2147736092);
L_8003DA20:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_8003DA38
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003DA38;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $s0, $at, L_8003DA38
    if (ctx->r16 != ctx->r1) {
        // nop
    
        goto L_8003DA38;
    }
    // nop

    // break       6
    do_break(2147736116);
L_8003DA38:
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x80057A68
    // nop

    sub_80057A68(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lhu         $v0, -0x70D8($s3)
    ctx->r2 = MEM_HU(-0X70D8, ctx->r19);
    // nop

    // div         $zero, $s0, $v0
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_8003DA5C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003DA5C;
    }
    // nop

    // break       7
    do_break(2147736152);
L_8003DA5C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8003DA74
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003DA74;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $s0, $at, L_8003DA74
    if (ctx->r16 != ctx->r1) {
        // nop
    
        goto L_8003DA74;
    }
    // nop

    // break       6
    do_break(2147736176);
L_8003DA74:
    // mflo        $s0
    ctx->r16 = lo;
    // nop

    // addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // slti        $v0, $s0, 0x81
    ctx->r2 = SIGNED(ctx->r16) < 0X81 ? 1 : 0;
    // bne         $v0, $zero, L_8003DA90
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003DA90;
    }
    // nop

    // addiu       $s0, $zero, 0x80
    ctx->r16 = ADD32(0, 0X80);
L_8003DA90:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // addiu       $v1, $s0, -0x4000
    ctx->r3 = ADD32(ctx->r16, -0X4000);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3) >> 9;
    // jal         0x80078AC4
    // sh          $v1, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_6;
    // sh          $v1, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r3;
    after_6:
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // lhu         $v1, 0x2DE($s1)
    ctx->r3 = MEM_HU(0X2DE, ctx->r17);
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // bne         $s4, $zero, L_8003DAD4
    if (ctx->r20 != 0) {
        // sh          $v1, 0x2DE($s1)
        MEM_H(0X2DE, ctx->r17) = ctx->r3;
        goto L_8003DAD4;
    }
    // sh          $v1, 0x2DE($s1)
    MEM_H(0X2DE, ctx->r17) = ctx->r3;
    // jal         0x8003BD14
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    sub_8003BD14(rdram, ctx);
    goto after_7;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_7:
    // j           L_8003DADC
    // addiu       $v0, $zero, 0xDAC
    ctx->r2 = ADD32(0, 0XDAC);
    goto L_8003DADC;
    // addiu       $v0, $zero, 0xDAC
    ctx->r2 = ADD32(0, 0XDAC);
L_8003DAD4:
    // bne         $s7, $zero, L_8003DAE8
    if (ctx->r23 != 0) {
        // addiu       $v0, $zero, 0xDAC
        ctx->r2 = ADD32(0, 0XDAC);
        goto L_8003DAE8;
    }
    // addiu       $v0, $zero, 0xDAC
    ctx->r2 = ADD32(0, 0XDAC);
L_8003DADC:
    // sh          $v0, 0x2D6($s1)
    MEM_H(0X2D6, ctx->r17) = ctx->r2;
    // j           L_8003DBB0
    // sh          $s6, 0x2D8($s1)
    MEM_H(0X2D8, ctx->r17) = ctx->r22;
    goto L_8003DBB0;
    // sh          $s6, 0x2D8($s1)
    MEM_H(0X2D8, ctx->r17) = ctx->r22;
L_8003DAE8:
    // lh          $v0, 0x12($sp)
    ctx->r2 = MEM_HS(0X12, ctx->r29);
    // lh          $v1, 0x26A($s1)
    ctx->r3 = MEM_HS(0X26A, ctx->r17);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // andi        $v1, $v0, 0x7
    ctx->r3 = ctx->r2 & 0X7;
    // sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_8003DB94
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_8003DB94;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x1D1C
    ctx->r2 = ADD32(ctx->r2, 0X1D1C);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_8003DB24;
    jr_addend_8003DB24 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8003DB24 >> 2) {
        case 0: goto L_8003DB2C; break;
        case 1: goto L_8003DB3C; break;
        case 2: goto L_8003DB4C; break;
        case 3: goto L_8003DB58; break;
        case 4: goto L_8003DB64; break;
        case 5: goto L_8003DB70; break;
        case 6: goto L_8003DB7C; break;
        case 7: goto L_8003DB88; break;
        default: switch_error(__func__, 0x8003DB24, 0x80011D1C);
    }
    // nop

L_8003DB2C:
    // negu        $v0, $s2
    ctx->r2 = SUB32(0, ctx->r18);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // j           L_8003DB94
    // sh          $zero, 0x14($sp)
    MEM_H(0X14, ctx->r29) = 0;
    goto L_8003DB94;
    // sh          $zero, 0x14($sp)
    MEM_H(0X14, ctx->r29) = 0;
L_8003DB3C:
    // negu        $v0, $s2
    ctx->r2 = SUB32(0, ctx->r18);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // j           L_8003DB94
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
    goto L_8003DB94;
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
L_8003DB4C:
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    // j           L_8003DB94
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
    goto L_8003DB94;
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
L_8003DB58:
    // sh          $s2, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r18;
    // j           L_8003DB94
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
    goto L_8003DB94;
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
L_8003DB64:
    // sh          $s2, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r18;
    // j           L_8003DB94
    // sh          $zero, 0x14($sp)
    MEM_H(0X14, ctx->r29) = 0;
    goto L_8003DB94;
    // sh          $zero, 0x14($sp)
    MEM_H(0X14, ctx->r29) = 0;
L_8003DB70:
    // negu        $v0, $s2
    ctx->r2 = SUB32(0, ctx->r18);
    // j           L_8003DB90
    // sh          $s2, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r18;
    goto L_8003DB90;
    // sh          $s2, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r18;
L_8003DB7C:
    // negu        $v0, $s2
    ctx->r2 = SUB32(0, ctx->r18);
    // j           L_8003DB90
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    goto L_8003DB90;
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
L_8003DB88:
    // negu        $v0, $s2
    ctx->r2 = SUB32(0, ctx->r18);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
L_8003DB90:
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
L_8003DB94:
    // sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // sll         $a2, $s6, 16
    ctx->r6 = S32(ctx->r22) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // jal         0x80042C44
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    sub_80042C44(rdram, ctx);
    goto after_8;
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    after_8:
L_8003DBB0:
    // lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(0X40, ctx->r29);
    // lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(0X3C, ctx->r29);
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
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
