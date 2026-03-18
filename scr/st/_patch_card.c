#include "recomp.h"
#include "disable_warnings.h"

void _patch_card(uint8_t* rdram, recomp_context* ctx) {
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

    // lw          $v1, 0x70($v0)
    ctx->r3 = MEM_W(0X70, ctx->r2);
    // nop

    // andi        $t1, $v1, 0xFFFF
    ctx->r9 = ctx->r3 & 0XFFFF;
    // sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) << 16;
    // lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(0X74, ctx->r2);
    // nop

    // andi        $t2, $v1, 0xFFFF
    ctx->r10 = ctx->r3 & 0XFFFF;
    // addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // addiu       $t2, $t2, -0x77AC
    ctx->r10 = ADD32(ctx->r10, -0X77AC);
    // lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // addiu       $t1, $t1, -0x7798
    ctx->r9 = ADD32(ctx->r9, -0X7798);
L_800688D8:
    // lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(0X0, ctx->r10);
    // nop

    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // bne         $t2, $t1, L_800688D8
    if (ctx->r10 != ctx->r9) {
        // addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
        goto L_800688D8;
    }
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // jal         0x80077DC4
    // sw          $v0, -0x2004($at)
    MEM_W(-0X2004, ctx->r1) = ctx->r2;
    FlushCache(rdram, ctx);
    goto after_2;
    // sw          $v0, -0x2004($at)
    MEM_W(-0X2004, ctx->r1) = ctx->r2;
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
