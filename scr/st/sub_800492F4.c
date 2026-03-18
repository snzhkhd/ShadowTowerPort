#include "recomp.h"
#include "disable_warnings.h"

void sub_800492F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addiu       $s2, $v0, 0x5948
    ctx->r18 = ADD32(ctx->r2, 0X5948);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(0X74, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_80049398
    if (ctx->r2 == 0) {
        // lui         $s0, 0x801A
        ctx->r16 = S32(0X801A << 16);
        goto L_80049398;
    }
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // lw          $v0, 0x248($s0)
    ctx->r2 = MEM_W(0X248, ctx->r16);
    // nop

    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // lw          $v0, 0x250($s0)
    ctx->r2 = MEM_W(0X250, ctx->r16);
    // mflo        $a1
    ctx->r5 = lo;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // nop

    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
    after_0:
    // sw          $v0, 0xBC($s2)
    MEM_W(0XBC, ctx->r18) = ctx->r2;
    // lw          $v0, 0x248($s0)
    ctx->r2 = MEM_W(0X248, ctx->r16);
    // lw          $v1, 0x24C($s0)
    ctx->r3 = MEM_W(0X24C, ctx->r16);
    // lw          $a0, 0x250($s0)
    ctx->r4 = MEM_W(0X250, ctx->r16);
    // lw          $a1, 0x254($s0)
    ctx->r5 = MEM_W(0X254, ctx->r16);
    // sw          $v0, 0xAC($s2)
    MEM_W(0XAC, ctx->r18) = ctx->r2;
    // sw          $v1, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r3;
    // sw          $a0, 0xB4($s2)
    MEM_W(0XB4, ctx->r18) = ctx->r4;
    // sw          $a1, 0xB8($s2)
    MEM_W(0XB8, ctx->r18) = ctx->r5;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x44C0($s2)
    MEM_H(0X44C0, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // j           L_80049528
    // sh          $v0, 0x44C2($s2)
    MEM_H(0X44C2, ctx->r18) = ctx->r2;
    goto L_80049528;
    // sh          $v0, 0x44C2($s2)
    MEM_H(0X44C2, ctx->r18) = ctx->r2;
L_80049398:
    // lw          $a1, 0x5C($s2)
    ctx->r5 = MEM_W(0X5C, ctx->r18);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a1, $v0, L_80049440
    if (ctx->r5 == ctx->r2) {
        // sll         $s0, $a1, 1
        ctx->r16 = S32(ctx->r5) << 1;
        goto L_80049440;
    }
    // sll         $s0, $a1, 1
    ctx->r16 = S32(ctx->r5) << 1;
    // addu        $s0, $s0, $a1
    ctx->r16 = ADD32(ctx->r16, ctx->r5);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // addu        $s0, $s0, $a1
    ctx->r16 = ADD32(ctx->r16, ctx->r5);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // addu        $s0, $s0, $a1
    ctx->r16 = ADD32(ctx->r16, ctx->r5);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(0X74, ctx->r16);
    // nop

    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(0X7C, ctx->r16);
    // mflo        $a1
    ctx->r5 = lo;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // nop

    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_1;
    // addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
    after_1:
    // sw          $v0, 0xBC($s2)
    MEM_W(0XBC, ctx->r18) = ctx->r2;
    // lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(0X74, ctx->r16);
    // lw          $v1, 0x78($s0)
    ctx->r3 = MEM_W(0X78, ctx->r16);
    // lw          $a0, 0x7C($s0)
    ctx->r4 = MEM_W(0X7C, ctx->r16);
    // lw          $a1, 0x80($s0)
    ctx->r5 = MEM_W(0X80, ctx->r16);
    // sw          $v0, 0xAC($s2)
    MEM_W(0XAC, ctx->r18) = ctx->r2;
    // sw          $v1, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r3;
    // sw          $a0, 0xB4($s2)
    MEM_W(0XB4, ctx->r18) = ctx->r4;
    // sw          $a1, 0xB8($s2)
    MEM_W(0XB8, ctx->r18) = ctx->r5;
    // lhu         $v0, 0x2E($s0)
    ctx->r2 = MEM_HU(0X2E, ctx->r16);
    // nop

    // sh          $v0, 0x44C0($s2)
    MEM_H(0X44C0, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(0X30, ctx->r16);
    // j           L_80049528
    // sh          $v0, 0x44C2($s2)
    MEM_H(0X44C2, ctx->r18) = ctx->r2;
    goto L_80049528;
    // sh          $v0, 0x44C2($s2)
    MEM_H(0X44C2, ctx->r18) = ctx->r2;
L_80049440:
    // lw          $v1, 0x64($s2)
    ctx->r3 = MEM_W(0X64, ctx->r18);
    // nop

    // beq         $v1, $a1, L_80049528
    if (ctx->r3 == ctx->r5) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_80049528;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // addiu       $a1, $a1, 0x2230
    ctx->r5 = ADD32(ctx->r5, 0X2230);
    // addu        $s0, $v0, $a1
    ctx->r16 = ADD32(ctx->r2, ctx->r5);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(0X24, ctx->r16);
    // nop

    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(0X2C, ctx->r16);
    // mflo        $a2
    ctx->r6 = lo;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // nop

    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(0XA, ctx->r16);
    // addiu       $a1, $a1, -0x1F20
    ctx->r5 = ADD32(ctx->r5, -0X1F20);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $s1, $v0, $a1
    ctx->r17 = ADD32(ctx->r2, ctx->r5);
    // mflo        $t0
    ctx->r8 = lo;
    // jal         0x800746C4
    // addu        $a0, $a2, $t0
    ctx->r4 = ADD32(ctx->r6, ctx->r8);
    SquareRoot0(rdram, ctx);
    goto after_2;
    // addu        $a0, $a2, $t0
    ctx->r4 = ADD32(ctx->r6, ctx->r8);
    after_2:
    // sw          $v0, 0xBC($s2)
    MEM_W(0XBC, ctx->r18) = ctx->r2;
    // lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(0X24, ctx->r16);
    // lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(0X28, ctx->r16);
    // lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(0X2C, ctx->r16);
    // lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(0X30, ctx->r16);
    // sw          $v0, 0xAC($s2)
    MEM_W(0XAC, ctx->r18) = ctx->r2;
    // sw          $v1, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r3;
    // sw          $a0, 0xB4($s2)
    MEM_W(0XB4, ctx->r18) = ctx->r4;
    // sw          $a1, 0xB8($s2)
    MEM_W(0XB8, ctx->r18) = ctx->r5;
    // lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(0X4, ctx->r16);
    // nop

    // andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // beq         $v0, $zero, L_80049510
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80049510;
    }
    // nop

    // lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(0X4, ctx->r17);
    // lbu         $v0, 0x48($s0)
    ctx->r2 = MEM_BU(0X48, ctx->r16);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // j           L_80049514
    // sra         $v0, $a3, 7
    ctx->r2 = S32(ctx->r7) >> 7;
    goto L_80049514;
    // sra         $v0, $a3, 7
    ctx->r2 = S32(ctx->r7) >> 7;
L_80049510:
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
L_80049514:
    // nop

    // sh          $v0, 0x44C0($s2)
    MEM_H(0X44C0, ctx->r18) = ctx->r2;
    // lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(0X8, ctx->r17);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // sh          $v1, -0x61F6($v0)
    MEM_H(-0X61F6, ctx->r2) = ctx->r3;
L_80049528:
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
