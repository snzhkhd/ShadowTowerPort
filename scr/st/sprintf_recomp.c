#include "recomp.h"
#include "disable_warnings.h"

void sprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // addiu       $sp, $sp, -0x250
    ctx->r29 = ADD32(ctx->r29, -0X250);
    // sw          $s4, 0x238($sp)
    MEM_W(0X238, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // addiu       $v0, $sp, 0x258
    ctx->r2 = ADD32(ctx->r29, 0X258);
    // sw          $ra, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r31;
    // sw          $s7, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r23;
    // sw          $s6, 0x240($sp)
    MEM_W(0X240, ctx->r29) = ctx->r22;
    // sw          $s5, 0x23C($sp)
    MEM_W(0X23C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x234($sp)
    MEM_W(0X234, ctx->r29) = ctx->r19;
    // sw          $s2, 0x230($sp)
    MEM_W(0X230, ctx->r29) = ctx->r18;
    // sw          $s1, 0x22C($sp)
    MEM_W(0X22C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x228($sp)
    MEM_W(0X228, ctx->r29) = ctx->r16;
    // sw          $a1, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r5;
    // sw          $v0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r2;
    // lb          $a1, 0x0($a1)
    ctx->r5 = MEM_BS(0X0, ctx->r5);
    // nop

    // beq         $a1, $zero, L_80079370
    if (ctx->r5 == 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_80079370;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // addiu       $s7, $zero, 0x2D
    ctx->r23 = ADD32(0, 0X2D);
    // addiu       $s6, $zero, 0x2B
    ctx->r22 = ADD32(0, 0X2B);
    // addiu       $s5, $zero, 0x20
    ctx->r21 = ADD32(0, 0X20);
    // addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // addiu       $v0, $zero, 0x25
    ctx->r2 = ADD32(0, 0X25);
L_80078B8C:
    // bne         $a1, $v0, L_800792B8
    if (ctx->r5 != ctx->r2) {
        // addu        $v0, $s4, $s2
        ctx->r2 = ADD32(ctx->r20, ctx->r18);
        goto L_800792B8;
    }
    // addu        $v0, $s4, $s2
    ctx->r2 = ADD32(ctx->r20, ctx->r18);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, 0x7C60
    ctx->r5 = ADD32(ctx->r5, 0X7C60);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(0X4, ctx->r5);
    // lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(0X8, ctx->r5);
    // sw          $v0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r2;
    // sw          $v1, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r3;
    // sw          $a0, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r4;
    // addiu       $v1, $zero, 0x23
    ctx->r3 = ADD32(0, 0X23);
L_80078BB8:
    // lw          $a2, 0x254($sp)
    ctx->r6 = MEM_W(0X254, ctx->r29);
    // nop

    // addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // lb          $a1, 0x1($a2)
    ctx->r5 = MEM_BS(0X1, ctx->r6);
    // nop

    // bne         $a1, $s7, L_80078BEC
    if (ctx->r5 != ctx->r23) {
        // nop
    
        goto L_80078BEC;
    }
    // nop

    // lw          $v0, 0x210($sp)
    ctx->r2 = MEM_W(0X210, ctx->r29);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // j           L_80078BB8
    // sw          $v0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r2;
    goto L_80078BB8;
    // sw          $v0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r2;
L_80078BEC:
    // bne         $a1, $s6, L_80078C08
    if (ctx->r5 != ctx->r22) {
        // nop
    
        goto L_80078C08;
    }
    // nop

    // lw          $v0, 0x210($sp)
    ctx->r2 = MEM_W(0X210, ctx->r29);
    // nop

    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // j           L_80078BB8
    // sw          $v0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r2;
    goto L_80078BB8;
    // sw          $v0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r2;
L_80078C08:
    // bne         $a1, $s5, L_80078C18
    if (ctx->r5 != ctx->r21) {
        // nop
    
        goto L_80078C18;
    }
    // nop

    // j           L_80078BB8
    // sb          $a1, 0x211($sp)
    MEM_B(0X211, ctx->r29) = ctx->r5;
    goto L_80078BB8;
    // sb          $a1, 0x211($sp)
    MEM_B(0X211, ctx->r29) = ctx->r5;
L_80078C18:
    // bne         $a1, $v1, L_80078C34
    if (ctx->r5 != ctx->r3) {
        // nop
    
        goto L_80078C34;
    }
    // nop

    // lw          $v0, 0x210($sp)
    ctx->r2 = MEM_W(0X210, ctx->r29);
    // nop

    // ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // j           L_80078BB8
    // sw          $v0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r2;
    goto L_80078BB8;
    // sw          $v0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r2;
L_80078C34:
    // bne         $a1, $s3, L_80078C50
    if (ctx->r5 != ctx->r19) {
        // addiu       $v0, $zero, 0x2A
        ctx->r2 = ADD32(0, 0X2A);
        goto L_80078C50;
    }
    // addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // lw          $v0, 0x210($sp)
    ctx->r2 = MEM_W(0X210, ctx->r29);
    // nop

    // ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // j           L_80078BB8
    // sw          $v0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r2;
    goto L_80078BB8;
    // sw          $v0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r2;
L_80078C50:
    // bne         $a1, $v0, L_80078CD8
    if (ctx->r5 != ctx->r2) {
        // addiu       $v0, $a1, -0x30
        ctx->r2 = ADD32(ctx->r5, -0X30);
        goto L_80078CD8;
    }
    // addiu       $v0, $a1, -0x30
    ctx->r2 = ADD32(ctx->r5, -0X30);
    // lw          $v0, 0x220($sp)
    ctx->r2 = MEM_W(0X220, ctx->r29);
    // nop

    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sw          $v0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r2;
    // bgez        $a0, L_80078C88
    if (SIGNED(ctx->r4) >= 0) {
        // sw          $a0, 0x214($sp)
        MEM_W(0X214, ctx->r29) = ctx->r4;
        goto L_80078C88;
    }
    // sw          $a0, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r4;
    // lw          $v1, 0x210($sp)
    ctx->r3 = MEM_W(0X210, ctx->r29);
    // negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
    // sw          $v0, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r2;
    // ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // sw          $v1, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r3;
L_80078C88:
    // addiu       $v0, $a2, 0x2
    ctx->r2 = ADD32(ctx->r6, 0X2);
    // sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // lb          $a1, 0x2($a2)
    ctx->r5 = MEM_BS(0X2, ctx->r6);
    // j           L_80078CE4
    // addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    goto L_80078CE4;
    // addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
L_80078C9C:
    // lw          $v1, 0x214($sp)
    ctx->r3 = MEM_W(0X214, ctx->r29);
    // nop

    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sw          $v0, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r2;
    // lw          $v1, 0x254($sp)
    ctx->r3 = MEM_W(0X254, ctx->r29);
    // nop

    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // lb          $a1, 0x1($v1)
    ctx->r5 = MEM_BS(0X1, ctx->r3);
    // nop

    // addiu       $v0, $a1, -0x30
    ctx->r2 = ADD32(ctx->r5, -0X30);
L_80078CD8:
    // sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // bne         $v0, $zero, L_80078C9C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x2E
        ctx->r2 = ADD32(0, 0X2E);
        goto L_80078C9C;
    }
    // addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
L_80078CE4:
    // bne         $a1, $v0, L_80078DA0
    if (ctx->r5 != ctx->r2) {
        // nop
    
        goto L_80078DA0;
    }
    // nop

    // lw          $a0, 0x254($sp)
    ctx->r4 = MEM_W(0X254, ctx->r29);
    // nop

    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // lb          $a1, 0x1($a0)
    ctx->r5 = MEM_BS(0X1, ctx->r4);
    // addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // bne         $a1, $v0, L_80078D74
    if (ctx->r5 != ctx->r2) {
        // addiu       $v0, $a1, -0x30
        ctx->r2 = ADD32(ctx->r5, -0X30);
        goto L_80078D74;
    }
    // addiu       $v0, $a1, -0x30
    ctx->r2 = ADD32(ctx->r5, -0X30);
    // lw          $v0, 0x220($sp)
    ctx->r2 = MEM_W(0X220, ctx->r29);
    // nop

    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sw          $v0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r2;
    // addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // sw          $v1, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r3;
    // sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // lb          $a1, 0x2($a0)
    ctx->r5 = MEM_BS(0X2, ctx->r4);
    // j           L_80078D80
    // nop

    goto L_80078D80;
    // nop

L_80078D38:
    // lw          $v1, 0x218($sp)
    ctx->r3 = MEM_W(0X218, ctx->r29);
    // nop

    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sw          $v0, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r2;
    // lw          $v1, 0x254($sp)
    ctx->r3 = MEM_W(0X254, ctx->r29);
    // nop

    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // lb          $a1, 0x1($v1)
    ctx->r5 = MEM_BS(0X1, ctx->r3);
    // nop

    // addiu       $v0, $a1, -0x30
    ctx->r2 = ADD32(ctx->r5, -0X30);
L_80078D74:
    // sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // bne         $v0, $zero, L_80078D38
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80078D38;
    }
    // nop

L_80078D80:
    // lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(0X218, ctx->r29);
    // nop

    // bltz        $v0, L_80078DA0
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80078DA0;
    }
    // nop

    // lw          $v0, 0x210($sp)
    ctx->r2 = MEM_W(0X210, ctx->r29);
    // nop

    // ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // sw          $v0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r2;
L_80078DA0:
    // lw          $v1, 0x210($sp)
    ctx->r3 = MEM_W(0X210, ctx->r29);
    // nop

    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // beq         $v0, $zero, L_80078DC0
    if (ctx->r2 == 0) {
        // addiu       $s1, $sp, 0x210
        ctx->r17 = ADD32(ctx->r29, 0X210);
        goto L_80078DC0;
    }
    // addiu       $s1, $sp, 0x210
    ctx->r17 = ADD32(ctx->r29, 0X210);
    // addiu       $v0, $zero, -0x9
    ctx->r2 = ADD32(0, -0X9);
    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // sw          $v0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r2;
L_80078DC0:
    // addiu       $v1, $a1, -0x4C
    ctx->r3 = ADD32(ctx->r5, -0X4C);
L_80078DC4:
    // sltiu       $v0, $v1, 0x2D
    ctx->r2 = ctx->r3 < 0X2D ? 1 : 0;
    // beq         $v0, $zero, L_800792AC
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_800792AC;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addu        $at, $at, $v0
    gpr jr_addend_80078DE0;
    jr_addend_80078DE0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x4028($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80078DE0 >> 2) {
        case 0: goto L_80078E00; break;
        case 1: goto L_800792AC; break;
        case 2: goto L_800792AC; break;
        case 3: goto L_800792AC; break;
        case 4: goto L_800792AC; break;
        case 5: goto L_800792AC; break;
        case 6: goto L_800792AC; break;
        case 7: goto L_800792AC; break;
        case 8: goto L_800792AC; break;
        case 9: goto L_800792AC; break;
        case 10: goto L_800792AC; break;
        case 11: goto L_800792AC; break;
        case 12: goto L_800790B8; break;
        case 13: goto L_800792AC; break;
        case 14: goto L_800792AC; break;
        case 15: goto L_800792AC; break;
        case 16: goto L_800792AC; break;
        case 17: goto L_800792AC; break;
        case 18: goto L_800792AC; break;
        case 19: goto L_800792AC; break;
        case 20: goto L_800792AC; break;
        case 21: goto L_800792AC; break;
        case 22: goto L_800792AC; break;
        case 23: goto L_800791CC; break;
        case 24: goto L_80078E2C; break;
        case 25: goto L_800792AC; break;
        case 26: goto L_800792AC; break;
        case 27: goto L_800792AC; break;
        case 28: goto L_80078DE8; break;
        case 29: goto L_80078E2C; break;
        case 30: goto L_800792AC; break;
        case 31: goto L_800792AC; break;
        case 32: goto L_80078DF4; break;
        case 33: goto L_800792AC; break;
        case 34: goto L_80079278; break;
        case 35: goto L_80078FA4; break;
        case 36: goto L_800790A4; break;
        case 37: goto L_800792AC; break;
        case 38: goto L_800792AC; break;
        case 39: goto L_800791EC; break;
        case 40: goto L_800792AC; break;
        case 41: goto L_80078E84; break;
        case 42: goto L_800792AC; break;
        case 43: goto L_800792AC; break;
        case 44: goto L_800790C4; break;
        default: switch_error(__func__, 0x80078DE0, 0x80014028);
    }
    // nop

L_80078DE8:
    // lw          $v0, 0x210($sp)
    ctx->r2 = MEM_W(0X210, ctx->r29);
    // j           L_80078E0C
    // ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    goto L_80078E0C;
    // ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
L_80078DF4:
    // lw          $v0, 0x210($sp)
    ctx->r2 = MEM_W(0X210, ctx->r29);
    // j           L_80078E0C
    // ori         $v0, $v0, 0x40
    ctx->r2 = ctx->r2 | 0X40;
    goto L_80078E0C;
    // ori         $v0, $v0, 0x40
    ctx->r2 = ctx->r2 | 0X40;
L_80078E00:
    // lw          $v0, 0x210($sp)
    ctx->r2 = MEM_W(0X210, ctx->r29);
    // nop

    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
L_80078E0C:
    // sw          $v0, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r2;
    // lw          $v1, 0x254($sp)
    ctx->r3 = MEM_W(0X254, ctx->r29);
    // nop

    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // lb          $a1, 0x1($v1)
    ctx->r5 = MEM_BS(0X1, ctx->r3);
    // j           L_80078DC4
    // addiu       $v1, $a1, -0x4C
    ctx->r3 = ADD32(ctx->r5, -0X4C);
    goto L_80078DC4;
    // addiu       $v1, $a1, -0x4C
    ctx->r3 = ADD32(ctx->r5, -0X4C);
L_80078E2C:
    // lw          $v0, 0x220($sp)
    ctx->r2 = MEM_W(0X220, ctx->r29);
    // nop

    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sw          $v0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r2;
    // lw          $v1, 0x210($sp)
    ctx->r3 = MEM_W(0X210, ctx->r29);
    // nop

    // srl         $v0, $v1, 5
    ctx->r2 = S32(U32(ctx->r3) >> 5);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80078E5C
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4) << 16;
        goto L_80078E5C;
    }
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
L_80078E5C:
    // bgez        $a0, L_80078E70
    if (SIGNED(ctx->r4) >= 0) {
        // srl         $v0, $v1, 1
        ctx->r2 = S32(U32(ctx->r3) >> 1);
        goto L_80078E70;
    }
    // srl         $v0, $v1, 1
    ctx->r2 = S32(U32(ctx->r3) >> 1);
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // j           L_80078EB8
    // sb          $s7, 0x211($sp)
    MEM_B(0X211, ctx->r29) = ctx->r23;
    goto L_80078EB8;
    // sb          $s7, 0x211($sp)
    MEM_B(0X211, ctx->r29) = ctx->r23;
