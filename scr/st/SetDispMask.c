#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_render.h"

void SetDispMask(uint8_t* rdram, recomp_context* ctx) 
{

	SetDispMask((int)ctx->r4);

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x20
//    ctx->r29 = ADD32(ctx->r29, -0X20);
//    // sw          $s1, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r17;
//    // lui         $s1, 0x8008
//    ctx->r17 = S32(0X8008 << 16);
//    // addiu       $s1, $s1, 0x7CC2
//    ctx->r17 = ADD32(ctx->r17, 0X7CC2);
//    // sw          $ra, 0x18($sp)
//    MEM_W(0X18, ctx->r29) = ctx->r31;
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // lbu         $v0, 0x0($s1)
//    ctx->r2 = MEM_BU(0X0, ctx->r17);
//    // nop
//
//    // sltiu       $v0, $v0, 0x2
//    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
//    // bne         $v0, $zero, L_80079A10
//    if (ctx->r2 != 0) {
//        // addu        $s0, $a0, $zero
//        ctx->r16 = ADD32(ctx->r4, 0);
//        goto L_80079A10;
//    }
//    // addu        $s0, $a0, $zero
//    ctx->r16 = ADD32(ctx->r4, 0);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x41A4
//    ctx->r4 = ADD32(ctx->r4, 0X41A4);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7CBC($v0)
//    ctx->r2 = MEM_W(0X7CBC, ctx->r2);
//    // nop
//
//    // jalr        $v0
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_0;
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//    after_0:
//L_80079A10:
//    // bne         $s0, $zero, L_80079A24
//    if (ctx->r16 != 0) {
//        // addiu       $a0, $s1, 0x6A
//        ctx->r4 = ADD32(ctx->r17, 0X6A);
//        goto L_80079A24;
//    }
//    // addiu       $a0, $s1, 0x6A
//    ctx->r4 = ADD32(ctx->r17, 0X6A);
//    // addiu       $a1, $zero, -0x1
//    ctx->r5 = ADD32(0, -0X1);
//    // jal         0x8007C6C8
//    // addiu       $a2, $zero, 0x14
//    ctx->r6 = ADD32(0, 0X14);
//    sub_8007C6C8(rdram, ctx);
//    goto after_1;
//    // addiu       $a2, $zero, 0x14
//    ctx->r6 = ADD32(0, 0X14);
//    after_1:
//L_80079A24:
//    // lui         $a0, 0x300
//    ctx->r4 = S32(0X300 << 16);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7CB8($v0)
//    ctx->r2 = MEM_W(0X7CB8, ctx->r2);
//    // beq         $s0, $zero, L_80079A3C
//    if (ctx->r16 == 0) {
//        // ori         $a0, $a0, 0x1
//        ctx->r4 = ctx->r4 | 0X1;
//        goto L_80079A3C;
//    }
//    // ori         $a0, $a0, 0x1
//    ctx->r4 = ctx->r4 | 0X1;
//    // lui         $a0, 0x300
//    ctx->r4 = S32(0X300 << 16);
//L_80079A3C:
//    // lw          $v0, 0x10($v0)
//    ctx->r2 = MEM_W(0X10, ctx->r2);
//    // nop
//
//    // jalr        $v0
//    // nop
//
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_2;
//    // nop
//
//    after_2:
//    // lw          $ra, 0x18($sp)
//    ctx->r31 = MEM_W(0X18, ctx->r29);
//    // lw          $s1, 0x14($sp)
//    ctx->r17 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // jr          $ra
//    // addiu       $sp, $sp, 0x20
//    ctx->r29 = ADD32(ctx->r29, 0X20);
//    return;
//    // addiu       $sp, $sp, 0x20
//    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
