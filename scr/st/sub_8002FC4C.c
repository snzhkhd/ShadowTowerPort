#include "recomp.h"
#include "disable_warnings.h"

void sub_8002FC4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x7F88
    ctx->r6 = ADD32(ctx->r2, 0X7F88);
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
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F90
    ctx->r6 = ADD32(ctx->r2, 0X7F90);
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
    // jal         0x800174C4
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    sub_800174C4(rdram, ctx);
    goto after_0;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    after_0:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lhu         $v1, -0x2E7C($v0)
    ctx->r3 = MEM_HU(-0X2E7C, ctx->r2);
    // nop

    // andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // beq         $v0, $zero, L_8002FCD8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8002FCD8;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E56($at)
    MEM_H(-0X7E56, ctx->r1) = ctx->r2;
    // j           L_8002FCEC
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    goto L_8002FCEC;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_8002FCD8:
    // andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // beq         $v0, $zero, L_8002FCEC
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_8002FCEC;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $zero, -0x7E56($at)
    MEM_H(-0X7E56, ctx->r1) = 0;
L_8002FCEC:
    // sh          $zero, -0x2E7C($v0)
    MEM_H(-0X2E7C, ctx->r2) = 0;
    // addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // sb          $v0, 0x310($s0)
    MEM_B(0X310, ctx->r16) = ctx->r2;
    // sb          $v0, 0x300($s0)
    MEM_B(0X300, ctx->r16) = ctx->r2;
    // sb          $v0, 0x311($s0)
    MEM_B(0X311, ctx->r16) = ctx->r2;
    // sb          $v0, 0x301($s0)
    MEM_B(0X301, ctx->r16) = ctx->r2;
    // sb          $v0, 0x312($s0)
    MEM_B(0X312, ctx->r16) = ctx->r2;
    // sb          $v0, 0x302($s0)
    MEM_B(0X302, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
    // sb          $v0, 0x303($s0)
    MEM_B(0X303, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x2E4($s0)
    ctx->r2 = MEM_BU(0X2E4, ctx->r16);
    // addiu       $v1, $zero, 0x31
    ctx->r3 = ADD32(0, 0X31);
    // sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8002FD38
    if (ctx->r2 == 0) {
        // sb          $v1, 0x313($s0)
        MEM_B(0X313, ctx->r16) = ctx->r3;
        goto L_8002FD38;
    }
    // sb          $v1, 0x313($s0)
    MEM_B(0X313, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x2E4($s0)
    ctx->r3 = MEM_BU(0X2E4, ctx->r16);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // j           L_8002FD44
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_8002FD44;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8002FD38:
    // lbu         $v0, 0x2E4($s0)
    ctx->r2 = MEM_BU(0X2E4, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
L_8002FD44:
    // sh          $v0, 0x360($s0)
    MEM_H(0X360, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x360($s0)
    ctx->r2 = MEM_BU(0X360, ctx->r16);
    // lbu         $v1, 0x360($s0)
    ctx->r3 = MEM_BU(0X360, ctx->r16);
    // sb          $zero, 0x32E($s0)
    MEM_B(0X32E, ctx->r16) = 0;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // sb          $v0, 0x32C($s0)
    MEM_B(0X32C, ctx->r16) = ctx->r2;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $v0, -0x7E6E($v0)
    ctx->r2 = MEM_HU(-0X7E6E, ctx->r2);
    // addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // beq         $v0, $zero, L_8002FDAC
    if (ctx->r2 == 0) {
        // sb          $v1, 0x32D($s0)
        MEM_B(0X32D, ctx->r16) = ctx->r3;
        goto L_8002FDAC;
    }
    // sb          $v1, 0x32D($s0)
    MEM_B(0X32D, ctx->r16) = ctx->r3;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $v0, -0x7E56($v0)
    ctx->r2 = MEM_HU(-0X7E56, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002FD9C
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_8002FD9C;
    }
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // ori         $a1, $s0, 0x32C
    ctx->r5 = ctx->r16 | 0X32C;
    // j           L_8002FDA4
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_8002FDA4;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8002FD9C:
    // ori         $a1, $s0, 0x32C
    ctx->r5 = ctx->r16 | 0X32C;
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_8002FDA4:
    // jal         0x8002916C
    // nop

    sub_8002916C(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_8002FDAC:
    // lhu         $v1, 0x2DC($s0)
    ctx->r3 = MEM_HU(0X2DC, ctx->r16);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_8002FDEC
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
        goto L_8002FDEC;
    }
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // lbu         $v1, 0x2C7($s0)
    ctx->r3 = MEM_BU(0X2C7, ctx->r16);
    // nop

    // beq         $v1, $v0, L_8002FDDC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8002FDDC;
    }
    // nop

    // jal         0x8002F498
    // nop

    sub_8002F498(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_8002FDF4
    // nop

    goto L_8002FDF4;
    // nop

L_8002FDDC:
    // jal         0x8002F97C
    // nop

    sub_8002F97C(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // j           L_8002FDF4
    // nop

    goto L_8002FDF4;
    // nop

L_8002FDEC:
    // jal         0x8002E4D0
    // nop

    sub_8002E4D0(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_8002FDF4:
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $v0, -0x7E56($v0)
    ctx->r2 = MEM_HU(-0X7E56, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002FE18
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002FE18;
    }
    // nop

    // jal         0x8002ED98
    // nop

    sub_8002ED98(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // j           L_8002FE20
    // nop

    goto L_8002FE20;
    // nop

L_8002FE18:
    // jal         0x8002E94C
    // nop

    sub_8002E94C(rdram, ctx);
    goto after_6;
    // nop

    after_6:
L_8002FE20:
    // jal         0x8002E490
    // nop

    sub_8002E490(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // jal         0x8002C9E8
    // nop

    sub_8002C9E8(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // jal         0x80017680
    // nop

    sub_80017680(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
