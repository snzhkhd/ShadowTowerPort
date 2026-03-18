#include "recomp.h"
#include "disable_warnings.h"

void sub_8007DBEC(uint8_t* rdram, recomp_context* ctx) {
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
    // beq         $v1, $v0, L_8007DC44
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
        goto L_8007DC44;
    }
    // slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8007DC1C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8007DC1C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_8007DC30
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007DC30;
    }
    // nop

    // j           L_8007DC84
    // nop

    goto L_8007DC84;
    // nop

L_8007DC1C:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_8007DC58
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007DC58;
    }
    // nop

    // j           L_8007DC84
    // nop

    goto L_8007DC84;
    // nop

L_8007DC30:
    // lbu         $a1, 0x47($a0)
    ctx->r5 = MEM_BU(0X47, ctx->r4);
    // jal         0x8007E1D4
    // nop

    sub_8007E1D4(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_8007DC84
    // nop

    goto L_8007DC84;
    // nop

L_8007DC44:
    // lbu         $a1, 0x47($a0)
    ctx->r5 = MEM_BU(0X47, ctx->r4);
    // jal         0x8007E1F4
    // nop

    sub_8007E1F4(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_8007DC84
    // nop

    goto L_8007DC84;
    // nop

L_8007DC58:
    // lbu         $v0, 0x48($a0)
    ctx->r2 = MEM_BU(0X48, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8007DC7C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007DC7C;
    }
    // nop

    // lbu         $a1, 0x47($a0)
    ctx->r5 = MEM_BU(0X47, ctx->r4);
    // jal         0x8007E214
    // nop

    sub_8007E214(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_8007DC84
    // nop

    goto L_8007DC84;
    // nop

L_8007DC7C:
    // jal         0x8007E234
    // nop

    sub_8007E234(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_8007DC84:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
