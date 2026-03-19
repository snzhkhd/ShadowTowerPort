#include "kf_cd.h"

#include "recomp.h"
#include "disable_warnings.h"

void CdControlB(uint8_t* rdram, recomp_context* ctx) 
{
    printf("CdControlB\n");
    KFCD_CdControl(rdram, ctx);
    return;


    
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // andi        $s3, $s4, 0xFF
    ctx->r19 = ctx->r20 & 0XFF;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0x950
    ctx->r3 = ADD32(ctx->r3, 0X950);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // lw          $s5, 0x9D8($s5)
    ctx->r21 = MEM_W(0X9D8, ctx->r21);
    // sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19) << 2;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addu        $s6, $v0, $v1
    ctx->r22 = ADD32(ctx->r2, ctx->r3);
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
L_80068FB0:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // beq         $s3, $fp, L_80068FE4
    if (ctx->r19 == ctx->r30) {
        // sw          $zero, 0x9D8($at)
        MEM_W(0X9D8, ctx->r1) = 0;
        goto L_80068FE4;
    }
    // sw          $zero, 0x9D8($at)
    MEM_W(0X9D8, ctx->r1) = 0;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lbu         $v0, 0x9E8($v0)
    ctx->r2 = MEM_BU(0X9E8, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_80068FE4
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_80068FE4;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80069D68
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw(rdram, ctx);
    goto after_0;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
L_80068FE4:
    // beq         $s1, $zero, L_80069014
    if (ctx->r17 == 0) {
        // nop
    
        goto L_80069014;
    }
    // nop

    // lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(0X0, ctx->r22);
    // nop

    // beq         $v0, $zero, L_80069014
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
        goto L_80069014;
    }
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // jal         0x80069D68
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw(rdram, ctx);
    goto after_1;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // bne         $v0, $zero, L_80069038
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80069038;
    }
    // nop

L_80069014:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $s5, 0x9D8($at)
    MEM_W(0X9D8, ctx->r1) = ctx->r21;
    // andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // jal         0x80069D68
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw(rdram, ctx);
    goto after_2;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // beq         $v0, $zero, L_8006904C
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8006904C;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80069038:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s7, L_80068FB0
    if (ctx->r16 != ctx->r23) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80068FB0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $s5, 0x9D8($at)
    MEM_W(0X9D8, ctx->r1) = ctx->r21;
L_8006904C:
    // bne         $v0, $zero, L_80069068
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80069068;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80069820
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    CD_sync(rdram, ctx);
    goto after_3;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_3:
    // xori        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 ^ 0X2;
    // j           L_8006906C
    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    goto L_8006906C;
    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80069068:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006906C:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(0X30, ctx->r29);
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
    // jr          $ra
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
