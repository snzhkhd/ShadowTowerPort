#include "recomp.h"
#include "disable_warnings.h"

void sub_8007E4B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E24($v0)
    ctx->r2 = MEM_W(0X7E24, ctx->r2);
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
    // jalr        $v0
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(0X7E64, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8007E524
    if (ctx->r2 == 0) {
        // addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
        goto L_8007E524;
    }
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(0X3C, ctx->r17);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // bne         $v0, $v1, L_8007E524
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8007E524;
    }
    // nop

    // lbu         $v0, 0x36($s1)
    ctx->r2 = MEM_BU(0X36, ctx->r17);
    // nop

    // sltiu       $s4, $v0, 0x1
    ctx->r20 = ctx->r2 < 0X1 ? 1 : 0;
L_8007E524:
    // beq         $s4, $zero, L_8007E5C0
    if (ctx->r20 == 0) {
        // nop
    
        goto L_8007E5C0;
    }
    // nop

    // addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // addiu       $s2, $zero, -0xF0
    ctx->r18 = ADD32(0, -0XF0);
L_8007E534:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E90($v0)
    ctx->r2 = MEM_W(0X7E90, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // blez        $v0, L_8007E5C0
    if (SIGNED(ctx->r2) <= 0) {
        // sw          $v0, 0x7E90($at)
        MEM_W(0X7E90, ctx->r1) = ctx->r2;
        goto L_8007E5C0;
    }
    // sw          $v0, 0x7E90($at)
    MEM_W(0X7E90, ctx->r1) = ctx->r2;
    // bltz        $s0, L_8007E570
    if (SIGNED(ctx->r16) < 0) {
        // nop
    
        goto L_8007E570;
    }
    // nop

    // lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(0XC, ctx->r17);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E24($v0)
    ctx->r2 = MEM_W(0X7E24, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    after_1:
L_8007E570:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E20($v0)
    ctx->r2 = MEM_W(0X7E20, ctx->r2);
    // nop

    // jalr        $v0
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x8007D604
    // andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    sub_8007D604(rdram, ctx);
    goto after_3;
    // andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_3:
    // bltz        $v0, L_8007E810
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_8007E810;
    }
    // nop

    // jal         0x8007F324
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    setRC2wait(rdram, ctx);
    goto after_4;
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_4:
    // jal         0x8007D838
    // nop

    sub_8007D838(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // beq         $v0, $zero, L_8007E734
    if (ctx->r2 == 0) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8007E734;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_8007E534
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0xF0
        ctx->r18 = ADD32(ctx->r18, 0XF0);
        goto L_8007E534;
    }
    // addiu       $s2, $s2, 0xF0
    ctx->r18 = ADD32(ctx->r18, 0XF0);
L_8007E5C0:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E58($v1)
    ctx->r3 = MEM_W(0X7E58, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E90($v0)
    ctx->r2 = MEM_W(0X7E90, ctx->r2);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8007E7AC
    if (ctx->r2 != 0) {
        // sltiu       $a0, $v1, 0x1
        ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
        goto L_8007E7AC;
    }
    // sltiu       $a0, $v1, 0x1
    ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0x7E70
    ctx->r3 = ADD32(ctx->r3, 0X7E70);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4) << 4;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $s2, $v0, 4
    ctx->r18 = S32(ctx->r2) << 4;
    // addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
L_8007E600:
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // nop

    // bltz        $a0, L_8007E7AC
    if (SIGNED(ctx->r4) < 0) {
        // nop
    
        goto L_8007E7AC;
    }
    // nop

    // blez        $a0, L_8007E64C
    if (SIGNED(ctx->r4) <= 0) {
        // sll         $v0, $a0, 4
        ctx->r2 = S32(ctx->r4) << 4;
        goto L_8007E64C;
    }
    // sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4) << 4;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E4C($v1)
    ctx->r3 = MEM_W(0X7E4C, ctx->r3);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(0XC, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $s3, $v1, -0xF0
    ctx->r19 = ADD32(ctx->r3, -0XF0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E38($v0)
    ctx->r2 = MEM_W(0X7E38, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_6;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_6:
L_8007E64C:
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // nop

    // beq         $v1, $s5, L_8007E694
    if (ctx->r3 == ctx->r21) {
        // nop
    
        goto L_8007E694;
    }
    // nop

    // slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8007E680
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8007E680;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8007E6F4
    if (ctx->r2 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8007E6F4;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // bltz        $v1, L_8007E6F4
    if (SIGNED(ctx->r3) < 0) {
        // nop
    
        goto L_8007E6F4;
    }
    // nop

    // j           L_8007E6B0
    // nop

    goto L_8007E6B0;
    // nop

L_8007E680:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // bne         $v1, $v0, L_8007E6F4
    if (ctx->r3 != ctx->r2) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8007E6F4;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // j           L_8007E6F4
    // sw          $s5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r21;
    goto L_8007E6F4;
    // sw          $s5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r21;
L_8007E694:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E38($v0)
    ctx->r2 = MEM_W(0X7E38, ctx->r2);
    // nop

    // jalr        $v0
    // addiu       $a0, $s3, -0xF0
    ctx->r4 = ADD32(ctx->r19, -0XF0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_7;
    // addiu       $a0, $s3, -0xF0
    ctx->r4 = ADD32(ctx->r19, -0XF0);
    after_7:
    // j           L_8007E6EC
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_8007E6EC;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007E6B0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E4C($v0)
    ctx->r2 = MEM_W(0X7E4C, ctx->r2);
    // nop

    // addu        $s3, $v0, $s2
    ctx->r19 = ADD32(ctx->r2, ctx->r18);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E38($v0)
    ctx->r2 = MEM_W(0X7E38, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_8;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_8:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E3C($v0)
    ctx->r2 = MEM_W(0X7E3C, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_9;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_9:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007E6EC:
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8007E6F4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E20($v0)
    ctx->r2 = MEM_W(0X7E20, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_10;
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_10:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x8007D42C
    // andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    sub_8007D42C(rdram, ctx);
    goto after_11;
    // andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_11:
    // bltz        $v0, L_8007E810
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_8007E810;
    }
    // nop

    // jal         0x8007F324
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    setRC2wait(rdram, ctx);
    goto after_12;
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_12:
    // jal         0x8007D838
    // nop

    sub_8007D838(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // bne         $v0, $zero, L_8007E73C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007E73C;
    }
    // nop

L_8007E734:
    // j           L_8007E810
    // addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    goto L_8007E810;
    // addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
L_8007E73C:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E90($v0)
    ctx->r2 = MEM_W(0X7E90, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E90($at)
    MEM_W(0X7E90, ctx->r1) = ctx->r2;
    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8007E600
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007E600;
    }
    // nop

    // j           L_8007E7AC
    // nop

    goto L_8007E7AC;
    // nop

L_8007E768:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E20($v0)
    ctx->r2 = MEM_W(0X7E20, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_14;
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_14:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x8007D42C
    // andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    sub_8007D42C(rdram, ctx);
    goto after_15;
    // andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_15:
    // bltz        $v0, L_8007E810
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_8007E810;
    }
    // nop

    // jal         0x8007F324
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    setRC2wait(rdram, ctx);
    goto after_16;
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_16:
    // jal         0x8007D838
    // nop

    sub_8007D838(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // beq         $v0, $zero, L_8007E810
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
        goto L_8007E810;
    }
    // addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
L_8007E7AC:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E90($v0)
    ctx->r2 = MEM_W(0X7E90, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // bgtz        $v0, L_8007E768
    if (SIGNED(ctx->r2) > 0) {
        // sw          $v0, 0x7E90($at)
        MEM_W(0X7E90, ctx->r1) = ctx->r2;
        goto L_8007E768;
    }
    // sw          $v0, 0x7E90($at)
    MEM_W(0X7E90, ctx->r1) = ctx->r2;
    // jal         0x8007D8C8
    // nop

    sub_8007D8C8(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // lbu         $v1, 0x44($s1)
    ctx->r3 = MEM_BU(0X44, ctx->r17);
    // nop

    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sb          $v0, 0x44($s1)
    MEM_B(0X44, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E94($v0)
    ctx->r2 = MEM_W(0X7E94, ctx->r2);
    // lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(0X3C, ctx->r17);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E18($v0)
    ctx->r2 = MEM_W(0X7E18, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_19;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_19:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007E810:
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
