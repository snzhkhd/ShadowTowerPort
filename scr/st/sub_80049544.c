#include "recomp.h"
#include "disable_warnings.h"

void sub_80049544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // beq         $v0, $zero, L_80049578
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80049578;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // jal         0x80048AD0
    // nop

    sub_80048AD0(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80049578:
    // lhu         $v0, 0x1E($s1)
    ctx->r2 = MEM_HU(0X1E, ctx->r17);
    // lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(0X8, ctx->r17);
    // lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(0X0, ctx->r17);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // andi        $v0, $a1, 0x10
    ctx->r2 = ctx->r5 & 0X10;
    // beq         $v0, $zero, L_800495C4
    if (ctx->r2 == 0) {
        // sw          $v1, 0x8($s1)
        MEM_W(0X8, ctx->r17) = ctx->r3;
        goto L_800495C4;
    }
    // sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // andi        $a1, $a1, 0x400
    ctx->r5 = ctx->r5 & 0X400;
    // sltu        $a1, $zero, $a1
    ctx->r5 = 0 < ctx->r5 ? 1 : 0;
    // jal         0x8004BB88
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    sub_8004BB88(rdram, ctx);
    goto after_1;
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    after_1:
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // sw          $v0, 0x59A4($v1)
    MEM_W(0X59A4, ctx->r3) = ctx->r2;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_800495D0
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_800495D0;
    }
    // nop

    // j           L_800495D0
    // ori         $s0, $s0, 0x10
    ctx->r16 = ctx->r16 | 0X10;
    goto L_800495D0;
    // ori         $s0, $s0, 0x10
    ctx->r16 = ctx->r16 | 0X10;
L_800495C4:
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x59A4($v1)
    MEM_W(0X59A4, ctx->r3) = ctx->r2;
L_800495D0:
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_80049608
    if (ctx->r2 == 0) {
        // lui         $v1, 0x801B
        ctx->r3 = S32(0X801B << 16);
        goto L_80049608;
    }
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // jal         0x8004BE80
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_8004BE80(rdram, ctx);
    goto after_2;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // sw          $v0, 0x59A8($v1)
    MEM_W(0X59A8, ctx->r3) = ctx->r2;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_80049610
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80049610;
    }
    // nop

    // j           L_80049610
    // ori         $s0, $s0, 0x10
    ctx->r16 = ctx->r16 | 0X10;
    goto L_80049610;
    // ori         $s0, $s0, 0x10
    ctx->r16 = ctx->r16 | 0X10;
L_80049608:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x59A8($v1)
    MEM_W(0X59A8, ctx->r3) = ctx->r2;
L_80049610:
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_80049648
    if (ctx->r2 == 0) {
        // lui         $v1, 0x801B
        ctx->r3 = S32(0X801B << 16);
        goto L_80049648;
    }
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // jal         0x8004F53C
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_8004F53C(rdram, ctx);
    goto after_3;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // sw          $v0, 0x59AC($v1)
    MEM_W(0X59AC, ctx->r3) = ctx->r2;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_80049650
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80049650;
    }
    // nop

    // j           L_80049650
    // ori         $s0, $s0, 0x40
    ctx->r16 = ctx->r16 | 0X40;
    goto L_80049650;
    // ori         $s0, $s0, 0x40
    ctx->r16 = ctx->r16 | 0X40;
L_80049648:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x59AC($v1)
    MEM_W(0X59AC, ctx->r3) = ctx->r2;
L_80049650:
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
    // nop

    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // beq         $v0, $zero, L_80049694
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x800
        ctx->r2 = ctx->r3 & 0X800;
        goto L_80049694;
    }
    // andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // beq         $v0, $zero, L_8004967C
    if (ctx->r2 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8004967C;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lhu         $v0, 0x1C($s1)
    ctx->r2 = MEM_HU(0X1C, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x200
    ctx->r2 = ADD32(ctx->r2, 0X200);
    // sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
L_8004967C:
    // jal         0x8003BEB4
    // nop

    sub_8003BEB4(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_80049694
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80049694;
    }
    // nop

    // ori         $s0, $s0, 0x80
    ctx->r16 = ctx->r16 | 0X80;
L_80049694:
    // lhu         $v1, 0x1E($s1)
    ctx->r3 = MEM_HU(0X1E, ctx->r17);
    // lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(0X8, ctx->r17);
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // sw          $a0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r4;
    // sw          $v0, 0x59BC($v1)
    MEM_W(0X59BC, ctx->r3) = ctx->r2;
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
