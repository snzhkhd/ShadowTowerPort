#include "recomp.h"
#include "disable_warnings.h"

void sub_80040F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $t0, $v0, -0x70D8
    ctx->r8 = ADD32(ctx->r2, -0X70D8);
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lbu         $v1, 0x155($t1)
    ctx->r3 = MEM_BU(0X155, ctx->r9);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $v0, L_80041140
    if (ctx->r3 != ctx->r2) {
        // addu        $t3, $a0, $zero
        ctx->r11 = ADD32(ctx->r4, 0);
        goto L_80041140;
    }
    // addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // andi        $a2, $t3, 0xFF
    ctx->r6 = ctx->r11 & 0XFF;
    // beq         $a2, $v1, L_80041140
    if (ctx->r6 == ctx->r3) {
        // sll         $v0, $a2, 1
        ctx->r2 = S32(ctx->r6) << 1;
        goto L_80041140;
    }
    // sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6) << 1;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, -0x2D68
    ctx->r3 = ADD32(ctx->r3, -0X2D68);
    // addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // lhu         $a1, 0x2($t2)
    ctx->r5 = MEM_HU(0X2, ctx->r10);
    // lhu         $v1, 0x6($t0)
    ctx->r3 = MEM_HU(0X6, ctx->r8);
    // nop

    // slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_80041140
    if (ctx->r2 != 0) {
        // subu        $v0, $v1, $a1
        ctx->r2 = SUB32(ctx->r3, ctx->r5);
        goto L_80041140;
    }
    // subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // sh          $v0, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r2;
    // sltiu       $v0, $a2, 0x30
    ctx->r2 = ctx->r6 < 0X30 ? 1 : 0;
    // beq         $v0, $zero, L_800410F4
    if (ctx->r2 == 0) {
        // sb          $a0, 0x155($t1)
        MEM_B(0X155, ctx->r9) = ctx->r4;
        goto L_800410F4;
    }
    // sb          $a0, 0x155($t1)
    MEM_B(0X155, ctx->r9) = ctx->r4;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x1DFC
    ctx->r2 = ADD32(ctx->r2, 0X1DFC);
    // sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_80040F90;
    jr_addend_80040F90 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80040F90 >> 2) {
        case 0: goto L_80040F98; break;
        case 1: goto L_80041084; break;
        case 2: goto L_800410F4; break;
        case 3: goto L_8004100C; break;
        case 4: goto L_80041084; break;
        case 5: goto L_800410F4; break;
        case 6: goto L_80041084; break;
        case 7: goto L_80040FCC; break;
        case 8: goto L_800410F4; break;
        case 9: goto L_80041034; break;
        case 10: goto L_80040F98; break;
        case 11: goto L_800410F4; break;
        case 12: goto L_8004105C; break;
        case 13: goto L_80041084; break;
        case 14: goto L_800410F4; break;
        case 15: goto L_80041084; break;
        case 16: goto L_80041084; break;
        case 17: goto L_800410F4; break;
        case 18: goto L_800410F4; break;
        case 19: goto L_800410F4; break;
        case 20: goto L_800410F4; break;
        case 21: goto L_800410F4; break;
        case 22: goto L_800410F4; break;
        case 23: goto L_800410F4; break;
        case 24: goto L_800410F4; break;
        case 25: goto L_800410F4; break;
        case 26: goto L_800410F4; break;
        case 27: goto L_800410F4; break;
        case 28: goto L_800410F4; break;
        case 29: goto L_800410F4; break;
        case 30: goto L_800410F4; break;
        case 31: goto L_800410F4; break;
        case 32: goto L_800410F4; break;
        case 33: goto L_800410F4; break;
        case 34: goto L_800410F4; break;
        case 35: goto L_800410F4; break;
        case 36: goto L_800410F4; break;
        case 37: goto L_800410F4; break;
        case 38: goto L_800410F4; break;
        case 39: goto L_800410F4; break;
        case 40: goto L_800410F4; break;
        case 41: goto L_800410F4; break;
        case 42: goto L_800410F4; break;
        case 43: goto L_800410F4; break;
        case 44: goto L_800410D4; break;
        case 45: goto L_800410D4; break;
        case 46: goto L_800410D4; break;
        case 47: goto L_800410D4; break;
        default: switch_error(__func__, 0x80040F90, 0x80011DFC);
    }
    // nop

