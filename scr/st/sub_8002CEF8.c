#include "recomp.h"
#include "disable_warnings.h"

void sub_8002CEF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // jal         0x800174C4
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    ST_BeginDraw2D(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    after_0:
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sb          $v0, 0x300($s2)
    MEM_B(0X300, ctx->r18) = ctx->r2;
    // sb          $v0, 0x301($s2)
    MEM_B(0X301, ctx->r18) = ctx->r2;
    // sb          $v0, 0x302($s2)
    MEM_B(0X302, ctx->r18) = ctx->r2;
    // lbu         $v0, 0x2E4($s2)
    ctx->r2 = MEM_BU(0X2E4, ctx->r18);
    // addiu       $v1, $zero, 0x31
    ctx->r3 = ADD32(0, 0X31);
    // sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8002CF58
    if (ctx->r2 == 0) {
        // sb          $v1, 0x303($s2)
        MEM_B(0X303, ctx->r18) = ctx->r3;
        goto L_8002CF58;
    }
    // sb          $v1, 0x303($s2)
    MEM_B(0X303, ctx->r18) = ctx->r3;
    // lbu         $v1, 0x2E4($s2)
    ctx->r3 = MEM_BU(0X2E4, ctx->r18);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // j           L_8002CF64
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_8002CF64;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8002CF58:
    // lbu         $v0, 0x2E4($s2)
    ctx->r2 = MEM_BU(0X2E4, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
L_8002CF64:
    // sh          $v0, 0x360($s2)
    MEM_H(0X360, ctx->r18) = ctx->r2;
    // ori         $a0, $s2, 0x330
    ctx->r4 = ctx->r18 | 0X330;
    // ori         $a1, $s2, 0x32C
    ctx->r5 = ctx->r18 | 0X32C;
    // addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // addiu       $v0, $zero, 0x5D
    ctx->r2 = ADD32(0, 0X5D);
    // sh          $v0, 0x330($s2)
    MEM_H(0X330, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x86
    ctx->r2 = ADD32(0, 0X86);
    // sh          $v0, 0x334($s2)
    MEM_H(0X334, ctx->r18) = ctx->r2;
    // lbu         $v0, 0x360($s2)
    ctx->r2 = MEM_BU(0X360, ctx->r18);
    // addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // sh          $v1, 0x336($s2)
    MEM_H(0X336, ctx->r18) = ctx->r3;
    // lbu         $v1, 0x360($s2)
    ctx->r3 = MEM_BU(0X360, ctx->r18);
    // lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(0X0, ctx->r18);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // sb          $zero, 0x32E($s2)
    MEM_B(0X32E, ctx->r18) = 0;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // sb          $v0, 0x32C($s2)
    MEM_B(0X32C, ctx->r18) = ctx->r2;
    // sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8) << 1;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addiu       $v0, $v0, 0x76
    ctx->r2 = ADD32(ctx->r2, 0X76);
    // sb          $v1, 0x32D($s2)
    MEM_B(0X32D, ctx->r18) = ctx->r3;
    // jal         0x80027D18
    // sh          $v0, 0x332($s2)
    MEM_H(0X332, ctx->r18) = ctx->r2;
    sub_80027D18(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x332($s2)
    MEM_H(0X332, ctx->r18) = ctx->r2;
    after_1:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_2;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_2:
    // addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // addiu       $s2, $s2, 0x300
    ctx->r18 = ADD32(ctx->r18, 0X300);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // addiu       $s0, $s0, 0xD50
    ctx->r16 = ADD32(ctx->r16, 0XD50);
    // addiu       $s1, $s0, 0xC00
    ctx->r17 = ADD32(ctx->r16, 0XC00);
    // lhu         $a0, 0x640($s0)
    ctx->r4 = MEM_HU(0X640, ctx->r16);
    // lhu         $a1, 0x10($sp)
    ctx->r5 = MEM_HU(0X10, ctx->r29);
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // addiu       $a1, $a1, 0x61
    ctx->r5 = ADD32(ctx->r5, 0X61);
    // jal         0x8002732C
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_3;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_3:
    // addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lhu         $a0, 0x642($s0)
    ctx->r4 = MEM_HU(0X642, ctx->r16);
    // lhu         $a1, 0x12($sp)
    ctx->r5 = MEM_HU(0X12, ctx->r29);
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // addiu       $a1, $a1, 0x61
    ctx->r5 = ADD32(ctx->r5, 0X61);
    // jal         0x8002732C
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_4;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
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
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x6CC2($v0)
    ctx->r2 = MEM_BU(0X6CC2, ctx->r2);
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x80079BE4
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    ClearImage(rdram, ctx);
    goto after_7;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    after_7:
    // jal         0x80017634
    // nop

    sub_80017634(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
