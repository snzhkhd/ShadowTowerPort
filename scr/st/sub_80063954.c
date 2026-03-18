#include "recomp.h"
#include "disable_warnings.h"

void sub_80063954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, -0x7F0C
    ctx->r6 = ADD32(ctx->r2, -0X7F0C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // swl         $a0, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r4);
    // swr         $a0, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7F04
    ctx->r6 = ADD32(ctx->r2, -0X7F04);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // swl         $a0, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r4);
    // swr         $a0, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7EFC
    ctx->r6 = ADD32(ctx->r2, -0X7EFC);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r3);
    // swr         $v1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r3);
    // swl         $a0, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r4);
    // swr         $a0, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r4);
    // jal         0x800636F8
    // nop

    sub_800636F8(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(0X0, ctx->r4);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $a0, 0xD08($v0)
    ctx->r4 = MEM_W(0XD08, ctx->r2);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0xD28($v1)
    ctx->r2 = MEM_HU(0XD28, ctx->r3);
    // lhu         $a0, 0x3E($a1)
    ctx->r4 = MEM_HU(0X3E, ctx->r5);
    // nop

    // beq         $v0, $a0, L_80063A30
    if (ctx->r2 == ctx->r4) {
        // addiu       $v1, $v1, 0xD28
        ctx->r3 = ADD32(ctx->r3, 0XD28);
        goto L_80063A30;
    }
    // addiu       $v1, $v1, 0xD28
    ctx->r3 = ADD32(ctx->r3, 0XD28);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $a0, $v0, L_80063ABC
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_80063ABC;
    }
    // nop

L_80063A30:
    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // lhu         $a0, 0x58($a1)
    ctx->r4 = MEM_HU(0X58, ctx->r5);
    // nop

    // beq         $v0, $a0, L_80063A4C
    if (ctx->r2 == ctx->r4) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80063A4C;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $a0, $v0, L_80063ABC
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_80063ABC;
    }
    // nop

L_80063A4C:
    // lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(0X2, ctx->r3);
    // lhu         $a0, 0x40($a1)
    ctx->r4 = MEM_HU(0X40, ctx->r5);
    // nop

    // beq         $v0, $a0, L_80063A68
    if (ctx->r2 == ctx->r4) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80063A68;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $a0, $v0, L_80063ABC
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_80063ABC;
    }
    // nop

L_80063A68:
    // lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(0X6, ctx->r3);
    // lhu         $a0, 0x5A($a1)
    ctx->r4 = MEM_HU(0X5A, ctx->r5);
    // nop

    // beq         $v0, $a0, L_80063A84
    if (ctx->r2 == ctx->r4) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80063A84;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $a0, $v0, L_80063ABC
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_80063ABC;
    }
    // nop

L_80063A84:
    // lhu         $v0, 0x8($v1)
    ctx->r2 = MEM_HU(0X8, ctx->r3);
    // lhu         $a0, 0x44($a1)
    ctx->r4 = MEM_HU(0X44, ctx->r5);
    // nop

    // beq         $v0, $a0, L_80063AA0
    if (ctx->r2 == ctx->r4) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80063AA0;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $a0, $v0, L_80063ABC
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_80063ABC;
    }
    // nop

L_80063AA0:
    // lhu         $v0, 0xA($v1)
    ctx->r2 = MEM_HU(0XA, ctx->r3);
    // lhu         $v1, 0x50($a1)
    ctx->r3 = MEM_HU(0X50, ctx->r5);
    // nop

    // beq         $v0, $v1, L_80063AC4
    if (ctx->r2 == ctx->r3) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80063AC4;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80063AC4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80063AC4;
    }
    // nop

L_80063ABC:
    // jal         0x80021158
    // nop

    sub_80021158(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_80063AC4:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0xD28($a0)
    ctx->r3 = MEM_HU(0XD28, ctx->r4);
    // lhu         $v0, 0x3E($s0)
    ctx->r2 = MEM_HU(0X3E, ctx->r16);
    // nop

    // bne         $v1, $v0, L_80063AF8
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $a0, 0xD28
        ctx->r4 = ADD32(ctx->r4, 0XD28);
        goto L_80063AF8;
    }
    // addiu       $a0, $a0, 0xD28
    ctx->r4 = ADD32(ctx->r4, 0XD28);
    // lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(0X2, ctx->r4);
    // lhu         $v0, 0x40($s0)
    ctx->r2 = MEM_HU(0X40, ctx->r16);
    // nop

    // beq         $v1, $v0, L_80063B1C
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80063B1C;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_80063AF8:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lhu         $a0, 0x3E($s0)
    ctx->r4 = MEM_HU(0X3E, ctx->r16);
    // jal         0x8003F12C
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_8003F12C(rdram, ctx);
    goto after_4;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // lhu         $a0, 0x40($s0)
    ctx->r4 = MEM_HU(0X40, ctx->r16);
    // jal         0x8003F12C
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_8003F12C(rdram, ctx);
    goto after_5;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_80063B1C:
    // addiu       $a0, $v0, 0xD28
    ctx->r4 = ADD32(ctx->r2, 0XD28);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(0X4, ctx->r4);
    // lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(0X58, ctx->r16);
    // nop

    // bne         $v1, $v0, L_80063B50
    if (ctx->r3 != ctx->r2) {
        // addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
        goto L_80063B50;
    }
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(0X6, ctx->r4);
    // lhu         $v0, 0x5A($s0)
    ctx->r2 = MEM_HU(0X5A, ctx->r16);
    // nop

    // beq         $v1, $v0, L_80063B70
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80063B70;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_80063B50:
    // lhu         $a0, 0x58($s0)
    ctx->r4 = MEM_HU(0X58, ctx->r16);
    // jal         0x8003F12C
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_8003F12C(rdram, ctx);
    goto after_6;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_6:
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // lhu         $a0, 0x5A($s0)
    ctx->r4 = MEM_HU(0X5A, ctx->r16);
    // jal         0x8003F12C
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_8003F12C(rdram, ctx);
    goto after_7;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_80063B70:
    // addiu       $s1, $v0, 0xD28
    ctx->r17 = ADD32(ctx->r2, 0XD28);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(0X8, ctx->r17);
    // lhu         $v0, 0x44($s0)
    ctx->r2 = MEM_HU(0X44, ctx->r16);
    // nop

    // beq         $v1, $v0, L_80063B98
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
        goto L_80063B98;
    }
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // jal         0x8003EE38
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_8003EE38(rdram, ctx);
    goto after_8;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_8:
L_80063B98:
    // lhu         $v1, 0xA($s1)
    ctx->r3 = MEM_HU(0XA, ctx->r17);
    // lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(0X50, ctx->r16);
    // nop

    // beq         $v1, $v0, L_80063BB4
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
        goto L_80063BB4;
    }
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // jal         0x8003EE38
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_8003EE38(rdram, ctx);
    goto after_9;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_80063BB4:
    // jal         0x800214A4
    // nop

    sub_800214A4(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $v0, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r2;
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
