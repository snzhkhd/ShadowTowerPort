#include "recomp.h"
#include "disable_warnings.h"

void sub_80066004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x800174C4
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    ST_BeginDraw2D(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
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
    // addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // sb          $v0, 0x30F($s0)
    MEM_B(0X30F, ctx->r16) = ctx->r2;
    // sb          $v0, 0x30B($s0)
    MEM_B(0X30B, ctx->r16) = ctx->r2;
    // sb          $v0, 0x303($s0)
    MEM_B(0X303, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
    // sb          $v0, 0x31F($s0)
    MEM_B(0X31F, ctx->r16) = ctx->r2;
    // sb          $v0, 0x31B($s0)
    MEM_B(0X31B, ctx->r16) = ctx->r2;
    // sltiu       $v1, $v1, 0x10
    ctx->r3 = ctx->r3 < 0X10 ? 1 : 0;
    // beq         $v1, $zero, L_800660AC
    if (ctx->r3 == 0) {
        // sb          $v0, 0x313($s0)
        MEM_B(0X313, ctx->r16) = ctx->r2;
        goto L_800660AC;
    }
    // sb          $v0, 0x313($s0)
    MEM_B(0X313, ctx->r16) = ctx->r2;
    // lbu         $v1, 0x2E4($s0)
    ctx->r3 = MEM_BU(0X2E4, ctx->r16);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // j           L_800660B8
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_800660B8;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_800660AC:
    // lbu         $v0, 0x2E4($s0)
    ctx->r2 = MEM_BU(0X2E4, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
L_800660B8:
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
    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // bne         $v0, $zero, L_80066108
    if (ctx->r2 != 0) {
        // sb          $v1, 0x32D($s0)
        MEM_B(0X32D, ctx->r16) = ctx->r3;
        goto L_80066108;
    }
    // sb          $v1, 0x32D($s0)
    MEM_B(0X32D, ctx->r16) = ctx->r3;
    // jal         0x800651F0
    // nop

    sub_800651F0(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lhu         $v1, 0x2DC($s0)
    ctx->r3 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // beq         $v0, $zero, L_80066118
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
        goto L_80066118;
    }
    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
L_80066108:
    // jal         0x80065270
    // nop

    sub_80065270(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_80066138
    // nop

    goto L_80066138;
    // nop

L_80066118:
    // beq         $v0, $zero, L_80066130
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80066130;
    }
    // nop

    // jal         0x80065770
    // nop

    sub_80065770(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // j           L_80066138
    // nop

    goto L_80066138;
    // nop

L_80066130:
    // jal         0x80065DE0
    // nop

    sub_80065DE0(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_80066138:
    // jal         0x800650DC
    // nop

    sub_800650DC(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x800175A4
    // nop

    sub_800175A4(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // jal         0x80065F40
    // nop

    sub_80065F40(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // jal         0x80017634
    // nop

    sub_80017634(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
