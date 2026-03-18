#include "recomp.h"
#include "disable_warnings.h"

void _spu_setReverbAttr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(0X0, ctx->r4);
    // nop

    // sltiu       $a2, $a1, 0x1
    ctx->r6 = ctx->r5 < 0X1 ? 1 : 0;
    // bne         $a2, $zero, L_8006FC20
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x1
        ctx->r2 = ctx->r5 & 0X1;
        goto L_8006FC20;
    }
    // andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // beq         $v0, $zero, L_8006FC34
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FC34;
    }
    // nop

L_8006FC20:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // nop

    // sh          $v0, 0x1C0($v1)
    MEM_H(0X1C0, ctx->r3) = ctx->r2;
L_8006FC34:
    // bne         $a2, $zero, L_8006FC44
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x2
        ctx->r2 = ctx->r5 & 0X2;
        goto L_8006FC44;
    }
    // andi        $v0, $a1, 0x2
    ctx->r2 = ctx->r5 & 0X2;
    // beq         $v0, $zero, L_8006FC58
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FC58;
    }
    // nop

L_8006FC44:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(0X6, ctx->r4);
    // nop

    // sh          $v0, 0x1C2($v1)
    MEM_H(0X1C2, ctx->r3) = ctx->r2;
L_8006FC58:
    // bne         $a2, $zero, L_8006FC68
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x4
        ctx->r2 = ctx->r5 & 0X4;
        goto L_8006FC68;
    }
    // andi        $v0, $a1, 0x4
    ctx->r2 = ctx->r5 & 0X4;
    // beq         $v0, $zero, L_8006FC7C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FC7C;
    }
    // nop

L_8006FC68:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // nop

    // sh          $v0, 0x1C4($v1)
    MEM_H(0X1C4, ctx->r3) = ctx->r2;
L_8006FC7C:
    // bne         $a2, $zero, L_8006FC8C
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x8
        ctx->r2 = ctx->r5 & 0X8;
        goto L_8006FC8C;
    }
    // andi        $v0, $a1, 0x8
    ctx->r2 = ctx->r5 & 0X8;
    // beq         $v0, $zero, L_8006FCA0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FCA0;
    }
    // nop

L_8006FC8C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(0XA, ctx->r4);
    // nop

    // sh          $v0, 0x1C6($v1)
    MEM_H(0X1C6, ctx->r3) = ctx->r2;
L_8006FCA0:
    // bne         $a2, $zero, L_8006FCB0
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x10
        ctx->r2 = ctx->r5 & 0X10;
        goto L_8006FCB0;
    }
    // andi        $v0, $a1, 0x10
    ctx->r2 = ctx->r5 & 0X10;
    // beq         $v0, $zero, L_8006FCC4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FCC4;
    }
    // nop

L_8006FCB0:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(0XC, ctx->r4);
    // nop

    // sh          $v0, 0x1C8($v1)
    MEM_H(0X1C8, ctx->r3) = ctx->r2;
L_8006FCC4:
    // bne         $a2, $zero, L_8006FCD4
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x20
        ctx->r2 = ctx->r5 & 0X20;
        goto L_8006FCD4;
    }
    // andi        $v0, $a1, 0x20
    ctx->r2 = ctx->r5 & 0X20;
    // beq         $v0, $zero, L_8006FCE8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FCE8;
    }
    // nop

L_8006FCD4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0xE($a0)
    ctx->r2 = MEM_HU(0XE, ctx->r4);
    // nop

    // sh          $v0, 0x1CA($v1)
    MEM_H(0X1CA, ctx->r3) = ctx->r2;
L_8006FCE8:
    // bne         $a2, $zero, L_8006FCF8
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x40
        ctx->r2 = ctx->r5 & 0X40;
        goto L_8006FCF8;
    }
    // andi        $v0, $a1, 0x40
    ctx->r2 = ctx->r5 & 0X40;
    // beq         $v0, $zero, L_8006FD0C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FD0C;
    }
    // nop

L_8006FCF8:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x10($a0)
    ctx->r2 = MEM_HU(0X10, ctx->r4);
    // nop

    // sh          $v0, 0x1CC($v1)
    MEM_H(0X1CC, ctx->r3) = ctx->r2;
L_8006FD0C:
    // bne         $a2, $zero, L_8006FD1C
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x80
        ctx->r2 = ctx->r5 & 0X80;
        goto L_8006FD1C;
    }
    // andi        $v0, $a1, 0x80
    ctx->r2 = ctx->r5 & 0X80;
    // beq         $v0, $zero, L_8006FD30
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FD30;
    }
    // nop

L_8006FD1C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(0X12, ctx->r4);
    // nop

    // sh          $v0, 0x1CE($v1)
    MEM_H(0X1CE, ctx->r3) = ctx->r2;
