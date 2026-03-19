#include "recomp.h"
#include "disable_warnings.h"

void sub_80030AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x7FB8
    ctx->r6 = ADD32(ctx->r2, 0X7FB8);
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
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7FC0
    ctx->r6 = ADD32(ctx->r2, 0X7FC0);
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
    // jal         0x800174C4
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    ST_BeginDraw2D(rdram, ctx);
    goto after_0;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    after_0:
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
    // beq         $v0, $zero, L_80030B64
    if (ctx->r2 == 0) {
        // sb          $v1, 0x313($s0)
        MEM_B(0X313, ctx->r16) = ctx->r3;
        goto L_80030B64;
    }
    // sb          $v1, 0x313($s0)
    MEM_B(0X313, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x2E4($s0)
    ctx->r3 = MEM_BU(0X2E4, ctx->r16);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // j           L_80030B70
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_80030B70;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80030B64:
    // lbu         $v0, 0x2E4($s0)
    ctx->r2 = MEM_BU(0X2E4, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
L_80030B70:
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
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // sb          $v1, 0x32D($s0)
    MEM_B(0X32D, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x2DC($s0)
    ctx->r3 = MEM_HU(0X2DC, ctx->r16);
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sb          $v0, 0x32C($s0)
    MEM_B(0X32C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80030BB8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80030BB8;
    }
    // nop

    // jal         0x8003025C
    // nop

    sub_8003025C(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_80030BC0
    // nop

    goto L_80030BC0;
    // nop

L_80030BB8:
    // jal         0x8002FE4C
    // nop

    sub_8002FE4C(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_80030BC0:
    // jal         0x8002C9E8
    // nop

    sub_8002C9E8(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x80017680
    // nop

    sub_80017680(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
