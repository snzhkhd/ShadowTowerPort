#include "recomp.h"
#include "disable_warnings.h"

void sub_80071FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x6901
    ctx->r3 = ADD32(ctx->r3, -0X6901);
    // lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(0X5, ctx->r3);
    // lb          $v1, 0x0($v1)
    ctx->r3 = MEM_BS(0X0, ctx->r3);
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lw          $v1, -0x6910($v1)
    ctx->r3 = MEM_W(-0X6910, ctx->r3);
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(0X5, ctx->r3);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // bgez        $v0, L_80072024
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $t0, $a0, $zero
        ctx->r8 = ADD32(ctx->r4, 0);
        goto L_80072024;
    }
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
L_80072024:
    // sra         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2) >> 3;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80072040
    if (ctx->r2 != 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_80072040;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // addiu       $a3, $a1, -0x10
    ctx->r7 = ADD32(ctx->r5, -0X10);
L_80072040:
    // lui         $a0, 0x2AAA
    ctx->r4 = S32(0X2AAA << 16);
    // ori         $a0, $a0, 0xAAAB
    ctx->r4 = ctx->r4 | 0XAAAB;
    // lbu         $v1, 0x4($v1)
    ctx->r3 = MEM_BU(0X4, ctx->r3);
    // addiu       $v0, $t0, 0x3C
    ctx->r2 = ADD32(ctx->r8, 0X3C);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $a0, $t1, 1
    ctx->r4 = S32(ctx->r9) >> 1;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addiu       $a0, $a0, -0x5
    ctx->r4 = ADD32(ctx->r4, -0X5);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) >> 16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lhu         $v1, 0x1570($at)
    ctx->r3 = MEM_HU(0X1570, ctx->r1);
    // blez        $v0, L_800720C4
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_800720C4;
    }
    // nop

    // j           L_800720D8
    // sllv        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3) << (ctx->r2 & 31);
    goto L_800720D8;
    // sllv        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3) << (ctx->r2 & 31);
L_800720C4:
    // bgez        $v0, L_800720D8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800720D8;
    }
    // nop

    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // srav        $v1, $v1, $v0
    ctx->r3 = S32(ctx->r3) >> (ctx->r2 & 31);
L_800720D8:
    // jr          $ra
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    return;
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
;}
