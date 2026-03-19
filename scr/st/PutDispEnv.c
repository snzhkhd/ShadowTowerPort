#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"
#include "psx/libgpu.h"

void PutDispEnv(uint8_t* rdram, recomp_context* ctx) 
{
    printf("PutDispEnv\n");
    DISPENV* env = (DISPENV*)GET_PTR(ctx->r4);
    //  Psy-X  
    PutDispEnv(env);
    ctx->r2 = 0;
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x20
//    ctx->r29 = ADD32(ctx->r29, -0X20);
//    // sw          $s1, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r17;
//    // addu        $s1, $a0, $zero
//    ctx->r17 = ADD32(ctx->r4, 0);
//    // sw          $s2, 0x18($sp)
//    MEM_W(0X18, ctx->r29) = ctx->r18;
//    // lui         $s2, 0x8008
//    ctx->r18 = S32(0X8008 << 16);
//    // addiu       $s2, $s2, 0x7CC2
//    ctx->r18 = ADD32(ctx->r18, 0X7CC2);
//    // sw          $ra, 0x1C($sp)
//    MEM_W(0X1C, ctx->r29) = ctx->r31;
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // lbu         $v0, 0x0($s2)
//    ctx->r2 = MEM_BU(0X0, ctx->r18);
//    // nop
//
//    // sltiu       $v0, $v0, 0x2
//    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
//    // bne         $v0, $zero, L_8007A2E0
//    if (ctx->r2 != 0) {
//        // lui         $s0, 0x800
//        ctx->r16 = S32(0X800 << 16);
//        goto L_8007A2E0;
//    }
//    // lui         $s0, 0x800
//    ctx->r16 = S32(0X800 << 16);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x42A4
//    ctx->r4 = ADD32(ctx->r4, 0X42A4);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7CBC($v0)
//    ctx->r2 = MEM_W(0X7CBC, ctx->r2);
//    // nop
//
//    // jalr        $v0
//    // addu        $a1, $s1, $zero
//    ctx->r5 = ADD32(ctx->r17, 0);
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_0;
//    // addu        $a1, $s1, $zero
//    ctx->r5 = ADD32(ctx->r17, 0);
//    after_0:
//L_8007A2E0:
//    // lui         $v0, 0x500
//    ctx->r2 = S32(0X500 << 16);
//    // lhu         $v1, 0x2($s1)
//    ctx->r3 = MEM_HU(0X2, ctx->r17);
//    // lhu         $a0, 0x0($s1)
//    ctx->r4 = MEM_HU(0X0, ctx->r17);
//    // lui         $a1, 0x8008
//    ctx->r5 = S32(0X8008 << 16);
//    // lw          $a1, 0x7CB8($a1)
//    ctx->r5 = MEM_W(0X7CB8, ctx->r5);
//    // andi        $v1, $v1, 0x3FF
//    ctx->r3 = ctx->r3 & 0X3FF;
//    // sll         $v1, $v1, 10
//    ctx->r3 = S32(ctx->r3) << 10;
//    // andi        $a0, $a0, 0x3FF
//    ctx->r4 = ctx->r4 & 0X3FF;
//    // or          $a0, $a0, $v0
//    ctx->r4 = ctx->r4 | ctx->r2;
//    // lw          $v0, 0x10($a1)
//    ctx->r2 = MEM_W(0X10, ctx->r5);
//    // nop
//
//    // jalr        $v0
//    // or          $a0, $v1, $a0
//    ctx->r4 = ctx->r3 | ctx->r4;
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_1;
//    // or          $a0, $v1, $a0
//    ctx->r4 = ctx->r3 | ctx->r4;
//    after_1:
//    // lw          $v1, 0x7A($s2)
//    ctx->r3 = MEM_W(0X7A, ctx->r18);
//    // lw          $v0, 0x10($s1)
//    ctx->r2 = MEM_W(0X10, ctx->r17);
//    // nop
//
//    // bne         $v1, $v0, L_8007A388
//    if (ctx->r3 != ctx->r2) {
//        // addiu       $a0, $s2, 0x6A
//        ctx->r4 = ADD32(ctx->r18, 0X6A);
//        goto L_8007A388;
//    }
//    // addiu       $a0, $s2, 0x6A
//    ctx->r4 = ADD32(ctx->r18, 0X6A);
//    // lhu         $v0, 0x6A($s2)
//    ctx->r2 = MEM_HU(0X6A, ctx->r18);
//    // lh          $v1, 0x0($s1)
//    ctx->r3 = MEM_HS(0X0, ctx->r17);
//    // sll         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) << 16;
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // bne         $v0, $v1, L_8007A388
//    if (ctx->r2 != ctx->r3) {
//        // nop
//    
//        goto L_8007A388;
//    }
//    // nop
//
//    // lhu         $v0, 0x2($a0)
//    ctx->r2 = MEM_HU(0X2, ctx->r4);
//    // lh          $v1, 0x2($s1)
//    ctx->r3 = MEM_HS(0X2, ctx->r17);
//    // sll         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) << 16;
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // bne         $v0, $v1, L_8007A388
//    if (ctx->r2 != ctx->r3) {
//        // nop
//    
//        goto L_8007A388;
//    }
//    // nop
//
//    // lhu         $v0, 0x4($a0)
//    ctx->r2 = MEM_HU(0X4, ctx->r4);
//    // lh          $v1, 0x4($s1)
//    ctx->r3 = MEM_HS(0X4, ctx->r17);
//    // sll         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) << 16;
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // bne         $v0, $v1, L_8007A388
//    if (ctx->r2 != ctx->r3) {
//        // nop
//    
//        goto L_8007A388;
//    }
//    // nop
//
//    // lhu         $v0, 0x6($a0)
//    ctx->r2 = MEM_HU(0X6, ctx->r4);
//    // lh          $v1, 0x6($s1)
//    ctx->r3 = MEM_HS(0X6, ctx->r17);
//    // sll         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) << 16;
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // beq         $v0, $v1, L_8007A474
//    if (ctx->r2 == ctx->r3) {
//        // nop
//    
//        goto L_8007A474;
//    }
//    // nop
//
//L_8007A388:
//    // jal         0x80077DA8
//    // nop
//
//    GetVideoMode(rdram, ctx);
//    goto after_2;
//    // nop
//
//    after_2:
//    // sb          $v0, 0x12($s1)
//    MEM_B(0X12, ctx->r17) = ctx->r2;
//    // andi        $v0, $v0, 0xFF
//    ctx->r2 = ctx->r2 & 0XFF;
//    // addiu       $v1, $zero, 0x1
//    ctx->r3 = ADD32(0, 0X1);
//    // bne         $v0, $v1, L_8007A3A8
//    if (ctx->r2 != ctx->r3) {
//        // nop
//    
//        goto L_8007A3A8;
//    }
//    // nop
//
//    // ori         $s0, $s0, 0x8
//    ctx->r16 = ctx->r16 | 0X8;
//L_8007A3A8:
//    // lbu         $v0, 0x11($s1)
//    ctx->r2 = MEM_BU(0X11, ctx->r17);
//    // nop
//
//    // beq         $v0, $zero, L_8007A3BC
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8007A3BC;
//    }
//    // nop
//
//    // ori         $s0, $s0, 0x10
//    ctx->r16 = ctx->r16 | 0X10;
//L_8007A3BC:
//    // lbu         $v0, 0x10($s1)
//    ctx->r2 = MEM_BU(0X10, ctx->r17);
//    // nop
//
//    // beq         $v0, $zero, L_8007A3D0
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8007A3D0;
//    }
//    // nop
//
//    // ori         $s0, $s0, 0x20
//    ctx->r16 = ctx->r16 | 0X20;
//L_8007A3D0:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lbu         $v0, 0x7CC3($v0)
//    ctx->r2 = MEM_BU(0X7CC3, ctx->r2);
//    // nop
//
//    // beq         $v0, $zero, L_8007A3E8
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8007A3E8;
//    }
//    // nop
//
//    // ori         $s0, $s0, 0x80
//    ctx->r16 = ctx->r16 | 0X80;
//L_8007A3E8:
//    // lh          $v1, 0x4($s1)
//    ctx->r3 = MEM_HS(0X4, ctx->r17);
//    // nop
//
//    // slti        $v0, $v1, 0x119
//    ctx->r2 = SIGNED(ctx->r3) < 0X119 ? 1 : 0;
//    // bne         $v0, $zero, L_8007A430
//    if (ctx->r2 != 0) {
//        // slti        $v0, $v1, 0x161
//        ctx->r2 = SIGNED(ctx->r3) < 0X161 ? 1 : 0;
//        goto L_8007A430;
//    }
//    // slti        $v0, $v1, 0x161
//    ctx->r2 = SIGNED(ctx->r3) < 0X161 ? 1 : 0;
//    // beq         $v0, $zero, L_8007A40C
//    if (ctx->r2 == 0) {
//        // slti        $v0, $v1, 0x191
//        ctx->r2 = SIGNED(ctx->r3) < 0X191 ? 1 : 0;
//        goto L_8007A40C;
//    }
//    // slti        $v0, $v1, 0x191
//    ctx->r2 = SIGNED(ctx->r3) < 0X191 ? 1 : 0;
//    // j           L_8007A430
//    // ori         $s0, $s0, 0x1
//    ctx->r16 = ctx->r16 | 0X1;
//    goto L_8007A430;
//    // ori         $s0, $s0, 0x1
//    ctx->r16 = ctx->r16 | 0X1;
//L_8007A40C:
//    // beq         $v0, $zero, L_8007A41C
//    if (ctx->r2 == 0) {
//        // slti        $v0, $v1, 0x231
//        ctx->r2 = SIGNED(ctx->r3) < 0X231 ? 1 : 0;
//        goto L_8007A41C;
//    }
//    // slti        $v0, $v1, 0x231
//    ctx->r2 = SIGNED(ctx->r3) < 0X231 ? 1 : 0;
//    // j           L_8007A430
//    // ori         $s0, $s0, 0x40
//    ctx->r16 = ctx->r16 | 0X40;
//    goto L_8007A430;
//    // ori         $s0, $s0, 0x40
//    ctx->r16 = ctx->r16 | 0X40;
//L_8007A41C:
//    // beq         $v0, $zero, L_8007A42C
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8007A42C;
//    }
//    // nop
//
//    // j           L_8007A430
//    // ori         $s0, $s0, 0x2
//    ctx->r16 = ctx->r16 | 0X2;
//    goto L_8007A430;
//    // ori         $s0, $s0, 0x2
//    ctx->r16 = ctx->r16 | 0X2;
//L_8007A42C:
//    // ori         $s0, $s0, 0x3
//    ctx->r16 = ctx->r16 | 0X3;
//L_8007A430:
//    // lbu         $v0, 0x12($s1)
//    ctx->r2 = MEM_BU(0X12, ctx->r17);
//    // lh          $v1, 0x6($s1)
//    ctx->r3 = MEM_HS(0X6, ctx->r17);
//    // bne         $v0, $zero, L_8007A444
//    if (ctx->r2 != 0) {
//        // slti        $v0, $v1, 0x121
//        ctx->r2 = SIGNED(ctx->r3) < 0X121 ? 1 : 0;
//        goto L_8007A444;
//    }
//    // slti        $v0, $v1, 0x121
//    ctx->r2 = SIGNED(ctx->r3) < 0X121 ? 1 : 0;
//    // slti        $v0, $v1, 0x101
//    ctx->r2 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
//L_8007A444:
//    // bne         $v0, $zero, L_8007A450
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_8007A450;
//    }
//    // nop
//
//    // ori         $s0, $s0, 0x24
//    ctx->r16 = ctx->r16 | 0X24;
//L_8007A450:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7CB8($v0)
//    ctx->r2 = MEM_W(0X7CB8, ctx->r2);
//    // nop
//
//    // lw          $v0, 0x10($v0)
//    ctx->r2 = MEM_W(0X10, ctx->r2);
//    // nop
//
//    // jalr        $v0
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_3;
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    after_3:
//    // addiu       $v0, $zero, 0x8
//    ctx->r2 = ADD32(0, 0X8);
//    // sb          $v0, 0x12($s1)
//    MEM_B(0X12, ctx->r17) = ctx->r2;
//L_8007A474:
//    // lui         $a0, 0x8008
//    ctx->r4 = S32(0X8008 << 16);
//    // addiu       $a0, $a0, 0x7D34
//    ctx->r4 = ADD32(ctx->r4, 0X7D34);
//    // lhu         $v0, 0x0($a0)
//    ctx->r2 = MEM_HU(0X0, ctx->r4);
//    // lh          $v1, 0x8($s1)
//    ctx->r3 = MEM_HS(0X8, ctx->r17);
//    // sll         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) << 16;
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // bne         $v0, $v1, L_8007A4EC
//    if (ctx->r2 != ctx->r3) {
//        // nop
//    
//        goto L_8007A4EC;
//    }
//    // nop
//
//    // lhu         $v0, 0x2($a0)
//    ctx->r2 = MEM_HU(0X2, ctx->r4);
//    // lh          $v1, 0xA($s1)
//    ctx->r3 = MEM_HS(0XA, ctx->r17);
//    // sll         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) << 16;
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // bne         $v0, $v1, L_8007A4EC
//    if (ctx->r2 != ctx->r3) {
//        // nop
//    
//        goto L_8007A4EC;
//    }
//    // nop
//
//    // lhu         $v0, 0x4($a0)
//    ctx->r2 = MEM_HU(0X4, ctx->r4);
//    // lh          $v1, 0xC($s1)
//    ctx->r3 = MEM_HS(0XC, ctx->r17);
//    // sll         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) << 16;
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // bne         $v0, $v1, L_8007A4EC
//    if (ctx->r2 != ctx->r3) {
//        // nop
//    
//        goto L_8007A4EC;
//    }
//    // nop
//
//    // lhu         $v0, 0x6($a0)
//    ctx->r2 = MEM_HU(0X6, ctx->r4);
//    // lh          $v1, 0xE($s1)
//    ctx->r3 = MEM_HS(0XE, ctx->r17);
//    // sll         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) << 16;
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // bne         $v0, $v1, L_8007A4EC
//    if (ctx->r2 != ctx->r3) {
//        // addiu       $v0, $zero, 0x8
//        ctx->r2 = ADD32(0, 0X8);
//        goto L_8007A4EC;
//    }
//    // addiu       $v0, $zero, 0x8
//    ctx->r2 = ADD32(0, 0X8);
//    // lbu         $v1, 0x12($s1)
//    ctx->r3 = MEM_BU(0X12, ctx->r17);
//    // nop
//
//    // bne         $v1, $v0, L_8007A758
//    if (ctx->r3 != ctx->r2) {
//        // nop
//    
//        goto L_8007A758;
//    }
//    // nop
//
//L_8007A4EC:
//    // jal         0x80077DA8
//    // nop
//
//    GetVideoMode(rdram, ctx);
//    goto after_4;
//    // nop
//
//    after_4:
//    // sb          $v0, 0x12($s1)
//    MEM_B(0X12, ctx->r17) = ctx->r2;
//    // andi        $v0, $v0, 0xFF
//    ctx->r2 = ctx->r2 & 0XFF;
//    // lh          $a0, 0xA($s1)
//    ctx->r4 = MEM_HS(0XA, ctx->r17);
//    // bne         $v0, $zero, L_8007A50C
//    if (ctx->r2 != 0) {
//        // addiu       $s0, $a0, 0x13
//        ctx->r16 = ADD32(ctx->r4, 0X13);
//        goto L_8007A50C;
//    }
//    // addiu       $s0, $a0, 0x13
//    ctx->r16 = ADD32(ctx->r4, 0X13);
//    // addiu       $s0, $a0, 0x10
//    ctx->r16 = ADD32(ctx->r4, 0X10);
//L_8007A50C:
//    // lh          $v0, 0xE($s1)
//    ctx->r2 = MEM_HS(0XE, ctx->r17);
//    // nop
//
//    // bne         $v0, $zero, L_8007A520
//    if (ctx->r2 != 0) {
//        // addu        $s2, $s0, $v0
//        ctx->r18 = ADD32(ctx->r16, ctx->r2);
//        goto L_8007A520;
//    }
//    // addu        $s2, $s0, $v0
//    ctx->r18 = ADD32(ctx->r16, ctx->r2);
//    // addiu       $s2, $s0, 0xF0
//    ctx->r18 = ADD32(ctx->r16, 0XF0);
//L_8007A520:
//    // lh          $v1, 0x4($s1)
//    ctx->r3 = MEM_HS(0X4, ctx->r17);
//    // nop
//
//    // slti        $v0, $v1, 0x119
//    ctx->r2 = SIGNED(ctx->r3) < 0X119 ? 1 : 0;
//    // bne         $v0, $zero, L_8007A55C
//    if (ctx->r2 != 0) {
//        // addu        $a2, $zero, $zero
//        ctx->r6 = ADD32(0, 0);
//        goto L_8007A55C;
//    }
//    // addu        $a2, $zero, $zero
//    ctx->r6 = ADD32(0, 0);
//    // slti        $v0, $v1, 0x161
//    ctx->r2 = SIGNED(ctx->r3) < 0X161 ? 1 : 0;
//    // bne         $v0, $zero, L_8007A55C
//    if (ctx->r2 != 0) {
//        // addiu       $a2, $zero, 0x1
//        ctx->r6 = ADD32(0, 0X1);
//        goto L_8007A55C;
//    }
//    // addiu       $a2, $zero, 0x1
//    ctx->r6 = ADD32(0, 0X1);
//    // slti        $v0, $v1, 0x191
//    ctx->r2 = SIGNED(ctx->r3) < 0X191 ? 1 : 0;
//    // bne         $v0, $zero, L_8007A55C
//    if (ctx->r2 != 0) {
//        // addiu       $a2, $zero, 0x2
//        ctx->r6 = ADD32(0, 0X2);
//        goto L_8007A55C;
//    }
//    // addiu       $a2, $zero, 0x2
//    ctx->r6 = ADD32(0, 0X2);
//    // slti        $v0, $v1, 0x231
//    ctx->r2 = SIGNED(ctx->r3) < 0X231 ? 1 : 0;
//    // beq         $v0, $zero, L_8007A55C
//    if (ctx->r2 == 0) {
//        // addiu       $a2, $zero, 0x4
//        ctx->r6 = ADD32(0, 0X4);
//        goto L_8007A55C;
//    }
//    // addiu       $a2, $zero, 0x4
//    ctx->r6 = ADD32(0, 0X4);
//    // addiu       $a2, $zero, 0x3
//    ctx->r6 = ADD32(0, 0X3);
//L_8007A55C:
//    // lh          $v1, 0x8($s1)
//    ctx->r3 = MEM_HS(0X8, ctx->r17);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // addu        $v0, $v0, $a2
//    ctx->r2 = ADD32(ctx->r2, ctx->r6);
//    // lbu         $v0, 0x7DBC($v0)
//    ctx->r2 = MEM_BU(0X7DBC, ctx->r2);
//    // nop
//
//    // mult        $v1, $v0
//    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
//    // lbu         $v1, 0x12($s1)
//    ctx->r3 = MEM_BU(0X12, ctx->r17);
//    // nop
//
//    // sll         $v0, $v1, 2
//    ctx->r2 = S32(ctx->r3) << 2;
//    // addu        $v0, $v0, $v1
//    ctx->r2 = ADD32(ctx->r2, ctx->r3);
//    // addu        $v0, $v0, $a2
//    ctx->r2 = ADD32(ctx->r2, ctx->r6);
//    // sll         $v0, $v0, 2
//    ctx->r2 = S32(ctx->r2) << 2;
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // addu        $v1, $v1, $v0
//    ctx->r3 = ADD32(ctx->r3, ctx->r2);
//    // lhu         $v1, 0x7D94($v1)
//    ctx->r3 = MEM_HU(0X7D94, ctx->r3);
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // addu        $at, $at, $v0
//    ctx->r1 = ADD32(ctx->r1, ctx->r2);
//    // lhu         $v0, 0x7D96($at)
//    ctx->r2 = MEM_HU(0X7D96, ctx->r1);
//    // lh          $a1, 0xC($s1)
//    ctx->r5 = MEM_HS(0XC, ctx->r17);
//    // subu        $v0, $v0, $v1
//    ctx->r2 = SUB32(ctx->r2, ctx->r3);
//    // mflo        $a3
//    ctx->r7 = lo;
//    // beq         $a1, $zero, L_8007A5C4
//    if (ctx->r5 == 0) {
//        // addu        $a0, $v1, $a3
//        ctx->r4 = ADD32(ctx->r3, ctx->r7);
//        goto L_8007A5C4;
//    }
//    // addu        $a0, $v1, $a3
//    ctx->r4 = ADD32(ctx->r3, ctx->r7);
//    // mult        $v0, $a1
//    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
//    // mflo        $a3
//    ctx->r7 = lo;
//    // sra         $v0, $a3, 8
//    ctx->r2 = S32(ctx->r7) >> 8;
//L_8007A5C4:
//    // addu        $v1, $a0, $v0
//    ctx->r3 = ADD32(ctx->r4, ctx->r2);
//    // lbu         $v0, 0x12($s1)
//    ctx->r2 = MEM_BU(0X12, ctx->r17);
//    // nop
//
//    // beq         $v0, $zero, L_8007A664
//    if (ctx->r2 == 0) {
//        // slti        $v0, $a0, 0x21C
//        ctx->r2 = SIGNED(ctx->r4) < 0X21C ? 1 : 0;
//        goto L_8007A664;
//    }
//    // slti        $v0, $a0, 0x21C
//    ctx->r2 = SIGNED(ctx->r4) < 0X21C ? 1 : 0;
//    // bne         $v0, $zero, L_8007A5F0
//    if (ctx->r2 != 0) {
//        // addiu       $a1, $zero, 0x21C
//        ctx->r5 = ADD32(0, 0X21C);
//        goto L_8007A5F0;
//    }
//    // addiu       $a1, $zero, 0x21C
//    ctx->r5 = ADD32(0, 0X21C);
//    // slti        $v0, $a0, 0xC95
//    ctx->r2 = SIGNED(ctx->r4) < 0XC95 ? 1 : 0;
//    // beq         $v0, $zero, L_8007A5F0
//    if (ctx->r2 == 0) {
//        // addiu       $a1, $zero, 0xC94
//        ctx->r5 = ADD32(0, 0XC94);
//        goto L_8007A5F0;
//    }
//    // addiu       $a1, $zero, 0xC94
//    ctx->r5 = ADD32(0, 0XC94);
//    // addu        $a1, $a0, $zero
//    ctx->r5 = ADD32(ctx->r4, 0);
//L_8007A5F0:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // addu        $v0, $v0, $a2
//    ctx->r2 = ADD32(ctx->r2, ctx->r6);
//    // lbu         $v0, 0x7DBC($v0)
//    ctx->r2 = MEM_BU(0X7DBC, ctx->r2);
//    // addu        $a0, $a1, $zero
//    ctx->r4 = ADD32(ctx->r5, 0);
//    // sll         $v0, $v0, 2
//    ctx->r2 = S32(ctx->r2) << 2;
//    // addu        $a1, $a0, $v0
//    ctx->r5 = ADD32(ctx->r4, ctx->r2);
//    // slt         $v0, $v1, $a1
//    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
//    // bne         $v0, $zero, L_8007A628
//    if (ctx->r2 != 0) {
//        // slti        $v0, $s0, 0x13
//        ctx->r2 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
//        goto L_8007A628;
//    }
//    // slti        $v0, $s0, 0x13
//    ctx->r2 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
//    // slti        $v0, $v1, 0xCBD
//    ctx->r2 = SIGNED(ctx->r3) < 0XCBD ? 1 : 0;
//    // beq         $v0, $zero, L_8007A624
//    if (ctx->r2 == 0) {
//        // addiu       $a1, $zero, 0xCBC
//        ctx->r5 = ADD32(0, 0XCBC);
//        goto L_8007A624;
//    }
//    // addiu       $a1, $zero, 0xCBC
//    ctx->r5 = ADD32(0, 0XCBC);
//    // addu        $a1, $v1, $zero
//    ctx->r5 = ADD32(ctx->r3, 0);
//L_8007A624:
//    // slti        $v0, $s0, 0x13
//    ctx->r2 = SIGNED(ctx->r16) < 0X13 ? 1 : 0;
//L_8007A628:
//    // bne         $v0, $zero, L_8007A644
//    if (ctx->r2 != 0) {
//        // addu        $v1, $a1, $zero
//        ctx->r3 = ADD32(ctx->r5, 0);
//        goto L_8007A644;
//    }
//    // addu        $v1, $a1, $zero
//    ctx->r3 = ADD32(ctx->r5, 0);
//    // slti        $v0, $s0, 0x130
//    ctx->r2 = SIGNED(ctx->r16) < 0X130 ? 1 : 0;
//    // beq         $v0, $zero, L_8007A648
//    if (ctx->r2 == 0) {
//        // addiu       $a1, $zero, 0x12F
//        ctx->r5 = ADD32(0, 0X12F);
//        goto L_8007A648;
//    }
//    // addiu       $a1, $zero, 0x12F
//    ctx->r5 = ADD32(0, 0X12F);
//    // j           L_8007A648
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//    goto L_8007A648;
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//L_8007A644:
//    // addiu       $a1, $zero, 0x13
//    ctx->r5 = ADD32(0, 0X13);
//L_8007A648:
//    // addu        $s0, $a1, $zero
//    ctx->r16 = ADD32(ctx->r5, 0);
//    // addiu       $a1, $s0, 0x2
//    ctx->r5 = ADD32(ctx->r16, 0X2);
//    // slt         $v0, $s2, $a1
//    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r5) ? 1 : 0;
//    // bne         $v0, $zero, L_8007A6FC
//    if (ctx->r2 != 0) {
//        // slti        $v0, $s2, 0x132
//        ctx->r2 = SIGNED(ctx->r18) < 0X132 ? 1 : 0;
//        goto L_8007A6FC;
//    }
//    // slti        $v0, $s2, 0x132
//    ctx->r2 = SIGNED(ctx->r18) < 0X132 ? 1 : 0;
//    // j           L_8007A6F0
//    // addiu       $a1, $zero, 0x131
//    ctx->r5 = ADD32(0, 0X131);
//    goto L_8007A6F0;
//    // addiu       $a1, $zero, 0x131
//    ctx->r5 = ADD32(0, 0X131);
//L_8007A664:
//    // slti        $v0, $a0, 0x1F4
//    ctx->r2 = SIGNED(ctx->r4) < 0X1F4 ? 1 : 0;
//    // bne         $v0, $zero, L_8007A680
//    if (ctx->r2 != 0) {
//        // addiu       $a1, $zero, 0x1F4
//        ctx->r5 = ADD32(0, 0X1F4);
//        goto L_8007A680;
//    }
//    // addiu       $a1, $zero, 0x1F4
//    ctx->r5 = ADD32(0, 0X1F4);
//    // slti        $v0, $a0, 0xCB3
//    ctx->r2 = SIGNED(ctx->r4) < 0XCB3 ? 1 : 0;
//    // beq         $v0, $zero, L_8007A680
//    if (ctx->r2 == 0) {
//        // addiu       $a1, $zero, 0xCB2
//        ctx->r5 = ADD32(0, 0XCB2);
//        goto L_8007A680;
//    }
//    // addiu       $a1, $zero, 0xCB2
//    ctx->r5 = ADD32(0, 0XCB2);
//    // addu        $a1, $a0, $zero
//    ctx->r5 = ADD32(ctx->r4, 0);
//L_8007A680:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // addu        $v0, $v0, $a2
//    ctx->r2 = ADD32(ctx->r2, ctx->r6);
//    // lbu         $v0, 0x7DBC($v0)
//    ctx->r2 = MEM_BU(0X7DBC, ctx->r2);
//    // addu        $a0, $a1, $zero
//    ctx->r4 = ADD32(ctx->r5, 0);
//    // sll         $v0, $v0, 2
//    ctx->r2 = S32(ctx->r2) << 2;
//    // addu        $a1, $a0, $v0
//    ctx->r5 = ADD32(ctx->r4, ctx->r2);
//    // slt         $v0, $v1, $a1
//    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
//    // bne         $v0, $zero, L_8007A6B8
//    if (ctx->r2 != 0) {
//        // slti        $v0, $s0, 0x10
//        ctx->r2 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
//        goto L_8007A6B8;
//    }
//    // slti        $v0, $s0, 0x10
//    ctx->r2 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
//    // slti        $v0, $v1, 0xCDB
//    ctx->r2 = SIGNED(ctx->r3) < 0XCDB ? 1 : 0;
//    // beq         $v0, $zero, L_8007A6B4
//    if (ctx->r2 == 0) {
//        // addiu       $a1, $zero, 0xCDA
//        ctx->r5 = ADD32(0, 0XCDA);
//        goto L_8007A6B4;
//    }
//    // addiu       $a1, $zero, 0xCDA
//    ctx->r5 = ADD32(0, 0XCDA);
//    // addu        $a1, $v1, $zero
//    ctx->r5 = ADD32(ctx->r3, 0);
//L_8007A6B4:
//    // slti        $v0, $s0, 0x10
//    ctx->r2 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
//L_8007A6B8:
//    // bne         $v0, $zero, L_8007A6D4
//    if (ctx->r2 != 0) {
//        // addu        $v1, $a1, $zero
//        ctx->r3 = ADD32(ctx->r5, 0);
//        goto L_8007A6D4;
//    }
//    // addu        $v1, $a1, $zero
//    ctx->r3 = ADD32(ctx->r5, 0);
//    // slti        $v0, $s0, 0x102
//    ctx->r2 = SIGNED(ctx->r16) < 0X102 ? 1 : 0;
//    // beq         $v0, $zero, L_8007A6D8
//    if (ctx->r2 == 0) {
//        // addiu       $a1, $zero, 0x101
//        ctx->r5 = ADD32(0, 0X101);
//        goto L_8007A6D8;
//    }
//    // addiu       $a1, $zero, 0x101
//    ctx->r5 = ADD32(0, 0X101);
//    // j           L_8007A6D8
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//    goto L_8007A6D8;
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//L_8007A6D4:
//    // addiu       $a1, $zero, 0x10
//    ctx->r5 = ADD32(0, 0X10);
//L_8007A6D8:
//    // addu        $s0, $a1, $zero
//    ctx->r16 = ADD32(ctx->r5, 0);
//    // addiu       $a1, $s0, 0x2
//    ctx->r5 = ADD32(ctx->r16, 0X2);
//    // slt         $v0, $s2, $a1
//    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r5) ? 1 : 0;
//    // bne         $v0, $zero, L_8007A6FC
//    if (ctx->r2 != 0) {
//        // slti        $v0, $s2, 0x103
//        ctx->r2 = SIGNED(ctx->r18) < 0X103 ? 1 : 0;
//        goto L_8007A6FC;
//    }
//    // slti        $v0, $s2, 0x103
//    ctx->r2 = SIGNED(ctx->r18) < 0X103 ? 1 : 0;
//    // addiu       $a1, $zero, 0x102
//    ctx->r5 = ADD32(0, 0X102);
//L_8007A6F0:
//    // beq         $v0, $zero, L_8007A6FC
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8007A6FC;
//    }
//    // nop
//
//    // addu        $a1, $s2, $zero
//    ctx->r5 = ADD32(ctx->r18, 0);
//L_8007A6FC:
//    // addu        $s2, $a1, $zero
//    ctx->r18 = ADD32(ctx->r5, 0);
//    // andi        $v1, $v1, 0xFFF
//    ctx->r3 = ctx->r3 & 0XFFF;
//    // sll         $v1, $v1, 12
//    ctx->r3 = S32(ctx->r3) << 12;
//    // andi        $a0, $a0, 0xFFF
//    ctx->r4 = ctx->r4 & 0XFFF;
//    // lui         $v0, 0x600
//    ctx->r2 = S32(0X600 << 16);
//    // lui         $a1, 0x8008
//    ctx->r5 = S32(0X8008 << 16);
//    // lw          $a1, 0x7CB8($a1)
//    ctx->r5 = MEM_W(0X7CB8, ctx->r5);
//    // or          $a0, $a0, $v0
//    ctx->r4 = ctx->r4 | ctx->r2;
//    // lw          $v0, 0x10($a1)
//    ctx->r2 = MEM_W(0X10, ctx->r5);
//    // nop
//
//    // jalr        $v0
//    // or          $a0, $v1, $a0
//    ctx->r4 = ctx->r3 | ctx->r4;
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_5;
//    // or          $a0, $v1, $a0
//    ctx->r4 = ctx->r3 | ctx->r4;
//    after_5:
//    // andi        $v1, $s2, 0x3FF
//    ctx->r3 = ctx->r18 & 0X3FF;
//    // sll         $v1, $v1, 10
//    ctx->r3 = S32(ctx->r3) << 10;
//    // andi        $a0, $s0, 0x3FF
//    ctx->r4 = ctx->r16 & 0X3FF;
//    // lui         $v0, 0x700
//    ctx->r2 = S32(0X700 << 16);
//    // lui         $a1, 0x8008
//    ctx->r5 = S32(0X8008 << 16);
//    // lw          $a1, 0x7CB8($a1)
//    ctx->r5 = MEM_W(0X7CB8, ctx->r5);
//    // or          $a0, $a0, $v0
//    ctx->r4 = ctx->r4 | ctx->r2;
//    // lw          $v0, 0x10($a1)
//    ctx->r2 = MEM_W(0X10, ctx->r5);
//    // nop
//
//    // jalr        $v0
//    // or          $a0, $v1, $a0
//    ctx->r4 = ctx->r3 | ctx->r4;
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_6;
//    // or          $a0, $v1, $a0
//    ctx->r4 = ctx->r3 | ctx->r4;
//    after_6:
//L_8007A758:
//    // lui         $a0, 0x8008
//    ctx->r4 = S32(0X8008 << 16);
//    // addiu       $a0, $a0, 0x7D2C
//    ctx->r4 = ADD32(ctx->r4, 0X7D2C);
//    // addu        $a1, $s1, $zero
//    ctx->r5 = ADD32(ctx->r17, 0);
//    // jal         0x80078AA4
//    // addiu       $a2, $zero, 0x14
//    ctx->r6 = ADD32(0, 0X14);
//    memcpy_recomp(rdram, ctx);
//    goto after_7;
//    // addiu       $a2, $zero, 0x14
//    ctx->r6 = ADD32(0, 0X14);
//    after_7:
//    // addu        $v0, $s1, $zero
//    ctx->r2 = ADD32(ctx->r17, 0);
//    // lw          $ra, 0x1C($sp)
//    ctx->r31 = MEM_W(0X1C, ctx->r29);
//    // lw          $s2, 0x18($sp)
//    ctx->r18 = MEM_W(0X18, ctx->r29);
//    // lw          $s1, 0x14($sp)
//    ctx->r17 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // jr          $ra
//    // addiu       $sp, $sp, 0x20
//    ctx->r29 = ADD32(ctx->r29, 0X20);
//    return;
//    // addiu       $sp, $sp, 0x20
//    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