L_80078E70:
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80078EB8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80078EB8;
    }
    // nop

    // j           L_80078EB8
    // sb          $s6, 0x211($sp)
    MEM_B(0X211, ctx->r29) = ctx->r22;
    goto L_80078EB8;
    // sb          $s6, 0x211($sp)
    MEM_B(0X211, ctx->r29) = ctx->r22;
L_80078E84:
    // lw          $v0, 0x220($sp)
    ctx->r2 = MEM_W(0X220, ctx->r29);
    // nop

    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sw          $v0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r2;
    // lw          $v0, 0x210($sp)
    ctx->r2 = MEM_W(0X210, ctx->r29);
    // nop

    // srl         $v0, $v0, 5
    ctx->r2 = S32(U32(ctx->r2) >> 5);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80078EB4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80078EB4;
    }
    // nop

    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
L_80078EB4:
    // sb          $zero, 0x211($sp)
    MEM_B(0X211, ctx->r29) = 0;
L_80078EB8:
    // lw          $v1, 0x210($sp)
    ctx->r3 = MEM_W(0X210, ctx->r29);
    // nop

    // srl         $v0, $v1, 4
    ctx->r2 = S32(U32(ctx->r3) >> 4);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80078F0C
    if (ctx->r2 != 0) {
        // srl         $v0, $v1, 3
        ctx->r2 = S32(U32(ctx->r3) >> 3);
        goto L_80078F0C;
    }
    // srl         $v0, $v1, 3
    ctx->r2 = S32(U32(ctx->r3) >> 3);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80078EF8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80078EF8;
    }
    // nop

    // lw          $v1, 0x214($sp)
    ctx->r3 = MEM_W(0X214, ctx->r29);
    // lb          $v0, 0x211($sp)
    ctx->r2 = MEM_BS(0X211, ctx->r29);
    // nop

    // beq         $v0, $zero, L_80078EF8
    if (ctx->r2 == 0) {
        // sw          $v1, 0x218($sp)
        MEM_W(0X218, ctx->r29) = ctx->r3;
        goto L_80078EF8;
    }
    // sw          $v1, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r3;
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sw          $v0, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r2;
L_80078EF8:
    // lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(0X218, ctx->r29);
    // nop

    // bgtz        $v0, L_80078F0C
    if (SIGNED(ctx->r2) > 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80078F0C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r2;
L_80078F0C:
    // beq         $a0, $zero, L_80078F50
    if (ctx->r4 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80078F50;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $a1, 0xCCCC
    ctx->r5 = S32(0XCCCC << 16);
    // ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
L_80078F1C:
    // multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // mfhi        $t0
    ctx->r8 = hi;
    // srl         $v1, $t0, 3
    ctx->r3 = S32(U32(ctx->r8) >> 3);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // bne         $a0, $zero, L_80078F1C
    if (ctx->r4 != 0) {
        // sb          $v0, 0x0($s1)
        MEM_B(0X0, ctx->r17) = ctx->r2;
        goto L_80078F1C;
    }
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
L_80078F50:
    // lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(0X218, ctx->r29);
    // nop

    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80078F84
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80078F84;
    }
    // nop

    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80078F68:
    // sb          $s3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r19;
    // lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(0X218, ctx->r29);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80078F68
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80078F68;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80078F84:
    // lb          $v0, 0x211($sp)
    ctx->r2 = MEM_BS(0X211, ctx->r29);
    // lbu         $v1, 0x211($sp)
    ctx->r3 = MEM_BU(0X211, ctx->r29);
    // beq         $v0, $zero, L_800792C4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800792C4;
    }
    // nop

    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // sb          $v1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r3;
    // j           L_800792C4
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    goto L_800792C4;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80078FA4:
    // lw          $v0, 0x220($sp)
    ctx->r2 = MEM_W(0X220, ctx->r29);
    // nop

    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sw          $v0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r2;
    // lw          $v1, 0x210($sp)
    ctx->r3 = MEM_W(0X210, ctx->r29);
    // nop

    // srl         $v0, $v1, 5
    ctx->r2 = S32(U32(ctx->r3) >> 5);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80078FD4
    if (ctx->r2 == 0) {
        // srl         $v0, $v1, 4
        ctx->r2 = S32(U32(ctx->r3) >> 4);
        goto L_80078FD4;
    }
    // srl         $v0, $v1, 4
    ctx->r2 = S32(U32(ctx->r3) >> 4);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
