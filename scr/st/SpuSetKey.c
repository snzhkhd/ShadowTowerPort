#include "recomp.h"
#include "disable_warnings.h"

void SpuSetKey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // beq         $a0, $zero, L_80071128
    if (ctx->r4 == 0) {
        // srl         $a2, $a1, 16
        ctx->r6 = S32(U32(ctx->r5) >> 16);
        goto L_80071128;
    }
    // srl         $a2, $a1, 16
    ctx->r6 = S32(U32(ctx->r5) >> 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $a0, $v0, L_800711F8
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_800711F8;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE0C($v0)
    ctx->r2 = MEM_W(0XE0C, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80071108
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80071108;
    }
    // nop

    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x7A58
    ctx->r4 = ADD32(ctx->r4, -0X7A58);
    // sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // sh          $a2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r6;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xDD8($v0)
    ctx->r2 = MEM_W(0XDD8, ctx->r2);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xDD8($at)
    MEM_W(0XDD8, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xDD4($v0)
    ctx->r2 = MEM_W(0XDD4, ctx->r2);
    // nop

    // or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xDD4($at)
    MEM_W(0XDD4, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // nop

    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // beq         $v0, $zero, L_800710E0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800710E0;
    }
    // nop

    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // nor         $v1, $zero, $a1
    ctx->r3 = ~(0 | ctx->r5);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
L_800710E0:
    // lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(0X6, ctx->r4);
    // nop

    // and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // beq         $v0, $zero, L_800711F8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800711F8;
    }
    // nop

    // lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(0X6, ctx->r4);
    // nor         $v1, $zero, $a2
    ctx->r3 = ~(0 | ctx->r6);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // j           L_800711F8
    // sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    goto L_800711F8;
    // sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
L_80071108:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xDAC($v0)
    ctx->r2 = MEM_W(0XDAC, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // sh          $a1, 0x188($v1)
    MEM_H(0X188, ctx->r3) = ctx->r5;
    // j           L_800711F0
    // sh          $a2, 0x18A($v1)
    MEM_H(0X18A, ctx->r3) = ctx->r6;
    goto L_800711F0;
    // sh          $a2, 0x18A($v1)
    MEM_H(0X18A, ctx->r3) = ctx->r6;
L_80071128:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE0C($v0)
    ctx->r2 = MEM_W(0XE0C, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_800711CC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800711CC;
    }
    // nop

    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x7A58
    ctx->r4 = ADD32(ctx->r4, -0X7A58);
    // sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
    // sh          $a2, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r6;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xDD8($v0)
    ctx->r2 = MEM_W(0XDD8, ctx->r2);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xDD8($at)
    MEM_W(0XDD8, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xDD4($v0)
    ctx->r2 = MEM_W(0XDD4, ctx->r2);
    // nor         $v1, $zero, $a1
    ctx->r3 = ~(0 | ctx->r5);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xDD4($at)
    MEM_W(0XDD4, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // beq         $v0, $zero, L_800711A4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800711A4;
    }
    // nop

    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_800711A4:
    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // nop

    // and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // beq         $v0, $zero, L_800711F8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800711F8;
    }
    // nop

    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // nor         $v1, $zero, $a2
    ctx->r3 = ~(0 | ctx->r6);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // j           L_800711F8
    // sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    goto L_800711F8;
    // sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
L_800711CC:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // nop

    // sh          $a1, 0x18C($v0)
    MEM_H(0X18C, ctx->r2) = ctx->r5;
    // sh          $a2, 0x18E($v0)
    MEM_H(0X18E, ctx->r2) = ctx->r6;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xDAC($v0)
    ctx->r2 = MEM_W(0XDAC, ctx->r2);
    // nor         $v1, $zero, $a1
    ctx->r3 = ~(0 | ctx->r5);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_800711F0:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xDAC($at)
    MEM_W(0XDAC, ctx->r1) = ctx->r2;
L_800711F8:
    // jr          $ra
    // nop

    return;
    // nop

;}
