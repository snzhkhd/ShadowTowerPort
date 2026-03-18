#include "recomp.h"
#include "disable_warnings.h"

void sub_80023ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // addu        $s5, $a3, $s1
    ctx->r21 = ADD32(ctx->r7, ctx->r17);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // lui         $s4, 0x1F80
    ctx->r20 = S32(0X1F80 << 16);
    // lw          $s4, 0xF0($s4)
    ctx->r20 = MEM_W(0XF0, ctx->r20);
    // slt         $v0, $s1, $s5
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r21) ? 1 : 0;
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // beq         $v0, $zero, L_80023FD4
    if (ctx->r2 == 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_80023FD4;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s6, $v0, 0x76F8
    ctx->r22 = ADD32(ctx->r2, 0X76F8);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // sll         $v1, $s2, 2
    ctx->r3 = S32(ctx->r18) << 2;
    // addu        $s3, $v1, $v0
    ctx->r19 = ADD32(ctx->r3, ctx->r2);
L_80023F38:
    // lbu         $v1, 0x0($s4)
    ctx->r3 = MEM_BU(0X0, ctx->r20);
    // ori         $v0, $zero, 0x834C
    ctx->r2 = 0 | 0X834C;
    // addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(0X0, ctx->r2);
    // beq         $v1, $zero, L_80023F94
    if (ctx->r3 == 0) {
        // addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_80023F94;
    }
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // bne         $s0, $zero, L_80023F74
    if (ctx->r16 != 0) {
        // addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
        goto L_80023F74;
    }
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // sll         $a1, $s1, 1
    ctx->r5 = S32(ctx->r17) << 1;
    // addu        $v0, $s2, $s6
    ctx->r2 = ADD32(ctx->r18, ctx->r22);
    // lbu         $a3, -0x1B8($v0)
    ctx->r7 = MEM_BU(-0X1B8, ctx->r2);
    // jal         0x80023ABC
    // andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    sub_80023ABC(rdram, ctx);
    goto after_0;
    // andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    after_0:
    // j           L_80023FC4
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    goto L_80023FC4;
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80023F74:
    // jal         0x80015258
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80015258(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // bne         $v0, $v1, L_80023FC0
    if (ctx->r2 != ctx->r3) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80023FC0;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // j           L_80023FB8
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    goto L_80023FB8;
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80023F94:
    // beq         $s0, $zero, L_80023FC0
    if (ctx->r16 == 0) {
        // nop
    
        goto L_80023FC0;
    }
    // nop

    // jal         0x80015258
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80015258(rdram, ctx);
    goto after_2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // beq         $v0, $v1, L_80023FC0
    if (ctx->r2 == ctx->r3) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80023FC0;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80023FB8:
    // jal         0x80015250
    // nop

    sub_80015250(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_80023FC0:
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80023FC4:
    // addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // slt         $v0, $s1, $s5
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r21) ? 1 : 0;
    // bne         $v0, $zero, L_80023F38
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80023F38;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80023FD4:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
