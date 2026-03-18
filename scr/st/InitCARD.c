#include "recomp.h"
#include "disable_warnings.h"

void InitCARD(uint8_t* rdram, recomp_context* ctx) {
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
    // jal         0x80077F24
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ChangeClearPAD(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // jal         0x80077E94
    // nop

    EnterCriticalSection(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x80078370
    // nop

    ReadInitPadFlag(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // bne         $v0, $zero, L_80068718
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80068718;
    }
    // nop

    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80068718:
    // jal         0x800687B4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    InitCARD2(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // jal         0x80068980
    // nop

    _copy_memcard_patch(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x8006887C
    // nop

    _patch_card(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x80068910
    // nop

    _patch_card2(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_7;
    // nop

    after_7:
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
