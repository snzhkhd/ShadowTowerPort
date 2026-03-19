#include "recomp.h"
#include "disable_warnings.h"


void sub_800175A4(uint8_t* rdram, recomp_context* ctx) 
{
    printf("sub_800175A4  end draw?\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x80079A60
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    ST_DrawSync(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // jal         0x80077104
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    VSync(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // lui         $s0, 0x1
    ctx->r16 = S32(0X1 << 16);
    // ori         $s0, $s0, 0x8000
    ctx->r16 = ctx->r16 | 0X8000;
    // lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // addiu       $s1, $s1, -0x2F70
    ctx->r17 = ADD32(ctx->r17, -0X2F70);
    // addu        $s0, $s1, $s0
    ctx->r16 = ADD32(ctx->r17, ctx->r16);
    // lbu         $v0, 0x6CC2($s0)
    ctx->r2 = MEM_BU(0X6CC2, ctx->r16);
    // nop

    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addiu       $v0, $s1, 0xB8
    ctx->r2 = ADD32(ctx->r17, 0XB8);
    // jal         0x8007A290
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    PutDispEnv(rdram, ctx);
    goto after_2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_2:
    // lbu         $v0, 0x6CC2($s0)
    ctx->r2 = MEM_BU(0X6CC2, ctx->r16);
    // nop

    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x8007A0C4
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    PutDrawEnv(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_3:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
