#include "recomp.h"
#include "disable_warnings.h"

void _patch_card2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $ra, 0x6150($at)
    MEM_W(0X6150, ctx->r1) = ctx->r31;
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
    // nop

    // lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(0X9C8, ctx->r2);
    // lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // addiu       $t2, $t2, -0x7798
    ctx->r10 = ADD32(ctx->r10, -0X7798);
    // lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // addiu       $t1, $t1, -0x7784
    ctx->r9 = ADD32(ctx->r9, -0X7784);
L_8006894C:
    // lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(0X0, ctx->r10);
    // nop

    // sw          $t0, 0x9C8($v0)
    MEM_W(0X9C8, ctx->r2) = ctx->r8;
    // addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // bne         $t2, $t1, L_8006894C
    if (ctx->r10 != ctx->r9) {
        // addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
        goto L_8006894C;
    }
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // jal         0x80077DC4
    // nop

    FlushCache(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $ra, 0x801E
    ctx->r31 = S32(0X801E << 16);
    // lw          $ra, 0x6150($ra)
    ctx->r31 = MEM_W(0X6150, ctx->r31);
    // nop

    // jr          $ra
    // nop

    return;
    // nop

;}
