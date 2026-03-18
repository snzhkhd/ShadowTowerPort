#include "recomp.h"
#include "disable_warnings.h"

void sub_80079AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, 0x7CC2
    ctx->r4 = ADD32(ctx->r4, 0X7CC2);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_80079B04
    if (ctx->r3 == ctx->r2) {
        // addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
        goto L_80079B04;
    }
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_80079B90
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80079B90;
    }
    // nop

    // j           L_80079BD4
    // nop

    goto L_80079BD4;
    // nop

L_80079B04:
    // lh          $a1, 0x4($s0)
    ctx->r5 = MEM_HS(0X4, ctx->r16);
    // lh          $v1, 0x2($a0)
    ctx->r3 = MEM_HS(0X2, ctx->r4);
    // nop

    // slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_80079B84
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80079B84;
    }
    // nop

    // lh          $a3, 0x0($s0)
    ctx->r7 = MEM_HS(0X0, ctx->r16);
    // nop

    // addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80079B84
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80079B84;
    }
    // nop

    // lh          $v1, 0x2($s0)
    ctx->r3 = MEM_HS(0X2, ctx->r16);
    // lh          $a0, 0x4($a0)
    ctx->r4 = MEM_HS(0X4, ctx->r4);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80079B84
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80079B84;
    }
    // nop

    // lh          $a2, 0x6($s0)
    ctx->r6 = MEM_HS(0X6, ctx->r16);
    // nop

    // addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80079B84
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80079B84;
    }
    // nop

    // blez        $a1, L_80079B84
    if (SIGNED(ctx->r5) <= 0) {
        // nop
    
        goto L_80079B84;
    }
    // nop

    // bltz        $a3, L_80079B84
    if (SIGNED(ctx->r7) < 0) {
        // nop
    
        goto L_80079B84;
    }
    // nop

    // bltz        $v1, L_80079B84
    if (SIGNED(ctx->r3) < 0) {
        // nop
    
        goto L_80079B84;
    }
    // nop

    // bgtz        $a2, L_80079BD4
    if (SIGNED(ctx->r6) > 0) {
        // nop
    
        goto L_80079BD4;
    }
    // nop

L_80079B84:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // j           L_80079B98
    // addiu       $a0, $a0, 0x41CC
    ctx->r4 = ADD32(ctx->r4, 0X41CC);
    goto L_80079B98;
    // addiu       $a0, $a0, 0x41CC
    ctx->r4 = ADD32(ctx->r4, 0X41CC);
L_80079B90:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x41EC
    ctx->r4 = ADD32(ctx->r4, 0X41EC);
L_80079B98:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7CBC($v0)
    ctx->r2 = MEM_W(0X7CBC, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    after_0:
    // lh          $a1, 0x0($s0)
    ctx->r5 = MEM_HS(0X0, ctx->r16);
    // lh          $a2, 0x2($s0)
    ctx->r6 = MEM_HS(0X2, ctx->r16);
    // lh          $a3, 0x4($s0)
    ctx->r7 = MEM_HS(0X4, ctx->r16);
    // lh          $v1, 0x6($s0)
    ctx->r3 = MEM_HS(0X6, ctx->r16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7CBC($v0)
    ctx->r2 = MEM_W(0X7CBC, ctx->r2);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x41D8
    ctx->r4 = ADD32(ctx->r4, 0X41D8);
    // jalr        $v0
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_1:
L_80079BD4:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
