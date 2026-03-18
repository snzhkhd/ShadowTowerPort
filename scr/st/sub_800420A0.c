#include "recomp.h"
#include "disable_warnings.h"

void sub_800420A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v1, $v0, -0x2E80
    ctx->r3 = ADD32(ctx->r2, -0X2E80);
    // sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(0X2, ctx->r3);
    // lhu         $v0, 0x22($v1)
    ctx->r2 = MEM_HU(0X22, ctx->r3);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_800420FC
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800420FC;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2E4($a1)
    ctx->r4 = MEM_W(0X2E4, ctx->r5);
    // lw          $v1, 0x2C0($a1)
    ctx->r3 = MEM_W(0X2C0, ctx->r5);
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80042134
    if (ctx->r2 == 0) {
        // sw          $v1, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r3;
        goto L_80042134;
    }
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // j           L_8004219C
    // sw          $a0, 0x2C0($a1)
    MEM_W(0X2C0, ctx->r5) = ctx->r4;
    goto L_8004219C;
    // sw          $a0, 0x2C0($a1)
    MEM_W(0X2C0, ctx->r5) = ctx->r4;
L_800420FC:
    // lhu         $v0, 0x24($v1)
    ctx->r2 = MEM_HU(0X24, ctx->r3);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_80042144
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042144;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2E4($a1)
    ctx->r4 = MEM_W(0X2E4, ctx->r5);
    // lw          $v1, 0x2C0($a1)
    ctx->r3 = MEM_W(0X2C0, ctx->r5);
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_8004213C
    if (ctx->r2 != 0) {
        // sw          $v1, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r3;
        goto L_8004213C;
    }
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
L_80042134:
    // j           L_8004219C
    // sw          $v1, 0x2C0($a1)
    MEM_W(0X2C0, ctx->r5) = ctx->r3;
    goto L_8004219C;
    // sw          $v1, 0x2C0($a1)
    MEM_W(0X2C0, ctx->r5) = ctx->r3;
L_8004213C:
    // j           L_8004219C
    // sw          $a0, 0x2C0($a1)
    MEM_W(0X2C0, ctx->r5) = ctx->r4;
    goto L_8004219C;
    // sw          $a0, 0x2C0($a1)
    MEM_W(0X2C0, ctx->r5) = ctx->r4;
L_80042144:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0x2C0($a0)
    ctx->r3 = MEM_W(0X2C0, ctx->r4);
    // nop

    // blez        $v1, L_80042178
    if (SIGNED(ctx->r3) <= 0) {
        // nop
    
        goto L_80042178;
    }
    // nop

    // lw          $v0, 0x2E4($a0)
    ctx->r2 = MEM_W(0X2E4, ctx->r4);
    // nop

    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // bgez        $v0, L_8004219C
    if (SIGNED(ctx->r2) >= 0) {
        // sw          $v0, 0x2C0($a0)
        MEM_W(0X2C0, ctx->r4) = ctx->r2;
        goto L_8004219C;
    }
    // sw          $v0, 0x2C0($a0)
    MEM_W(0X2C0, ctx->r4) = ctx->r2;
    // j           L_8004219C
    // sw          $zero, 0x2C0($a0)
    MEM_W(0X2C0, ctx->r4) = 0;
    goto L_8004219C;
    // sw          $zero, 0x2C0($a0)
    MEM_W(0X2C0, ctx->r4) = 0;
L_80042178:
    // bgez        $v1, L_800421A0
    if (SIGNED(ctx->r3) >= 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_800421A0;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lw          $v0, 0x2E4($a0)
    ctx->r2 = MEM_W(0X2E4, ctx->r4);
    // nop

    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // blez        $v0, L_8004219C
    if (SIGNED(ctx->r2) <= 0) {
        // sw          $v0, 0x2C0($a0)
        MEM_W(0X2C0, ctx->r4) = ctx->r2;
        goto L_8004219C;
    }
    // sw          $v0, 0x2C0($a0)
    MEM_W(0X2C0, ctx->r4) = ctx->r2;
    // sw          $zero, 0x2C0($a0)
    MEM_W(0X2C0, ctx->r4) = 0;
L_8004219C:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_800421A0:
    // addiu       $a0, $v0, -0x2E80
    ctx->r4 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(0X2, ctx->r4);
    // lhu         $v0, 0x2C($a0)
    ctx->r2 = MEM_HU(0X2C, ctx->r4);
    // nop

    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // beq         $v0, $zero, L_800421FC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800421FC;
    }
    // nop

    // lhu         $v0, 0x2A($a0)
    ctx->r2 = MEM_HU(0X2A, ctx->r4);
    // nop

    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // bne         $v0, $zero, L_80042210
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80042210;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2E4($a1)
    ctx->r4 = MEM_W(0X2E4, ctx->r5);
    // lw          $v1, 0x2B8($a1)
    ctx->r3 = MEM_W(0X2B8, ctx->r5);
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80042250
    if (ctx->r2 == 0) {
        // sw          $v1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r3;
        goto L_80042250;
    }
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // j           L_800422BC
    // sw          $a0, 0x2B8($a1)
    MEM_W(0X2B8, ctx->r5) = ctx->r4;
    goto L_800422BC;
    // sw          $a0, 0x2B8($a1)
    MEM_W(0X2B8, ctx->r5) = ctx->r4;
