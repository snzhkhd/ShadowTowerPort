#include "recomp.h"
#include "disable_warnings.h"

void _ExitCard_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $ra, -0x6738($at)
    MEM_W(-0X6738, ctx->r1) = ctx->r31;
    // jal         0x80077E94
    // nop

    EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addiu       $t1, $zero, 0x56
    ctx->r9 = ADD32(0, 0X56);
    // addiu       $t2, $zero, 0xB0
    ctx->r10 = ADD32(0, 0XB0);
    // jalr        $t2
    // nop

    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(0X18, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // addu        $t7, $v0, $zero
    ctx->r15 = ADD32(ctx->r2, 0);
    // lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // addiu       $t2, $t2, 0x70D0
    ctx->r10 = ADD32(ctx->r10, 0X70D0);
    // lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // addiu       $t1, $t1, 0x70E8
    ctx->r9 = ADD32(ctx->r9, 0X70E8);
L_80077064:
    // lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(0X0, ctx->r10);
    // lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(0X0, ctx->r2);
    // addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // bne         $v1, $t3, L_800770AC
    if (ctx->r3 != ctx->r11) {
        // addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
        goto L_800770AC;
    }
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // bne         $t2, $t1, L_80077064
    if (ctx->r10 != ctx->r9) {
        // nop
    
        goto L_80077064;
    }
    // nop

    // addu        $v0, $t7, $zero
    ctx->r2 = ADD32(ctx->r15, 0);
    // lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // addiu       $t2, $t2, 0x70E8
    ctx->r10 = ADD32(ctx->r10, 0X70E8);
    // lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // addiu       $t1, $t1, 0x7100
    ctx->r9 = ADD32(ctx->r9, 0X7100);
L_80077094:
    // lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(0X0, ctx->r10);
    // nop

    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // bne         $t2, $t1, L_80077094
    if (ctx->r10 != ctx->r9) {
        // addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
        goto L_80077094;
    }
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800770AC:
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
    // lw          $ra, -0x6738($ra)
    ctx->r31 = MEM_W(-0X6738, ctx->r31);
    // nop

    // jr          $ra
    // nop

    return;
    // nop

;}
