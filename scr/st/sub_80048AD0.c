#include "recomp.h"
#include "disable_warnings.h"

void sub_80048AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x1838
    ctx->r29 = ADD32(ctx->r29, -0X1838);
    // sw          $s6, 0x1828($sp)
    MEM_W(0X1828, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x1830($sp)
    MEM_W(0X1830, ctx->r29) = ctx->r31;
    // sw          $s7, 0x182C($sp)
    MEM_W(0X182C, ctx->r29) = ctx->r23;
    // sw          $s5, 0x1824($sp)
    MEM_W(0X1824, ctx->r29) = ctx->r21;
    // sw          $s4, 0x1820($sp)
    MEM_W(0X1820, ctx->r29) = ctx->r20;
    // sw          $s3, 0x181C($sp)
    MEM_W(0X181C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x1818($sp)
    MEM_W(0X1818, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1814($sp)
    MEM_W(0X1814, ctx->r29) = ctx->r17;
    // sw          $s0, 0x1810($sp)
    MEM_W(0X1810, ctx->r29) = ctx->r16;
    // lw          $v0, 0x30C($v0)
    ctx->r2 = MEM_W(0X30C, ctx->r2);
    // lui         $s4, 0x1F80
    ctx->r20 = S32(0X1F80 << 16);
    // sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // lw          $v0, 0x4($s6)
    ctx->r2 = MEM_W(0X4, ctx->r22);
    // nop

    // sw          $v0, 0xE4($s4)
    MEM_W(0XE4, ctx->r20) = ctx->r2;
    // lw          $v0, 0x8($s6)
    ctx->r2 = MEM_W(0X8, ctx->r22);
    // nop

    // sw          $v0, 0xE8($s4)
    MEM_W(0XE8, ctx->r20) = ctx->r2;
    // lw          $v0, 0xC($s6)
    ctx->r2 = MEM_W(0XC, ctx->r22);
    // nop

    // sw          $v0, 0xEC($s4)
    MEM_W(0XEC, ctx->r20) = ctx->r2;
    // lh          $v1, 0x14($s6)
    ctx->r3 = MEM_HS(0X14, ctx->r22);
    // lw          $v0, 0x4($s6)
    ctx->r2 = MEM_W(0X4, ctx->r22);
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xF4($s4)
    MEM_W(0XF4, ctx->r20) = ctx->r2;
    // lh          $v1, 0x16($s6)
    ctx->r3 = MEM_HS(0X16, ctx->r22);
    // lw          $v0, 0x8($s6)
    ctx->r2 = MEM_W(0X8, ctx->r22);
    // ori         $a0, $a0, 0xE4
    ctx->r4 = ctx->r4 | 0XE4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xF8($s4)
    MEM_W(0XF8, ctx->r20) = ctx->r2;
    // lh          $v1, 0x18($s6)
    ctx->r3 = MEM_HS(0X18, ctx->r22);
    // lw          $v0, 0xC($s6)
    ctx->r2 = MEM_W(0XC, ctx->r22);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xFC($s4)
    MEM_W(0XFC, ctx->r20) = ctx->r2;
    // lw          $v0, 0x4($s6)
    ctx->r2 = MEM_W(0X4, ctx->r22);
    // ori         $a1, $a1, 0xF4
    ctx->r5 = ctx->r5 | 0XF4;
    // sw          $v0, 0x104($s4)
    MEM_W(0X104, ctx->r20) = ctx->r2;
    // lhu         $v1, 0x1E($s6)
    ctx->r3 = MEM_HU(0X1E, ctx->r22);
    // lw          $v0, 0x8($s6)
    ctx->r2 = MEM_W(0X8, ctx->r22);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, -0x403
    ctx->r2 = ADD32(ctx->r2, -0X403);
    // sw          $v0, 0x108($s4)
    MEM_W(0X108, ctx->r20) = ctx->r2;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v1, 0xC($s6)
    ctx->r3 = MEM_W(0XC, ctx->r22);
    // addiu       $s0, $v0, 0x5948
    ctx->r16 = ADD32(ctx->r2, 0X5948);
    // sh          $zero, 0x44CA($s0)
    MEM_H(0X44CA, ctx->r16) = 0;
    // jal         0x80046270
    // sw          $v1, 0x10C($s4)
    MEM_W(0X10C, ctx->r20) = ctx->r3;
    sub_80046270(rdram, ctx);
    goto after_0;
    // sw          $v1, 0x10C($s4)
    MEM_W(0X10C, ctx->r20) = ctx->r3;
    after_0:
    // lhu         $v0, 0x44CA($s0)
    ctx->r2 = MEM_HU(0X44CA, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80048BD8
    if (ctx->r2 != 0) {
        // addu        $s7, $zero, $zero
        ctx->r23 = ADD32(0, 0);
        goto L_80048BD8;
    }
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // addu        $v0, $s7, $zero
    ctx->r2 = ADD32(ctx->r23, 0);
    // lui         $v1, 0x8
    ctx->r3 = S32(0X8 << 16);
    // sw          $v1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r3;
    // j           L_800492C4
    // sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
    goto L_800492C4;
    // sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
L_80048BD8:
    // jal         0x8004656C
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    sub_8004656C(rdram, ctx);
    goto after_1;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $v0, $s0, 0xC0
    ctx->r2 = ADD32(ctx->r16, 0XC0);
    // sw          $v0, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r2;
    // addiu       $v0, $s0, 0x11C0
    ctx->r2 = ADD32(ctx->r16, 0X11C0);
    // sw          $v0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r2;
    // addiu       $v0, $s0, 0x22C0
    ctx->r2 = ADD32(ctx->r16, 0X22C0);
    // sw          $v0, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->r2;
    // addiu       $v0, $s0, 0x33C0
    ctx->r2 = ADD32(ctx->r16, 0X33C0);
    // jal         0x80046604
    // sw          $v0, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->r2;
    sub_80046604(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->r2;
    after_2:
    // lh          $a0, 0x20($s6)
    ctx->r4 = MEM_HS(0X20, ctx->r22);
    // addiu       $v0, $zero, 0x270F
    ctx->r2 = ADD32(0, 0X270F);
    // bne         $a0, $v0, L_80048CC4
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_80048CC4;
    }
    // nop

    // lh          $v0, 0x14($s6)
    ctx->r2 = MEM_HS(0X14, ctx->r22);
    // nop

    // bne         $v0, $zero, L_80048C54
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80048C54;
    }
    // nop

    // lh          $v0, 0x18($s6)
    ctx->r2 = MEM_HS(0X18, ctx->r22);
    // nop

    // bne         $v0, $zero, L_80048C54
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80048C54;
    }
    // nop

    // sh          $zero, 0x148($s4)
    MEM_H(0X148, ctx->r20) = 0;
    // lhu         $v0, 0x16($s6)
    ctx->r2 = MEM_HU(0X16, ctx->r22);
    // lhu         $v1, 0x1E($s6)
    ctx->r3 = MEM_HU(0X1E, ctx->r22);
    // sh          $zero, 0x14C($s4)
    MEM_H(0X14C, ctx->r20) = 0;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_80048D3C
    // sh          $v0, 0x14A($s4)
    MEM_H(0X14A, ctx->r20) = ctx->r2;
    goto L_80048D3C;
    // sh          $v0, 0x14A($s4)
    MEM_H(0X14A, ctx->r20) = ctx->r2;
L_80048C54:
    // lh          $a0, 0x18($s6)
    ctx->r4 = MEM_HS(0X18, ctx->r22);
    // lh          $a1, 0x14($s6)
    ctx->r5 = MEM_HS(0X14, ctx->r22);
    // jal         0x80076EA4
    // nop

    ratan2(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x800744C4
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    rcos(rdram, ctx);
    goto after_4;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_4:
    // lhu         $v1, 0x1C($s6)
    ctx->r3 = MEM_HU(0X1C, ctx->r22);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80048C88
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80048C88;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80048C88:
    // lhu         $v0, 0x14($s6)
    ctx->r2 = MEM_HU(0X14, ctx->r22);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x148($s4)
    MEM_H(0X148, ctx->r20) = ctx->r2;
    // lhu         $v0, 0x16($s6)
    ctx->r2 = MEM_HU(0X16, ctx->r22);
    // lhu         $v1, 0x1E($s6)
    ctx->r3 = MEM_HU(0X1E, ctx->r22);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x14A($s4)
    MEM_H(0X14A, ctx->r20) = ctx->r2;
    // lh          $a0, 0x18($s6)
    ctx->r4 = MEM_HS(0X18, ctx->r22);
    // lh          $a1, 0x14($s6)
    ctx->r5 = MEM_HS(0X14, ctx->r22);
    // jal         0x80076EA4
    // nop

    ratan2(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // j           L_80048D08
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    goto L_80048D08;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80048CC4:
    // jal         0x800744C4
    // nop

    rcos(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lhu         $v1, 0x1C($s6)
    ctx->r3 = MEM_HU(0X1C, ctx->r22);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80048CE8
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80048CE8;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80048CE8:
    // lhu         $v0, 0x14($s6)
    ctx->r2 = MEM_HU(0X14, ctx->r22);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x148($s4)
    MEM_H(0X148, ctx->r20) = ctx->r2;
    // lhu         $v0, 0x16($s6)
    ctx->r2 = MEM_HU(0X16, ctx->r22);
    // nop

    // sh          $v0, 0x14A($s4)
    MEM_H(0X14A, ctx->r20) = ctx->r2;
    // lh          $a0, 0x20($s6)
    ctx->r4 = MEM_HS(0X20, ctx->r22);
L_80048D08:
    // jal         0x800743F4
    // nop

    rsin(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lhu         $v1, 0x1C($s6)
    ctx->r3 = MEM_HU(0X1C, ctx->r22);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80048D2C
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80048D2C;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80048D2C:
    // lhu         $v0, 0x18($s6)
    ctx->r2 = MEM_HU(0X18, ctx->r22);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x14C($s4)
    MEM_H(0X14C, ctx->r20) = ctx->r2;
L_80048D3C:
    // lui         $s5, 0x8
    ctx->r21 = S32(0X8 << 16);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $v0, 0x22($s4)
    MEM_H(0X22, ctx->r20) = ctx->r2;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, 0x5948
    ctx->r2 = ADD32(ctx->r2, 0X5948);
    // addiu       $s3, $v0, 0xC0
    ctx->r19 = ADD32(ctx->r2, 0XC0);
    // addiu       $s2, $v0, 0x11C0
    ctx->r18 = ADD32(ctx->r2, 0X11C0);
    // addiu       $s1, $v0, 0x22C0
    ctx->r17 = ADD32(ctx->r2, 0X22C0);
    // sw          $s5, 0x124($s4)
    MEM_W(0X124, ctx->r20) = ctx->r21;
    // sw          $s5, 0x144($s4)
    MEM_W(0X144, ctx->r20) = ctx->r21;
    // sw          $s5, 0x138($s4)
    MEM_W(0X138, ctx->r20) = ctx->r21;
    // sw          $s5, 0x120($s4)
    MEM_W(0X120, ctx->r20) = ctx->r21;
    // sw          $s5, 0x11C($s4)
    MEM_W(0X11C, ctx->r20) = ctx->r21;
    // sw          $s5, 0x118($s4)
    MEM_W(0X118, ctx->r20) = ctx->r21;
    // sw          $s5, 0x114($s4)
    MEM_W(0X114, ctx->r20) = ctx->r21;
    // sw          $s5, 0x128($s4)
    MEM_W(0X128, ctx->r20) = ctx->r21;
    // sw          $s5, 0x12C($s4)
    MEM_W(0X12C, ctx->r20) = ctx->r21;
    // sw          $s5, 0x130($s4)
    MEM_W(0X130, ctx->r20) = ctx->r21;
    // sw          $s5, 0x134($s4)
    MEM_W(0X134, ctx->r20) = ctx->r21;
    // sw          $zero, 0x198($s4)
    MEM_W(0X198, ctx->r20) = 0;
    // sw          $s3, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r19;
    // sw          $s2, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r18;
    // sw          $s1, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->r17;
    // lhu         $v1, 0x44CE($v0)
    ctx->r3 = MEM_HU(0X44CE, ctx->r2);
    // addiu       $s0, $v0, 0x33C0
    ctx->r16 = ADD32(ctx->r2, 0X33C0);
    // sw          $s0, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->r16;
    // sw          $v1, 0x47D8($v0)
    MEM_W(0X47D8, ctx->r2) = ctx->r3;
    // lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(0X0, ctx->r22);
    // jal         0x800468C0
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    sub_800468C0(rdram, ctx);
    goto after_8;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_8:
    // sw          $s3, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r19;
    // sw          $s2, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r18;
    // sw          $s1, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->r17;
    // sw          $s0, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->r16;
    // lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(0X0, ctx->r22);
    // jal         0x80047884
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    sub_80047884(rdram, ctx);
    goto after_9;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_9:
    // lw          $v0, 0x128($s4)
    ctx->r2 = MEM_W(0X128, ctx->r20);
    // nop

    // bne         $v0, $s5, L_80048E0C
    if (ctx->r2 != ctx->r21) {
        // nop
    
        goto L_80048E0C;
    }
    // nop

    // lwl         $v0, 0x17B($s4)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X17B, ctx->r20);
    // lwr         $v0, 0x178($s4)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X178, ctx->r20);
    // lwl         $v1, 0x17F($s4)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X17F, ctx->r20);
    // lwr         $v1, 0x17C($s4)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X17C, ctx->r20);
    // swl         $v0, 0x173($s4)
    do_swl(rdram, 0X173, ctx->r20, ctx->r2);
    // swr         $v0, 0x170($s4)
    do_swr(rdram, 0X170, ctx->r20, ctx->r2);
    // swl         $v1, 0x177($s4)
    do_swl(rdram, 0X177, ctx->r20, ctx->r3);
    // swr         $v1, 0x174($s4)
    do_swr(rdram, 0X174, ctx->r20, ctx->r3);
    // lw          $v0, 0x12C($s4)
    ctx->r2 = MEM_W(0X12C, ctx->r20);
    // nop

    // sw          $v0, 0x128($s4)
    MEM_W(0X128, ctx->r20) = ctx->r2;
L_80048E0C:
    // lw          $v0, 0x130($s4)
    ctx->r2 = MEM_W(0X130, ctx->r20);
    // nop

    // bne         $v0, $s5, L_80048E48
    if (ctx->r2 != ctx->r21) {
        // nop
    
        goto L_80048E48;
    }
    // nop

    // lwl         $v0, 0x18B($s4)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X18B, ctx->r20);
    // lwr         $v0, 0x188($s4)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X188, ctx->r20);
    // lwl         $v1, 0x18F($s4)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X18F, ctx->r20);
    // lwr         $v1, 0x18C($s4)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X18C, ctx->r20);
    // swl         $v0, 0x183($s4)
    do_swl(rdram, 0X183, ctx->r20, ctx->r2);
    // swr         $v0, 0x180($s4)
    do_swr(rdram, 0X180, ctx->r20, ctx->r2);
    // swl         $v1, 0x187($s4)
    do_swl(rdram, 0X187, ctx->r20, ctx->r3);
    // swr         $v1, 0x184($s4)
    do_swr(rdram, 0X184, ctx->r20, ctx->r3);
    // lw          $v0, 0x134($s4)
    ctx->r2 = MEM_W(0X134, ctx->r20);
    // nop

    // sw          $v0, 0x130($s4)
    MEM_W(0X130, ctx->r20) = ctx->r2;
L_80048E48:
    // lw          $v0, 0x114($s4)
    ctx->r2 = MEM_W(0X114, ctx->r20);
    // nop

    // bne         $v0, $s5, L_80048E84
    if (ctx->r2 != ctx->r21) {
        // nop
    
        goto L_80048E84;
    }
    // nop

    // lwl         $v0, 0x16B($s4)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X16B, ctx->r20);
    // lwr         $v0, 0x168($s4)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X168, ctx->r20);
    // lwl         $v1, 0x16F($s4)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X16F, ctx->r20);
    // lwr         $v1, 0x16C($s4)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X16C, ctx->r20);
    // swl         $v0, 0x15B($s4)
    do_swl(rdram, 0X15B, ctx->r20, ctx->r2);
    // swr         $v0, 0x158($s4)
    do_swr(rdram, 0X158, ctx->r20, ctx->r2);
    // swl         $v1, 0x15F($s4)
    do_swl(rdram, 0X15F, ctx->r20, ctx->r3);
    // swr         $v1, 0x15C($s4)
    do_swr(rdram, 0X15C, ctx->r20, ctx->r3);
    // lw          $v0, 0x11C($s4)
    ctx->r2 = MEM_W(0X11C, ctx->r20);
    // nop

    // sw          $v0, 0x114($s4)
    MEM_W(0X114, ctx->r20) = ctx->r2;
L_80048E84:
    // lw          $v0, 0x118($s4)
    ctx->r2 = MEM_W(0X118, ctx->r20);
    // nop

    // bne         $v0, $s5, L_80048EC0
    if (ctx->r2 != ctx->r21) {
        // nop
    
        goto L_80048EC0;
    }
    // nop

    // lwl         $v0, 0x15B($s4)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X15B, ctx->r20);
    // lwr         $v0, 0x158($s4)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X158, ctx->r20);
    // lwl         $v1, 0x15F($s4)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X15F, ctx->r20);
    // lwr         $v1, 0x15C($s4)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X15C, ctx->r20);
    // swl         $v0, 0x163($s4)
    do_swl(rdram, 0X163, ctx->r20, ctx->r2);
    // swr         $v0, 0x160($s4)
    do_swr(rdram, 0X160, ctx->r20, ctx->r2);
    // swl         $v1, 0x167($s4)
    do_swl(rdram, 0X167, ctx->r20, ctx->r3);
    // swr         $v1, 0x164($s4)
    do_swr(rdram, 0X164, ctx->r20, ctx->r3);
    // lw          $v0, 0x114($s4)
    ctx->r2 = MEM_W(0X114, ctx->r20);
    // nop

    // sw          $v0, 0x118($s4)
    MEM_W(0X118, ctx->r20) = ctx->r2;
L_80048EC0:
    // lw          $v0, 0x114($s4)
    ctx->r2 = MEM_W(0X114, ctx->r20);
    // nop

    // beq         $v0, $s5, L_80048F84
    if (ctx->r2 == ctx->r21) {
        // nop
    
        goto L_80048F84;
    }
    // nop

    // lhu         $v0, 0x15A($s4)
    ctx->r2 = MEM_HU(0X15A, ctx->r20);
    // nop

    // beq         $v0, $zero, L_80048F84
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048F84;
    }
    // nop

    // lhu         $v0, 0x158($s4)
    ctx->r2 = MEM_HU(0X158, ctx->r20);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x15C($s4)
    ctx->r2 = MEM_HU(0X15C, ctx->r20);
    // mflo        $v1
    ctx->r3 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // jal         0x800746C4
    // addu        $a0, $v1, $a3
    ctx->r4 = ADD32(ctx->r3, ctx->r7);
    SquareRoot0(rdram, ctx);
    goto after_10;
    // addu        $a0, $v1, $a3
    ctx->r4 = ADD32(ctx->r3, ctx->r7);
    after_10:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // lhu         $a0, 0x15A($s4)
    ctx->r4 = MEM_HU(0X15A, ctx->r20);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // jal         0x80076EA4
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    ratan2(rdram, ctx);
    goto after_11;
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    after_11:
    // beq         $s0, $zero, L_80048F84
    if (ctx->r16 == 0) {
        // nop
    
        goto L_80048F84;
    }
    // nop

    // sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) << 16;
    // jal         0x800743F4
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    rsin(rdram, ctx);
    goto after_12;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_12:
    // lw          $v1, 0x114($s4)
    ctx->r3 = MEM_W(0X114, ctx->r20);
    // nop

    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80048F60
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80048F60;
    }
    // nop

    // break       7
    do_break(2147782492);
L_80048F60:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80048F78
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80048F78;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80048F78
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80048F78;
    }
    // nop

    // break       6
    do_break(2147782516);
L_80048F78:
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // sw          $v1, 0x114($s4)
    MEM_W(0X114, ctx->r20) = ctx->r3;
L_80048F84:
    // lw          $v1, 0x118($s4)
    ctx->r3 = MEM_W(0X118, ctx->r20);
    // lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // beq         $v1, $v0, L_8004905C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
        goto L_8004905C;
    }
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // lhu         $v0, 0x162($s4)
    ctx->r2 = MEM_HU(0X162, ctx->r20);
    // nop

    // beq         $v0, $zero, L_8004905C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
        goto L_8004905C;
    }
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // lhu         $v0, 0x160($s4)
    ctx->r2 = MEM_HU(0X160, ctx->r20);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x164($s4)
    ctx->r3 = MEM_HU(0X164, ctx->r20);
    // nop

    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // lhu         $v0, 0x15C($s4)
    ctx->r2 = MEM_HU(0X15C, ctx->r20);
    // mflo        $a0
    ctx->r4 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_13;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    after_13:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // lhu         $a0, 0x162($s4)
    ctx->r4 = MEM_HU(0X162, ctx->r20);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // jal         0x80076EA4
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    ratan2(rdram, ctx);
    goto after_14;
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    after_14:
    // beq         $s0, $zero, L_80049058
    if (ctx->r16 == 0) {
        // nop
    
        goto L_80049058;
    }
    // nop

    // sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) << 16;
    // jal         0x800743F4
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    rsin(rdram, ctx);
    goto after_15;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_15:
    // lw          $v1, 0x118($s4)
    ctx->r3 = MEM_W(0X118, ctx->r20);
    // nop

    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80049034
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80049034;
    }
    // nop

    // break       7
    do_break(2147782704);
