#include "recomp.h"
#include "disable_warnings.h"

void sub_800246E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // ori         $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 | 0XF8;
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // ori         $v0, $v0, 0x244
    ctx->r2 = ctx->r2 | 0X244;
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // ori         $a0, $a0, 0xF8
    ctx->r4 = ctx->r4 | 0XF8;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x53
    ctx->r6 = ADD32(0, 0X53);
    // sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // lui         $s4, 0x1F80
    ctx->r20 = S32(0X1F80 << 16);
    // sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r30;
    // sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // sw          $v1, 0xF0($s4)
    MEM_W(0XF0, ctx->r20) = ctx->r3;
    // jal         0x80014D5C
    // sw          $v0, 0xF4($s4)
    MEM_W(0XF4, ctx->r20) = ctx->r2;
    sub_80014D5C(rdram, ctx);
    goto after_0;
    // sw          $v0, 0xF4($s4)
    MEM_W(0XF4, ctx->r20) = ctx->r2;
    after_0:
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // ori         $a0, $a0, 0x244
    ctx->r4 = ctx->r4 | 0X244;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
    sub_80014D5C(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
    after_1:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a0, $v0, 0x310
    ctx->r4 = ADD32(ctx->r2, 0X310);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lbu         $fp, 0x7274($a0)
    ctx->r30 = MEM_BU(0X7274, ctx->r4);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sh          $zero, 0x98($s4)
    MEM_H(0X98, ctx->r20) = 0;
    // lw          $s6, -0x7DFC($v0)
    ctx->r22 = MEM_W(-0X7DFC, ctx->r2);
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // beq         $fp, $v1, L_80025168
    if (ctx->r30 == ctx->r3) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80025168;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addu        $s7, $v1, $zero
    ctx->r23 = ADD32(ctx->r3, 0);
    // sll         $v0, $fp, 1
    ctx->r2 = S32(ctx->r30) << 1;
L_80024784:
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // addiu       $t0, $t0, 0x310
    ctx->r8 = ADD32(ctx->r8, 0X310);
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // lhu         $v1, 0x71B4($v0)
    ctx->r3 = MEM_HU(0X71B4, ctx->r2);
    // addiu       $t0, $t0, 0x2230
    ctx->r8 = ADD32(ctx->r8, 0X2230);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $s0, $v0, $t0
    ctx->r16 = ADD32(ctx->r2, ctx->r8);
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_80025158
    if (ctx->r3 == ctx->r2) {
        // sb          $zero, 0x7($s0)
        MEM_B(0X7, ctx->r16) = 0;
        goto L_80025158;
    }
    // sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // addiu       $t0, $t0, -0x2F70
    ctx->r8 = ADD32(ctx->r8, -0X2F70);
    // lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(0X3, ctx->r16);
    // addu        $a1, $t0, $v1
    ctx->r5 = ADD32(ctx->r8, ctx->r3);
    // andi        $a0, $v0, 0x3F
    ctx->r4 = ctx->r2 & 0X3F;
    // sb          $a0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r4;
    // lw          $v0, 0x6E04($a1)
    ctx->r2 = MEM_W(0X6E04, ctx->r5);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(0X18, ctx->r16);
    // mflo        $t0
    ctx->r8 = lo;
    // sltu        $v0, $t0, $v1
    ctx->r2 = ctx->r8 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_80024820
    if (ctx->r2 == 0) {
        // ori         $v0, $a0, 0x40
        ctx->r2 = ctx->r4 | 0X40;
        goto L_80024820;
    }
    // ori         $v0, $a0, 0x40
    ctx->r2 = ctx->r4 | 0X40;
    // lw          $v0, 0x6E00($a1)
    ctx->r2 = MEM_W(0X6E00, ctx->r5);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t0
    ctx->r8 = lo;
    // sltu        $v0, $v1, $t0
    ctx->r2 = ctx->r3 < ctx->r8 ? 1 : 0;
    // bne         $v0, $zero, L_80024824
    if (ctx->r2 != 0) {
        // ori         $v0, $a0, 0x80
        ctx->r2 = ctx->r4 | 0X80;
        goto L_80024824;
    }
    // ori         $v0, $a0, 0x80
    ctx->r2 = ctx->r4 | 0X80;
L_80024820:
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
L_80024824:
    // lbu         $v1, 0x5($s0)
    ctx->r3 = MEM_BU(0X5, ctx->r16);
    // addiu       $v0, $zero, 0xE2
    ctx->r2 = ADD32(0, 0XE2);
    // beq         $v1, $v0, L_80025158
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0xE3
        ctx->r2 = SIGNED(ctx->r3) < 0XE3 ? 1 : 0;
        goto L_80025158;
    }
    // slti        $v0, $v1, 0xE3
    ctx->r2 = SIGNED(ctx->r3) < 0XE3 ? 1 : 0;
    // beq         $v0, $zero, L_80024870
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x25
        ctx->r2 = ADD32(0, 0X25);
        goto L_80024870;
    }
    // addiu       $v0, $zero, 0x25
    ctx->r2 = ADD32(0, 0X25);
    // beq         $v1, $v0, L_80025158
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x26
        ctx->r2 = SIGNED(ctx->r3) < 0X26 ? 1 : 0;
        goto L_80025158;
    }
    // slti        $v0, $v1, 0x26
    ctx->r2 = SIGNED(ctx->r3) < 0X26 ? 1 : 0;
    // beq         $v0, $zero, L_8002485C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1F
        ctx->r2 = ADD32(0, 0X1F);
        goto L_8002485C;
    }
    // addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // beq         $v1, $v0, L_800248A8
    if (ctx->r3 == ctx->r2) {
        // addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
        goto L_800248A8;
    }
    // addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // j           L_80024E2C
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    goto L_80024E2C;
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
L_8002485C:
    // addiu       $v0, $zero, 0x26
    ctx->r2 = ADD32(0, 0X26);
    // beq         $v1, $v0, L_80024D44
    if (ctx->r3 == ctx->r2) {
        // addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
        goto L_80024D44;
    }
    // addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // j           L_80024E2C
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    goto L_80024E2C;
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
L_80024870:
    // addiu       $v0, $zero, 0xE9
    ctx->r2 = ADD32(0, 0XE9);
    // beq         $v1, $v0, L_80025158
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0xEA
        ctx->r2 = SIGNED(ctx->r3) < 0XEA ? 1 : 0;
        goto L_80025158;
    }
    // slti        $v0, $v1, 0xEA
    ctx->r2 = SIGNED(ctx->r3) < 0XEA ? 1 : 0;
    // beq         $v0, $zero, L_80024894
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xE5
        ctx->r2 = ADD32(0, 0XE5);
        goto L_80024894;
    }
    // addiu       $v0, $zero, 0xE5
    ctx->r2 = ADD32(0, 0XE5);
    // beq         $v1, $v0, L_80025158
    if (ctx->r3 == ctx->r2) {
        // addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
        goto L_80025158;
    }
    // addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // j           L_80024E2C
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    goto L_80024E2C;
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
L_80024894:
    // addiu       $v0, $zero, 0xEC
    ctx->r2 = ADD32(0, 0XEC);
    // beq         $v1, $v0, L_80024B18
    if (ctx->r3 == ctx->r2) {
        // addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
        goto L_80024B18;
    }
    // addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // j           L_80024E2C
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    goto L_80024E2C;
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
L_800248A8:
    // lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(0X24, ctx->r16);
    // lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(0X2C, ctx->r16);
    // lbu         $a2, 0x48($s0)
    ctx->r6 = MEM_BU(0X48, ctx->r16);
    // lbu         $a3, 0x49($s0)
    ctx->r7 = MEM_BU(0X49, ctx->r16);
    // ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // sra         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4) >> 12;
    // jal         0x8004FC94
    // sra         $a1, $a1, 12
    ctx->r5 = S32(ctx->r5) >> 12;
    sub_8004FC94(rdram, ctx);
    goto after_2;
    // sra         $a1, $a1, 12
    ctx->r5 = S32(ctx->r5) >> 12;
    after_2:
    // beq         $v0, $zero, L_80024AEC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80024AEC;
    }
    // nop

    // lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(0X50, ctx->r16);
    // nop

    // subu        $v0, $v0, $s6
    ctx->r2 = SUB32(ctx->r2, ctx->r22);
    // bgez        $v0, L_80025158
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80025158;
    }
    // nop

    // lbu         $v0, 0x4D($s0)
    ctx->r2 = MEM_BU(0X4D, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // beq         $v0, $zero, L_80024924
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80024924;
    }
    // nop

    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lhu         $v1, 0x4E($s0)
    ctx->r3 = MEM_HU(0X4E, ctx->r16);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3) << 1;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $a0, $s6, $a0
    ctx->r4 = ADD32(ctx->r22, ctx->r4);
    // sw          $a0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r4;
