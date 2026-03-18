#include "recomp.h"
#include "disable_warnings.h"

void sub_80055990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $v1, $zero, 0x139
    ctx->r3 = ADD32(0, 0X139);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x7590
    ctx->r2 = ADD32(ctx->r2, 0X7590);
    // addiu       $v0, $v0, 0x139
    ctx->r2 = ADD32(ctx->r2, 0X139);
L_800559A0:
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bgez        $v1, L_800559A0
    if (SIGNED(ctx->r3) >= 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_800559A0;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // jr          $ra
    // sb          $zero, -0x70B1($v0)
    MEM_B(-0X70B1, ctx->r2) = 0;
    return;
    // sb          $zero, -0x70B1($v0)
    MEM_B(-0X70B1, ctx->r2) = 0;
;}