L_80078FD4:
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_8007900C
    if (ctx->r2 != 0) {
        // srl         $v0, $v1, 3
        ctx->r2 = S32(U32(ctx->r3) >> 3);
        goto L_8007900C;
    }
    // srl         $v0, $v1, 3
    ctx->r2 = S32(U32(ctx->r3) >> 3);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80078FF8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80078FF8;
    }
    // nop

    // lw          $v0, 0x214($sp)
    ctx->r2 = MEM_W(0X214, ctx->r29);
    // nop

    // sw          $v0, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r2;
L_80078FF8:
    // lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(0X218, ctx->r29);
    // nop

    // bgtz        $v0, L_8007900C
    if (SIGNED(ctx->r2) > 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007900C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r2;
L_8007900C:
    // beq         $a0, $zero, L_80079030
    if (ctx->r4 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80079030;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80079014:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // bne         $a0, $zero, L_80079014
    if (ctx->r4 != 0) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80079014;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80079030:
    // lw          $v0, 0x210($sp)
    ctx->r2 = MEM_W(0X210, ctx->r29);
    // nop

    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8007906C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007906C;
    }
    // nop

    // beq         $s0, $zero, L_8007906C
    if (ctx->r16 == 0) {
        // nop
    
        goto L_8007906C;
    }
    // nop

    // lb          $v0, 0x0($s1)
    ctx->r2 = MEM_BS(0X0, ctx->r17);
    // nop

    // beq         $v0, $s3, L_8007906C
    if (ctx->r2 == ctx->r19) {
        // nop
    
        goto L_8007906C;
    }
    // nop

    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // sb          $s3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r19;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8007906C:
    // lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(0X218, ctx->r29);
    // nop

    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800792C4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800792C4;
    }
    // nop

    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80079084:
    // sb          $s3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r19;
    // lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(0X218, ctx->r29);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80079084
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80079084;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // j           L_800792C4
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    goto L_800792C4;
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800790A4:
    // lw          $v1, 0x210($sp)
    ctx->r3 = MEM_W(0X210, ctx->r29);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // sw          $v0, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r2;
    // ori         $v1, $v1, 0x50
    ctx->r3 = ctx->r3 | 0X50;
    // sw          $v1, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r3;