L_80024924:
    // lbu         $v0, 0x4D($s0)
    ctx->r2 = MEM_BU(0X4D, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // beq         $v0, $zero, L_80024964
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80024964;
    }
    // nop

    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lhu         $v1, 0x4E($s0)
    ctx->r3 = MEM_HU(0X4E, ctx->r16);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3) << 1;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $a0, $s6, $a0
    ctx->r4 = ADD32(ctx->r22, ctx->r4);
    // j           L_80024980
    // sw          $a0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r4;
    goto L_80024980;
    // sw          $a0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r4;
L_80024964:
    // lhu         $v1, 0x4E($s0)
    ctx->r3 = MEM_HU(0X4E, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
L_80024980:
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // lbu         $v0, 0x48($s0)
    ctx->r2 = MEM_BU(0X48, ctx->r16);
    // addiu       $t0, $t0, -0x70D8
    ctx->r8 = ADD32(ctx->r8, -0X70D8);
    // sll         $a1, $v0, 11
    ctx->r5 = S32(ctx->r2) << 11;
    // lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(0X24, ctx->r16);
    // lw          $v1, 0x248($t0)
    ctx->r3 = MEM_W(0X248, ctx->r8);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    // bgez        $a0, L_800249AC
    if (SIGNED(ctx->r4) >= 0) {
        // nop
    
        goto L_800249AC;
    }
    // nop

    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_800249AC:
    // subu        $a0, $a1, $a0
    ctx->r4 = SUB32(ctx->r5, ctx->r4);
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // lbu         $v0, 0x49($s0)
    ctx->r2 = MEM_BU(0X49, ctx->r16);
    // addiu       $t0, $t0, -0x70D8
    ctx->r8 = ADD32(ctx->r8, -0X70D8);
    // sll         $a1, $v0, 11
    ctx->r5 = S32(ctx->r2) << 11;
    // lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(0X2C, ctx->r16);
    // lw          $v1, 0x250($t0)
    ctx->r3 = MEM_W(0X250, ctx->r8);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // bgez        $v1, L_800249DC
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_800249DC;
    }
    // nop

    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_800249DC:
    // subu        $v1, $a1, $v1
    ctx->r3 = SUB32(ctx->r5, ctx->r3);
    // slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_800249F0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800249F0;
    }
    // nop

    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_800249F0:
    // lbu         $v0, 0x4C($s0)
    ctx->r2 = MEM_BU(0X4C, ctx->r16);
    // nop

    // sll         $s1, $v0, 12
    ctx->r17 = S32(ctx->r2) << 12;
    // slt         $v0, $a0, $s1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r17) ? 1 : 0;
    // bne         $v0, $zero, L_80024A14
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80024A14;
    }
    // nop

    // lbu         $s1, 0x4B($s0)
    ctx->r17 = MEM_BU(0X4B, ctx->r16);
    // j           L_80024A60
    // nop

    goto L_80024A60;
    // nop

