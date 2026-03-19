#include "recomp.h"
#include "disable_warnings.h"

void sub_80021158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // lui         $s1, 0x1
    ctx->r17 = S32(0X1 << 16);
    // ori         $s1, $s1, 0x8000
    ctx->r17 = ctx->r17 | 0X8000;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r31;
    // sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x7EF4
    ctx->r6 = ADD32(ctx->r2, 0X7EF4);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x4B($sp)
    do_swl(rdram, 0X4B, ctx->r29, ctx->r3);
    // swr         $v1, 0x48($sp)
    do_swr(rdram, 0X48, ctx->r29, ctx->r3);
    // swl         $a0, 0x4F($sp)
    do_swl(rdram, 0X4F, ctx->r29, ctx->r4);
    // swr         $a0, 0x4C($sp)
    do_swr(rdram, 0X4C, ctx->r29, ctx->r4);
    // lui         $s2, 0xFF
    ctx->r18 = S32(0XFF << 16);
    // ori         $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 | 0XFFFF;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // addu        $s1, $s3, $s1
    ctx->r17 = ADD32(ctx->r19, ctx->r17);
    // sb          $zero, 0x18($s3)
    MEM_B(0X18, ctx->r19) = 0;
    // sb          $zero, 0x74($s3)
    MEM_B(0X74, ctx->r19) = 0;
    // lbu         $v1, 0x6CC2($s1)
    ctx->r3 = MEM_BU(0X6CC2, ctx->r17);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6CC4($s1)
    MEM_B(0X6CC4, ctx->r17) = ctx->r2;
    // sb          $v0, 0x73($s3)
    MEM_B(0X73, ctx->r19) = ctx->r2;
    // sb          $v0, 0x17($s3)
    MEM_B(0X17, ctx->r19) = ctx->r2;
    // sb          $zero, 0x74($s3)
    MEM_B(0X74, ctx->r19) = 0;
    // sb          $zero, 0x18($s3)
    MEM_B(0X18, ctx->r19) = 0;
    // sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3) << 1;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x8007A0C4
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    PutDrawEnv(rdram, ctx);
    goto after_0;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_0:
    // lbu         $v0, 0x6CC2($s1)
    ctx->r2 = MEM_BU(0X6CC2, ctx->r17);
    // addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x8007A0C4
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    PutDrawEnv(rdram, ctx);
    goto after_1;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_1:
    // addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // jal         0x80079F4C
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    ClearOTagR(rdram, ctx);
    goto after_2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // sb          $v0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r2;
    // lui         $v0, 0x500
    ctx->r2 = S32(0X500 << 16);
    // lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(0X50, ctx->r29);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    // sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
    // lbu         $v1, 0x6CC2($s1)
    ctx->r3 = MEM_BU(0X6CC2, ctx->r17);
    // and         $a2, $a2, $s2
    ctx->r6 = ctx->r6 & ctx->r18;
    // or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // subu        $v1, $s0, $v1
    ctx->r3 = SUB32(ctx->r16, ctx->r3);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(0X4, ctx->r2);
    // lbu         $v1, 0x6CC2($s1)
    ctx->r3 = MEM_BU(0X6CC2, ctx->r17);
    // addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // sh          $zero, 0x30($sp)
    MEM_H(0X30, ctx->r29) = 0;
    // subu        $v1, $s0, $v1
    ctx->r3 = SUB32(ctx->r16, ctx->r3);
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // lbu         $v1, 0x6CC2($s1)
    ctx->r3 = MEM_BU(0X6CC2, ctx->r17);
    // lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(0X6, ctx->r2);
    // subu        $v1, $s0, $v1
    ctx->r3 = SUB32(ctx->r16, ctx->r3);
    // sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(0X4, ctx->r2);
    // lbu         $t0, 0x6CC2($s1)
    ctx->r8 = MEM_BU(0X6CC2, ctx->r17);
    // and         $v1, $v1, $s2
    ctx->r3 = ctx->r3 & ctx->r18;
    // sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // subu        $s0, $s0, $t0
    ctx->r16 = SUB32(ctx->r16, ctx->r8);
    // sh          $v0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r2;
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(0X6, ctx->r2);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // sb          $v0, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r2;
    // sb          $v0, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r2;
    // sb          $v0, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r2;
    // jal         0x8007C704
    // sh          $v1, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r3;
    GetTPage(rdram, ctx);
    goto after_3;
    // sh          $v1, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r3;
    after_3:
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    // jal         0x8007A934
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sub_8007A934(rdram, ctx);
    goto after_4;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $s1, $v0, -0x7394
    ctx->r17 = ADD32(ctx->r2, -0X7394);
    // addiu       $s5, $s1, -0xA6C
    ctx->r21 = ADD32(ctx->r17, -0XA6C);
    // lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // and         $s0, $s0, $s2
    ctx->r16 = ctx->r16 & ctx->r18;
    // lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(0X38, ctx->r29);
    // lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(0X50, ctx->r29);
    // and         $a0, $a0, $a1
    ctx->r4 = ctx->r4 & ctx->r5;
    // and         $v0, $v1, $s2
    ctx->r2 = ctx->r3 & ctx->r18;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // or          $v1, $v1, $s0
    ctx->r3 = ctx->r3 | ctx->r16;
    // sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