L_800790B8:
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // j           L_800790CC
    // addiu       $a3, $a3, 0x4000
    ctx->r7 = ADD32(ctx->r7, 0X4000);
    goto L_800790CC;
    // addiu       $a3, $a3, 0x4000
    ctx->r7 = ADD32(ctx->r7, 0X4000);
L_800790C4:
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // addiu       $a3, $a3, 0x4014
    ctx->r7 = ADD32(ctx->r7, 0X4014);
L_800790CC:
    // lw          $v0, 0x220($sp)
    ctx->r2 = MEM_W(0X220, ctx->r29);
    // nop

    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sw          $v0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r2;
    // lw          $v1, 0x210($sp)
    ctx->r3 = MEM_W(0X210, ctx->r29);
    // nop

    // srl         $v0, $v1, 5
    ctx->r2 = S32(U32(ctx->r3) >> 5);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_800790FC
    if (ctx->r2 == 0) {
        // srl         $v0, $v1, 4
        ctx->r2 = S32(U32(ctx->r3) >> 4);
        goto L_800790FC;
    }
    // srl         $v0, $v1, 4
    ctx->r2 = S32(U32(ctx->r3) >> 4);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
L_800790FC:
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80079140
    if (ctx->r2 != 0) {
        // srl         $v0, $v1, 3
        ctx->r2 = S32(U32(ctx->r3) >> 3);
        goto L_80079140;
    }
    // srl         $v0, $v1, 3
    ctx->r2 = S32(U32(ctx->r3) >> 3);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8007912C
    if (ctx->r2 == 0) {
        // srl         $v0, $v1, 2
        ctx->r2 = S32(U32(ctx->r3) >> 2);
        goto L_8007912C;
    }
    // srl         $v0, $v1, 2
    ctx->r2 = S32(U32(ctx->r3) >> 2);
    // lw          $a2, 0x214($sp)
    ctx->r6 = MEM_W(0X214, ctx->r29);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8007912C
    if (ctx->r2 == 0) {
        // sw          $a2, 0x218($sp)
        MEM_W(0X218, ctx->r29) = ctx->r6;
        goto L_8007912C;
    }
    // sw          $a2, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r6;
    // addiu       $v0, $a2, -0x2
    ctx->r2 = ADD32(ctx->r6, -0X2);
    // sw          $v0, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r2;
