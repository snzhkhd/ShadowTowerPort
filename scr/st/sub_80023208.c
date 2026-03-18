#include "recomp.h"
#include "disable_warnings.h"

void sub_80023208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // sltiu       $v0, $v0, 0x12C
    ctx->r2 = ctx->r2 < 0X12C ? 1 : 0;
    // bne         $v0, $zero, L_80023280
    if (ctx->r2 != 0) {
        // addiu       $v0, $a0, 0x100
        ctx->r2 = ADD32(ctx->r4, 0X100);
        goto L_80023280;
    }
    // addiu       $v0, $a0, 0x100
    ctx->r2 = ADD32(ctx->r4, 0X100);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $a1, $v0, 0x5920
    ctx->r5 = ADD32(ctx->r2, 0X5920);
    // lh          $v1, 0x5920($v0)
    ctx->r3 = MEM_HS(0X5920, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8002326C
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8002326C;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v0, 0x1E($a1)
    ctx->r2 = MEM_BU(0X1E, ctx->r5);
    // nop

    // bne         $v0, $v1, L_8002326C
    if (ctx->r2 != ctx->r3) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8002326C;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x10($a1)
    ctx->r3 = MEM_BU(0X10, ctx->r5);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80023268
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80023268;
    }
    // nop

    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // j           L_80023280
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    goto L_80023280;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
L_80023268:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_8002326C:
    // lbu         $v0, 0x5924($v0)
    ctx->r2 = MEM_BU(0X5924, ctx->r2);
    // nop

    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
L_80023280:
    // jr          $ra
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
;}
