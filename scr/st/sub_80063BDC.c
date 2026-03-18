#include "recomp.h"
#include "disable_warnings.h"

void sub_80063BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addiu       $s2, $s0, -0x70D8
    ctx->r18 = ADD32(ctx->r16, -0X70D8);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x1F80
    ctx->r17 = S32(0X1F80 << 16);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // lhu         $v1, 0x6($s2)
    ctx->r3 = MEM_HU(0X6, ctx->r18);
    // lw          $s3, 0x0($s1)
    ctx->r19 = MEM_W(0X0, ctx->r17);
    // lw          $s4, 0x4($s1)
    ctx->r20 = MEM_W(0X4, ctx->r17);
    // lhu         $s5, 0x8($s1)
    ctx->r21 = MEM_HU(0X8, ctx->r17);
    // lhu         $s6, 0xA($s1)
    ctx->r22 = MEM_HU(0XA, ctx->r17);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sh          $v0, 0x2D8($s1)
    MEM_H(0X2D8, ctx->r17) = ctx->r2;
    // jal         0x8005A3A8
    // sh          $v1, 0x2DA($s1)
    MEM_H(0X2DA, ctx->r17) = ctx->r3;
    sub_8005A3A8(rdram, ctx);
    goto after_0;
    // sh          $v1, 0x2DA($s1)
    MEM_H(0X2DA, ctx->r17) = ctx->r3;
    after_0:
    // lhu         $v0, 0x2D8($s1)
    ctx->r2 = MEM_HU(0X2D8, ctx->r17);
    // lhu         $v1, -0x70D8($s0)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80063C54
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063C54;
    }
    // nop

    // sh          $v1, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r3;
L_80063C54:
    // lhu         $v0, 0x2DA($s1)
    ctx->r2 = MEM_HU(0X2DA, ctx->r17);
    // lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(0X4, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80063C74
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063C74;
    }
    // nop

    // sh          $v1, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r3;
L_80063C74:
    // sw          $s3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r19;
    // sw          $s4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r20;
    // sh          $s5, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r21;
    // sh          $s6, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r22;
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