L_80049034:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8004904C
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8004904C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8004904C
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8004904C;
    }
    // nop

    // break       6
    do_break(2147782728);
L_8004904C:
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // sw          $v1, 0x118($s4)
    MEM_W(0X118, ctx->r20) = ctx->r3;
L_80049058:
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_8004905C:
    // lh          $a2, 0x16($s6)
    ctx->r6 = MEM_HS(0X16, ctx->r22);
    // lw          $t6, 0x120($s4)
    ctx->r14 = MEM_W(0X120, ctx->r20);
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // slt         $v0, $t6, $v0
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80049078
    if (ctx->r2 == 0) {
        // sll         $v0, $a2, 12
        ctx->r2 = S32(ctx->r6) << 12;
        goto L_80049078;
    }
    // sll         $v0, $a2, 12
    ctx->r2 = S32(ctx->r6) << 12;
    // ori         $s7, $s7, 0x4
    ctx->r23 = ctx->r23 | 0X4;
L_80049078:
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bgez        $v0, L_80049088
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80049088;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80049088:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // lhu         $v1, 0x1E($s6)
    ctx->r3 = MEM_HU(0X1E, ctx->r22);
    // lw          $a0, 0x114($s4)
    ctx->r4 = MEM_W(0X114, ctx->r20);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // slt         $a0, $a0, $v1
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $a0, $zero, L_800490A8
    if (ctx->r4 == 0) {
        // nop
    
        goto L_800490A8;
    }
    // nop

    // ori         $s7, $s7, 0x1
    ctx->r23 = ctx->r23 | 0X1;
