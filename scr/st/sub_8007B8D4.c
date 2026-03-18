#include "recomp.h"
#include "disable_warnings.h"

void sub_8007B8D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // jal         0x8007C070
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    sub_8007C070(rdram, ctx);
    goto after_0;
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    after_0:
    // j           L_8007B920
    // nop

    goto L_8007B920;
    // nop

L_8007B908:
    // jal         0x8007C0A4
    // nop

    sub_8007C0A4(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // bne         $v0, $zero, L_8007BB68
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8007BB68;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // jal         0x8007BB84
    // nop

    sub_8007BB84(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_8007B920:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DE8($v0)
    ctx->r2 = MEM_W(0X7DE8, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DEC($v1)
    ctx->r3 = MEM_W(0X7DEC, ctx->r3);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // beq         $v0, $v1, L_8007B908
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_8007B908;
    }
    // nop

    // jal         0x80077490
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    SetIntrMask(rdram, ctx);
    goto after_3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, 0x7CC0
    ctx->r4 = ADD32(ctx->r4, 0X7CC0);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7DF0($at)
    MEM_W(0X7DF0, ctx->r1) = ctx->r2;
    // lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(0X1, ctx->r4);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $zero, L_8007B9B4
    if (ctx->r3 == 0) {
        // sw          $v0, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r2;
        goto L_8007B9B4;
    }
    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DE8($v1)
    ctx->r3 = MEM_W(0X7DE8, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DEC($v0)
    ctx->r2 = MEM_W(0X7DEC, ctx->r2);
    // nop

    // bne         $v1, $v0, L_8007B9F8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8007B9F8;
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
    // bne         $v0, $zero, L_8007B9F8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007B9F8;
    }
    // nop

    // lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(0XC, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8007B9F8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007B9F8;
    }
    // nop

L_8007B9B4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DC8($v1)
    ctx->r3 = MEM_W(0X7DC8, ctx->r3);
    // lui         $a0, 0x400
    ctx->r4 = S32(0X400 << 16);
L_8007B9C0:
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // beq         $v0, $zero, L_8007B9C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007B9C0;
    }
    // nop

    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jalr        $s3
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
    goto after_4;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_4:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7DF0($a0)
    ctx->r4 = MEM_W(0X7DF0, ctx->r4);
    // jal         0x80077490
    // nop

    SetIntrMask(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // j           L_8007BB68
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8007BB68;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007B9F8:
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, -0x447C
    ctx->r5 = ADD32(ctx->r5, -0X447C);
    // jal         0x80077374
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    DMACallback(rdram, ctx);
    goto after_6;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // beq         $s1, $zero, L_8007BAB4
    if (ctx->r17 == 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_8007BAB4;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $t0, 0x801F
    ctx->r8 = S32(0X801F << 16);
    // addiu       $t0, $t0, -0x653C
    ctx->r8 = ADD32(ctx->r8, -0X653C);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_8007BA20:
    // bgez        $v0, L_8007BA2C
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8007BA2C;
    }
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
L_8007BA2C:
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8007BA70
    if (ctx->r2 == 0) {
        // sll         $a0, $a2, 2
        ctx->r4 = S32(ctx->r6) << 2;
        goto L_8007BA70;
    }
    // sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6) << 2;
    // lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(0X0, ctx->r7);
    // addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DE8($v1)
    ctx->r3 = MEM_W(0X7DE8, ctx->r3);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // j           L_8007BA20
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    goto L_8007BA20;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_8007BA70:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DE8($v0)
    ctx->r2 = MEM_W(0X7DE8, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DE8($v1)
    ctx->r3 = MEM_W(0X7DE8, ctx->r3);
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4) << 5;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x653C
    ctx->r3 = ADD32(ctx->r3, -0X653C);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // j           L_8007BAD8
    // sw          $v0, -0x6544($at)
    MEM_W(-0X6544, ctx->r1) = ctx->r2;
    goto L_8007BAD8;
    // sw          $v0, -0x6544($at)
    MEM_W(-0X6544, ctx->r1) = ctx->r2;
L_8007BAB4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DE8($v1)
    ctx->r3 = MEM_W(0X7DE8, ctx->r3);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $s0, -0x6544($at)
    MEM_W(-0X6544, ctx->r1) = ctx->r16;
L_8007BAD8:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DE8($v1)
    ctx->r3 = MEM_W(0X7DE8, ctx->r3);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $s2, -0x6540($at)
    MEM_W(-0X6540, ctx->r1) = ctx->r18;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DE8($v1)
    ctx->r3 = MEM_W(0X7DE8, ctx->r3);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $s3, -0x6548($at)
    MEM_W(-0X6548, ctx->r1) = ctx->r19;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DE8($v0)
    ctx->r2 = MEM_W(0X7DE8, ctx->r2);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7DF0($a0)
    ctx->r4 = MEM_W(0X7DF0, ctx->r4);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // jal         0x80077490
    // sw          $v0, 0x7DE8($at)
    MEM_W(0X7DE8, ctx->r1) = ctx->r2;
    SetIntrMask(rdram, ctx);
    goto after_7;
    // sw          $v0, 0x7DE8($at)
    MEM_W(0X7DE8, ctx->r1) = ctx->r2;
    after_7:
    // jal         0x8007BB84
    // nop

    sub_8007BB84(rdram, ctx);
    goto after_8;
    // nop

    after_8:
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
L_8007BB68:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
