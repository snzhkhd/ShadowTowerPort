#include "recomp.h"
#include "disable_warnings.h"

void sub_80052D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(0X0, ctx->r5);
    // addiu       $v0, $v0, 0x7590
    ctx->r2 = ADD32(ctx->r2, 0X7590);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // andi        $v1, $v1, 0x80
    ctx->r3 = ctx->r3 & 0X80;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(0X0, ctx->r5);
    // addiu       $v0, $zero, 0x10A
    ctx->r2 = ADD32(0, 0X10A);
    // bne         $v1, $v0, L_80052DF0
    if (ctx->r3 != ctx->r2) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_80052DF0;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lbu         $v0, 0x27($v1)
    ctx->r2 = MEM_BU(0X27, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x27($v1)
    MEM_B(0X27, ctx->r3) = ctx->r2;
L_80052DF0:
    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // nop

    // sltiu       $v0, $v0, 0x10A
    ctx->r2 = ctx->r2 < 0X10A ? 1 : 0;
    // beq         $v0, $zero, L_80052E48
    if (ctx->r2 == 0) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_80052E48;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lhu         $v0, 0x28($v1)
    ctx->r2 = MEM_HU(0X28, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r2;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lhu         $a1, 0x0($a1)
    ctx->r5 = MEM_HU(0X0, ctx->r5);
    // addiu       $v0, $v0, 0x76F8
    ctx->r2 = ADD32(ctx->r2, 0X76F8);
    // srl         $a0, $a1, 5
    ctx->r4 = S32(U32(ctx->r5) >> 5);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // andi        $a1, $a1, 0x1F
    ctx->r5 = ctx->r5 & 0X1F;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $v1, 0x70($a0)
    ctx->r3 = MEM_W(0X70, ctx->r4);
    // sllv        $v0, $v0, $a1
    ctx->r2 = S32(ctx->r2) << (ctx->r5 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r3;
L_80052E48:
    // jr          $ra
    // nop

    return;
    // nop

;}
