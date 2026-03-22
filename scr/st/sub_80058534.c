#include "recomp.h"
#include "disable_warnings.h"

void sub_80058534(uint8_t* rdram, recomp_context* ctx) 
{

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // beq         $a1, $v0, L_8005860C
    if (ctx->r5 == ctx->r2) {
        // sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
        goto L_8005860C;
    }
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, -0x2EDF($v0)
    ctx->r2 = MEM_BU(-0X2EDF, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8005860C
    if (ctx->r2 == 0) {
        // andi        $v0, $a1, 0x7FF
        ctx->r2 = ctx->r5 & 0X7FF;
        goto L_8005860C;
    }
    // andi        $v0, $a1, 0x7FF
    ctx->r2 = ctx->r5 & 0X7FF;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x23BC
    ctx->r2 = ADD32(ctx->r2, -0X23BC);
    // addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // lh          $v1, 0x0($a3)
    ctx->r3 = MEM_HS(0X0, ctx->r7);
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // beq         $v1, $t0, L_8005860C
    if (ctx->r3 == ctx->r8) {
        // sll         $v1, $v1, 3
        ctx->r3 = S32(ctx->r3) << 3;
        goto L_8005860C;
    }
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addiu       $v0, $v0, -0xA5C
    ctx->r2 = ADD32(ctx->r2, -0XA5C);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lh          $a1, 0x4($v1)
    ctx->r5 = MEM_HS(0X4, ctx->r3);
    // nop

    // beq         $a1, $t0, L_8005860C
    if (ctx->r5 == ctx->r8) {
        // addiu       $v0, $zero, 0xFE
        ctx->r2 = ADD32(0, 0XFE);
        goto L_8005860C;
    }
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // beq         $a1, $v0, L_8005860C
    if (ctx->r5 == ctx->r2) {
        // nop
    
        goto L_8005860C;
    }
    // nop

    // lh          $v0, 0x6($a3)
    ctx->r2 = MEM_HS(0X6, ctx->r7);
    // nop

    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // bgez        $a2, L_800585C0
    if (SIGNED(ctx->r6) >= 0) {
        // slti        $v0, $a2, 0x80
        ctx->r2 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
        goto L_800585C0;
    }
    // slti        $v0, $a2, 0x80
    ctx->r2 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // j           L_800585CC
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_800585CC;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800585C0:
    // bne         $v0, $zero, L_800585D0
    if (ctx->r2 != 0) {
        // sll         $v0, $a2, 16
        ctx->r2 = S32(ctx->r6) << 16;
        goto L_800585D0;
    }
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
L_800585CC:
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
L_800585D0:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4) << 16;
    // sra         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) >> 16;
    // lh          $a1, 0x4($v1)
    ctx->r5 = MEM_HS(0X4, ctx->r3);
    // lh          $a2, 0x2($a3)
    ctx->r6 = MEM_HS(0X2, ctx->r7);
    // lh          $a3, 0x4($a3)
    ctx->r7 = MEM_HS(0X4, ctx->r7);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8006F054
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8006F054(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x2E40
    ctx->r2 = ADD32(ctx->r2, -0X2E40);
    // sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16) << 1;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $v0, 0xA50($s0)
    MEM_H(0XA50, ctx->r16) = ctx->r2;
L_8005860C:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
