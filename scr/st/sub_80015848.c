#include "recomp.h"
#include "disable_warnings.h"

void NextCdTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // addiu       $s0, $s0, 0x34
    ctx->r16 = ADD32(ctx->r16, 0X34);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x742C
    ctx->r2 = ADD32(ctx->r2, -0X742C);
    // bne         $s0, $v0, L_80015878
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_80015878;
    }
    // nop

    // addiu       $s0, $s0, -0x9C0
    ctx->r16 = ADD32(ctx->r16, -0X9C0);
L_80015878:
    // sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_800158C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800158C0;
    }
    // nop

    // jal         0x80068CCC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdReadyCallback(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80068CB8
    // addiu       $a0, $a0, 0x561C
    ctx->r4 = ADD32(ctx->r4, 0X561C);
    CdSyncCallback(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, 0x561C
    ctx->r4 = ADD32(ctx->r4, 0X561C);
    after_1:
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_800158A4:
    // addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_2;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // beq         $v0, $zero, L_800158A4
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
        goto L_800158A4;
    }
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // j           L_800158E0
    // nop

    goto L_800158E0;
    // nop

L_800158C0:
    // jal         0x80068CCC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdReadyCallback(rdram, ctx);
    goto after_3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // jal         0x80068CB8
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdSyncCallback(rdram, ctx);
    goto after_4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80068CE0
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    CdControl(rdram, ctx);
    goto after_5;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_5:
L_800158E0:
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
