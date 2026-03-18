#include "recomp.h"
#include "disable_warnings.h"

void StoreImage2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x42F0
    ctx->r4 = ADD32(ctx->r4, 0X42F0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x80079AC8
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80079AC8(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    VSync(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_1:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DD4($v1)
    ctx->r3 = MEM_W(0X7DD4, ctx->r3);
    // addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, 0XF0);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7DFC($at)
    MEM_W(0X7DFC, ctx->r1) = ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x7E00($at)
    MEM_W(0X7E00, ctx->r1) = 0;
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // j           L_8007C304
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    goto L_8007C304;
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
L_8007C2E0:
    // jal         0x8007C0A4
    // nop

    sub_8007C0A4(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // bne         $v0, $zero, L_8007C360
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8007C360;
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
L_8007C304:
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8007C2E0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007C2E0;
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
    // beq         $v0, $zero, L_8007C2E0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007C2E0;
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
    goto after_3;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7CB8($v0)
    ctx->r2 = MEM_W(0X7CB8, ctx->r2);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(0X20, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_4;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007C360:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
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
