#include "recomp.h"
#include "disable_warnings.h"

void sub_8004DE24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(0X2, ctx->r4);
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) << 6;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x29C8
    ctx->r2 = ADD32(ctx->r2, -0X29C8);
    // bne         $a1, $zero, L_8004DEF0
    if (ctx->r5 != 0) {
        // addu        $v1, $v1, $v0
        ctx->r3 = ADD32(ctx->r3, ctx->r2);
        goto L_8004DEF0;
    }
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $t0, $v1, 0x4A
    ctx->r8 = ADD32(ctx->r3, 0X4A);
    // addu        $a3, $t1, $zero
    ctx->r7 = ADD32(ctx->r9, 0);
    // addiu       $t2, $zero, 0x3E8
    ctx->r10 = ADD32(0, 0X3E8);
L_8004DE54:
    // lhu         $a0, 0x0($a2)
    ctx->r4 = MEM_HU(0X0, ctx->r6);
    // nop

    // beq         $a0, $zero, L_8004DEDC
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8004DEDC;
    }
    // nop

    // lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(0X0, ctx->r8);
    // nop

    // beq         $v0, $zero, L_8004DE78
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
        goto L_8004DE78;
    }
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8004DE78:
    // subu        $v0, $t2, $a0
    ctx->r2 = SUB32(ctx->r10, ctx->r4);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v1, $v0, 6
    ctx->r3 = S32(ctx->r2) << 6;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mflo        $a1
    ctx->r5 = lo;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_8004DEB8
    if (ctx->r5 != 0) {
        // nop
    
        goto L_8004DEB8;
    }
    // nop

    // break       7
    do_break(2147802804);
L_8004DEB8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_8004DED0
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8004DED0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8004DED0
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8004DED0;
    }
    // nop

    // break       6
    do_break(2147802828);
L_8004DED0:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
L_8004DEDC:
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // slti        $v0, $a3, 0x9
    ctx->r2 = SIGNED(ctx->r7) < 0X9 ? 1 : 0;
    // bne         $v0, $zero, L_8004DE54
    if (ctx->r2 != 0) {
        // addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
        goto L_8004DE54;
    }
    // addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
L_8004DEF0:
    // jr          $ra
    // addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    return;
    // addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
;}
