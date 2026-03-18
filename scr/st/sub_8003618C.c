#include "recomp.h"
#include "disable_warnings.h"

void sub_8003618C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lw          $a1, 0xF1C($v0)
    ctx->r5 = MEM_W(0XF1C, ctx->r2);
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // lh          $v0, 0x40($a1)
    ctx->r2 = MEM_HS(0X40, ctx->r5);
    // lw          $v1, 0x20($a1)
    ctx->r3 = MEM_W(0X20, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lh          $v0, 0x42($a1)
    ctx->r2 = MEM_HS(0X42, ctx->r5);
    // lw          $v1, 0x24($a1)
    ctx->r3 = MEM_W(0X24, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // lh          $v0, 0x44($a1)
    ctx->r2 = MEM_HS(0X44, ctx->r5);
    // lw          $v1, 0x28($a1)
    ctx->r3 = MEM_W(0X28, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(0X1, ctx->r5);
    // nop

    // addiu       $v0, $v0, -0x2C
    ctx->r2 = ADD32(ctx->r2, -0X2C);
    // sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_800361FC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800361FC;
    }
    // nop

    // lh          $a1, 0x52($a1)
    ctx->r5 = MEM_HS(0X52, ctx->r5);
    // j           L_80036200
    // nop

    goto L_80036200;
    // nop

L_800361FC:
    // addiu       $a1, $zero, 0x1400
    ctx->r5 = ADD32(0, 0X1400);
L_80036200:
    // jal         0x80036150
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    sub_80036150(rdram, ctx);
    goto after_0;
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
