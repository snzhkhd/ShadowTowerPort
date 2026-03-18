#include "recomp.h"
#include "disable_warnings.h"

void _SsVmAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $t3, $zero, 0x63
    ctx->r11 = ADD32(0, 0X63);
    // ori         $t4, $zero, 0xFFFF
    ctx->r12 = 0 | 0XFFFF;
    // addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $t1, $zero, 0x63
    ctx->r9 = ADD32(0, 0X63);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lbu         $v0, -0x68F9($v0)
    ctx->r2 = MEM_BU(-0X68F9, ctx->r2);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lb          $v1, -0x690C($v1)
    ctx->r3 = MEM_BS(-0X690C, ctx->r3);
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // blez        $v1, L_8007059C
    if (SIGNED(ctx->r3) <= 0) {
        // sra         $t5, $v0, 24
        ctx->r13 = S32(ctx->r2) >> 24;
        goto L_8007059C;
    }
    // sra         $t5, $v0, 24
    ctx->r13 = S32(ctx->r2) >> 24;
    // addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // lw          $t7, 0xE60($t7)
    ctx->r15 = MEM_W(0XE60, ctx->r15);
    // addu        $t6, $v1, $zero
    ctx->r14 = ADD32(ctx->r3, 0);
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
L_8007045C:
    // sllv        $v0, $t8, $v1
    ctx->r2 = S32(ctx->r24) << (ctx->r3 & 31);
    // and         $v0, $t7, $v0
    ctx->r2 = ctx->r15 & ctx->r2;
    // bne         $v0, $zero, L_80070588
    if (ctx->r2 != 0) {
        // sll         $v0, $v1, 3
        ctx->r2 = S32(ctx->r3) << 3;
        goto L_80070588;
    }
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lb          $v0, -0x70E3($v0)
    ctx->r2 = MEM_BS(-0X70E3, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800704B4
    if (ctx->r2 != 0) {
        // andi        $v0, $a3, 0xFF
        ctx->r2 = ctx->r7 & 0XFF;
        goto L_800704B4;
    }
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, -0x70FA($v0)
    ctx->r2 = MEM_HU(-0X70FA, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800704B4
    if (ctx->r2 != 0) {
        // andi        $v0, $a3, 0xFF
        ctx->r2 = ctx->r7 & 0XFF;
        goto L_800704B4;
    }
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // j           L_8007059C
    // addu        $t3, $a3, $zero
    ctx->r11 = ADD32(ctx->r7, 0);
    goto L_8007059C;
    // addu        $t3, $a3, $zero
    ctx->r11 = ADD32(ctx->r7, 0);
L_800704B4:
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // andi        $a1, $t5, 0xFFFF
    ctx->r5 = ctx->r13 & 0XFFFF;
    // lui         $a2, 0x801F
    ctx->r6 = S32(0X801F << 16);
    // addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // lh          $a2, -0x70E6($a2)
    ctx->r6 = MEM_HS(-0X70E6, ctx->r6);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // lhu         $a0, -0x70E6($a0)
    ctx->r4 = MEM_HU(-0X70E6, ctx->r4);
    // slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_80070518
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070518;
    }
    // nop

    // addu        $t5, $a0, $zero
    ctx->r13 = ADD32(ctx->r4, 0);
    // addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // lui         $t4, 0x801F
    ctx->r12 = S32(0X801F << 16);
    // addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // lhu         $t4, -0x70FA($t4)
    ctx->r12 = MEM_HU(-0X70FA, ctx->r12);
    // lui         $t0, 0x801F
    ctx->r8 = S32(0X801F << 16);
    // addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // lhu         $t0, -0x70FE($t0)
    ctx->r8 = MEM_HU(-0X70FE, ctx->r8);
    // j           L_80070588
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    goto L_80070588;
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80070518:
    // bne         $a2, $a1, L_80070588
    if (ctx->r6 != ctx->r5) {
        // andi        $a0, $t4, 0xFFFF
        ctx->r4 = ctx->r12 & 0XFFFF;
        goto L_80070588;
    }
    // andi        $a0, $t4, 0xFFFF
    ctx->r4 = ctx->r12 & 0XFFFF;
    // lui         $a2, 0x801F
    ctx->r6 = S32(0X801F << 16);
    // addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // lhu         $a2, -0x70FA($a2)
    ctx->r6 = MEM_HU(-0X70FA, ctx->r6);
    // nop

    // andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    // sltu        $v0, $a1, $a0
    ctx->r2 = ctx->r5 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_80070554
    if (ctx->r2 == 0) {
        // addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
        goto L_80070554;
    }
    // addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // lui         $t0, 0x801F
    ctx->r8 = S32(0X801F << 16);
    // addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // lhu         $t0, -0x70FE($t0)
    ctx->r8 = MEM_HU(-0X70FE, ctx->r8);
    // j           L_80070584
    // addu        $t4, $a2, $zero
    ctx->r12 = ADD32(ctx->r6, 0);
    goto L_80070584;
    // addu        $t4, $a2, $zero
    ctx->r12 = ADD32(ctx->r6, 0);
L_80070554:
    // bne         $a1, $a0, L_80070588
    if (ctx->r5 != ctx->r4) {
        // nop
    
        goto L_80070588;
    }
    // nop

    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, -0x70FE($v0)
    ctx->r2 = MEM_HS(-0X70FE, ctx->r2);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lhu         $v1, -0x70FE($at)
    ctx->r3 = MEM_HU(-0X70FE, ctx->r1);
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80070588
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80070588;
    }
    // nop

    // addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
