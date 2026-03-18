#include "recomp.h"
#include "disable_warnings.h"

void sub_8007AF5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // bne         $a0, $zero, L_8007AF6C
    if (ctx->r4 != 0) {
        // addiu       $sp, $sp, -0x10
        ctx->r29 = ADD32(ctx->r29, -0X10);
        goto L_8007AF6C;
    }
    // addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // j           L_8007AFD4
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8007AFD4;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007AF6C:
    // lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(0X0, ctx->r4);
    // nop

    // srl         $a1, $a1, 3
    ctx->r5 = S32(U32(ctx->r5) >> 3);
    // sw          $a1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r5;
    // lh          $a2, 0x4($a0)
    ctx->r6 = MEM_HS(0X4, ctx->r4);
    // nop

    // negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // sra         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6) >> 3;
    // sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(0X2, ctx->r4);
    // sll         $a1, $a1, 10
    ctx->r5 = S32(ctx->r5) << 10;
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // sll         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) << 15;
    // lh          $v1, 0x6($a0)
    ctx->r3 = MEM_HS(0X6, ctx->r4);
    // lui         $a0, 0xE200
    ctx->r4 = S32(0XE200 << 16);
    // or          $a1, $a1, $a0
    ctx->r5 = ctx->r5 | ctx->r4;
    // or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // sra         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) >> 3;
    // sll         $a0, $v1, 5
    ctx->r4 = S32(ctx->r3) << 5;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // or          $v0, $v0, $a2
    ctx->r2 = ctx->r2 | ctx->r6;
    // sw          $v1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r3;
L_8007AFD4:
    // jr          $ra
    // addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
