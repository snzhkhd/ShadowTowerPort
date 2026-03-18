#include "recomp.h"
#include "disable_warnings.h"

void sub_800767F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lhu         $t4, 0xC($a1)
    ctx->r12 = MEM_HU(0XC, ctx->r5);
    // lhu         $t5, 0x8($t0)
    ctx->r13 = MEM_HU(0X8, ctx->r8);
    // sll         $t4, $t4, 16
    ctx->r12 = S32(ctx->r12) << 16;
    // addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // lhu         $t4, 0xE($a1)
    ctx->r12 = MEM_HU(0XE, ctx->r5);
    // lhu         $t6, 0x8($t1)
    ctx->r14 = MEM_HU(0X8, ctx->r9);
    // sll         $t4, $t4, 16
    ctx->r12 = S32(ctx->r12) << 16;
    // addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // lhu         $t7, 0x8($t2)
    ctx->r15 = MEM_HU(0X8, ctx->r10);
    // lhu         $t8, 0x8($t3)
    ctx->r24 = MEM_HU(0X8, ctx->r11);
    // lw          $t4, 0x10($a1)
    ctx->r12 = MEM_W(0X10, ctx->r5);
    // sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
    // sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // lw          $t4, 0x10($t0)
    ctx->r12 = MEM_W(0X10, ctx->r8);
    // lw          $t5, 0x10($t1)
    ctx->r13 = MEM_W(0X10, ctx->r9);
    // lw          $t6, 0x10($t2)
    ctx->r14 = MEM_W(0X10, ctx->r10);
    // lw          $t7, 0x10($t3)
    ctx->r15 = MEM_W(0X10, ctx->r11);
    // sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    // sw          $t5, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r13;
    // sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // lw          $t4, 0x14($a1)
    ctx->r12 = MEM_W(0X14, ctx->r5);
    // sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4) << 8;
    // srl         $t9, $t9, 8
    ctx->r25 = S32(U32(ctx->r25) >> 8);
    // lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(0X0, ctx->r12);
    // sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // lui         $t6, 0x900
    ctx->r14 = S32(0X900 << 16);
    // or          $t8, $t8, $t6
    ctx->r24 = ctx->r24 | ctx->r14;
    // sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
