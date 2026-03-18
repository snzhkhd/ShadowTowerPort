#include "recomp.h"
#include "disable_warnings.h"

void catan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $t1, $sp, 0x74
    ctx->r9 = ADD32(ctx->r29, 0X74);
    // lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // addiu       $t0, $t0, 0x1F20
    ctx->r8 = ADD32(ctx->r8, 0X1F20);
    // addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // addu        $a1, $sp, $zero
    ctx->r5 = ADD32(ctx->r29, 0);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
L_80074590:
    // lw          $v1, 0x38($a1)
    ctx->r3 = MEM_W(0X38, ctx->r5);
    // nop

    // bgez        $v1, L_800745D4
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_800745D4;
    }
    // nop

    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // srav        $v1, $v1, $a2
    ctx->r3 = S32(ctx->r3) >> (ctx->r6 & 31);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lw          $v1, 0x38($a1)
    ctx->r3 = MEM_W(0X38, ctx->r5);
    // srav        $v0, $v0, $a2
    ctx->r2 = S32(ctx->r2) >> (ctx->r6 & 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // lw          $v0, 0x70($a1)
    ctx->r2 = MEM_W(0X70, ctx->r5);
    // lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(0X0, ctx->r8);
    // j           L_80074608
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_80074608;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_800745D4:
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // srav        $v1, $v1, $a2
    ctx->r3 = S32(ctx->r3) >> (ctx->r6 & 31);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lw          $v1, 0x38($a1)
    ctx->r3 = MEM_W(0X38, ctx->r5);
    // srav        $v0, $v0, $a2
    ctx->r2 = S32(ctx->r2) >> (ctx->r6 & 31);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // lw          $v0, 0x70($a1)
    ctx->r2 = MEM_W(0X70, ctx->r5);
    // lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(0X0, ctx->r8);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_80074608:
    // sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slti        $v0, $a2, 0xC
    ctx->r2 = SIGNED(ctx->r6) < 0XC ? 1 : 0;
    // bne         $v0, $zero, L_80074590
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
        goto L_80074590;
    }
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(0XA0, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
