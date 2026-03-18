#include "recomp.h"
#include "disable_warnings.h"

void sub_8006BF24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, 0xD58($v1)
    ctx->r3 = MEM_HU(0XD58, ctx->r3);
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lhu         $a1, 0x1AE($v0)
    ctx->r5 = MEM_HU(0X1AE, ctx->r2);
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sh          $v1, 0x1A6($v0)
    MEM_H(0X1A6, ctx->r2) = ctx->r3;
    // jal         0x8006C77C
    // andi        $s3, $a1, 0x7FF
    ctx->r19 = ctx->r5 & 0X7FF;
    _spu_Fw1ts(rdram, ctx);
    goto after_0;
    // andi        $s3, $a1, 0x7FF
    ctx->r19 = ctx->r5 & 0X7FF;
    after_0:
    // beq         $s1, $zero, L_8006C04C
    if (ctx->r17 == 0) {
        // sltiu       $v0, $s1, 0x41
        ctx->r2 = ctx->r17 < 0X41 ? 1 : 0;
        goto L_8006C04C;
    }
    // sltiu       $v0, $s1, 0x41
    ctx->r2 = ctx->r17 < 0X41 ? 1 : 0;
L_8006BF6C:
    // beq         $v0, $zero, L_8006BF78
    if (ctx->r2 == 0) {
        // addiu       $s0, $zero, 0x40
        ctx->r16 = ADD32(0, 0X40);
        goto L_8006BF78;
    }
    // addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_8006BF78:
    // blez        $s0, L_8006BFA4
    if (SIGNED(ctx->r16) <= 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8006BFA4;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD40($a0)
    ctx->r4 = MEM_W(0XD40, ctx->r4);
L_8006BF88:
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // sh          $v0, 0x1A8($a0)
    MEM_H(0X1A8, ctx->r4) = ctx->r2;
    // slt         $v0, $v1, $s0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // bne         $v0, $zero, L_8006BF88
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006BF88;
    }
    // nop

L_8006BFA4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $a0, 0x1AA($v1)
    ctx->r4 = MEM_HU(0X1AA, ctx->r3);
    // nop

    // andi        $v0, $a0, 0xFFCF
    ctx->r2 = ctx->r4 & 0XFFCF;
    // ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // jal         0x8006C77C
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
    _spu_Fw1ts(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
    after_1:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // nop

    // lhu         $v0, 0x1AE($v0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // beq         $v0, $zero, L_8006C034
    if (ctx->r2 == 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8006C034;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006BFEC:
    // sltiu       $v0, $v1, 0xF01
    ctx->r2 = ctx->r3 < 0XF01 ? 1 : 0;
    // bne         $v0, $zero, L_8006C014
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006C014;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3E50
    ctx->r4 = ADD32(ctx->r4, 0X3E50);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a1, $a1, 0x3E70
    ctx->r5 = ADD32(ctx->r5, 0X3E70);
    printf(rdram, ctx);
    goto after_2;
    // addiu       $a1, $a1, 0x3E70
    ctx->r5 = ADD32(ctx->r5, 0X3E70);
    after_2:
    // j           L_8006C034
    // nop

    goto L_8006C034;
    // nop

L_8006C014:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // nop

    // lhu         $v0, 0x1AE($v0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // bne         $v0, $zero, L_8006BFEC
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8006BFEC;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006C034:
    // jal         0x8006C77C
    // subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    _spu_Fw1ts(rdram, ctx);
    goto after_3;
    // subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    after_3:
    // jal         0x8006C77C
    // nop

    _spu_Fw1ts(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // bne         $s1, $zero, L_8006BF6C
    if (ctx->r17 != 0) {
        // sltiu       $v0, $s1, 0x41
        ctx->r2 = ctx->r17 < 0X41 ? 1 : 0;
        goto L_8006BF6C;
    }
    // sltiu       $v0, $s1, 0x41
    ctx->r2 = ctx->r17 < 0X41 ? 1 : 0;
L_8006C04C:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // nop

    // lhu         $a0, 0x1AA($v0)
    ctx->r4 = MEM_HU(0X1AA, ctx->r2);
    // andi        $a1, $s3, 0xFFFF
    ctx->r5 = ctx->r19 & 0XFFFF;
    // andi        $v1, $a0, 0xFFCF
    ctx->r3 = ctx->r4 & 0XFFCF;
    // sh          $v1, 0x1AA($v0)
    MEM_H(0X1AA, ctx->r2) = ctx->r3;
    // lhu         $v0, 0x1AE($v0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // beq         $v0, $a1, L_8006C0C8
    if (ctx->r2 == ctx->r5) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8006C0C8;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006C080:
    // sltiu       $v0, $v1, 0xF01
    ctx->r2 = ctx->r3 < 0XF01 ? 1 : 0;
    // bne         $v0, $zero, L_8006C0A8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006C0A8;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3E50
    ctx->r4 = ADD32(ctx->r4, 0X3E50);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a1, $a1, 0x3E84
    ctx->r5 = ADD32(ctx->r5, 0X3E84);
    printf(rdram, ctx);
    goto after_5;
    // addiu       $a1, $a1, 0x3E84
    ctx->r5 = ADD32(ctx->r5, 0X3E84);
    after_5:
    // j           L_8006C0C8
    // nop

    goto L_8006C0C8;
    // nop

L_8006C0A8:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // nop

    // lhu         $v0, 0x1AE($v0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // bne         $v0, $a1, L_8006C080
    if (ctx->r2 != ctx->r5) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8006C080;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006C0C8:
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
