#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libspu.h"

void SpuSetCommonAttr(uint8_t* rdram, recomp_context* ctx) 
{
    SpuCommonAttr* attr = (SpuCommonAttr*)GET_PTR(ctx->r4);

    if (attr) {
        SpuSetCommonAttr(attr);
    }
    return;


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(0X0, ctx->r4);
    // nop

    // sltiu       $t2, $t1, 0x1
    ctx->r10 = ctx->r9 < 0X1 ? 1 : 0;
    // bne         $t2, $zero, L_8006CCF0
    if (ctx->r10 != 0) {
        // addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
        goto L_8006CCF0;
    }
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // andi        $v0, $t1, 0x1
    ctx->r2 = ctx->r9 & 0X1;
    // beq         $v0, $zero, L_8006CD98
    if (ctx->r2 == 0) {
        // andi        $v0, $t1, 0x4
        ctx->r2 = ctx->r9 & 0X4;
        goto L_8006CD98;
    }
    // andi        $v0, $t1, 0x4
    ctx->r2 = ctx->r9 & 0X4;
    // beq         $v0, $zero, L_8006CD54
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006CD54;
    }
    // nop

L_8006CCF0:
    // lh          $v1, 0x8($a0)
    ctx->r3 = MEM_HS(0X8, ctx->r4);
    // nop

    // sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_8006CD54
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8006CD54;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addu        $at, $at, $v0
    gpr jr_addend_8006CD14;
    jr_addend_8006CD14 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x3EA0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8006CD14 >> 2) {
        case 0: goto L_8006CD54; break;
        case 1: goto L_8006CD1C; break;
        case 2: goto L_8006CD24; break;
        case 3: goto L_8006CD2C; break;
        case 4: goto L_8006CD34; break;
        case 5: goto L_8006CD3C; break;
        case 6: goto L_8006CD44; break;
        case 7: goto L_8006CD4C; break;
        default: switch_error(__func__, 0x8006CD14, 0x80013EA0);
    }
    // nop

L_8006CD1C:
    // j           L_8006CD5C
    // ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    goto L_8006CD5C;
    // ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
L_8006CD24:
    // j           L_8006CD5C
    // ori         $a1, $zero, 0x9000
    ctx->r5 = 0 | 0X9000;
    goto L_8006CD5C;
    // ori         $a1, $zero, 0x9000
    ctx->r5 = 0 | 0X9000;
L_8006CD2C:
    // j           L_8006CD5C
    // ori         $a1, $zero, 0xA000
    ctx->r5 = 0 | 0XA000;
    goto L_8006CD5C;
    // ori         $a1, $zero, 0xA000
    ctx->r5 = 0 | 0XA000;
L_8006CD34:
    // j           L_8006CD5C
    // ori         $a1, $zero, 0xB000
    ctx->r5 = 0 | 0XB000;
    goto L_8006CD5C;
    // ori         $a1, $zero, 0xB000
    ctx->r5 = 0 | 0XB000;
L_8006CD3C:
    // j           L_8006CD5C
    // ori         $a1, $zero, 0xC000
    ctx->r5 = 0 | 0XC000;
    goto L_8006CD5C;
    // ori         $a1, $zero, 0xC000
    ctx->r5 = 0 | 0XC000;
L_8006CD44:
    // j           L_8006CD5C
    // ori         $a1, $zero, 0xD000
    ctx->r5 = 0 | 0XD000;
    goto L_8006CD5C;
    // ori         $a1, $zero, 0xD000
    ctx->r5 = 0 | 0XD000;
L_8006CD4C:
    // j           L_8006CD5C
    // ori         $a1, $zero, 0xE000
    ctx->r5 = 0 | 0XE000;
    goto L_8006CD5C;
    // ori         $a1, $zero, 0xE000
    ctx->r5 = 0 | 0XE000;
