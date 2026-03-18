#include "recomp.h"
#include "disable_warnings.h"

void sub_800788E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0x7C50($a1)
    ctx->r5 = MEM_W(0X7C50, ctx->r5);
    // j           L_8007891C
    // addiu       $a2, $a0, -0x8
    ctx->r6 = ADD32(ctx->r4, -0X8);
    goto L_8007891C;
    // addiu       $a2, $a0, -0x8
    ctx->r6 = ADD32(ctx->r4, -0X8);
L_800788F4:
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // nop

    // sltu        $v0, $a1, $v1
    ctx->r2 = ctx->r5 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80078918
    if (ctx->r2 != 0) {
        // sltu        $v0, $a1, $a2
        ctx->r2 = ctx->r5 < ctx->r6 ? 1 : 0;
        goto L_80078918;
    }
    // sltu        $v0, $a1, $a2
    ctx->r2 = ctx->r5 < ctx->r6 ? 1 : 0;
    // bne         $v0, $zero, L_8007893C
    if (ctx->r2 != 0) {
        // sltu        $v0, $a2, $v1
        ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
        goto L_8007893C;
    }
    // sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8007893C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007893C;
    }
    // nop

L_80078918:
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_8007891C:
    // sltu        $v0, $a1, $a2
    ctx->r2 = ctx->r5 < ctx->r6 ? 1 : 0;
    // beq         $v0, $zero, L_800788F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800788F4;
    }
    // nop

    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // sltu        $v0, $a2, $v0
    ctx->r2 = ctx->r6 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_800788F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800788F4;
    }
    // nop

L_8007893C:
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x66C8
    ctx->r4 = ADD32(ctx->r4, -0X66C8);
    // sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(0X4, ctx->r6);
    // nop

    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x66B8
    ctx->r3 = ADD32(ctx->r3, -0X66B8);
    // sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(0X4, ctx->r5);
    // nop

    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7C50($v0)
    ctx->r2 = MEM_W(0X7C50, ctx->r2);
    // lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(0X4, ctx->r6);
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v0, -0x66BC($at)
    MEM_W(-0X66BC, ctx->r1) = ctx->r2;
    // sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4) << 3;
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // bne         $v0, $v1, L_800789D0
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_800789D0;
    }
    // nop

    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800789D0
    if (ctx->r2 == 0) {
        // addu        $v0, $a0, $v0
        ctx->r2 = ADD32(ctx->r4, ctx->r2);
        goto L_800789D0;
    }
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // j           L_800789DC
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    goto L_800789DC;
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_800789D0:
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_800789DC:
    // lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(0X4, ctx->r5);
    // nop

    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // bne         $v0, $a2, L_80078A10
    if (ctx->r2 != ctx->r6) {
        // nop
    
        goto L_80078A10;
    }
    // nop

    // lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(0X4, ctx->r6);
    // nop

    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // j           L_80078A14
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    goto L_80078A14;
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80078A10:
    // sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
L_80078A14:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // jr          $ra
    // sw          $a1, 0x7C50($at)
    MEM_W(0X7C50, ctx->r1) = ctx->r5;
    return;
    // sw          $a1, 0x7C50($at)
    MEM_W(0X7C50, ctx->r1) = ctx->r5;
;}
