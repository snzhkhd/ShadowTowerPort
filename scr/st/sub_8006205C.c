#include "recomp.h"
#include "disable_warnings.h"

void sub_8006205C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x248
    ctx->r29 = ADD32(ctx->r29, -0X248);
    // sw          $s4, 0x240($sp)
    MEM_W(0X240, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x238($sp)
    MEM_W(0X238, ctx->r29) = ctx->r18;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // sw          $s1, 0x234($sp)
    MEM_W(0X234, ctx->r29) = ctx->r17;
    // addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // sw          $ra, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r31;
    // sw          $s3, 0x23C($sp)
    MEM_W(0X23C, ctx->r29) = ctx->r19;
    // sw          $s0, 0x230($sp)
    MEM_W(0X230, ctx->r29) = ctx->r16;
L_80062084:
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $a0, 0x1F8($s2)
    ctx->r4 = MEM_HU(0X1F8, ctx->r18);
    // addiu       $a3, $v0, -0x7F34
    ctx->r7 = ADD32(ctx->r2, -0X7F34);
    // lh          $v1, 0x0($a3)
    ctx->r3 = MEM_HS(0X0, ctx->r7);
    // lb          $a1, 0x2($a3)
    ctx->r5 = MEM_BS(0X2, ctx->r7);
    // sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // sb          $a1, 0x12($sp)
    MEM_B(0X12, ctx->r29) = ctx->r5;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x80078AE4
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    itoa(rdram, ctx);
    goto after_0;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_0:
    // addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80078A64
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    strcat_recomp(rdram, ctx);
    goto after_1;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // jal         0x80078A64
    // addiu       $a1, $a1, -0x7F2C
    ctx->r5 = ADD32(ctx->r5, -0X7F2C);
    strcat_recomp(rdram, ctx);
    goto after_2;
    // addiu       $a1, $a1, -0x7F2C
    ctx->r5 = ADD32(ctx->r5, -0X7F2C);
    after_2:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lhu         $a1, 0x1FE($s2)
    ctx->r5 = MEM_HU(0X1FE, ctx->r18);
    // lw          $v0, 0x1F4($s2)
    ctx->r2 = MEM_W(0X1F4, ctx->r18);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) >> 11;
    // jal         0x80078A64
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    strcat_recomp(rdram, ctx);
    goto after_3;
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_3:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80077EB4
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    open(rdram, ctx);
    goto after_4;
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_8006211C
    if (ctx->r16 != ctx->r2) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8006211C;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // bne         $s1, $zero, L_80062084
    if (ctx->r17 != 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80062084;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $zero, 0x162
    ctx->r2 = ADD32(0, 0X162);
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // j           L_80062204
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80062204;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006211C:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80077EC4
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    lseek(rdram, ctx);
    goto after_5;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_5:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // jal         0x80077ED4
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    read(rdram, ctx);
    goto after_6;
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_6:
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // bne         $v0, $s3, L_80062158
    if (ctx->r2 != ctx->r19) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80062158;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // bne         $s1, $zero, L_800621E4
    if (ctx->r17 != 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_800621E4;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $zero, 0x162
    ctx->r2 = ADD32(0, 0X162);
    // j           L_800621D0
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    goto L_800621D0;
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_80062158:
    // addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // jal         0x80061EE8
    // addiu       $a3, $zero, 0x1D88
    ctx->r7 = ADD32(0, 0X1D88);
    sub_80061EE8(rdram, ctx);
    goto after_7;
    // addiu       $a3, $zero, 0x1D88
    ctx->r7 = ADD32(0, 0X1D88);
    after_7:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // beq         $a0, $s3, L_80062198
    if (ctx->r4 == ctx->r19) {
        // nop
    
        goto L_80062198;
    }
    // nop

    // lhu         $v0, 0x1FE($s2)
    ctx->r2 = MEM_HU(0X1FE, ctx->r18);
    // lw          $v1, 0x1F4($s2)
    ctx->r3 = MEM_W(0X1F4, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x1E($v1)
    ctx->r2 = MEM_BU(0X1E, ctx->r3);
    // nop

    // beq         $a0, $v0, L_800621F8
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_800621F8;
    }
    // nop

L_80062198:
    // lhu         $v0, 0x1FE($s2)
    ctx->r2 = MEM_HU(0X1FE, ctx->r18);
    // lw          $v1, 0x1F4($s2)
    ctx->r3 = MEM_W(0X1F4, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x1E($v1)
    ctx->r2 = MEM_BU(0X1E, ctx->r3);
    // nop

    // beq         $a0, $v0, L_800621C0
    if (ctx->r4 == ctx->r2) {
        // addiu       $v0, $zero, 0x15D
        ctx->r2 = ADD32(0, 0X15D);
        goto L_800621C0;
    }
    // addiu       $v0, $zero, 0x15D
    ctx->r2 = ADD32(0, 0X15D);
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_800621C0:
    // bne         $s1, $zero, L_800621E0
    if (ctx->r17 != 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_800621E0;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_8;
    // nop

    after_8:
L_800621D0:
    // jal         0x80077EF4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    close(rdram, ctx);
    goto after_9;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // j           L_80062204
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80062204;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800621E0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800621E4:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80077EC4
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    lseek(rdram, ctx);
    goto after_10;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_10:
    // j           L_8006211C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    goto L_8006211C;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800621F8:
    // jal         0x80077EF4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    close(rdram, ctx);
    goto after_11;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80062204:
    // lw          $ra, 0x244($sp)
    ctx->r31 = MEM_W(0X244, ctx->r29);
    // lw          $s4, 0x240($sp)
    ctx->r20 = MEM_W(0X240, ctx->r29);
    // lw          $s3, 0x23C($sp)
    ctx->r19 = MEM_W(0X23C, ctx->r29);
    // lw          $s2, 0x238($sp)
    ctx->r18 = MEM_W(0X238, ctx->r29);
    // lw          $s1, 0x234($sp)
    ctx->r17 = MEM_W(0X234, ctx->r29);
    // lw          $s0, 0x230($sp)
    ctx->r16 = MEM_W(0X230, ctx->r29);
    // addiu       $sp, $sp, 0x248
    ctx->r29 = ADD32(ctx->r29, 0X248);
    // jr          $ra
    // nop

    return;
    // nop

;}
