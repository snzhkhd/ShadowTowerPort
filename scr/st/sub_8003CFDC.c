#include "recomp.h"
#include "disable_warnings.h"

void sub_8003CFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x76F8
    ctx->r3 = ADD32(ctx->r3, 0X76F8);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x140($v0)
    ctx->r2 = MEM_BU(0X140, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8003D028
    if (ctx->r2 == 0) {
        // slti        $v0, $v0, 0x4
        ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
        goto L_8003D028;
    }
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8003D028
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003D028;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(0X2C, ctx->r2);
    // lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
L_8003D028:
    // jr          $ra
    // nop

    return;
    // nop

;}
