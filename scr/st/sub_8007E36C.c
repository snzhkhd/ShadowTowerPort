#include "recomp.h"
#include "disable_warnings.h"

void sub_8007E36C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E98($v0)
    ctx->r2 = MEM_W(0X7E98, ctx->r2);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // beq         $v0, $zero, L_8007E3B8
    if (ctx->r2 == 0) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_8007E3B8;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E30($v0)
    ctx->r2 = MEM_W(0X7E30, ctx->r2);
    // nop

    // jalr        $v0
    // addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    after_0:
    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E30($v0)
    ctx->r2 = MEM_W(0X7E30, ctx->r2);
    // nop

    // jalr        $v0
    // addiu       $a0, $a0, 0x2D0
    ctx->r4 = ADD32(ctx->r4, 0X2D0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, 0x2D0
    ctx->r4 = ADD32(ctx->r4, 0X2D0);
    after_1:
L_8007E3B8:
    // lbu         $v0, 0x36($s0)
    ctx->r2 = MEM_BU(0X36, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8007E3D0
    if (ctx->r2 != 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8007E3D0;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0x7E64($a1)
    ctx->r5 = MEM_W(0X7E64, ctx->r5);
L_8007E3D0:
    // jal         0x8007D604
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8007D604(rdram, ctx);
    goto after_2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // bltz        $v1, L_8007E41C
    if (SIGNED(ctx->r3) < 0) {
        // nop
    
        goto L_8007E41C;
    }
    // nop

    // andi        $v0, $v1, 0xF0
    ctx->r2 = ctx->r3 & 0XF0;
    // bne         $v0, $zero, L_8007E3F8
    if (ctx->r2 != 0) {
        // andi        $v0, $v1, 0xF
        ctx->r2 = ctx->r3 & 0XF;
        goto L_8007E3F8;
    }
    // andi        $v0, $v1, 0xF
    ctx->r2 = ctx->r3 & 0XF;
    // j           L_8007E41C
    // addiu       $v0, $zero, -0x9
    ctx->r2 = ADD32(0, -0X9);
    goto L_8007E41C;
    // addiu       $v0, $zero, -0x9
    ctx->r2 = ADD32(0, -0X9);
L_8007E3F8:
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E90($at)
    MEM_W(0X7E90, ctx->r1) = ctx->r2;
    // bne         $v0, $zero, L_8007E41C
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007E41C;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E90($at)
    MEM_W(0X7E90, ctx->r1) = ctx->r2;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007E41C:
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
