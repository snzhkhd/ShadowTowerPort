#include "recomp.h"
#include "disable_warnings.h"

void _remove_ChgclrPAD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $ra, -0x66D8($at)
    MEM_W(-0X66D8, ctx->r1) = ctx->r31;
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
    // addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // lw          $v0, 0x16C($v0)
    ctx->r2 = MEM_W(0X16C, ctx->r2);
    // nop

    // addi        $v1, $v0, 0x62C
    ctx->r3 = ADD32(ctx->r2, 0X62C);
L_80078794:
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // bne         $t2, $zero, L_80078794
    if (ctx->r10 != 0) {
        // nop
    
        goto L_80078794;
    }
    // nop

    // jal         0x80077DC4
    // nop

    FlushCache(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lui         $ra, 0x801F
    ctx->r31 = S32(0X801F << 16);
    // lw          $ra, -0x66D8($ra)
    ctx->r31 = MEM_W(-0X66D8, ctx->r31);
    // nop

    // jr          $ra
    // nop

    return;
    // nop

;}