L_800421FC:
    // lhu         $v0, 0x2A($a0)
    ctx->r2 = MEM_HU(0X2A, ctx->r4);
    // nop

    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // beq         $v0, $zero, L_80042260
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80042260;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80042210:
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // lhu         $v0, 0x2C($v0)
    ctx->r2 = MEM_HU(0X2C, ctx->r2);
    // nop

    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // bne         $v1, $zero, L_80042264
    if (ctx->r3 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042264;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2E4($a1)
    ctx->r4 = MEM_W(0X2E4, ctx->r5);
    // lw          $v1, 0x2B8($a1)
    ctx->r3 = MEM_W(0X2B8, ctx->r5);
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_80042258
    if (ctx->r2 != 0) {
        // sw          $v1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r3;
        goto L_80042258;
    }
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
L_80042250:
    // j           L_800422BC
    // sw          $v1, 0x2B8($a1)
    MEM_W(0X2B8, ctx->r5) = ctx->r3;
    goto L_800422BC;
    // sw          $v1, 0x2B8($a1)
    MEM_W(0X2B8, ctx->r5) = ctx->r3;
L_80042258:
    // j           L_800422BC
    // sw          $a0, 0x2B8($a1)
    MEM_W(0X2B8, ctx->r5) = ctx->r4;
    goto L_800422BC;
    // sw          $a0, 0x2B8($a1)
    MEM_W(0X2B8, ctx->r5) = ctx->r4;
L_80042260:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80042264:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0x2B8($a0)
    ctx->r3 = MEM_W(0X2B8, ctx->r4);
    // nop

    // blez        $v1, L_80042298
    if (SIGNED(ctx->r3) <= 0) {
        // nop
    
        goto L_80042298;
    }
    // nop

    // lw          $v0, 0x2E4($a0)
    ctx->r2 = MEM_W(0X2E4, ctx->r4);
    // nop

    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // bgez        $v0, L_800422BC
    if (SIGNED(ctx->r2) >= 0) {
        // sw          $v0, 0x2B8($a0)
        MEM_W(0X2B8, ctx->r4) = ctx->r2;
        goto L_800422BC;
    }
    // sw          $v0, 0x2B8($a0)
    MEM_W(0X2B8, ctx->r4) = ctx->r2;
    // j           L_800422BC
    // sw          $zero, 0x2B8($a0)
    MEM_W(0X2B8, ctx->r4) = 0;
    goto L_800422BC;
    // sw          $zero, 0x2B8($a0)
    MEM_W(0X2B8, ctx->r4) = 0;
L_80042298:
    // bgez        $v1, L_800422C0
    if (SIGNED(ctx->r3) >= 0) {
        // lui         $t0, 0x801A
        ctx->r8 = S32(0X801A << 16);
        goto L_800422C0;
    }
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // lw          $v0, 0x2E4($a0)
    ctx->r2 = MEM_W(0X2E4, ctx->r4);
    // nop

    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // blez        $v0, L_800422C0
    if (SIGNED(ctx->r2) <= 0) {
        // sw          $v0, 0x2B8($a0)
        MEM_W(0X2B8, ctx->r4) = ctx->r2;
        goto L_800422C0;
    }
    // sw          $v0, 0x2B8($a0)
    MEM_W(0X2B8, ctx->r4) = ctx->r2;
    // sw          $zero, 0x2B8($a0)
    MEM_W(0X2B8, ctx->r4) = 0;
L_800422BC:
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
L_800422C0:
    // addiu       $t0, $t0, -0x6E20
    ctx->r8 = ADD32(ctx->r8, -0X6E20);
    // lwc2        $9, 0x0($t0)
    gte_lwc2(rdram, ctx, 9, 8, 0);
    // lwc2        $10, 0x4($t0)
    gte_lwc2(rdram, ctx, 10, 8, 4);
    // lwc2        $11, 0x8($t0)
    gte_lwc2(rdram, ctx, 11, 8, 8);
    // nop

    // nop

    // .word       0x4AA00428                   # INVALID     $s5, $zero, 0x428 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AA00428);
    // addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(0X28, ctx->r29);
    // lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(0X30, ctx->r29);
    // jal         0x800746C4
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // sh          $v0, 0x2C8($v1)
    MEM_H(0X2C8, ctx->r3) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // bne         $a0, $zero, L_80042324
    if (ctx->r4 != 0) {
        // nop
    
        goto L_80042324;
    }
    // nop

    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // j           L_800423D4
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    goto L_800423D4;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80042324:
    // lw          $v0, 0x2B8($v1)
    ctx->r2 = MEM_W(0X2B8, ctx->r3);
    // nop

    // bgez        $v0, L_80042344
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80042344;
    }
    // nop

    // lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(0X28, ctx->r29);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80042344:
    // lw          $v0, 0x2C0($v1)
    ctx->r2 = MEM_W(0X2C0, ctx->r3);
    // nop

    // bgez        $v0, L_80042364
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80042364;
    }
    // nop

    // lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(0X30, ctx->r29);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_80042364:
    // lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(0X28, ctx->r29);
    // nop

    // div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_8004237C
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8004237C;
    }
    // nop

    // break       7
    do_break(2147754872);
