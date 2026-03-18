#include "recomp.h"
#include "disable_warnings.h"

void sub_8002CD98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // addiu       $a2, $zero, 0x5C
    ctx->r6 = ADD32(0, 0X5C);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $v0, 0xD50
    ctx->r16 = ADD32(ctx->r2, 0XD50);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lhu         $a0, 0x320($s0)
    ctx->r4 = MEM_HU(0X320, ctx->r16);
    // addiu       $s1, $s0, 0xC00
    ctx->r17 = ADD32(ctx->r16, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_0;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_0:
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // lhu         $a0, 0x2E0($v1)
    ctx->r4 = MEM_HU(0X2E0, ctx->r3);
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // sb          $v0, 0x300($v1)
    MEM_B(0X300, ctx->r3) = ctx->r2;
    // sb          $v0, 0x301($v1)
    MEM_B(0X301, ctx->r3) = ctx->r2;
    // bne         $a0, $zero, L_8002CE20
    if (ctx->r4 != 0) {
        // sb          $v0, 0x302($v1)
        MEM_B(0X302, ctx->r3) = ctx->r2;
        goto L_8002CE20;
    }
    // sb          $v0, 0x302($v1)
    MEM_B(0X302, ctx->r3) = ctx->r2;
    // addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
    // addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // lhu         $a0, 0x322($s0)
    ctx->r4 = MEM_HU(0X322, ctx->r16);
    // ori         $a3, $a3, 0x308
    ctx->r7 = ctx->r7 | 0X308;
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_1;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_1:
    // addiu       $a1, $zero, 0xBD
    ctx->r5 = ADD32(0, 0XBD);
    // addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // lhu         $a0, 0x324($s0)
    ctx->r4 = MEM_HU(0X324, ctx->r16);
    // j           L_8002CE50
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    goto L_8002CE50;
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
L_8002CE20:
    // addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
    // addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // lhu         $a0, 0x322($s0)
    ctx->r4 = MEM_HU(0X322, ctx->r16);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_2;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_2:
    // addiu       $a1, $zero, 0xBD
    ctx->r5 = ADD32(0, 0XBD);
    // addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // lhu         $a0, 0x324($s0)
    ctx->r4 = MEM_HU(0X324, ctx->r16);
    // ori         $a3, $a3, 0x308
    ctx->r7 = ctx->r7 | 0X308;
L_8002CE50:
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_3:
    // addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // addiu       $a2, $zero, 0xF0
    ctx->r6 = ADD32(0, 0XF0);
    // jal         0x80029618
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    sub_80029618(rdram, ctx);
    goto after_4;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_4:
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
