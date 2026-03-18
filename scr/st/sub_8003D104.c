#include "recomp.h"
#include "disable_warnings.h"

void sub_8003D104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // beq         $v0, $s2, L_8003D26C
    if (ctx->r2 == ctx->r18) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8003D26C;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // addiu       $s1, $v0, 0x76F8
    ctx->r17 = ADD32(ctx->r2, 0X76F8);
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
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // lbu         $v1, 0x140($v0)
    ctx->r3 = MEM_BU(0X140, ctx->r2);
    // nop

    // beq         $v1, $zero, L_8003D26C
    if (ctx->r3 == 0) {
        // subu        $v1, $v1, $a0
        ctx->r3 = SUB32(ctx->r3, ctx->r4);
        goto L_8003D26C;
    }
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // bgtz        $v1, L_8003D260
    if (SIGNED(ctx->r3) > 0) {
        // addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
        goto L_8003D260;
    }
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // jal         0x800582F0
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    sub_800582F0(rdram, ctx);
    goto after_0;
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_0:
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

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
    // addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70A0
    ctx->r2 = ADD32(ctx->r2, -0X70A0);
    // beq         $s0, $v0, L_8003D1AC
    if (ctx->r16 == ctx->r2) {
        // sb          $zero, 0x140($v1)
        MEM_B(0X140, ctx->r3) = 0;
        goto L_8003D1AC;
    }
    // sb          $zero, 0x140($v1)
    MEM_B(0X140, ctx->r3) = 0;
    // addiu       $v0, $v0, 0x1A
    ctx->r2 = ADD32(ctx->r2, 0X1A);
    // beq         $s0, $v0, L_8003D1B0
    if (ctx->r16 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003D1B0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sh          $s2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r18;
L_8003D1AC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8003D1B0:
    // addiu       $v1, $v0, -0x709A
    ctx->r3 = ADD32(ctx->r2, -0X709A);
    // bne         $s0, $v1, L_8003D1EC
    if (ctx->r16 != ctx->r3) {
        // addiu       $v0, $v1, 0x1A
        ctx->r2 = ADD32(ctx->r3, 0X1A);
        goto L_8003D1EC;
    }
    // addiu       $v0, $v1, 0x1A
    ctx->r2 = ADD32(ctx->r3, 0X1A);
    // lbu         $v0, 0x10A($s0)
    ctx->r2 = MEM_BU(0X10A, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1F
    ctx->r2 = ADD32(ctx->r2, -0X1F);
    // sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8003D1E0
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
        goto L_8003D1E0;
    }
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // jal         0x8003F12C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003F12C(rdram, ctx);
    goto after_1;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
L_8003D1E0:
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // j           L_8003D220
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    goto L_8003D220;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8003D1EC:
    // bne         $s0, $v0, L_8003D200
    if (ctx->r16 != ctx->r2) {
        // addiu       $v0, $v1, 0x2
        ctx->r2 = ADD32(ctx->r3, 0X2);
        goto L_8003D200;
    }
    // addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // j           L_8003D220
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    goto L_8003D220;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8003D200:
    // bne         $s0, $v0, L_8003D214
    if (ctx->r16 != ctx->r2) {
        // addiu       $v0, $v1, 0x1C
        ctx->r2 = ADD32(ctx->r3, 0X1C);
        goto L_8003D214;
    }
    // addiu       $v0, $v1, 0x1C
    ctx->r2 = ADD32(ctx->r3, 0X1C);
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // j           L_8003D220
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    goto L_8003D220;
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8003D214:
    // bne         $s0, $v0, L_8003D228
    if (ctx->r16 != ctx->r2) {
        // ori         $a0, $zero, 0xFFFF
        ctx->r4 = 0 | 0XFFFF;
        goto L_8003D228;
    }
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_8003D220:
    // jal         0x8003F12C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003F12C(rdram, ctx);
    goto after_2;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
L_8003D228:
    // jal         0x8003CB88
    // nop

    sub_8003CB88(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x8005A3A8
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8005A3A8(rdram, ctx);
    goto after_4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, -0x70D8($v0)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r2);
    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // nop

    // sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8003D264
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003D264;
    }
    // nop

    // j           L_8003D264
    // sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
    goto L_8003D264;
    // sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
L_8003D260:
    // sb          $v1, 0x140($v0)
    MEM_B(0X140, ctx->r2) = ctx->r3;
L_8003D264:
    // jal         0x8003D030
    // nop

    sub_8003D030(rdram, ctx);
    goto after_5;
    // nop

    after_5:
L_8003D26C:
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
