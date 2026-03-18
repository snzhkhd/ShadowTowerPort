#include "recomp.h"
#include "disable_warnings.h"

void sub_80014E4C(uint8_t* rdram, recomp_context* ctx) {
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
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80014EBC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80014EBC;
    }
    // nop

    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_80014E78:
    // bne         $v1, $zero, L_80014E94
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80014E94;
    }
    // nop

    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // beq         $v0, $zero, L_80014F74
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80014F74;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80014E94:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // nop

    // bne         $v1, $a2, L_80014E78
    if (ctx->r3 != ctx->r6) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80014E78;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
L_80014EBC:
    // nop

    // beq         $v1, $v0, L_80014F74
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80014F74;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80014ECC:
    // bne         $v1, $a0, L_80014F54
    if (ctx->r3 != ctx->r4) {
        // addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
        goto L_80014F54;
    }
    // addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80014ED8:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v0, $v1, L_80014ED8
    if (ctx->r2 == ctx->r3) {
        // subu        $v0, $s0, $s1
        ctx->r2 = SUB32(ctx->r16, ctx->r17);
        goto L_80014ED8;
    }
    // subu        $v0, $s0, $s1
    ctx->r2 = SUB32(ctx->r16, ctx->r17);
    // addiu       $v0, $v0, -0xC
    ctx->r2 = ADD32(ctx->r2, -0XC);
    // sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // bne         $v0, $zero, L_80014F64
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80014F64;
    }
    // nop

    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // bne         $v0, $a0, L_80014F44
    if (ctx->r2 != ctx->r4) {
        // addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
        goto L_80014F44;
    }
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80014F1C:
    // jal         0x80014E20
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80014E20(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v0, $s2, L_80014F1C
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_80014F1C;
    }
    // nop

L_80014F44:
    // jal         0x80014DA4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80014DA4(rdram, ctx);
    goto after_1;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // j           L_80014F74
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    goto L_80014F74;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_80014F54:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_80014F64:
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $v0, L_80014ECC
    if (ctx->r3 != ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80014ECC;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80014F74:
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