L_8007912C:
    // lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(0X218, ctx->r29);
    // nop

    // bgtz        $v0, L_80079140
    if (SIGNED(ctx->r2) > 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80079140;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x218($sp)
    MEM_W(0X218, ctx->r29) = ctx->r2;
L_80079140:
    // beq         $a0, $zero, L_80079168
    if (ctx->r4 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80079168;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80079148:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
    // srl         $a0, $a0, 4
    ctx->r4 = S32(U32(ctx->r4) >> 4);
    // addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // bne         $a0, $zero, L_80079148
    if (ctx->r4 != 0) {
        // sb          $v0, 0x0($s1)
        MEM_B(0X0, ctx->r17) = ctx->r2;
        goto L_80079148;
    }
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
L_80079168:
    // lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(0X218, ctx->r29);
    // nop

    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8007919C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007919C;
    }
    // nop

    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80079180:
    // sb          $s3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r19;
    // lw          $v0, 0x218($sp)
    ctx->r2 = MEM_W(0X218, ctx->r29);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80079180
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80079180;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8007919C:
    // lw          $v0, 0x210($sp)
    ctx->r2 = MEM_W(0X210, ctx->r29);
    // nop

    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_800792C4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800792C4;
    }
    // nop

    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // sb          $a1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r5;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // j           L_800792C4
    // sb          $s3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r19;
    goto L_800792C4;
    // sb          $s3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r19;
