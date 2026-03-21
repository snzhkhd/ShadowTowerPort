#include "recomp.h"
#include "disable_warnings.h"

void sub_80057428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x80077104
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
   // VSync(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s0, $v0, -0x2E80
    ctx->r16 = ADD32(ctx->r2, -0X2E80);
    // addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_8005745C:
    // jal         0x8007C910
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    PadGetState_0(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // sb          $v0, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(0X15, ctx->r16);
    // nop

    // beq         $v0, $s3, L_800574A0
    if (ctx->r2 == ctx->r19) {
        // nop
    
        goto L_800574A0;
    }
    // nop

    // lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(0X15, ctx->r16);
    // nop

    // beq         $v0, $s2, L_800574A0
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_800574A0;
    }
    // nop

    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    VSync(rdram, ctx);
    goto after_2;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_2:
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // slti        $v0, $v0, 0x3C
    ctx->r2 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // bne         $v0, $zero, L_8005745C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005745C;
    }
    // nop

L_800574A0:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
