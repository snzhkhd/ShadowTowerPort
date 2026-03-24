#include "recomp.h"
#include "disable_warnings.h"

void SsVabOpenHeadWithMode(uint8_t* rdram, recomp_context* ctx) 
{
    printf("SsVabOpenHeadWithMode\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x430
    ctx->r29 = ADD32(ctx->r29, -0X430);
    // sw          $s3, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x410($sp)
    MEM_W(0X410, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x414($sp)
    MEM_W(0X414, ctx->r29) = ctx->r17;
    // addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
    // sw          $s5, 0x424($sp)
    MEM_W(0X424, ctx->r29) = ctx->r21;
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // sw          $s4, 0x420($sp)
    MEM_W(0X420, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $ra, 0x428($sp)
    MEM_W(0X428, ctx->r29) = ctx->r31;
    // jal         0x80071EEC
    // sw          $s2, 0x418($sp)
    MEM_W(0X418, ctx->r29) = ctx->r18;
    _spu_getInTransfer(rdram, ctx);
    goto after_0;
    // sw          $s2, 0x418($sp)
    MEM_W(0X418, ctx->r29) = ctx->r18;
    after_0:
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // beq         $v0, $s2, L_80073D9C
    if (ctx->r2 == ctx->r18) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80073D9C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // jal         0x80071EC4
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _spu_setInTransfer(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x10
    ctx->r2 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_80073AF8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80073AF8;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_80073AA8
    if (ctx->r3 != ctx->r2) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80073AA8;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80073A5C:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lbu         $v0, -0x68E8($v0)
    ctx->r2 = MEM_BU(-0X68E8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80073A8C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80073A8C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80073A5C
    if (ctx->r2 != 0) {
        // sll         $v0, $s1, 16
        ctx->r2 = S32(ctx->r17) << 16;
        goto L_80073A5C;
    }
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // j           L_80073AEC
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    goto L_80073AEC;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
L_80073A8C:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // sb          $v0, -0x68E8($at)
    MEM_B(-0X68E8, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x6890($v0)
    ctx->r2 = MEM_HU(-0X6890, ctx->r2);
    // j           L_80073AD8
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    goto L_80073AD8;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
L_80073AA8:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, -0x68E8($v0)
    ctx->r2 = MEM_BU(-0X68E8, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80073AE8
    if (ctx->r2 != 0) {
        // sll         $v0, $s1, 16
        ctx->r2 = S32(ctx->r17) << 16;
        goto L_80073AE8;
    }
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sb          $s2, -0x68E8($at)
    MEM_B(-0X68E8, ctx->r1) = ctx->r18;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x6890($v0)
    ctx->r2 = MEM_HU(-0X6890, ctx->r2);
    // addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
L_80073AD8:
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x6890($at)
    MEM_H(-0X6890, ctx->r1) = ctx->r2;
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
L_80073AE8:
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
L_80073AEC:
    // slti        $v0, $a2, 0x10
    ctx->r2 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80073B08
    if (ctx->r2 != 0) {
        // addu        $a3, $s3, $zero
        ctx->r7 = ADD32(ctx->r19, 0);
        goto L_80073B08;
    }
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
L_80073AF8:
    // jal         0x80071EC4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    _spu_setInTransfer(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // j           L_80073D9C
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80073D9C;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80073B08:
    // sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6) << 2;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $a3, -0x69A8($at)
    MEM_W(-0X69A8, ctx->r1) = ctx->r7;
    // lui         $v1, 0x56
    ctx->r3 = S32(0X56 << 16);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(0X0, ctx->r4);
    // ori         $v1, $v1, 0x4142
    ctx->r3 = ctx->r3 | 0X4142;
    // srl         $v0, $a1, 8
    ctx->r2 = S32(U32(ctx->r5) >> 8);
    // beq         $v0, $v1, L_80073B48
    if (ctx->r2 == ctx->r3) {
        // addiu       $a3, $a3, 0x20
        ctx->r7 = ADD32(ctx->r7, 0X20);
        goto L_80073B48;
    }
    // addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // sb          $zero, -0x68E8($at)
    MEM_B(-0X68E8, ctx->r1) = 0;
    // j           L_80073CBC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    goto L_80073CBC;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80073B48:
    // andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
    // bne         $v1, $v0, L_80073B70
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x40
        ctx->r2 = ADD32(0, 0X40);
        goto L_80073B70;
    }
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80073B70
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x40
        ctx->r2 = ADD32(0, 0X40);
        goto L_80073B70;
    }
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_80073B70:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x691E($at)
    MEM_H(-0X691E, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(0X12, ctx->r4);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lh          $v1, -0x691E($v1)
    ctx->r3 = MEM_HS(-0X691E, ctx->r3);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80073CA4
    if (ctx->r2 != 0) {
        // addu        $s2, $a3, $zero
        ctx->r18 = ADD32(ctx->r7, 0);
        goto L_80073CA4;
    }
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $a3, -0x69E8($at)
    MEM_W(-0X69E8, ctx->r1) = ctx->r7;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // addu        $a3, $s2, $v0
    ctx->r7 = ADD32(ctx->r18, ctx->r2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // blez        $v1, L_80073BE8
    if (SIGNED(ctx->r3) <= 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80073BE8;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
L_80073BC4:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80073BD8
    if (ctx->r2 == 0) {
        // sw          $s0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r16;
        goto L_80073BD8;
    }
    // sw          $s0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r16;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80073BD8:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $a2
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // bne         $v0, $zero, L_80073BC4
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
        goto L_80073BC4;
    }
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_80073BE8:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $a3, -0x6960($at)
    MEM_W(-0X6960, ctx->r1) = ctx->r7;
    // lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(0X12, ctx->r4);
    // lbu         $s3, 0x16($a0)
    ctx->r19 = MEM_BU(0X16, ctx->r4);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // andi        $t0, $s3, 0xFF
    ctx->r8 = ctx->r19 & 0XFF;
L_80073C1C:
    // slt         $v0, $t0, $a1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_80073C50
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80073C50;
    }
    // nop

    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(0X0, ctx->r7);
    // slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80073C40
    if (ctx->r2 != 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_80073C40;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
L_80073C40:
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // nop

    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_80073C50:
    // addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // bne         $v0, $zero, L_80073C1C
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
        goto L_80073C1C;
    }
    // addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
    // bne         $v0, $zero, L_80073C90
    if (ctx->r2 != 0) {
        // addu        $a3, $s5, $zero
        ctx->r7 = ADD32(ctx->r21, 0);
        goto L_80073C90;
    }
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // jal         0x80073DC4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    SpuMalloc(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $a3, $v0, L_80073C94
    if (ctx->r7 != ctx->r2) {
        // addu        $v1, $a3, $s0
        ctx->r3 = ADD32(ctx->r7, ctx->r16);
        goto L_80073C94;
    }
    // addu        $v1, $a3, $s0
    ctx->r3 = ADD32(ctx->r7, ctx->r16);
    // j           L_80073CA8
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    goto L_80073CA8;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80073C90:
    // addu        $v1, $a3, $s0
    ctx->r3 = ADD32(ctx->r7, ctx->r16);
L_80073C94:
    // lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_80073CE4
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80073CE4;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80073CA4:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80073CA8:
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $zero, -0x68E8($at)
    MEM_B(-0X68E8, ctx->r1) = 0;
L_80073CBC:
    // jal         0x80071EC4
    // nop

    _spu_setInTransfer(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lhu         $v1, -0x6890($v1)
    ctx->r3 = MEM_HU(-0X6890, ctx->r3);
    // nop

    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v1, -0x6890($at)
    MEM_H(-0X6890, ctx->r1) = ctx->r3;
    // j           L_80073D9C
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80073D9C;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80073CE4:
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $a3, -0x6888($at)
    MEM_W(-0X6888, ctx->r1) = ctx->r7;
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // slti        $v0, $v1, 0x0
    ctx->r2 = SIGNED(ctx->r3) < 0X0 ? 1 : 0;
    // bne         $v0, $zero, L_80073D74
    if (ctx->r2 != 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80073D74;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80073D10:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // bne         $v0, $zero, L_80073D48
    if (ctx->r2 != 0) {
        // srl         $v1, $a1, 31
        ctx->r3 = S32(U32(ctx->r5) >> 31);
        goto L_80073D48;
    }
    // srl         $v1, $a1, 31
    ctx->r3 = S32(U32(ctx->r5) >> 31);
    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // addu        $v0, $a3, $s0
    ctx->r2 = ADD32(ctx->r7, ctx->r16);
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // j           L_80073D64
    // sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
    goto L_80073D64;
    // sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
L_80073D48:
    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // addu        $v0, $a3, $s0
    ctx->r2 = ADD32(ctx->r7, ctx->r16);
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
L_80073D64:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_80073D10
    if (ctx->r2 == 0) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_80073D10;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80073D74:
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sw          $s0, -0x68D0($at)
    MEM_W(-0X68D0, ctx->r1) = ctx->r16;
    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, -0x68E8($at)
    MEM_B(-0X68E8, ctx->r1) = ctx->r3;
L_80073D9C:
    // lw          $ra, 0x428($sp)
    ctx->r31 = MEM_W(0X428, ctx->r29);
    // lw          $s5, 0x424($sp)
    ctx->r21 = MEM_W(0X424, ctx->r29);
    // lw          $s4, 0x420($sp)
    ctx->r20 = MEM_W(0X420, ctx->r29);
    // lw          $s3, 0x41C($sp)
    ctx->r19 = MEM_W(0X41C, ctx->r29);
    // lw          $s2, 0x418($sp)
    ctx->r18 = MEM_W(0X418, ctx->r29);
    // lw          $s1, 0x414($sp)
    ctx->r17 = MEM_W(0X414, ctx->r29);
    // lw          $s0, 0x410($sp)
    ctx->r16 = MEM_W(0X410, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x430
    ctx->r29 = ADD32(ctx->r29, 0X430);
    return;
    // addiu       $sp, $sp, 0x430
    ctx->r29 = ADD32(ctx->r29, 0X430);
;}
