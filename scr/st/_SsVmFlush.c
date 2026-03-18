#include "recomp.h"
#include "disable_warnings.h"

void _SsVmFlush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x6A4C($v0)
    ctx->r2 = MEM_W(-0X6A4C, ctx->r2);
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // sw          $ra, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r31;
    // sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v0, -0x6A4C($at)
    MEM_W(-0X6A4C, ctx->r1) = ctx->r2;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $zero, -0x6A48($at)
    MEM_W(-0X6A48, ctx->r1) = 0;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lb          $v0, -0x690C($v0)
    ctx->r2 = MEM_BS(-0X690C, ctx->r2);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x6A48
    ctx->r3 = ADD32(ctx->r3, -0X6A48);
    // blez        $v0, L_80070974
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80070974;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // lui         $s2, 0x801F
    ctx->r18 = S32(0X801F << 16);
    // addiu       $s2, $s2, -0x70FA
    ctx->r18 = ADD32(ctx->r18, -0X70FA);
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80070910:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80071AF4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    SpuGetVoiceEnvelope(rdram, ctx);
    goto after_0;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_0:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // lhu         $v0, -0x70FA($v0)
    ctx->r2 = MEM_HU(-0X70FA, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80070958
    if (ctx->r2 != 0) {
        // sllv        $a0, $s3, $s0
        ctx->r4 = S32(ctx->r19) << (ctx->r16 & 31);
        goto L_80070958;
    }
    // sllv        $a0, $s3, $s0
    ctx->r4 = S32(ctx->r19) << (ctx->r16 & 31);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x6A4C($v0)
    ctx->r2 = MEM_W(-0X6A4C, ctx->r2);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // nop

    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_80070958:
    // addiu       $s2, $s2, 0x36
    ctx->r18 = ADD32(ctx->r18, 0X36);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lb          $v0, -0x690C($v0)
    ctx->r2 = MEM_BS(-0X690C, ctx->r2);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80070910
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x36
        ctx->r17 = ADD32(ctx->r17, 0X36);
        goto L_80070910;
    }
    // addiu       $s1, $s1, 0x36
    ctx->r17 = ADD32(ctx->r17, 0X36);
L_80070974:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lb          $v0, -0x68D8($v0)
    ctx->r2 = MEM_BS(-0X68D8, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80070A40
    if (ctx->r2 != 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80070A40;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x6A48
    ctx->r3 = ADD32(ctx->r3, -0X6A48);
L_80070994:
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // and         $s2, $s2, $v0
    ctx->r18 = ctx->r18 & ctx->r2;
    // slti        $v0, $s0, 0xF
    ctx->r2 = SIGNED(ctx->r16) < 0XF ? 1 : 0;
    // bne         $v0, $zero, L_80070994
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_80070994;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lb          $v0, -0x690C($v0)
    ctx->r2 = MEM_BS(-0X690C, ctx->r2);
    // nop

    // blez        $v0, L_80070A3C
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80070A3C;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // lui         $s1, 0x801F
    ctx->r17 = S32(0X801F << 16);
    // addiu       $s1, $s1, -0x70E3
    ctx->r17 = ADD32(ctx->r17, -0X70E3);
L_800709D0:
    // sllv        $a1, $s3, $s0
    ctx->r5 = S32(ctx->r19) << (ctx->r16 & 31);
    // and         $v0, $s2, $a1
    ctx->r2 = ctx->r18 & ctx->r5;
    // beq         $v0, $zero, L_80070A24
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070A24;
    }
    // nop

    // lb          $v0, 0x0($s1)
    ctx->r2 = MEM_BS(0X0, ctx->r17);
    // nop

    // bne         $v0, $s4, L_80070A20
    if (ctx->r2 != ctx->r20) {
        // slti        $v0, $s0, 0x10
        ctx->r2 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
        goto L_80070A20;
    }
    // slti        $v0, $s0, 0x10
    ctx->r2 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80070A04
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80070A04;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $v0, $s0, -0x10
    ctx->r2 = ADD32(ctx->r16, -0X10);
    // sllv        $v0, $s3, $v0
    ctx->r2 = S32(ctx->r19) << (ctx->r2 & 31);
L_80070A04:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // jal         0x80070D24
    // or          $a1, $v0, $a1
    ctx->r5 = ctx->r2 | ctx->r5;
    SpuSetNoiseVoice(rdram, ctx);
    goto after_1;
    // or          $a1, $v0, $a1
    ctx->r5 = ctx->r2 | ctx->r5;
    after_1:
L_80070A20:
    // sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_80070A24:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lb          $v0, -0x690C($v0)
    ctx->r2 = MEM_BS(-0X690C, ctx->r2);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800709D0
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x36
        ctx->r17 = ADD32(ctx->r17, 0X36);
        goto L_800709D0;
    }
    // addiu       $s1, $s1, 0x36
    ctx->r17 = ADD32(ctx->r17, 0X36);
L_80070A3C:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80070A40:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x6A08($v0)
    ctx->r2 = MEM_HU(-0X6A08, ctx->r2);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lhu         $v1, -0x7110($v1)
    ctx->r3 = MEM_HU(-0X7110, ctx->r3);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x6A06($v0)
    ctx->r2 = MEM_HU(-0X6A06, ctx->r2);
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v1, -0x7110($at)
    MEM_H(-0X7110, ctx->r1) = ctx->r3;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lhu         $v1, -0x710E($v1)
    ctx->r3 = MEM_HU(-0X710E, ctx->r3);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v1, -0x710E($at)
    MEM_H(-0X710E, ctx->r1) = ctx->r3;
