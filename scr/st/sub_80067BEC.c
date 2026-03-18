#include "recomp.h"
#include "disable_warnings.h"

void sub_80067BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $ra, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r31;
    // sw          $fp, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r30;
    // sw          $s7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r23;
    // sw          $s6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r22;
    // sw          $s5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r21;
    // sw          $s4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r20;
    // sw          $s3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r19;
    // sw          $s2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r18;
    // sw          $s1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r17;
    // sw          $s0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r16;
    // sb          $a0, 0xA0($sp)
    MEM_B(0XA0, ctx->r29) = ctx->r4;
    // addiu       $a2, $v0, -0x7ED4
    ctx->r6 = ADD32(ctx->r2, -0X7ED4);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7ED0
    ctx->r6 = ADD32(ctx->r2, -0X7ED0);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r3);
    // swr         $v1, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r3);
    // swl         $a0, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r4);
    // swr         $a0, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7EC8
    ctx->r6 = ADD32(ctx->r2, -0X7EC8);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x4B($sp)
    do_swl(rdram, 0X4B, ctx->r29, ctx->r3);
    // swr         $v1, 0x48($sp)
    do_swr(rdram, 0X48, ctx->r29, ctx->r3);
    // swl         $a0, 0x4F($sp)
    do_swl(rdram, 0X4F, ctx->r29, ctx->r4);
    // swr         $a0, 0x4C($sp)
    do_swr(rdram, 0X4C, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7EC0
    ctx->r6 = ADD32(ctx->r2, -0X7EC0);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x53($sp)
    do_swl(rdram, 0X53, ctx->r29, ctx->r3);
    // swr         $v1, 0x50($sp)
    do_swr(rdram, 0X50, ctx->r29, ctx->r3);
    // swl         $a0, 0x57($sp)
    do_swl(rdram, 0X57, ctx->r29, ctx->r4);
    // swr         $a0, 0x54($sp)
    do_swr(rdram, 0X54, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7EB8
    ctx->r6 = ADD32(ctx->r2, -0X7EB8);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x5B($sp)
    do_swl(rdram, 0X5B, ctx->r29, ctx->r3);
    // swr         $v1, 0x58($sp)
    do_swr(rdram, 0X58, ctx->r29, ctx->r3);
    // swl         $a0, 0x5F($sp)
    do_swl(rdram, 0X5F, ctx->r29, ctx->r4);
    // swr         $a0, 0x5C($sp)
    do_swr(rdram, 0X5C, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7EB0
    ctx->r6 = ADD32(ctx->r2, -0X7EB0);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x63($sp)
    do_swl(rdram, 0X63, ctx->r29, ctx->r3);
    // swr         $v1, 0x60($sp)
    do_swr(rdram, 0X60, ctx->r29, ctx->r3);
    // swl         $a0, 0x67($sp)
    do_swl(rdram, 0X67, ctx->r29, ctx->r4);
    // swr         $a0, 0x64($sp)
    do_swr(rdram, 0X64, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7EA8
    ctx->r6 = ADD32(ctx->r2, -0X7EA8);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x6B($sp)
    do_swl(rdram, 0X6B, ctx->r29, ctx->r3);
    // swr         $v1, 0x68($sp)
    do_swr(rdram, 0X68, ctx->r29, ctx->r3);
    // swl         $a0, 0x6F($sp)
    do_swl(rdram, 0X6F, ctx->r29, ctx->r4);
    // swr         $a0, 0x6C($sp)
    do_swr(rdram, 0X6C, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7EA0
    ctx->r6 = ADD32(ctx->r2, -0X7EA0);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x73($sp)
    do_swl(rdram, 0X73, ctx->r29, ctx->r3);
    // swr         $v1, 0x70($sp)
    do_swr(rdram, 0X70, ctx->r29, ctx->r3);
    // swl         $a0, 0x77($sp)
    do_swl(rdram, 0X77, ctx->r29, ctx->r4);
    // swr         $a0, 0x74($sp)
    do_swr(rdram, 0X74, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7E98
    ctx->r6 = ADD32(ctx->r2, -0X7E98);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x7B($sp)
    do_swl(rdram, 0X7B, ctx->r29, ctx->r3);
    // swr         $v1, 0x78($sp)
    do_swr(rdram, 0X78, ctx->r29, ctx->r3);
    // swl         $a0, 0x7F($sp)
    do_swl(rdram, 0X7F, ctx->r29, ctx->r4);
    // swr         $a0, 0x7C($sp)
    do_swr(rdram, 0X7C, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7E90
    ctx->r6 = ADD32(ctx->r2, -0X7E90);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x83($sp)
    do_swl(rdram, 0X83, ctx->r29, ctx->r3);
    // swr         $v1, 0x80($sp)
    do_swr(rdram, 0X80, ctx->r29, ctx->r3);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lbu         $v1, 0xD38($v0)
    ctx->r3 = MEM_BU(0XD38, ctx->r2);
    // addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // bne         $v1, $v0, L_80067DB4
    if (ctx->r3 != ctx->r2) {
        // lui         $s1, 0x1F80
        ctx->r17 = S32(0X1F80 << 16);
        goto L_80067DB4;
    }
    // lui         $s1, 0x1F80
    ctx->r17 = S32(0X1F80 << 16);
    // lhu         $v0, 0x2E0($s1)
    ctx->r2 = MEM_HU(0X2E0, ctx->r17);
    // j           L_80067DBC
    // addiu       $v1, $zero, 0x1A
    ctx->r3 = ADD32(0, 0X1A);
    goto L_80067DBC;
    // addiu       $v1, $zero, 0x1A
    ctx->r3 = ADD32(0, 0X1A);
L_80067DB4:
    // lhu         $v0, 0x2E0($s1)
    ctx->r2 = MEM_HU(0X2E0, ctx->r17);
    // addiu       $v1, $zero, 0x154
    ctx->r3 = ADD32(0, 0X154);
L_80067DBC:
    // sh          $v1, 0x330($s1)
    MEM_H(0X330, ctx->r17) = ctx->r3;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addiu       $v0, $v0, 0x21
    ctx->r2 = ADD32(ctx->r2, 0X21);
    // sh          $v0, 0x332($s1)
    MEM_H(0X332, ctx->r17) = ctx->r2;
    // ori         $a0, $s1, 0x330
    ctx->r4 = ctx->r17 | 0X330;
    // addiu       $s0, $s1, 0x32C
    ctx->r16 = ADD32(ctx->r17, 0X32C);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addiu       $a2, $zero, 0x201
    ctx->r6 = ADD32(0, 0X201);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $zero, 0x10E
    ctx->r2 = ADD32(0, 0X10E);
    // sh          $v0, 0x334($s1)
    MEM_H(0X334, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // jal         0x80027D18
    // sh          $v0, 0x336($s1)
    MEM_H(0X336, ctx->r17) = ctx->r2;
    sub_80027D18(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x336($s1)
    MEM_H(0X336, ctx->r17) = ctx->r2;
    after_0:
    // lbu         $v1, 0xA0($sp)
    ctx->r3 = MEM_BU(0XA0, ctx->r29);
    // addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // bne         $v1, $v0, L_80067E40
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80067E40;
    }
    // nop

    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_HS(0X0, ctx->r17);
    // nop

    // blez        $v0, L_80067E28
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $a0, $sp, 0x50
        ctx->r4 = ADD32(ctx->r29, 0X50);
        goto L_80067E28;
    }
    // addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x8002916C
    // addiu       $a2, $zero, 0xC00
    ctx->r6 = ADD32(0, 0XC00);
    sub_8002916C(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0xC00
    ctx->r6 = ADD32(0, 0XC00);
    after_1:
    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_HS(0X0, ctx->r17);
L_80067E28:
    // nop

    // slti        $v0, $v0, 0x12F
    ctx->r2 = SIGNED(ctx->r2) < 0X12F ? 1 : 0;
    // beq         $v0, $zero, L_80067E88
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x58
        ctx->r4 = ADD32(ctx->r29, 0X58);
        goto L_80067E88;
    }
    // addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // j           L_80067E80
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    goto L_80067E80;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_80067E40:
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_80067E60
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $a0, $sp, 0x68
        ctx->r4 = ADD32(ctx->r29, 0X68);
        goto L_80067E60;
    }
    // addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x8002916C
    // addiu       $a2, $zero, 0xC00
    ctx->r6 = ADD32(0, 0XC00);
    sub_8002916C(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0xC00
    ctx->r6 = ADD32(0, 0XC00);
    after_2:
L_80067E60:
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x12F
    ctx->r2 = SIGNED(ctx->r2) < 0X12F ? 1 : 0;
    // beq         $v0, $zero, L_80067E88
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x70
        ctx->r4 = ADD32(ctx->r29, 0X70);
        goto L_80067E88;
    }
    // addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_80067E80:
    // jal         0x8002916C
    // addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    sub_8002916C(rdram, ctx);
    goto after_3;
    // addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_3:
L_80067E88:
    // lbu         $v1, 0xA0($sp)
    ctx->r3 = MEM_BU(0XA0, ctx->r29);
    // addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // bne         $v1, $v0, L_80067F1C
    if (ctx->r3 != ctx->r2) {
        // lui         $a0, 0xD84
        ctx->r4 = S32(0XD84 << 16);
        goto L_80067F1C;
    }
    // lui         $a0, 0xD84
    ctx->r4 = S32(0XD84 << 16);
    // lh          $v1, 0x0($s1)
    ctx->r3 = MEM_HS(0X0, ctx->r17);
    // ori         $a0, $a0, 0xA599
    ctx->r4 = ctx->r4 | 0XA599;
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
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t0
    ctx->r8 = hi;
    // sra         $v1, $t0, 4
    ctx->r3 = S32(ctx->r8) >> 4;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // addiu       $v1, $v1, 0x23
    ctx->r3 = ADD32(ctx->r3, 0X23);
    // jal         0x80028220
    // sh          $v1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r3;
    sub_80028220(rdram, ctx);
    goto after_4;
    // sh          $v1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r3;
    after_4:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_5;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_5:
    // lhu         $v0, 0x60($sp)
    ctx->r2 = MEM_HU(0X60, ctx->r29);
    // lhu         $v1, 0x64($sp)
    ctx->r3 = MEM_HU(0X64, ctx->r29);
    // lhu         $a0, 0x66($sp)
    ctx->r4 = MEM_HU(0X66, ctx->r29);
    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x62($sp)
    ctx->r2 = MEM_HU(0X62, ctx->r29);
    // j           L_80067FA4
    // sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
    goto L_80067FA4;
    // sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
L_80067F1C:
    // lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(0X2, ctx->r17);
    // ori         $a0, $a0, 0xA599
    ctx->r4 = ctx->r4 | 0XA599;
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
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t0
    ctx->r8 = hi;
    // sra         $v1, $t0, 4
    ctx->r3 = S32(ctx->r8) >> 4;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // addiu       $v1, $v1, 0x23
    ctx->r3 = ADD32(ctx->r3, 0X23);
    // jal         0x80028220
    // sh          $v1, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r3;
    sub_80028220(rdram, ctx);
    goto after_6;
    // sh          $v1, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r3;
    after_6:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_7;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_7:
    // lhu         $v0, 0x78($sp)
    ctx->r2 = MEM_HU(0X78, ctx->r29);
    // lhu         $v1, 0x7C($sp)
    ctx->r3 = MEM_HU(0X7C, ctx->r29);
    // lhu         $a0, 0x7E($sp)
    ctx->r4 = MEM_HU(0X7E, ctx->r29);
    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x7A($sp)
    ctx->r2 = MEM_HU(0X7A, ctx->r29);
    // sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
L_80067FA4:
    // sh          $a0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r4;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // jal         0x80028220
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_80028220(rdram, ctx);
    goto after_8;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_9;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_9:
    // lbu         $v1, 0xA0($sp)
    ctx->r3 = MEM_BU(0XA0, ctx->r29);
    // addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // bne         $v1, $v0, L_8006800C
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x3C
        ctx->r2 = ADD32(0, 0X3C);
        goto L_8006800C;
    }
    // addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // sh          $v0, 0x33C($s1)
    MEM_H(0X33C, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // sh          $v0, 0x33E($s1)
    MEM_H(0X33E, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0xC4
    ctx->r2 = ADD32(0, 0XC4);
    // sh          $v0, 0x340($s1)
    MEM_H(0X340, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x342($s1)
    MEM_H(0X342, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // sh          $v0, 0x358($s1)
    MEM_H(0X358, ctx->r17) = ctx->r2;
    // j           L_80068038
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    goto L_80068038;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
L_8006800C:
    // addiu       $v0, $zero, 0x180
    ctx->r2 = ADD32(0, 0X180);
    // sh          $v0, 0x33C($s1)
    MEM_H(0X33C, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // sh          $v0, 0x33E($s1)
    MEM_H(0X33E, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0xC4
    ctx->r2 = ADD32(0, 0XC4);
    // sh          $v0, 0x340($s1)
    MEM_H(0X340, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x342($s1)
    MEM_H(0X342, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // sh          $v0, 0x358($s1)
    MEM_H(0X358, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x1D0
    ctx->r2 = ADD32(0, 0X1D0);
L_80068038:
    // sh          $v0, 0x35A($s1)
    MEM_H(0X35A, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($s1)
    MEM_H(0X35C, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x1F6
    ctx->r2 = ADD32(0, 0X1F6);
    // sh          $v0, 0x35E($s1)
    MEM_H(0X35E, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // ori         $a0, $s1, 0x33C
    ctx->r4 = ctx->r17 | 0X33C;
    // ori         $a1, $s1, 0x358
    ctx->r5 = ctx->r17 | 0X358;
    // ori         $a2, $s1, 0x35C
    ctx->r6 = ctx->r17 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_10;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_10:
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7E8C
    ctx->r6 = ADD32(ctx->r2, -0X7E8C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x8B($sp)
    do_swl(rdram, 0X8B, ctx->r29, ctx->r3);
    // swr         $v1, 0x88($sp)
    do_swr(rdram, 0X88, ctx->r29, ctx->r3);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7E88
    ctx->r6 = ADD32(ctx->r2, -0X7E88);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x93($sp)
    do_swl(rdram, 0X93, ctx->r29, ctx->r3);
    // swr         $v1, 0x90($sp)
    do_swr(rdram, 0X90, ctx->r29, ctx->r3);
    // lbu         $v1, 0xA0($sp)
    ctx->r3 = MEM_BU(0XA0, ctx->r29);
    // addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // bne         $v1, $v0, L_800680B4
    if (ctx->r3 != ctx->r2) {
        // addiu       $s5, $zero, 0x156
        ctx->r21 = ADD32(0, 0X156);
        goto L_800680B4;
    }
    // addiu       $s5, $zero, 0x156
    ctx->r21 = ADD32(0, 0X156);
    // addiu       $s5, $zero, 0x1C
    ctx->r21 = ADD32(0, 0X1C);
L_800680B4:
    // addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s7, $v0, 0xD38
    ctx->r23 = ADD32(ctx->r2, 0XD38);
    // addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // lbu         $v0, 0x303($s1)
    ctx->r2 = MEM_BU(0X303, ctx->r17);
    // lbu         $s6, 0xA0($sp)
    ctx->r22 = MEM_BU(0XA0, ctx->r29);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, 0x303($s1)
    MEM_B(0X303, ctx->r17) = ctx->r2;
L_800680DC:
    // addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // bne         $s6, $v0, L_800680F8
    if (ctx->r22 != ctx->r2) {
        // nop
    
        goto L_800680F8;
    }
    // nop

    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_HS(0X0, ctx->r17);
    // lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(0X4, ctx->r17);
    // j           L_8006810C
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    goto L_8006810C;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
L_800680F8:
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(0X8, ctx->r17);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
L_8006810C:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $s0, 0x0($v0)
    ctx->r16 = MEM_HU(0X0, ctx->r2);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lbu         $v0, 0xD38($v0)
    ctx->r2 = MEM_BU(0XD38, ctx->r2);
    // nop

    // bne         $s6, $v0, L_800681A4
    if (ctx->r22 != ctx->r2) {
        // addiu       $s3, $s1, 0x300
        ctx->r19 = ADD32(ctx->r17, 0X300);
        goto L_800681A4;
    }
    // addiu       $s3, $s1, 0x300
    ctx->r19 = ADD32(ctx->r17, 0X300);
    // lbu         $v0, 0x4($s7)
    ctx->r2 = MEM_BU(0X4, ctx->r23);
    // nop

    // beq         $v0, $zero, L_800681A8
    if (ctx->r2 == 0) {
        // sll         $v0, $s0, 16
        ctx->r2 = S32(ctx->r16) << 16;
        goto L_800681A8;
    }
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
    // lw          $v0, 0x8($s7)
    ctx->r2 = MEM_W(0X8, ctx->r23);
    // nop

    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800681A8
    if (ctx->r2 != 0) {
        // sll         $v0, $s0, 16
        ctx->r2 = S32(ctx->r16) << 16;
        goto L_800681A8;
    }
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
    // lw          $v0, 0xC($s7)
    ctx->r2 = MEM_W(0XC, ctx->r23);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_800681A8
    if (ctx->r2 != 0) {
        // sll         $v0, $s0, 16
        ctx->r2 = S32(ctx->r16) << 16;
        goto L_800681A8;
    }
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $fp, L_800681B4
    if (ctx->r2 != ctx->r30) {
        // addiu       $s3, $sp, 0x88
        ctx->r19 = ADD32(ctx->r29, 0X88);
        goto L_800681B4;
    }
    // addiu       $s3, $sp, 0x88
    ctx->r19 = ADD32(ctx->r29, 0X88);
    // addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x10A
    ctx->r2 = ADD32(0, 0X10A);
    // sh          $v0, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // sh          $s5, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r21;
    // sh          $s4, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r20;
    // jal         0x80028220
    // sh          $v0, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r2;
    sub_80028220(rdram, ctx);
    goto after_11;
    // sh          $v0, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r2;
    after_11:
    // j           L_800681A8
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
    goto L_800681A8;
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
L_800681A4:
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
L_800681A8:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // beq         $v0, $fp, L_800681E0
    if (ctx->r2 == ctx->r30) {
        // nop
    
        goto L_800681E0;
    }
    // nop

L_800681B4:
    // andi        $a1, $s5, 0xFFFF
    ctx->r5 = ctx->r21 & 0XFFFF;
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
    // lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(0X14, ctx->r17);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_12;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_12:
L_800681E0:
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // slti        $v0, $s2, 0xB
    ctx->r2 = SIGNED(ctx->r18) < 0XB ? 1 : 0;
    // bne         $v0, $zero, L_800680DC
    if (ctx->r2 != 0) {
        // addiu       $s4, $s4, 0x10
        ctx->r20 = ADD32(ctx->r20, 0X10);
        goto L_800680DC;
    }
    // addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // lbu         $v0, 0x303($s1)
    ctx->r2 = MEM_BU(0X303, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // sb          $v0, 0x303($s1)
    MEM_B(0X303, ctx->r17) = ctx->r2;
    // lbu         $v1, 0xA0($sp)
    ctx->r3 = MEM_BU(0XA0, ctx->r29);
    // addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // bne         $v1, $v0, L_80068214
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $zero, 0x14E
        ctx->r4 = ADD32(0, 0X14E);
        goto L_80068214;
    }
    // addiu       $a0, $zero, 0x14E
    ctx->r4 = ADD32(0, 0X14E);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_80068214:
    // addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // addiu       $a2, $zero, 0x128
    ctx->r6 = ADD32(0, 0X128);
    // jal         0x80029548
    // addiu       $a3, $zero, 0xDE
    ctx->r7 = ADD32(0, 0XDE);
    sub_80029548(rdram, ctx);
    goto after_13;
    // addiu       $a3, $zero, 0xDE
    ctx->r7 = ADD32(0, 0XDE);
    after_13:
    // lw          $ra, 0xCC($sp)
    ctx->r31 = MEM_W(0XCC, ctx->r29);
    // lw          $fp, 0xC8($sp)
    ctx->r30 = MEM_W(0XC8, ctx->r29);
    // lw          $s7, 0xC4($sp)
    ctx->r23 = MEM_W(0XC4, ctx->r29);
    // lw          $s6, 0xC0($sp)
    ctx->r22 = MEM_W(0XC0, ctx->r29);
    // lw          $s5, 0xBC($sp)
    ctx->r21 = MEM_W(0XBC, ctx->r29);
    // lw          $s4, 0xB8($sp)
    ctx->r20 = MEM_W(0XB8, ctx->r29);
    // lw          $s3, 0xB4($sp)
    ctx->r19 = MEM_W(0XB4, ctx->r29);
    // lw          $s2, 0xB0($sp)
    ctx->r18 = MEM_W(0XB0, ctx->r29);
    // lw          $s1, 0xAC($sp)
    ctx->r17 = MEM_W(0XAC, ctx->r29);
    // lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(0XA8, ctx->r29);
    // addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    // jr          $ra
    // nop

    return;
    // nop

;}
