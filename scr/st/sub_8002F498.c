#include "recomp.h"
#include "disable_warnings.h"

void sub_8002F498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x98
    ctx->r2 = ADD32(0, 0X98);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F70
    ctx->r6 = ADD32(ctx->r2, 0X7F70);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // swl         $a0, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r4);
    // swr         $a0, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F78
    ctx->r6 = ADD32(ctx->r2, 0X7F78);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r3);
    // swr         $v1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r3);
    // swl         $a0, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r4);
    // swr         $a0, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r4);
    // addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0x32C
    ctx->r5 = ctx->r5 | 0X32C;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $s1, 0x1F80
    ctx->r17 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sb          $v0, 0x318($s1)
    MEM_B(0X318, ctx->r17) = ctx->r2;
    // sb          $v0, 0x308($s1)
    MEM_B(0X308, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sb          $v0, 0x31A($s1)
    MEM_B(0X31A, ctx->r17) = ctx->r2;
    // sb          $v0, 0x30A($s1)
    MEM_B(0X30A, ctx->r17) = ctx->r2;
    // sb          $v0, 0x319($s1)
    MEM_B(0X319, ctx->r17) = ctx->r2;
    // sb          $v0, 0x309($s1)
    MEM_B(0X309, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
    // sb          $v0, 0x30B($s1)
    MEM_B(0X30B, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    // jal         0x8002916C
    // sb          $v0, 0x31B($s1)
    MEM_B(0X31B, ctx->r17) = ctx->r2;
    sub_8002916C(rdram, ctx);
    goto after_0;
    // sb          $v0, 0x31B($s1)
    MEM_B(0X31B, ctx->r17) = ctx->r2;
    after_0:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // ori         $a1, $a1, 0x32C
    ctx->r5 = ctx->r5 | 0X32C;
    // jal         0x8002916C
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    sub_8002916C(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
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
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a0, $a0, 0x350
    ctx->r4 = ctx->r4 | 0X350;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // sh          $v0, 0x350($s1)
    MEM_H(0X350, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // sh          $v0, 0x352($s1)
    MEM_H(0X352, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0xC0
    ctx->r2 = ADD32(0, 0XC0);
    // sh          $v0, 0x354($s1)
    MEM_H(0X354, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x7C
    ctx->r2 = ADD32(0, 0X7C);
    // sh          $v0, 0x356($s1)
    MEM_H(0X356, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    // sh          $v0, 0x358($s1)
    MEM_H(0X358, ctx->r17) = ctx->r2;
    // sh          $zero, 0x35A($s1)
    MEM_H(0X35A, ctx->r17) = 0;
    // jal         0x80028364
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80028364(rdram, ctx);
    goto after_3;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a0, $a0, 0x350
    ctx->r4 = ctx->r4 | 0X350;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0xCC
    ctx->r2 = ADD32(0, 0XCC);
    // sh          $v0, 0x350($s1)
    MEM_H(0X350, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // sh          $v0, 0x354($s1)
    MEM_H(0X354, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x340
    ctx->r2 = ADD32(0, 0X340);
    // sh          $v0, 0x358($s1)
    MEM_H(0X358, ctx->r17) = ctx->r2;
    // jal         0x80028364
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80028364(rdram, ctx);
    goto after_4;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // lhu         $v0, 0x2BE($s1)
    ctx->r2 = MEM_HU(0X2BE, ctx->r17);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // beq         $v0, $v1, L_8002F960
    if (ctx->r2 == ctx->r3) {
        // addiu       $a1, $zero, 0xE
        ctx->r5 = ADD32(0, 0XE);
        goto L_8002F960;
    }
    // addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // lbu         $v1, 0x303($s1)
    ctx->r3 = MEM_BU(0X303, ctx->r17);
    // lhu         $v0, 0x2C0($s1)
    ctx->r2 = MEM_HU(0X2C0, ctx->r17);
    // ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sb          $v1, 0x303($s1)
    MEM_B(0X303, ctx->r17) = ctx->r3;
    // lw          $v1, 0x2CC($s1)
    ctx->r3 = MEM_W(0X2CC, ctx->r17);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_5;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_5:
    // lui         $v1, 0xF
    ctx->r3 = S32(0XF << 16);
    // ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // ori         $a2, $a2, 0x4
    ctx->r6 = ctx->r6 | 0X4;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // lbu         $v0, 0x303($s1)
    ctx->r2 = MEM_BU(0X303, ctx->r17);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // jal         0x8002F1F8
    // sb          $v0, 0x303($s1)
    MEM_B(0X303, ctx->r17) = ctx->r2;
    sub_8002F1F8(rdram, ctx);
    goto after_6;
    // sb          $v0, 0x303($s1)
    MEM_B(0X303, ctx->r17) = ctx->r2;
    after_6:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lhu         $v1, 0x2C0($s1)
    ctx->r3 = MEM_HU(0X2C0, ctx->r17);
    // addiu       $s2, $v0, 0x76F8
    ctx->r18 = ADD32(ctx->r2, 0X76F8);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a1, $v0, $s2
    ctx->r5 = ADD32(ctx->r2, ctx->r18);
    // lhu         $v0, 0x13C($a1)
    ctx->r2 = MEM_HU(0X13C, ctx->r5);
    // nop

    // beq         $v0, $zero, L_8002F7E4
    if (ctx->r2 == 0) {
        // lui         $a0, 0x2416
        ctx->r4 = S32(0X2416 << 16);
        goto L_8002F7E4;
    }
    // lui         $a0, 0x2416
    ctx->r4 = S32(0X2416 << 16);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // ori         $a0, $a0, 0x8E19
    ctx->r4 = ctx->r4 | 0X8E19;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) << 5;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // mfhi        $t0
    ctx->r8 = hi;
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addiu       $a1, $zero, 0xBC
    ctx->r5 = ADD32(0, 0XBC);
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a2, $zero, 0xD9
    ctx->r6 = ADD32(0, 0XD9);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x38($a0)
    ctx->r2 = MEM_HU(0X38, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // sra         $v0, $t0, 6
    ctx->r2 = S32(ctx->r8) >> 6;
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E62($at)
    MEM_H(-0X7E62, ctx->r1) = ctx->r2;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v0, $t2, 6
    ctx->r2 = S32(ctx->r10) >> 6;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E78($at)
    MEM_H(-0X7E78, ctx->r1) = ctx->r2;
    // jal         0x8002732C
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    sub_8002732C(rdram, ctx);
    goto after_7;
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    after_7:
    // addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // addiu       $a2, $zero, 0xD9
    ctx->r6 = ADD32(0, 0XD9);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // ori         $a3, $a3, 0x310
    ctx->r7 = ctx->r7 | 0X310;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $v0, -0x7E62($v0)
    ctx->r2 = MEM_HU(-0X7E62, ctx->r2);
    // lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    sub_80027440(rdram, ctx);
    goto after_8;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    after_8:
    // addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // addiu       $a1, $zero, 0x108
    ctx->r5 = ADD32(0, 0X108);
    // addiu       $a2, $zero, 0xD9
    ctx->r6 = ADD32(0, 0XD9);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // jal         0x80026ECC
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    sub_80026ECC(rdram, ctx);
    goto after_9;
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    after_9:
    // addiu       $a1, $zero, 0x110
    ctx->r5 = ADD32(0, 0X110);
    // addiu       $a2, $zero, 0xD9
    ctx->r6 = ADD32(0, 0XD9);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // ori         $a3, $a3, 0x310
    ctx->r7 = ctx->r7 | 0X310;
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E62($v1)
    ctx->r3 = MEM_HU(-0X7E62, ctx->r3);
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E78($a0)
    ctx->r4 = MEM_HU(-0X7E78, ctx->r4);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    sub_80027440(rdram, ctx);
    goto after_10;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    after_10:
    // addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // addiu       $a1, $zero, 0x11F
    ctx->r5 = ADD32(0, 0X11F);
    // addiu       $a2, $zero, 0xD9
    ctx->r6 = ADD32(0, 0XD9);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // jal         0x80026ECC
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    sub_80026ECC(rdram, ctx);
    goto after_11;
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    after_11:
L_8002F7E4:
    // lhu         $v0, 0x2C0($s1)
    ctx->r2 = MEM_HU(0X2C0, ctx->r17);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lbu         $v0, 0x13F($v1)
    ctx->r2 = MEM_BU(0X13F, ctx->r3);
    // nop

    // beq         $v0, $zero, L_8002F960
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x10
        ctx->r5 = ADD32(0, 0X10);
        goto L_8002F960;
    }
    // addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // addiu       $a2, $zero, 0xD8
    ctx->r6 = ADD32(0, 0XD8);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x3A($a0)
    ctx->r2 = MEM_HU(0X3A, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_12;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_12:
    // lhu         $v1, 0x2C0($s1)
    ctx->r3 = MEM_HU(0X2C0, ctx->r17);
    // nop

    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v0, $s2
    ctx->r3 = ADD32(ctx->r2, ctx->r18);
    // lbu         $v0, 0x140($v1)
    ctx->r2 = MEM_BU(0X140, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8002F8EC
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x50
        ctx->r5 = ADD32(0, 0X50);
        goto L_8002F8EC;
    }
    // addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // addiu       $a2, $zero, 0xD9
    ctx->r6 = ADD32(0, 0XD9);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // ori         $a3, $a3, 0x318
    ctx->r7 = ctx->r7 | 0X318;
    // lbu         $a0, 0x140($v1)
    ctx->r4 = MEM_BU(0X140, ctx->r3);
    // lui         $s0, 0x300
    ctx->r16 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    sub_80027440(rdram, ctx);
    goto after_13;
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    after_13:
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // addiu       $a2, $zero, 0xD9
    ctx->r6 = ADD32(0, 0XD9);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // jal         0x80026ECC
    // ori         $a3, $a3, 0x308
    ctx->r7 = ctx->r7 | 0X308;
    sub_80026ECC(rdram, ctx);
    goto after_14;
    // ori         $a3, $a3, 0x308
    ctx->r7 = ctx->r7 | 0X308;
    after_14:
    // addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // addiu       $a2, $zero, 0xD9
    ctx->r6 = ADD32(0, 0XD9);
    // lhu         $v1, 0x2C0($s1)
    ctx->r3 = MEM_HU(0X2C0, ctx->r17);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // lbu         $a0, 0x13F($v0)
    ctx->r4 = MEM_BU(0X13F, ctx->r2);
    // j           L_8002F958
    // ori         $a3, $a3, 0x318
    ctx->r7 = ctx->r7 | 0X318;
    goto L_8002F958;
    // ori         $a3, $a3, 0x318
    ctx->r7 = ctx->r7 | 0X318;
L_8002F8EC:
    // addiu       $a2, $zero, 0xD9
    ctx->r6 = ADD32(0, 0XD9);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // ori         $a3, $a3, 0x310
    ctx->r7 = ctx->r7 | 0X310;
    // lbu         $a0, 0x140($v1)
    ctx->r4 = MEM_BU(0X140, ctx->r3);
    // lui         $s0, 0x300
    ctx->r16 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    sub_80027440(rdram, ctx);
    goto after_15;
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    after_15:
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // addiu       $a2, $zero, 0xD9
    ctx->r6 = ADD32(0, 0XD9);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // jal         0x80026ECC
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    sub_80026ECC(rdram, ctx);
    goto after_16;
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    after_16:
    // addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // addiu       $a2, $zero, 0xD9
    ctx->r6 = ADD32(0, 0XD9);
    // lhu         $v1, 0x2C0($s1)
    ctx->r3 = MEM_HU(0X2C0, ctx->r17);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // lbu         $a0, 0x13F($v0)
    ctx->r4 = MEM_BU(0X13F, ctx->r2);
    // ori         $a3, $a3, 0x310
    ctx->r7 = ctx->r7 | 0X310;
L_8002F958:
    // jal         0x80027440
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    sub_80027440(rdram, ctx);
    goto after_17;
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    after_17:
L_8002F960:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
