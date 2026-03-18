#include "recomp.h"
#include "disable_warnings.h"

void _spu_Fw1ts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // j           L_8006C7BC
    // sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    goto L_8006C7BC;
    // sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8006C790:
    // lw          $v1, 0x4($sp)
    ctx->r3 = MEM_W(0X4, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(0X0, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8006C7BC:
    // lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(0X0, ctx->r29);
    // nop

    // slti        $v0, $v0, 0x3C
    ctx->r2 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // bne         $v0, $zero, L_8006C790
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006C790;
    }
    // nop

    // jr          $ra
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
