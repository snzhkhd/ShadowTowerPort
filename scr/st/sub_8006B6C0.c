#include "recomp.h"
#include "disable_warnings.h"

void sub_8006B6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x80068CB8
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    CdSyncCallback(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // jal         0x80068CCC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdReadyCallback(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0xD34
    ctx->r16 = ADD32(ctx->r16, 0XD34);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8006B70C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006B70C;
    }
    // nop

    // jal         0x800690FC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdDataCallback(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
L_8006B70C:
    // jal         0x80068B34
    // nop

    CdStatus(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8006B770
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006B770;
    }
    // nop

    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    VSync(rdram, ctx);
    goto after_4;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_4:
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // bne         $v0, $zero, L_8006B744
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_8006B744;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078A3C
    // addiu       $a0, $a0, 0x3E18
    ctx->r4 = ADD32(ctx->r4, 0X3E18);
    sub_80078A3C(rdram, ctx);
    goto after_5;
    // addiu       $a0, $a0, 0x3E18
    ctx->r4 = ADD32(ctx->r4, 0X3E18);
    after_5:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8006B744:
    // jal         0x80068E1C
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    CdControlF(rdram, ctx);
    goto after_6;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_6:
    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    VSync(rdram, ctx);
    goto after_7;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_7:
    // addiu       $v1, $s0, -0x30
    ctx->r3 = ADD32(ctx->r16, -0X30);
    // sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(0X14, ctx->r3);
    // j           L_8006B898
    // nop

    goto L_8006B898;
    // nop

L_8006B770:
    // beq         $s2, $zero, L_8006B7C8
    if (ctx->r18 == 0) {
        // nop
    
        goto L_8006B7C8;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078A3C
    // addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    sub_80078A3C(rdram, ctx);
    goto after_8;
    // addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    after_8:
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_9;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_9:
    // jal         0x80068B64
    // nop

    CdLastPos(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_11;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_11:
    // bne         $v0, $zero, L_8006B7C8
    if (ctx->r2 != 0) {
        // addiu       $v0, $s0, -0x30
        ctx->r2 = ADD32(ctx->r16, -0X30);
        goto L_8006B7C8;
    }
    // addiu       $v0, $s0, -0x30
    ctx->r2 = ADD32(ctx->r16, -0X30);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // lw          $v0, -0x1C($s0)
    ctx->r2 = MEM_W(-0X1C, ctx->r16);
    // j           L_8006B898
    // nop

    goto L_8006B898;
    // nop

L_8006B7C8:
    // jal         0x80068BDC
    // nop

    CdFlush(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // addiu       $s1, $s1, 0xD10
    ctx->r17 = ADD32(ctx->r17, 0XD10);
    // lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(0X0, ctx->r17);
    // nop

    // sb          $s0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r16;
    // jal         0x80068B44
    // andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    CdMode(rdram, ctx);
    goto after_13;
    // andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    after_13:
    // bne         $s0, $v0, L_8006B7FC
    if (ctx->r16 != ctx->r2) {
        // addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
        goto L_8006B7FC;
    }
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // beq         $s2, $zero, L_8006B824
    if (ctx->r18 == 0) {
        // nop
    
        goto L_8006B824;
    }
    // nop

L_8006B7FC:
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_14;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_14:
    // bne         $v0, $zero, L_8006B824
    if (ctx->r2 != 0) {
        // addiu       $v0, $s1, -0xC
        ctx->r2 = ADD32(ctx->r17, -0XC);
        goto L_8006B824;
    }
    // addiu       $v0, $s1, -0xC
    ctx->r2 = ADD32(ctx->r17, -0XC);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(0X14, ctx->r2);
    // j           L_8006B898
    // nop

    goto L_8006B898;
    // nop

L_8006B824:
    // jal         0x80068B64
    // nop

    CdLastPos(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // jal         0x80069244
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    CdPosToInt(rdram, ctx);
    goto after_16;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_16:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // addiu       $a0, $a0, -0x4C6C
    ctx->r4 = ADD32(ctx->r4, -0X4C6C);
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0xD04
    ctx->r16 = ADD32(ctx->r16, 0XD04);
    // jal         0x80068CCC
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    CdReadyCallback(rdram, ctx);
    goto after_17;
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    after_17:
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8006B870
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
        goto L_8006B870;
    }
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // jal         0x800690FC
    // addiu       $a0, $a0, -0x4A0C
    ctx->r4 = ADD32(ctx->r4, -0X4A0C);
    CdDataCallback(rdram, ctx);
    goto after_18;
    // addiu       $a0, $a0, -0x4A0C
    ctx->r4 = ADD32(ctx->r4, -0X4A0C);
    after_18:
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_8006B870:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80068E1C
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    CdControlF(rdram, ctx);
    goto after_19;
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    after_19:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // jal         0x80077104
    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    VSync(rdram, ctx);
    goto after_20;
    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    after_20:
    // sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
L_8006B898:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