L_80024A14:
    // beq         $s1, $zero, L_80025158
    if (ctx->r17 == 0) {
        // nop
    
        goto L_80025158;
    }
    // nop

    // lbu         $v0, 0x4B($s0)
    ctx->r2 = MEM_BU(0X4B, ctx->r16);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // div         $zero, $v0, $s1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r17)));
    // bne         $s1, $zero, L_80024A44
    if (ctx->r17 != 0) {
        // nop
    
        goto L_80024A44;
    }
    // nop

    // break       7
    do_break(2147633728);
L_80024A44:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s1, $at, L_80024A5C
    if (ctx->r17 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80024A5C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80024A5C
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80024A5C;
    }
    // nop

    // break       6
    do_break(2147633752);
L_80024A5C:
    // mflo        $s1
    ctx->r17 = lo;
L_80024A60:
    // lbu         $v0, 0x4D($s0)
    ctx->r2 = MEM_BU(0X4D, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80024AB4
    if (ctx->r2 == 0) {
        // slti        $v0, $s1, 0x14
        ctx->r2 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
        goto L_80024AB4;
    }
    // slti        $v0, $s1, 0x14
    ctx->r2 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // addiu       $t0, $t0, -0x70D8
    ctx->r8 = ADD32(ctx->r8, -0X70D8);
    // lw          $v1, 0x24C($t0)
    ctx->r3 = MEM_W(0X24C, ctx->r8);
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // nop

    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // bgez        $v1, L_80024A98
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80024A98;
    }
    // nop

    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_80024A98:
    // lbu         $v0, 0x4B($s0)
    ctx->r2 = MEM_BU(0X4B, ctx->r16);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t0
    ctx->r8 = lo;
    // sra         $v1, $t0, 13
    ctx->r3 = S32(ctx->r8) >> 13;
    // subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // slti        $v0, $s1, 0x14
    ctx->r2 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
