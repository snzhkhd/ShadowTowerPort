#include "recomp.h"
#include "disable_warnings.h"

void SetGraphQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // addiu       $s1, $s1, 0x7CC1
    ctx->r17 = ADD32(ctx->r17, 0X7CC1);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(0X1, ctx->r17);
    // lbu         $s2, 0x0($s1)
    ctx->r18 = MEM_BU(0X0, ctx->r17);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80079900
    if (ctx->r2 != 0) {
        // addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
        goto L_80079900;
    }
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x4174
    ctx->r4 = ADD32(ctx->r4, 0X4174);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7CBC($v0)
    ctx->r2 = MEM_W(0X7CBC, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
L_80079900:
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // beq         $s0, $v0, L_80079940
    if (ctx->r16 == ctx->r2) {
        // addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
        goto L_80079940;
    }
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7CB8($v0)
    ctx->r2 = MEM_W(0X7CB8, ctx->r2);
    // nop

    // lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(0X34, ctx->r2);
    // nop

    // jalr        $v0
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80077374
    // sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    DMACallback(rdram, ctx);
    goto after_2;
    // sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    after_2:
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80079940:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