L_800490A8:
    // lhu         $v0, 0x170($s4)
    ctx->r2 = MEM_HU(0X170, ctx->r20);
    // lh          $a3, 0x14($s6)
    ctx->r7 = MEM_HS(0X14, ctx->r22);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x172($s4)
    ctx->r2 = MEM_HU(0X172, ctx->r20);
    // mflo        $a0
    ctx->r4 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $a1, 0x18($s6)
    ctx->r5 = MEM_HS(0X18, ctx->r22);
    // lhu         $v0, 0x174($s4)
    ctx->r2 = MEM_HU(0X174, ctx->r20);
    // mflo        $v1
    ctx->r3 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bgez        $v0, L_80049104
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $v1, $v0, 12
        ctx->r3 = S32(ctx->r2) >> 12;
        goto L_80049104;
    }
    // sra         $v1, $v0, 12
    ctx->r3 = S32(ctx->r2) >> 12;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
    // sra         $v1, $v0, 12
    ctx->r3 = S32(ctx->r2) >> 12;
L_80049104:
    // lhu         $a0, 0x1C($s6)
    ctx->r4 = MEM_HU(0X1C, ctx->r22);
    // lw          $v0, 0x128($s4)
    ctx->r2 = MEM_W(0X128, ctx->r20);
    // subu        $v1, $a0, $v1
    ctx->r3 = SUB32(ctx->r4, ctx->r3);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80049120
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80049120;
    }
    // nop

    // ori         $s7, $s7, 0x2
    ctx->r23 = ctx->r23 | 0X2;
