#include "recomp.h"
#include "disable_warnings.h"

void sub_80061EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // sw          $fp, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r30;
    // addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r19;
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // sw          $s2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sw          $s1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r17;
    // addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // sw          $s6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r22;
    // addu        $s6, $s0, $zero
    ctx->r22 = ADD32(ctx->r16, 0);
    // sw          $s7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r23;
    // lui         $s7, 0x1F80
    ctx->r23 = S32(0X1F80 << 16);
    // sw          $ra, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r31;
    // sw          $s5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r21;
    // blez        $s3, L_80062024
    if (SIGNED(ctx->r19) <= 0) {
        // sw          $s4, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r20;
        goto L_80062024;
    }
    // sw          $s4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r20;
    // addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
L_80061F3C:
    // bne         $s1, $zero, L_80061F64
    if (ctx->r17 != 0) {
        // slti        $v0, $s0, 0x3
        ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
        goto L_80061F64;
    }
    // slti        $v0, $s0, 0x3
    ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // lhu         $a0, 0x1F8($s7)
    ctx->r4 = MEM_HU(0X1F8, ctx->r23);
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
    // beq         $v0, $zero, L_80061F6C
    if (ctx->r2 == 0) {
        // addiu       $s1, $zero, 0x3
        ctx->r17 = ADD32(0, 0X3);
        goto L_80061F6C;
    }
    // addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // slti        $v0, $s0, 0x3
    ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
L_80061F64:
    // bne         $v0, $zero, L_80061F74
    if (ctx->r2 != 0) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80061F74;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80061F6C:
    // j           L_80062028
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80062028;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80061F74:
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // jal         0x80077EC4
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    lseek(rdram, ctx);
    goto after_1;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // jal         0x80077ED4
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    read(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_2:
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_80061FAC
    if (ctx->r2 != ctx->r3) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_80061FAC;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x162
    ctx->r2 = ADD32(0, 0X162);
    // j           L_80061F3C
    // sh          $v0, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r2;
    goto L_80061F3C;
    // sh          $v0, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r2;
L_80061FAC:
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_80061FB0:
    // addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // addu        $a0, $a1, $v0
    ctx->r4 = ADD32(ctx->r5, ctx->r2);
    // slti        $v0, $v1, 0x7F
    ctx->r2 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    // bne         $v0, $zero, L_80061FB0
    if (ctx->r2 != 0) {
        // addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
        goto L_80061FB0;
    }
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // nor         $a1, $zero, $a0
    ctx->r5 = ~(0 | ctx->r4);
    // lbu         $v1, 0x8F($sp)
    ctx->r3 = MEM_BU(0X8F, ctx->r29);
    // andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // beq         $v0, $v1, L_80061FE8
    if (ctx->r2 == ctx->r3) {
        // addiu       $v0, $zero, 0x15D
        ctx->r2 = ADD32(0, 0X15D);
        goto L_80061FE8;
    }
    // addiu       $v0, $zero, 0x15D
    ctx->r2 = ADD32(0, 0X15D);
    // j           L_80061F3C
    // sh          $v0, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r2;
    goto L_80061F3C;
    // sh          $v0, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r2;
L_80061FE8:
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80061FEC:
    // addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // slti        $v0, $v1, 0x7F
    ctx->r2 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    // bne         $v0, $zero, L_80061FEC
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80061FEC;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addiu       $s3, $s3, -0x7F
    ctx->r19 = ADD32(ctx->r19, -0X7F);
    // addiu       $s4, $s4, 0x80
    ctx->r20 = ADD32(ctx->r20, 0X80);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lbu         $v0, 0x8F($sp)
    ctx->r2 = MEM_BU(0X8F, ctx->r29);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bgtz        $s3, L_80061F3C
    if (SIGNED(ctx->r19) > 0) {
        // addu        $s6, $s6, $v0
        ctx->r22 = ADD32(ctx->r22, ctx->r2);
        goto L_80061F3C;
    }
    // addu        $s6, $s6, $v0
    ctx->r22 = ADD32(ctx->r22, ctx->r2);
L_80062024:
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
L_80062028:
    // lw          $ra, 0xB4($sp)
    ctx->r31 = MEM_W(0XB4, ctx->r29);
    // lw          $fp, 0xB0($sp)
    ctx->r30 = MEM_W(0XB0, ctx->r29);
    // lw          $s7, 0xAC($sp)
    ctx->r23 = MEM_W(0XAC, ctx->r29);
    // lw          $s6, 0xA8($sp)
    ctx->r22 = MEM_W(0XA8, ctx->r29);
    // lw          $s5, 0xA4($sp)
    ctx->r21 = MEM_W(0XA4, ctx->r29);
    // lw          $s4, 0xA0($sp)
    ctx->r20 = MEM_W(0XA0, ctx->r29);
    // lw          $s3, 0x9C($sp)
    ctx->r19 = MEM_W(0X9C, ctx->r29);
    // lw          $s2, 0x98($sp)
    ctx->r18 = MEM_W(0X98, ctx->r29);
    // lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(0X94, ctx->r29);
    // lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(0X90, ctx->r29);
    // addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // jr          $ra
    // nop

    return;
    // nop

;}
