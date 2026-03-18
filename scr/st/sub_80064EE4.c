#include "recomp.h"
#include "disable_warnings.h"

void sub_80064EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sh          $zero, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = 0;
    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
    // jal         0x80057A3C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80057A3C(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xCE8
    ctx->r2 = ADD32(ctx->r2, 0XCE8);
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s2, $v0, -0x2E80
    ctx->r18 = ADD32(ctx->r2, -0X2E80);
    // sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
L_80064F28:
    // lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(0XC, ctx->r17);
    // nop

    // beq         $v0, $zero, L_80064F40
    if (ctx->r2 == 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80064F40;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
L_80064F40:
    // lhu         $v1, 0x2DC($s0)
    ctx->r3 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // beq         $v0, $zero, L_80064F64
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
        goto L_80064F64;
    }
    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // jal         0x80063CB0
    // nop

    sub_80063CB0(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_80064F94
    // nop

    goto L_80064F94;
    // nop

L_80064F64:
    // beq         $v0, $zero, L_80064F84
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x2
        ctx->r2 = ctx->r3 & 0X2;
        goto L_80064F84;
    }
    // andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // jal         0x800642E8
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    sub_800642E8(rdram, ctx);
    goto after_2;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_2:
    // bne         $v0, $zero, L_80064FCC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80064FCC;
    }
    // nop

    // j           L_80064F94
    // nop

    goto L_80064F94;
    // nop

L_80064F84:
    // beq         $v0, $zero, L_80064F94
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80064F94;
    }
    // nop

    // jal         0x80064BA8
    // nop

    sub_80064BA8(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_80064F94:
    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x80066004
    // nop

    sub_80066004(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lbu         $a0, 0x2E4($s0)
    ctx->r4 = MEM_BU(0X2E4, ctx->r16);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_80064FBC
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80064FBC;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_80064FBC:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_80064F28
    // sb          $v0, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = ctx->r2;
    goto L_80064F28;
    // sb          $v0, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = ctx->r2;
L_80064FCC:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
