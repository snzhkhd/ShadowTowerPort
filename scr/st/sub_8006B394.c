#include "recomp.h"
#include "disable_warnings.h"

void sub_8006B394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, 0xD04
    ctx->r5 = ADD32(ctx->r5, 0XD04);
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // sw          $s1, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r17;
    // bne         $a0, $v0, L_8006B4E8
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8006B4E8;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(0X14, ctx->r5);
    // nop

    // blez        $v0, L_8006B4EC
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8006B4EC;
    }
    // nop

    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // bne         $v1, $v0, L_8006B468
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8006B468;
    }
    // nop

    // lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(0X30, ctx->r5);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8006B428
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_8006B428;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // jal         0x800690FC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdDataCallback(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // jal         0x800690DC
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    CdGetSector2(rdram, ctx);
    goto after_1;
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // jal         0x80069120
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdDataSync(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // jal         0x800690FC
    // addiu       $a0, $a0, -0x4A0C
    ctx->r4 = ADD32(ctx->r4, -0X4A0C);
    CdDataCallback(rdram, ctx);
    goto after_3;
    // addiu       $a0, $a0, -0x4A0C
    ctx->r4 = ADD32(ctx->r4, -0X4A0C);
    after_3:
    // j           L_8006B430
    // nop

    goto L_8006B430;
    // nop

L_8006B428:
    // jal         0x800690BC
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    CdGetSector(rdram, ctx);
    goto after_4;
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
L_8006B430:
    // jal         0x80069244
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    CdPosToInt(rdram, ctx);
    goto after_5;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_5:
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0xD24
    ctx->r16 = ADD32(ctx->r16, 0XD24);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // nop

    // beq         $v0, $v1, L_8006B468
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_8006B468;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078A3C
    // addiu       $a0, $a0, 0x3E00
    ctx->r4 = ADD32(ctx->r4, 0X3E00);
    sub_80078A3C(rdram, ctx);
    goto after_6;
    // addiu       $a0, $a0, 0x3E00
    ctx->r4 = ADD32(ctx->r4, 0X3E00);
    after_6:
    // addiu       $v1, $s0, -0x20
    ctx->r3 = ADD32(ctx->r16, -0X20);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_8006B468:
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0xD34
    ctx->r16 = ADD32(ctx->r16, 0XD34);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8006B49C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006B49C;
    }
    // nop

    // lw          $a0, -0x28($s0)
    ctx->r4 = MEM_W(-0X28, ctx->r16);
    // lw          $a1, -0x20($s0)
    ctx->r5 = MEM_W(-0X20, ctx->r16);
    // jal         0x800690DC
    // nop

    CdGetSector2(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // j           L_8006B4EC
    // nop

    goto L_8006B4EC;
    // nop

L_8006B49C:
    // lw          $a0, -0x28($s0)
    ctx->r4 = MEM_W(-0X28, ctx->r16);
    // lw          $a1, -0x20($s0)
    ctx->r5 = MEM_W(-0X20, ctx->r16);
    // jal         0x800690BC
    // nop

    CdGetSector(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // addiu       $a0, $s0, -0x30
    ctx->r4 = ADD32(ctx->r16, -0X30);
    // lw          $v0, -0x20($s0)
    ctx->r2 = MEM_W(-0X20, ctx->r16);
    // lw          $v1, -0x28($s0)
    ctx->r3 = MEM_W(-0X28, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(0X14, ctx->r4);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(0X20, ctx->r4);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8006B4EC
    // sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
    goto L_8006B4EC;
    // sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
L_8006B4E8:
    // sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
L_8006B4EC:
    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    VSync(rdram, ctx);
    goto after_9;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_9:
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0xD04
    ctx->r16 = ADD32(ctx->r16, 0XD04);
    // sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // nop

    // bgez        $v0, L_8006B518
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8006B518;
    }
    // nop

    // jal         0x8006B6C0
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sub_8006B6C0(rdram, ctx);
    goto after_10;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
L_8006B518:
    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    VSync(rdram, ctx);
    goto after_11;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_11:
    // lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(0X1C, ctx->r16);
    // nop

    // addiu       $v1, $v1, 0x4B0
    ctx->r3 = ADD32(ctx->r3, 0X4B0);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8006B53C
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8006B53C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
L_8006B53C:
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8006B56C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006B56C;
    }
    // nop

    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    VSync(rdram, ctx);
    goto after_12;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_12:
    // lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(0X1C, ctx->r16);
    // nop

    // addiu       $v1, $v1, 0x4B0
    ctx->r3 = ADD32(ctx->r3, 0X4B0);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8006B5E0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8006B5E0;
    }
    // nop

L_8006B56C:
    // lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(0X24, ctx->r16);
    // jal         0x80068CB8
    // nop

    CdSyncCallback(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(0X28, ctx->r16);
    // jal         0x80068CCC
    // nop

    CdReadyCallback(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8006B5A8
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
        goto L_8006B5A8;
    }
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // jal         0x800690FC
    // nop

    CdDataCallback(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_8006B5A8:
    // jal         0x80068E1C
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    CdControlF(rdram, ctx);
    goto after_16;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_16:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD00($v1)
    ctx->r3 = MEM_W(0XD00, ctx->r3);
    // nop

    // beq         $v1, $zero, L_8006B5E0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8006B5E0;
    }
    // nop

    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8006B5D8
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
        goto L_8006B5D8;
    }
    // addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8006B5D8:
    // jalr        $v1
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
    goto after_17;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_17:
L_8006B5E0:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
