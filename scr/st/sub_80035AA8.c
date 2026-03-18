#include "recomp.h"
#include "disable_warnings.h"

void sub_80035AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // ori         $v0, $zero, 0x834C
    ctx->r2 = 0 | 0X834C;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
    // nop

    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(0X0, ctx->r4);
    // bne         $v0, $zero, L_80035B3C
    if (ctx->r2 != 0) {
        // lui         $s2, 0x1F80
        ctx->r18 = S32(0X1F80 << 16);
        goto L_80035B3C;
    }
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // beq         $s0, $zero, L_80035B08
    if (ctx->r16 == 0) {
        // nop
    
        goto L_80035B08;
    }
    // nop

    // jal         0x80035008
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80035008(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // jal         0x8003413C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003413C(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
L_80035B08:
    // nop

    // lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(0X8, ctx->r3);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    // sw          $v1, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r3;
    // sw          $v0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r2;
    // lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(0XC, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // j           L_80035B64
    // sw          $v1, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->r3;
    goto L_80035B64;
    // sw          $v1, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->r3;
L_80035B3C:
    // lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(0X6, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80035B5C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80035B5C;
    }
    // nop

    // jal         0x8003569C
    // nop

    sub_8003569C(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_80035B64
    // nop

    goto L_80035B64;
    // nop

L_80035B5C:
    // jal         0x80034364
    // nop

    sub_80034364(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_80035B64:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
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
