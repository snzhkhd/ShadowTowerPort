#include "recomp.h"
#include "disable_warnings.h"

void sub_80068258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, -0x7E84
    ctx->r6 = ADD32(ctx->r2, -0X7E84);
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
    // addiu       $a2, $v0, -0x7E7C
    ctx->r6 = ADD32(ctx->r2, -0X7E7C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r3);
    // swr         $v1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r3);
    // jal         0x800174C4
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    ST_BeginDraw2D(rdram, ctx);
    goto after_0;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    after_0:
    // addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // sb          $v1, 0x31E($s0)
    MEM_B(0X31E, ctx->r16) = ctx->r3;
    // sb          $v1, 0x30E($s0)
    MEM_B(0X30E, ctx->r16) = ctx->r3;
    // sb          $v1, 0x31D($s0)
    MEM_B(0X31D, ctx->r16) = ctx->r3;
    // sb          $v1, 0x30D($s0)
    MEM_B(0X30D, ctx->r16) = ctx->r3;
    // sb          $v1, 0x31A($s0)
    MEM_B(0X31A, ctx->r16) = ctx->r3;
    // sb          $v1, 0x30A($s0)
    MEM_B(0X30A, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x2E4($s0)
    ctx->r3 = MEM_BU(0X2E4, ctx->r16);
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sb          $v0, 0x31C($s0)
    MEM_B(0X31C, ctx->r16) = ctx->r2;
    // sb          $v0, 0x30C($s0)
    MEM_B(0X30C, ctx->r16) = ctx->r2;
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
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // sb          $v0, 0x318($s0)
    MEM_B(0X318, ctx->r16) = ctx->r2;
    // sb          $v0, 0x308($s0)
    MEM_B(0X308, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    // sb          $v0, 0x319($s0)
    MEM_B(0X319, ctx->r16) = ctx->r2;
    // sb          $v0, 0x309($s0)
    MEM_B(0X309, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
    // sb          $v0, 0x30F($s0)
    MEM_B(0X30F, ctx->r16) = ctx->r2;
    // sb          $v0, 0x30B($s0)
    MEM_B(0X30B, ctx->r16) = ctx->r2;
    // sb          $v0, 0x303($s0)
    MEM_B(0X303, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    // sb          $v0, 0x31F($s0)
    MEM_B(0X31F, ctx->r16) = ctx->r2;
    // sb          $v0, 0x31B($s0)
    MEM_B(0X31B, ctx->r16) = ctx->r2;
    // sltiu       $v1, $v1, 0x10
    ctx->r3 = ctx->r3 < 0X10 ? 1 : 0;
    // beq         $v1, $zero, L_80068344
    if (ctx->r3 == 0) {
        // sb          $v0, 0x313($s0)
        MEM_B(0X313, ctx->r16) = ctx->r2;
        goto L_80068344;
    }
    // sb          $v0, 0x313($s0)
    MEM_B(0X313, ctx->r16) = ctx->r2;
    // lbu         $v1, 0x2E4($s0)
    ctx->r3 = MEM_BU(0X2E4, ctx->r16);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // j           L_80068350
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_80068350;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80068344:
    // lbu         $v0, 0x2E4($s0)
    ctx->r2 = MEM_BU(0X2E4, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
L_80068350:
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
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_8006838C
    if (ctx->r2 == 0) {
        // sb          $v1, 0x32D($s0)
        MEM_B(0X32D, ctx->r16) = ctx->r3;
        goto L_8006838C;
    }
    // sb          $v1, 0x32D($s0)
    MEM_B(0X32D, ctx->r16) = ctx->r3;
    // jal         0x800319A8
    // nop

    sub_800319A8(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_8006838C:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_800683B8
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_800683B8;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // jal         0x80067BEC
    // addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    sub_80067BEC(rdram, ctx);
    goto after_2;
    // addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    after_2:
    // jal         0x80067BEC
    // addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    sub_80067BEC(rdram, ctx);
    goto after_3;
    // addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_3:
    // j           L_800683E0
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    goto L_800683E0;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_800683B8:
    // lbu         $v1, 0xD38($v0)
    ctx->r3 = MEM_BU(0XD38, ctx->r2);
    // addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // bne         $v1, $v0, L_800683CC
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $zero, 0x62
        ctx->r4 = ADD32(0, 0X62);
        goto L_800683CC;
    }
    // addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_800683CC:
    // jal         0x80067BEC
    // nop

    sub_80067BEC(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x80067624
    // nop

    sub_80067624(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_800683E0:
    // lbu         $v1, 0xD38($v0)
    ctx->r3 = MEM_BU(0XD38, ctx->r2);
    // addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // bne         $v1, $v0, L_800683FC
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_800683FC;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // j           L_80068404
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_80068404;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800683FC:
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_80068404:
    // jal         0x8002916C
    // nop

    sub_8002916C(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_7;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
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
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
