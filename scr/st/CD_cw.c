#include "recomp.h"
#include "disable_warnings.h"

void CD_cw(uint8_t* rdram, recomp_context* ctx) 
{
    ctx->r2 = 1; // всегда успех
    uint8_t cmd = (uint8_t)ctx->r4;
    printf("[CD_cw_8004DBE0] cmd=0x%02X\n", cmd);

//
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x9E4($v0)
//    ctx->r2 = MEM_W(0X9E4, ctx->r2);
//    // addiu       $sp, $sp, -0x38
//    ctx->r29 = ADD32(ctx->r29, -0X38);
//    // sw          $s0, 0x18($sp)
//    MEM_W(0X18, ctx->r29) = ctx->r16;
//    // addu        $s0, $a1, $zero
//    ctx->r16 = ADD32(ctx->r5, 0);
//    // sw          $s6, 0x30($sp)
//    MEM_W(0X30, ctx->r29) = ctx->r22;
//    // addu        $s6, $a2, $zero
//    ctx->r22 = ADD32(ctx->r6, 0);
//    // sw          $s2, 0x20($sp)
//    MEM_W(0X20, ctx->r29) = ctx->r18;
//    // addu        $s2, $a3, $zero
//    ctx->r18 = ADD32(ctx->r7, 0);
//    // sw          $s1, 0x1C($sp)
//    MEM_W(0X1C, ctx->r29) = ctx->r17;
//    // addu        $s1, $a0, $zero
//    ctx->r17 = ADD32(ctx->r4, 0);
//    // sw          $ra, 0x34($sp)
//    MEM_W(0X34, ctx->r29) = ctx->r31;
//    // sw          $s5, 0x2C($sp)
//    MEM_W(0X2C, ctx->r29) = ctx->r21;
//    // sw          $s4, 0x28($sp)
//    MEM_W(0X28, ctx->r29) = ctx->r20;
//    // slti        $v0, $v0, 0x2
//    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
//    // bne         $v0, $zero, L_80069DCC
//    if (ctx->r2 != 0) {
//        // sw          $s3, 0x24($sp)
//        MEM_W(0X24, ctx->r29) = ctx->r19;
//        goto L_80069DCC;
//    }
//    // sw          $s3, 0x24($sp)
//    MEM_W(0X24, ctx->r29) = ctx->r19;
//    // andi        $v0, $s1, 0xFF
//    ctx->r2 = ctx->r17 & 0XFF;
//    // sll         $v0, $v0, 2
//    ctx->r2 = S32(ctx->r2) << 2;
//    // lui         $a1, 0x8008
//    ctx->r5 = S32(0X8008 << 16);
//    // addu        $a1, $a1, $v0
//    ctx->r5 = ADD32(ctx->r5, ctx->r2);
//    // lw          $a1, 0xA00($a1)
//    ctx->r5 = MEM_W(0XA00, ctx->r5);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // jal         0x80078AD4
//    // addiu       $a0, $a0, 0x3B98
//    ctx->r4 = ADD32(ctx->r4, 0X3B98);
//    printf(rdram, ctx);
//    goto after_0;
//    // addiu       $a0, $a0, 0x3B98
//    ctx->r4 = ADD32(ctx->r4, 0X3B98);
//    after_0:
//L_80069DCC:
//    // andi        $v0, $s1, 0xFF
//    ctx->r2 = ctx->r17 & 0XFF;
//    // sll         $v1, $v0, 2
//    ctx->r3 = S32(ctx->r2) << 2;
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // addu        $v0, $v0, $v1
//    ctx->r2 = ADD32(ctx->r2, ctx->r3);
//    // lw          $v0, 0xC20($v0)
//    ctx->r2 = MEM_W(0XC20, ctx->r2);
//    // nop
//
//    // beq         $v0, $zero, L_80069E28
//    if (ctx->r2 == 0) {
//        // addu        $a0, $zero, $zero
//        ctx->r4 = ADD32(0, 0);
//        goto L_80069E28;
//    }
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    // bne         $s0, $zero, L_80069E28
//    if (ctx->r16 != 0) {
//        // nop
//    
//        goto L_80069E28;
//    }
//    // nop
//
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x9E4($v0)
//    ctx->r2 = MEM_W(0X9E4, ctx->r2);
//    // nop
//
//    // blez        $v0, L_8006A14C
//    if (SIGNED(ctx->r2) <= 0) {
//        // addiu       $v0, $zero, -0x2
//        ctx->r2 = ADD32(0, -0X2);
//        goto L_8006A14C;
//    }
//    // addiu       $v0, $zero, -0x2
//    ctx->r2 = ADD32(0, -0X2);
//    // lui         $a1, 0x8008
//    ctx->r5 = S32(0X8008 << 16);
//    // addu        $a1, $a1, $v1
//    ctx->r5 = ADD32(ctx->r5, ctx->r3);
//    // lw          $a1, 0xA00($a1)
//    ctx->r5 = MEM_W(0XA00, ctx->r5);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // jal         0x80078AD4
//    // addiu       $a0, $a0, 0x3BA0
//    ctx->r4 = ADD32(ctx->r4, 0X3BA0);
//    printf(rdram, ctx);
//    goto after_1;
//    // addiu       $a0, $a0, 0x3BA0
//    ctx->r4 = ADD32(ctx->r4, 0X3BA0);
//    after_1:
//    // j           L_8006A14C
//    // addiu       $v0, $zero, -0x2
//    ctx->r2 = ADD32(0, -0X2);
//    goto L_8006A14C;
//    // addiu       $v0, $zero, -0x2
//    ctx->r2 = ADD32(0, -0X2);
//L_80069E28:
//    // jal         0x80069820
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    CD_sync(rdram, ctx);
//    goto after_2;
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    after_2:
//    // andi        $v1, $s1, 0xFF
//    ctx->r3 = ctx->r17 & 0XFF;
//    // addiu       $v0, $zero, 0x2
//    ctx->r2 = ADD32(0, 0X2);
//    // bne         $v1, $v0, L_80069E70
//    if (ctx->r3 != ctx->r2) {
//        // addiu       $v0, $zero, 0xE
//        ctx->r2 = ADD32(0, 0XE);
//        goto L_80069E70;
//    }
//    // addiu       $v0, $zero, 0xE
//    ctx->r2 = ADD32(0, 0XE);
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    // addu        $v0, $s0, $a0
//    ctx->r2 = ADD32(ctx->r16, ctx->r4);
//L_80069E48:
//    // lbu         $v0, 0x0($v0)
//    ctx->r2 = MEM_BU(0X0, ctx->r2);
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // addu        $at, $at, $a0
//    ctx->r1 = ADD32(ctx->r1, ctx->r4);
//    // sb          $v0, 0x9F4($at)
//    MEM_B(0X9F4, ctx->r1) = ctx->r2;
//    // addiu       $a0, $a0, 0x1
//    ctx->r4 = ADD32(ctx->r4, 0X1);
//    // slti        $v0, $a0, 0x4
//    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
//    // bne         $v0, $zero, L_80069E48
//    if (ctx->r2 != 0) {
//        // addu        $v0, $s0, $a0
//        ctx->r2 = ADD32(ctx->r16, ctx->r4);
//        goto L_80069E48;
//    }
//    // addu        $v0, $s0, $a0
//    ctx->r2 = ADD32(ctx->r16, ctx->r4);
//    // andi        $v1, $s1, 0xFF
//    ctx->r3 = ctx->r17 & 0XFF;
//    // addiu       $v0, $zero, 0xE
//    ctx->r2 = ADD32(0, 0XE);
//L_80069E70:
//    // bne         $v1, $v0, L_80069E84
//    if (ctx->r3 != ctx->r2) {
//        // nop
//    
//        goto L_80069E84;
//    }
//    // nop
//
//    // lbu         $v0, 0x0($s0)
//    ctx->r2 = MEM_BU(0X0, ctx->r16);
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // sb          $v0, 0x9F8($at)
//    MEM_B(0X9F8, ctx->r1) = ctx->r2;
//L_80069E84:
//    // lui         $a1, 0x8008
//    ctx->r5 = S32(0X8008 << 16);
//    // addiu       $a1, $a1, 0xCB8
//    ctx->r5 = ADD32(ctx->r5, 0XCB8);
//    // sll         $a0, $v1, 2
//    ctx->r4 = S32(ctx->r3) << 2;
//    // sb          $zero, 0x0($a1)
//    MEM_B(0X0, ctx->r5) = 0;
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // addu        $v0, $v0, $a0
//    ctx->r2 = ADD32(ctx->r2, ctx->r4);
//    // lw          $v0, 0xB20($v0)
//    ctx->r2 = MEM_W(0XB20, ctx->r2);
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // beq         $v0, $zero, L_80069EB0
//    if (ctx->r2 == 0) {
//        // addiu       $v1, $v1, 0xB20
//        ctx->r3 = ADD32(ctx->r3, 0XB20);
//        goto L_80069EB0;
//    }
//    // addiu       $v1, $v1, 0xB20
//    ctx->r3 = ADD32(ctx->r3, 0XB20);
//    // sb          $zero, 0x1($a1)
//    MEM_B(0X1, ctx->r5) = 0;
//L_80069EB0:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0xCA0($v0)
//    ctx->r2 = MEM_W(0XCA0, ctx->r2);
//    // nop
//
//    // sb          $zero, 0x0($v0)
//    MEM_B(0X0, ctx->r2) = 0;
//    // addiu       $v0, $v1, 0x100
//    ctx->r2 = ADD32(ctx->r3, 0X100);
//    // addu        $v1, $a0, $v0
//    ctx->r3 = ADD32(ctx->r4, ctx->r2);
//    // lw          $v0, 0x0($v1)
//    ctx->r2 = MEM_W(0X0, ctx->r3);
//    // nop
//
//    // blez        $v0, L_80069F08
//    if (SIGNED(ctx->r2) <= 0) {
//        // addu        $a0, $zero, $zero
//        ctx->r4 = ADD32(0, 0);
//        goto L_80069F08;
//    }
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    // addu        $a1, $v1, $zero
//    ctx->r5 = ADD32(ctx->r3, 0);
//    // addu        $v0, $s0, $a0
//    ctx->r2 = ADD32(ctx->r16, ctx->r4);
//L_80069EE0:
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lw          $v1, 0xCA8($v1)
//    ctx->r3 = MEM_W(0XCA8, ctx->r3);
//    // lbu         $v0, 0x0($v0)
//    ctx->r2 = MEM_BU(0X0, ctx->r2);
//    // nop
//
//    // sb          $v0, 0x0($v1)
//    MEM_B(0X0, ctx->r3) = ctx->r2;
//    // lw          $v0, 0x0($a1)
//    ctx->r2 = MEM_W(0X0, ctx->r5);
//    // addiu       $a0, $a0, 0x1
//    ctx->r4 = ADD32(ctx->r4, 0X1);
//    // slt         $v0, $a0, $v0
//    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
//    // bne         $v0, $zero, L_80069EE0
//    if (ctx->r2 != 0) {
//        // addu        $v0, $s0, $a0
//        ctx->r2 = ADD32(ctx->r16, ctx->r4);
//        goto L_80069EE0;
//    }
//    // addu        $v0, $s0, $a0
//    ctx->r2 = ADD32(ctx->r16, ctx->r4);
//L_80069F08:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0xCA4($v0)
//    ctx->r2 = MEM_W(0XCA4, ctx->r2);
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // sb          $s1, 0x9F9($at)
//    MEM_B(0X9F9, ctx->r1) = ctx->r17;
//    // sb          $s1, 0x0($v0)
//    MEM_B(0X0, ctx->r2) = ctx->r17;
//    // bne         $s2, $zero, L_8006A14C
//    if (ctx->r18 != 0) {
//        // addu        $v0, $zero, $zero
//        ctx->r2 = ADD32(0, 0);
//        goto L_8006A14C;
//    }
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    // jal         0x80077104
//    // addiu       $a0, $zero, -0x1
//    ctx->r4 = ADD32(0, -0X1);
//    VSync(rdram, ctx);
//    goto after_3;
//    // addiu       $a0, $zero, -0x1
//    ctx->r4 = ADD32(0, -0X1);
//    after_3:
//    // addiu       $v0, $v0, 0x3C0
//    ctx->r2 = ADD32(ctx->r2, 0X3C0);
//    // lui         $a0, 0x8008
//    ctx->r4 = S32(0X8008 << 16);
//    // addiu       $a0, $a0, 0xCB8
//    ctx->r4 = ADD32(ctx->r4, 0XCB8);
//    // lui         $at, 0x801E
//    ctx->r1 = S32(0X801E << 16);
//    // sw          $v0, 0x6188($at)
//    MEM_W(0X6188, ctx->r1) = ctx->r2;
//    // lui         $at, 0x801E
//    ctx->r1 = S32(0X801E << 16);
//    // sw          $zero, 0x618C($at)
//    MEM_W(0X618C, ctx->r1) = 0;
//    // lbu         $v1, 0x0($a0)
//    ctx->r3 = MEM_BU(0X0, ctx->r4);
//    // lui         $v0, 0x8001
//    ctx->r2 = S32(0X8001 << 16);
//    // addiu       $v0, $v0, 0x3BB0
//    ctx->r2 = ADD32(ctx->r2, 0X3BB0);
//    // lui         $at, 0x801E
//    ctx->r1 = S32(0X801E << 16);
//    // sw          $v0, 0x6190($at)
//    MEM_W(0X6190, ctx->r1) = ctx->r2;
//    // bne         $v1, $zero, L_8006A0FC
//    if (ctx->r3 != 0) {
//        // addu        $a2, $s6, $zero
//        ctx->r6 = ADD32(ctx->r22, 0);
//        goto L_8006A0FC;
//    }
//    // addu        $a2, $s6, $zero
//    ctx->r6 = ADD32(ctx->r22, 0);
//    // lui         $s5, 0x8008
//    ctx->r21 = S32(0X8008 << 16);
//    // addiu       $s5, $s5, 0xA00
//    ctx->r21 = ADD32(ctx->r21, 0XA00);
//    // lui         $s3, 0x8008
//    ctx->r19 = S32(0X8008 << 16);
//    // addiu       $s3, $s3, 0xA80
//    ctx->r19 = ADD32(ctx->r19, 0XA80);
//    // addu        $s2, $a0, $zero
//    ctx->r18 = ADD32(ctx->r4, 0);
//    // addiu       $s4, $s2, 0x1
//    ctx->r20 = ADD32(ctx->r18, 0X1);
//L_80069F7C:
//    // jal         0x80077104
//    // addiu       $a0, $zero, -0x1
//    ctx->r4 = ADD32(0, -0X1);
//    VSync(rdram, ctx);
//    goto after_4;
//    // addiu       $a0, $zero, -0x1
//    ctx->r4 = ADD32(0, -0X1);
//    after_4:
//    // lui         $v1, 0x801E
//    ctx->r3 = S32(0X801E << 16);
//    // lw          $v1, 0x6188($v1)
//    ctx->r3 = MEM_W(0X6188, ctx->r3);
//    // nop
//
//    // slt         $v1, $v1, $v0
//    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
//    // bne         $v1, $zero, L_80069FC8
//    if (ctx->r3 != 0) {
//        // nop
//    
//        goto L_80069FC8;
//    }
//    // nop
//
//    // lui         $v0, 0x801E
//    ctx->r2 = S32(0X801E << 16);
//    // lw          $v0, 0x618C($v0)
//    ctx->r2 = MEM_W(0X618C, ctx->r2);
//    // nop
//
//    // addu        $v1, $v0, $zero
//    ctx->r3 = ADD32(ctx->r2, 0);
//    // addiu       $v0, $v0, 0x1
//    ctx->r2 = ADD32(ctx->r2, 0X1);
//    // lui         $at, 0x801E
//    ctx->r1 = S32(0X801E << 16);
//    // sw          $v0, 0x618C($at)
//    MEM_W(0X618C, ctx->r1) = ctx->r2;
//    // lui         $v0, 0x3C
//    ctx->r2 = S32(0X3C << 16);
//    // slt         $v0, $v0, $v1
//    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
//    // beq         $v0, $zero, L_8006A030
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8006A030;
//    }
//    // nop
//
//L_80069FC8:
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // jal         0x80078A3C
//    // addiu       $a0, $a0, 0x3AFC
//    ctx->r4 = ADD32(ctx->r4, 0X3AFC);
//    sub_80078A3C(rdram, ctx);
//    goto after_5;
//    // addiu       $a0, $a0, 0x3AFC
//    ctx->r4 = ADD32(ctx->r4, 0X3AFC);
//    after_5:
//    // lbu         $a0, 0x0($s2)
//    ctx->r4 = MEM_BU(0X0, ctx->r18);
//    // lbu         $v0, 0x1($s2)
//    ctx->r2 = MEM_BU(0X1, ctx->r18);
//    // lui         $a1, 0x801E
//    ctx->r5 = S32(0X801E << 16);
//    // lw          $a1, 0x6190($a1)
//    ctx->r5 = MEM_W(0X6190, ctx->r5);
//    // sll         $v0, $v0, 2
//    ctx->r2 = S32(ctx->r2) << 2;
//    // addu        $v0, $v0, $s3
//    ctx->r2 = ADD32(ctx->r2, ctx->r19);
//    // sll         $a0, $a0, 2
//    ctx->r4 = S32(ctx->r4) << 2;
//    // lw          $v1, 0x0($v0)
//    ctx->r3 = MEM_W(0X0, ctx->r2);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lbu         $v0, 0x9F9($v0)
//    ctx->r2 = MEM_BU(0X9F9, ctx->r2);
//    // addu        $a0, $a0, $s3
//    ctx->r4 = ADD32(ctx->r4, ctx->r19);
//    // sll         $v0, $v0, 2
//    ctx->r2 = S32(ctx->r2) << 2;
//    // addu        $v0, $v0, $s5
//    ctx->r2 = ADD32(ctx->r2, ctx->r21);
//    // sw          $v1, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r3;
//    // lw          $a2, 0x0($v0)
//    ctx->r6 = MEM_W(0X0, ctx->r2);
//    // lw          $a3, 0x0($a0)
//    ctx->r7 = MEM_W(0X0, ctx->r4);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // jal         0x80078AD4
//    // addiu       $a0, $a0, 0x3B0C
//    ctx->r4 = ADD32(ctx->r4, 0X3B0C);
//    printf(rdram, ctx);
//    goto after_6;
//    // addiu       $a0, $a0, 0x3B0C
//    ctx->r4 = ADD32(ctx->r4, 0X3B0C);
//    after_6:
//    // jal         0x8006A1FC
//    // nop
//
//    CD_flush(rdram, ctx);
//    goto after_7;
//    // nop
//
//    after_7:
//    // j           L_8006A034
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    goto L_8006A034;
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//L_8006A030:
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//L_8006A034:
//    // bne         $v0, $zero, L_8006A14C
//    if (ctx->r2 != 0) {
//        // addiu       $v0, $zero, -0x1
//        ctx->r2 = ADD32(0, -0X1);
//        goto L_8006A14C;
//    }
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    // jal         0x80077468
//    // nop
//
//    CheckCallback(rdram, ctx);
//    goto after_8;
//    // nop
//
//    after_8:
//    // beq         $v0, $zero, L_8006A0EC
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8006A0EC;
//    }
//    // nop
//
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0xCA0($v0)
//    ctx->r2 = MEM_W(0XCA0, ctx->r2);
//    // nop
//
//    // lbu         $v0, 0x0($v0)
//    ctx->r2 = MEM_BU(0X0, ctx->r2);
//    // nop
//
//    // andi        $s1, $v0, 0x3
//    ctx->r17 = ctx->r2 & 0X3;
//L_8006A064:
//    // jal         0x800692C4
//    // nop
//
//    sub_800692C4(rdram, ctx);
//    goto after_9;
//    // nop
//
//    after_9:
//    // addu        $s0, $v0, $zero
//    ctx->r16 = ADD32(ctx->r2, 0);
//    // beq         $s0, $zero, L_8006A0DC
//    if (ctx->r16 == 0) {
//        // andi        $v0, $s0, 0x4
//        ctx->r2 = ctx->r16 & 0X4;
//        goto L_8006A0DC;
//    }
//    // andi        $v0, $s0, 0x4
//    ctx->r2 = ctx->r16 & 0X4;
//    // beq         $v0, $zero, L_8006A0A8
//    if (ctx->r2 == 0) {
//        // andi        $v0, $s0, 0x2
//        ctx->r2 = ctx->r16 & 0X2;
//        goto L_8006A0A8;
//    }
//    // andi        $v0, $s0, 0x2
//    ctx->r2 = ctx->r16 & 0X2;
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x9DC($v0)
//    ctx->r2 = MEM_W(0X9DC, ctx->r2);
//    // nop
//
//    // beq         $v0, $zero, L_8006A0A4
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8006A0A4;
//    }
//    // nop
//
//    // lbu         $a0, 0x0($s4)
//    ctx->r4 = MEM_BU(0X0, ctx->r20);
//    // lui         $a1, 0x801E
//    ctx->r5 = S32(0X801E << 16);
//    // jalr        $v0
//    // addiu       $a1, $a1, 0x6178
//    ctx->r5 = ADD32(ctx->r5, 0X6178);
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_10;
//    // addiu       $a1, $a1, 0x6178
//    ctx->r5 = ADD32(ctx->r5, 0X6178);
//    after_10:
//L_8006A0A4:
//    // andi        $v0, $s0, 0x2
//    ctx->r2 = ctx->r16 & 0X2;
//L_8006A0A8:
//    // beq         $v0, $zero, L_8006A064
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8006A064;
//    }
//    // nop
//
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x9D8($v0)
//    ctx->r2 = MEM_W(0X9D8, ctx->r2);
//    // nop
//
//    // beq         $v0, $zero, L_8006A064
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8006A064;
//    }
//    // nop
//
//    // lbu         $a0, 0x0($s2)
//    ctx->r4 = MEM_BU(0X0, ctx->r18);
//    // lui         $a1, 0x801E
//    ctx->r5 = S32(0X801E << 16);
//    // jalr        $v0
//    // addiu       $a1, $a1, 0x6170
//    ctx->r5 = ADD32(ctx->r5, 0X6170);
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_11;
//    // addiu       $a1, $a1, 0x6170
//    ctx->r5 = ADD32(ctx->r5, 0X6170);
//    after_11:
//    // j           L_8006A064
//    // nop
//
//    goto L_8006A064;
//    // nop
//
//L_8006A0DC:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0xCA0($v0)
//    ctx->r2 = MEM_W(0XCA0, ctx->r2);
//    // nop
//
//    // sb          $s1, 0x0($v0)
//    MEM_B(0X0, ctx->r2) = ctx->r17;
//L_8006A0EC:
//    // lbu         $v0, 0x0($s2)
//    ctx->r2 = MEM_BU(0X0, ctx->r18);
//    // nop
//
//    // beq         $v0, $zero, L_80069F7C
//    if (ctx->r2 == 0) {
//        // addu        $a2, $s6, $zero
//        ctx->r6 = ADD32(ctx->r22, 0);
//        goto L_80069F7C;
//    }
//    // addu        $a2, $s6, $zero
//    ctx->r6 = ADD32(ctx->r22, 0);
//L_8006A0FC:
//    // lui         $a0, 0x801E
//    ctx->r4 = S32(0X801E << 16);
//    // addiu       $a0, $a0, 0x6170
//    ctx->r4 = ADD32(ctx->r4, 0X6170);
//    // beq         $a2, $zero, L_8006A128
//    if (ctx->r6 == 0) {
//        // addiu       $v1, $zero, 0x7
//        ctx->r3 = ADD32(0, 0X7);
//        goto L_8006A128;
//    }
//    // addiu       $v1, $zero, 0x7
//    ctx->r3 = ADD32(0, 0X7);
//    // addiu       $a1, $zero, -0x1
//    ctx->r5 = ADD32(0, -0X1);
//L_8006A110:
//    // lbu         $v0, 0x0($a0)
//    ctx->r2 = MEM_BU(0X0, ctx->r4);
//    // addiu       $a0, $a0, 0x1
//    ctx->r4 = ADD32(ctx->r4, 0X1);
//    // addiu       $v1, $v1, -0x1
//    ctx->r3 = ADD32(ctx->r3, -0X1);
//    // sb          $v0, 0x0($a2)
//    MEM_B(0X0, ctx->r6) = ctx->r2;
//    // bne         $v1, $a1, L_8006A110
//    if (ctx->r3 != ctx->r5) {
//        // addiu       $a2, $a2, 0x1
//        ctx->r6 = ADD32(ctx->r6, 0X1);
//        goto L_8006A110;
//    }
//    // addiu       $a2, $a2, 0x1
//    ctx->r6 = ADD32(ctx->r6, 0X1);
//L_8006A128:
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // addiu       $v0, $v0, 0xCB8
//    ctx->r2 = ADD32(ctx->r2, 0XCB8);
//    // lbu         $v1, 0x0($v0)
//    ctx->r3 = MEM_BU(0X0, ctx->r2);
//    // addiu       $v0, $zero, 0x5
//    ctx->r2 = ADD32(0, 0X5);
//    // bne         $v1, $v0, L_8006A14C
//    if (ctx->r3 != ctx->r2) {
//        // addu        $v0, $a0, $zero
//        ctx->r2 = ADD32(ctx->r4, 0);
//        goto L_8006A14C;
//    }
//    // addu        $v0, $a0, $zero
//    ctx->r2 = ADD32(ctx->r4, 0);
//    // addiu       $a0, $zero, -0x1
//    ctx->r4 = ADD32(0, -0X1);
//    // addu        $v0, $a0, $zero
//    ctx->r2 = ADD32(ctx->r4, 0);
//L_8006A14C:
//    // lw          $ra, 0x34($sp)
//    ctx->r31 = MEM_W(0X34, ctx->r29);
//    // lw          $s6, 0x30($sp)
//    ctx->r22 = MEM_W(0X30, ctx->r29);
//    // lw          $s5, 0x2C($sp)
//    ctx->r21 = MEM_W(0X2C, ctx->r29);
//    // lw          $s4, 0x28($sp)
//    ctx->r20 = MEM_W(0X28, ctx->r29);
//    // lw          $s3, 0x24($sp)
//    ctx->r19 = MEM_W(0X24, ctx->r29);
//    // lw          $s2, 0x20($sp)
//    ctx->r18 = MEM_W(0X20, ctx->r29);
//    // lw          $s1, 0x1C($sp)
//    ctx->r17 = MEM_W(0X1C, ctx->r29);
//    // lw          $s0, 0x18($sp)
//    ctx->r16 = MEM_W(0X18, ctx->r29);
//    // jr          $ra
//    // addiu       $sp, $sp, 0x38
//    ctx->r29 = ADD32(ctx->r29, 0X38);
//    return;
//    // addiu       $sp, $sp, 0x38
//    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
