#include "recomp.h"
#include "disable_warnings.h"

void CdCheckISO9660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // addiu       $s0, $s0, 0x7DA8
    ctx->r16 = ADD32(ctx->r16, 0X7DA8);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // jal         0x8006B320
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    CdReadSector(rdram, ctx);
    goto after_0;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    after_0:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $s1, $v0, L_8006AD90
    if (ctx->r17 == ctx->r2) {
        // addiu       $a0, $s0, 0x1
        ctx->r4 = ADD32(ctx->r16, 0X1);
        goto L_8006AD90;
    }
    // addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9E4($v0)
    ctx->r2 = MEM_W(0X9E4, ctx->r2);
    // nop

    // blez        $v0, L_8006AFB8
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8006AFB8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a0, $a0, 0x3C9C
    ctx->r4 = ADD32(ctx->r4, 0X3C9C);
    printf(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, 0x3C9C
    ctx->r4 = ADD32(ctx->r4, 0X3C9C);
    after_1:
    // j           L_8006AFB8
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8006AFB8;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006AD90:
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // addiu       $a1, $a1, 0x3CC8
    ctx->r5 = ADD32(ctx->r5, 0X3CC8);
    // jal         0x80078A84
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    strncmp(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_2:
    // beq         $v0, $zero, L_8006ADD0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006ADD0;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9E4($v0)
    ctx->r2 = MEM_W(0X9E4, ctx->r2);
    // nop

    // blez        $v0, L_8006AFB8
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8006AFB8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a0, $a0, 0x3CD0
    ctx->r4 = ADD32(ctx->r4, 0X3CD0);
    printf(rdram, ctx);
    goto after_3;
    // addiu       $a0, $a0, 0x3CD0
    ctx->r4 = ADD32(ctx->r4, 0X3CD0);
    after_3:
    // j           L_8006AFB8
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8006AFB8;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006ADD0:
    // lwl         $v0, 0x8F($s0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X8F, ctx->r16);
    // lwr         $v0, 0x8C($s0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X8C, ctx->r16);
    // nop

    // swl         $v0, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r2);
    // swr         $v0, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r2);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(0X18, ctx->r29);
    // jal         0x8006B320
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    CdReadSector(rdram, ctx);
    goto after_4;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_4:
    // beq         $v0, $s1, L_8006AE28
    if (ctx->r2 == ctx->r17) {
        // nop
    
        goto L_8006AE28;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9E4($v0)
    ctx->r2 = MEM_W(0X9E4, ctx->r2);
    // nop

    // blez        $v0, L_8006AFB8
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8006AFB8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(0X18, ctx->r29);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a0, $a0, 0x3D00
    ctx->r4 = ADD32(ctx->r4, 0X3D00);
    printf(rdram, ctx);
    goto after_5;
    // addiu       $a0, $a0, 0x3D00
    ctx->r4 = ADD32(ctx->r4, 0X3D00);
    after_5:
    // j           L_8006AFB8
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8006AFB8;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006AE28:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9E4($v0)
    ctx->r2 = MEM_W(0X9E4, ctx->r2);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8006AE4C
    if (ctx->r2 != 0) {
        // addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
        goto L_8006AE4C;
    }
    // addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a0, $a0, 0x3D24
    ctx->r4 = ADD32(ctx->r4, 0X3D24);
    printf(rdram, ctx);
    goto after_6;
    // addiu       $a0, $a0, 0x3D24
    ctx->r4 = ADD32(ctx->r4, 0X3D24);
    after_6:
L_8006AE4C:
    // addiu       $v1, $s1, 0x800
    ctx->r3 = ADD32(ctx->r17, 0X800);
    // sltu        $v0, $s1, $v1
    ctx->r2 = ctx->r17 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8006AF60
    if (ctx->r2 == 0) {
        // addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
        goto L_8006AF60;
    }
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $s4, 0x801E
    ctx->r20 = S32(0X801E << 16);
    // addiu       $s4, $s4, 0x67B0
    ctx->r20 = ADD32(ctx->r20, 0X67B0);
    // addiu       $s6, $s4, 0x4
    ctx->r22 = ADD32(ctx->r20, 0X4);
    // addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
L_8006AE6C:
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8006AF60
    if (ctx->r2 == 0) {
        // sll         $v0, $a3, 1
        ctx->r2 = S32(ctx->r7) << 1;
        goto L_8006AF60;
    }
    // sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7) << 1;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2) << 2;
    // addu        $v0, $s0, $s4
    ctx->r2 = ADD32(ctx->r16, ctx->r20);
    // lwl         $v1, 0x5($s1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X5, ctx->r17);
    // lwr         $v1, 0x2($s1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X2, ctx->r17);
    // nop

    // swl         $v1, 0x3($v0)
    do_swl(rdram, 0X3, ctx->r2, ctx->r3);
    // swr         $v1, 0x0($v0)
    do_swr(rdram, 0X0, ctx->r2, ctx->r3);
    // addu        $s2, $s0, $s6
    ctx->r18 = ADD32(ctx->r16, ctx->r22);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(0X6, ctx->r17);
    // addiu       $s3, $a3, 0x1
    ctx->r19 = ADD32(ctx->r7, 0X1);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // sw          $s3, 0x67A8($at)
    MEM_W(0X67A8, ctx->r1) = ctx->r19;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // sw          $v0, 0x67AC($at)
    MEM_W(0X67AC, ctx->r1) = ctx->r2;
    // lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(0X0, ctx->r17);
    // jal         0x80078AA4
    // addiu       $a1, $s1, 0x8
    ctx->r5 = ADD32(ctx->r17, 0X8);
    memcpy_recomp(rdram, ctx);
    goto after_7;
    // addiu       $a1, $s1, 0x8
    ctx->r5 = ADD32(ctx->r17, 0X8);
    after_7:
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // nop

    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9E4($v0)
    ctx->r2 = MEM_W(0X9E4, ctx->r2);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8006AF48
    if (ctx->r2 != 0) {
        // addu        $s1, $s1, $v1
        ctx->r17 = ADD32(ctx->r17, ctx->r3);
        goto L_8006AF48;
    }
    // addu        $s1, $s1, $v1
    ctx->r17 = ADD32(ctx->r17, ctx->r3);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // lw          $a1, 0x67B0($a1)
    ctx->r5 = MEM_W(0X67B0, ctx->r5);
    // lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // lw          $a2, 0x67A8($a2)
    ctx->r6 = MEM_W(0X67A8, ctx->r6);
    // lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    // lw          $a3, 0x67AC($a3)
    ctx->r7 = MEM_W(0X67AC, ctx->r7);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3D44
    ctx->r4 = ADD32(ctx->r4, 0X3D44);
    // jal         0x80078AD4
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    printf(rdram, ctx);
    goto after_8;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_8:
L_8006AF48:
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // slti        $v0, $a3, 0x80
    ctx->r2 = SIGNED(ctx->r7) < 0X80 ? 1 : 0;
    // beq         $v0, $zero, L_8006AF88
    if (ctx->r2 == 0) {
        // sltu        $v0, $s1, $s5
        ctx->r2 = ctx->r17 < ctx->r21 ? 1 : 0;
        goto L_8006AF88;
    }
    // sltu        $v0, $s1, $s5
    ctx->r2 = ctx->r17 < ctx->r21 ? 1 : 0;
    // bne         $v0, $zero, L_8006AE6C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006AE6C;
    }
    // nop

L_8006AF60:
    // slti        $v0, $a3, 0x80
    ctx->r2 = SIGNED(ctx->r7) < 0X80 ? 1 : 0;
    // beq         $v0, $zero, L_8006AF88
    if (ctx->r2 == 0) {
        // sll         $v0, $a3, 1
        ctx->r2 = S32(ctx->r7) << 1;
        goto L_8006AF88;
    }
    // sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7) << 1;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sw          $zero, 0x67AC($at)
    MEM_W(0X67AC, ctx->r1) = 0;
L_8006AF88:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9E4($v0)
    ctx->r2 = MEM_W(0X9E4, ctx->r2);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xCF0($at)
    MEM_W(0XCF0, ctx->r1) = 0;
    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8006AFB8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8006AFB8;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3D58
    ctx->r4 = ADD32(ctx->r4, 0X3D58);
    // jal         0x80078AD4
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    printf(rdram, ctx);
    goto after_9;
    // addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    after_9:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006AFB8:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
