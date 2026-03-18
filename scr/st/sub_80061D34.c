#include "recomp.h"
#include "disable_warnings.h"

void sub_80061D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // sw          $s5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sw          $s0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sw          $s3, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r19;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // sw          $s2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r18;
    // addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
    // sw          $s6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r22;
    // addu        $s6, $s2, $zero
    ctx->r22 = ADD32(ctx->r18, 0);
    // sw          $ra, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r31;
    // sw          $fp, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r30;
    // sw          $s7, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r23;
    // blez        $s4, L_80061EB0
    if (SIGNED(ctx->r20) <= 0) {
        // sw          $s1, 0x114($sp)
        MEM_W(0X114, ctx->r29) = ctx->r17;
        goto L_80061EB0;
    }
    // sw          $s1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r17;
    // addiu       $s7, $sp, 0x10
    ctx->r23 = ADD32(ctx->r29, 0X10);
    // addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
L_80061D88:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sb          $zero, 0x8F($sp)
    MEM_B(0X8F, ctx->r29) = 0;
L_80061D90:
    // addu        $v1, $s7, $a0
    ctx->r3 = ADD32(ctx->r23, ctx->r4);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lbu         $v1, 0x8F($sp)
    ctx->r3 = MEM_BU(0X8F, ctx->r29);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slti        $v0, $a0, 0x7F
    ctx->r2 = SIGNED(ctx->r4) < 0X7F ? 1 : 0;
    // bne         $v0, $zero, L_80061D90
    if (ctx->r2 != 0) {
        // sb          $v1, 0x8F($sp)
        MEM_B(0X8F, ctx->r29) = ctx->r3;
        goto L_80061D90;
    }
    // sb          $v1, 0x8F($sp)
    MEM_B(0X8F, ctx->r29) = ctx->r3;
    // nor         $v0, $zero, $v1
    ctx->r2 = ~(0 | ctx->r3);
    // sb          $v0, 0x8F($sp)
    MEM_B(0X8F, ctx->r29) = ctx->r2;
L_80061DC4:
    // bne         $s2, $zero, L_80061DF8
    if (ctx->r18 != 0) {
        // slti        $v0, $s3, 0x3
        ctx->r2 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
        goto L_80061DF8;
    }
    // slti        $v0, $s3, 0x3
    ctx->r2 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // lhu         $a0, 0x1F8($a0)
    ctx->r4 = MEM_HU(0X1F8, ctx->r4);
    // nop

    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x80061578
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_80061578(rdram, ctx);
    goto after_0;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_0:
    // bne         $v0, $zero, L_80061DF4
    if (ctx->r2 != 0) {
        // addiu       $s2, $zero, 0x3
        ctx->r18 = ADD32(0, 0X3);
        goto L_80061DF4;
    }
    // addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // j           L_80061EB4
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80061EB4;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80061DF4:
    // slti        $v0, $s3, 0x3
    ctx->r2 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
L_80061DF8:
    // bne         $v0, $zero, L_80061E14
    if (ctx->r2 != 0) {
        // addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80061E14;
    }
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // addiu       $v0, $zero, 0x163
    ctx->r2 = ADD32(0, 0X163);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sh          $v0, 0x0($at)
    MEM_H(0X0, ctx->r1) = ctx->r2;
    // j           L_80061EB4
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80061EB4;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80061E14:
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80077EC4
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    lseek(rdram, ctx);
    goto after_1;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // jal         0x80077EE4
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    write(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_2:
    // beq         $v0, $fp, L_80061DC4
    if (ctx->r2 == ctx->r30) {
        // addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
        goto L_80061DC4;
    }
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // jal         0x80077EC4
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    lseek(rdram, ctx);
    goto after_3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // jal         0x80077ED4
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    read(rdram, ctx);
    goto after_4;
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_4:
    // beq         $v0, $fp, L_80061DC4
    if (ctx->r2 == ctx->r30) {
        // addiu       $a2, $sp, 0x90
        ctx->r6 = ADD32(ctx->r29, 0X90);
        goto L_80061DC4;
    }
    // addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_80061E68:
    // addu        $v0, $a2, $a0
    ctx->r2 = ADD32(ctx->r6, ctx->r4);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // slti        $v0, $a0, 0x7F
    ctx->r2 = SIGNED(ctx->r4) < 0X7F ? 1 : 0;
    // bne         $v0, $zero, L_80061E68
    if (ctx->r2 != 0) {
        // addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
        goto L_80061E68;
    }
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // nor         $a0, $zero, $v1
    ctx->r4 = ~(0 | ctx->r3);
    // lbu         $v1, 0x8F($sp)
    ctx->r3 = MEM_BU(0X8F, ctx->r29);
    // andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // bne         $v0, $v1, L_80061DC4
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80061DC4;
    }
    // nop

    // addiu       $s4, $s4, -0x7F
    ctx->r20 = ADD32(ctx->r20, -0X7F);
    // addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // addu        $s6, $s6, $a0
    ctx->r22 = ADD32(ctx->r22, ctx->r4);
    // bgtz        $s4, L_80061D88
    if (SIGNED(ctx->r20) > 0) {
        // addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_80061D88;
    }
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80061EB0:
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
L_80061EB4:
    // lw          $ra, 0x134($sp)
    ctx->r31 = MEM_W(0X134, ctx->r29);
    // lw          $fp, 0x130($sp)
    ctx->r30 = MEM_W(0X130, ctx->r29);
    // lw          $s7, 0x12C($sp)
    ctx->r23 = MEM_W(0X12C, ctx->r29);
    // lw          $s6, 0x128($sp)
    ctx->r22 = MEM_W(0X128, ctx->r29);
    // lw          $s5, 0x124($sp)
    ctx->r21 = MEM_W(0X124, ctx->r29);
    // lw          $s4, 0x120($sp)
    ctx->r20 = MEM_W(0X120, ctx->r29);
    // lw          $s3, 0x11C($sp)
    ctx->r19 = MEM_W(0X11C, ctx->r29);
    // lw          $s2, 0x118($sp)
    ctx->r18 = MEM_W(0X118, ctx->r29);
    // lw          $s1, 0x114($sp)
    ctx->r17 = MEM_W(0X114, ctx->r29);
    // lw          $s0, 0x110($sp)
    ctx->r16 = MEM_W(0X110, ctx->r29);
    // addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // jr          $ra
    // nop

    return;
    // nop

;}