L_80049120:
    // lhu         $v0, 0x180($s4)
    ctx->r2 = MEM_HU(0X180, ctx->r20);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x182($s4)
    ctx->r2 = MEM_HU(0X182, ctx->r20);
    // mflo        $a3
    ctx->r7 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x184($s4)
    ctx->r2 = MEM_HU(0X184, ctx->r20);
    // mflo        $v1
    ctx->r3 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a3, $v1
    ctx->r2 = ADD32(ctx->r7, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bgez        $v0, L_80049178
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $v1, $v0, 12
        ctx->r3 = S32(ctx->r2) >> 12;
        goto L_80049178;
    }
    // sra         $v1, $v0, 12
    ctx->r3 = S32(ctx->r2) >> 12;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
    // sra         $v1, $v0, 12
    ctx->r3 = S32(ctx->r2) >> 12;
L_80049178:
    // lw          $v0, 0x130($s4)
    ctx->r2 = MEM_W(0X130, ctx->r20);
    // subu        $v1, $a0, $v1
    ctx->r3 = SUB32(ctx->r4, ctx->r3);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80049190
    if (ctx->r2 == 0) {
        // lui         $v1, 0x801B
        ctx->r3 = S32(0X801B << 16);
        goto L_80049190;
    }
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // ori         $s7, $s7, 0x8
    ctx->r23 = ctx->r23 | 0X8;
