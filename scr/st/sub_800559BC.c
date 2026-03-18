#include "recomp.h"
#include "disable_warnings.h"

void sub_800559BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // sw          $s2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r18;
    // lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // addiu       $s2, $s2, -0x31B0
    ctx->r18 = ADD32(ctx->r18, -0X31B0);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // sw          $ra, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r31;
    // sw          $s3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r17;
    // jal         0x80014D5C
    // sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    sub_80014D5C(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // addiu       $s0, $s0, 0x7590
    ctx->r16 = ADD32(ctx->r16, 0X7590);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x59
    ctx->r6 = ADD32(0, 0X59);
    sub_80014D5C(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x59
    ctx->r6 = ADD32(0, 0X59);
    after_1:
    // addiu       $a0, $s2, 0x88
    ctx->r4 = ADD32(ctx->r18, 0X88);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    sub_80014D5C(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    after_2:
    // lui         $t4, 0x7FFF
    ctx->r12 = S32(0X7FFF << 16);
    // ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // lui         $t3, 0xFFFD
    ctx->r11 = S32(0XFFFD << 16);
    // ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // lui         $t2, 0xFFFE
    ctx->r10 = S32(0XFFFE << 16);
    // ori         $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 | 0XFFFF;
    // lui         $t1, 0xFFFF
    ctx->r9 = S32(0XFFFF << 16);
    // ori         $t1, $t1, 0x7FFF
    ctx->r9 = ctx->r9 | 0X7FFF;
    // addiu       $a0, $s2, -0x12C8
    ctx->r4 = ADD32(ctx->r18, -0X12C8);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // addiu       $s1, $s2, -0x1448
    ctx->r17 = ADD32(ctx->r18, -0X1448);
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, -0x4930
    ctx->r2 = ADD32(ctx->r2, -0X4930);
    // addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    // addiu       $v1, $zero, 0x41
    ctx->r3 = ADD32(0, 0X41);
    // addiu       $a3, $zero, 0x22
    ctx->r7 = ADD32(0, 0X22);
    // sw          $s3, 0x160C($s1)
    MEM_W(0X160C, ctx->r17) = ctx->r19;
    // sw          $s3, 0x1610($s1)
    MEM_W(0X1610, ctx->r17) = ctx->r19;
    // sw          $s3, 0x1614($s1)
    MEM_W(0X1614, ctx->r17) = ctx->r19;
    // sh          $t0, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r8;
    // sh          $t0, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r8;
    // sh          $t0, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = ctx->r8;
    // sh          $t0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r8;
    // sh          $v1, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r3;
    // sh          $v1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r3;
    // sh          $v1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r3;
    // sh          $v1, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r3;
    // sh          $v1, 0x42($v0)
    MEM_H(0X42, ctx->r2) = ctx->r3;
    // sh          $v1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r3;
    // sh          $v1, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r3;
    // sh          $v1, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r3;
    // sh          $v1, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r3;
    // sh          $a3, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r7;
    // sh          $a3, 0x34($v0)
    MEM_H(0X34, ctx->r2) = ctx->r7;
    // sh          $a3, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = ctx->r7;
    // sh          $a3, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r7;
    // sh          $v1, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r3;
    // sh          $v1, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r3;
    // sh          $v1, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r3;
    // sh          $t0, 0x56($v0)
    MEM_H(0X56, ctx->r2) = ctx->r8;
    // sh          $a3, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r7;
    // sh          $v1, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r3;
    // sh          $v1, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r3;
    // sh          $v1, 0x58($v0)
    MEM_H(0X58, ctx->r2) = ctx->r3;
    // sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // sh          $v1, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r3;
    // sh          $v1, 0x3E($v0)
    MEM_H(0X3E, ctx->r2) = ctx->r3;
    // sh          $v1, 0x40($v0)
    MEM_H(0X40, ctx->r2) = ctx->r3;
    // sh          $v1, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r3;
    // sh          $v1, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r3;
    // sh          $t0, 0x48($v0)
    MEM_H(0X48, ctx->r2) = ctx->r8;
    // sh          $t0, 0x64($v0)
    MEM_H(0X64, ctx->r2) = ctx->r8;
    // sh          $t0, 0x66($v0)
    MEM_H(0X66, ctx->r2) = ctx->r8;
    // sh          $t0, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r8;
    // sh          $t0, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r8;
    // addiu       $v0, $zero, 0x10C
    ctx->r2 = ADD32(0, 0X10C);
    // sb          $zero, 0x16DC($s1)
    MEM_B(0X16DC, ctx->r17) = 0;
    // sh          $v0, 0x13A($s0)
    MEM_H(0X13A, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sb          $v0, 0x156($s0)
    MEM_B(0X156, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x10E
    ctx->r2 = ADD32(0, 0X10E);
    // sh          $v0, 0x13C($s0)
    MEM_H(0X13C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x157($s0)
    MEM_B(0X157, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x139
    ctx->r2 = ADD32(0, 0X139);
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // sh          $v0, 0x13E($s0)
    MEM_H(0X13E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x138
    ctx->r2 = ADD32(0, 0X138);
    // sh          $v0, 0x140($s0)
    MEM_H(0X140, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x113
    ctx->r2 = ADD32(0, 0X113);
    // sh          $v0, 0x142($s0)
    MEM_H(0X142, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x11C
    ctx->r2 = ADD32(0, 0X11C);
    // sh          $v0, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // sb          $v0, 0x15B($s0)
    MEM_B(0X15B, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x11D
    ctx->r2 = ADD32(0, 0X11D);
    // sh          $v0, 0x146($s0)
    MEM_H(0X146, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sb          $v0, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x11E
    ctx->r2 = ADD32(0, 0X11E);
    // sh          $v0, 0x148($s0)
    MEM_H(0X148, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // sb          $v0, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x12E
    ctx->r2 = ADD32(0, 0X12E);
    // sh          $v0, 0x14A($s0)
    MEM_H(0X14A, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // addiu       $v1, $zero, -0x61
    ctx->r3 = ADD32(0, -0X61);
    // sb          $t0, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r8;
    // sb          $t0, 0x159($s0)
    MEM_B(0X159, ctx->r16) = ctx->r8;
    // sb          $t0, 0x15A($s0)
    MEM_B(0X15A, ctx->r16) = ctx->r8;
    // sh          $v0, 0x14C($s0)
    MEM_H(0X14C, ctx->r16) = ctx->r2;
    // sb          $t0, 0x15F($s0)
    MEM_B(0X15F, ctx->r16) = ctx->r8;
    // lw          $v0, 0x1444($s1)
    ctx->r2 = MEM_W(0X1444, ctx->r17);
    // addiu       $a3, $zero, -0x7
    ctx->r7 = ADD32(0, -0X7);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x19
    ctx->r3 = ADD32(0, -0X19);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lw          $v1, 0x1440($s1)
    ctx->r3 = MEM_W(0X1440, ctx->r17);
    // and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // sw          $v0, 0x1444($s1)
    MEM_W(0X1444, ctx->r17) = ctx->r2;
    // and         $v1, $v1, $t4
    ctx->r3 = ctx->r3 & ctx->r12;
    // sw          $v1, 0x1440($s1)
    MEM_W(0X1440, ctx->r17) = ctx->r3;
    // addiu       $v1, $zero, -0x2
    ctx->r3 = ADD32(0, -0X2);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x1444($s1)
    MEM_W(0X1444, ctx->r17) = ctx->r2;
    // and         $v0, $v0, $t3
    ctx->r2 = ctx->r2 & ctx->r11;
    // and         $v0, $v0, $t2
    ctx->r2 = ctx->r2 & ctx->r10;
    // and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // addiu       $v1, $zero, -0x4001
    ctx->r3 = ADD32(0, -0X4001);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x2001
    ctx->r3 = ADD32(0, -0X2001);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x1001
    ctx->r3 = ADD32(0, -0X1001);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x801
    ctx->r3 = ADD32(0, -0X801);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x401
    ctx->r3 = ADD32(0, -0X401);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x201
    ctx->r3 = ADD32(0, -0X201);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x101
    ctx->r3 = ADD32(0, -0X101);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x81
    ctx->r3 = ADD32(0, -0X81);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x1444($s1)
    MEM_W(0X1444, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // sw          $zero, 0x1440($s1)
    MEM_W(0X1440, ctx->r17) = 0;
    // sh          $v0, 0x14E($s0)
    MEM_H(0X14E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x58
    ctx->r2 = ADD32(0, 0X58);
    // sh          $v0, 0x150($s0)
    MEM_H(0X150, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xF3
    ctx->r2 = ADD32(0, 0XF3);
    // sh          $v0, 0x152($s0)
    MEM_H(0X152, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x85
    ctx->r2 = ADD32(0, 0X85);
    // sb          $t0, 0x160($s0)
    MEM_B(0X160, ctx->r16) = ctx->r8;
    // sb          $t0, 0x161($s0)
    MEM_B(0X161, ctx->r16) = ctx->r8;
    // sb          $t0, 0x162($s0)
    MEM_B(0X162, ctx->r16) = ctx->r8;
    // sh          $v0, 0x154($s0)
    MEM_H(0X154, ctx->r16) = ctx->r2;
    // jal         0x80014D5C
    // sb          $t0, 0x163($s0)
    MEM_B(0X163, ctx->r16) = ctx->r8;
    sub_80014D5C(rdram, ctx);
    goto after_3;
    // sb          $t0, 0x163($s0)
    MEM_B(0X163, ctx->r16) = ctx->r8;
    after_3:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    sub_80014D5C(rdram, ctx);
    goto after_4;
    // addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_4:
    // addiu       $a0, $s2, -0x1208
    ctx->r4 = ADD32(ctx->r18, -0X1208);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    sub_80014D5C(rdram, ctx);
    goto after_5;
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    after_5:
    // addiu       $a0, $s2, -0xC08
    ctx->r4 = ADD32(ctx->r18, -0XC08);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    sub_80014D5C(rdram, ctx);
    goto after_6;
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    after_6:
    // addiu       $a0, $s2, -0x608
    ctx->r4 = ADD32(ctx->r18, -0X608);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    sub_80014D5C(rdram, ctx);
    goto after_7;
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    after_7:
    // addiu       $a0, $s2, 0x30
    ctx->r4 = ADD32(ctx->r18, 0X30);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    sub_80014D5C(rdram, ctx);
    goto after_8;
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_8:
    // addiu       $a0, $s2, 0x60
    ctx->r4 = ADD32(ctx->r18, 0X60);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    sub_80014D5C(rdram, ctx);
    goto after_9;
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_9:
    // addiu       $a0, $s2, 0x74
    ctx->r4 = ADD32(ctx->r18, 0X74);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    sub_80014D5C(rdram, ctx);
    goto after_10;
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_10:
    // addiu       $a0, $s2, 0x29C
    ctx->r4 = ADD32(ctx->r18, 0X29C);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    sub_80014D5C(rdram, ctx);
    goto after_11;
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_11:
    // sw          $s3, 0x16E0($s1)
    MEM_W(0X16E0, ctx->r17) = ctx->r19;
    // lw          $ra, 0xA0($sp)
    ctx->r31 = MEM_W(0XA0, ctx->r29);
    // lw          $s3, 0x9C($sp)
    ctx->r19 = MEM_W(0X9C, ctx->r29);
    // lw          $s2, 0x98($sp)
    ctx->r18 = MEM_W(0X98, ctx->r29);
    // lw          $s1, 0x94($sp)
    ctx->r17 = MEM_W(0X94, ctx->r29);
    // lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(0X90, ctx->r29);
    // addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // jr          $ra
    // nop

    return;
    // nop

;}