L_8006CD54:
    // lhu         $a2, 0x4($a0)
    ctx->r6 = MEM_HU(0X4, ctx->r4);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8006CD5C:
    // beq         $a1, $zero, L_8006CD88
    if (ctx->r5 == 0) {
        // andi        $v0, $a2, 0x7FFF
        ctx->r2 = ctx->r6 & 0X7FFF;
        goto L_8006CD88;
    }
    // andi        $v0, $a2, 0x7FFF
    ctx->r2 = ctx->r6 & 0X7FFF;
    // lh          $a3, 0x4($a0)
    ctx->r7 = MEM_HS(0X4, ctx->r4);
    // lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(0X4, ctx->r4);
    // slti        $v0, $a3, 0x80
    ctx->r2 = SIGNED(ctx->r7) < 0X80 ? 1 : 0;
    // beq         $v0, $zero, L_8006CD84
    if (ctx->r2 == 0) {
        // addiu       $a2, $zero, 0x7F
        ctx->r6 = ADD32(0, 0X7F);
        goto L_8006CD84;
    }
    // addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // bltz        $a3, L_8006CD84
    if (SIGNED(ctx->r7) < 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_8006CD84;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_8006CD84:
    // andi        $v0, $a2, 0x7FFF
    ctx->r2 = ctx->r6 & 0X7FFF;
L_8006CD88:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // sh          $v0, 0x180($v1)
    MEM_H(0X180, ctx->r3) = ctx->r2;
L_8006CD98:
    // bne         $t2, $zero, L_8006CDB0
    if (ctx->r10 != 0) {
        // andi        $v0, $t1, 0x2
        ctx->r2 = ctx->r9 & 0X2;
        goto L_8006CDB0;
    }
    // andi        $v0, $t1, 0x2
    ctx->r2 = ctx->r9 & 0X2;
    // beq         $v0, $zero, L_8006CE58
    if (ctx->r2 == 0) {
        // andi        $v0, $t1, 0x8
        ctx->r2 = ctx->r9 & 0X8;
        goto L_8006CE58;
    }
    // andi        $v0, $t1, 0x8
    ctx->r2 = ctx->r9 & 0X8;
    // beq         $v0, $zero, L_8006CE14
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006CE14;
    }
    // nop

L_8006CDB0:
    // lh          $v1, 0xA($a0)
    ctx->r3 = MEM_HS(0XA, ctx->r4);
    // nop

    // sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_8006CE14
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8006CE14;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addu        $at, $at, $v0
    gpr jr_addend_8006CDD4;
    jr_addend_8006CDD4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x3EC0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8006CDD4 >> 2) {
        case 0: goto L_8006CE14; break;
        case 1: goto L_8006CDDC; break;
        case 2: goto L_8006CDE4; break;
        case 3: goto L_8006CDEC; break;
        case 4: goto L_8006CDF4; break;
        case 5: goto L_8006CDFC; break;
        case 6: goto L_8006CE04; break;
        case 7: goto L_8006CE0C; break;
        default: switch_error(__func__, 0x8006CDD4, 0x80013EC0);
    }
    // nop

L_8006CDDC:
    // j           L_8006CE1C
    // ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    goto L_8006CE1C;
    // ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
L_8006CDE4:
    // j           L_8006CE1C
    // ori         $a1, $zero, 0x9000
    ctx->r5 = 0 | 0X9000;
    goto L_8006CE1C;
    // ori         $a1, $zero, 0x9000
    ctx->r5 = 0 | 0X9000;
L_8006CDEC:
    // j           L_8006CE1C
    // ori         $a1, $zero, 0xA000
    ctx->r5 = 0 | 0XA000;
    goto L_8006CE1C;
    // ori         $a1, $zero, 0xA000
    ctx->r5 = 0 | 0XA000;
L_8006CDF4:
    // j           L_8006CE1C
    // ori         $a1, $zero, 0xB000
    ctx->r5 = 0 | 0XB000;
    goto L_8006CE1C;
    // ori         $a1, $zero, 0xB000
    ctx->r5 = 0 | 0XB000;
L_8006CDFC:
    // j           L_8006CE1C
    // ori         $a1, $zero, 0xC000
    ctx->r5 = 0 | 0XC000;
    goto L_8006CE1C;
    // ori         $a1, $zero, 0xC000
    ctx->r5 = 0 | 0XC000;
