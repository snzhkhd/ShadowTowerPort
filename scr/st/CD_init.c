#include "recomp.h"
#include "disable_warnings.h"

void CD_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3BEC
    ctx->r4 = ADD32(ctx->r4, 0X3BEC);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80078A3C
    // nop

    sub_80078A3C(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3BF8
    ctx->r4 = ADD32(ctx->r4, 0X3BF8);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // jal         0x80078AD4
    // addiu       $a1, $a1, 0xCBC
    ctx->r5 = ADD32(ctx->r5, 0XCBC);
    printf(rdram, ctx);
    goto after_1;
    // addiu       $a1, $a1, 0xCBC
    ctx->r5 = ADD32(ctx->r5, 0XCBC);
    after_1:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sb          $zero, 0x9F9($at)
    MEM_B(0X9F9, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sb          $zero, 0x9F8($at)
    MEM_B(0X9F8, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x9DC($at)
    MEM_W(0X9DC, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x9D8($at)
    MEM_W(0X9D8, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x9EC($at)
    MEM_W(0X9EC, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // jal         0x80077314
    // sw          $zero, 0x9E8($at)
    MEM_W(0X9E8, ctx->r1) = 0;
    ResetCallback(rdram, ctx);
    goto after_2;
    // sw          $zero, 0x9E8($at)
    MEM_W(0X9E8, ctx->r1) = 0;
    after_2:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x56B4
    ctx->r5 = ADD32(ctx->r5, -0X56B4);
    // jal         0x80077344
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    InterruptCallback(rdram, ctx);
    goto after_3;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCA0($v1)
    ctx->r3 = MEM_W(0XCA0, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCAC($v0)
    ctx->r2 = MEM_W(0XCAC, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // beq         $v0, $zero, L_8006A500
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_8006A500;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
L_8006A4B0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA0($v0)
    ctx->r2 = MEM_W(0XCA0, ctx->r2);
    // nop

    // sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCAC($v0)
    ctx->r2 = MEM_W(0XCAC, ctx->r2);
    // nop

    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA8($v0)
    ctx->r2 = MEM_W(0XCA8, ctx->r2);
    // nop

    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCAC($v0)
    ctx->r2 = MEM_W(0XCAC, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // bne         $v0, $zero, L_8006A4B0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006A4B0;
    }
    // nop

L_8006A500:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0xCB8
    ctx->r3 = ADD32(ctx->r3, 0XCB8);
    // sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(0X2, ctx->r3);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // lw          $a3, 0xCA0($a3)
    ctx->r7 = MEM_W(0XCA0, ctx->r7);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCAC($v0)
    ctx->r2 = MEM_W(0XCAC, ctx->r2);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCB0($v1)
    ctx->r3 = MEM_W(0XCB0, ctx->r3);
    // addiu       $v0, $zero, 0x1325
    ctx->r2 = ADD32(0, 0X1325);
    // jal         0x80069D68
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    CD_cw(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    after_4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9E8($v0)
    ctx->r2 = MEM_W(0X9E8, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8006A580
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_8006A580;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80069D68
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw(rdram, ctx);
    goto after_5;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
L_8006A580:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80069D68
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw(rdram, ctx);
    goto after_6;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // bne         $v0, $zero, L_8006A5DC
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8006A5DC;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80069D68
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    CD_cw(rdram, ctx);
    goto after_7;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
    // bne         $v0, $zero, L_8006A5D8
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8006A5D8;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80069820
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    CD_sync(rdram, ctx);
    goto after_8;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_8:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // bne         $a0, $v1, L_8006A5DC
    if (ctx->r4 != ctx->r3) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8006A5DC;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // j           L_8006A5DC
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8006A5DC;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006A5D8:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006A5DC:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
