#include "recomp.h"
#include "disable_warnings.h"

void _SsVmKeyOffNow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // lhu         $a0, -0x68EE($a0)
    ctx->r4 = MEM_HU(-0X68EE, ctx->r4);
    // nop

    // andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // sltiu       $v0, $v1, 0x10
    ctx->r2 = ctx->r3 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_800727FC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800727FC;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sllv        $a2, $v0, $v1
    ctx->r6 = S32(ctx->r2) << (ctx->r3 & 31);
    // j           L_8007280C
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    goto L_8007280C;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800727FC:
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // sllv        $a1, $v0, $v1
    ctx->r5 = S32(ctx->r2) << (ctx->r3 & 31);
    // andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
L_8007280C:
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
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $zero, -0x70E3($at)
    MEM_B(-0X70E3, ctx->r1) = 0;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lhu         $v1, -0x6A08($v1)
    ctx->r3 = MEM_HU(-0X6A08, ctx->r3);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // lhu         $a0, -0x6A06($a0)
    ctx->r4 = MEM_HU(-0X6A06, ctx->r4);
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
    // sh          $zero, -0x7100($at)
    MEM_H(-0X7100, ctx->r1) = 0;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x7110($v0)
    ctx->r2 = MEM_HU(-0X7110, ctx->r2);
    // or          $v1, $v1, $a2
    ctx->r3 = ctx->r3 | ctx->r6;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v1, -0x6A08($at)
    MEM_H(-0X6A08, ctx->r1) = ctx->r3;
    // nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x7110($at)
    MEM_H(-0X7110, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x710E($v0)
    ctx->r2 = MEM_HU(-0X710E, ctx->r2);
    // or          $a0, $a0, $a1
    ctx->r4 = ctx->r4 | ctx->r5;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $a0, -0x6A06($at)
    MEM_H(-0X6A06, ctx->r1) = ctx->r4;
    // nor         $a0, $zero, $a0
    ctx->r4 = ~(0 | ctx->r4);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // jr          $ra
    // sh          $v0, -0x710E($at)
    MEM_H(-0X710E, ctx->r1) = ctx->r2;
    return;
    // sh          $v0, -0x710E($at)
    MEM_H(-0X710E, ctx->r1) = ctx->r2;
;}
