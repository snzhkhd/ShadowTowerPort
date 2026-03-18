#include "recomp.h"
#include "disable_warnings.h"

void _SsGetSeqData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2) >> 16;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addiu       $v0, $v0, -0x79A0
    ctx->r2 = ADD32(ctx->r2, -0X79A0);
    // sll         $a2, $t1, 2
    ctx->r6 = S32(ctx->r9) << 2;
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2) >> 16;
    // sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8) << 1;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // nop

    // addu        $s3, $v1, $v0
    ctx->r19 = ADD32(ctx->r3, ctx->r2);
    // lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(0X0, ctx->r19);
    // nop

    // lbu         $s2, 0x0($a3)
    ctx->r18 = MEM_BU(0X0, ctx->r7);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // sw          $a3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r7;
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(0X98, ctx->r2);
    // addiu       $v1, $zero, 0x401
    ctx->r3 = ADD32(0, 0X401);
    // andi        $v0, $v0, 0x401
    ctx->r2 = ctx->r2 & 0X401;
    // bne         $v0, $v1, L_8006E194
    if (ctx->r2 != ctx->r3) {
        // addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
        goto L_8006E194;
    }
    // addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // lw          $v1, 0x10($s3)
    ctx->r3 = MEM_W(0X10, ctx->r19);
    // nop

    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // bne         $a3, $v0, L_8006E198
    if (ctx->r7 != ctx->r2) {
        // andi        $v0, $s2, 0x80
        ctx->r2 = ctx->r18 & 0X80;
        goto L_8006E198;
    }
    // andi        $v0, $s2, 0x80
    ctx->r2 = ctx->r18 & 0X80;
    // addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
    // lbu         $a2, 0x1($v1)
    ctx->r6 = MEM_BU(0X1, ctx->r3);
    // jal         0x8006DE90
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    _SsSeqGetEof(rdram, ctx);
    goto after_0;
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    after_0:
    // j           L_8006E45C
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8006E45C;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006E194:
    // andi        $v0, $s2, 0x80
    ctx->r2 = ctx->r18 & 0X80;
L_8006E198:
    // beq         $v0, $zero, L_8006E2F8
    if (ctx->r2 == 0) {
        // andi        $v0, $s2, 0xF
        ctx->r2 = ctx->r18 & 0XF;
        goto L_8006E2F8;
    }
    // andi        $v0, $s2, 0xF
    ctx->r2 = ctx->r18 & 0XF;
    // sb          $v0, 0x17($s3)
    MEM_B(0X17, ctx->r19) = ctx->r2;
    // andi        $a2, $s2, 0xF0
    ctx->r6 = ctx->r18 & 0XF0;
    // addiu       $v0, $zero, 0xC0
    ctx->r2 = ADD32(0, 0XC0);
    // beq         $a2, $v0, L_8006E278
    if (ctx->r6 == ctx->r2) {
        // slti        $v0, $a2, 0xC1
        ctx->r2 = SIGNED(ctx->r6) < 0XC1 ? 1 : 0;
        goto L_8006E278;
    }
    // slti        $v0, $a2, 0xC1
    ctx->r2 = SIGNED(ctx->r6) < 0XC1 ? 1 : 0;
    // beq         $v0, $zero, L_8006E1D4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x90
        ctx->r2 = ADD32(0, 0X90);
        goto L_8006E1D4;
    }
    // addiu       $v0, $zero, 0x90
    ctx->r2 = ADD32(0, 0X90);
    // beq         $a2, $v0, L_8006E1F0
    if (ctx->r6 == ctx->r2) {
        // addiu       $v0, $zero, 0xB0
        ctx->r2 = ADD32(0, 0XB0);
        goto L_8006E1F0;
    }
    // addiu       $v0, $zero, 0xB0
    ctx->r2 = ADD32(0, 0XB0);
    // beq         $a2, $v0, L_8006E248
    if (ctx->r6 == ctx->r2) {
        // addu        $v0, $s5, $zero
        ctx->r2 = ADD32(ctx->r21, 0);
        goto L_8006E248;
    }
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // j           L_8006E45C
    // nop

    goto L_8006E45C;
    // nop

L_8006E1D4:
    // addiu       $v0, $zero, 0xE0
    ctx->r2 = ADD32(0, 0XE0);
    // beq         $a2, $v0, L_8006E2A8
    if (ctx->r6 == ctx->r2) {
        // addiu       $v0, $zero, 0xF0
        ctx->r2 = ADD32(0, 0XF0);
        goto L_8006E2A8;
    }
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // beq         $a2, $v0, L_8006E2C8
    if (ctx->r6 == ctx->r2) {
        // addu        $v0, $s5, $zero
        ctx->r2 = ADD32(ctx->r21, 0);
        goto L_8006E2C8;
    }
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // j           L_8006E45C
    // nop

    goto L_8006E45C;
    // nop

