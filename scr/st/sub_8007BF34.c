#include "recomp.h"
#include "disable_warnings.h"

void sub_8007BF34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // bne         $a0, $zero, L_8007BFE8
    if (ctx->r4 != 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_8007BFE8;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x8007C070
    // nop

    sub_8007C070(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_8007BF6C
    // nop

    goto L_8007BF6C;
    // nop

L_8007BF54:
    // jal         0x8007BB84
    // nop

    sub_8007BB84(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x8007C0A4
    // nop

    sub_8007C0A4(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // bne         $v0, $zero, L_8007C060
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8007C060;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007BF6C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DE8($v1)
    ctx->r3 = MEM_W(0X7DE8, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DEC($v0)
    ctx->r2 = MEM_W(0X7DEC, ctx->r2);
    // nop

    // beq         $v1, $v0, L_8007BFA0
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007BFA0;
    }
    // nop

    // j           L_8007BF54
    // nop

    goto L_8007BF54;
    // nop

L_8007BF90:
    // jal         0x8007C0A4
    // nop

    sub_8007C0A4(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // bne         $v0, $zero, L_8007C060
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8007C060;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007BFA0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DD4($v0)
    ctx->r2 = MEM_W(0X7DD4, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8007BF90
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007BF90;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8007BF90
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007BF90;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_8007C060
    // nop

    goto L_8007C060;
    // nop

L_8007BFE8:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DE8($v0)
    ctx->r2 = MEM_W(0X7DE8, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DEC($v1)
    ctx->r3 = MEM_W(0X7DEC, ctx->r3);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $s0, $v0, 0x3F
    ctx->r16 = ctx->r2 & 0X3F;
    // beq         $s0, $zero, L_8007C014
    if (ctx->r16 == 0) {
        // nop
    
        goto L_8007C014;
    }
    // nop

    // jal         0x8007BB84
    // nop

    sub_8007BB84(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_8007C014:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DD4($v0)
    ctx->r2 = MEM_W(0X7DD4, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8007C054
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007C054;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8007C060
    if (ctx->r2 != 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8007C060;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8007C054:
    // bne         $s0, $zero, L_8007C060
    if (ctx->r16 != 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8007C060;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007C060:
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
