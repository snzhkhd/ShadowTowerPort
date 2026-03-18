#include "recomp.h"
#include "disable_warnings.h"

void sub_800588B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // beq         $v1, $zero, L_800588F0
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800588F0;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_800589EC
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_800589EC;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_800589F0
    // nop

    goto L_800589F0;
    // nop

L_800588F0:
    // lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(0X28, ctx->r16);
    // lh          $v1, 0x4($s0)
    ctx->r3 = MEM_HS(0X4, ctx->r16);
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x2E18
    ctx->r2 = ADD32(ctx->r2, -0X2E18);
    // jal         0x80015B78
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    sub_80015B78(rdram, ctx);
    goto after_0;
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    after_0:
    // beq         $v0, $zero, L_80058940
    if (ctx->r2 == 0) {
        // addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
        goto L_80058940;
    }
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_80058924:
    // addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_1;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // beq         $v0, $zero, L_80058924
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
        goto L_80058924;
    }
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // j           L_800589F0
    // nop

    goto L_800589F0;
    // nop

L_80058940:
    // lh          $a0, 0x4($s1)
    ctx->r4 = MEM_HS(0X4, ctx->r17);
    // nop

    // beq         $a0, $s2, L_80058964
    if (ctx->r4 == ctx->r18) {
        // addiu       $v0, $zero, 0xFE
        ctx->r2 = ADD32(0, 0XFE);
        goto L_80058964;
    }
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // beq         $a0, $v0, L_80058964
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80058964;
    }
    // nop

    // jal         0x80073564
    // nop

    sub_80073564(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // sh          $s2, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r18;
L_80058964:
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(0XC, ctx->r16);
    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // jal         0x80073994
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    sub_80073994(rdram, ctx);
    goto after_3;
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_800589A0
    if (ctx->r2 != ctx->r3) {
        // addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
        goto L_800589A0;
    }
    // addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // jal         0x80015848
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80015848(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // j           L_800589F0
    // nop

    goto L_800589F0;
    // nop

L_800589A0:
    // lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(0X28, ctx->r16);
    // jal         0x80015A94
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_80015A94(rdram, ctx);
    goto after_5;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_5:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r2;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x7378
    ctx->r2 = ADD32(ctx->r2, -0X7378);
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_800589D0:
    // addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
    // beq         $v0, $zero, L_800589D0
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
        goto L_800589D0;
    }
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // j           L_800589F0
    // nop

    goto L_800589F0;
    // nop

L_800589EC:
    // sb          $v0, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r2;
L_800589F0:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
