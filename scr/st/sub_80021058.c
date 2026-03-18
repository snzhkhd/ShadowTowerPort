#include "recomp.h"
#include "disable_warnings.h"

void sub_80021058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sb          $t1, 0x24($t8)
    MEM_B(0X24, ctx->r24) = ctx->r9;
    // sb          $t0, 0x25($t8)
    MEM_B(0X25, ctx->r24) = ctx->r8;
    // sh          $a0, 0x18($t8)
    MEM_H(0X18, ctx->r24) = ctx->r4;
    // sh          $a0, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r4;
    // sh          $a2, 0x20($t8)
    MEM_H(0X20, ctx->r24) = ctx->r6;
    // sh          $a2, 0x10($t8)
    MEM_H(0X10, ctx->r24) = ctx->r6;
    // sh          $a1, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r5;
    // sh          $a1, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r5;
    // sh          $a3, 0x22($t8)
    MEM_H(0X22, ctx->r24) = ctx->r7;
    // sh          $a3, 0x1A($t8)
    MEM_H(0X1A, ctx->r24) = ctx->r7;
    // sb          $v0, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r2;
    // addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // sb          $v0, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $s1, $v0, L_8002109C
    if (ctx->r17 == ctx->r2) {
        // addiu       $v0, $zero, 0x2E
        ctx->r2 = ADD32(0, 0X2E);
        goto L_8002109C;
    }
    // addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // sb          $v0, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r2;
L_8002109C:
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // lw          $v0, 0xE4($t9)
    ctx->r2 = MEM_W(0XE4, ctx->r25);
    // lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(0X0, ctx->r24);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r3;
    // lw          $v1, 0xE4($t9)
    ctx->r3 = MEM_W(0XE4, ctx->r25);
    // nop

    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // and         $a0, $t8, $a0
    ctx->r4 = ctx->r24 & ctx->r4;
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(0X4, ctx->r29);
    // lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(0X0, ctx->r29);
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // jr          $ra
    // nop

    return;
    // nop

;}
