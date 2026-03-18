#include "recomp.h"
#include "disable_warnings.h"

void sub_8007BDE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x80077490
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    SetIntrMask(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x7DEC($at)
    MEM_W(0X7DEC, ctx->r1) = 0;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DEC($v1)
    ctx->r3 = MEM_W(0X7DEC, ctx->r3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7DF8($at)
    MEM_W(0X7DF8, ctx->r1) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, 0x7DE8($at)
    MEM_W(0X7DE8, ctx->r1) = ctx->r3;
    // andi        $v1, $s0, 0x7
    ctx->r3 = ctx->r16 & 0X7;
    // beq         $v1, $v0, L_8007BEB4
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8007BEB4;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8007BE44
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8007BE44;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $zero, L_8007BE54
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8007BE54;
    }
    // nop

    // j           L_8007BF00
    // nop

    goto L_8007BF00;
    // nop

L_8007BE44:
    // beq         $v1, $v0, L_8007BEB4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_8007BEB4;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $v1, $v0, L_8007BF00
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8007BF00;
    }
    // nop

L_8007BE54:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DD4($v1)
    ctx->r3 = MEM_W(0X7DD4, ctx->r3);
    // addiu       $v0, $zero, 0x401
    ctx->r2 = ADD32(0, 0X401);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DE4($v1)
    ctx->r3 = MEM_W(0X7DE4, ctx->r3);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x6650
    ctx->r4 = ADD32(ctx->r4, -0X6650);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
    // addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    // jal         0x8007C6C8
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    sub_8007C6C8(rdram, ctx);
    goto after_1;
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_1:
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x6548
    ctx->r4 = ADD32(ctx->r4, -0X6548);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x8007C6C8
    // addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    sub_8007C6C8(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x1800
    ctx->r6 = ADD32(0, 0X1800);
    after_2:
    // j           L_8007BF00
    // nop

    goto L_8007BF00;
    // nop

L_8007BEB4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DD4($v1)
    ctx->r3 = MEM_W(0X7DD4, ctx->r3);
    // addiu       $v0, $zero, 0x401
    ctx->r2 = ADD32(0, 0X401);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DE4($v1)
    ctx->r3 = MEM_W(0X7DE4, ctx->r3);
    // nop

    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DC8($v1)
    ctx->r3 = MEM_W(0X7DC8, ctx->r3);
    // lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DC8($v1)
    ctx->r3 = MEM_W(0X7DC8, ctx->r3);
    // lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8007BF00:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7DF8($a0)
    ctx->r4 = MEM_W(0X7DF8, ctx->r4);
    // jal         0x80077490
    // nop

    SetIntrMask(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // bne         $v0, $zero, L_8007BF24
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007BF24;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // jal         0x8007C1E8
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8007C1E8(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
L_8007BF24:
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
