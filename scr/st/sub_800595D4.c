#include "recomp.h"
#include "disable_warnings.h"

void sub_800595D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x7E00
    ctx->r2 = ADD32(ctx->r2, -0X7E00);
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s4, $v0, 0x76F8
    ctx->r20 = ADD32(ctx->r2, 0X76F8);
    // addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x42($v0)
    ctx->r3 = MEM_HU(0X42, ctx->r2);
    // lhu         $a0, 0x5E($v0)
    ctx->r4 = MEM_HU(0X5E, ctx->r2);
    // lhu         $a1, 0x4E($v0)
    ctx->r5 = MEM_HU(0X4E, ctx->r2);
    // lhu         $a2, 0x60($v0)
    ctx->r6 = MEM_HU(0X60, ctx->r2);
    // lhu         $a3, 0x5C($v0)
    ctx->r7 = MEM_HU(0X5C, ctx->r2);
    // addiu       $v0, $s3, 0xA88
    ctx->r2 = ADD32(ctx->r19, 0XA88);
    // sw          $v0, 0xA84($s3)
    MEM_W(0XA84, ctx->r19) = ctx->r2;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
L_80059658:
    // ori         $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 | 0X2000;
    // addiu       $v0, $s1, 0x800
    ctx->r2 = ADD32(ctx->r17, 0X800);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_80059684
    if (ctx->r3 == 0) {
        // sll         $v0, $s2, 2
        ctx->r2 = S32(ctx->r18) << 2;
        goto L_80059684;
    }
    // sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18) << 2;
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // addiu       $v0, $s3, 0xA88
    ctx->r2 = ADD32(ctx->r19, 0XA88);
    // sw          $v0, 0xA84($s3)
    MEM_W(0XA84, ctx->r19) = ctx->r2;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18) << 2;
L_80059684:
    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(0X10, ctx->r2);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_800596EC
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
        goto L_800596EC;
    }
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
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
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // lbu         $a1, 0x11D($v0)
    ctx->r5 = MEM_BU(0X11D, ctx->r2);
    // lw          $a2, 0xA84($s3)
    ctx->r6 = MEM_W(0XA84, ctx->r19);
    // jal         0x80016030
    // addiu       $a1, $a1, 0x190
    ctx->r5 = ADD32(ctx->r5, 0X190);
    sub_80016030(rdram, ctx);
    goto after_1;
    // addiu       $a1, $a1, 0x190
    ctx->r5 = ADD32(ctx->r5, 0X190);
    after_1:
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // lw          $a0, 0xA84($s3)
    ctx->r4 = MEM_W(0XA84, ctx->r19);
    // jal         0x8003EC5C
    // sll         $s0, $v0, 11
    ctx->r16 = S32(ctx->r2) << 11;
    sub_8003EC5C(rdram, ctx);
    goto after_2;
    // sll         $s0, $v0, 11
    ctx->r16 = S32(ctx->r2) << 11;
    after_2:
    // lw          $v0, 0xA84($s3)
    ctx->r2 = MEM_W(0XA84, ctx->r19);
    // addu        $s1, $s1, $s0
    ctx->r17 = ADD32(ctx->r17, ctx->r16);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // j           L_8005971C
    // sw          $v0, 0xA84($s3)
    MEM_W(0XA84, ctx->r19) = ctx->r2;
    goto L_8005971C;
    // sw          $v0, 0xA84($s3)
    MEM_W(0XA84, ctx->r19) = ctx->r2;
L_800596EC:
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // lhu         $v0, 0x28($sp)
    ctx->r2 = MEM_HU(0X28, ctx->r29);
    // lhu         $t0, 0x2A($sp)
    ctx->r8 = MEM_HU(0X2A, ctx->r29);
    // addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // sh          $v1, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r3;
    // sh          $v1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r3;
    // sh          $v0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r2;
    // jal         0x80079BE4
    // sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    ClearImage(rdram, ctx);
    goto after_3;
    // sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    after_3:
L_8005971C:
    // lhu         $v0, 0x2A($sp)
    ctx->r2 = MEM_HU(0X2A, ctx->r29);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // slti        $v0, $s2, 0x5
    ctx->r2 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80059658
    if (ctx->r2 != 0) {
        // lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
        goto L_80059658;
    }
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(0X4C, ctx->r29);
    // lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(0X48, ctx->r29);
    // lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(0X44, ctx->r29);
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
