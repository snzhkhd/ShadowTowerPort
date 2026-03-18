#include "recomp.h"
#include "disable_warnings.h"

void _SsVmInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $ra, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r31;
    // sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // jal         0x80071EC4
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    _spu_setInTransfer(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    after_0:
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // addiu       $a1, $a1, -0x6840
    ctx->r5 = ADD32(ctx->r5, -0X6840);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x6968($at)
    MEM_H(-0X6968, ctx->r1) = 0;
    // jal         0x80071E64
    // addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    SpuInitMalloc(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x6BD0
    ctx->r3 = ADD32(ctx->r3, -0X6BD0);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_80071B68:
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // sltiu       $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 < 0XC0 ? 1 : 0;
    // bne         $v0, $zero, L_80071B68
    if (ctx->r2 != 0) {
        // andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
        goto L_80071B68;
    }
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_80071B90:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $zero, -0x6BF0($at)
    MEM_B(-0X6BF0, ctx->r1) = 0;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_80071B90
    if (ctx->r2 != 0) {
        // andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
        goto L_80071B90;
    }
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x6890($at)
    MEM_H(-0X6890, ctx->r1) = 0;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
L_80071BC0:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $zero, -0x68E8($at)
    MEM_B(-0X68E8, ctx->r1) = 0;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80071BC0
    if (ctx->r2 != 0) {
        // andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
        goto L_80071BC0;
    }
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // sll         $v0, $s1, 24
    ctx->r2 = S32(ctx->r17) << 24;
    // sra         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2) >> 24;
    // sltiu       $v0, $v1, 0x18
    ctx->r2 = ctx->r3 < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_80071C08
    if (ctx->r2 != 0) {
        // lui         $v0, 0x6
        ctx->r2 = S32(0X6 << 16);
        goto L_80071C08;
    }
    // lui         $v0, 0x6
    ctx->r2 = S32(0X6 << 16);
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sb          $v0, -0x690C($at)
    MEM_B(-0X690C, ctx->r1) = ctx->r2;
    // j           L_80071C10
    // lui         $v0, 0x6
    ctx->r2 = S32(0X6 << 16);
    goto L_80071C10;
    // lui         $v0, 0x6
    ctx->r2 = S32(0X6 << 16);
L_80071C08:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sb          $v1, -0x690C($at)
    MEM_B(-0X690C, ctx->r1) = ctx->r3;
L_80071C10:
    // ori         $v0, $v0, 0x93
    ctx->r2 = ctx->r2 | 0X93;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lb          $v1, -0x690C($v1)
    ctx->r3 = MEM_BS(-0X690C, ctx->r3);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // ori         $v0, $zero, 0x80FF
    ctx->r2 = 0 | 0X80FF;
    // sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // sh          $zero, 0x18($sp)
    MEM_H(0X18, ctx->r29) = 0;
    // sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    // blez        $v1, L_80071DC0
    if (SIGNED(ctx->r3) <= 0) {
        // sh          $v0, 0x4C($sp)
        MEM_H(0X4C, ctx->r29) = ctx->r2;
        goto L_80071DC0;
    }
    // sh          $v0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r2;
    // addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
    // addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // addiu       $s3, $zero, 0x40
    ctx->r19 = ADD32(0, 0X40);
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80071C68:
    // andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // sllv        $v1, $s2, $v1
    ctx->r3 = S32(ctx->r18) << (ctx->r3 & 31);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s5, -0x70FE($at)
    MEM_H(-0X70FE, ctx->r1) = ctx->r21;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s1, -0x7100($at)
    MEM_H(-0X7100, ctx->r1) = ctx->r17;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $zero, -0x70E3($at)
    MEM_B(-0X70E3, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70FC($at)
    MEM_H(-0X70FC, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70FA($at)
    MEM_H(-0X70FA, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s4, -0x70F0($at)
    MEM_H(-0X70F0, ctx->r1) = ctx->r20;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70EE($at)
    MEM_H(-0X70EE, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70EC($at)
    MEM_H(-0X70EC, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s1, -0x70EA($at)
    MEM_H(-0X70EA, ctx->r1) = ctx->r17;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70F8($at)
    MEM_H(-0X70F8, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70F4($at)
    MEM_H(-0X70F4, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $s3, -0x70F6($at)
    MEM_B(-0X70F6, ctx->r1) = ctx->r19;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70E2($at)
    MEM_H(-0X70E2, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70E0($at)
    MEM_H(-0X70E0, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70DE($at)
    MEM_H(-0X70DE, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70DC($at)
    MEM_H(-0X70DC, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70D6($at)
    MEM_H(-0X70D6, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70D4($at)
    MEM_H(-0X70D4, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70D2($at)
    MEM_H(-0X70D2, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70D0($at)
    MEM_H(-0X70D0, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70CE($at)
    MEM_H(-0X70CE, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70DA($at)
    MEM_H(-0X70DA, ctx->r1) = 0;
    // jal         0x80071204
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    SpuSetVoiceAttr(rdram, ctx);
    goto after_2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_2:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $s0, -0x68EE($at)
    MEM_H(-0X68EE, ctx->r1) = ctx->r16;
    // jal         0x800727D4
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _SsVmKeyOffNow(rdram, ctx);
    goto after_3;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lb          $v1, -0x690C($v1)
    ctx->r3 = MEM_BS(-0X690C, ctx->r3);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80071C68
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80071C68;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80071DC0:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addiu       $v0, $v0, -0x6A00
    ctx->r2 = ADD32(ctx->r2, -0X6A00);
    // addiu       $v1, $zero, 0x3FFF
    ctx->r3 = ADD32(0, 0X3FFF);
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
    // sh          $v1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r3;
    // sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
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
    // sh          $zero, -0x6A08($at)
    MEM_H(-0X6A08, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x710C($at)
    MEM_H(-0X710C, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x710A($at)
    MEM_H(-0X710A, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x7108($at)
    MEM_H(-0X7108, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x7106($at)
    MEM_H(-0X7106, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sb          $zero, -0x68D8($at)
    MEM_B(-0X68D8, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $zero, -0x6920($at)
    MEM_H(-0X6920, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // jal         0x80070894
    // sh          $v0, -0x691E($at)
    MEM_H(-0X691E, ctx->r1) = ctx->r2;
    _SsVmFlush(rdram, ctx);
    goto after_4;
    // sh          $v0, -0x691E($at)
    MEM_H(-0X691E, ctx->r1) = ctx->r2;
    after_4:
    // lw          $ra, 0x68($sp)
    ctx->r31 = MEM_W(0X68, ctx->r29);
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
    // addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
