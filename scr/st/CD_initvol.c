#include "recomp.h"
#include "disable_warnings.h"

void CD_initvol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCB4($v1)
    ctx->r3 = MEM_W(0XCB4, ctx->r3);
    // nop

    // lhu         $v0, 0x1B8($v1)
    ctx->r2 = MEM_HU(0X1B8, ctx->r3);
    // nop

    // bne         $v0, $zero, L_8006A30C
    if (ctx->r2 != 0) {
        // addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
        goto L_8006A30C;
    }
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // lhu         $v0, 0x1BA($v1)
    ctx->r2 = MEM_HU(0X1BA, ctx->r3);
    // nop

    // bne         $v0, $zero, L_8006A310
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x3FFF
        ctx->r2 = ADD32(0, 0X3FFF);
        goto L_8006A310;
    }
    // addiu       $v0, $zero, 0x3FFF
    ctx->r2 = ADD32(0, 0X3FFF);
    // sh          $v0, 0x180($v1)
    MEM_H(0X180, ctx->r3) = ctx->r2;
    // sh          $v0, 0x182($v1)
    MEM_H(0X182, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCB4($v1)
    ctx->r3 = MEM_W(0XCB4, ctx->r3);
L_8006A30C:
    // addiu       $v0, $zero, 0x3FFF
    ctx->r2 = ADD32(0, 0X3FFF);
L_8006A310:
    // sh          $v0, 0x1B0($v1)
    MEM_H(0X1B0, ctx->r3) = ctx->r2;
    // sh          $v0, 0x1B2($v1)
    MEM_H(0X1B2, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0xC001
    ctx->r2 = 0 | 0XC001;
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCA0($v1)
    ctx->r3 = MEM_W(0XCA0, ctx->r3);
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r2;
    // sb          $v0, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $zero, 0x3($sp)
    MEM_B(0X3, ctx->r29) = 0;
    // sb          $zero, 0x1($sp)
    MEM_B(0X1, ctx->r29) = 0;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCA8($v1)
    ctx->r3 = MEM_W(0XCA8, ctx->r3);
    // lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(0X0, ctx->r29);
    // nop

    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCAC($v1)
    ctx->r3 = MEM_W(0XCAC, ctx->r3);
    // lbu         $v0, 0x1($sp)
    ctx->r2 = MEM_BU(0X1, ctx->r29);
    // nop

    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCA0($v1)
    ctx->r3 = MEM_W(0XCA0, ctx->r3);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCA4($v1)
    ctx->r3 = MEM_W(0XCA4, ctx->r3);
    // lbu         $v0, 0x2($sp)
    ctx->r2 = MEM_BU(0X2, ctx->r29);
    // nop

    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCA8($v1)
    ctx->r3 = MEM_W(0XCA8, ctx->r3);
    // lbu         $v0, 0x3($sp)
    ctx->r2 = MEM_BU(0X3, ctx->r29);
    // nop

    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCAC($v1)
    ctx->r3 = MEM_W(0XCAC, ctx->r3);
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // jr          $ra
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
