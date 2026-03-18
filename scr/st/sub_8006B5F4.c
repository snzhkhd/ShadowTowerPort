#include "recomp.h"
#include "disable_warnings.h"

void sub_8006B5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0xD04
    ctx->r16 = ADD32(ctx->r16, 0XD04);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(0X10, ctx->r16);
    // lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(0X8, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(0X20, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8006B6B0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006B6B0;
    }
    // nop

    // lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(0X24, ctx->r16);
    // jal         0x80068CB8
    // nop

    CdSyncCallback(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(0X28, ctx->r16);
    // jal         0x80068CCC
    // nop

    CdReadyCallback(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8006B688
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
        goto L_8006B688;
    }
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // jal         0x800690FC
    // nop

    CdDataCallback(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_8006B688:
    // jal         0x80068E1C
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    CdControlF(rdram, ctx);
    goto after_3;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD00($v0)
    ctx->r2 = MEM_W(0XD00, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8006B6B0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006B6B0;
    }
    // nop

    // lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(0X34, ctx->r16);
    // jalr        $v0
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_4;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
L_8006B6B0:
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
