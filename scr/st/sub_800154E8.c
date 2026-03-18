#include "recomp.h"
#include "disable_warnings.h"

void sub_800154E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // sw          $s0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r16;
    // lw          $s0, -0x7428($v0)
    ctx->r16 = MEM_W(-0X7428, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $a0, $v0, L_800155AC
    if (ctx->r4 != ctx->r2) {
        // sw          $ra, 0x134($sp)
        MEM_W(0X134, ctx->r29) = ctx->r31;
        goto L_800155AC;
    }
    // sw          $ra, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // beq         $v1, $zero, L_80015608
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80015608;
    }
    // nop

    // bltz        $v1, L_80015608
    if (SIGNED(ctx->r3) < 0) {
        // slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
        goto L_80015608;
    }
    // slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_80015608
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80015608;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80015608
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80015608;
    }
    // nop

L_80015534:
    // lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(0X1C, ctx->r16);
    // jal         0x800690BC
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    CdGetSector(rdram, ctx);
    goto after_0;
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // beq         $v0, $zero, L_80015534
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80015534;
    }
    // nop

L_80015548:
    // lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(0X1C, ctx->r16);
    // jal         0x800690BC
    // addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    CdGetSector(rdram, ctx);
    goto after_1;
    // addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_1:
    // beq         $v0, $zero, L_80015548
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_80015548;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(0X1C, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_8001556C:
    // jal         0x800690BC
    // addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    CdGetSector(rdram, ctx);
    goto after_2;
    // addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_2:
    // beq         $v0, $zero, L_8001556C
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8001556C;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(0X24, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v0, $zero, L_80015608
    if (ctx->r2 != 0) {
        // sw          $v0, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r2;
        goto L_80015608;
    }
    // sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // jal         0x80068CCC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdReadyCallback(rdram, ctx);
    goto after_3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // j           L_80015600
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    goto L_80015600;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800155AC:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $a0, $v0, L_80015608
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_80015608;
    }
    // nop

    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // beq         $v1, $zero, L_80015608
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80015608;
    }
    // nop

    // bltz        $v1, L_80015608
    if (SIGNED(ctx->r3) < 0) {
        // slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
        goto L_80015608;
    }
    // slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_80015608
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80015608;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80015608
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80015608;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // jal         0x80068CCC
    // sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    CdReadyCallback(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    after_4:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
L_80015600:
    // jal         0x8001561C
    // nop

    sub_8001561C(rdram, ctx);
    goto after_5;
    // nop

    after_5:
L_80015608:
    // lw          $ra, 0x134($sp)
    ctx->r31 = MEM_W(0X134, ctx->r29);
    // lw          $s0, 0x130($sp)
    ctx->r16 = MEM_W(0X130, ctx->r29);
    // addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // jr          $ra
    // nop

    return;
    // nop

;}