L_8004237C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_80042394
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80042394;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80042394
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80042394;
    }
    // nop

    // break       6
    do_break(2147754896);
L_80042394:
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(0X30, ctx->r29);
    // nop

    // div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_800423B0
    if (ctx->r4 != 0) {
        // nop
    
        goto L_800423B0;
    }
    // nop

    // break       7
    do_break(2147754924);
L_800423B0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_800423C8
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800423C8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_800423C8
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_800423C8;
    }
    // nop

    // break       6
    do_break(2147754948);
L_800423C8:
    // mflo        $v0
    ctx->r2 = lo;
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_800423D4:
    // addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $v0, -0x70D8
    ctx->r17 = ADD32(ctx->r2, -0X70D8);
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // lhu         $v0, 0x27A($s1)
    ctx->r2 = MEM_HU(0X27A, ctx->r17);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // sh          $zero, 0x58($sp)
    MEM_H(0X58, ctx->r29) = 0;
    // sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // jal         0x80074EC4
    // sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    RotMatrix(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    after_1:
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x1C($sp)
    ctx->r3 = MEM_HU(0X1C, ctx->r29);
    // lhu         $a0, 0x20($sp)
    ctx->r4 = MEM_HU(0X20, ctx->r29);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // sh          $v1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r3;
    // sh          $a0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r4;
    // lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(0X0, ctx->r16);
    // lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(0X4, ctx->r16);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(0X8, ctx->r16);
    // lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(0XC, ctx->r16);
    // lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(0X10, ctx->r16);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // nop

    // nop

    // .word       0x4A486012                   # INVALID     $s2, $t0, 0x6012 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A486012);
    // addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // swc2        $25, 0x0($s0)
    gte_swc2(rdram, ctx, 25, 16, 0);
    // swc2        $26, 0x4($s0)
    gte_swc2(rdram, ctx, 26, 16, 4);
    // swc2        $27, 0x8($s0)
    gte_swc2(rdram, ctx, 27, 16, 8);
    // lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(0X20, ctx->r29);
    // lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(0X18, ctx->r29);
    // jal         0x80076EA4
    // nop

    ratan2(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // lwc2        $9, 0x0($s0)
    gte_lwc2(rdram, ctx, 9, 16, 0);
    // lwc2        $10, 0x4($s0)
    gte_lwc2(rdram, ctx, 10, 16, 4);
    // lwc2        $11, 0x8($s0)
    gte_lwc2(rdram, ctx, 11, 16, 8);
    // nop

    // nop

    // .word       0x4AA00428                   # INVALID     $s5, $zero, 0x428 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AA00428);
    // addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(0X28, ctx->r29);
    // lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(0X30, ctx->r29);
    // jal         0x800746C4
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    SquareRoot0(rdram, ctx);
    goto after_3;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_3:
    // lh          $v1, 0x1CC($s1)
    ctx->r3 = MEM_HS(0X1CC, ctx->r17);
    // lhu         $a1, 0x1CC($s1)
    ctx->r5 = MEM_HU(0X1CC, ctx->r17);
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // bgez        $v1, L_800424CC
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $a3, 0x2C8($s1)
        MEM_H(0X2C8, ctx->r17) = ctx->r7;
        goto L_800424CC;
    }
    // sh          $a3, 0x2C8($s1)
    MEM_H(0X2C8, ctx->r17) = ctx->r7;
    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_800424CC:
    // sra         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) >> 2;
    // subu        $a2, $a1, $v0
    ctx->r6 = SUB32(ctx->r5, ctx->r2);
    // lh          $a0, 0x1CE($s1)
    ctx->r4 = MEM_HS(0X1CE, ctx->r17);
    // lhu         $a1, 0x1CE($s1)
    ctx->r5 = MEM_HU(0X1CE, ctx->r17);
    // bgez        $a0, L_800424E8
    if (SIGNED(ctx->r4) >= 0) {
        // sh          $a2, 0x1CC($s1)
        MEM_H(0X1CC, ctx->r17) = ctx->r6;
        goto L_800424E8;
    }
    // sh          $a2, 0x1CC($s1)
    MEM_H(0X1CC, ctx->r17) = ctx->r6;
    // addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