L_8006CE04:
    // j           L_8006CE1C
    // ori         $a1, $zero, 0xD000
    ctx->r5 = 0 | 0XD000;
    goto L_8006CE1C;
    // ori         $a1, $zero, 0xD000
    ctx->r5 = 0 | 0XD000;
L_8006CE0C:
    // j           L_8006CE1C
    // ori         $a1, $zero, 0xE000
    ctx->r5 = 0 | 0XE000;
    goto L_8006CE1C;
    // ori         $a1, $zero, 0xE000
    ctx->r5 = 0 | 0XE000;
L_8006CE14:
    // lhu         $t0, 0x6($a0)
    ctx->r8 = MEM_HU(0X6, ctx->r4);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8006CE1C:
    // beq         $a1, $zero, L_8006CE48
    if (ctx->r5 == 0) {
        // andi        $v0, $t0, 0x7FFF
        ctx->r2 = ctx->r8 & 0X7FFF;
        goto L_8006CE48;
    }
    // andi        $v0, $t0, 0x7FFF
    ctx->r2 = ctx->r8 & 0X7FFF;
    // lh          $a2, 0x6($a0)
    ctx->r6 = MEM_HS(0X6, ctx->r4);
    // lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(0X6, ctx->r4);
    // slti        $v0, $a2, 0x80
    ctx->r2 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // beq         $v0, $zero, L_8006CE44
    if (ctx->r2 == 0) {
        // addiu       $t0, $zero, 0x7F
        ctx->r8 = ADD32(0, 0X7F);
        goto L_8006CE44;
    }
    // addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // bltz        $a2, L_8006CE44
    if (SIGNED(ctx->r6) < 0) {
        // addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
        goto L_8006CE44;
    }
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
L_8006CE44:
    // andi        $v0, $t0, 0x7FFF
    ctx->r2 = ctx->r8 & 0X7FFF;
L_8006CE48:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // sh          $v0, 0x182($v1)
    MEM_H(0X182, ctx->r3) = ctx->r2;
L_8006CE58:
    // bne         $t2, $zero, L_8006CE68
    if (ctx->r10 != 0) {
        // andi        $v0, $t1, 0x40
        ctx->r2 = ctx->r9 & 0X40;
        goto L_8006CE68;
    }
    // andi        $v0, $t1, 0x40
    ctx->r2 = ctx->r9 & 0X40;
    // beq         $v0, $zero, L_8006CE7C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006CE7C;
    }
    // nop

L_8006CE68:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x10($a0)
    ctx->r2 = MEM_HU(0X10, ctx->r4);
    // nop

    // sh          $v0, 0x1B0($v1)
    MEM_H(0X1B0, ctx->r3) = ctx->r2;
L_8006CE7C:
    // bne         $t2, $zero, L_8006CE8C
    if (ctx->r10 != 0) {
        // andi        $v0, $t1, 0x80
        ctx->r2 = ctx->r9 & 0X80;
        goto L_8006CE8C;
    }
    // andi        $v0, $t1, 0x80
    ctx->r2 = ctx->r9 & 0X80;
    // beq         $v0, $zero, L_8006CEA0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006CEA0;
    }
    // nop

L_8006CE8C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(0X12, ctx->r4);
    // nop

    // sh          $v0, 0x1B2($v1)
    MEM_H(0X1B2, ctx->r3) = ctx->r2;
L_8006CEA0:
    // bne         $t2, $zero, L_8006CEB0
    if (ctx->r10 != 0) {
        // andi        $v0, $t1, 0x400
        ctx->r2 = ctx->r9 & 0X400;
        goto L_8006CEB0;
    }
    // andi        $v0, $t1, 0x400
    ctx->r2 = ctx->r9 & 0X400;
    // beq         $v0, $zero, L_8006CEC4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006CEC4;
    }
    // nop

L_8006CEB0:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x1C($a0)
    ctx->r2 = MEM_HU(0X1C, ctx->r4);
    // nop

    // sh          $v0, 0x1B4($v1)
    MEM_H(0X1B4, ctx->r3) = ctx->r2;
