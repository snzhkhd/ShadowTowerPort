#include "recomp.h"
#include "disable_warnings.h"

void sub_8007D150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E7C($v1)
    ctx->r3 = MEM_W(0X7E7C, ctx->r3);
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sh          $v0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x88
    ctx->r2 = ADD32(0, 0X88);
    // sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
    // lbu         $v1, 0xE8($s0)
    ctx->r3 = MEM_BU(0XE8, ctx->r16);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // bne         $v1, $v0, L_8007D19C
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $zero, 0x91
        ctx->r4 = ADD32(0, 0X91);
        goto L_8007D19C;
    }
    // addiu       $a0, $zero, 0x91
    ctx->r4 = ADD32(0, 0X91);
    // addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
L_8007D19C:
    // jal         0x8007F324
    // nop

    setRC2wait(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E58($v0)
    ctx->r2 = MEM_W(0X7E58, ctx->r2);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7E7C($a0)
    ctx->r4 = MEM_W(0X7E7C, ctx->r4);
    // beq         $v0, $zero, L_8007D1C0
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0x1003
        ctx->r3 = ADD32(0, 0X1003);
        goto L_8007D1C0;
    }
    // addiu       $v1, $zero, 0x1003
    ctx->r3 = ADD32(0, 0X1003);
    // addiu       $v1, $zero, 0x3003
    ctx->r3 = ADD32(0, 0X3003);
L_8007D1C0:
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sh          $v1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x7E70($at)
    ctx->r2 = MEM_W(0X7E70, ctx->r1);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // bltz        $v0, L_8007D2AC
    if (SIGNED(ctx->r2) < 0) {
        // addiu       $v1, $v1, 0x7E70
        ctx->r3 = ADD32(ctx->r3, 0X7E70);
        goto L_8007D2AC;
    }
    // addiu       $v1, $v1, 0x7E70
    ctx->r3 = ADD32(ctx->r3, 0X7E70);
    // blez        $v0, L_8007D258
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8007D258;
    }
    // nop

    // addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_8007D1EC:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E58($v1)
    ctx->r3 = MEM_W(0X7E58, ctx->r3);
    // nop

    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2) << 4;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E38($v1)
    ctx->r3 = MEM_W(0X7E38, ctx->r3);
    // nop

    // jalr        $v1
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
    goto after_1;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_1:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E58($v0)
    ctx->r2 = MEM_W(0X7E58, ctx->r2);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // bgtz        $v0, L_8007D1EC
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8007D1EC;
    }
    // nop

L_8007D258:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E58($v0)
    ctx->r2 = MEM_W(0X7E58, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0x7E70
    ctx->r3 = ADD32(ctx->r3, 0X7E70);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // bne         $v0, $zero, L_8007D2AC
    if (ctx->r2 != 0) {
        // addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
        goto L_8007D2AC;
    }
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E38($v0)
    ctx->r2 = MEM_W(0X7E38, ctx->r2);
    // nop

    // jalr        $v0
    // sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    after_2:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E3C($v0)
    ctx->r2 = MEM_W(0X7E3C, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_8007D2AC:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E7C($v1)
    ctx->r3 = MEM_W(0X7E7C, ctx->r3);
    // nop

    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // beq         $v0, $zero, L_8007D324
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D324;
    }
    // nop

    // lhu         $v0, 0xA($v1)
    ctx->r2 = MEM_HU(0XA, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // sh          $v0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // beq         $v0, $zero, L_8007D314
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007D314;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // jal         0x8007D8C8
    // nop

    sub_8007D8C8(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E7C($v1)
    ctx->r3 = MEM_W(0X7E7C, ctx->r3);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(0X0, ctx->r3);
    // j           L_8007D350
    // nop

    goto L_8007D350;
    // nop

L_8007D314:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E78($v1)
    ctx->r3 = MEM_W(0X7E78, ctx->r3);
    // addiu       $v0, $zero, -0x81
    ctx->r2 = ADD32(0, -0X81);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8007D324:
    // lbu         $v0, 0x50($s0)
    ctx->r2 = MEM_BU(0X50, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8007D344
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D344;
    }
    // nop

    // lbu         $v0, 0x36($s0)
    ctx->r2 = MEM_BU(0X36, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8007D350
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007D350;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007D344:
    // lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(0X3C, ctx->r16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8007D350:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
