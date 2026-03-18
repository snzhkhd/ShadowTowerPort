#include "recomp.h"
#include "disable_warnings.h"

void SpuIsTransferCompleted(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xDB0($v0)
    ctx->r2 = MEM_W(0XDB0, ctx->r2);
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // beq         $v0, $s0, L_8007437C
    if (ctx->r2 == ctx->r16) {
        // sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
        goto L_8007437C;
    }
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD74($v0)
    ctx->r2 = MEM_W(0XD74, ctx->r2);
    // nop

    // bne         $v0, $s0, L_80074384
    if (ctx->r2 != ctx->r16) {
        // nop
    
        goto L_80074384;
    }
    // nop

L_8007437C:
    // j           L_800743D4
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_800743D4;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074384:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xDA8($a0)
    ctx->r4 = MEM_W(0XDA8, ctx->r4);
    // jal         0x80077E34
    // nop

    TestEvent(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // bne         $s1, $s0, L_800743C4
    if (ctx->r17 != ctx->r16) {
        // nop
    
        goto L_800743C4;
    }
    // nop

    // bne         $v0, $zero, L_800743CC
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800743CC;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800743A4:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xDA8($a0)
    ctx->r4 = MEM_W(0XDA8, ctx->r4);
    // jal         0x80077E34
    // nop

    TestEvent(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // beq         $v0, $zero, L_800743A4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800743A4;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_800743CC
    // nop

    goto L_800743CC;
    // nop

L_800743C4:
    // bne         $v0, $s0, L_800743D4
    if (ctx->r2 != ctx->r16) {
        // nop
    
        goto L_800743D4;
    }
    // nop

L_800743CC:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xD74($at)
    MEM_W(0XD74, ctx->r1) = ctx->r2;
L_800743D4:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
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
