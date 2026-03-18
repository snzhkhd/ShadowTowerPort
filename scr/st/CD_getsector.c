#include "recomp.h"
#include "disable_warnings.h"

void CD_getsector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA0($v0)
    ctx->r2 = MEM_W(0XCA0, ctx->r2);
    // lui         $a2, 0x2
    ctx->r6 = S32(0X2 << 16);
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
    // ori         $a2, $a2, 0x943
    ctx->r6 = ctx->r6 | 0X943;
    // sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCB0($v1)
    ctx->r3 = MEM_W(0XCB0, ctx->r3);
    // addiu       $v0, $zero, 0x1323
    ctx->r2 = ADD32(0, 0X1323);
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

L_8006A7E0:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_8006A7E0
    if (ctx->r2 == 0) {
        // lui         $v0, 0x1100
        ctx->r2 = S32(0X1100 << 16);
        goto L_8006A7E0;
    }
    // lui         $v0, 0x1100
    ctx->r2 = S32(0X1100 << 16);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCE4($v1)
    ctx->r3 = MEM_W(0XCE4, ctx->r3);
    // nop

    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xCE4($a0)
    ctx->r4 = MEM_W(0XCE4, ctx->r4);
    // nop

    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8006A83C
    if (ctx->r2 == 0) {
        // addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
        goto L_8006A83C;
    }
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
L_8006A828:
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // bne         $v0, $zero, L_8006A828
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006A828;
    }
    // nop

L_8006A83C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCB0($v1)
    ctx->r3 = MEM_W(0XCB0, ctx->r3);
    // addiu       $v0, $zero, 0x1325
    ctx->r2 = ADD32(0, 0X1325);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // jr          $ra
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