L_800424E8:
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // lh          $v1, 0x1D0($s1)
    ctx->r3 = MEM_HS(0X1D0, ctx->r17);
    // lhu         $a0, 0x1D0($s1)
    ctx->r4 = MEM_HU(0X1D0, ctx->r17);
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // bgez        $v1, L_80042504
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $a1, 0x1CE($s1)
        MEM_H(0X1CE, ctx->r17) = ctx->r5;
        goto L_80042504;
    }
    // sh          $a1, 0x1CE($s1)
    MEM_H(0X1CE, ctx->r17) = ctx->r5;
    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_80042504:
    // sra         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) >> 2;
    // subu        $v1, $a0, $v0
    ctx->r3 = SUB32(ctx->r4, ctx->r2);
    // addiu       $v0, $a2, 0x3
    ctx->r2 = ADD32(ctx->r6, 0X3);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80042524
    if (ctx->r2 == 0) {
        // sh          $v1, 0x1D0($s1)
        MEM_H(0X1D0, ctx->r17) = ctx->r3;
        goto L_80042524;
    }
    // sh          $v1, 0x1D0($s1)
    MEM_H(0X1D0, ctx->r17) = ctx->r3;
    // sh          $zero, 0x1CC($s1)
    MEM_H(0X1CC, ctx->r17) = 0;
L_80042524:
    // addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_8004253C
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x3
        ctx->r2 = ADD32(ctx->r3, 0X3);
        goto L_8004253C;
    }
    // addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // sh          $zero, 0x1CE($s1)
    MEM_H(0X1CE, ctx->r17) = 0;
L_8004253C:
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80042550
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_80042550;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // sh          $zero, 0x1D0($s1)
    MEM_H(0X1D0, ctx->r17) = 0;
L_80042550:
    // addiu       $v1, $v0, 0x310
    ctx->r3 = ADD32(ctx->r2, 0X310);
    // lh          $v0, 0x71A4($v1)
    ctx->r2 = MEM_HS(0X71A4, ctx->r3);
    // nop

    // bgez        $v0, L_80042568
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80042568;
    }
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
L_80042568:
    // lh          $a0, 0x71A8($v1)
    ctx->r4 = MEM_HS(0X71A8, ctx->r3);
    // lhu         $v1, 0x1CC($s1)
    ctx->r3 = MEM_HU(0X1CC, ctx->r17);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // bgez        $a0, L_80042584
    if (SIGNED(ctx->r4) >= 0) {
        // sh          $a2, 0x1CC($s1)
        MEM_H(0X1CC, ctx->r17) = ctx->r6;
        goto L_80042584;
    }
    // sh          $a2, 0x1CC($s1)
    MEM_H(0X1CC, ctx->r17) = ctx->r6;
    // addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
L_80042584:
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addiu       $a0, $a0, -0x5EC8
    ctx->r4 = ADD32(ctx->r4, -0X5EC8);
    // lhu         $a1, 0x1D0($s1)
    ctx->r5 = MEM_HU(0X1D0, ctx->r17);
    // lhu         $v1, 0x6160($a0)
    ctx->r3 = MEM_HU(0X6160, ctx->r4);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) >> 16;
    // srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $a1, 0x1D0($s1)
    MEM_H(0X1D0, ctx->r17) = ctx->r5;
    // lhu         $v1, 0x6164($a0)
    ctx->r3 = MEM_HU(0X6164, ctx->r4);
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // sh          $v0, 0x1CC($s1)
    MEM_H(0X1CC, ctx->r17) = ctx->r2;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) >> 16;
    // srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // sh          $a1, 0x1D0($s1)
    MEM_H(0X1D0, ctx->r17) = ctx->r5;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // beq         $a1, $zero, L_80042604
    if (ctx->r5 == 0) {
        // nop
    
        goto L_80042604;
    }
    // nop

    // lbu         $v0, 0x21E($s1)
    ctx->r2 = MEM_BU(0X21E, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80042604
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80042604;
    }
    // nop

    // jal         0x80041150
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_80041150(rdram, ctx);
    goto after_4;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_4:
L_80042604:
    // lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(0X6C, ctx->r29);
    // lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(0X68, ctx->r29);
    // lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(0X64, ctx->r29);
    // lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(0X60, ctx->r29);
    // addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // jr          $ra
    // nop

    return;
    // nop

;}
