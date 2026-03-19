#include "recomp.h"
#include "disable_warnings.h"

void sub_8003C95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // jal         0x80015AD4
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
L_8003C990:
    // jal         0x8001531C
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x800456F8
    // nop

    sub_800456F8(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lh          $v0, 0x5920($s0)
    ctx->r2 = MEM_HS(0X5920, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8003C990
    if (ctx->r2 != 0) {
        // andi        $a0, $s1, 0xFF
        ctx->r4 = ctx->r17 & 0XFF;
        goto L_8003C990;
    }
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    // andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    // addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // addiu       $v1, $s0, 0x5920
    ctx->r3 = ADD32(ctx->r16, 0X5920);
    // addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // sb          $v0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r2;
    // sb          $v0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r2;
    // sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // jal         0x80045044
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    sub_80045044(rdram, ctx);
    goto after_3;
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_3:
L_8003CA04:
    // jal         0x8001531C
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x800456F8
    // nop

    sub_800456F8(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lh          $v0, 0x5920($s0)
    ctx->r2 = MEM_HS(0X5920, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8003CA04
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003CA04;
    }
    // nop

    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // jal         0x80077104
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    VSync(rdram, ctx);
    goto after_7;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // jal         0x8003EAF8
    // nop

    sub_8003EAF8(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // jal         0x80032058
    // nop

    sub_80032058(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // jal         0x80016508
    // nop

    sub_80016508(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // jal         0x8003216C
    // nop

    sub_8003216C(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x800500AC
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_800500AC(rdram, ctx);
    goto after_12;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_12:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // lbu         $v0, 0x58($sp)
    ctx->r2 = MEM_BU(0X58, ctx->r29);
    // andi        $a3, $s4, 0xFF
    ctx->r7 = ctx->r20 & 0XFF;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lw          $v1, -0x7DFC($v0)
    ctx->r3 = MEM_W(-0X7DFC, ctx->r2);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // jal         0x80045044
    // sw          $v1, 0x5938($v0)
    MEM_W(0X5938, ctx->r2) = ctx->r3;
    sub_80045044(rdram, ctx);
    goto after_14;
    // sw          $v1, 0x5938($v0)
    MEM_W(0X5938, ctx->r2) = ctx->r3;
    after_14:
    // jal         0x800330F0
    // nop

    sub_800330F0(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
