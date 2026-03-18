#include "recomp.h"
#include "disable_warnings.h"

void sub_8007D910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lbu         $v1, 0x46($a0)
    ctx->r3 = MEM_BU(0X46, ctx->r4);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_8007D964
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
        goto L_8007D964;
    }
    // slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8007D940
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8007D940;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_8007D954
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007D954;
    }
    // nop

    // j           L_8007D984
    // nop

    goto L_8007D984;
    // nop

L_8007D940:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_8007D978
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007D978;
    }
    // nop

    // j           L_8007D984
    // nop

    goto L_8007D984;
    // nop

L_8007D954:
    // jal         0x8007E1C0
    // nop

    sub_8007E1C0(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_8007D984
    // nop

    goto L_8007D984;
    // nop

L_8007D964:
    // lbu         $a1, 0xE4($a0)
    ctx->r5 = MEM_BU(0XE4, ctx->r4);
    // jal         0x8007E1D4
    // nop

    sub_8007E1D4(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_8007D984
    // nop

    goto L_8007D984;
    // nop

L_8007D978:
    // lbu         $a1, 0x47($a0)
    ctx->r5 = MEM_BU(0X47, ctx->r4);
    // jal         0x8007E214
    // nop

    sub_8007E214(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_8007D984:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
