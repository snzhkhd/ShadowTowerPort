#include "recomp.h"
#include "disable_warnings.h"

void sub_80062C28(uint8_t* rdram, recomp_context* ctx) 
{


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x1F80
    ctx->r17 = S32(0X1F80 << 16);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // jal         0x80057A3C
    // sh          $a0, 0x206($s1)
    MEM_H(0X206, ctx->r17) = ctx->r4;
    sub_80057A3C(rdram, ctx);

    goto after_0;
    // sh          $a0, 0x206($s1)
    MEM_H(0X206, ctx->r17) = ctx->r4;
    after_0:
    // jal         0x8002CA84
    // nop

    sub_8002CA84(rdram, ctx);

    goto after_1;
    // nop

    after_1:
    // jal         0x8002CA84
    // nop

    sub_8002CA84(rdram, ctx);

    goto after_2;
    // nop

    after_2:
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
L_80062C6C:
    // jal         0x800616F8
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    sub_800616F8(rdram, ctx);

    goto after_3;
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    after_3:
    // beq         $v0, $zero, L_8006305C
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8006305C;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // jal         0x8002CA84
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    sub_8002CA84(rdram, ctx);

    goto after_4;
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    after_4:
    // jal         0x8002CA84
    // nop

    sub_8002CA84(rdram, ctx);

    goto after_5;
    // nop

    after_5:
    // lhu         $a0, 0x1F8($s1)
    ctx->r4 = MEM_HU(0X1F8, ctx->r17);
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x800613E8
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_800613E8(rdram, ctx);

    goto after_6;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_6:
    // lhu         $a0, 0x2DC($s1)
    ctx->r4 = MEM_HU(0X2DC, ctx->r17);
    // nop

    // andi        $v0, $a0, 0xFF00
    ctx->r2 = ctx->r4 & 0XFF00;
    // beq         $v0, $zero, L_80062D60
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80062D60;
    }
    // nop

    // lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(0X1F4, ctx->r17);
    // nop

    // lhu         $v1, 0xE0($v0)
    ctx->r3 = MEM_HU(0XE0, ctx->r2);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $v1, $v0, L_80062D60
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_80062D60;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    // jal         0x800615D8
    // sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    sub_800615D8(rdram, ctx);

    goto after_7;
    // sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    after_7:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // bne         $s0, $zero, L_80062CFC
    if (ctx->r16 != 0) {
        // nop
    
        goto L_80062CFC;
    }
    // nop

    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // j           L_80062C6C
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    goto L_80062C6C;
    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
L_80062CFC:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80062D14
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_80062D14;
    }
    // nop

    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // j           L_80062F9C
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    goto L_80062F9C;
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
L_80062D14:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x8002CA84
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    sub_8002CA84(rdram, ctx);

    goto after_8;
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    after_8:
    // jal         0x8002CA84
    // nop

    sub_8002CA84(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lhu         $a0, 0x1F8($s1)
    ctx->r4 = MEM_HU(0X1F8, ctx->r17);
    // nop

    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x80062BC0
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_80062BC0(rdram, ctx);
    goto after_10;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_10:
    // bne         $v0, $zero, L_80062D54
    if (ctx->r2 != 0) {
        // addiu       $v1, $zero, 0x164
        ctx->r3 = ADD32(0, 0X164);
        goto L_80062D54;
    }
    // addiu       $v1, $zero, 0x164
    ctx->r3 = ADD32(0, 0X164);
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // j           L_80062F9C
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    goto L_80062F9C;
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
L_80062D54:
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // j           L_80062D94
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    goto L_80062D94;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
L_80062D60:
    // lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(0X1F4, ctx->r17);
    // nop

    // lhu         $v1, 0xE0($v0)
    ctx->r3 = MEM_HU(0XE0, ctx->r2);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80062D88
    if (ctx->r3 != ctx->r2) {
        // addiu       $v1, $zero, 0x15E
        ctx->r3 = ADD32(0, 0X15E);
        goto L_80062D88;
    }
    // addiu       $v1, $zero, 0x15E
    ctx->r3 = ADD32(0, 0X15E);
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // j           L_80062F9C
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    goto L_80062F9C;
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
L_80062D88:
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
L_80062D94:
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    // lhu         $a0, 0x1F8($s1)
    ctx->r4 = MEM_HU(0X1F8, ctx->r17);
    // nop

    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x8006103C
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_8006103C(rdram, ctx);
    goto after_11;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_11:
    // lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(0X1F4, ctx->r17);
    // nop

    // lhu         $v1, 0xE0($v0)
    ctx->r3 = MEM_HU(0XE0, ctx->r2);
    // nop

    // beq         $v1, $zero, L_80062DEC
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_80062DEC;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_80062DDC
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x160
        ctx->r2 = ADD32(0, 0X160);
        goto L_80062DDC;
    }
    // addiu       $v0, $zero, 0x160
    ctx->r2 = ADD32(0, 0X160);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $v1, $v0, L_80062DE0
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80062DE0;
    }
    // nop

    // addiu       $v0, $zero, 0x161
    ctx->r2 = ADD32(0, 0X161);
