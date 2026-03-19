#include "recomp.h"
#include "disable_warnings.h"

void sub_8003EE38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, -0x7FD4
    ctx->r6 = ADD32(ctx->r2, -0X7FD4);
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
    // addiu       $a2, $v0, -0x7FCC
    ctx->r6 = ADD32(ctx->r2, -0X7FCC);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r3);
    // swr         $v1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r3);
    // swl         $a0, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r4);
    // swr         $a0, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r4);
    // andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8003EECC
    if (ctx->r3 == ctx->r2) {
        // addiu       $s5, $zero, 0xFF
        ctx->r21 = ADD32(0, 0XFF);
        goto L_8003EECC;
    }
    // addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
L_8003EECC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // andi        $a0, $s6, 0xFF
    ctx->r4 = ctx->r22 & 0XFF;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lbu         $v1, 0x14C($v0)
    ctx->r3 = MEM_BU(0X14C, ctx->r2);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8003EF68
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
        goto L_8003EF68;
    }
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v1, $v0, -0x1CE8
    ctx->r3 = ADD32(ctx->r2, -0X1CE8);
    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
L_8003EF04:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $a2, L_8003EF58
    if (ctx->r2 == ctx->r6) {
        // andi        $v0, $v0, 0x20
        ctx->r2 = ctx->r2 & 0X20;
        goto L_8003EF58;
    }
    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // bne         $v0, $a3, L_8003EF58
    if (ctx->r2 != ctx->r7) {
        // nop
    
        goto L_8003EF58;
    }
    // nop

    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // sltiu       $v0, $v0, 0x2C
    ctx->r2 = ctx->r2 < 0X2C ? 1 : 0;
    // beq         $v0, $zero, L_8003EF38
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003EF38;
    }
    // nop

    // sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_8003EF38:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // addiu       $v0, $v0, 0x56
    ctx->r2 = ADD32(ctx->r2, 0X56);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_8003EF58
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003EF58;
    }
    // nop

    // sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_8003EF58:
    // addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $t0, L_8003EF04
    if (ctx->r5 != ctx->r8) {
        // addiu       $v1, $v1, 0x58
        ctx->r3 = ADD32(ctx->r3, 0X58);
        goto L_8003EF04;
    }
    // addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
L_8003EF68:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // andi        $s2, $s6, 0xFF
    ctx->r18 = ctx->r22 & 0XFF;
    // addu        $v0, $s2, $a2
    ctx->r2 = ADD32(ctx->r18, ctx->r6);
    // sb          $s5, 0x14C($v0)
    MEM_B(0X14C, ctx->r2) = ctx->r21;
    // andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8003F0B4
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_8003F0B4;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3) << 2;
    // addiu       $a1, $a1, 0x2E4
    ctx->r5 = ADD32(ctx->r5, 0X2E4);
    // sll         $s4, $s2, 2
    ctx->r20 = S32(ctx->r18) << 2;
    // addu        $s0, $s4, $a2
    ctx->r16 = ADD32(ctx->r20, ctx->r6);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, -0x2D68
    ctx->r3 = ADD32(ctx->r3, -0X2D68);
    // lw          $a2, 0x120($s0)
    ctx->r6 = MEM_W(0X120, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80016030
    // sw          $v0, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->r2;
    sub_80016030(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->r2;
    after_0:
    // sll         $v0, $s2, 3
    ctx->r2 = S32(ctx->r18) << 3;
    // addiu       $s3, $v0, 0x60
    ctx->r19 = ADD32(ctx->r2, 0X60);
    // lw          $s0, 0x120($s0)
    ctx->r16 = MEM_W(0X120, ctx->r16);
    // ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // lhu         $s2, 0x0($s0)
    ctx->r18 = MEM_HU(0X0, ctx->r16);
    // nop

    // addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // beq         $v0, $v1, L_8003F058
    if (ctx->r2 == ctx->r3) {
        // addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_8003F058;
    }
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $s7, $v0, -0x2F70
    ctx->r23 = ADD32(ctx->r2, -0X2F70);
L_8003EFF4:
    // lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(0X0, ctx->r16);
    // nop

    // sltiu       $v0, $s1, 0x5
    ctx->r2 = ctx->r17 < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_8003F03C
    if (ctx->r2 != 0) {
        // addiu       $a1, $sp, 0x10
        ctx->r5 = ADD32(ctx->r29, 0X10);
        goto L_8003F03C;
    }
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // addu        $a2, $a2, $s4
    ctx->r6 = ADD32(ctx->r6, ctx->r20);
    // andi        $v0, $s3, 0xFFFF
    ctx->r2 = ctx->r19 & 0XFFFF;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // ori         $v1, $zero, 0x834C
    ctx->r3 = 0 | 0X834C;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(0X8, ctx->r16);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // jal         0x800177A0
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    sub_800177A0(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    after_1:
L_8003F03C:
    // addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
    // addiu       $v1, $s2, -0x1
    ctx->r3 = ADD32(ctx->r18, -0X1);
    // addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $v1, $v0, L_8003EFF4
    if (ctx->r3 != ctx->r2) {
        // addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_8003EFF4;
    }
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8003F058:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // andi        $s1, $s5, 0xFF
    ctx->r17 = ctx->r21 & 0XFF;
    // sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17) << 2;
    // addiu       $a1, $s1, 0x2E5
    ctx->r5 = ADD32(ctx->r17, 0X2E5);
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // addiu       $s0, $s0, -0x7378
    ctx->r16 = ADD32(ctx->r16, -0X7378);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_2;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // andi        $s0, $s6, 0xFF
    ctx->r16 = ctx->r22 & 0XFF;
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // jal         0x8003EC5C
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_8003EC5C(rdram, ctx);
    goto after_3;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addiu       $a1, $s1, 0x2E6
    ctx->r5 = ADD32(ctx->r17, 0X2E6);
    // jal         0x80058A0C
    // addiu       $a2, $s0, 0x6
    ctx->r6 = ADD32(ctx->r16, 0X6);
    sub_80058A0C(rdram, ctx);
    goto after_5;
    // addiu       $a2, $s0, 0x6
    ctx->r6 = ADD32(ctx->r16, 0X6);
    after_5:
L_8003F0B4:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // sb          $v0, 0x188($a0)
    MEM_B(0X188, ctx->r4) = ctx->r2;
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sh          $zero, 0x182($a0)
    MEM_H(0X182, ctx->r4) = 0;
    // sh          $zero, 0x184($a0)
    MEM_H(0X184, ctx->r4) = 0;
    // sh          $v1, 0x13C($v0)
    MEM_H(0X13C, ctx->r2) = ctx->r3;
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // sw          $zero, 0x128($v0)
    MEM_W(0X128, ctx->r2) = 0;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // jal         0x80015AD4
    // sb          $v0, 0x155($a1)
    MEM_B(0X155, ctx->r5) = ctx->r2;
    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_6;
    // sb          $v0, 0x155($a1)
    MEM_B(0X155, ctx->r5) = ctx->r2;
    after_6:
    // lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(0X40, ctx->r29);
    // lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(0X3C, ctx->r29);
    // lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