L_8006FD30:
    // bne         $a2, $zero, L_8006FD40
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x100
        ctx->r2 = ctx->r5 & 0X100;
        goto L_8006FD40;
    }
    // andi        $v0, $a1, 0x100
    ctx->r2 = ctx->r5 & 0X100;
    // beq         $v0, $zero, L_8006FD54
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FD54;
    }
    // nop

L_8006FD40:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x14($a0)
    ctx->r2 = MEM_HU(0X14, ctx->r4);
    // nop

    // sh          $v0, 0x1D0($v1)
    MEM_H(0X1D0, ctx->r3) = ctx->r2;
L_8006FD54:
    // bne         $a2, $zero, L_8006FD64
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x200
        ctx->r2 = ctx->r5 & 0X200;
        goto L_8006FD64;
    }
    // andi        $v0, $a1, 0x200
    ctx->r2 = ctx->r5 & 0X200;
    // beq         $v0, $zero, L_8006FD78
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FD78;
    }
    // nop

L_8006FD64:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x16($a0)
    ctx->r2 = MEM_HU(0X16, ctx->r4);
    // nop

    // sh          $v0, 0x1D2($v1)
    MEM_H(0X1D2, ctx->r3) = ctx->r2;
L_8006FD78:
    // bne         $a2, $zero, L_8006FD88
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x400
        ctx->r2 = ctx->r5 & 0X400;
        goto L_8006FD88;
    }
    // andi        $v0, $a1, 0x400
    ctx->r2 = ctx->r5 & 0X400;
    // beq         $v0, $zero, L_8006FD9C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FD9C;
    }
    // nop

L_8006FD88:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x18($a0)
    ctx->r2 = MEM_HU(0X18, ctx->r4);
    // nop

    // sh          $v0, 0x1D4($v1)
    MEM_H(0X1D4, ctx->r3) = ctx->r2;
L_8006FD9C:
    // bne         $a2, $zero, L_8006FDAC
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x800
        ctx->r2 = ctx->r5 & 0X800;
        goto L_8006FDAC;
    }
    // andi        $v0, $a1, 0x800
    ctx->r2 = ctx->r5 & 0X800;
    // beq         $v0, $zero, L_8006FDC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FDC0;
    }
    // nop

L_8006FDAC:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x1A($a0)
    ctx->r2 = MEM_HU(0X1A, ctx->r4);
    // nop

    // sh          $v0, 0x1D6($v1)
    MEM_H(0X1D6, ctx->r3) = ctx->r2;
L_8006FDC0:
    // bne         $a2, $zero, L_8006FDD0
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x1000
        ctx->r2 = ctx->r5 & 0X1000;
        goto L_8006FDD0;
    }
    // andi        $v0, $a1, 0x1000
    ctx->r2 = ctx->r5 & 0X1000;
    // beq         $v0, $zero, L_8006FDE4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FDE4;
    }
    // nop

L_8006FDD0:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x1C($a0)
    ctx->r2 = MEM_HU(0X1C, ctx->r4);
    // nop

    // sh          $v0, 0x1D8($v1)
    MEM_H(0X1D8, ctx->r3) = ctx->r2;
L_8006FDE4:
    // bne         $a2, $zero, L_8006FDF4
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x2000
        ctx->r2 = ctx->r5 & 0X2000;
        goto L_8006FDF4;
    }
    // andi        $v0, $a1, 0x2000
    ctx->r2 = ctx->r5 & 0X2000;
    // beq         $v0, $zero, L_8006FE08
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FE08;
    }
    // nop

L_8006FDF4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x1E($a0)
    ctx->r2 = MEM_HU(0X1E, ctx->r4);
    // nop

    // sh          $v0, 0x1DA($v1)
    MEM_H(0X1DA, ctx->r3) = ctx->r2;
L_8006FE08:
    // bne         $a2, $zero, L_8006FE18
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x4000
        ctx->r2 = ctx->r5 & 0X4000;
        goto L_8006FE18;
    }
    // andi        $v0, $a1, 0x4000
    ctx->r2 = ctx->r5 & 0X4000;
    // beq         $v0, $zero, L_8006FE2C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FE2C;
    }
    // nop

L_8006FE18:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x20($a0)
    ctx->r2 = MEM_HU(0X20, ctx->r4);
    // nop

    // sh          $v0, 0x1DC($v1)
    MEM_H(0X1DC, ctx->r3) = ctx->r2;
L_8006FE2C:
    // bne         $a2, $zero, L_8006FE3C
    if (ctx->r6 != 0) {
        // andi        $v0, $a1, 0x8000
        ctx->r2 = ctx->r5 & 0X8000;
        goto L_8006FE3C;
    }
    // andi        $v0, $a1, 0x8000
    ctx->r2 = ctx->r5 & 0X8000;
    // beq         $v0, $zero, L_8006FE50
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FE50;
    }
    // nop

