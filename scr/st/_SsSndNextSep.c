#include "recomp.h"
#include "disable_warnings.h"

void _SsSndNextSep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addiu       $v0, $v0, -0x79A0
    ctx->r2 = ADD32(ctx->r2, -0X79A0);
    // sra         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4) >> 14;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $a2, $a1, 1
    ctx->r6 = S32(ctx->r5) << 1;
    // addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    // sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6) << 2;
    // subu        $a2, $a2, $a1
    ctx->r6 = SUB32(ctx->r6, ctx->r5);
    // sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6) << 4;
    // lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(0X0, ctx->r4);
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // sb          $t0, 0x20($a3)
    MEM_B(0X20, ctx->r7) = ctx->r8;
    // sb          $zero, 0x21($a3)
    MEM_B(0X21, ctx->r7) = 0;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // addiu       $a1, $zero, -0x101
    ctx->r5 = ADD32(0, -0X101);
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // addiu       $a1, $zero, -0x9
    ctx->r5 = ADD32(0, -0X9);
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // addiu       $a1, $zero, -0x3
    ctx->r5 = ADD32(0, -0X3);
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // addiu       $a1, $zero, -0x201
    ctx->r5 = ADD32(0, -0X201);
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    // lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(0X4, ctx->r7);
    // sb          $t0, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r8;
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // lw          $v0, 0x98($a2)
    ctx->r2 = MEM_W(0X98, ctx->r6);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // jr          $ra
    // sw          $v0, 0x98($a2)
    MEM_W(0X98, ctx->r6) = ctx->r2;
    return;
    // sw          $v0, 0x98($a2)
    MEM_W(0X98, ctx->r6) = ctx->r2;
;}
