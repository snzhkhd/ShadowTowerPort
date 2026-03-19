#include "recomp.h"
#include "disable_warnings.h"

void sub_8002D0B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x800174C4
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    ST_BeginDraw2D(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sb          $v0, 0x300($s0)
    MEM_B(0X300, ctx->r16) = ctx->r2;
    // sb          $v0, 0x301($s0)
    MEM_B(0X301, ctx->r16) = ctx->r2;
    // sb          $v0, 0x302($s0)
    MEM_B(0X302, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // sb          $v0, 0x308($s0)
    MEM_B(0X308, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    // sb          $v0, 0x309($s0)
    MEM_B(0X309, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sb          $v0, 0x30A($s0)
    MEM_B(0X30A, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // sb          $v0, 0x30B($s0)
    MEM_B(0X30B, ctx->r16) = ctx->r2;
    // sb          $v0, 0x303($s0)
    MEM_B(0X303, ctx->r16) = ctx->r2;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s1, $v0, 0xD50
    ctx->r17 = ADD32(ctx->r2, 0XD50);
    // lhu         $a0, 0x6A4($s1)
    ctx->r4 = MEM_HU(0X6A4, ctx->r17);
    // addiu       $s2, $s1, 0xC00
    ctx->r18 = ADD32(ctx->r17, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    sub_8002732C(rdram, ctx);
    goto after_1;
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    after_1:
    // lhu         $v0, 0x2DE($s0)
    ctx->r2 = MEM_HU(0X2DE, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8002D168
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, 0x7F
        ctx->r5 = ADD32(0, 0X7F);
        goto L_8002D168;
    }
    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lhu         $a0, 0x6A6($s1)
    ctx->r4 = MEM_HU(0X6A6, ctx->r17);
    // ori         $a3, $a3, 0x308
    ctx->r7 = ctx->r7 | 0X308;
    // jal         0x8002732C
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    sub_8002732C(rdram, ctx);
    goto after_2;
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    after_2:
    // addiu       $a1, $zero, 0xB7
    ctx->r5 = ADD32(0, 0XB7);
    // addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lhu         $a0, 0x6A8($s1)
    ctx->r4 = MEM_HU(0X6A8, ctx->r17);
    // j           L_8002D194
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    goto L_8002D194;
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
L_8002D168:
    // addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // lhu         $a0, 0x6A6($s1)
    ctx->r4 = MEM_HU(0X6A6, ctx->r17);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // jal         0x8002732C
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    sub_8002732C(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    after_3:
    // addiu       $a1, $zero, 0xB7
    ctx->r5 = ADD32(0, 0XB7);
    // addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // lhu         $a0, 0x6A8($s1)
    ctx->r4 = MEM_HU(0X6A8, ctx->r17);
    // ori         $a3, $a3, 0x308
    ctx->r7 = ctx->r7 | 0X308;
L_8002D194:
    // jal         0x8002732C
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    sub_8002732C(rdram, ctx);
    goto after_4;
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    after_4:
    // addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // jal         0x80029618
    // addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    sub_80029618(rdram, ctx);
    goto after_5;
    // addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    after_5:
    // jal         0x800175A4
    // nop

    sub_800175A4(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // jal         0x80017634
    // nop

    sub_80017634(rdram, ctx);
    goto after_7;
    // nop

    after_7:
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
