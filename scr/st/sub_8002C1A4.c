#include "recomp.h"
#include "disable_warnings.h"

void sub_8002C1A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // nop

    // bne         $v0, $zero, L_8002C25C
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, 0x20
        ctx->r5 = ADD32(0, 0X20);
        goto L_8002C25C;
    }
    // addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // addiu       $a2, $zero, 0x4A
    ctx->r6 = ADD32(0, 0X4A);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s0, $v0, 0xD50
    ctx->r16 = ADD32(ctx->r2, 0XD50);
    // lhu         $a0, 0x26E($s0)
    ctx->r4 = MEM_HU(0X26E, ctx->r16);
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
    // lhu         $v0, 0x202($s2)
    ctx->r2 = MEM_HU(0X202, ctx->r18);
    // nop

    // beq         $v0, $zero, L_8002C22C
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x79
        ctx->r5 = ADD32(0, 0X79);
        goto L_8002C22C;
    }
    // addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
    // addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lhu         $a0, 0x28A($s0)
    ctx->r4 = MEM_HU(0X28A, ctx->r16);
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
    // addiu       $a1, $zero, 0xBF
    ctx->r5 = ADD32(0, 0XBF);
    // addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // lhu         $a0, 0x28C($s0)
    ctx->r4 = MEM_HU(0X28C, ctx->r16);
    // j           L_8002C290
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    goto L_8002C290;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
L_8002C22C:
    // addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // lhu         $a0, 0x28A($s0)
    ctx->r4 = MEM_HU(0X28A, ctx->r16);
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
    // addiu       $a1, $zero, 0xBF
    ctx->r5 = ADD32(0, 0XBF);
    // addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // lhu         $a0, 0x28C($s0)
    ctx->r4 = MEM_HU(0X28C, ctx->r16);
    // j           L_8002C294
    // ori         $a3, $a3, 0x308
    ctx->r7 = ctx->r7 | 0X308;
    goto L_8002C294;
    // ori         $a3, $a3, 0x308
    ctx->r7 = ctx->r7 | 0X308;
L_8002C25C:
    // addiu       $a2, $zero, 0x4A
    ctx->r6 = ADD32(0, 0X4A);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // addiu       $s0, $s0, 0xD50
    ctx->r16 = ADD32(ctx->r16, 0XD50);
    // lhu         $a0, 0x270($s0)
    ctx->r4 = MEM_HU(0X270, ctx->r16);
    // addiu       $s1, $s0, 0xC00
    ctx->r17 = ADD32(ctx->r16, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_3:
    // addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // lhu         $a0, 0x298($s0)
    ctx->r4 = MEM_HU(0X298, ctx->r16);
L_8002C290:
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
L_8002C294:
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_4;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_4:
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