L_8006E1F0:
    // sll         $s1, $a0, 16
    ctx->r17 = S32(ctx->r4) << 16;
    // sra         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) >> 16;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5) << 16;
    // sra         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) >> 16;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // sb          $a2, 0x16($s3)
    MEM_B(0X16, ctx->r19) = ctx->r6;
    // lbu         $s2, 0x0($v0)
    ctx->r18 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // lbu         $s4, 0x0($v0)
    ctx->r20 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // jal         0x8006E484
    // sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    _SsReadDeltaValue(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    after_1:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // sw          $v0, 0x90($s3)
    MEM_W(0X90, ctx->r19) = ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x7A40($v0)
    ctx->r2 = MEM_W(-0X7A40, ctx->r2);
    // j           L_8006E38C
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    goto L_8006E38C;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
L_8006E248:
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // sb          $a2, 0x16($s3)
    MEM_B(0X16, ctx->r19) = ctx->r6;
    // lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x7A30($v0)
    ctx->r2 = MEM_W(-0X7A30, ctx->r2);
    // j           L_8006E450
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    goto L_8006E450;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
L_8006E278:
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // sb          $a2, 0x16($s3)
    MEM_B(0X16, ctx->r19) = ctx->r6;
    // lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x7A3C($v0)
    ctx->r2 = MEM_W(-0X7A3C, ctx->r2);
    // j           L_8006E450
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    goto L_8006E450;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
L_8006E2A8:
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sb          $a2, 0x16($s3)
    MEM_B(0X16, ctx->r19) = ctx->r6;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8006E3E8
    // sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    goto L_8006E3E8;
    // sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
L_8006E2C8:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // sb          $v1, 0x16($s3)
    MEM_B(0X16, ctx->r19) = ctx->r3;
    // lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x2F
    ctx->r2 = ADD32(0, 0X2F);
    // andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // beq         $a2, $v0, L_8006E414
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_8006E414;
    }
    // nop

    // j           L_8006E43C
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    goto L_8006E43C;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
L_8006E2F8:
    // lbu         $v1, 0x16($s3)
    ctx->r3 = MEM_BU(0X16, ctx->r19);
    // addiu       $v0, $zero, 0xC0
    ctx->r2 = ADD32(0, 0XC0);
    // beq         $v1, $v0, L_8006E3BC
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0xC1
        ctx->r2 = SIGNED(ctx->r3) < 0XC1 ? 1 : 0;
        goto L_8006E3BC;
    }
    // slti        $v0, $v1, 0xC1
    ctx->r2 = SIGNED(ctx->r3) < 0XC1 ? 1 : 0;
    // beq         $v0, $zero, L_8006E328
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x90
        ctx->r2 = ADD32(0, 0X90);
        goto L_8006E328;
    }
    // addiu       $v0, $zero, 0x90
    ctx->r2 = ADD32(0, 0X90);
    // beq         $v1, $v0, L_8006E344
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xB0
        ctx->r2 = ADD32(0, 0XB0);
        goto L_8006E344;
    }
    // addiu       $v0, $zero, 0xB0
    ctx->r2 = ADD32(0, 0XB0);
    // beq         $v1, $v0, L_8006E39C
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $s5, $zero
        ctx->r2 = ADD32(ctx->r21, 0);
        goto L_8006E39C;
    }
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // j           L_8006E45C
    // nop

    goto L_8006E45C;
    // nop

L_8006E328:
    // addiu       $v0, $zero, 0xE0
    ctx->r2 = ADD32(0, 0XE0);
    // beq         $v1, $v0, L_8006E3DC
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8006E3DC;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8006E404
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $s5, $zero
        ctx->r2 = ADD32(ctx->r21, 0);
        goto L_8006E404;
    }
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // j           L_8006E45C
    // nop

    goto L_8006E45C;
    // nop

L_8006E344:
    // sll         $s1, $a0, 16
    ctx->r17 = S32(ctx->r4) << 16;
    // sra         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) >> 16;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5) << 16;
    // sra         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) >> 16;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lbu         $s4, 0x0($v0)
    ctx->r20 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // jal         0x8006E484
    // sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    _SsReadDeltaValue(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    after_2:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // sw          $v0, 0x90($s3)
    MEM_W(0X90, ctx->r19) = ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x7A40($v0)
    ctx->r2 = MEM_W(-0X7A40, ctx->r2);
    // nop

L_8006E38C:
    // jalr        $v0
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_3;
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_3:
    // j           L_8006E45C
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    goto L_8006E45C;
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
L_8006E39C:
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x7A30($v0)
    ctx->r2 = MEM_W(-0X7A30, ctx->r2);
    // j           L_8006E450
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    goto L_8006E450;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
L_8006E3BC:
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x7A3C($v0)
    ctx->r2 = MEM_W(-0X7A3C, ctx->r2);
    // j           L_8006E450
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    goto L_8006E450;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
L_8006E3DC:
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
L_8006E3E8:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x7A38($v0)
    ctx->r2 = MEM_W(-0X7A38, ctx->r2);
    // nop

    // jalr        $v0
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_4;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_4:
    // j           L_8006E45C
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    goto L_8006E45C;
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
L_8006E404:
    // andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    // addiu       $v0, $zero, 0x2F
    ctx->r2 = ADD32(0, 0X2F);
    // bne         $a2, $v0, L_8006E438
    if (ctx->r6 != ctx->r2) {
        // nop
    
        goto L_8006E438;
    }
    // nop

L_8006E414:
    // addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // jal         0x8006DE90
    // addiu       $a2, $zero, 0x2F
    ctx->r6 = ADD32(0, 0X2F);
    _SsSeqGetEof(rdram, ctx);
    goto after_5;
    // addiu       $a2, $zero, 0x2F
    ctx->r6 = ADD32(0, 0X2F);
    after_5:
    // j           L_8006E45C
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    goto L_8006E45C;
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
L_8006E438:
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
L_8006E43C:
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x7A34($v0)
    ctx->r2 = MEM_W(-0X7A34, ctx->r2);
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
L_8006E450:
    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
L_8006E45C:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
