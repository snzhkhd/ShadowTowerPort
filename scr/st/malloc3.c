#include "recomp.h"
#include "disable_warnings.h"

//void malloc3(uint8_t* rdram, recomp_context* ctx)
//{
//
//    uint32_t size = ctx->r4;
//    if (size == 0) {
//        ctx->r2 = 0;
//        return;
//    }
//
//    size = (size + 7) & ~7; // выравнивание на 8
//
//    if (g_heapPtr + size + 8 > g_heapEnd) {
//        printf("[malloc3] FAIL size=%d (no space)\n", size);
//        ctx->r2 = 0;
//        return;
//    }
//
//    uint32_t addr = g_heapPtr;
//    g_heapPtr += size + 8;
//
//    ctx->r2 = addr;
//}



void malloc3(uint8_t* rdram, recomp_context* ctx)
{

    uint32_t head = MEM_W(0, 0x80087C50);
    uint32_t next = MEM_W(0, head);
    uint32_t size = MEM_W(4, head);
    printf("[malloc3] req=%d head=%08X next=%08X size=%d\n",
        ctx->r4, head, next, size);

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // beq         $a0, $zero, L_800788D8
    if (ctx->r4 == 0) {
        // andi        $v0, $a0, 0x7
        ctx->r2 = ctx->r4 & 0X7;
        goto L_800788D8;
    }
    // andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // j           L_80078848
    // nop

    goto L_80078848;
    // nop

L_80078844:
    // andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
L_80078848:
    //printf("malloc3 -> L_80078844\n");
    // bne         $v0, $zero, L_80078844
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_80078844;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // addiu       $v0, $a0, 0x7
    ctx->r2 = ADD32(ctx->r4, 0X7);
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // lw          $a2, 0x7C50($a2)
    ctx->r6 = MEM_W(0X7C50, ctx->r6);
    // addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(0X0, ctx->r6);
    // nop

L_80078870:
   /* printf("malloc3 -> L_80078870\n");*/
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // nop

    // slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_800788B8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800788B8;
    }
    // nop

    // bne         $v1, $a1, L_80078898
    if (ctx->r3 != ctx->r5) {
        // subu        $v0, $v1, $a1
        ctx->r2 = SUB32(ctx->r3, ctx->r5);
        goto L_80078898;
    }
    // subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // j           L_800788A8
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    goto L_800788A8;
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80078898:
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
L_800788A8:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $a2, 0x7C50($at)
    MEM_W(0X7C50, ctx->r1) = ctx->r6;
    // j           L_800788DC
    // addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    goto L_800788DC;
    // addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
L_800788B8:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7C50($v0)
    ctx->r2 = MEM_W(0X7C50, ctx->r2);
    // nop

    // beq         $a0, $v0, L_800788D8
    if (ctx->r4 == ctx->r2) {
        // addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
        goto L_800788D8;
    }
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(0X0, ctx->r4);
    // j           L_80078870
    // nop

    goto L_80078870;
    // nop

L_800788D8:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800788DC:
    // jr          $ra
    // nop
    printf("[malloc3] result=%08X\n", ctx->r2);
    return;
    // nop

;}
