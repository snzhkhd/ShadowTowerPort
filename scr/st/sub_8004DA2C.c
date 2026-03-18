#include "recomp.h"
#include "disable_warnings.h"

void sub_8004DA2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x80078AC4
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    rand_recomp(rdram, ctx);
    goto after_0;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lhu         $a0, 0x10($s0)
    ctx->r4 = MEM_HU(0X10, ctx->r16);
    // jal         0x80052D40
    // sra         $s1, $v1, 15
    ctx->r17 = S32(ctx->r3) >> 15;
    sub_80052D40(rdram, ctx);
    goto after_1;
    // sra         $s1, $v1, 15
    ctx->r17 = S32(ctx->r3) >> 15;
    after_1:
    // beq         $v0, $zero, L_8004DA8C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004DA8C;
    }
    // nop

    // lbu         $v0, 0x65($s0)
    ctx->r2 = MEM_BU(0X65, ctx->r16);
    // nop

    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004DA8C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004DA8C;
    }
    // nop

    // lhu         $a1, 0x10($s0)
    ctx->r5 = MEM_HU(0X10, ctx->r16);
    // j           L_8004DAEC
    // nop

    goto L_8004DAEC;
    // nop

L_8004DA8C:
    // lhu         $a0, 0x12($s0)
    ctx->r4 = MEM_HU(0X12, ctx->r16);
    // jal         0x80052D40
    // nop

    sub_80052D40(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // beq         $v0, $zero, L_8004DAC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004DAC0;
    }
    // nop

    // lbu         $v0, 0x66($s0)
    ctx->r2 = MEM_BU(0X66, ctx->r16);
    // nop

    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004DAC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004DAC0;
    }
    // nop

    // lhu         $a1, 0x12($s0)
    ctx->r5 = MEM_HU(0X12, ctx->r16);
    // j           L_8004DAEC
    // nop

    goto L_8004DAEC;
    // nop

L_8004DAC0:
    // lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(0X14, ctx->r16);
    // jal         0x80052D40
    // nop

    sub_80052D40(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // beq         $v0, $zero, L_8004DAF4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004DAF4;
    }
    // nop

    // lbu         $v0, 0x67($s0)
    ctx->r2 = MEM_BU(0X67, ctx->r16);
    // nop

    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004DAF4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004DAF4;
    }
    // nop

    // lhu         $a1, 0x14($s0)
    ctx->r5 = MEM_HU(0X14, ctx->r16);
L_8004DAEC:
    // jal         0x8004D804
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8004D804(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
L_8004DAF4:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
