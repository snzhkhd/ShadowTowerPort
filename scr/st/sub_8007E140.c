#include "recomp.h"
#include "disable_warnings.h"

void sub_8007E140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x53($a0)
    ctx->r2 = MEM_BU(0X53, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8007E178
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8007E178;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lbu         $v1, 0x46($a0)
    ctx->r3 = MEM_BU(0X46, ctx->r4);
    // nop

    // bne         $v1, $v0, L_8007E170
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xFE
        ctx->r2 = ADD32(0, 0XFE);
        goto L_8007E170;
    }
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // j           L_8007E190
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_8007E190;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007E170:
    // j           L_8007E18C
    // sb          $v0, 0x46($a0)
    MEM_B(0X46, ctx->r4) = ctx->r2;
    goto L_8007E18C;
    // sb          $v0, 0x46($a0)
    MEM_B(0X46, ctx->r4) = ctx->r2;
L_8007E178:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E1C($v0)
    ctx->r2 = MEM_W(0X7E1C, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_8007E18C:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007E190:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