L_80024AB4:
    // bne         $v0, $zero, L_80025158
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80025158;
    }
    // nop

    // lh          $a0, 0x54($s0)
    ctx->r4 = MEM_HS(0X54, ctx->r16);
    // nop

    // beq         $a0, $s7, L_80024ADC
    if (ctx->r4 == ctx->r23) {
        // nop
    
        goto L_80024ADC;
    }
    // nop

    // lbu         $a1, 0x4A($s0)
    ctx->r5 = MEM_BU(0X4A, ctx->r16);
    // jal         0x8005850C
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    sub_8005850C(rdram, ctx);
    goto after_5;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    after_5:
    // sh          $s7, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r23;
L_80024ADC:
    // lbu         $a0, 0x4A($s0)
    ctx->r4 = MEM_BU(0X4A, ctx->r16);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // j           L_80024CF8
    // addiu       $a0, $a0, 0xD0
    ctx->r4 = ADD32(ctx->r4, 0XD0);
    goto L_80024CF8;
    // addiu       $a0, $a0, 0xD0
    ctx->r4 = ADD32(ctx->r4, 0XD0);
L_80024AEC:
    // lhu         $v1, 0x4E($s0)
    ctx->r3 = MEM_HU(0X4E, ctx->r16);
    // lh          $a0, 0x54($s0)
    ctx->r4 = MEM_HS(0X54, ctx->r16);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // beq         $a0, $s7, L_80025158
    if (ctx->r4 == ctx->r23) {
        // sw          $v0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->r2;
        goto L_80025158;
    }
    // sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // lbu         $a1, 0x4A($s0)
    ctx->r5 = MEM_BU(0X4A, ctx->r16);
    // j           L_80024D34
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    goto L_80024D34;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
L_80024B18:
    // lbu         $a2, 0x48($s0)
    ctx->r6 = MEM_BU(0X48, ctx->r16);
    // lbu         $a3, 0x49($s0)
    ctx->r7 = MEM_BU(0X49, ctx->r16);
    // ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(0X24, ctx->r16);
    // lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(0X2C, ctx->r16);
    // sll         $a2, $a2, 8
    ctx->r6 = S32(ctx->r6) << 8;
    // jal         0x8004FD28
    // sll         $a3, $a3, 8
    ctx->r7 = S32(ctx->r7) << 8;
    sub_8004FD28(rdram, ctx);
    goto after_6;
    // sll         $a3, $a3, 8
    ctx->r7 = S32(ctx->r7) << 8;
    after_6:
    // beq         $v0, $zero, L_80024D08
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80024D08;
    }
    // nop

    // lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(0X50, ctx->r16);
    // nop

    // subu        $v0, $v0, $s6
    ctx->r2 = SUB32(ctx->r2, ctx->r22);
    // bgez        $v0, L_80025158
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80025158;
    }
    // nop

    // lbu         $v0, 0x4D($s0)
    ctx->r2 = MEM_BU(0X4D, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // beq         $v0, $zero, L_80024B94
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80024B94;
    }
    // nop

    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lhu         $v1, 0x4E($s0)
    ctx->r3 = MEM_HU(0X4E, ctx->r16);
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3) << 4;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $a0, $s6, $a0
    ctx->r4 = ADD32(ctx->r22, ctx->r4);
    // sw          $a0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r4;
L_80024B94:
    // lbu         $v0, 0x4D($s0)
    ctx->r2 = MEM_BU(0X4D, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // beq         $v0, $zero, L_80024BD4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80024BD4;
    }
    // nop

    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lhu         $v1, 0x4E($s0)
    ctx->r3 = MEM_HU(0X4E, ctx->r16);
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3) << 4;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $a0, $s6, $a0
    ctx->r4 = ADD32(ctx->r22, ctx->r4);
    // j           L_80024BF0
    // sw          $a0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r4;
    goto L_80024BF0;
    // sw          $a0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r4;
L_80024BD4:
    // lhu         $v1, 0x4E($s0)
    ctx->r3 = MEM_HU(0X4E, ctx->r16);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
