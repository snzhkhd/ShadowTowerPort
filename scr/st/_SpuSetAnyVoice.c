#include "recomp.h"
#include "disable_warnings.h"

void _SpuSetAnyVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE0C($v0)
    ctx->r2 = MEM_W(0XE0C, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x7BE0
    ctx->r4 = ADD32(ctx->r4, -0X7BE0);
    // bne         $v0, $zero, L_80070D80
    if (ctx->r2 != 0) {
        // addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
        goto L_80070D80;
    }
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD40($a0)
    ctx->r4 = MEM_W(0XD40, ctx->r4);
L_80070D80:
    // sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // beq         $t1, $t3, L_80070DD8
    if (ctx->r9 == ctx->r11) {
        // or          $t2, $v0, $v1
        ctx->r10 = ctx->r2 | ctx->r3;
        goto L_80070DD8;
    }
    // or          $t2, $v0, $v1
    ctx->r10 = ctx->r2 | ctx->r3;
    // slti        $v0, $t1, 0x2
    ctx->r2 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80070DC8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_80070DC8;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // beq         $t1, $zero, L_80070E94
    if (ctx->r9 == 0) {
        // lui         $v0, 0xFF
        ctx->r2 = S32(0XFF << 16);
        goto L_80070E94;
    }
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // j           L_80071008
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    goto L_80071008;
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
L_80070DC8:
    // beq         $t1, $v0, L_80070F68
    if (ctx->r9 == ctx->r2) {
        // lui         $v0, 0xFF
        ctx->r2 = S32(0XFF << 16);
        goto L_80070F68;
    }
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // j           L_80071008
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    goto L_80071008;
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
L_80070DD8:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE0C($v0)
    ctx->r2 = MEM_W(0XE0C, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80070E4C
    if (ctx->r2 == 0) {
        // sll         $v1, $a2, 1
        ctx->r3 = S32(ctx->r6) << 1;
        goto L_80070E4C;
    }
    // sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6) << 1;
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // addiu       $a1, $a1, -0x7BE0
    ctx->r5 = ADD32(ctx->r5, -0X7BE0);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $a0, $a3, 1
    ctx->r4 = S32(ctx->r7) << 1;
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // or          $v0, $v0, $t0
    ctx->r2 = ctx->r2 | ctx->r8;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // srl         $v0, $t0, 16
    ctx->r2 = S32(U32(ctx->r8) >> 16);
    // lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(0X0, ctx->r4);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // addiu       $v0, $a2, -0xC6
    ctx->r2 = ADD32(ctx->r6, -0XC6);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xDD8($v1)
    ctx->r3 = MEM_W(0XDD8, ctx->r3);
    // sllv        $v0, $t3, $v0
    ctx->r2 = S32(ctx->r11) << (ctx->r2 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, 0xDD8($at)
    MEM_W(0XDD8, ctx->r1) = ctx->r3;
    // j           L_80070E84
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    goto L_80070E84;
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
L_80070E4C:
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xD40($a1)
    ctx->r5 = MEM_W(0XD40, ctx->r5);
    // sll         $a0, $a3, 1
    ctx->r4 = S32(ctx->r7) << 1;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // or          $v0, $v0, $t0
    ctx->r2 = ctx->r2 | ctx->r8;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // srl         $v0, $t0, 16
    ctx->r2 = S32(U32(ctx->r8) >> 16);
    // lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(0X0, ctx->r4);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
L_80070E84:
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // and         $v0, $t0, $v0
    ctx->r2 = ctx->r8 & ctx->r2;
    // j           L_80071000
    // or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    goto L_80071000;
    // or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
L_80070E94:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE0C($v0)
    ctx->r2 = MEM_W(0XE0C, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80070F10
    if (ctx->r2 == 0) {
        // sll         $v1, $a2, 1
        ctx->r3 = S32(ctx->r6) << 1;
        goto L_80070F10;
    }
    // sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6) << 1;
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // addiu       $a1, $a1, -0x7BE0
    ctx->r5 = ADD32(ctx->r5, -0X7BE0);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nor         $a0, $zero, $t0
    ctx->r4 = ~(0 | ctx->r8);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sll         $a0, $a3, 1
    ctx->r4 = S32(ctx->r7) << 1;
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // srl         $v0, $t0, 16
    ctx->r2 = S32(U32(ctx->r8) >> 16);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(0X0, ctx->r4);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // addiu       $v0, $a2, -0xC6
    ctx->r2 = ADD32(ctx->r6, -0XC6);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xDD8($v1)
    ctx->r3 = MEM_W(0XDD8, ctx->r3);
    // sllv        $v0, $t3, $v0
    ctx->r2 = S32(ctx->r11) << (ctx->r2 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, 0xDD8($at)
    MEM_W(0XDD8, ctx->r1) = ctx->r3;
    // j           L_80070F54
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    goto L_80070F54;
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
L_80070F10:
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xD40($a1)
    ctx->r5 = MEM_W(0XD40, ctx->r5);
    // nop

    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nor         $a0, $zero, $t0
    ctx->r4 = ~(0 | ctx->r8);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sll         $a0, $a3, 1
    ctx->r4 = S32(ctx->r7) << 1;
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // srl         $v0, $t0, 16
    ctx->r2 = S32(U32(ctx->r8) >> 16);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(0X0, ctx->r4);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
L_80070F54:
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // and         $v0, $t0, $v0
    ctx->r2 = ctx->r8 & ctx->r2;
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // j           L_80071000
    // and         $t2, $t2, $v0
    ctx->r10 = ctx->r10 & ctx->r2;
    goto L_80071000;
    // and         $t2, $t2, $v0
    ctx->r10 = ctx->r10 & ctx->r2;
L_80070F68:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE0C($v0)
    ctx->r2 = MEM_W(0XE0C, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80070FCC
    if (ctx->r2 == 0) {
        // sll         $v1, $a3, 1
        ctx->r3 = S32(ctx->r7) << 1;
        goto L_80070FCC;
    }
    // sll         $v1, $a3, 1
    ctx->r3 = S32(ctx->r7) << 1;
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x7BE0
    ctx->r4 = ADD32(ctx->r4, -0X7BE0);
    // sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // srl         $v0, $t0, 16
    ctx->r2 = S32(U32(ctx->r8) >> 16);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // addiu       $v0, $a2, -0xC6
    ctx->r2 = ADD32(ctx->r6, -0XC6);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xDD8($v1)
    ctx->r3 = MEM_W(0XDD8, ctx->r3);
    // sllv        $v0, $t3, $v0
    ctx->r2 = S32(ctx->r11) << (ctx->r2 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, 0xDD8($at)
    MEM_W(0XDD8, ctx->r1) = ctx->r3;
    // j           L_80070FF8
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    goto L_80070FF8;
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
L_80070FCC:
    // sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6) << 1;
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD40($a0)
    ctx->r4 = MEM_W(0XD40, ctx->r4);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // srl         $v0, $t0, 16
    ctx->r2 = S32(U32(ctx->r8) >> 16);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
L_80070FF8:
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // and         $t2, $t0, $v0
    ctx->r10 = ctx->r8 & ctx->r2;
L_80071000:
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
L_80071008:
    // jr          $ra
    // and         $v0, $t2, $v0
    ctx->r2 = ctx->r10 & ctx->r2;
    return;
    // and         $v0, $t2, $v0
    ctx->r2 = ctx->r10 & ctx->r2;
;}