L_80070584:
    // addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
L_80070588:
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // slt         $v0, $v0, $t6
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // bne         $v0, $zero, L_8007045C
    if (ctx->r2 != 0) {
        // andi        $v1, $a3, 0xFF
        ctx->r3 = ctx->r7 & 0XFF;
        goto L_8007045C;
    }
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
L_8007059C:
    // andi        $v1, $t3, 0xFF
    ctx->r3 = ctx->r11 & 0XFF;
    // addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // bne         $v1, $v0, L_800705BC
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $t2, 0xFF
        ctx->r2 = ctx->r10 & 0XFF;
        goto L_800705BC;
    }
    // andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // bne         $v0, $zero, L_800705BC
    if (ctx->r2 != 0) {
        // addu        $t3, $t1, $zero
        ctx->r11 = ADD32(ctx->r9, 0);
        goto L_800705BC;
    }
    // addu        $t3, $t1, $zero
    ctx->r11 = ADD32(ctx->r9, 0);
    // lui         $t3, 0x801F
    ctx->r11 = S32(0X801F << 16);
    // lbu         $t3, -0x690C($t3)
    ctx->r11 = MEM_BU(-0X690C, ctx->r11);
L_800705BC:
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lb          $v1, -0x690C($v1)
    ctx->r3 = MEM_BS(-0X690C, ctx->r3);
    // andi        $v0, $t3, 0xFF
    ctx->r2 = ctx->r11 & 0XFF;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8007069C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007069C;
    }
    // nop

    // blez        $v1, L_80070644
    if (SIGNED(ctx->r3) <= 0) {
        // addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
        goto L_80070644;
    }
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xE60($a1)
    ctx->r5 = MEM_W(0XE60, ctx->r5);
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
L_800705F0:
    // sllv        $v0, $a2, $v1
    ctx->r2 = S32(ctx->r6) << (ctx->r3 & 31);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // bne         $v0, $zero, L_80070630
    if (ctx->r2 != 0) {
        // sll         $v0, $v1, 3
        ctx->r2 = S32(ctx->r3) << 3;
        goto L_80070630;
    }
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v1, -0x70FE($v1)
    ctx->r3 = MEM_HU(-0X70FE, ctx->r3);
    // nop

    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, -0x70FE($at)
    MEM_H(-0X70FE, ctx->r1) = ctx->r3;
L_80070630:
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_800705F0
    if (ctx->r2 != 0) {
        // andi        $v1, $a3, 0xFF
        ctx->r3 = ctx->r7 & 0XFF;
        goto L_800705F0;
    }
    // andi        $v1, $a3, 0xFF
    ctx->r3 = ctx->r7 & 0XFF;
L_80070644:
    // andi        $v0, $t3, 0xFF
    ctx->r2 = ctx->r11 & 0XFF;
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $zero, -0x70FE($at)
    MEM_H(-0X70FE, ctx->r1) = 0;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lbu         $v0, -0x68F9($v0)
    ctx->r2 = MEM_BU(-0X68F9, ctx->r2);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $zero, -0x70D6($at)
    MEM_H(-0X70D6, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $zero, -0x70E2($at)
    MEM_H(-0X70E2, ctx->r1) = 0;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $v0, -0x70E6($at)
    MEM_H(-0X70E6, ctx->r1) = ctx->r2;
L_8007069C:
    // jr          $ra
    // andi        $v0, $t3, 0xFF
    ctx->r2 = ctx->r11 & 0XFF;
    return;
    // andi        $v0, $t3, 0xFF
    ctx->r2 = ctx->r11 & 0XFF;
;}