L_8006FE3C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x22($a0)
    ctx->r2 = MEM_HU(0X22, ctx->r4);
    // nop

    // sh          $v0, 0x1DE($v1)
    MEM_H(0X1DE, ctx->r3) = ctx->r2;
L_8006FE50:
    // bne         $a2, $zero, L_8006FE64
    if (ctx->r6 != 0) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_8006FE64;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_8006FE78
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FE78;
    }
    // nop

L_8006FE64:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x24($a0)
    ctx->r2 = MEM_HU(0X24, ctx->r4);
    // nop

    // sh          $v0, 0x1E0($v1)
    MEM_H(0X1E0, ctx->r3) = ctx->r2;
L_8006FE78:
    // bne         $a2, $zero, L_8006FE8C
    if (ctx->r6 != 0) {
        // lui         $v0, 0x2
        ctx->r2 = S32(0X2 << 16);
        goto L_8006FE8C;
    }
    // lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_8006FEA0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FEA0;
    }
    // nop

L_8006FE8C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x26($a0)
    ctx->r2 = MEM_HU(0X26, ctx->r4);
    // nop

    // sh          $v0, 0x1E2($v1)
    MEM_H(0X1E2, ctx->r3) = ctx->r2;
L_8006FEA0:
    // bne         $a2, $zero, L_8006FEB4
    if (ctx->r6 != 0) {
        // lui         $v0, 0x4
        ctx->r2 = S32(0X4 << 16);
        goto L_8006FEB4;
    }
    // lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_8006FEC8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FEC8;
    }
    // nop

L_8006FEB4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x28($a0)
    ctx->r2 = MEM_HU(0X28, ctx->r4);
    // nop

    // sh          $v0, 0x1E4($v1)
    MEM_H(0X1E4, ctx->r3) = ctx->r2;
L_8006FEC8:
    // bne         $a2, $zero, L_8006FEDC
    if (ctx->r6 != 0) {
        // lui         $v0, 0x8
        ctx->r2 = S32(0X8 << 16);
        goto L_8006FEDC;
    }
    // lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_8006FEF0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FEF0;
    }
    // nop

L_8006FEDC:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x2A($a0)
    ctx->r2 = MEM_HU(0X2A, ctx->r4);
    // nop

    // sh          $v0, 0x1E6($v1)
    MEM_H(0X1E6, ctx->r3) = ctx->r2;
L_8006FEF0:
    // bne         $a2, $zero, L_8006FF04
    if (ctx->r6 != 0) {
        // lui         $v0, 0x10
        ctx->r2 = S32(0X10 << 16);
        goto L_8006FF04;
    }
    // lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_8006FF18
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FF18;
    }
    // nop

L_8006FF04:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x2C($a0)
    ctx->r2 = MEM_HU(0X2C, ctx->r4);
    // nop

    // sh          $v0, 0x1E8($v1)
    MEM_H(0X1E8, ctx->r3) = ctx->r2;
L_8006FF18:
    // bne         $a2, $zero, L_8006FF2C
    if (ctx->r6 != 0) {
        // lui         $v0, 0x20
        ctx->r2 = S32(0X20 << 16);
        goto L_8006FF2C;
    }
    // lui         $v0, 0x20
    ctx->r2 = S32(0X20 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_8006FF40
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FF40;
    }
    // nop

L_8006FF2C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x2E($a0)
    ctx->r2 = MEM_HU(0X2E, ctx->r4);
    // nop

    // sh          $v0, 0x1EA($v1)
    MEM_H(0X1EA, ctx->r3) = ctx->r2;
L_8006FF40:
    // bne         $a2, $zero, L_8006FF54
    if (ctx->r6 != 0) {
        // lui         $v0, 0x40
        ctx->r2 = S32(0X40 << 16);
        goto L_8006FF54;
    }
    // lui         $v0, 0x40
    ctx->r2 = S32(0X40 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_8006FF68
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FF68;
    }
    // nop

L_8006FF54:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x30($a0)
    ctx->r2 = MEM_HU(0X30, ctx->r4);
    // nop

    // sh          $v0, 0x1EC($v1)
    MEM_H(0X1EC, ctx->r3) = ctx->r2;
L_8006FF68:
    // bne         $a2, $zero, L_8006FF7C
    if (ctx->r6 != 0) {
        // lui         $v0, 0x80
        ctx->r2 = S32(0X80 << 16);
        goto L_8006FF7C;
    }
    // lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_8006FF90
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FF90;
    }
    // nop

