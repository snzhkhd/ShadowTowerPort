#include "recomp.h"
#include "disable_warnings.h"

void sub_8007EED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(0X3C, ctx->r4);
    // nop

    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $zero, 0xF3
    ctx->r2 = ADD32(0, 0XF3);
    // bne         $v1, $v0, L_8007EF08
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8007EF08;
    }
    // nop

    // lbu         $v0, 0xE8($a0)
    ctx->r2 = MEM_BU(0XE8, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8007EF64
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007EF64;
    }
    // nop

L_8007EF08:
    // lbu         $v1, 0x46($a0)
    ctx->r3 = MEM_BU(0X46, ctx->r4);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_8007EF54
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007EF54;
    }
    // nop

    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8007EF34
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007EF34;
    }
    // nop

    // beq         $v1, $zero, L_8007EF9C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8007EF9C;
    }
    // nop

    // j           L_8007EF74
    // nop

    goto L_8007EF74;
    // nop

L_8007EF34:
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // beq         $v1, $v0, L_8007EF64
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007EF64;
    }
    // nop

    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8007EF9C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007EF9C;
    }
    // nop

    // j           L_8007EF74
    // nop

    goto L_8007EF74;
    // nop

L_8007EF54:
    // jal         0x8007E1A0
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_8007E1A0(rdram, ctx);
    goto after_0;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // j           L_8007EF9C
    // nop

    goto L_8007EF9C;
    // nop

L_8007EF64:
    // jal         0x8007E1A0
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_8007E1A0(rdram, ctx);
    goto after_1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // j           L_8007EF9C
    // nop

    goto L_8007EF9C;
    // nop

L_8007EF74:
    // lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(0X14, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8007EF94
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007EF94;
    }
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_8007EF9C
    // nop

    goto L_8007EF9C;
    // nop

L_8007EF94:
    // jal         0x8007D910
    // nop

    sub_8007D910(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_8007EF9C:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
