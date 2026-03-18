#include "recomp.h"
#include "disable_warnings.h"

void sub_8007F2EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lhu         $v0, 0xE6($a0)
    ctx->r2 = MEM_HU(0XE6, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8007F30C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8007F30C;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // lbu         $v1, 0x46($a0)
    ctx->r3 = MEM_BU(0X46, ctx->r4);
    // nop

    // beq         $v1, $v0, L_8007F310
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007F310;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007F30C:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007F310:
    // jr          $ra
    // nop

    return;
    // nop

;}
