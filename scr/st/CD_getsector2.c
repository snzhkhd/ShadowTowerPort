#include "recomp.h"
#include "disable_warnings.h"

void CD_getsector2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA0($v0)
    ctx->r2 = MEM_W(0XCA0, ctx->r2);
    // lui         $a2, 0x2102
    ctx->r6 = S32(0X2102 << 16);
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCAC($v1)
    ctx->r3 = MEM_W(0XCAC, ctx->r3);
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCD4($v0)
    ctx->r2 = MEM_W(0XCD4, ctx->r2);
    // ori         $a2, $a2, 0x843
    ctx->r6 = ctx->r6 | 0X843;
    // sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCB0($v1)
    ctx->r3 = MEM_W(0XCB0, ctx->r3);
    // addiu       $v0, $zero, 0x1325
    ctx->r2 = ADD32(0, 0X1325);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCD8($v1)
    ctx->r3 = MEM_W(0XCD8, ctx->r3);
    // nop

    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCDC($v0)
    ctx->r2 = MEM_W(0XCDC, ctx->r2);
    // nop

    // sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCE0($v1)
    ctx->r3 = MEM_W(0XCE0, ctx->r3);
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCA0($v1)
    ctx->r3 = MEM_W(0XCA0, ctx->r3);
    // nop

    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // bne         $v0, $zero, L_8006A908
    if (ctx->r2 != 0) {
        // addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
        goto L_8006A908;
    }
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
L_8006A8F4:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_8006A8F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006A8F4;
    }
    // nop

L_8006A908:
    // lui         $v1, 0x1140
    ctx->r3 = S32(0X1140 << 16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCE4($v0)
    ctx->r2 = MEM_W(0XCE4, ctx->r2);
    // ori         $v1, $v1, 0x100
    ctx->r3 = ctx->r3 | 0X100;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCE4($v0)
    ctx->r2 = MEM_W(0XCE4, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // jr          $ra
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