L_800791CC:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // lw          $v0, 0x220($sp)
    ctx->r2 = MEM_W(0X220, ctx->r29);
    // addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sb          $v1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r3;
    // j           L_800792C4
    // sw          $v0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r2;
    goto L_800792C4;
    // sw          $v0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r2;
L_800791EC:
    // lw          $v0, 0x220($sp)
    ctx->r2 = MEM_W(0X220, ctx->r29);
    // lw          $v1, 0x210($sp)
    ctx->r3 = MEM_W(0X210, ctx->r29);
    // lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sw          $v0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r2;
    // srl         $v0, $v1, 2
    ctx->r2 = S32(U32(ctx->r3) >> 2);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8007923C
    if (ctx->r2 == 0) {
        // srl         $v0, $v1, 4
        ctx->r2 = S32(U32(ctx->r3) >> 4);
        goto L_8007923C;
    }
    // srl         $v0, $v1, 4
    ctx->r2 = S32(U32(ctx->r3) >> 4);
    // lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(0X0, ctx->r17);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_800792C4
    if (ctx->r2 == 0) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800792C4;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // lw          $v1, 0x218($sp)
    ctx->r3 = MEM_W(0X218, ctx->r29);
    // nop

    // slt         $v0, $v1, $s0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // beq         $v0, $zero, L_800792C4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800792C4;
    }
    // nop

    // j           L_800792C4
    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    goto L_800792C4;
    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_8007923C:
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80079258
    if (ctx->r2 != 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_80079258;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x800793B4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    strlen_recomp(rdram, ctx);
    goto after_0;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // j           L_800792C4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    goto L_800792C4;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80079258:
    // lw          $a2, 0x218($sp)
    ctx->r6 = MEM_W(0X218, ctx->r29);
    // jal         0x800793C4
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    memchr(rdram, ctx);
    goto after_1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // bne         $v0, $zero, L_800792C4
    if (ctx->r2 != 0) {
        // subu        $s0, $v0, $s1
        ctx->r16 = SUB32(ctx->r2, ctx->r17);
        goto L_800792C4;
    }
    // subu        $s0, $v0, $s1
    ctx->r16 = SUB32(ctx->r2, ctx->r17);
    // lw          $s0, 0x218($sp)
    ctx->r16 = MEM_W(0X218, ctx->r29);
    // j           L_800792C4
    // nop

    goto L_800792C4;
    // nop

L_80079278:
    // lw          $v0, 0x220($sp)
    ctx->r2 = MEM_W(0X220, ctx->r29);
    // lw          $v1, 0x210($sp)
    ctx->r3 = MEM_W(0X210, ctx->r29);
    // lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(0X0, ctx->r2);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sw          $v0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->r2;
    // srl         $v0, $v1, 5
    ctx->r2 = S32(U32(ctx->r3) >> 5);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_800792A4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800792A4;
    }
    // nop

    // j           L_80079350
    // sh          $s2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r18;
    goto L_80079350;
    // sh          $s2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r18;