L_8006CEC4:
    // bne         $t2, $zero, L_8006CED4
    if (ctx->r10 != 0) {
        // andi        $v0, $t1, 0x800
        ctx->r2 = ctx->r9 & 0X800;
        goto L_8006CED4;
    }
    // andi        $v0, $t1, 0x800
    ctx->r2 = ctx->r9 & 0X800;
    // beq         $v0, $zero, L_8006CEE8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006CEE8;
    }
    // nop

L_8006CED4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $v0, 0x1E($a0)
    ctx->r2 = MEM_HU(0X1E, ctx->r4);
    // nop

    // sh          $v0, 0x1B6($v1)
    MEM_H(0X1B6, ctx->r3) = ctx->r2;
L_8006CEE8:
    // bne         $t2, $zero, L_8006CEF8
    if (ctx->r10 != 0) {
        // andi        $v0, $t1, 0x100
        ctx->r2 = ctx->r9 & 0X100;
        goto L_8006CEF8;
    }
    // andi        $v0, $t1, 0x100
    ctx->r2 = ctx->r9 & 0X100;
    // beq         $v0, $zero, L_8006CF3C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006CF3C;
    }
    // nop

L_8006CEF8:
    // lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(0X14, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8006CF20
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006CF20;
    }
    // nop

    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // j           L_8006CF38
    // andi        $v0, $v0, 0xFFFB
    ctx->r2 = ctx->r2 & 0XFFFB;
    goto L_8006CF38;
    // andi        $v0, $v0, 0xFFFB
    ctx->r2 = ctx->r2 & 0XFFFB;
L_8006CF20:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
L_8006CF38:
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
L_8006CF3C:
    // bne         $t2, $zero, L_8006CF4C
    if (ctx->r10 != 0) {
        // andi        $v0, $t1, 0x200
        ctx->r2 = ctx->r9 & 0X200;
        goto L_8006CF4C;
    }
    // andi        $v0, $t1, 0x200
    ctx->r2 = ctx->r9 & 0X200;
    // beq         $v0, $zero, L_8006CF90
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006CF90;
    }
    // nop

L_8006CF4C:
    // lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(0X18, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8006CF74
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006CF74;
    }
    // nop

    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // j           L_8006CF8C
    // andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    goto L_8006CF8C;
    // andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
L_8006CF74:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
L_8006CF8C:
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
L_8006CF90:
    // bne         $t2, $zero, L_8006CFA0
    if (ctx->r10 != 0) {
        // andi        $v0, $t1, 0x1000
        ctx->r2 = ctx->r9 & 0X1000;
        goto L_8006CFA0;
    }
    // andi        $v0, $t1, 0x1000
    ctx->r2 = ctx->r9 & 0X1000;
    // beq         $v0, $zero, L_8006CFE4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006CFE4;
    }
    // nop

L_8006CFA0:
    // lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(0X20, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8006CFC8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006CFC8;
    }
    // nop

    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // j           L_8006CFE0
    // andi        $v0, $v0, 0xFFF7
    ctx->r2 = ctx->r2 & 0XFFF7;
    goto L_8006CFE0;
    // andi        $v0, $v0, 0xFFF7
    ctx->r2 = ctx->r2 & 0XFFF7;
L_8006CFC8:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
L_8006CFE0:
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
L_8006CFE4:
    // bne         $t2, $zero, L_8006CFF4
    if (ctx->r10 != 0) {
        // andi        $v0, $t1, 0x2000
        ctx->r2 = ctx->r9 & 0X2000;
        goto L_8006CFF4;
    }
    // andi        $v0, $t1, 0x2000
    ctx->r2 = ctx->r9 & 0X2000;
    // beq         $v0, $zero, L_8006D038
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006D038;
    }
    // nop

L_8006CFF4:
    // lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(0X24, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8006D01C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006D01C;
    }
    // nop

    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // j           L_8006D034
    // andi        $v0, $v0, 0xFFFD
    ctx->r2 = ctx->r2 & 0XFFFD;
    goto L_8006D034;
    // andi        $v0, $v0, 0xFFFD
    ctx->r2 = ctx->r2 & 0XFFFD;
L_8006D01C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
L_8006D034:
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
L_8006D038:
    // jr          $ra
    // nop

    return;
    // nop

;}