L_80070A84:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // lh          $v0, -0x70E2($v0)
    ctx->r2 = MEM_HS(-0X70E2, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80070AB0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070AB0;
    }
    // nop

    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x6A50($v0)
    ctx->r2 = MEM_W(-0X6A50, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_80070AB0:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // lh          $v0, -0x70D6($v0)
    ctx->r2 = MEM_HS(-0X70D6, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80070ADC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070ADC;
    }
    // nop

    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x6BD8($v0)
    ctx->r2 = MEM_W(-0X6BD8, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_80070ADC:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x18
    ctx->r2 = SIGNED(ctx->r16) < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_80070A84
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x36
        ctx->r17 = ADD32(ctx->r17, 0X36);
        goto L_80070A84;
    }
    // addiu       $s1, $s1, 0x36
    ctx->r17 = ADD32(ctx->r17, 0X36);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $s1, 0x801F
    ctx->r17 = S32(0X801F << 16);
    // addiu       $s1, $s1, -0x6BF0
    ctx->r17 = ADD32(ctx->r17, -0X6BF0);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addiu       $v0, $v0, -0x6BD0
    ctx->r2 = ADD32(ctx->r2, -0X6BD0);
    // addiu       $s7, $v0, 0xA
    ctx->r23 = ADD32(ctx->r2, 0XA);
    // addiu       $s6, $v0, 0x8
    ctx->r22 = ADD32(ctx->r2, 0X8);
    // addiu       $s5, $v0, 0x6
    ctx->r21 = ADD32(ctx->r2, 0X6);
    // addiu       $s4, $v0, 0x4
    ctx->r20 = ADD32(ctx->r2, 0X4);
    // addiu       $s3, $v0, 0x2
    ctx->r19 = ADD32(ctx->r2, 0X2);
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_80070B18:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2) << (ctx->r16 & 31);
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80070B58
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_80070B58;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(0X0, ctx->r19);
    // nop

    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
L_80070B58:
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // beq         $v0, $zero, L_80070B88
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070B88;
    }
    // nop

    // lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(0X14, ctx->r29);
    // nop

    // ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(0X0, ctx->r20);
    // nop

    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
L_80070B88:
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_80070BBC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070BBC;
    }
    // nop

    // lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(0X14, ctx->r29);
    // nop

    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(0X0, ctx->r21);
    // nop

    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80070BBC:
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_80070BF8
    if (ctx->r2 == 0) {
        // lui         $v1, 0x6
        ctx->r3 = S32(0X6 << 16);
        goto L_80070BF8;
    }
    // lui         $v1, 0x6
    ctx->r3 = S32(0X6 << 16);
    // lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(0X14, ctx->r29);
    // nop

    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(0X0, ctx->r22);
    // nop

    // sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x0($s7)
    ctx->r2 = MEM_HU(0X0, ctx->r23);
    // nop

    // sh          $v0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r2;
L_80070BF8:
    // lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(0X14, ctx->r29);
    // nop

    // beq         $v0, $zero, L_80070C10
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070C10;
    }
    // nop

    // jal         0x80071204
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    SpuSetVoiceAttr(rdram, ctx);
    goto after_4;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_4:
L_80070C10:
    // sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
    // addiu       $s6, $s6, 0x10
    ctx->r22 = ADD32(ctx->r22, 0X10);
    // addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x18
    ctx->r2 = SIGNED(ctx->r16) < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_80070B18
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
        goto L_80070B18;
    }
    // addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // lbu         $a1, -0x6A06($a1)
    ctx->r5 = MEM_BU(-0X6A06, ctx->r5);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x6A08($v0)
    ctx->r2 = MEM_HU(-0X6A08, ctx->r2);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x80071044
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    SpuSetKey(rdram, ctx);
    goto after_5;
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    after_5:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // lbu         $a1, -0x710E($a1)
    ctx->r5 = MEM_BU(-0X710E, ctx->r5);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(-0X7110, ctx->r2);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x80071044
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    SpuSetKey(rdram, ctx);
    goto after_6;
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    after_6:
    // addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // lbu         $a1, -0x710A($a1)
    ctx->r5 = MEM_BU(-0X710A, ctx->r5);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x710C($v0)
    ctx->r2 = MEM_HU(-0X710C, ctx->r2);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x80071014
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    SpuSetReverbVoice(rdram, ctx);
    goto after_7;
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    after_7:
    // addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // lbu         $a1, -0x7106($a1)
    ctx->r5 = MEM_BU(-0X7106, ctx->r5);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x7108($v0)
    ctx->r2 = MEM_HU(-0X7108, ctx->r2);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x80070D24
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    SpuSetNoiseVoice(rdram, ctx);
    goto after_8;
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    after_8:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x6A08($at)
    MEM_H(-0X6A08, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x6A06($at)
    MEM_H(-0X6A06, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x7110($at)
    MEM_H(-0X7110, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x710E($at)
    MEM_H(-0X710E, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x7108($at)
    MEM_H(-0X7108, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x7106($at)
    MEM_H(-0X7106, ctx->r1) = 0;
    // lw          $ra, 0x70($sp)
    ctx->r31 = MEM_W(0X70, ctx->r29);
    // lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(0X6C, ctx->r29);
    // lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(0X68, ctx->r29);
    // lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(0X64, ctx->r29);
    // lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(0X60, ctx->r29);
    // lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(0X5C, ctx->r29);
    // lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(0X58, ctx->r29);
    // lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(0X54, ctx->r29);
    // lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(0X50, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
