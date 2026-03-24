#include "recomp.h"
#include "disable_warnings.h"

void CD_ready(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x80077104
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
//    VSync(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // addiu       $fp, $fp, 0xA00
    ctx->r30 = ADD32(ctx->r30, 0XA00);
    // lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // addiu       $s5, $s5, 0xA80
    ctx->r21 = ADD32(ctx->r21, 0XA80);
    // lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // addiu       $s2, $s2, 0xCB8
    ctx->r18 = ADD32(ctx->r18, 0XCB8);
    // addiu       $s6, $s2, 0x1
    ctx->r22 = ADD32(ctx->r18, 0X1);
    // addiu       $s4, $s2, 0x2
    ctx->r20 = ADD32(ctx->r18, 0X2);
    // addiu       $v0, $v0, 0x3C0
    ctx->r2 = ADD32(ctx->r2, 0X3C0);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, 0x6188($at)
    MEM_W(0X6188, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x3B8C
    ctx->r2 = ADD32(ctx->r2, 0X3B8C);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $zero, 0x618C($at)
    MEM_W(0X618C, ctx->r1) = 0;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->r2;
L_80069B20:
    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
//    VSync(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_1:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, 0x6188($v1)
    ctx->r3 = MEM_W(0X6188, ctx->r3);
    // nop

    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_80069B6C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80069B6C;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, 0x618C($v0)
    ctx->r2 = MEM_W(0X618C, ctx->r2);
    // nop

    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, 0x618C($at)
    MEM_W(0X618C, ctx->r1) = ctx->r2;
    // lui         $v0, 0x3C
    ctx->r2 = S32(0X3C << 16);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80069BD4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80069BD4;
    }
    // nop

L_80069B6C:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078A3C
    // addiu       $a0, $a0, 0x3AFC
    ctx->r4 = ADD32(ctx->r4, 0X3AFC);
    sub_80078A3C(rdram, ctx);
    goto after_2;
    // addiu       $a0, $a0, 0x3AFC
    ctx->r4 = ADD32(ctx->r4, 0X3AFC);
    after_2:
    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(0X1, ctx->r18);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // lw          $a1, 0x6190($a1)
    ctx->r5 = MEM_W(0X6190, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lbu         $v0, 0x9F9($v0)
    ctx->r2 = MEM_BU(0X9F9, ctx->r2);
    // addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(0X0, ctx->r2);
    // lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(0X0, ctx->r4);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a0, $a0, 0x3B0C
    ctx->r4 = ADD32(ctx->r4, 0X3B0C);
    printf(rdram, ctx);
    goto after_3;
    // addiu       $a0, $a0, 0x3B0C
    ctx->r4 = ADD32(ctx->r4, 0X3B0C);
    after_3:
    // jal         0x8006A1FC
    // nop

    CD_flush(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // j           L_80069BD8
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80069BD8;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80069BD4:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80069BD8:
    // bne         $v0, $zero, L_80069D38
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80069D38;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // jal         0x80077468
    // nop

    CheckCallback(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // beq         $v0, $zero, L_80069C90
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80069C90;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA0($v0)
    ctx->r2 = MEM_W(0XCA0, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $s1, $v0, 0x3
    ctx->r17 = ctx->r2 & 0X3;
L_80069C08:
    // jal         0x800692C4
    // nop

    sub_800692C4(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80069C80
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x4
        ctx->r2 = ctx->r16 & 0X4;
        goto L_80069C80;
    }
    // andi        $v0, $s0, 0x4
    ctx->r2 = ctx->r16 & 0X4;
    // beq         $v0, $zero, L_80069C4C
    if (ctx->r2 == 0) {
        // andi        $v0, $s0, 0x2
        ctx->r2 = ctx->r16 & 0X2;
        goto L_80069C4C;
    }
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9DC($v0)
    ctx->r2 = MEM_W(0X9DC, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80069C48
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80069C48;
    }
    // nop

    // lbu         $a0, 0x0($s6)
    ctx->r4 = MEM_BU(0X0, ctx->r22);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // jalr        $v0
    // addiu       $a1, $a1, 0x6178
    ctx->r5 = ADD32(ctx->r5, 0X6178);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_7;
    // addiu       $a1, $a1, 0x6178
    ctx->r5 = ADD32(ctx->r5, 0X6178);
    after_7:
L_80069C48:
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
L_80069C4C:
    // beq         $v0, $zero, L_80069C08
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80069C08;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9D8($v0)
    ctx->r2 = MEM_W(0X9D8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80069C08
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80069C08;
    }
    // nop

    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // jalr        $v0
    // addiu       $a1, $a1, 0x6170
    ctx->r5 = ADD32(ctx->r5, 0X6170);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_8;
    // addiu       $a1, $a1, 0x6170
    ctx->r5 = ADD32(ctx->r5, 0X6170);
    after_8:
    // j           L_80069C08
    // nop

    goto L_80069C08;
    // nop

L_80069C80:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA0($v0)
    ctx->r2 = MEM_W(0XCA0, ctx->r2);
    // nop

    // sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
L_80069C90:
    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // nop

    // andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // beq         $a2, $zero, L_80069CE0
    if (ctx->r6 == 0) {
        // nop
    
        goto L_80069CE0;
    }
    // nop

    // sb          $zero, 0x2($s2)
    MEM_B(0X2, ctx->r18) = 0;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0x6180
    ctx->r4 = ADD32(ctx->r4, 0X6180);
    // beq         $s3, $zero, L_80069D28
    if (ctx->r19 == 0) {
        // addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
        goto L_80069D28;
    }
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80069CC0:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // bne         $v1, $a3, L_80069CC0
    if (ctx->r3 != ctx->r7) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80069CC0;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // j           L_80069D38
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    goto L_80069D38;
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_80069CE0:
    // lbu         $v0, -0x1($s4)
    ctx->r2 = MEM_BU(-0X1, ctx->r20);
    // nop

    // andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // beq         $a2, $zero, L_80069D30
    if (ctx->r6 == 0) {
        // nop
    
        goto L_80069D30;
    }
    // nop

    // sb          $zero, 0x1($s2)
    MEM_B(0X1, ctx->r18) = 0;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0x6178
    ctx->r4 = ADD32(ctx->r4, 0X6178);
    // beq         $a1, $zero, L_80069D28
    if (ctx->r5 == 0) {
        // addiu       $v1, $zero, 0x7
        ctx->r3 = ADD32(0, 0X7);
        goto L_80069D28;
    }
    // addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80069D10:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // bne         $v1, $a3, L_80069D10
    if (ctx->r3 != ctx->r7) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80069D10;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80069D28:
    // j           L_80069D38
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    goto L_80069D38;
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_80069D30:
    // beq         $s7, $zero, L_80069B20
    if (ctx->r23 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80069B20;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80069D38:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
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
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
