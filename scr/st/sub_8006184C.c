#include "recomp.h"
#include "disable_warnings.h"

void sub_8006184C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x250
    ctx->r29 = ADD32(ctx->r29, -0X250);
    // sw          $s2, 0x238($sp)
    MEM_W(0X238, ctx->r29) = ctx->r18;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // sw          $ra, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = ctx->r31;
    // sw          $s6, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r22;
    // sw          $s5, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r21;
    // sw          $s4, 0x240($sp)
    MEM_W(0X240, ctx->r29) = ctx->r20;
    // sw          $s3, 0x23C($sp)
    MEM_W(0X23C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x234($sp)
    MEM_W(0X234, ctx->r29) = ctx->r17;
    // sw          $s0, 0x230($sp)
    MEM_W(0X230, ctx->r29) = ctx->r16;
    // lw          $v0, 0x1F4($s2)
    ctx->r2 = MEM_W(0X1F4, ctx->r18);
    // nop

    // lh          $s3, 0xE2($v0)
    ctx->r19 = MEM_HS(0XE2, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // beq         $s3, $v0, L_800619D8
    if (ctx->r19 == ctx->r2) {
        // addiu       $s5, $zero, 0x3
        ctx->r21 = ADD32(0, 0X3);
        goto L_800619D8;
    }
    // addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // addiu       $s4, $sp, 0x10
    ctx->r20 = ADD32(ctx->r29, 0X10);
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // sll         $s1, $s3, 5
    ctx->r17 = S32(ctx->r19) << 5;
L_8006189C:
    // lhu         $a0, 0x1F8($s2)
    ctx->r4 = MEM_HU(0X1F8, ctx->r18);
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
    // bne         $v0, $zero, L_800618C0
    if (ctx->r2 != 0) {
        // lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
        goto L_800618C0;
    }
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // j           L_800619DC
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_800619DC;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800618C0:
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
    goto after_1;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_1:
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x80078A64
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    strcat_recomp(rdram, ctx);
    goto after_2;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_2:
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // jal         0x80078A64
    // addiu       $a1, $a1, -0x7F2C
    ctx->r5 = ADD32(ctx->r5, -0X7F2C);
    strcat_recomp(rdram, ctx);
    goto after_3;
    // addiu       $a1, $a1, -0x7F2C
    ctx->r5 = ADD32(ctx->r5, -0X7F2C);
    after_3:
    // lw          $a1, 0x1F4($s2)
    ctx->r5 = MEM_W(0X1F4, ctx->r18);
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x80078A64
    // addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    strcat_recomp(rdram, ctx);
    goto after_4;
    // addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    after_4:
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x80077EB4
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    open(rdram, ctx);
    goto after_5;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // bne         $s0, $s6, L_80061938
    if (ctx->r16 != ctx->r22) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80061938;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $v0, $zero, 0x162
    ctx->r2 = ADD32(0, 0X162);
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // j           L_800619DC
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_800619DC;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80061938:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80077EC4
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    lseek(rdram, ctx);
    goto after_6;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_6:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // jal         0x80077ED4
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    read(rdram, ctx);
    goto after_7;
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_7:
    // bne         $v0, $s6, L_80061988
    if (ctx->r2 != ctx->r22) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80061988;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // bne         $s5, $zero, L_80061974
    if (ctx->r21 != 0) {
        // addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
        goto L_80061974;
    }
    // addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // jal         0x80077EF4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    close(rdram, ctx);
    goto after_8;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // j           L_800619DC
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_800619DC;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80061974:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80077EC4
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    lseek(rdram, ctx);
    goto after_9;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_9:
    // j           L_80061938
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    goto L_80061938;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80061988:
    // addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // lw          $v0, 0x1F4($s2)
    ctx->r2 = MEM_W(0X1F4, ctx->r18);
    // lbu         $v1, 0x6D($sp)
    ctx->r3 = MEM_BU(0X6D, ctx->r29);
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // sb          $v1, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r3;
    // lw          $v0, 0x1F4($s2)
    ctx->r2 = MEM_W(0X1F4, ctx->r18);
    // lhu         $v1, 0x6E($sp)
    ctx->r3 = MEM_HU(0X6E, ctx->r29);
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // sh          $v1, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r3;
    // lw          $v0, 0x1F4($s2)
    ctx->r2 = MEM_W(0X1F4, ctx->r18);
    // lhu         $v1, 0x70($sp)
    ctx->r3 = MEM_HU(0X70, ctx->r29);
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // sh          $v1, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r3;
    // lw          $v0, 0x1F4($s2)
    ctx->r2 = MEM_W(0X1F4, ctx->r18);
    // lbu         $v1, 0x72($sp)
    ctx->r3 = MEM_BU(0X72, ctx->r29);
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // jal         0x80077EF4
    // sb          $v1, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r3;
    close(rdram, ctx);
    goto after_10;
    // sb          $v1, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r3;
    after_10:
    // bne         $s3, $s6, L_8006189C
    if (ctx->r19 != ctx->r22) {
        // addiu       $s1, $s1, -0x20
        ctx->r17 = ADD32(ctx->r17, -0X20);
        goto L_8006189C;
    }
    // addiu       $s1, $s1, -0x20
    ctx->r17 = ADD32(ctx->r17, -0X20);
L_800619D8:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800619DC:
    // lw          $ra, 0x24C($sp)
    ctx->r31 = MEM_W(0X24C, ctx->r29);
    // lw          $s6, 0x248($sp)
    ctx->r22 = MEM_W(0X248, ctx->r29);
    // lw          $s5, 0x244($sp)
    ctx->r21 = MEM_W(0X244, ctx->r29);
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
    // addiu       $sp, $sp, 0x250
    ctx->r29 = ADD32(ctx->r29, 0X250);
    // jr          $ra
    // nop

    return;
    // nop

;}