L_80024BF0:
    // lbu         $v0, 0x48($s0)
    ctx->r2 = MEM_BU(0X48, ctx->r16);
    // lbu         $v1, 0x4C($s0)
    ctx->r3 = MEM_BU(0X4C, ctx->r16);
    // lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(0X1C, ctx->r16);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // sll         $v1, $v1, 7
    ctx->r3 = S32(ctx->r3) << 7;
    // subu        $a0, $a1, $v1
    ctx->r4 = SUB32(ctx->r5, ctx->r3);
    // slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_80024C6C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80024C6C;
    }
    // nop

    // beq         $a1, $a0, L_80024C6C
    if (ctx->r5 == ctx->r4) {
        // subu        $v0, $a1, $a2
        ctx->r2 = SUB32(ctx->r5, ctx->r6);
        goto L_80024C6C;
    }
    // subu        $v0, $a1, $a2
    ctx->r2 = SUB32(ctx->r5, ctx->r6);
    // lbu         $v1, 0x4B($s0)
    ctx->r3 = MEM_BU(0X4B, ctx->r16);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // subu        $v0, $a1, $a0
    ctx->r2 = SUB32(ctx->r5, ctx->r4);
    // nop

    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80024C48
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80024C48;
    }
    // nop

    // break       7
    do_break(2147634244);
L_80024C48:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80024C60
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80024C60;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80024C60
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80024C60;
    }
    // nop

    // break       6
    do_break(2147634268);
L_80024C60:
    // mflo        $s1
    ctx->r17 = lo;
    // j           L_80024C70
    // nop

    goto L_80024C70;
    // nop

L_80024C6C:
    // lbu         $s1, 0x4B($s0)
    ctx->r17 = MEM_BU(0X4B, ctx->r16);
L_80024C70:
    // lbu         $v0, 0x4D($s0)
    ctx->r2 = MEM_BU(0X4D, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80024CC4
    if (ctx->r2 == 0) {
        // slti        $v0, $s1, 0x14
        ctx->r2 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
        goto L_80024CC4;
    }
    // slti        $v0, $s1, 0x14
    ctx->r2 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // addiu       $t0, $t0, -0x70D8
    ctx->r8 = ADD32(ctx->r8, -0X70D8);
    // lw          $v1, 0x24C($t0)
    ctx->r3 = MEM_W(0X24C, ctx->r8);
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // nop

    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // bgez        $v1, L_80024CA8
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80024CA8;
    }
    // nop

    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_80024CA8:
    // lbu         $v0, 0x4B($s0)
    ctx->r2 = MEM_BU(0X4B, ctx->r16);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t0
    ctx->r8 = lo;
    // sra         $v1, $t0, 13
    ctx->r3 = S32(ctx->r8) >> 13;
    // subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // slti        $v0, $s1, 0x14
    ctx->r2 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
L_80024CC4:
    // bne         $v0, $zero, L_80025158
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80025158;
    }
    // nop

    // lh          $a0, 0x54($s0)
    ctx->r4 = MEM_HS(0X54, ctx->r16);
    // nop

    // beq         $a0, $s7, L_80024CEC
    if (ctx->r4 == ctx->r23) {
        // nop
    
        goto L_80024CEC;
    }
    // nop

    // lbu         $a1, 0x4A($s0)
    ctx->r5 = MEM_BU(0X4A, ctx->r16);
    // jal         0x8005850C
    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
    sub_8005850C(rdram, ctx);
    goto after_9;
    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
    after_9:
    // sh          $s7, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r23;
L_80024CEC:
    // lbu         $a0, 0x4A($s0)
    ctx->r4 = MEM_BU(0X4A, ctx->r16);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $a0, $a0, 0x454
    ctx->r4 = ADD32(ctx->r4, 0X454);
L_80024CF8:
    // jal         0x800582F0
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    sub_800582F0(rdram, ctx);
    goto after_10;
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    after_10:
    // j           L_8002515C
    // sh          $v0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r2;
    goto L_8002515C;
    // sh          $v0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r2;
L_80024D08:
    // lhu         $v1, 0x4E($s0)
    ctx->r3 = MEM_HU(0X4E, ctx->r16);
    // lh          $a0, 0x54($s0)
    ctx->r4 = MEM_HS(0X54, ctx->r16);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // beq         $a0, $s7, L_80025158
    if (ctx->r4 == ctx->r23) {
        // sw          $v0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->r2;
        goto L_80025158;
    }
    // sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // lbu         $a1, 0x4A($s0)
    ctx->r5 = MEM_BU(0X4A, ctx->r16);
    // nop

    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
L_80024D34:
    // jal         0x8005850C
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    sub_8005850C(rdram, ctx);
    goto after_11;
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    after_11:
    // j           L_8002515C
    // sh          $s7, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r23;
    goto L_8002515C;
    // sh          $s7, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r23;
