#include "recomp.h"
#include "disable_warnings.h"

void CdReadWithRetry(uint8_t* rdram, recomp_context* ctx)
{
    // CdReadWithRetry(a0=sectorCount, a1=destBuffer, a2=mode)
    uint32_t sectorCount = ctx->r4;
    uint32_t destBuffer = ctx->r5;
    uint32_t mode = ctx->r6;

 /*   printf("[CdReadWithRetry] sectors=%d dest=%08X mode=%08X sector=%d\n",
        sectorCount, destBuffer, mode, g_cdCurrentSector);*/

    uint8_t* dest = (uint8_t*)GET_PTR(destBuffer);

    if (g_cdImage && dest && sectorCount > 0 && sectorCount < 10000) {
        for (uint32_t i = 0; i < sectorCount; i++) {
            fseek(g_cdImage, (g_cdCurrentSector + i) * 2352 + 24, SEEK_SET);
            fread(dest + i * 2048, 1, 2048, g_cdImage);
        }
        g_cdCurrentSector += sectorCount;
    }

    // Успех
    ctx->r2 = 1;
}

void _CdReadWithRetry(uint8_t* rdram, recomp_context* ctx) 
{
    printf("[CdReadWithRetry] ENTER\n");


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, 0xD04
    ctx->r4 = ADD32(ctx->r4, 0XD04);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $a2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r6;
    // lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(0XC, ctx->r4);
    // nop

    // andi        $v1, $v0, 0x30
    ctx->r3 = ctx->r2 & 0X30;
    // beq         $v1, $zero, L_8006B984
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
        goto L_8006B984;
    }
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // beq         $v1, $v0, L_8006B990
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x246
        ctx->r2 = ADD32(0, 0X246);
        goto L_8006B990;
    }
    // addiu       $v0, $zero, 0x246
    ctx->r2 = ADD32(0, 0X246);
    // j           L_8006B99C
    // nop

    goto L_8006B99C;
    // nop

L_8006B984:
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // j           L_8006B9A8
    // sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    goto L_8006B9A8;
    // sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
L_8006B990:
    // addiu       $v0, $zero, 0x249
    ctx->r2 = ADD32(0, 0X249);
    // j           L_8006B9A8
    // sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    goto L_8006B9A8;
    // sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
L_8006B99C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0xD04
    ctx->r3 = ADD32(ctx->r3, 0XD04);
    // sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
L_8006B9A8:
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0xD04
    ctx->r16 = ADD32(ctx->r16, 0XD04);
    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
    // jal         0x80068CB8
    // sw          $a3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r7;
    CdSyncCallback(rdram, ctx);
    goto after_0;
    // sw          $a3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r7;
    after_0:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80068CCC
    // sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    CdReadyCallback(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    after_1:
    // sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8006B9FC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006B9FC;
    }
    // nop

    // jal         0x800690FC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdDataCallback(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
L_8006B9FC:
    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    VSync(rdram, ctx);
    goto after_3;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_3:
    // sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // jal         0x80068B34
    // nop

    CdStatus(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // andi        $v0, $v0, 0xE0
    ctx->r2 = ctx->r2 & 0XE0;
    // beq         $v0, $zero, L_8006BA28
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
        goto L_8006BA28;
    }
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80068F50
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControlB(rdram, ctx);
    goto after_5;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_5:
L_8006BA28:
    // jal         0x8006B6C0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8006B6C0(rdram, ctx);
    goto after_6;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_6:
    // slt         $v0, $zero, $v0
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
