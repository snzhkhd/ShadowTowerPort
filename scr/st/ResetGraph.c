#include "recomp.h"
#include "disable_warnings.h"

void ResetGraph(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // andi        $v1, $s1, 0x7
    ctx->r3 = ctx->r17 & 0X7;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // beq         $v1, $v0, L_80079730
    if (ctx->r3 == ctx->r2) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_80079730;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_80079720
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_80079720;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // beq         $v1, $zero, L_80079730
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80079730;
    }
    // nop

    // j           L_800797F4
    // nop

    goto L_800797F4;
    // nop

L_80079720:
    // beq         $v1, $v0, L_8007974C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007974C;
    }
    // nop

    // j           L_800797F4
    // nop

    goto L_800797F4;
    // nop

L_80079730:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x4114
    ctx->r4 = ADD32(ctx->r4, 0X4114);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, 0x7C78
    ctx->r5 = ADD32(ctx->r5, 0X7C78);
    // lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // jal         0x80078AD4
    // addiu       $a2, $a2, 0x7CC0
    ctx->r6 = ADD32(ctx->r6, 0X7CC0);
    printf(rdram, ctx);
    goto after_0;
    // addiu       $a2, $a2, 0x7CC0
    ctx->r6 = ADD32(ctx->r6, 0X7CC0);
    after_0:
L_8007974C:
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0x7CC0
    ctx->r16 = ADD32(ctx->r16, 0X7CC0);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x8007C6C8
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    memset_1(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_1:
    // jal         0x80077314
    // nop

    ResetCallback(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7CB8($a0)
    ctx->r4 = MEM_W(0X7CB8, ctx->r4);
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // jal         0x8007C6F4
    // and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    GPU_cw(rdram, ctx);
    goto after_3;
    // and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    after_3:
    // jal         0x8007BDE4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    ResetGraph_Internal(rdram, ctx);
    goto after_4;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r3;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v1, 0x7D40($v1)
    ctx->r3 = MEM_HU(0X7D40, ctx->r3);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lhu         $v0, 0x7D4C($at)
    ctx->r2 = MEM_HU(0X7D4C, ctx->r1);
    // addiu       $a2, $zero, 0x5C
    ctx->r6 = ADD32(0, 0X5C);
    // jal         0x8007C6C8
    // sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    memset_1(rdram, ctx);
    goto after_5;
    // sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    after_5:
    // addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // jal         0x8007C6C8
    // addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    memset_1(rdram, ctx);
    goto after_6;
    // addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_6:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // j           L_80079844
    // nop

    goto L_80079844;
    // nop

L_800797F4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lbu         $v0, 0x7CC2($v0)
    ctx->r2 = MEM_BU(0X7CC2, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80079828
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80079828;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x4134
    ctx->r4 = ADD32(ctx->r4, 0X4134);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7CBC($v0)
    ctx->r2 = MEM_W(0X7CBC, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_7;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_7:
L_80079828:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7CB8($v0)
    ctx->r2 = MEM_W(0X7CB8, ctx->r2);
    // nop

    // lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(0X34, ctx->r2);
    // nop

    // jalr        $v0
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_8;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
L_80079844:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
