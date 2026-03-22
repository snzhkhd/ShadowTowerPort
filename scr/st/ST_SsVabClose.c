#include "recomp.h"
#include "disable_warnings.h"

void ST_SsVabClose(uint8_t* rdram, recomp_context* ctx) 
{
    printf("SsVabClose\n");


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // beq         $v0, $zero, L_800735D4
    if (ctx->r2 == 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_800735D4;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2) >> 16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // lbu         $v1, -0x68E8($v1)
    ctx->r3 = MEM_BU(-0X68E8, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_800735D4
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $s0, 2
        ctx->r2 = S32(ctx->r16) << 2;
        goto L_800735D4;
    }
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, -0x6888($a0)
    ctx->r4 = MEM_W(-0X6888, ctx->r4);
    // jal         0x800735E4
    // nop

    SpuFree(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // sb          $zero, -0x68E8($at)
    MEM_B(-0X68E8, ctx->r1) = 0;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x6890($v0)
    ctx->r2 = MEM_HU(-0X6890, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x6890($at)
    MEM_H(-0X6890, ctx->r1) = ctx->r2;
L_800735D4:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
