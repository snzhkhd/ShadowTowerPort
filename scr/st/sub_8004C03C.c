#include "recomp.h"
#include "disable_warnings.h"

void sub_8004C03C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // beq         $a0, $zero, L_8004C0D4
    if (ctx->r4 == 0) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8004C0D4;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a1, $v0, -0x5EC8
    ctx->r5 = ADD32(ctx->r2, -0X5EC8);
    // sw          $a0, 0x6138($a1)
    MEM_W(0X6138, ctx->r5) = ctx->r4;
    // lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(0X2, ctx->r4);
    // addiu       $a2, $a1, 0x3500
    ctx->r6 = ADD32(ctx->r5, 0X3500);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sw          $v0, 0x6134($a1)
    MEM_W(0X6134, ctx->r5) = ctx->r2;
    // lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(0X2, ctx->r4);
    // nop

    // sw          $v1, 0x6148($a1)
    MEM_W(0X6148, ctx->r5) = ctx->r3;
    // lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(0X20, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8004C0EC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004C0EC;
    }
    // nop

    // lh          $v1, 0x6A($a0)
    ctx->r3 = MEM_HS(0X6A, ctx->r4);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sw          $v0, 0x6140($a1)
    MEM_W(0X6140, ctx->r5) = ctx->r2;
    // lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(0X2, ctx->r2);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // j           L_8004C0EC
    // sw          $v0, 0x613C($a1)
    MEM_W(0X613C, ctx->r5) = ctx->r2;
    goto L_8004C0EC;
    // sw          $v0, 0x613C($a1)
    MEM_W(0X613C, ctx->r5) = ctx->r2;
L_8004C0D4:
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // sw          $zero, 0x6138($v0)
    MEM_W(0X6138, ctx->r2) = 0;
    // sw          $zero, 0x6134($v0)
    MEM_W(0X6134, ctx->r2) = 0;
    // sw          $zero, 0x6148($v0)
    MEM_W(0X6148, ctx->r2) = 0;
    // sw          $zero, 0x6140($v0)
    MEM_W(0X6140, ctx->r2) = 0;
    // sw          $zero, 0x613C($v0)
    MEM_W(0X613C, ctx->r2) = 0;
L_8004C0EC:
    // jr          $ra
    // nop

    return;
    // nop

;}
