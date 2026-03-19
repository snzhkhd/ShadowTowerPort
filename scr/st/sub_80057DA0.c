#include "recomp.h"
#include "disable_warnings.h"

void sub_80057DA0(uint8_t* rdram, recomp_context* ctx) 
{
    printf("80057DA0\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x8006CA24
    // nop

    MemCardInit(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x8006D044
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    SsSetMVol(rdram, ctx);
    goto after_1;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_1:
    // jal         0x8006E984
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    SsSetTickMode(rdram, ctx);
    goto after_2;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // jal         0x8006D2E4
    // nop

    SsStart2(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x80070274
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    SsUtSetReverbType(rdram, ctx);
    goto after_4;
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_4:
    // jal         0x800703F4
    // nop

    SsUtReverbOn(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // jal         0x8006F584
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    SsUtSetReverbDepth(rdram, ctx);
    goto after_6;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_6:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x8006CC04
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    SsSetSerialAttr(rdram, ctx);
    goto after_7;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // sb          $zero, -0x2E40($v0)
    MEM_B(-0X2E40, ctx->r2) = 0;
    // addiu       $v0, $v0, -0x2E40
    ctx->r2 = ADD32(ctx->r2, -0X2E40);
    // addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80057E10:
    // sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $v1, L_80057E10
    if (ctx->r4 != ctx->r3) {
        // addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_80057E10;
    }
    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x2408
    ctx->r2 = ADD32(ctx->r2, -0X2408);
    // addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80057E38:
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $a1, L_80057E38
    if (ctx->r4 != ctx->r5) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_80057E38;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v1, $v0, 0xC64
    ctx->r3 = ADD32(ctx->r2, 0XC64);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a1, $v0, -0x2E40
    ctx->r5 = ADD32(ctx->r2, -0X2E40);
L_80057E64:
    // sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80057E64
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x1000
        ctx->r5 = ADD32(ctx->r5, 0X1000);
        goto L_80057E64;
    }
    // addiu       $a1, $a1, 0x1000
    ctx->r5 = ADD32(ctx->r5, 0X1000);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v1, $v0, 0xC74
    ctx->r3 = ADD32(ctx->r2, 0XC74);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a1, $v0, 0x41C0
    ctx->r5 = ADD32(ctx->r2, 0X41C0);
L_80057E94:
    // sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_80057E94
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x1000
        ctx->r5 = ADD32(ctx->r5, 0X1000);
        goto L_80057E94;
    }
    // addiu       $a1, $a1, 0x1000
    ctx->r5 = ADD32(ctx->r5, 0X1000);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v1, $v0, 0xC94
    ctx->r3 = ADD32(ctx->r2, 0XC94);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a1, $v0, 0x1C0
    ctx->r5 = ADD32(ctx->r2, 0X1C0);
L_80057EC4:
    // sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_80057EC4
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x1000
        ctx->r5 = ADD32(ctx->r5, 0X1000);
        goto L_80057EC4;
    }
    // addiu       $a1, $a1, 0x1000
    ctx->r5 = ADD32(ctx->r5, 0X1000);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v1, $v0, 0xCB4
    ctx->r3 = ADD32(ctx->r2, 0XCB4);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $a1, $v0, -0x6E40
    ctx->r5 = ADD32(ctx->r2, -0X6E40);
L_80057EF4:
    // sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_80057EF4
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x1000
        ctx->r5 = ADD32(ctx->r5, 0X1000);
        goto L_80057EF4;
    }
    // addiu       $a1, $a1, 0x1000
    ctx->r5 = ADD32(ctx->r5, 0X1000);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x2E40
    ctx->r2 = ADD32(ctx->r2, -0X2E40);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v1, $v1, -0xE40
    ctx->r3 = ADD32(ctx->r3, -0XE40);
    // sw          $v1, 0x3B14($v0)
    MEM_W(0X3B14, ctx->r2) = ctx->r3;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x7E40
    ctx->r3 = ADD32(ctx->r3, -0X7E40);
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // sw          $v1, 0x3B1C($v0)
    MEM_W(0X3B1C, ctx->r2) = ctx->r3;
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);


    printf("80057DA0 end\n");
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
