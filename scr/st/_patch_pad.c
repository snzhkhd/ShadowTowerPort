#include "recomp.h"
#include "disable_warnings.h"

void _patch_pad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $ra, -0x66E8($at)
    MEM_W(-0X66E8, ctx->r1) = ctx->r31;
    // jal         0x80077E94
    // nop

    EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addiu       $t1, $zero, 0x57
    ctx->r9 = ADD32(0, 0X57);
    // addiu       $t2, $zero, 0xB0
    ctx->r10 = ADD32(0, 0XB0);
    // jalr        $t2
    // nop

    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $v0, 0x16C($v0)
    ctx->r2 = MEM_W(0X16C, ctx->r2);
    // addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // addi        $v1, $v0, 0x884
    ctx->r3 = ADD32(ctx->r2, 0X884);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v1, -0x66E0($at)
    MEM_W(-0X66E0, ctx->r1) = ctx->r3;
    // addi        $v1, $v0, 0x894
    ctx->r3 = ADD32(ctx->r2, 0X894);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v1, -0x66DC($at)
    MEM_W(-0X66DC, ctx->r1) = ctx->r3;
L_8007872C:
    // sw          $zero, 0x594($v0)
    MEM_W(0X594, ctx->r2) = 0;
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // bne         $t1, $zero, L_8007872C
    if (ctx->r9 != 0) {
        // nop
    
        goto L_8007872C;
    }
    // nop

    // jal         0x80077DC4
    // nop

    FlushCache(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $ra, 0x801F
    ctx->r31 = S32(0X801F << 16);
    // lw          $ra, -0x66E8($ra)
    ctx->r31 = MEM_W(-0X66E8, ctx->r31);
    // nop

    // jr          $ra
    // nop

    return;
    // nop

;}
