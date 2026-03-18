#include "recomp.h"
#include "disable_warnings.h"

void sub_8002732C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lbu         $v0, 0x3($s7)
    ctx->r2 = MEM_BU(0X3, ctx->r23);
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // andi        $v0, $v0, 0x7C
    ctx->r2 = ctx->r2 & 0X7C;
    // srl         $s4, $v0, 2
    ctx->r20 = S32(U32(ctx->r2) >> 2);
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // lbu         $v0, 0x2E5($v0)
    ctx->r2 = MEM_BU(0X2E5, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80027394
    if (ctx->r2 != 0) {
        // addu        $fp, $a1, $zero
        ctx->r30 = ADD32(ctx->r5, 0);
        goto L_80027394;
    }
    // addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // addiu       $s5, $zero, 0xE
    ctx->r21 = ADD32(0, 0XE);
    // j           L_800273A0
    // addiu       $s3, $zero, 0x40
    ctx->r19 = ADD32(0, 0X40);
    goto L_800273A0;
    // addiu       $s3, $zero, 0x40
    ctx->r19 = ADD32(0, 0X40);
L_80027394:
    // addiu       $s4, $zero, 0xB
    ctx->r20 = ADD32(0, 0XB);
    // addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
    // addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_800273A0:
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8002740C
    if (ctx->r3 == ctx->r2) {
        // srl         $s6, $s4, 1
        ctx->r22 = S32(U32(ctx->r20) >> 1);
        goto L_8002740C;
    }
    // srl         $s6, $s4, 1
    ctx->r22 = S32(U32(ctx->r20) >> 1);
L_800273B0:
    // bne         $v1, $zero, L_800273C8
    if (ctx->r3 != 0) {
        // andi        $a1, $s1, 0xFFFF
        ctx->r5 = ctx->r17 & 0XFFFF;
        goto L_800273C8;
    }
    // andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // addu        $s1, $fp, $zero
    ctx->r17 = ADD32(ctx->r30, 0);
    // addu        $s2, $s2, $s5
    ctx->r18 = ADD32(ctx->r18, ctx->r21);
    // j           L_800273FC
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    goto L_800273FC;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800273C8:
    // andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // jal         0x80026ECC
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    sub_80026ECC(rdram, ctx);
    goto after_0;
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    after_0:
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // sltu        $v0, $v0, $s3
    ctx->r2 = ctx->r2 < ctx->r19 ? 1 : 0;
    // beq         $v0, $zero, L_800273F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800273F4;
    }
    // nop

    // j           L_800273F8
    // addu        $s1, $s1, $s6
    ctx->r17 = ADD32(ctx->r17, ctx->r22);
    goto L_800273F8;
    // addu        $s1, $s1, $s6
    ctx->r17 = ADD32(ctx->r17, ctx->r22);
L_800273F4:
    // addu        $s1, $s1, $s4
    ctx->r17 = ADD32(ctx->r17, ctx->r20);
L_800273F8:
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800273FC:
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $v1, $v0, L_800273B0
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800273B0;
    }
    // nop

L_8002740C:
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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
