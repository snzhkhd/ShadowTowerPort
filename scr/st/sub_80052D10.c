#include "recomp.h"
#include "disable_warnings.h"

void sub_80052D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a2, $v0, 0x76F8
    ctx->r6 = ADD32(ctx->r2, 0X76F8);
    // addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80052D24:
    // addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $a0, L_80052D24
    if (ctx->r3 != ctx->r4) {
        // sb          $a1, 0x94($v0)
        MEM_B(0X94, ctx->r2) = ctx->r5;
        goto L_80052D24;
    }
    // sb          $a1, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r5;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // jr          $ra
    // sw          $zero, 0x780C($v0)
    MEM_W(0X780C, ctx->r2) = 0;
    return;
    // sw          $zero, 0x780C($v0)
    MEM_W(0X780C, ctx->r2) = 0;
;}
