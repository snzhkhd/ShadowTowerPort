#include "recomp.h"
#include "disable_warnings.h"

void sub_800692C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCA0($v1)
    ctx->r3 = MEM_W(0XCA0, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xCAC($a0)
    ctx->r4 = MEM_W(0XCAC, ctx->r4);
    // nop

    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // nop

    // beq         $v0, $zero, L_80069808
    if (ctx->r2 == 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_80069808;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // j           L_80069328
    // nop

    goto L_80069328;
    // nop

L_80069318:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
L_80069328:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // lbu         $v1, 0x10($sp)
    ctx->r3 = MEM_BU(0X10, ctx->r29);
    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // bne         $v1, $v0, L_80069318
    if (ctx->r3 != ctx->r2) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80069318;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_80069340:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA0($v0)
    ctx->r2 = MEM_W(0XCA0, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_80069384
    if (ctx->r2 == 0) {
        // addu        $v1, $a0, $s0
        ctx->r3 = ADD32(ctx->r4, ctx->r16);
        goto L_80069384;
    }
    // addu        $v1, $a0, $s0
    ctx->r3 = ADD32(ctx->r4, ctx->r16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA4($v0)
    ctx->r2 = MEM_W(0XCA4, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_80069340
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80069340;
    }
    // nop

L_80069384:
    // slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_800693AC
    if (ctx->r2 == 0) {
        // addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
        goto L_800693AC;
    }
    // addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
L_80069398:
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_80069398
    if (ctx->r2 != 0) {
        // addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
        goto L_80069398;
    }
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
L_800693AC:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCA0($v1)
    ctx->r3 = MEM_W(0XCA0, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCAC($v0)
    ctx->r2 = MEM_W(0XCAC, ctx->r2);
    // addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA8($v0)
    ctx->r2 = MEM_W(0XCA8, ctx->r2);
    // nop

    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lbu         $v1, 0x10($sp)
    ctx->r3 = MEM_BU(0X10, ctx->r29);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $v1, $v0, L_80069414
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80069414;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lbu         $v0, 0x9F9($v0)
    ctx->r2 = MEM_BU(0X9F9, ctx->r2);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0xBA0($at)
    ctx->r2 = MEM_W(0XBA0, ctx->r1);
    // nop

    // beq         $v0, $zero, L_80069478
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80069478;
    }
    // nop

L_80069414:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9E8($v0)
    ctx->r2 = MEM_W(0X9E8, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // bne         $v0, $zero, L_80069458
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80069458;
    }
    // nop

    // lbu         $v0, 0x18($sp)
    ctx->r2 = MEM_BU(0X18, ctx->r29);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_80069458
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80069458;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9F0($v0)
    ctx->r2 = MEM_W(0X9F0, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x9F0($at)
    MEM_W(0X9F0, ctx->r1) = ctx->r2;
L_80069458:
    // lbu         $v0, 0x18($sp)
    ctx->r2 = MEM_BU(0X18, ctx->r29);
    // lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(0X19, ctx->r29);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // andi        $s1, $v0, 0x1D
    ctx->r17 = ctx->r2 & 0X1D;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x9E8($at)
    MEM_W(0X9E8, ctx->r1) = ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, 0x9EC($at)
    MEM_W(0X9EC, ctx->r1) = ctx->r3;
L_80069478:
    // lbu         $v1, 0x10($sp)
    ctx->r3 = MEM_BU(0X10, ctx->r29);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $v1, $v0, L_800694F0
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800694F0;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9E4($v0)
    ctx->r2 = MEM_W(0X9E4, ctx->r2);
    // nop

    // blez        $v0, L_800694F0
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_800694F0;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a0, $a0, 0x3B28
    ctx->r4 = ADD32(ctx->r4, 0X3B28);
    printf(rdram, ctx);
    goto after_0;
    // addiu       $a0, $a0, 0x3B28
    ctx->r4 = ADD32(ctx->r4, 0X3B28);
    after_0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9E4($v0)
    ctx->r2 = MEM_W(0X9E4, ctx->r2);
    // nop

    // blez        $v0, L_800694F0
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_800694F0;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lbu         $v0, 0x9F9($v0)
    ctx->r2 = MEM_BU(0X9F9, ctx->r2);
    // lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // lw          $a2, 0x9E8($a2)
    ctx->r6 = MEM_W(0X9E8, ctx->r6);
    // lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // lw          $a3, 0x9EC($a3)
    ctx->r7 = MEM_W(0X9EC, ctx->r7);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // lw          $a1, 0xA00($a1)
    ctx->r5 = MEM_W(0XA00, ctx->r5);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a0, $a0, 0x3B34
    ctx->r4 = ADD32(ctx->r4, 0X3B34);
    printf(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, 0x3B34
    ctx->r4 = ADD32(ctx->r4, 0X3B34);
    after_1:
L_800694F0:
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // nop

    // addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_800697EC
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_800697EC;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addu        $at, $at, $v0
    gpr jr_addend_80069518;
    jr_addend_80069518 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x3B70($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80069518 >> 2) {
        case 0: goto L_8006966C; break;
        case 1: goto L_80069620; break;
        case 2: goto L_80069520; break;
        case 3: goto L_800696EC; break;
        case 4: goto L_8006976C; break;
        default: switch_error(__func__, 0x80069518, 0x80013B70);
    }
    // nop

L_80069520:
    // beq         $s1, $zero, L_8006956C
    if (ctx->r17 == 0) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_8006956C;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0xCB8
    ctx->r3 = ADD32(ctx->r3, 0XCB8);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, 0x6170
    ctx->r3 = ADD32(ctx->r3, 0X6170);
    // beq         $v1, $zero, L_80069664
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_80069664;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8006954C:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_8006954C
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8006954C;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // j           L_8006980C
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    goto L_8006980C;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8006956C:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lbu         $v0, 0x9F9($v0)
    ctx->r2 = MEM_BU(0X9F9, ctx->r2);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0xAA0($at)
    ctx->r2 = MEM_W(0XAA0, ctx->r1);
    // nop

    // beq         $v0, $zero, L_800695D8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_800695D8;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0xCB8
    ctx->r3 = ADD32(ctx->r3, 0XCB8);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, 0x6170
    ctx->r3 = ADD32(ctx->r3, 0X6170);
    // beq         $v1, $zero, L_800695D0
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_800695D0;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800695B8:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_800695B8
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_800695B8;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800695D0:
    // j           L_8006980C
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_8006980C;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800695D8:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0xCB8
    ctx->r3 = ADD32(ctx->r3, 0XCB8);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, 0x6170
    ctx->r3 = ADD32(ctx->r3, 0X6170);
    // beq         $v1, $zero, L_80069664
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_80069664;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80069600:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_80069600
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80069600;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // j           L_8006980C
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    goto L_8006980C;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80069620:
    // beq         $s1, $zero, L_8006962C
    if (ctx->r17 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8006962C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8006962C:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sb          $v0, 0xCB8($at)
    MEM_B(0XCB8, ctx->r1) = ctx->r2;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, 0x6170
    ctx->r3 = ADD32(ctx->r3, 0X6170);
    // beq         $v1, $zero, L_80069664
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_80069664;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8006964C:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_8006964C
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8006964C;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80069664:
    // j           L_8006980C
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    goto L_8006980C;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8006966C:
    // beq         $s1, $zero, L_80069680
    if (ctx->r17 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80069680;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s0, $v0, L_80069680
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_80069680;
    }
    // nop

    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80069680:
    // beq         $s1, $zero, L_8006968C
    if (ctx->r17 == 0) {
        // addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
        goto L_8006968C;
    }
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_8006968C:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0xCB8
    ctx->r2 = ADD32(ctx->r2, 0XCB8);
    // sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, 0x6178
    ctx->r3 = ADD32(ctx->r3, 0X6178);
    // beq         $v1, $zero, L_800696C8
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_800696C8;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800696B0:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_800696B0
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_800696B0;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800696C8:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA0($v0)
    ctx->r2 = MEM_W(0XCA0, ctx->r2);
    // nop

    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xCAC($v1)
    ctx->r3 = MEM_W(0XCAC, ctx->r3);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // j           L_8006980C
    // sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    goto L_8006980C;
    // sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_800696EC:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0x6180
    ctx->r4 = ADD32(ctx->r4, 0X6180);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0xCB8
    ctx->r2 = ADD32(ctx->r2, 0XCB8);
    // addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(0X2, ctx->r2);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // beq         $a0, $zero, L_80069734
    if (ctx->r4 == 0) {
        // addiu       $v1, $zero, 0x7
        ctx->r3 = ADD32(0, 0X7);
        goto L_80069734;
    }
    // addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8006971C:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // bne         $v1, $a2, L_8006971C
    if (ctx->r3 != ctx->r6) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_8006971C;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80069734:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, 0x6178
    ctx->r3 = ADD32(ctx->r3, 0X6178);
    // beq         $v1, $zero, L_80069764
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_80069764;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8006974C:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_8006974C
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8006974C;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80069764:
    // j           L_8006980C
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    goto L_8006980C;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8006976C:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0x6170
    ctx->r4 = ADD32(ctx->r4, 0X6170);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0xCB8
    ctx->r2 = ADD32(ctx->r2, 0XCB8);
    // addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(0X1, ctx->r2);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // beq         $a0, $zero, L_800697B4
    if (ctx->r4 == 0) {
        // addiu       $v1, $zero, 0x7
        ctx->r3 = ADD32(0, 0X7);
        goto L_800697B4;
    }
    // addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8006979C:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // bne         $v1, $a2, L_8006979C
    if (ctx->r3 != ctx->r6) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_8006979C;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800697B4:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, 0x6178
    ctx->r3 = ADD32(ctx->r3, 0X6178);
    // beq         $v1, $zero, L_800697E4
    if (ctx->r3 == 0) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_800697E4;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800697CC:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // bne         $a0, $a2, L_800697CC
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_800697CC;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800697E4:
    // j           L_8006980C
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    goto L_8006980C;
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800697EC:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078A3C
    // addiu       $a0, $a0, 0x3B50
    ctx->r4 = ADD32(ctx->r4, 0X3B50);
    sub_80078A3C(rdram, ctx);
    goto after_2;
    // addiu       $a0, $a0, 0x3B50
    ctx->r4 = ADD32(ctx->r4, 0X3B50);
    after_2:
    // lbu         $a1, 0x10($sp)
    ctx->r5 = MEM_BU(0X10, ctx->r29);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a0, $a0, 0x3B64
    ctx->r4 = ADD32(ctx->r4, 0X3B64);
    printf(rdram, ctx);
    goto after_3;
    // addiu       $a0, $a0, 0x3B64
    ctx->r4 = ADD32(ctx->r4, 0X3B64);
    after_3:
L_80069808:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006980C:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