L_80021388:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_5;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_5:
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // lw          $a0, 0xA70($s5)
    ctx->r4 = MEM_W(0XA70, ctx->r21);
    // lw          $a1, 0xE0($s3)
    ctx->r5 = MEM_W(0XE0, ctx->r19);
    // addiu       $a0, $a0, 0x7FF
    ctx->r4 = ADD32(ctx->r4, 0X7FF);
    // jal         0x8006B944
    // srl         $a0, $a0, 11
    ctx->r4 = S32(U32(ctx->r4) >> 11);
    CdReadWithRetry(rdram, ctx);
    goto after_6;
    // srl         $a0, $a0, 11
    ctx->r4 = S32(U32(ctx->r4) >> 11);
    after_6:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800213B4:
    // jal         0x8006BA44
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    CdCheckStatus(rdram, ctx);
    goto after_7;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_7:
    // blez        $v0, L_800213DC
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_800213DC;
    }
    // nop

    // jal         0x80077104
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    VSync(rdram, ctx);
    goto after_8;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_8:
    // jal         0x8007A054
    // addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    DrawOTag(rdram, ctx);
    goto after_9;
    // addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_9:
    // j           L_800213B4
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    goto L_800213B4;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800213DC:
    // beq         $v0, $zero, L_800213F4
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x48
        ctx->r4 = ADD32(ctx->r29, 0X48);
        goto L_800213F4;
    }
    // addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // slti        $v0, $s4, 0x32
    ctx->r2 = SIGNED(ctx->r20) < 0X32 ? 1 : 0;
    // bne         $v0, $zero, L_80021388
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80021388;
    }
    // nop

L_800213F4:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    ClearImage(rdram, ctx);
    goto after_10;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_10:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_11;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_11:
    // jal         0x800173A8
    // nop

    sub_800173A8(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // lw          $a0, -0x2E90($v0)
    ctx->r4 = MEM_W(-0X2E90, ctx->r2);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lw          $a1, -0x7390($v0)
    ctx->r5 = MEM_W(-0X7390, ctx->r2);
    // jal         0x80031EFC
    // nop

    sub_80031EFC(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7EFC
    ctx->r6 = ADD32(ctx->r2, 0X7EFC);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x5B($sp)
    do_swl(rdram, 0X5B, ctx->r29, ctx->r3);
    // swr         $v1, 0x58($sp)
    do_swr(rdram, 0X58, ctx->r29, ctx->r3);
    // swl         $a0, 0x5F($sp)
    do_swl(rdram, 0X5F, ctx->r29, ctx->r4);
    // swr         $a0, 0x5C($sp)
    do_swr(rdram, 0X5C, ctx->r29, ctx->r4);
    // jal         0x80077104
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    VSync(rdram, ctx);
    goto after_14;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_14:
    // addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80079DCC
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    MoveImage(rdram, ctx);
    goto after_15;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_15:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_16;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_16:
    // jal         0x800799C8
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    SetDispMask(rdram, ctx);
    goto after_17;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // lw          $ra, 0x78($sp)
    ctx->r31 = MEM_W(0X78, ctx->r29);
    // lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(0X74, ctx->r29);
    // lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(0X70, ctx->r29);
    // lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(0X6C, ctx->r29);
    // lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(0X68, ctx->r29);
    // lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(0X64, ctx->r29);
    // lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(0X60, ctx->r29);
    // addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // jr          $ra
    // nop

    return;
    // nop

;}
