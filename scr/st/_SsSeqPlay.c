#include "recomp.h"
#include "disable_warnings.h"

void _SsSeqPlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4) << 16;
    // sra         $a0, $a3, 14
    ctx->r4 = S32(ctx->r7) >> 14;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lw          $v1, -0x79A0($v1)
    ctx->r3 = MEM_W(-0X79A0, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // lh          $v0, 0x54($s1)
    ctx->r2 = MEM_HS(0X54, ctx->r17);
    // lw          $v1, 0x90($s1)
    ctx->r3 = MEM_W(0X90, ctx->r17);
    // lhu         $a0, 0x54($s1)
    ctx->r4 = MEM_HU(0X54, ctx->r17);
    // subu        $a2, $v1, $v0
    ctx->r6 = SUB32(ctx->r3, ctx->r2);
    // blez        $a2, L_8006DE30
    if (SIGNED(ctx->r6) <= 0) {
        // slt         $v0, $v0, $v1
        ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_8006DE30;
    }
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // lh          $v1, 0x52($s1)
    ctx->r3 = MEM_HS(0X52, ctx->r17);
    // lhu         $v0, 0x52($s1)
    ctx->r2 = MEM_HU(0X52, ctx->r17);
    // blez        $v1, L_8006DE10
    if (SIGNED(ctx->r3) <= 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8006DE10;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_8006DE74
    // sh          $v0, 0x52($s1)
    MEM_H(0X52, ctx->r17) = ctx->r2;
    goto L_8006DE74;
    // sh          $v0, 0x52($s1)
    MEM_H(0X52, ctx->r17) = ctx->r2;
L_8006DE10:
    // bne         $v1, $zero, L_8006DE28
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8006DE28;
    }
    // nop

    // lw          $v0, 0x90($s1)
    ctx->r2 = MEM_W(0X90, ctx->r17);
    // sh          $a0, 0x52($s1)
    MEM_H(0X52, ctx->r17) = ctx->r4;
    // j           L_8006DE70
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    goto L_8006DE70;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8006DE28:
    // j           L_8006DE74
    // sw          $a2, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r6;
    goto L_8006DE74;
    // sw          $a2, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r6;
L_8006DE30:
    // bne         $v0, $zero, L_8006DE74
    if (ctx->r2 != 0) {
        // addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
        goto L_8006DE74;
    }
    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sra         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) >> 16;
L_8006DE44:
    // jal         0x8006E0D4
    // sra         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18) >> 16;
    _SsGetSeqData(rdram, ctx);
    goto after_0;
    // sra         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18) >> 16;
    after_0:
    // lw          $v0, 0x90($s1)
    ctx->r2 = MEM_W(0X90, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8006DE44
    if (ctx->r2 == 0) {
        // sra         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19) >> 16;
        goto L_8006DE44;
    }
    // sra         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) >> 16;
    // lh          $v1, 0x54($s1)
    ctx->r3 = MEM_HS(0X54, ctx->r17);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // slt         $v0, $s0, $v1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8006DE44
    if (ctx->r2 != 0) {
        // subu        $v0, $s0, $v1
        ctx->r2 = SUB32(ctx->r16, ctx->r3);
        goto L_8006DE44;
    }
    // subu        $v0, $s0, $v1
    ctx->r2 = SUB32(ctx->r16, ctx->r3);
L_8006DE70:
    // sw          $v0, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r2;
L_8006DE74:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
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
