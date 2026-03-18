#include "recomp.h"
#include "disable_warnings.h"

void _spu_FiDMA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD90($v0)
    ctx->r2 = MEM_W(0XD90, ctx->r2);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // bne         $v0, $zero, L_8006C100
    if (ctx->r2 != 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_8006C100;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x8006C77C
    // nop

    _spu_Fw1ts(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_8006C100:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD40($a0)
    ctx->r4 = MEM_W(0XD40, ctx->r4);
    // nop

    // lhu         $v0, 0x1AA($a0)
    ctx->r2 = MEM_HU(0X1AA, ctx->r4);
    // nop

    // andi        $v0, $v0, 0xFFCF
    ctx->r2 = ctx->r2 & 0XFFCF;
    // sh          $v0, 0x1AA($a0)
    MEM_H(0X1AA, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x1AA($a0)
    ctx->r2 = MEM_HU(0X1AA, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // beq         $v0, $zero, L_8006C154
    if (ctx->r2 == 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8006C154;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006C134:
    // sltiu       $v0, $v1, 0xF01
    ctx->r2 = ctx->r3 < 0XF01 ? 1 : 0;
    // beq         $v0, $zero, L_8006C154
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006C154;
    }
    // nop

    // lhu         $v0, 0x1AA($a0)
    ctx->r2 = MEM_HU(0X1AA, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // bne         $v0, $zero, L_8006C134
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8006C134;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006C154:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD78($v0)
    ctx->r2 = MEM_W(0XD78, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8006C184
    if (ctx->r2 == 0) {
        // lui         $a0, 0xF000
        ctx->r4 = S32(0XF000 << 16);
        goto L_8006C184;
    }
    // lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD78($v0)
    ctx->r2 = MEM_W(0XD78, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_8006C190
    // nop

    goto L_8006C190;
    // nop

L_8006C184:
    // ori         $a0, $a0, 0x9
    ctx->r4 = ctx->r4 | 0X9;
    // jal         0x80077DF4
    // addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    DeliverEvent(rdram, ctx);
    goto after_2;
    // addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_2:
L_8006C190:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
