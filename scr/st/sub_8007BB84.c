#include "recomp.h"
#include "disable_warnings.h"

void sub_8007BB84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DD4($v0)
    ctx->r2 = MEM_W(0X7DD4, ctx->r2);
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $s0, 0x100
    ctx->r16 = S32(0X100 << 16);
    // and         $v0, $v0, $s0
    ctx->r2 = ctx->r2 & ctx->r16;
    // bne         $v0, $zero, L_8007BDD0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007BDD0;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x80077490
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    SetIntrMask(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7DE8($a0)
    ctx->r4 = MEM_W(0X7DE8, ctx->r4);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DEC($v1)
    ctx->r3 = MEM_W(0X7DEC, ctx->r3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // beq         $a0, $v1, L_8007BD34
    if (ctx->r4 == ctx->r3) {
        // sw          $v0, 0x7DF4($at)
        MEM_W(0X7DF4, ctx->r1) = ctx->r2;
        goto L_8007BD34;
    }
    // sw          $v0, 0x7DF4($at)
    MEM_W(0X7DF4, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DD4($v0)
    ctx->r2 = MEM_W(0X7DD4, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // and         $v0, $v0, $s0
    ctx->r2 = ctx->r2 & ctx->r16;
    // bne         $v0, $zero, L_8007BD34
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007BD34;
    }
    // nop

    // lui         $s1, 0x400
    ctx->r17 = S32(0X400 << 16);
    // lui         $s0, 0x100
    ctx->r16 = S32(0X100 << 16);
L_8007BBFC:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DEC($v0)
    ctx->r2 = MEM_W(0X7DEC, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DE8($v1)
    ctx->r3 = MEM_W(0X7DE8, ctx->r3);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // bne         $v0, $v1, L_8007BC38
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8007BC38;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7CCC($v0)
    ctx->r2 = MEM_W(0X7CCC, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8007BC38
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
        goto L_8007BC38;
    }
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // jal         0x80077374
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    DMACallback(rdram, ctx);
    goto after_1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
L_8007BC38:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DC8($v1)
    ctx->r3 = MEM_W(0X7DC8, ctx->r3);
    // nop

    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // and         $v0, $v0, $s1
    ctx->r2 = ctx->r2 & ctx->r17;
    // bne         $v0, $zero, L_8007BC6C
    if (ctx->r2 != 0) {
        // lui         $a0, 0x400
        ctx->r4 = S32(0X400 << 16);
        goto L_8007BC6C;
    }
    // lui         $a0, 0x400
    ctx->r4 = S32(0X400 << 16);
L_8007BC58:
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // beq         $v0, $zero, L_8007BC58
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007BC58;
    }
    // nop

L_8007BC6C:
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0x7DEC($a1)
    ctx->r5 = MEM_W(0X7DEC, ctx->r5);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DEC($v1)
    ctx->r3 = MEM_W(0X7DEC, ctx->r3);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5) << 1;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, -0x6544($a0)
    ctx->r4 = MEM_W(-0X6544, ctx->r4);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0x7DEC($a1)
    ctx->r5 = MEM_W(0X7DEC, ctx->r5);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // lw          $a1, -0x6540($a1)
    ctx->r5 = MEM_W(-0X6540, ctx->r5);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, -0x6548($v0)
    ctx->r2 = MEM_W(-0X6548, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DEC($v0)
    ctx->r2 = MEM_W(0X7DEC, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7DEC($at)
    MEM_W(0X7DEC, ctx->r1) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DE8($v1)
    ctx->r3 = MEM_W(0X7DE8, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DEC($v0)
    ctx->r2 = MEM_W(0X7DEC, ctx->r2);
    // nop

    // beq         $v1, $v0, L_8007BD34
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007BD34;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DD4($v0)
    ctx->r2 = MEM_W(0X7DD4, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // and         $v0, $v0, $s0
    ctx->r2 = ctx->r2 & ctx->r16;
    // beq         $v0, $zero, L_8007BBFC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007BBFC;
    }
    // nop

L_8007BD34:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7DF4($a0)
    ctx->r4 = MEM_W(0X7DF4, ctx->r4);
    // jal         0x80077490
    // nop

    SetIntrMask(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DE8($v1)
    ctx->r3 = MEM_W(0X7DE8, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DEC($v0)
    ctx->r2 = MEM_W(0X7DEC, ctx->r2);
    // nop

    // bne         $v1, $v0, L_8007BDB4
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8007BDB4;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DD4($v0)
    ctx->r2 = MEM_W(0X7DD4, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8007BDB4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007BDB4;
    }
    // nop

    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0x7CC8
    ctx->r3 = ADD32(ctx->r3, 0X7CC8);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // beq         $v0, $zero, L_8007BDB4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007BDB4;
    }
    // nop

    // lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(0X4, ctx->r3);
    // nop

    // beq         $a0, $zero, L_8007BDB4
    if (ctx->r4 == 0) {
        // addiu       $v0, $v1, -0x8
        ctx->r2 = ADD32(ctx->r3, -0X8);
        goto L_8007BDB4;
    }
    // addiu       $v0, $v1, -0x8
    ctx->r2 = ADD32(ctx->r3, -0X8);
    // sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // jalr        $a0
    // nop

    LOOKUP_FUNC(ctx->r4)(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_8007BDB4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DE8($v0)
    ctx->r2 = MEM_W(0X7DE8, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DEC($v1)
    ctx->r3 = MEM_W(0X7DEC, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
L_8007BDD0:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
