#include "recomp.h"
#include "disable_warnings.h"

void sub_80077B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7BE0($v0)
    ctx->r2 = MEM_W(0X7BE0, ctx->r2);
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // srl         $v0, $v0, 24
    ctx->r2 = S32(U32(ctx->r2) >> 24);
    // andi        $s1, $v0, 0x7F
    ctx->r17 = ctx->r2 & 0X7F;
    // beq         $s1, $zero, L_80077C1C
    if (ctx->r17 == 0) {
        // nop
    
        goto L_80077C1C;
    }
    // nop

    // addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // lui         $s3, 0xFF
    ctx->r19 = S32(0XFF << 16);
    // ori         $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 | 0XFFFF;
    // lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // addiu       $s5, $s5, 0x7BE4
    ctx->r21 = ADD32(ctx->r21, 0X7BE4);
L_80077B94:
    // beq         $s1, $zero, L_80077BF8
    if (ctx->r17 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80077BF8;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addu        $s2, $s5, $zero
    ctx->r18 = ADD32(ctx->r21, 0);
L_80077BA0:
    // slti        $v0, $s0, 0x7
    ctx->r2 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80077BF8
    if (ctx->r2 == 0) {
        // andi        $v0, $s1, 0x1
        ctx->r2 = ctx->r17 & 0X1;
        goto L_80077BF8;
    }
    // andi        $v0, $s1, 0x1
    ctx->r2 = ctx->r17 & 0X1;
    // beq         $v0, $zero, L_80077BE8
    if (ctx->r2 == 0) {
        // addiu       $v0, $s0, 0x18
        ctx->r2 = ADD32(ctx->r16, 0X18);
        goto L_80077BE8;
    }
    // addiu       $v0, $s0, 0x18
    ctx->r2 = ADD32(ctx->r16, 0X18);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7BE0($a0)
    ctx->r4 = MEM_W(0X7BE0, ctx->r4);
    // sllv        $v0, $s4, $v0
    ctx->r2 = S32(ctx->r20) << (ctx->r2 & 31);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // beq         $v0, $zero, L_80077BE8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80077BE8;
    }
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_80077BE8:
    // addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // srl         $s1, $s1, 1
    ctx->r17 = S32(U32(ctx->r17) >> 1);
    // bne         $s1, $zero, L_80077BA0
    if (ctx->r17 != 0) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80077BA0;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80077BF8:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7BE0($v0)
    ctx->r2 = MEM_W(0X7BE0, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // srl         $v0, $v0, 24
    ctx->r2 = S32(U32(ctx->r2) >> 24);
    // andi        $s1, $v0, 0x7F
    ctx->r17 = ctx->r2 & 0X7F;
    // bne         $s1, $zero, L_80077B94
    if (ctx->r17 != 0) {
        // nop
    
        goto L_80077B94;
    }
    // nop

L_80077C1C:
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0x7BE0($a1)
    ctx->r5 = MEM_W(0X7BE0, ctx->r5);
    // nop

    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lui         $v1, 0xFF00
    ctx->r3 = S32(0XFF00 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // beq         $v0, $v1, L_80077C54
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80077C54;
    }
    // nop

    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_80077C9C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80077C9C;
    }
    // nop

L_80077C54:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3FC0
    ctx->r4 = ADD32(ctx->r4, 0X3FC0);
    // lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(0X0, ctx->r5);
    // jal         0x80078AD4
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    printf(rdram, ctx);
    goto after_1;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_1:
L_80077C68:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3FDC
    ctx->r4 = ADD32(ctx->r4, 0X3FDC);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7C04($v0)
    ctx->r2 = MEM_W(0X7C04, ctx->r2);
    // sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(0X0, ctx->r3);
    // jal         0x80078AD4
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    printf(rdram, ctx);
    goto after_2;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_2:
    // slti        $v0, $s0, 0x7
    ctx->r2 = SIGNED(ctx->r16) < 0X7 ? 1 : 0;
    // bne         $v0, $zero, L_80077C68
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80077C68;
    }
    // nop

L_80077C9C:
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