L_80040F98:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
    // addu        $a0, $v1, $a1
    ctx->r4 = ADD32(ctx->r3, ctx->r5);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sb          $v0, 0x15B($a0)
    MEM_B(0X15B, ctx->r4) = ctx->r2;
    // sb          $v0, 0x157($a0)
    MEM_B(0X157, ctx->r4) = ctx->r2;
    // sb          $v0, 0x159($a0)
    MEM_B(0X159, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // j           L_80041000
    // sh          $zero, 0x160($v1)
    MEM_H(0X160, ctx->r3) = 0;
    goto L_80041000;
    // sh          $zero, 0x160($v1)
    MEM_H(0X160, ctx->r3) = 0;
L_80040FCC:
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
    // addu        $a0, $v1, $a1
    ctx->r4 = ADD32(ctx->r3, ctx->r5);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sb          $v0, 0x15B($a0)
    MEM_B(0X15B, ctx->r4) = ctx->r2;
    // sb          $v0, 0x157($a0)
    MEM_B(0X157, ctx->r4) = ctx->r2;
    // sb          $v0, 0x159($a0)
    MEM_B(0X159, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, -0x200
    ctx->r2 = ADD32(0, -0X200);
    // sh          $v0, 0x160($v1)
    MEM_H(0X160, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, -0x400
    ctx->r2 = ADD32(0, -0X400);
L_80041000:
    // sh          $v0, 0x162($v1)
    MEM_H(0X162, ctx->r3) = ctx->r2;
    // j           L_800410F4
    // sh          $zero, 0x164($v1)
    MEM_H(0X164, ctx->r3) = 0;
    goto L_800410F4;
    // sh          $zero, 0x164($v1)
    MEM_H(0X164, ctx->r3) = 0;
L_8004100C:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // sb          $v1, 0x157($a1)
    MEM_B(0X157, ctx->r5) = ctx->r3;
    // addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // j           L_800410A4
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    goto L_800410A4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_80041034:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // sb          $v1, 0x157($a1)
    MEM_B(0X157, ctx->r5) = ctx->r3;
    // addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // j           L_800410A4
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    goto L_800410A4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_8004105C:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // sb          $v1, 0x157($a1)
    MEM_B(0X157, ctx->r5) = ctx->r3;
    // addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // j           L_800410A4
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    goto L_800410A4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_80041084:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sb          $v1, 0x157($a1)
    MEM_B(0X157, ctx->r5) = ctx->r3;
L_800410A4:
    // sb          $v1, 0x159($a1)
    MEM_B(0X159, ctx->r5) = ctx->r3;
    // addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
    // sh          $zero, 0x160($v0)
    MEM_H(0X160, ctx->r2) = 0;
    // sh          $v1, 0x162($v0)
    MEM_H(0X162, ctx->r2) = ctx->r3;
    // sh          $zero, 0x164($v0)
    MEM_H(0X164, ctx->r2) = 0;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_800410F4
    // sb          $v0, 0x15B($v1)
    MEM_B(0X15B, ctx->r3) = ctx->r2;
    goto L_800410F4;
    // sb          $v0, 0x15B($v1)
    MEM_B(0X15B, ctx->r3) = ctx->r2;
L_800410D4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x15B($v1)
    MEM_B(0X15B, ctx->r3) = ctx->r2;
    // sb          $v0, 0x157($v1)
    MEM_B(0X157, ctx->r3) = ctx->r2;
    // sb          $v0, 0x159($v1)
    MEM_B(0X159, ctx->r3) = ctx->r2;
L_800410F4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sw          $t2, 0x118($v0)
    MEM_W(0X118, ctx->r2) = ctx->r10;
    // andi        $a0, $t3, 0xFF
    ctx->r4 = ctx->r11 & 0XFF;
    // slti        $v0, $a0, 0x30
    ctx->r2 = SIGNED(ctx->r4) < 0X30 ? 1 : 0;
    // beq         $v0, $zero, L_80041124
    if (ctx->r2 == 0) {
        // slti        $v0, $a0, 0x2C
        ctx->r2 = SIGNED(ctx->r4) < 0X2C ? 1 : 0;
        goto L_80041124;
    }
    // slti        $v0, $a0, 0x2C
    ctx->r2 = SIGNED(ctx->r4) < 0X2C ? 1 : 0;
    // beq         $v0, $zero, L_80041140
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041140;
    }
    // nop

L_80041124:
    // beq         $v1, $zero, L_80041134
    if (ctx->r3 == 0) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_80041134;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // j           L_80041138
    // addiu       $a1, $a1, 0x52
    ctx->r5 = ADD32(ctx->r5, 0X52);
    goto L_80041138;
    // addiu       $a1, $a1, 0x52
    ctx->r5 = ADD32(ctx->r5, 0X52);
L_80041134:
    // addiu       $a1, $a1, 0x38
    ctx->r5 = ADD32(ctx->r5, 0X38);
L_80041138:
    // jal         0x8003D104
    // nop

    sub_8003D104(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_80041140:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
