#include "recomp.h"
#include "disable_warnings.h"

void DrawOTag2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
L_8007C4C0:
    // bne         $v0, $zero, L_8007C58C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8007C58C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DD4($v0)
    ctx->r2 = MEM_W(0X7DD4, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8007C4C0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007C4C0;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8007C4C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007C4C0;
    }
    // nop

    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, -0x3960
    ctx->r5 = ADD32(ctx->r5, -0X3960);
    // jal         0x80077374
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    DMACallback(rdram, ctx);
    goto after_0;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // lh          $v0, 0x4($s0)
    ctx->r2 = MEM_HS(0X4, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8007C58C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8007C58C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lh          $v0, 0x6($s0)
    ctx->r2 = MEM_HS(0X6, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8007C548
    if (ctx->r2 != 0) {
        // sll         $v0, $s1, 16
        ctx->r2 = S32(ctx->r17) << 16;
        goto L_8007C548;
    }
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // j           L_8007C58C
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8007C58C;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007C548:
    // andi        $v1, $s2, 0xFFFF
    ctx->r3 = ctx->r18 & 0XFFFF;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(0X0, ctx->r16);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7CB8($v1)
    ctx->r3 = MEM_W(0X7CB8, ctx->r3);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, 0x7D60
    ctx->r4 = ADD32(ctx->r4, 0X7D60);
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(0X18, ctx->r3);
    // nop

    // jalr        $v0
    // addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    after_1:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007C58C:
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
