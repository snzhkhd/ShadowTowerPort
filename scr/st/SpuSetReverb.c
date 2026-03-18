#include "recomp.h"
#include "disable_warnings.h"

void SpuSetReverb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // beq         $s0, $zero, L_8007034C
    if (ctx->r16 == 0) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_8007034C;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $s0, $v0, L_8007036C
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8007036C;
    }
    // nop

    // j           L_800703D8
    // nop

    goto L_800703D8;
    // nop

L_8007034C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xDB4($at)
    MEM_W(0XDB4, ctx->r1) = 0;
    // j           L_800703D4
    // andi        $v0, $v0, 0xFF7F
    ctx->r2 = ctx->r2 & 0XFF7F;
    goto L_800703D4;
    // andi        $v0, $v0, 0xFF7F
    ctx->r2 = ctx->r2 & 0XFF7F;
L_8007036C:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xDB8($v0)
    ctx->r2 = MEM_W(0XDB8, ctx->r2);
    // nop

    // beq         $v0, $s0, L_800703B8
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_800703B8;
    }
    // nop

    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xDBC($a0)
    ctx->r4 = MEM_W(0XDBC, ctx->r4);
    // jal         0x8006FB74
    // nop

    _SpuIsInAllocateArea_(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // beq         $v0, $zero, L_800703B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800703B8;
    }
    // nop

    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xDB4($at)
    MEM_W(0XDB4, ctx->r1) = 0;
    // j           L_800703D4
    // andi        $v0, $v0, 0xFF7F
    ctx->r2 = ctx->r2 & 0XFF7F;
    goto L_800703D4;
    // andi        $v0, $v0, 0xFF7F
    ctx->r2 = ctx->r2 & 0XFF7F;
L_800703B8:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $s0, 0xDB4($at)
    MEM_W(0XDB4, ctx->r1) = ctx->r16;
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
L_800703D4:
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
L_800703D8:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xDB4($v0)
    ctx->r2 = MEM_W(0XDB4, ctx->r2);
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