L_80062DDC:
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_80062DE0:
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // j           L_80062F9C
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    goto L_80062F9C;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
L_80062DEC:
    // jal         0x8006184C
    // nop

    sub_8006184C(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // bne         $s0, $zero, L_80062E14
    if (ctx->r16 != 0) {
        // addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
        goto L_80062E14;
    }
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // addiu       $v1, $zero, 0x160
    ctx->r3 = ADD32(0, 0X160);
    // sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // j           L_80062F9C
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    goto L_80062F9C;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
L_80062E14:
    // bne         $s0, $s2, L_80062E28
    if (ctx->r16 != ctx->r18) {
        // nop
    
        goto L_80062E28;
    }
    // nop

    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // j           L_80062F9C
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    goto L_80062F9C;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
L_80062E28:
    // jal         0x80061A08
    // nop

    sub_80061A08(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // bne         $s0, $zero, L_80062E48
    if (ctx->r16 != 0) {
        // nop
    
        goto L_80062E48;
    }
    // nop

    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // j           L_80062C6C
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    goto L_80062C6C;
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
L_80062E48:
    // bne         $s0, $s2, L_80062E5C
    if (ctx->r16 != ctx->r18) {
        // nop
    
        goto L_80062E5C;
    }
    // nop

    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // j           L_80062F9C
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    goto L_80062F9C;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
L_80062E5C:
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // jal         0x8002CA84
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    sub_8002CA84(rdram, ctx);
    goto after_14;
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    after_14:
    // jal         0x8002CA84
    // nop

    sub_8002CA84(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lhu         $a0, 0x1F8($s1)
    ctx->r4 = MEM_HU(0X1F8, ctx->r17);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x800613E8
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_800613E8(rdram, ctx);
    goto after_16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_16:
    // lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(0X1F4, ctx->r17);
    // nop

    // lhu         $v1, 0xE0($v0)
    ctx->r3 = MEM_HU(0XE0, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80062EB8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80062EB8;
    }
    // nop

    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // addiu       $v1, $zero, 0x15F
    ctx->r3 = ADD32(0, 0X15F);
    // sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // j           L_80062F9C
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    goto L_80062F9C;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
L_80062EB8:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80062ED4
    if (ctx->r3 != ctx->r2) {
        // addiu       $v1, $zero, 0x15E
        ctx->r3 = ADD32(0, 0X15E);
        goto L_80062ED4;
    }
    // addiu       $v1, $zero, 0x15E
    ctx->r3 = ADD32(0, 0X15E);
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // j           L_80062F9C
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    goto L_80062F9C;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
L_80062ED4:
    // jal         0x800152D0
    // addiu       $a0, $zero, 0x1E06
    ctx->r4 = ADD32(0, 0X1E06);
   
    sub_800152D0(rdram, ctx);

    goto after_17;
    // addiu       $a0, $zero, 0x1E06
    ctx->r4 = ADD32(0, 0X1E06);
    after_17:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // bne         $s2, $zero, L_80062EF4
    if (ctx->r18 != 0) {
        // nop
    
        goto L_80062EF4;
    }
    // nop

    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // j           L_80062F9C
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    goto L_80062F9C;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
L_80062EF4:
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 & 0XFF00;
    // beq         $v0, $zero, L_80062F24
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80062F24;
    }
    // nop

    // lw          $a1, 0x208($s1)
    ctx->r5 = MEM_W(0X208, ctx->r17);
    // jal         0x800562D4
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_800562D4(rdram, ctx);
    goto after_18;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_18:
    // jal         0x80062228
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_80062228(rdram, ctx);
    goto after_19;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_19:
    // j           L_80062F40
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    goto L_80062F40;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_80062F24:
    // jal         0x8006205C
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_8006205C(rdram, ctx);
    goto after_20;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_20:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80062F40
    if (ctx->r16 == 0) {
        // nop
    
        goto L_80062F40;
    }
    // nop

    // jal         0x80056AA0
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_80056AA0(rdram, ctx);
    goto after_21;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_21:
L_80062F40:
    // jal         0x800152F8
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    __builtin_delete(rdram, ctx);
    goto after_22;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_22:
    // bne         $s0, $zero, L_80062F90
    if (ctx->r16 != 0) {
        // nop
    
        goto L_80062F90;
    }
    // nop

    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_HS(0X0, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80062F84
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80062F84;
    }
    // nop

    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 & 0XFF00;
    // beq         $v0, $zero, L_80062F7C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80062F7C;
    }
    // nop

    // j           L_80062F80
    // addiu       $v0, $zero, 0x163
    ctx->r2 = ADD32(0, 0X163);
    goto L_80062F80;
    // addiu       $v0, $zero, 0x163
    ctx->r2 = ADD32(0, 0X163);
L_80062F7C:
    // addiu       $v0, $zero, 0x162
    ctx->r2 = ADD32(0, 0X162);
L_80062F80:
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_80062F84:
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // j           L_80062F9C
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    goto L_80062F9C;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
L_80062F90:
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
L_80062F9C:
    // jal         0x8002CA84
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    sub_8002CA84(rdram, ctx);
    goto after_23;
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    after_23:
    // jal         0x8002CA84
    // nop

    sub_8002CA84(rdram, ctx);
    goto after_24;
    // nop

    after_24:
    // lhu         $v1, 0x2DC($s1)
    ctx->r3 = MEM_HU(0X2DC, ctx->r17);
    // nop

    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // beq         $v0, $zero, L_80062FEC
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x8000
        ctx->r2 = ctx->r3 & 0X8000;
        goto L_80062FEC;
    }
    // andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
