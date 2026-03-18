#include "recomp.h"
#include "disable_warnings.h"

void sub_8005F6A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
L_8005F660:
    // lhu         $v0, 0x3E($a0)
    ctx->r2 = MEM_HU(0X3E, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x40($a0)
    ctx->r2 = MEM_HU(0X40, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x42($a0)
    ctx->r2 = MEM_HU(0X42, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x46($a0)
    ctx->r2 = MEM_HU(0X46, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x48($a0)
    ctx->r2 = MEM_HU(0X48, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x4A($a0)
    ctx->r2 = MEM_HU(0X4A, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x4C($a0)
    ctx->r2 = MEM_HU(0X4C, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x4E($a0)
    ctx->r2 = MEM_HU(0X4E, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x52($a0)
    ctx->r2 = MEM_HU(0X52, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x54($a0)
    ctx->r2 = MEM_HU(0X54, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x56($a0)
    ctx->r2 = MEM_HU(0X56, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(0X58, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x5A($a0)
    ctx->r2 = MEM_HU(0X5A, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x5C($a0)
    ctx->r2 = MEM_HU(0X5C, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x5E($a0)
    ctx->r2 = MEM_HU(0X5E, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x60($a0)
    ctx->r2 = MEM_HU(0X60, ctx->r4);
    // nop

    // beq         $s0, $v0, L_8005F7C8
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005F7C8;
    }
    // nop

    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sh          $v1, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r3;
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $s0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r16;
L_8005F7C8:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x10A
    ctx->r2 = SIGNED(ctx->r16) < 0X10A ? 1 : 0;
    // bne         $v0, $zero, L_8005F660
    if (ctx->r2 != 0) {
        // addu        $v0, $s0, $a1
        ctx->r2 = ADD32(ctx->r16, ctx->r5);
        goto L_8005F660;
    }
    // addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // j           L_8005F878
    recomp_vram_call(rdram, ctx, 0x8005F878);
    return;
    // addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
;}
