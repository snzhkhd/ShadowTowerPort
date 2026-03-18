#include "recomp.h"
#include "disable_warnings.h"

void sub_8007C0A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    VSync(rdram, ctx);
    goto after_0;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_0:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DFC($v1)
    ctx->r3 = MEM_W(0X7DFC, ctx->r3);
    // nop

    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_8007C0F8
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8007C0F8;
    }
    // nop

    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0x7E00
    ctx->r3 = ADD32(ctx->r3, 0X7E00);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0xF
    ctx->r2 = S32(0XF << 16);
    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_8007C1D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007C1D4;
    }
    // nop

L_8007C0F8:
    // lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // lw          $a2, 0x7DC8($a2)
    ctx->r6 = MEM_W(0X7DC8, ctx->r6);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x42BC
    ctx->r4 = ADD32(ctx->r4, 0X42BC);
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0x7DE8($a1)
    ctx->r5 = MEM_W(0X7DE8, ctx->r5);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DCC($v0)
    ctx->r2 = MEM_W(0X7DCC, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DEC($v1)
    ctx->r3 = MEM_W(0X7DEC, ctx->r3);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DD4($v0)
    ctx->r2 = MEM_W(0X7DD4, ctx->r2);
    // lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(0X0, ctx->r6);
    // lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(0X0, ctx->r2);
    // jal         0x80078AD4
    // andi        $a1, $a1, 0x3F
    ctx->r5 = ctx->r5 & 0X3F;
    printf(rdram, ctx);
    goto after_1;
    // andi        $a1, $a1, 0x3F
    ctx->r5 = ctx->r5 & 0X3F;
    after_1:
    // jal         0x80077490
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    SetIntrMask(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
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
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, 0x7DE8($at)
    MEM_W(0X7DE8, ctx->r1) = ctx->r3;
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
    // j           L_8007C1D8
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8007C1D8;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007C1D4:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007C1D8:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