L_80062FC4:
    // lhu         $v0, -0x2E7C($v1)
    ctx->r2 = MEM_HU(-0X2E7C, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80062FC4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80062FC4;
    }
    // nop

    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_25;
    // nop

    after_25:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // sh          $zero, -0x2E7C($v0)
    MEM_H(-0X2E7C, ctx->r2) = 0;
    // j           L_80062C6C
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    goto L_80062C6C;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80062FEC:
    // beq         $v0, $zero, L_80063020
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0xFF00
        ctx->r2 = ctx->r3 & 0XFF00;
        goto L_80063020;
    }
    // andi        $v0, $v1, 0xFF00
    ctx->r2 = ctx->r3 & 0XFF00;
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
L_80062FF8:
    // lhu         $v0, -0x2E7C($v1)
    ctx->r2 = MEM_HU(-0X2E7C, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80062FF8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80062FF8;
    }
    // nop

    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_26;
    // nop

    after_26:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // sh          $zero, -0x2E7C($v0)
    MEM_H(-0X2E7C, ctx->r2) = 0;
    // j           L_80062C6C
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    goto L_80062C6C;
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
L_80063020:
    // beq         $v0, $zero, L_80063048
    if (ctx->r2 == 0) {
        // lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
        goto L_80063048;
    }
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
L_80063028:
    // lhu         $v0, -0x2E7C($v1)
    ctx->r2 = MEM_HU(-0X2E7C, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80063028
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063028;
    }
    // nop

    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_27;
    // nop

    after_27:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // sh          $zero, -0x2E7C($v0)
    MEM_H(-0X2E7C, ctx->r2) = 0;
L_80063048:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x80057A3C
    // sb          $v0, -0x70AE($v1)
    MEM_B(-0X70AE, ctx->r3) = ctx->r2;
    sub_80057A3C(rdram, ctx);
    goto after_28;
    // sb          $v0, -0x70AE($v1)
    MEM_B(-0X70AE, ctx->r3) = ctx->r2;
    after_28:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006305C:
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
