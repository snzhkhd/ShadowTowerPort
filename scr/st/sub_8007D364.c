#include "recomp.h"
#include "disable_warnings.h"

void sub_8007D364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, 0x7E5C
    ctx->r5 = ADD32(ctx->r5, 0X7E5C);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // nop

    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x7E9C($at)
    ctx->r2 = MEM_W(0X7E9C, ctx->r1);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // jalr        $v0
    // sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    after_0:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // bltz        $a0, L_8007D408
    if (SIGNED(ctx->r4) < 0) {
        // nop
    
        goto L_8007D408;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E5C($v0)
    ctx->r2 = MEM_W(0X7E5C, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8007D3E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D3E4;
    }
    // nop

    // jal         0x8007F324
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    setRC2wait(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_1:
    // jal         0x8007D838
    // nop

    sub_8007D838(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // bne         $v0, $zero, L_8007D3E4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007D3E4;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E18($v0)
    ctx->r2 = MEM_W(0X7E18, ctx->r2);
    // nop

    // jalr        $v0
    // addiu       $a0, $zero, -0x3
    ctx->r4 = ADD32(0, -0X3);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_3;
    // addiu       $a0, $zero, -0x3
    ctx->r4 = ADD32(0, -0X3);
    after_3:
L_8007D3E4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E5C($v1)
    ctx->r3 = MEM_W(0X7E5C, ctx->r3);
    // nop

    // slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_8007D41C
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8007D41C;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // j           L_8007D41C
    // sw          $v0, 0x7E5C($at)
    MEM_W(0X7E5C, ctx->r1) = ctx->r2;
    goto L_8007D41C;
    // sw          $v0, 0x7E5C($at)
    MEM_W(0X7E5C, ctx->r1) = ctx->r2;
L_8007D408:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E18($v0)
    ctx->r2 = MEM_W(0X7E18, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_8007D41C:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