L_800792A4:
    // j           L_80079350
    // sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
    goto L_80079350;
    // sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
L_800792AC:
    // addiu       $v0, $zero, 0x25
    ctx->r2 = ADD32(0, 0X25);
    // bne         $a1, $v0, L_80079370
    if (ctx->r5 != ctx->r2) {
        // addu        $v0, $s4, $s2
        ctx->r2 = ADD32(ctx->r20, ctx->r18);
        goto L_80079370;
    }
    // addu        $v0, $s4, $s2
    ctx->r2 = ADD32(ctx->r20, ctx->r18);
L_800792B8:
    // sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // j           L_80079350
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_80079350;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800792C4:
    // lw          $v0, 0x214($sp)
    ctx->r2 = MEM_W(0X214, ctx->r29);
    // nop

    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80079314
    if (ctx->r2 == 0) {
        // addu        $a0, $s4, $s2
        ctx->r4 = ADD32(ctx->r20, ctx->r18);
        goto L_80079314;
    }
    // addu        $a0, $s4, $s2
    ctx->r4 = ADD32(ctx->r20, ctx->r18);
    // lw          $v0, 0x210($sp)
    ctx->r2 = MEM_W(0X210, ctx->r29);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80079318
    if (ctx->r2 != 0) {
        // addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
        goto L_80079318;
    }
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_800792EC:
    // addu        $v0, $s4, $s2
    ctx->r2 = ADD32(ctx->r20, ctx->r18);
    // sb          $s5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r21;
    // lw          $v0, 0x214($sp)
    ctx->r2 = MEM_W(0X214, ctx->r29);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r2;
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800792EC
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_800792EC;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addu        $a0, $s4, $s2
    ctx->r4 = ADD32(ctx->r20, ctx->r18);
