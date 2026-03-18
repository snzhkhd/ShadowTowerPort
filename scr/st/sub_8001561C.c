#include "recomp.h"
#include "disable_warnings.h"

void sub_8001561C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $s0, -0x7428($v0)
    ctx->r16 = MEM_W(-0X7428, ctx->r2);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $a0, $v0, L_800157CC
    if (ctx->r4 != ctx->r2) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_800157CC;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // beq         $v1, $zero, L_80015834
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80015834;
    }
    // nop

    // bltz        $v1, L_80015834
    if (SIGNED(ctx->r3) < 0) {
        // slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
        goto L_80015834;
    }
    // slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_80015834
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80015834;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80015834
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80015834;
    }
    // nop

    // lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(0X1, ctx->r16);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // beq         $v1, $a2, L_80015834
    if (ctx->r3 == ctx->r6) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80015834;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80015694
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80015694;
    }
    // nop

    // beq         $v1, $zero, L_800156A4
    if (ctx->r3 == 0) {
        // nop
    
        goto L_800156A4;
    }
    // nop

    // j           L_80015834
    // nop

    goto L_80015834;
    // nop

L_80015694:
    // beq         $v1, $a0, L_80015700
    if (ctx->r3 == ctx->r4) {
        // nop
    
        goto L_80015700;
    }
    // nop

    // j           L_80015834
    // nop

    goto L_80015834;
    // nop

L_800156A4:
    // lwl         $v0, 0x1B($s0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X1B, ctx->r16);
    // lwr         $v0, 0x18($s0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X18, ctx->r16);
    // nop

    // swl         $v0, 0x17($s0)
    do_swl(rdram, 0X17, ctx->r16, ctx->r2);
    // swr         $v0, 0x14($s0)
    do_swr(rdram, 0X14, ctx->r16, ctx->r2);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(0X20, ctx->r16);
    // addiu       $a0, $a0, 0x54E8
    ctx->r4 = ADD32(ctx->r4, 0X54E8);
    // sb          $a2, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r6;
    // sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // jal         0x80068CCC
    // sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    CdReadyCallback(rdram, ctx);
    goto after_0;
    // sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    after_0:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80068CB8
    // addiu       $a0, $a0, 0x561C
    ctx->r4 = ADD32(ctx->r4, 0X561C);
    CdSyncCallback(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, 0x561C
    ctx->r4 = ADD32(ctx->r4, 0X561C);
    after_1:
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_800156E8:
    // jal         0x80068E1C
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    CdControlF(rdram, ctx);
    goto after_2;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // beq         $v0, $zero, L_800156E8
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
        goto L_800156E8;
    }
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // j           L_80015834
    // nop

    goto L_80015834;
    // nop

L_80015700:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // bne         $v0, $a0, L_800157AC
    if (ctx->r2 != ctx->r4) {
        // nop
    
        goto L_800157AC;
    }
    // nop

    // lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(0X24, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80015744
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80015744;
    }
    // nop

    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_80015728:
    // addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // beq         $v0, $zero, L_80015728
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
        goto L_80015728;
    }
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // j           L_80015834
    // nop

    goto L_80015834;
    // nop

L_80015744:
    // lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(0X20, ctx->r16);
    // lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(0X28, ctx->r16);
    // jal         0x80015B78
    // nop

    sub_80015B78(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // beq         $v0, $zero, L_80015780
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80015780;
    }
    // nop

    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_80015764:
    // addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_5;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_5:
    // beq         $v0, $zero, L_80015764
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
        goto L_80015764;
    }
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // j           L_80015834
    // nop

    goto L_80015834;
    // nop

L_80015780:
    // lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(0X2C, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8001579C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001579C;
    }
    // nop

    // lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(0X20, ctx->r16);
    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_6;
    // nop

    after_6:
L_8001579C:
    // jal         0x80015848
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80015848(rdram, ctx);
    goto after_7;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // j           L_80015834
    // nop

    goto L_80015834;
    // nop

L_800157AC:
    // lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(0X2C, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80015834
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80015834;
    }
    // nop

    // jalr        $v0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_8;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // j           L_80015834
    // nop

    goto L_80015834;
    // nop

L_800157CC:
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $a0, $v0, L_800157E4
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_800157E4;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // j           L_80015834
    // nop

    goto L_80015834;
    // nop

L_800157E4:
    // bne         $a0, $v0, L_80015834
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_80015834;
    }
    // nop

    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // beq         $v1, $zero, L_80015834
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80015834;
    }
    // nop

    // bltz        $v1, L_80015834
    if (SIGNED(ctx->r3) < 0) {
        // slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
        goto L_80015834;
    }
    // slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_80015834
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80015834;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80015834
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80015834;
    }
    // nop

    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_80015820:
    // addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_9;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_9:
    // beq         $v0, $zero, L_80015820
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
        goto L_80015820;
    }
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_80015834:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
