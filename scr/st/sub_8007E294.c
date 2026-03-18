#include "recomp.h"
#include "disable_warnings.h"

void sub_8007E294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E58($v1)
    ctx->r3 = MEM_W(0X7E58, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E68($v0)
    ctx->r2 = MEM_W(0X7E68, ctx->r2);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // bne         $v1, $v0, L_8007E2F4
    if (ctx->r3 != ctx->r2) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_8007E2F4;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E54($v0)
    ctx->r2 = MEM_W(0X7E54, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8007E2F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007E2F4;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E48($v0)
    ctx->r2 = MEM_W(0X7E48, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E44($v0)
    ctx->r2 = MEM_W(0X7E44, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_8007E2F4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E98($v0)
    ctx->r2 = MEM_W(0X7E98, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8007E338
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007E338;
    }
    // nop

    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E30($v0)
    ctx->r2 = MEM_W(0X7E30, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E30($v0)
    ctx->r2 = MEM_W(0X7E30, ctx->r2);
    // nop

    // jalr        $v0
    // addiu       $a0, $a0, 0xF0
    ctx->r4 = ADD32(ctx->r4, 0XF0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_3;
    // addiu       $a0, $a0, 0xF0
    ctx->r4 = ADD32(ctx->r4, 0XF0);
    after_3:
L_8007E338:
    // lbu         $v0, 0x36($s0)
    ctx->r2 = MEM_BU(0X36, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8007E350
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8007E350;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // j           L_8007E354
    // addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    goto L_8007E354;
    // addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
L_8007E350:
    // lbu         $a1, 0x36($s0)
    ctx->r5 = MEM_BU(0X36, ctx->r16);
L_8007E354:
    // jal         0x8007D604
    // nop

    sub_8007D604(rdram, ctx);
    goto after_4;
    // nop

    after_4:
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
