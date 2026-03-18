#include "recomp.h"
#include "disable_warnings.h"

void sub_80078250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // bne         $v0, $zero, L_80078290
    if (ctx->r2 != 0) {
        // addu        $s5, $a2, $zero
        ctx->r21 = ADD32(ctx->r6, 0);
        goto L_80078290;
    }
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
L_80078290:
    // lw          $v1, 0x154($zero)
    ctx->r3 = MEM_W(0X154, 0);
    // lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $s0, 0x150($zero)
    ctx->r16 = MEM_W(0X150, 0);
    // lui         $s3, 0x801F
    ctx->r19 = S32(0X801F << 16);
    // lw          $s3, -0x6728($s3)
    ctx->r19 = MEM_W(-0X6728, ctx->r19);
    // mfhi        $a3
    ctx->r7 = hi;
    // srl         $v1, $a3, 6
    ctx->r3 = S32(U32(ctx->r7) >> 6);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v1, $s0, $v0
    ctx->r3 = ADD32(ctx->r16, ctx->r2);
    // sltu        $v0, $s0, $v1
    ctx->r2 = ctx->r16 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_80078314
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80078314;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_800782D4:
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80078300
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80078300;
    }
    // nop

    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // jal         0x80078A74
    // addiu       $a1, $a1, -0x6720
    ctx->r5 = ADD32(ctx->r5, -0X6720);
    strcmp_recomp(rdram, ctx);
    goto after_0;
    // addiu       $a1, $a1, -0x6720
    ctx->r5 = ADD32(ctx->r5, -0X6720);
    after_0:
    // bne         $v0, $zero, L_80078300
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80078300;
    }
    // nop

    // j           L_80078310
    // sw          $s3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r19;
    goto L_80078310;
    // sw          $s3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r19;
L_80078300:
    // addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    // sltu        $v0, $s0, $s1
    ctx->r2 = ctx->r16 < ctx->r17 ? 1 : 0;
    // bne         $v0, $zero, L_800782D4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800782D4;
    }
    // nop

L_80078310:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80078314:
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x6728($v0)
    ctx->r2 = MEM_W(-0X6728, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_1:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
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
    // jr          $ra
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