L_80049190:
    // lw          $v0, 0x124($s4)
    ctx->r2 = MEM_W(0X124, ctx->r20);
    // lw          $a0, 0x114($s4)
    ctx->r4 = MEM_W(0X114, ctx->r20);
    // lw          $a1, 0x118($s4)
    ctx->r5 = MEM_W(0X118, ctx->r20);
    // lw          $a2, 0x128($s4)
    ctx->r6 = MEM_W(0X128, ctx->r20);
    // lw          $a3, 0x12C($s4)
    ctx->r7 = MEM_W(0X12C, ctx->r20);
    // lw          $t0, 0x130($s4)
    ctx->r8 = MEM_W(0X130, ctx->r20);
    // lw          $t1, 0x134($s4)
    ctx->r9 = MEM_W(0X134, ctx->r20);
    // lw          $t2, 0x138($s4)
    ctx->r10 = MEM_W(0X138, ctx->r20);
    // lw          $t3, 0x13C($s4)
    ctx->r11 = MEM_W(0X13C, ctx->r20);
    // lw          $t4, 0x140($s4)
    ctx->r12 = MEM_W(0X140, ctx->r20);
    // lw          $t5, 0x144($s4)
    ctx->r13 = MEM_W(0X144, ctx->r20);
    // addiu       $v1, $v1, 0x5948
    ctx->r3 = ADD32(ctx->r3, 0X5948);
    // sw          $t6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r14;
    // sw          $v0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r2;
    // sw          $a0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r4;
    // sw          $a1, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r5;
    // sw          $a2, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r6;
    // sw          $a3, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r7;
    // sw          $t0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r8;
    // sw          $t1, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r9;
    // sw          $t2, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r10;
    // sw          $t3, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r11;
    // sw          $t4, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r12;
    // sw          $t5, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r13;
    // lwl         $v0, 0x153($s4)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X153, ctx->r20);
    // lwr         $v0, 0x150($s4)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X150, ctx->r20);
    // lwl         $a0, 0x157($s4)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X157, ctx->r20);
    // lwr         $a0, 0x154($s4)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X154, ctx->r20);
    // swl         $v0, 0x7F($v1)
    do_swl(rdram, 0X7F, ctx->r3, ctx->r2);
    // swr         $v0, 0x7C($v1)
    do_swr(rdram, 0X7C, ctx->r3, ctx->r2);
    // swl         $a0, 0x83($v1)
    do_swl(rdram, 0X83, ctx->r3, ctx->r4);
    // swr         $a0, 0x80($v1)
    do_swr(rdram, 0X80, ctx->r3, ctx->r4);
    // lwl         $v0, 0x15B($s4)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X15B, ctx->r20);
    // lwr         $v0, 0x158($s4)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X158, ctx->r20);
    // lwl         $a0, 0x15F($s4)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X15F, ctx->r20);
    // lwr         $a0, 0x15C($s4)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X15C, ctx->r20);
    // swl         $v0, 0x87($v1)
    do_swl(rdram, 0X87, ctx->r3, ctx->r2);
    // swr         $v0, 0x84($v1)
    do_swr(rdram, 0X84, ctx->r3, ctx->r2);
    // swl         $a0, 0x8B($v1)
    do_swl(rdram, 0X8B, ctx->r3, ctx->r4);
    // swr         $a0, 0x88($v1)
    do_swr(rdram, 0X88, ctx->r3, ctx->r4);
    // lwl         $v0, 0x173($s4)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X173, ctx->r20);
    // lwr         $v0, 0x170($s4)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X170, ctx->r20);
    // lwl         $a0, 0x177($s4)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X177, ctx->r20);
    // lwr         $a0, 0x174($s4)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X174, ctx->r20);
    // swl         $v0, 0x8F($v1)
    do_swl(rdram, 0X8F, ctx->r3, ctx->r2);
    // swr         $v0, 0x8C($v1)
    do_swr(rdram, 0X8C, ctx->r3, ctx->r2);
    // swl         $a0, 0x93($v1)
    do_swl(rdram, 0X93, ctx->r3, ctx->r4);
    // swr         $a0, 0x90($v1)
    do_swr(rdram, 0X90, ctx->r3, ctx->r4);
    // lwl         $v0, 0x17B($s4)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X17B, ctx->r20);
    // lwr         $v0, 0x178($s4)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X178, ctx->r20);
    // lwl         $a0, 0x17F($s4)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X17F, ctx->r20);
    // lwr         $a0, 0x17C($s4)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X17C, ctx->r20);
    // swl         $v0, 0x97($v1)
    do_swl(rdram, 0X97, ctx->r3, ctx->r2);
    // swr         $v0, 0x94($v1)
    do_swr(rdram, 0X94, ctx->r3, ctx->r2);
    // swl         $a0, 0x9B($v1)
    do_swl(rdram, 0X9B, ctx->r3, ctx->r4);
    // swr         $a0, 0x98($v1)
    do_swr(rdram, 0X98, ctx->r3, ctx->r4);
    // lwl         $v0, 0x183($s4)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X183, ctx->r20);
    // lwr         $v0, 0x180($s4)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X180, ctx->r20);
    // lwl         $a0, 0x187($s4)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X187, ctx->r20);
    // lwr         $a0, 0x184($s4)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X184, ctx->r20);
    // swl         $v0, 0x9F($v1)
    do_swl(rdram, 0X9F, ctx->r3, ctx->r2);
    // swr         $v0, 0x9C($v1)
    do_swr(rdram, 0X9C, ctx->r3, ctx->r2);
    // swl         $a0, 0xA3($v1)
    do_swl(rdram, 0XA3, ctx->r3, ctx->r4);
    // swr         $a0, 0xA0($v1)
    do_swr(rdram, 0XA0, ctx->r3, ctx->r4);
    // lwl         $v0, 0x18B($s4)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X18B, ctx->r20);
    // lwr         $v0, 0x188($s4)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X188, ctx->r20);
    // lwl         $a0, 0x18F($s4)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X18F, ctx->r20);
    // lwr         $a0, 0x18C($s4)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X18C, ctx->r20);
    // swl         $v0, 0xA7($v1)
    do_swl(rdram, 0XA7, ctx->r3, ctx->r2);
    // swr         $v0, 0xA4($v1)
    do_swr(rdram, 0XA4, ctx->r3, ctx->r2);
    // swl         $a0, 0xAB($v1)
    do_swl(rdram, 0XAB, ctx->r3, ctx->r4);
    // swr         $a0, 0xA8($v1)
    do_swr(rdram, 0XA8, ctx->r3, ctx->r4);
    // lhu         $a0, 0x22($s4)
    ctx->r4 = MEM_HU(0X22, ctx->r20);
    // lw          $a1, 0x198($s4)
    ctx->r5 = MEM_W(0X198, ctx->r20);
    // addu        $v0, $s7, $zero
    ctx->r2 = ADD32(ctx->r23, 0);
    // sh          $a0, 0x44C8($v1)
    MEM_H(0X44C8, ctx->r3) = ctx->r4;
    // sw          $a1, 0x47DC($v1)
    MEM_W(0X47DC, ctx->r3) = ctx->r5;
L_800492C4:
    // lw          $ra, 0x1830($sp)
    ctx->r31 = MEM_W(0X1830, ctx->r29);
    // lw          $s7, 0x182C($sp)
    ctx->r23 = MEM_W(0X182C, ctx->r29);
    // lw          $s6, 0x1828($sp)
    ctx->r22 = MEM_W(0X1828, ctx->r29);
    // lw          $s5, 0x1824($sp)
    ctx->r21 = MEM_W(0X1824, ctx->r29);
    // lw          $s4, 0x1820($sp)
    ctx->r20 = MEM_W(0X1820, ctx->r29);
    // lw          $s3, 0x181C($sp)
    ctx->r19 = MEM_W(0X181C, ctx->r29);
    // lw          $s2, 0x1818($sp)
    ctx->r18 = MEM_W(0X1818, ctx->r29);
    // lw          $s1, 0x1814($sp)
    ctx->r17 = MEM_W(0X1814, ctx->r29);
    // lw          $s0, 0x1810($sp)
    ctx->r16 = MEM_W(0X1810, ctx->r29);
    // addiu       $sp, $sp, 0x1838
    ctx->r29 = ADD32(ctx->r29, 0X1838);
    // jr          $ra
    // nop

    return;
    // nop

;}
