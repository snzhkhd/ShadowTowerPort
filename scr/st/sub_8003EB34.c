#include "recomp.h"
#include "disable_warnings.h"

void sub_8003EB34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(0X8, ctx->r16);
    // jal         0x8003EBFC
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    sub_8003EBFC(rdram, ctx);
    goto after_0;
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    after_0:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s1, $v0, L_8003EBD8
    if (ctx->r17 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003EBD8;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0x248($v0)
    ctx->r3 = MEM_W(0X248, ctx->r2);
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // lw          $v0, 0x250($v0)
    ctx->r2 = MEM_W(0X250, ctx->r2);
    // lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(0X8, ctx->r16);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x8004A1B4
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    sub_8004A1B4(rdram, ctx);
    goto after_1;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_1:
    // subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    // slti        $v0, $v1, 0x801
    ctx->r2 = SIGNED(ctx->r3) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_8003EBC0
    if (ctx->r2 != 0) {
        // addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
        goto L_8003EBC0;
    }
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
L_8003EBC0:
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003EBDC
    if (ctx->r2 == 0) {
        // addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
        goto L_8003EBDC;
    }
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8003EBD8:
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_8003EBDC:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
