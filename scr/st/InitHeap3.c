#include "recomp.h"
#include "disable_warnings.h"
//void KF_InitHeap3(uint8_t* rdram, recomp_context* ctx);
//
//void __InitHeap3(uint8_t* rdram, recomp_context* ctx)
//{
//    g_heapBase = ctx->r4;
//    uint32_t size = ctx->r5;
//    g_heapPtr = g_heapBase + 8; // skip header
//    g_heapEnd = g_heapBase + size;
//
//    printf("[InitHeap3] base=%08X size=%d end=%08X\n",
//        g_heapBase, size, g_heapEnd);
//
//    // Вызываем оригинал
//    KF_InitHeap3(rdram, ctx);
//}

void InitHeap3(uint8_t* rdram, recomp_context* ctx) 
{
    // Force heap past CD buffer conflict zone
    uint32_t safeBase = 0x801F0000;
    uint32_t safeEnd = 0x801FDFF8;  // same end as before
    if (ctx->r4 < safeBase) {
        printf("[InitHeap3] Moving base %08X -> %08X\n", ctx->r4, safeBase);
        ctx->r4 = safeBase;
        ctx->r5 = safeEnd - safeBase;
    }

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // beq         $a0, $zero, L_8007882C
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8007882C;
    }
    // nop

    // beq         $a1, $zero, L_8007882C
    if (ctx->r5 == 0) {
        // andi        $v0, $a1, 0x7
        ctx->r2 = ctx->r5 & 0X7;
        goto L_8007882C;
    }
    // andi        $v0, $a1, 0x7
    ctx->r2 = ctx->r5 & 0X7;
    // beq         $v0, $zero, L_80078804
    if (ctx->r2 == 0) {
        // addu        $v0, $a0, $a1
        ctx->r2 = ADD32(ctx->r4, ctx->r5);
        goto L_80078804;
    }
    // addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_800787F0:
    // andi        $v0, $a1, 0x7
    ctx->r2 = ctx->r5 & 0X7;
    // bne         $v0, $zero, L_800787F0
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
        goto L_800787F0;
    }
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
L_80078804:
    // sw          $a0, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r4;
    // addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // addiu       $v0, $a1, 0x7
    ctx->r2 = ADD32(ctx->r5, 0X7);
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $a0, 0x7C50($at)
    MEM_W(0X7C50, ctx->r1) = ctx->r4;
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8007882C:
    // jr          $ra
    // nop


    return;
    // nop

;}
