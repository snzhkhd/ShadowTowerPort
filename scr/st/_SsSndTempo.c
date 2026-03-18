#include "recomp.h"
#include "disable_warnings.h"

void _SsSndTempo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x79A0
    ctx->r3 = ADD32(ctx->r3, -0X79A0);
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2) << 4;
    // lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(0X0, ctx->r9);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // addu        $a3, $v1, $t0
    ctx->r7 = ADD32(ctx->r3, ctx->r8);
    // lw          $v0, 0xA8($a3)
    ctx->r2 = MEM_W(0XA8, ctx->r7);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bgez        $v0, L_8006EB4C
    if (SIGNED(ctx->r2) >= 0) {
        // sw          $v0, 0xA8($a3)
        MEM_W(0XA8, ctx->r7) = ctx->r2;
        goto L_8006EB4C;
    }
    // sw          $v0, 0xA8($a3)
    MEM_W(0XA8, ctx->r7) = ctx->r2;
    // lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(0X0, ctx->r9);
    // nop

    // addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // addiu       $a0, $zero, -0x41
    ctx->r4 = ADD32(0, -0X41);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(0X0, ctx->r9);
    // j           L_8006ECD8
    // addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    goto L_8006ECD8;
    // addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
L_8006EB4C:
    // lh          $a0, 0x4E($a3)
    ctx->r4 = MEM_HS(0X4E, ctx->r7);
    // nop

    // blez        $a0, L_8006EBBC
    if (SIGNED(ctx->r4) <= 0) {
        // nop
    
        goto L_8006EBBC;
    }
    // nop

    // div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_8006EB6C
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8006EB6C;
    }
    // nop

    // break       7
    do_break(2147937128);
L_8006EB6C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_8006EB84
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8006EB84;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8006EB84
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8006EB84;
    }
    // nop

    // break       6
    do_break(2147937152);
L_8006EB84:
    // mfhi        $v0
    ctx->r2 = hi;
    // bne         $v0, $zero, L_8006ECE8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006ECE8;
    }
    // nop

    // lw          $v1, 0x94($a3)
    ctx->r3 = MEM_W(0X94, ctx->r7);
    // lw          $a0, 0xAC($a3)
    ctx->r4 = MEM_W(0XAC, ctx->r7);
    // nop

    // sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8006EBB4
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8006EBB4;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_8006EC04
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_8006EC04;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8006EBB4:
    // j           L_8006EC04
    // sw          $v0, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->r2;
    goto L_8006EC04;
    // sw          $v0, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->r2;
L_8006EBBC:
    // lw          $v1, 0x94($a3)
    ctx->r3 = MEM_W(0X94, ctx->r7);
    // lw          $t0, 0xAC($a3)
    ctx->r8 = MEM_W(0XAC, ctx->r7);
    // nop

    // sltu        $v0, $t0, $v1
    ctx->r2 = ctx->r8 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8006EBE0
    if (ctx->r2 == 0) {
        // addu        $v0, $v1, $a0
        ctx->r2 = ADD32(ctx->r3, ctx->r4);
        goto L_8006EBE0;
    }
    // addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // sw          $v0, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->r2;
    // j           L_8006EBF8
    // sltu        $v0, $v0, $t0
    ctx->r2 = ctx->r2 < ctx->r8 ? 1 : 0;
    goto L_8006EBF8;
    // sltu        $v0, $v0, $t0
    ctx->r2 = ctx->r2 < ctx->r8 ? 1 : 0;
L_8006EBE0:
    // sltu        $v0, $v1, $t0
    ctx->r2 = ctx->r3 < ctx->r8 ? 1 : 0;
    // beq         $v0, $zero, L_8006EC04
    if (ctx->r2 == 0) {
        // subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
        goto L_8006EC04;
    }
    // subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // lw          $t0, 0xAC($a3)
    ctx->r8 = MEM_W(0XAC, ctx->r7);
    // sw          $v0, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->r2;
    // sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
L_8006EBF8:
    // beq         $v0, $zero, L_8006EC04
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006EC04;
    }
    // nop

    // sw          $t0, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->r8;
L_8006EC04:
    // lh          $v0, 0x50($a3)
    ctx->r2 = MEM_HS(0X50, ctx->r7);
    // lw          $v1, 0x94($a3)
    ctx->r3 = MEM_W(0X94, ctx->r7);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // lw          $a0, -0x79A4($a0)
    ctx->r4 = MEM_W(-0X79A4, ctx->r4);
    // mflo        $v0
    ctx->r2 = lo;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4) << 4;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // divu        $zero, $v1, $v0
    lo = S32(U32(ctx->r3) / U32(ctx->r2)); hi = S32(U32(ctx->r3) % U32(ctx->r2));
    // bne         $v0, $zero, L_8006EC48
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006EC48;
    }
    // nop

    // break       7
    do_break(2147937348);
L_8006EC48:
    // mflo        $v1
    ctx->r3 = lo;
    // sh          $v1, 0x54($a3)
    MEM_H(0X54, ctx->r7) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // bgtz        $v1, L_8006EC60
    if (SIGNED(ctx->r3) > 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8006EC60;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, 0x54($a3)
    MEM_H(0X54, ctx->r7) = ctx->r2;
L_8006EC60:
    // lw          $v0, 0xA8($a3)
    ctx->r2 = MEM_W(0XA8, ctx->r7);
    // nop

    // beq         $v0, $zero, L_8006EC84
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006EC84;
    }
    // nop

    // lw          $v1, 0x94($a3)
    ctx->r3 = MEM_W(0X94, ctx->r7);
    // lw          $v0, 0xAC($a3)
    ctx->r2 = MEM_W(0XAC, ctx->r7);
    // nop

    // bne         $v1, $v0, L_8006ECE8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8006ECE8;
    }
    // nop

L_8006EC84:
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addiu       $v0, $v0, -0x79A0
    ctx->r2 = ADD32(ctx->r2, -0X79A0);
    // sra         $a2, $a2, 14
    ctx->r6 = S32(ctx->r6) >> 14;
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(0X0, ctx->r6);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    // lw          $v0, 0x98($a1)
    ctx->r2 = MEM_W(0X98, ctx->r5);
    // addiu       $a0, $zero, -0x41
    ctx->r4 = ADD32(0, -0X41);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x98($a1)
    MEM_W(0X98, ctx->r5) = ctx->r2;
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_8006ECD8:
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // addiu       $a0, $zero, -0x81
    ctx->r4 = ADD32(0, -0X81);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
L_8006ECE8:
    // jr          $ra
    // nop

    return;
    // nop

;}
