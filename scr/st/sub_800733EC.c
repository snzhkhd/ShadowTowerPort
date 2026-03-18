#include "recomp.h"
#include "disable_warnings.h"

void sub_800733EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lb          $v0, -0x690C($v0)
    ctx->r2 = MEM_BS(-0X690C, ctx->r2);
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // blez        $v0, L_8007348C
    if (SIGNED(ctx->r2) <= 0) {
        // sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
        goto L_8007348C;
    }
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_80073420:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE60($v0)
    ctx->r2 = MEM_W(0XE60, ctx->r2);
    // sllv        $v1, $s2, $a0
    ctx->r3 = S32(ctx->r18) << (ctx->r4 & 31);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_80073470
    if (ctx->r2 != 0) {
        // sll         $v0, $a0, 3
        ctx->r2 = S32(ctx->r4) << 3;
        goto L_80073470;
    }
    // sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4) << 3;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, -0x70F0($at)
    ctx->r2 = MEM_HS(-0X70F0, ctx->r1);
    // nop

    // bne         $v0, $s1, L_80073470
    if (ctx->r2 != ctx->r17) {
        // andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
        goto L_80073470;
    }
    // andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x68EE($at)
    MEM_H(-0X68EE, ctx->r1) = ctx->r2;
    // jal         0x800727D4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    _SsVmKeyOffNow(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
L_80073470:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lb          $v1, -0x690C($v1)
    ctx->r3 = MEM_BS(-0X690C, ctx->r3);
    // andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80073420
    if (ctx->r2 != 0) {
        // andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
        goto L_80073420;
    }
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_8007348C:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
