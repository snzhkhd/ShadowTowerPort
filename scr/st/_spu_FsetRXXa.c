#include "recomp.h"
#include "disable_warnings.h"

void _spu_FsetRXXa(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD64($v0)
    ctx->r2 = MEM_W(0XD64, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8006C644
    if (ctx->r2 == 0) {
        // addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
        goto L_8006C644;
    }
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD6C($a0)
    ctx->r4 = MEM_W(0XD6C, ctx->r4);
    // nop

    // divu        $zero, $a1, $a0
    lo = S32(U32(ctx->r5) / U32(ctx->r4)); hi = S32(U32(ctx->r5) % U32(ctx->r4));
    // bne         $a0, $zero, L_8006C624
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8006C624;
    }
    // nop

    // break       7
    do_break(2147927584);
L_8006C624:
    // mfhi        $v0
    ctx->r2 = hi;
    // beq         $v0, $zero, L_8006C644
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006C644;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD70($v0)
    ctx->r2 = MEM_W(0XD70, ctx->r2);
    // addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
L_8006C644:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD68($v0)
    ctx->r2 = MEM_W(0XD68, ctx->r2);
    // nop

    // srlv        $a3, $a1, $v0
    ctx->r7 = S32(U32(ctx->r5) >> (ctx->r2 & 31));
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // beq         $a2, $v0, L_8006C674
    if (ctx->r6 == ctx->r2) {
        // addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
        goto L_8006C674;
    }
    // addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $a2, $v0, L_8006C67C
    if (ctx->r6 != ctx->r2) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_8006C67C;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // j           L_8006C690
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    goto L_8006C690;
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
L_8006C674:
    // j           L_8006C690
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    goto L_8006C690;
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_8006C67C:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD40($a0)
    ctx->r4 = MEM_W(0XD40, ctx->r4);
    // sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $a3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r7;
L_8006C690:
    // jr          $ra
    // nop

    return;
    // nop

;}