L_80024D44:
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // sb          $v1, 0xF8($v0)
    MEM_B(0XF8, ctx->r2) = ctx->r3;
    // lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(0XA, ctx->r16);
    // jal         0x80023208
    // addiu       $s1, $s0, 0x3C
    ctx->r17 = ADD32(ctx->r16, 0X3C);
    sub_80023208(rdram, ctx);
    goto after_12;
    // addiu       $s1, $s0, 0x3C
    ctx->r17 = ADD32(ctx->r16, 0X3C);
    after_12:
    // andi        $s2, $v0, 0xFFFF
    ctx->r18 = ctx->r2 & 0XFFFF;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x80033DB8
    // addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    sub_80033DB8(rdram, ctx);
    goto after_13;
    // addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_13:
    // lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(0X48, ctx->r29);
    // nop

    // beq         $v0, $zero, L_80025158
    if (ctx->r2 == 0) {
        // lui         $t0, 0x8016
        ctx->r8 = S32(0X8016 << 16);
        goto L_80025158;
    }
    // lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // lhu         $v0, 0x34($s0)
    ctx->r2 = MEM_HU(0X34, ctx->r16);
    // nop

    // sh          $v0, 0xD8($s4)
    MEM_H(0XD8, ctx->r20) = ctx->r2;
    // lhu         $v0, 0x36($s0)
    ctx->r2 = MEM_HU(0X36, ctx->r16);
    // nop

    // sh          $v0, 0xDA($s4)
    MEM_H(0XDA, ctx->r20) = ctx->r2;
    // lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(0X38, ctx->r16);
    // addiu       $t0, $t0, 0x5090
    ctx->r8 = ADD32(ctx->r8, 0X5090);
    // sh          $v0, 0xDC($s4)
    MEM_H(0XDC, ctx->r20) = ctx->r2;
    // lh          $v0, 0x14($s0)
    ctx->r2 = MEM_HS(0X14, ctx->r16);
    // lw          $v1, 0xE4($t0)
    ctx->r3 = MEM_W(0XE4, ctx->r8);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r3;
    // lh          $v1, 0x14($s0)
    ctx->r3 = MEM_HS(0X14, ctx->r16);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x80($s4)
    MEM_W(0X80, ctx->r20) = ctx->r2;
    // lh          $v1, 0x14($s0)
    ctx->r3 = MEM_HS(0X14, ctx->r16);
    // addiu       $v0, $s0, 0x44
    ctx->r2 = ADD32(ctx->r16, 0X44);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x4288
    ctx->r2 = ADD32(ctx->r2, -0X4288);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(0X2, ctx->r16);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(0X10, ctx->r16);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lh          $v0, 0x16($s0)
    ctx->r2 = MEM_HS(0X16, ctx->r16);
    // addiu       $a2, $s0, 0x24
    ctx->r6 = ADD32(ctx->r16, 0X24);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(0X3, ctx->r16);
    // addiu       $a3, $s4, 0xD8
    ctx->r7 = ADD32(ctx->r20, 0XD8);
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // j           L_80025150
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    goto L_80025150;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80024E2C:
    // lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(0XA, ctx->r16);
    // addiu       $t0, $t0, 0x310
    ctx->r8 = ADD32(ctx->r8, 0X310);
    // addu        $v0, $s4, $v1
    ctx->r2 = ADD32(ctx->r20, ctx->r3);
    // sb          $s5, 0xF8($v0)
    MEM_B(0XF8, ctx->r2) = ctx->r21;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(0XA, ctx->r16);
    // jal         0x80023208
    // addu        $s2, $v0, $t0
    ctx->r18 = ADD32(ctx->r2, ctx->r8);
    sub_80023208(rdram, ctx);
    goto after_14;
    // addu        $s2, $v0, $t0
    ctx->r18 = ADD32(ctx->r2, ctx->r8);
    after_14:
    // andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80033DB8
    // addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    sub_80033DB8(rdram, ctx);
    goto after_15;
    // addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_15:
    // lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(0X48, ctx->r29);
    // nop

    // beq         $v0, $zero, L_80025158
    if (ctx->r2 == 0) {
        // addiu       $s1, $s0, 0x3C
        ctx->r17 = ADD32(ctx->r16, 0X3C);
        goto L_80025158;
    }
    // addiu       $s1, $s0, 0x3C
    ctx->r17 = ADD32(ctx->r16, 0X3C);
    // lhu         $v0, 0x34($s0)
    ctx->r2 = MEM_HU(0X34, ctx->r16);
    // nop

    // sh          $v0, 0xD8($s4)
    MEM_H(0XD8, ctx->r20) = ctx->r2;
    // lhu         $v0, 0x36($s0)
    ctx->r2 = MEM_HU(0X36, ctx->r16);
    // nop

    // sh          $v0, 0xDA($s4)
    MEM_H(0XDA, ctx->r20) = ctx->r2;
    // lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(0X38, ctx->r16);
    // nop

    // sh          $v0, 0xDC($s4)
    MEM_H(0XDC, ctx->r20) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_80024F54
    if (ctx->r2 == 0) {
        // lui         $t0, 0x8016
        ctx->r8 = S32(0X8016 << 16);
        goto L_80024F54;
    }
    // lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // lhu         $v0, 0x34($s0)
    ctx->r2 = MEM_HU(0X34, ctx->r16);
    // sh          $zero, 0xDA($s4)
    MEM_H(0XDA, ctx->r20) = 0;
    // sh          $v0, 0xD8($s4)
    MEM_H(0XD8, ctx->r20) = ctx->r2;
    // lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(0X38, ctx->r16);
    // addiu       $t0, $t0, 0x5090
    ctx->r8 = ADD32(ctx->r8, 0X5090);
    // sh          $v0, 0xDC($s4)
    MEM_H(0XDC, ctx->r20) = ctx->r2;
    // lh          $v0, 0x14($s0)
    ctx->r2 = MEM_HS(0X14, ctx->r16);
    // lw          $v1, 0xE4($t0)
    ctx->r3 = MEM_W(0XE4, ctx->r8);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r3;
    // lh          $v1, 0x14($s0)
    ctx->r3 = MEM_HS(0X14, ctx->r16);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x80($s4)
    MEM_W(0X80, ctx->r20) = ctx->r2;
    // lh          $v1, 0x14($s0)
    ctx->r3 = MEM_HS(0X14, ctx->r16);
    // addiu       $v0, $s0, 0x44
    ctx->r2 = ADD32(ctx->r16, 0X44);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x41C8
    ctx->r2 = ADD32(ctx->r2, -0X41C8);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(0X2, ctx->r16);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(0X10, ctx->r16);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lh          $v0, 0x16($s0)
    ctx->r2 = MEM_HS(0X16, ctx->r16);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lh          $v0, 0x16($s0)
    ctx->r2 = MEM_HS(0X16, ctx->r16);
    // addiu       $a2, $s0, 0x24
    ctx->r6 = ADD32(ctx->r16, 0X24);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(0X3, ctx->r16);
    // addiu       $a3, $s4, 0xD8
    ctx->r7 = ADD32(ctx->r20, 0XD8);
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // j           L_80025150
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    goto L_80025150;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80024F54:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F04
    ctx->r6 = ADD32(ctx->r2, 0X7F04);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x63($sp)
    do_swl(rdram, 0X63, ctx->r29, ctx->r3);
    // swr         $v1, 0x60($sp)
    do_swr(rdram, 0X60, ctx->r29, ctx->r3);
    // swl         $a0, 0x67($sp)
    do_swl(rdram, 0X67, ctx->r29, ctx->r4);
    // swr         $a0, 0x64($sp)
    do_swr(rdram, 0X64, ctx->r29, ctx->r4);
    // lh          $v0, 0x14($s0)
    ctx->r2 = MEM_HS(0X14, ctx->r16);
    // addiu       $t0, $t0, 0x5090
    ctx->r8 = ADD32(ctx->r8, 0X5090);
    // sb          $s5, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r21;
    // lw          $v1, 0xE4($t0)
    ctx->r3 = MEM_W(0XE4, ctx->r8);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r3;
    // lh          $v1, 0x14($s0)
    ctx->r3 = MEM_HS(0X14, ctx->r16);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x80($s4)
    MEM_W(0X80, ctx->r20) = ctx->r2;
    // lh          $v1, 0x14($s0)
    ctx->r3 = MEM_HS(0X14, ctx->r16);
    // addiu       $v0, $s0, 0x44
    ctx->r2 = ADD32(ctx->r16, 0X44);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x4288
    ctx->r2 = ADD32(ctx->r2, -0X4288);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(0X2, ctx->r16);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(0X10, ctx->r16);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lh          $v0, 0x16($s0)
    ctx->r2 = MEM_HS(0X16, ctx->r16);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lh          $v0, 0x16($s0)
    ctx->r2 = MEM_HS(0X16, ctx->r16);
    // addiu       $a2, $s0, 0x24
    ctx->r6 = ADD32(ctx->r16, 0X24);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(0X3, ctx->r16);
    // addiu       $a3, $s4, 0xD8
    ctx->r7 = ADD32(ctx->r20, 0XD8);
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // jal         0x80022678
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    sub_80022678(rdram, ctx);
    goto after_16;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_16:
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80025158
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80025158;
    }
    // nop

    // lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(0X24, ctx->r16);
    // lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(0X28, ctx->r16);
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(0X30, ctx->r16);
    // sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // beq         $v0, $zero, L_80025080
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80025080;
    }
    // nop

    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r3;
    // lhu         $v0, 0xE($s2)
    ctx->r2 = MEM_HU(0XE, ctx->r18);
    // j           L_800250A4
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    goto L_800250A4;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
L_80025080:
    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
    // nop

    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r3;
    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
    // nop

    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
