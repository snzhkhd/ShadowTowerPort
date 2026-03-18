#include "recomp.h"
#include "disable_warnings.h"

void sub_8004F994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x2230
    ctx->r3 = ADD32(ctx->r3, 0X2230);
    // addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // addiu       $a0, $a3, 0x4C
    ctx->r4 = ADD32(ctx->r7, 0X4C);
L_8004F9D0:
    // lhu         $v0, -0x42($a0)
    ctx->r2 = MEM_HU(-0X42, ctx->r4);
    // nop

    // beq         $v0, $t3, L_8004FA28
    if (ctx->r2 == ctx->r11) {
        // nop
    
        goto L_8004FA28;
    }
    // nop

    // beq         $a2, $t2, L_8004FA10
    if (ctx->r6 == ctx->r10) {
        // nop
    
        goto L_8004FA10;
    }
    // nop

    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // subu        $v1, $a2, $v0
    ctx->r3 = SUB32(ctx->r6, ctx->r2);
    // bgez        $v1, L_8004FA04
    if (SIGNED(ctx->r3) >= 0) {
        // slt         $v0, $t0, $v1
        ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_8004FA04;
    }
    // slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
L_8004FA04:
    // beq         $v0, $zero, L_8004FA10
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004FA10;
    }
    // nop

    // addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
L_8004FA10:
    // addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $zero, L_8004F9D0
    if (ctx->r5 != 0) {
        // addiu       $a3, $a3, 0x58
        ctx->r7 = ADD32(ctx->r7, 0X58);
        goto L_8004F9D0;
    }
    // addiu       $a3, $a3, 0x58
    ctx->r7 = ADD32(ctx->r7, 0X58);
    // jal         0x80078A24
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    exit(rdram, ctx);
    goto after_0;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
L_8004FA28:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