L_8006FF7C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x32($a0)
    ctx->r2 = MEM_HU(0X32, ctx->r4);
    // nop

    // sh          $v0, 0x1EE($v1)
    MEM_H(0X1EE, ctx->r3) = ctx->r2;
L_8006FF90:
    // bne         $a2, $zero, L_8006FFA4
    if (ctx->r6 != 0) {
        // lui         $v0, 0x100
        ctx->r2 = S32(0X100 << 16);
        goto L_8006FFA4;
    }
    // lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_8006FFB8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FFB8;
    }
    // nop

L_8006FFA4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x34($a0)
    ctx->r2 = MEM_HU(0X34, ctx->r4);
    // nop

    // sh          $v0, 0x1F0($v1)
    MEM_H(0X1F0, ctx->r3) = ctx->r2;
L_8006FFB8:
    // bne         $a2, $zero, L_8006FFCC
    if (ctx->r6 != 0) {
        // lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
        goto L_8006FFCC;
    }
    // lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_8006FFE0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006FFE0;
    }
    // nop

L_8006FFCC:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x36($a0)
    ctx->r2 = MEM_HU(0X36, ctx->r4);
    // nop

    // sh          $v0, 0x1F2($v1)
    MEM_H(0X1F2, ctx->r3) = ctx->r2;
L_8006FFE0:
    // bne         $a2, $zero, L_8006FFF4
    if (ctx->r6 != 0) {
        // lui         $v0, 0x400
        ctx->r2 = S32(0X400 << 16);
        goto L_8006FFF4;
    }
    // lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80070008
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070008;
    }
    // nop

L_8006FFF4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x38($a0)
    ctx->r2 = MEM_HU(0X38, ctx->r4);
    // nop

    // sh          $v0, 0x1F4($v1)
    MEM_H(0X1F4, ctx->r3) = ctx->r2;
L_80070008:
    // bne         $a2, $zero, L_8007001C
    if (ctx->r6 != 0) {
        // lui         $v0, 0x800
        ctx->r2 = S32(0X800 << 16);
        goto L_8007001C;
    }
    // lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80070030
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070030;
    }
    // nop

L_8007001C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x3A($a0)
    ctx->r2 = MEM_HU(0X3A, ctx->r4);
    // nop

    // sh          $v0, 0x1F6($v1)
    MEM_H(0X1F6, ctx->r3) = ctx->r2;
L_80070030:
    // bne         $a2, $zero, L_80070044
    if (ctx->r6 != 0) {
        // lui         $v0, 0x1000
        ctx->r2 = S32(0X1000 << 16);
        goto L_80070044;
    }
    // lui         $v0, 0x1000
    ctx->r2 = S32(0X1000 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80070058
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070058;
    }
    // nop

L_80070044:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(0X3C, ctx->r4);
    // nop

    // sh          $v0, 0x1F8($v1)
    MEM_H(0X1F8, ctx->r3) = ctx->r2;
L_80070058:
    // bne         $a2, $zero, L_8007006C
    if (ctx->r6 != 0) {
        // lui         $v0, 0x2000
        ctx->r2 = S32(0X2000 << 16);
        goto L_8007006C;
    }
    // lui         $v0, 0x2000
    ctx->r2 = S32(0X2000 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80070080
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070080;
    }
    // nop

L_8007006C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x3E($a0)
    ctx->r2 = MEM_HU(0X3E, ctx->r4);
    // nop

    // sh          $v0, 0x1FA($v1)
    MEM_H(0X1FA, ctx->r3) = ctx->r2;
L_80070080:
    // bne         $a2, $zero, L_80070094
    if (ctx->r6 != 0) {
        // lui         $v0, 0x4000
        ctx->r2 = S32(0X4000 << 16);
        goto L_80070094;
    }
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_800700A8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800700A8;
    }
    // nop

L_80070094:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x40($a0)
    ctx->r2 = MEM_HU(0X40, ctx->r4);
    // nop

    // sh          $v0, 0x1FC($v1)
    MEM_H(0X1FC, ctx->r3) = ctx->r2;
L_800700A8:
    // bne         $a2, $zero, L_800700B8
    if (ctx->r6 != 0) {
        // nop
    
        goto L_800700B8;
    }
    // nop

    // bgez        $a1, L_800700CC
    if (SIGNED(ctx->r5) >= 0) {
        // nop
    
        goto L_800700CC;
    }
    // nop

L_800700B8:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x42($a0)
    ctx->r2 = MEM_HU(0X42, ctx->r4);
    // nop

    // sh          $v0, 0x1FE($v1)
    MEM_H(0X1FE, ctx->r3) = ctx->r2;
L_800700CC:
    // jr          $ra
    // nop

    return;
    // nop

;}