L_800250A4:
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // addiu       $a3, $s4, 0xD8
    ctx->r7 = ADD32(ctx->r20, 0XD8);
    // lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // addiu       $t0, $t0, 0x5090
    ctx->r8 = ADD32(ctx->r8, 0X5090);
    // lh          $v1, 0x14($s0)
    ctx->r3 = MEM_HS(0X14, ctx->r16);
    // lw          $v0, 0xE4($t0)
    ctx->r2 = MEM_W(0XE4, ctx->r8);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, -0x14
    ctx->r2 = ADD32(ctx->r2, -0X14);
    // sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // lh          $v1, 0x14($s0)
    ctx->r3 = MEM_HS(0X14, ctx->r16);
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x80($s4)
    MEM_W(0X80, ctx->r20) = ctx->r2;
    // lh          $v1, 0x14($s0)
    ctx->r3 = MEM_HS(0X14, ctx->r16);
    // addiu       $v0, $zero, 0x1005
    ctx->r2 = ADD32(0, 0X1005);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // lbu         $a1, 0x3($s2)
    ctx->r5 = MEM_BU(0X3, ctx->r18);
    // addiu       $v0, $sp, 0x60
    ctx->r2 = ADD32(ctx->r29, 0X60);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $s0, 0x44
    ctx->r2 = ADD32(ctx->r16, 0X44);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x4288
    ctx->r2 = ADD32(ctx->r2, -0X4288);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // lh          $v1, 0x16($s0)
    ctx->r3 = MEM_HS(0X16, ctx->r16);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // srl         $a1, $a1, 2
    ctx->r5 = S32(U32(ctx->r5) >> 2);
    // andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    // ori         $a1, $a1, 0x2C
    ctx->r5 = ctx->r5 | 0X2C;
    // sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_80025150:
    // jal         0x80022678
    // nop

    sub_80022678(rdram, ctx);
    goto after_17;
    // nop

    after_17:
