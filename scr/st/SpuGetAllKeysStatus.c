#include "recomp.h"
#include "disable_warnings.h"

void SpuGetAllKeysStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_8006BC30:
    // sll         $a0, $a2, 4
    ctx->r4 = S32(ctx->r6) << 4;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xDAC($v1)
    ctx->r3 = MEM_W(0XDAC, ctx->r3);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sllv        $v0, $a3, $a2
    ctx->r2 = S32(ctx->r7) << (ctx->r6 & 31);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(0XC, ctx->r4);
    // beq         $v1, $zero, L_8006BC74
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8006BC74;
    }
    // nop

    // beq         $v0, $zero, L_8006BC6C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006BC6C;
    }
    // nop

    // j           L_8006BC88
    // sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
    goto L_8006BC88;
    // sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
L_8006BC6C:
    // j           L_8006BC88
    // sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
    goto L_8006BC88;
    // sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
L_8006BC74:
    // beq         $v0, $zero, L_8006BC84
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006BC84;
    }
    // nop

    // j           L_8006BC88
    // sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
    goto L_8006BC88;
    // sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
L_8006BC84:
    // sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_8006BC88:
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slt         $v0, $a2, $t2
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r10) ? 1 : 0;
    // bne         $v0, $zero, L_8006BC30
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_8006BC30;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // jr          $ra
    // nop

    return;
    // nop

;}
