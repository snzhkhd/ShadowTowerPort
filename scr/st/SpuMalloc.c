#include "recomp.h"
#include "disable_warnings.h"

void SpuMalloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xDB8($v0)
    ctx->r2 = MEM_W(0XDB8, ctx->r2);
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // bne         $v0, $zero, L_80073DFC
    if (ctx->r2 != 0) {
        // sw          $s3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r19;
        goto L_80073DFC;
    }
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // j           L_80073E18
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    goto L_80073E18;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_80073DFC:
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xDBC($v1)
    ctx->r3 = MEM_W(0XDBC, ctx->r3);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD68($a0)
    ctx->r4 = MEM_W(0XD68, ctx->r4);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sllv        $s3, $v0, $a0
    ctx->r19 = S32(ctx->r2) << (ctx->r4 & 31);
L_80073E18:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD70($v1)
    ctx->r3 = MEM_W(0XD70, ctx->r3);
    // nop

    // nor         $v0, $zero, $v1
    ctx->r2 = ~(0 | ctx->r3);
    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_80073E38
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80073E38;
    }
    // nop

    // addu        $s1, $s1, $v1
    ctx->r17 = ADD32(ctx->r17, ctx->r3);
L_80073E38:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD68($v0)
    ctx->r2 = MEM_W(0XD68, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xE28($v1)
    ctx->r3 = MEM_W(0XE28, ctx->r3);
    // srav        $s1, $s1, $v0
    ctx->r17 = S32(ctx->r17) >> (ctx->r2 & 31);
    // sllv        $s1, $s1, $v0
    ctx->r17 = S32(ctx->r17) << (ctx->r2 & 31);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // lui         $v1, 0x4000
    ctx->r3 = S32(0X4000 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_80073E6C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80073E6C;
    }
    // nop

    // j           L_80073EF0
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    goto L_80073EF0;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_80073E6C:
    // jal         0x80073664
    // nop

    _spu_gcSPU(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xE20($v1)
    ctx->r3 = MEM_W(0XE20, ctx->r3);
    // nop

    // slt         $v0, $s0, $v1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80073EF0
    if (ctx->r2 == 0) {
        // sll         $v0, $s0, 3
        ctx->r2 = S32(ctx->r16) << 3;
        goto L_80073EF0;
    }
    // sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16) << 3;
    // lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xE28($v1)
    ctx->r3 = MEM_W(0XE28, ctx->r3);
    // nop

    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
L_80073EA8:
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // and         $v0, $v1, $a3
    ctx->r2 = ctx->r3 & ctx->r7;
    // bne         $v0, $zero, L_80073ED8
    if (ctx->r2 != 0) {
        // and         $v0, $v1, $a2
        ctx->r2 = ctx->r3 & ctx->r6;
        goto L_80073ED8;
    }
    // and         $v0, $v1, $a2
    ctx->r2 = ctx->r3 & ctx->r6;
    // beq         $v0, $zero, L_80073EE0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80073EE0;
    }
    // nop

    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // sltu        $v0, $v0, $s1
    ctx->r2 = ctx->r2 < ctx->r17 ? 1 : 0;
    // bne         $v0, $zero, L_80073EE0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80073EE0;
    }
    // nop

L_80073ED8:
    // j           L_80073EF0
    // addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    goto L_80073EF0;
    // addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
L_80073EE0:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slt         $v0, $s0, $a1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_80073EA8
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_80073EA8;
    }
    // addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80073EF0:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s2, $v0, L_8007406C
    if (ctx->r18 == ctx->r2) {
        // sll         $s0, $s2, 3
        ctx->r16 = S32(ctx->r18) << 3;
        goto L_8007406C;
    }
    // sll         $s0, $s2, 3
    ctx->r16 = S32(ctx->r18) << 3;
    // lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // lw          $a3, 0xE28($a3)
    ctx->r7 = MEM_W(0XE28, ctx->r7);
    // nop

    // addu        $a2, $s0, $a3
    ctx->r6 = ADD32(ctx->r16, ctx->r7);
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // lui         $t0, 0x4000
    ctx->r8 = S32(0X4000 << 16);
    // and         $v0, $v1, $t0
    ctx->r2 = ctx->r3 & ctx->r8;
    // beq         $v0, $zero, L_80073FC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80073FC0;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE20($v0)
    ctx->r2 = MEM_W(0XE20, ctx->r2);
    // nop

    // slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8007406C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8007406C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(0X4, ctx->r6);
    // nop

    // subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // sltu        $v0, $v0, $s1
    ctx->r2 = ctx->r2 < ctx->r17 ? 1 : 0;
    // bne         $v0, $zero, L_8007406C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8007406C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $a1, 0xFFF
    ctx->r5 = S32(0XFFF << 16);
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // addiu       $a0, $s2, 0x1
    ctx->r4 = ADD32(ctx->r18, 0X1);
    // sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4) << 3;
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // or          $v0, $v0, $t0
    ctx->r2 = ctx->r2 | ctx->r8;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(0X4, ctx->r6);
    // nop

    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $a0, 0xE24($at)
    MEM_W(0XE24, ctx->r1) = ctx->r4;
    // sw          $s1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r17;
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // jal         0x80073664
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    _spu_gcSPU(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    after_1:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE28($v0)
    ctx->r2 = MEM_W(0XE28, ctx->r2);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // j           L_8007406C
    // nop

    goto L_8007406C;
    // nop

L_80073FC0:
    // lw          $t0, 0x4($a2)
    ctx->r8 = MEM_W(0X4, ctx->r6);
    // nop

    // sltu        $v0, $s1, $t0
    ctx->r2 = ctx->r17 < ctx->r8 ? 1 : 0;
    // beq         $v0, $zero, L_80074030
    if (ctx->r2 == 0) {
        // lui         $a0, 0xFFF
        ctx->r4 = S32(0XFFF << 16);
        goto L_80074030;
    }
    // lui         $a0, 0xFFF
    ctx->r4 = S32(0XFFF << 16);
    // lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // lw          $a2, 0xE24($a2)
    ctx->r6 = MEM_W(0XE24, ctx->r6);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE20($v0)
    ctx->r2 = MEM_W(0XE20, ctx->r2);
    // nop

    // slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80074030
    if (ctx->r2 == 0) {
        // addu        $v1, $v1, $s1
        ctx->r3 = ADD32(ctx->r3, ctx->r17);
        goto L_80074030;
    }
    // addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6) << 3;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(0X0, ctx->r2);
    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // subu        $v1, $t0, $s1
    ctx->r3 = SUB32(ctx->r8, ctx->r17);
    // sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, 0xE24($at)
    MEM_W(0XE24, ctx->r1) = ctx->r3;
    // sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // lui         $a0, 0xFFF
    ctx->r4 = S32(0XFFF << 16);
L_80074030:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xE28($v1)
    ctx->r3 = MEM_W(0XE28, ctx->r3);
    // sll         $s0, $s2, 3
    ctx->r16 = S32(ctx->r18) << 3;
    // addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // jal         0x80073664
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    _spu_gcSPU(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    after_2:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE28($v0)
    ctx->r2 = MEM_W(0XE28, ctx->r2);
    // nop

    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
L_8007406C:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
