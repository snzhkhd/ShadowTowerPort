#include "recomp.h"
#include "disable_warnings.h"

void CD_flush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
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
    // beq         $v0, $zero, L_8006A280
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_8006A280;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
L_8006A230:
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
    // bne         $v0, $zero, L_8006A230
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006A230;
    }
    // nop

L_8006A280:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0xCB8
    ctx->r3 = ADD32(ctx->r3, 0XCB8);
    // sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(0X2, ctx->r3);
    // nop

    // sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xCA0($a0)
    ctx->r4 = MEM_W(0XCA0, ctx->r4);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCAC($v0)
    ctx->r2 = MEM_W(0XCAC, ctx->r2);
    // nop

    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCB0($v1)
    ctx->r3 = MEM_W(0XCB0, ctx->r3);
    // addiu       $v0, $zero, 0x1325
    ctx->r2 = ADD32(0, 0X1325);
    // jr          $ra
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    return;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
;}
