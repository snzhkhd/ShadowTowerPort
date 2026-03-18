#include "recomp.h"
#include "disable_warnings.h"

void firstfile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lb          $v0, 0x0($s2)
    ctx->r2 = MEM_BS(0X0, ctx->r18);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x6720
    ctx->r4 = ADD32(ctx->r4, -0X6720);
    // slti        $v0, $v0, 0x3B
    ctx->r2 = SIGNED(ctx->r2) < 0X3B ? 1 : 0;
    // bne         $v0, $zero, L_8007810C
    if (ctx->r2 != 0) {
        // addu        $v1, $s2, $zero
        ctx->r3 = ADD32(ctx->r18, 0);
        goto L_8007810C;
    }
    // addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
L_800780EC:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // lb          $v0, 0x0($v1)
    ctx->r2 = MEM_BS(0X0, ctx->r3);
    // nop

    // slti        $v0, $v0, 0x3B
    ctx->r2 = SIGNED(ctx->r2) < 0X3B ? 1 : 0;
    // beq         $v0, $zero, L_800780EC
    if (ctx->r2 == 0) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800780EC;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8007810C:
    // sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
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
    // mfhi        $a2
    ctx->r6 = hi;
    // srl         $v1, $a2, 6
    ctx->r3 = S32(U32(ctx->r6) >> 6);
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
    // beq         $v0, $zero, L_80078180
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80078180;
    }
    // nop

    // addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_8007814C:
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80078170
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80078170;
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
    // beq         $v0, $zero, L_80078194
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80078194;
    }
    // nop

L_80078170:
    // addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    // sltu        $v0, $s0, $s1
    ctx->r2 = ctx->r16 < ctx->r17 ? 1 : 0;
    // bne         $v0, $zero, L_8007814C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007814C;
    }
    // nop

L_80078180:
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80078184:
    // bne         $v1, $zero, L_800781B8
    if (ctx->r3 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800781B8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_80078234
    // nop

    goto L_80078234;
    // nop

L_80078194:
    // lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(0X34, ctx->r16);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v0, -0x6728($at)
    MEM_W(-0X6728, ctx->r1) = ctx->r2;
    // j           L_80078184
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    goto L_80078184;
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800781A8:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x7DB0
    ctx->r2 = ADD32(ctx->r2, -0X7DB0);
    // j           L_80078228
    // sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    goto L_80078228;
    // sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
L_800781B8:
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
    // mfhi        $a2
    ctx->r6 = hi;
    // srl         $v1, $a2, 6
    ctx->r3 = S32(U32(ctx->r6) >> 6);
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
    // beq         $v0, $zero, L_8007822C
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8007822C;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_800781F4:
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80078218
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80078218;
    }
    // nop

    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // jal         0x80078A74
    // addiu       $a1, $a1, -0x6720
    ctx->r5 = ADD32(ctx->r5, -0X6720);
    strcmp_recomp(rdram, ctx);
    goto after_1;
    // addiu       $a1, $a1, -0x6720
    ctx->r5 = ADD32(ctx->r5, -0X6720);
    after_1:
    // beq         $v0, $zero, L_800781A8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800781A8;
    }
    // nop

L_80078218:
    // addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    // sltu        $v0, $s0, $s1
    ctx->r2 = ctx->r16 < ctx->r17 ? 1 : 0;
    // bne         $v0, $zero, L_800781F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800781F4;
    }
    // nop

L_80078228:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8007822C:
    // jal         0x80078354
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    firstfile2(rdram, ctx);
    goto after_2;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_2:
L_80078234:
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
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