L_80079314:
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_80079318:
    // jal         0x800793D4
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    memmove_recomp(rdram, ctx);
    goto after_2;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // lw          $v0, 0x214($sp)
    ctx->r2 = MEM_W(0X214, ctx->r29);
    // nop

    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80079350
    if (ctx->r2 == 0) {
        // addu        $s2, $s2, $s0
        ctx->r18 = ADD32(ctx->r18, ctx->r16);
        goto L_80079350;
    }
    // addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
L_80079334:
    // addu        $v0, $s4, $s2
    ctx->r2 = ADD32(ctx->r20, ctx->r18);
    // sb          $s5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r21;
    // lw          $v0, 0x214($sp)
    ctx->r2 = MEM_W(0X214, ctx->r29);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80079334
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80079334;
    }
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80079350:
    // lw          $v1, 0x254($sp)
    ctx->r3 = MEM_W(0X254, ctx->r29);
    // nop

    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // lb          $a1, 0x1($v1)
    ctx->r5 = MEM_BS(0X1, ctx->r3);
    // nop

    // bne         $a1, $zero, L_80078B8C
    if (ctx->r5 != 0) {
        // addiu       $v0, $zero, 0x25
        ctx->r2 = ADD32(0, 0X25);
        goto L_80078B8C;
    }
    // addiu       $v0, $zero, 0x25
    ctx->r2 = ADD32(0, 0X25);
L_80079370:
    // addu        $v0, $s4, $s2
    ctx->r2 = ADD32(ctx->r20, ctx->r18);
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // lw          $ra, 0x248($sp)
    ctx->r31 = MEM_W(0X248, ctx->r29);
    // lw          $s7, 0x244($sp)
    ctx->r23 = MEM_W(0X244, ctx->r29);
    // lw          $s6, 0x240($sp)
    ctx->r22 = MEM_W(0X240, ctx->r29);
    // lw          $s5, 0x23C($sp)
    ctx->r21 = MEM_W(0X23C, ctx->r29);
    // lw          $s4, 0x238($sp)
    ctx->r20 = MEM_W(0X238, ctx->r29);
    // lw          $s3, 0x234($sp)
    ctx->r19 = MEM_W(0X234, ctx->r29);
    // lw          $s2, 0x230($sp)
    ctx->r18 = MEM_W(0X230, ctx->r29);
    // lw          $s1, 0x22C($sp)
    ctx->r17 = MEM_W(0X22C, ctx->r29);
    // lw          $s0, 0x228($sp)
    ctx->r16 = MEM_W(0X228, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x250
    ctx->r29 = ADD32(ctx->r29, 0X250);
    return;
    // addiu       $sp, $sp, 0x250
    ctx->r29 = ADD32(ctx->r29, 0X250);
;}