L_80025158:
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
L_8002515C:
    // bne         $fp, $s7, L_80024784
    if (ctx->r30 != ctx->r23) {
        // sll         $v0, $fp, 1
        ctx->r2 = S32(ctx->r30) << 1;
        goto L_80024784;
    }
    // sll         $v0, $fp, 1
    ctx->r2 = S32(ctx->r30) << 1;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80025168:
    // lbu         $v0, 0x593F($v0)
    ctx->r2 = MEM_BU(0X593F, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80025190
    if (ctx->r2 != 0) {
        // addiu       $v0, $s4, 0x224
        ctx->r2 = ADD32(ctx->r20, 0X224);
        goto L_80025190;
    }
    // addiu       $v0, $s4, 0x224
    ctx->r2 = ADD32(ctx->r20, 0X224);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    // jal         0x80024004
    // addiu       $a3, $zero, 0xF9
    ctx->r7 = ADD32(0, 0XF9);
    sub_80024004(rdram, ctx);
    goto after_18;
    // addiu       $a3, $zero, 0xF9
    ctx->r7 = ADD32(0, 0XF9);
    after_18:
    // addiu       $v0, $s4, 0x224
    ctx->r2 = ADD32(ctx->r20, 0X224);
L_80025190:
    // sw          $v0, 0xF0($s4)
    MEM_W(0XF0, ctx->r20) = ctx->r2;
    // lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(0X8C, ctx->r29);
    // lw          $fp, 0x88($sp)
    ctx->r30 = MEM_W(0X88, ctx->r29);
    // lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(0X84, ctx->r29);
    // lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(0X80, ctx->r29);
    // lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(0X7C, ctx->r29);
    // lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(0X78, ctx->r29);
    // lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(0X74, ctx->r29);
    // lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(0X70, ctx->r29);
    // lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(0X6C, ctx->r29);
    // lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(0X68, ctx->r29);
    // addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // jr          $ra
    // nop

    return;
    // nop

;}
