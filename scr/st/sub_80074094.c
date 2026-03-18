#include "recomp.h"
#include "disable_warnings.h"

void sub_80074094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // sltiu       $v0, $v0, 0x11
    ctx->r2 = ctx->r2 < 0X11 ? 1 : 0;
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // beq         $v0, $zero, L_80074144
    if (ctx->r2 == 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_80074144;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // lbu         $v1, -0x68E8($v1)
    ctx->r3 = MEM_BU(-0X68E8, ctx->r3);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80074144
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80074144;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x1700($v0)
    ctx->r2 = MEM_W(0X1700, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80074130
    if (ctx->r2 != 0) {
        // sll         $s0, $s1, 2
        ctx->r16 = S32(ctx->r17) << 2;
        goto L_80074130;
    }
    // sll         $s0, $s1, 2
    ctx->r16 = S32(ctx->r17) << 2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lw          $v0, -0x68D0($v0)
    ctx->r2 = MEM_W(-0X68D0, ctx->r2);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $a2, 0x1704($at)
    MEM_H(0X1704, ctx->r1) = ctx->r6;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x1700($at)
    MEM_W(0X1700, ctx->r1) = ctx->r2;
    // jal         0x80074254
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    SpuSetTransferMode(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // lw          $a0, -0x6888($a0)
    ctx->r4 = MEM_W(-0X6888, ctx->r4);
    // jal         0x800741F4
    // nop

    SpuSetTransferStartAddr(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_80074130:
    // lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // lh          $s2, 0x1704($s2)
    ctx->r18 = MEM_HS(0X1704, ctx->r18);
    // nop

    // beq         $s2, $s1, L_80074154
    if (ctx->r18 == ctx->r17) {
        // addu        $s0, $s3, $zero
        ctx->r16 = ADD32(ctx->r19, 0);
        goto L_80074154;
    }
    // addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
L_80074144:
    // jal         0x80071EC4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    _spu_setInTransfer(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // j           L_800741CC
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_800741CC;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074154:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x1700($v1)
    ctx->r3 = MEM_W(0X1700, ctx->r3);
    // nop

    // sltu        $v0, $v1, $s0
    ctx->r2 = ctx->r3 < ctx->r16 ? 1 : 0;
    // beq         $v0, $zero, L_80074170
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80074170;
    }
    // nop

    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_80074170:
    // jal         0x80071EC4
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _spu_setInTransfer(rdram, ctx);
    goto after_3;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x80074284
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    SpuWritePartly(rdram, ctx);
    goto after_4;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x1700($v0)
    ctx->r2 = MEM_W(0X1700, ctx->r2);
    // nop

    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x1700($at)
    MEM_W(0X1700, ctx->r1) = ctx->r2;
    // bne         $v0, $zero, L_800741CC
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_800741CC;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v1, 0x1704($at)
    MEM_H(0X1704, ctx->r1) = ctx->r3;
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x1700($at)
    MEM_W(0X1700, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, -0x68E8($at)
    MEM_B(-0X68E8, ctx->r1) = ctx->r3;
L_800741CC:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
