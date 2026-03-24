#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libspu.h"


void SpuSetTransferStartAddr(uint8_t* rdram, recomp_context* ctx) 
{

    uint32_t addr = ctx->r4;
    // Выравниваем на 8 байт
    if (addr % 8) addr = (addr + 8) & ~7;
    g_spu_transfer_addr = addr;
    SpuSetTransferStartAddr(addr);

    printf("[SpuSetTransferStartAddr] SetTransferAddr=%08X\n", addr);

    ctx->r2 = ctx->r4;
    return;


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x7
    ctx->r2 = S32(0X7 << 16);
    // ori         $v0, $v0, 0xEFE8
    ctx->r2 = ctx->r2 | 0XEFE8;
    // addiu       $v1, $a1, -0x1010
    ctx->r3 = ADD32(ctx->r5, -0X1010);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8007423C
    if (ctx->r2 != 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_8007423C;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x8006C5F4
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    _spu_FsetRXXa(rdram, ctx);
    goto after_0;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_0:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v0, 0xD58($at)
    MEM_H(0XD58, ctx->r1) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, 0xD58($v1)
    ctx->r3 = MEM_HU(0XD58, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD68($v0)
    ctx->r2 = MEM_W(0XD68, ctx->r2);
    // j           L_80074240
    // sllv        $v0, $v1, $v0
    ctx->r2 = S32(ctx->r3) << (ctx->r2 & 31);
    goto L_80074240;
    // sllv        $v0, $v1, $v0
    ctx->r2 = S32(ctx->r3) << (ctx->r2 & 31);
L_8007423C:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80074240:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
