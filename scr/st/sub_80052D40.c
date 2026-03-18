#include "recomp.h"
#include "disable_warnings.h"

void sub_80052D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // slti        $v0, $v1, 0x10A
    ctx->r2 = SIGNED(ctx->r3) < 0X10A ? 1 : 0;
    // beq         $v0, $zero, L_80052D8C
    if (ctx->r2 == 0) {
        // addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
        goto L_80052D8C;
    }
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // bgez        $v1, L_80052D60
    if (SIGNED(ctx->r3) >= 0) {
        // addiu       $a2, $v0, 0x76F8
        ctx->r6 = ADD32(ctx->r2, 0X76F8);
        goto L_80052D60;
    }
    // addiu       $a2, $v0, 0x76F8
    ctx->r6 = ADD32(ctx->r2, 0X76F8);
    // addiu       $a1, $v1, 0x1F
    ctx->r5 = ADD32(ctx->r3, 0X1F);
L_80052D60:
    // sra         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5) >> 5;
    // sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5) << 2;
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5) << 5;
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // lw          $a0, 0x70($a0)
    ctx->r4 = MEM_W(0X70, ctx->r4);
    // sllv        $v1, $v1, $a1
    ctx->r3 = S32(ctx->r3) << (ctx->r5 & 31);
    // and         $a0, $a0, $v1
    ctx->r4 = ctx->r4 & ctx->r3;
    // bne         $a0, $zero, L_80052D90
    if (ctx->r4 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80052D90;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80052D8C:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80052D90:
    // jr          $ra
    // nop

    return;
    // nop

;}
