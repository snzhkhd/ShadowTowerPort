#include "recomp.h"
#include "disable_warnings.h"

void CdReset(uint8_t* rdram, recomp_context* ctx) 
{
	printf("[CD] CdReset(%d)\n", ctx->r4);
	ctx->r2 = 1;
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // addu        $s0, $a0, $zero
//    ctx->r16 = ADD32(ctx->r4, 0);
//    // addiu       $v0, $zero, 0x2
//    ctx->r2 = ADD32(0, 0X2);
//    // bne         $s0, $v0, L_80068B98
//    if (ctx->r16 != ctx->r2) {
//        // sw          $ra, 0x14($sp)
//        MEM_W(0X14, ctx->r29) = ctx->r31;
//        goto L_80068B98;
//    }
//    // sw          $ra, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r31;
//    // jal         0x8006A3C0
//    // nop
//
//    CD_initintr(rdram, ctx);
//    goto after_0;
//    // nop
//
//    after_0:
//    // j           L_80068BCC
//    // addiu       $v0, $zero, 0x1
//    ctx->r2 = ADD32(0, 0X1);
//    goto L_80068BCC;
//    // addiu       $v0, $zero, 0x1
//    ctx->r2 = ADD32(0, 0X1);
//L_80068B98:
//    // jal         0x8006A40C
//    // nop
//
//    CD_init(rdram, ctx);
//    goto after_1;
//    // nop
//
//    after_1:
//    // bne         $v0, $zero, L_80068BCC
//    if (ctx->r2 != 0) {
//        // addu        $v0, $zero, $zero
//        ctx->r2 = ADD32(0, 0);
//        goto L_80068BCC;
//    }
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    // addiu       $v0, $zero, 0x1
//    ctx->r2 = ADD32(0, 0X1);
//    // bne         $s0, $v0, L_80068BCC
//    if (ctx->r16 != ctx->r2) {
//        // nop
//    
//        goto L_80068BCC;
//    }
//    // nop
//
//    // jal         0x8006A2D0
//    // nop
//
//    CD_initvol(rdram, ctx);
//    goto after_2;
//    // nop
//
//    after_2:
//    // addu        $v1, $v0, $zero
//    ctx->r3 = ADD32(ctx->r2, 0);
//    // bne         $v1, $zero, L_80068BCC
//    if (ctx->r3 != 0) {
//        // addu        $v0, $zero, $zero
//        ctx->r2 = ADD32(0, 0);
//        goto L_80068BCC;
//    }
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    // addiu       $v0, $zero, 0x1
//    ctx->r2 = ADD32(0, 0X1);
//L_80068BCC:
//    // lw          $ra, 0x14($sp)
//    ctx->r31 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // jr          $ra
//    // addiu       $sp, $sp, 0x18
//    ctx->r29 = ADD32(ctx->r29, 0X18);
//    return;
//    // addiu       $sp, $sp, 0x18
//    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
