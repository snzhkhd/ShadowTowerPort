#include "recomp.h"
#include "disable_warnings.h"

void sub_8007F210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(0X4C, ctx->r16);
    // lbu         $v1, 0x46($s0)
    ctx->r3 = MEM_BU(0X46, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // beq         $v1, $zero, L_8007F2A8
    if (ctx->r3 == 0) {
        // sw          $v0, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = ctx->r2;
        goto L_8007F2A8;
    }
    // sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8007F268
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8007F268;
    }
    // nop

    // lbu         $v1, 0x4A($s0)
    ctx->r3 = MEM_BU(0X4A, ctx->r16);
    // nop

    // sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8007F27C
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_8007F27C;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // j           L_8007F2DC
    // sb          $v0, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r2;
    goto L_8007F2DC;
    // sb          $v0, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r2;
L_8007F268:
    // lbu         $v1, 0x4A($s0)
    ctx->r3 = MEM_BU(0X4A, ctx->r16);
    // nop

    // sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8007F284
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_8007F284;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8007F27C:
    // j           L_8007F2DC
    // sb          $v0, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r2;
    goto L_8007F2DC;
    // sb          $v0, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r2;
L_8007F284:
    // lbu         $v0, 0x49($s0)
    ctx->r2 = MEM_BU(0X49, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8007F2A8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007F2A8;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E1C($v0)
    ctx->r2 = MEM_W(0X7E1C, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
L_8007F2A8:
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // nop

    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $zero, 0xF3
    ctx->r2 = ADD32(0, 0XF3);
    // beq         $v1, $v0, L_8007F2DC
    if (ctx->r3 == ctx->r2) {
        // addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
        goto L_8007F2DC;
    }
    // addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // nop

    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // nop

    // sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // sb          $zero, 0xE8($s0)
    MEM_B(0XE8, ctx->r16) = 0;
L_8007F2DC:
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
