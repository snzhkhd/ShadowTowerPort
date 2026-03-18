#include "recomp.h"
#include "disable_warnings.h"

void SpuClearReverbWorkArea(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sltiu       $v0, $s0, 0xA
    ctx->r2 = ctx->r16 < 0XA ? 1 : 0;
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // beq         $v0, $zero, L_8007012C
    if (ctx->r2 == 0) {
        // addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
        goto L_8007012C;
    }
    // addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0xE30
    ctx->r3 = ADD32(ctx->r3, 0XE30);
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(0X0, ctx->r17);
    // jal         0x8006FB74
    // nop

    _SpuIsInAllocateArea_(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // beq         $v0, $zero, L_80070134
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070134;
    }
    // nop

L_8007012C:
    // j           L_80070244
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80070244;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80070134:
    // bne         $s0, $zero, L_80070158
    if (ctx->r16 != 0) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_80070158;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD68($v0)
    ctx->r2 = MEM_W(0XD68, ctx->r2);
    // addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // sllv        $s1, $v1, $v0
    ctx->r17 = S32(ctx->r3) << (ctx->r2 & 31);
    // ori         $v1, $zero, 0xFFF0
    ctx->r3 = 0 | 0XFFF0;
    // j           L_80070170
    // sllv        $s2, $v1, $v0
    ctx->r18 = S32(ctx->r3) << (ctx->r2 & 31);
    goto L_80070170;
    // sllv        $s2, $v1, $v0
    ctx->r18 = S32(ctx->r3) << (ctx->r2 & 31);
L_80070158:
    // lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(0X0, ctx->r17);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD68($v1)
    ctx->r3 = MEM_W(0XD68, ctx->r3);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sllv        $s1, $v0, $v1
    ctx->r17 = S32(ctx->r2) << (ctx->r3 & 31);
    // sllv        $s2, $a0, $v1
    ctx->r18 = S32(ctx->r4) << (ctx->r3 & 31);
L_80070170:
    // lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // lw          $s4, 0xD5C($s4)
    ctx->r20 = MEM_W(0XD5C, ctx->r20);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s4, $v0, L_80070190
    if (ctx->r20 != ctx->r2) {
        // nop
    
        goto L_80070190;
    }
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xD5C($at)
    MEM_W(0XD5C, ctx->r1) = 0;
    // addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80070190:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD78($v0)
    ctx->r2 = MEM_W(0XD78, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800701BC
    if (ctx->r2 == 0) {
        // addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
        goto L_800701BC;
    }
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD78($v0)
    ctx->r2 = MEM_W(0XD78, ctx->r2);
    // nop

    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xD78($at)
    MEM_W(0XD78, ctx->r1) = 0;
L_800701BC:
    // sltiu       $v0, $s1, 0x401
    ctx->r2 = ctx->r17 < 0X401 ? 1 : 0;
L_800701C0:
    // beq         $v0, $zero, L_800701D0
    if (ctx->r2 == 0) {
        // addiu       $s0, $zero, 0x400
        ctx->r16 = ADD32(0, 0X400);
        goto L_800701D0;
    }
    // addiu       $s0, $zero, 0x400
    ctx->r16 = ADD32(0, 0X400);
    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_800701D0:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // jal         0x8006C248
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    _spu_t(rdram, ctx);
    goto after_1;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
    // jal         0x8006C248
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _spu_t(rdram, ctx);
    goto after_2;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, 0xEC0
    ctx->r5 = ADD32(ctx->r5, 0XEC0);
    // jal         0x8006C248
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    _spu_t(rdram, ctx);
    goto after_3;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xDA8($a0)
    ctx->r4 = MEM_W(0XDA8, ctx->r4);
    // addiu       $s1, $s1, -0x400
    ctx->r17 = ADD32(ctx->r17, -0X400);
    // jal         0x80077E24
    // addiu       $s2, $s2, 0x400
    ctx->r18 = ADD32(ctx->r18, 0X400);
    WaitEvent(rdram, ctx);
    goto after_4;
    // addiu       $s2, $s2, 0x400
    ctx->r18 = ADD32(ctx->r18, 0X400);
    after_4:
    // bne         $s3, $zero, L_800701C0
    if (ctx->r19 != 0) {
        // sltiu       $v0, $s1, 0x401
        ctx->r2 = ctx->r17 < 0X401 ? 1 : 0;
        goto L_800701C0;
    }
    // sltiu       $v0, $s1, 0x401
    ctx->r2 = ctx->r17 < 0X401 ? 1 : 0;
    // beq         $s5, $zero, L_80070224
    if (ctx->r21 == 0) {
        // nop
    
        goto L_80070224;
    }
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $s4, 0xD5C($at)
    MEM_W(0XD5C, ctx->r1) = ctx->r20;
L_80070224:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // beq         $v0, $zero, L_80070244
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80070244;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xD78($at)
    MEM_W(0XD78, ctx->r1) = ctx->r2;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80070244:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
