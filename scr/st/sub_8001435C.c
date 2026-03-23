#include "recomp.h"
#include "disable_warnings.h"



void sub_8001435C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x80014354
    // nop

    nullsub_1(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // ori         $a1, $a1, 0xDFF8
    ctx->r5 = ctx->r5 | 0XDFF8;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // lw          $v0, 0x3988($v0)
    ctx->r2 = MEM_W(0X3988, ctx->r2);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // lw          $a0, 0x3980($a0)
    ctx->r4 = MEM_W(0X3980, ctx->r4);
    // addiu       $v1, $zero, -0x800
    ctx->r3 = ADD32(0, -0X800);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // addiu       $v0, $v0, 0x7FF
    ctx->r2 = ADD32(ctx->r2, 0X7FF);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // sw          $a0, 0x398C($at)
    MEM_W(0X398C, ctx->r1) = ctx->r4;
    // jal         0x800787D4
    // subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    InitHeap3(rdram, ctx);
    printf("[HEAP-CHECK-1] val=%08X\n", MEM_W(0, 0x801EFD60));
    goto after_1;
    // subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    after_1:
L_800143A8:
    // jal         0x80068A34
    // nop

    sub_80068A34(rdram, ctx);
    printf("[HEAP-CHECK-2] val=%08X\n", MEM_W(0, 0x801EFD60));
    goto after_2;
    // nop

    after_2:
    // bne         $v0, $zero, L_800143C8
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_800143C8;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80068C78
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    CdSync(rdram, ctx);


    goto after_3;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_3:
    // j           L_800143A8
    // nop

    goto L_800143A8;
    // nop

L_800143C8:
    // jal         0x80068BFC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdSetDebug(rdram, ctx);


    goto after_4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // jal         0x800686E4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    InitCARD(rdram, ctx);


    goto after_5;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_5:
    // jal         0x80068750
    // nop

    StartCARD(rdram, ctx);


    goto after_6;
    // nop

    after_6:
    // jal         0x80068654
    // nop

    _bu_init(rdram, ctx);

    goto after_7;
    // nop

    after_7:
    // jal         0x80057684
    // nop

    sub_80057684(rdram, ctx);

 
    goto after_8;
    // nop

    after_8:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);


    goto after_9;
    // nop

    after_9:
    // jal         0x80014A30
    // nop

    ST_MainGameLoop(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
