#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libpad.h"

void PadGetState_0(uint8_t* rdram, recomp_context* ctx) 
{

   // ctx->r2 = PadGetState((int)ctx->r4);
    printf("PadGetState\n");
    ctx->r2 = 6; // PadStateStable

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7E2C($v0)
//    ctx->r2 = MEM_W(0X7E2C, ctx->r2);
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // sw          $ra, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r31;
//    // jalr        $v0
//    // nop
//
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_0;
//    // nop
//
//    after_0:
//    // addu        $a0, $v0, $zero
//    ctx->r4 = ADD32(ctx->r2, 0);
//    // lw          $v0, 0x34($a0)
//    ctx->r2 = MEM_W(0X34, ctx->r4);
//    // lui         $v1, 0xFFFF
//    ctx->r3 = S32(0XFFFF << 16);
//    // and         $v0, $v0, $v1
//    ctx->r2 = ctx->r2 & ctx->r3;
//    // bne         $v0, $zero, L_8007C978
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_8007C978;
//    }
//    // nop
//
//    // lw          $v0, 0x10($a0)
//    ctx->r2 = MEM_W(0X10, ctx->r4);
//    // nop
//
//    // beq         $a0, $v0, L_8007C960
//    if (ctx->r4 == ctx->r2) {
//        // nop
//    
//        goto L_8007C960;
//    }
//    // nop
//
//    // lbu         $v0, 0x38($a0)
//    ctx->r2 = MEM_BU(0X38, ctx->r4);
//    // nop
//
//    // bne         $v0, $zero, L_8007C978
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_8007C978;
//    }
//    // nop
//
//L_8007C960:
//    // lw          $v0, 0x30($a0)
//    ctx->r2 = MEM_W(0X30, ctx->r4);
//    // nop
//
//    // lbu         $v0, 0x0($v0)
//    ctx->r2 = MEM_BU(0X0, ctx->r2);
//    // nop
//
//    // beq         $v0, $zero, L_8007C9BC
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8007C9BC;
//    }
//    // nop
//
//L_8007C978:
//    // lbu         $v1, 0x49($a0)
//    ctx->r3 = MEM_BU(0X49, ctx->r4);
//    // addiu       $v0, $zero, 0x3
//    ctx->r2 = ADD32(0, 0X3);
//    // beq         $v1, $v0, L_8007C9B4
//    if (ctx->r3 == ctx->r2) {
//        // slti        $v0, $v1, 0x4
//        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
//        goto L_8007C9B4;
//    }
//    // slti        $v0, $v1, 0x4
//    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
//    // beq         $v0, $zero, L_8007C9A0
//    if (ctx->r2 == 0) {
//        // addiu       $v0, $zero, 0x2
//        ctx->r2 = ADD32(0, 0X2);
//        goto L_8007C9A0;
//    }
//    // addiu       $v0, $zero, 0x2
//    ctx->r2 = ADD32(0, 0X2);
//    // beq         $v1, $v0, L_8007C9C0
//    if (ctx->r3 == ctx->r2) {
//        // addiu       $v0, $zero, 0x1
//        ctx->r2 = ADD32(0, 0X1);
//        goto L_8007C9C0;
//    }
//    // addiu       $v0, $zero, 0x1
//    ctx->r2 = ADD32(0, 0X1);
//    // j           L_8007C9BC
//    // nop
//
//    goto L_8007C9BC;
//    // nop
//
//L_8007C9A0:
//    // addiu       $v0, $zero, 0x6
//    ctx->r2 = ADD32(0, 0X6);
//    // beq         $v1, $v0, L_8007C9C0
//    if (ctx->r3 == ctx->r2) {
//        // addiu       $v0, $zero, 0x4
//        ctx->r2 = ADD32(0, 0X4);
//        goto L_8007C9C0;
//    }
//    // addiu       $v0, $zero, 0x4
//    ctx->r2 = ADD32(0, 0X4);
//    // j           L_8007C9BC
//    // nop
//
//    goto L_8007C9BC;
//    // nop
//
//L_8007C9B4:
//    // j           L_8007C9C0
//    // addiu       $v0, $zero, 0x1
//    ctx->r2 = ADD32(0, 0X1);
//    goto L_8007C9C0;
//    // addiu       $v0, $zero, 0x1
//    ctx->r2 = ADD32(0, 0X1);
//L_8007C9BC:
//    // lbu         $v0, 0x49($a0)
//    ctx->r2 = MEM_BU(0X49, ctx->r4);
//L_8007C9C0:
//    // lw          $ra, 0x10($sp)
//    ctx->r31 = MEM_W(0X10, ctx->r29);
//    // addiu       $sp, $sp, 0x18
//    ctx->r29 = ADD32(ctx->r29, 0X18);
//    // jr          $ra
//    // nop
//
//    return;
//    // nop

;}
