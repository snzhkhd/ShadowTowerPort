#include "recomp.h"
#include "disable_warnings.h"

void ST_InitEventSystem(uint8_t* rdram, recomp_context* ctx) 
{
    printf("ST_InitEventSystem \n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x80077E94
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    EnterCriticalSection(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $a0, 0xF200
    ctx->r4 = S32(0XF200 << 16);
    // ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    // lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // jal         0x80077E04
    // addiu       $a3, $a3, 0x53B4
    ctx->r7 = ADD32(ctx->r7, 0X53B4);
    OpenEvent(rdram, ctx);
    goto after_1;
    // addiu       $a3, $a3, 0x53B4
    ctx->r7 = ADD32(ctx->r7, 0X53B4);
    after_1:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // sw          $a0, -0x7E00($s0)
    MEM_W(-0X7E00, ctx->r16) = ctx->r4;
    // jal         0x80077E44
    // addiu       $s0, $s0, -0x7E00
    ctx->r16 = ADD32(ctx->r16, -0X7E00);
    EnableEvent(rdram, ctx);
    goto after_2;
    // addiu       $s0, $s0, -0x7E00
    ctx->r16 = ADD32(ctx->r16, -0X7E00);
    after_2:
    // lui         $a0, 0xF200
    ctx->r4 = S32(0XF200 << 16);
    // ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // ori         $a1, $zero, 0xEA60
    ctx->r5 = 0 | 0XEA60;
    // jal         0x80077F44
    // addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    SetRCnt(rdram, ctx);
    goto after_3;
    // addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    after_3:
    // lui         $a0, 0xF200
    ctx->r4 = S32(0XF200 << 16);
    // jal         0x80078018
    // ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    StartRCnt(rdram, ctx);
    goto after_4;
    // ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    after_4:
    // addiu       $v1, $s0, 0x14
    ctx->r3 = ADD32(ctx->r16, 0X14);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_800163EC:
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // slti        $v0, $a0, 0x30
    ctx->r2 = SIGNED(ctx->r4) < 0X30 ? 1 : 0;
    // bne         $v0, $zero, L_800163EC
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x34
        ctx->r3 = ADD32(ctx->r3, 0X34);
        goto L_800163EC;
    }
    // addiu       $v1, $v1, 0x34
    ctx->r3 = ADD32(ctx->r3, 0X34);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x7E00
    ctx->r2 = ADD32(ctx->r2, -0X7E00);
    // addiu       $v1, $v0, 0x14
    ctx->r3 = ADD32(ctx->r2, 0X14);
    // sw          $v1, 0x9D4($v0)
    MEM_W(0X9D4, ctx->r2) = ctx->r3;
    // jal         0x80068CB8
    // sw          $v1, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r3;
    CdSyncCallback(rdram, ctx);
    goto after_5;
    // sw          $v1, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r3;
    after_5:
    // jal         0x80068CCC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdReadyCallback(rdram, ctx);
    goto after_6;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_6:
    // jal         0x8006BB0C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8006BB0C(rdram, ctx);
    goto after_7;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_7:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // jal         0x8001624C
    // nop

    sub_8001624C(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
