#include "recomp.h"
#include "disable_warnings.h"

void sub_80026228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // addiu       $t2, $zero, 0x270F
    ctx->r10 = ADD32(0, 0X270F);
    // slti        $v0, $a0, 0x2710
    ctx->r2 = SIGNED(ctx->r4) < 0X2710 ? 1 : 0;
    // beq         $v0, $zero, L_80026240
    if (ctx->r2 == 0) {
        // addu        $t0, $a2, $zero
        ctx->r8 = ADD32(ctx->r6, 0);
        goto L_80026240;
    }
    // addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
L_80026240:
    // sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_800262A4
    if (ctx->r2 == 0) {
        // lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
        goto L_800262A4;
    }
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, -0xC0C
    ctx->r4 = ADD32(ctx->r4, -0XC0C);
    // sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9) << 2;
    // addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $t1, 0x1
    ctx->r3 = ADD32(ctx->r9, 0X1);
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $t1, 0x2
    ctx->r3 = ADD32(ctx->r9, 0X2);
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $t1, 0x3
    ctx->r3 = ADD32(ctx->r9, 0X3);
    // j           L_80026380
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    goto L_80026380;
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_800262A4:
    // slti        $v0, $v1, 0x64
    ctx->r2 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
    // beq         $v0, $zero, L_800262E4
    if (ctx->r2 == 0) {
        // addiu       $a0, $a0, -0xC0C
        ctx->r4 = ADD32(ctx->r4, -0XC0C);
        goto L_800262E4;
    }
    // addiu       $a0, $a0, -0xC0C
    ctx->r4 = ADD32(ctx->r4, -0XC0C);
    // sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9) << 2;
    // addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $t1, 0x1
    ctx->r3 = ADD32(ctx->r9, 0X1);
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $t1, 0x2
    ctx->r3 = ADD32(ctx->r9, 0X2);
    // j           L_8002635C
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    goto L_8002635C;
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_800262E4:
    // slti        $v0, $v1, 0x3E8
    ctx->r2 = SIGNED(ctx->r3) < 0X3E8 ? 1 : 0;
    // beq         $v0, $zero, L_80026310
    if (ctx->r2 == 0) {
        // lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
        goto L_80026310;
    }
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, -0xC0C
    ctx->r4 = ADD32(ctx->r4, -0XC0C);
    // sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9) << 2;
    // addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $t1, 0x1
    ctx->r3 = ADD32(ctx->r9, 0X1);
    // j           L_80026338
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    goto L_80026338;
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_80026310:
    // addiu       $a0, $a0, -0xC0C
    ctx->r4 = ADD32(ctx->r4, -0XC0C);
    // sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9) << 2;
    // addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // addiu       $v1, $t1, 0x1
    ctx->r3 = ADD32(ctx->r9, 0X1);
L_80026338:
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // addiu       $v1, $t1, 0x2
    ctx->r3 = ADD32(ctx->r9, 0X2);
L_8002635C:
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // addiu       $v1, $t1, 0x3
    ctx->r3 = ADD32(ctx->r9, 0X3);
L_80026380:
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // lui         $v1, 0x1062
    ctx->r3 = S32(0X1062 << 16);
    // ori         $v1, $v1, 0x4DD3
    ctx->r3 = ctx->r3 | 0X4DD3;
    // sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10) << 16;
    // sra         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) >> 16;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a3, 0x51EB
    ctx->r7 = S32(0X51EB << 16);
    // ori         $a3, $a3, 0x851F
    ctx->r7 = ctx->r7 | 0X851F;
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v1, $v0, 6
    ctx->r3 = S32(ctx->r2) >> 6;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $a1, $v1, 5
    ctx->r5 = S32(ctx->r3) << 5;
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5) << 3;
    // subu        $a1, $t2, $a1
    ctx->r5 = SUB32(ctx->r10, ctx->r5);
    // sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5) << 16;
    // sra         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) >> 16;
    // mult        $v0, $a3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // mfhi        $v0
    ctx->r2 = hi;
    // lui         $a3, 0x6666
    ctx->r7 = S32(0X6666 << 16);
    // ori         $a3, $a3, 0x6667
    ctx->r7 = ctx->r7 | 0X6667;
    // mult        $v1, $t0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a2, $a2, 31
    ctx->r6 = S32(ctx->r6) >> 31;
    // sra         $a0, $v0, 5
    ctx->r4 = S32(ctx->r2) >> 5;
    // subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // mflo        $v1
    ctx->r3 = lo;
    // sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5) << 16;
    // sra         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) >> 16;
    // mult        $v0, $a3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a2, $a2, 31
    ctx->r6 = S32(ctx->r6) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // addiu       $a3, $a3, -0xC0C
    ctx->r7 = ADD32(ctx->r7, -0XC0C);
    // mult        $a0, $t0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9) << 2;
    // addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // addiu       $v1, $t1, 0x1
    ctx->r3 = ADD32(ctx->r9, 0X1);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v1, $t2, 2
    ctx->r3 = S32(ctx->r10) >> 2;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // mflo        $t4
    ctx->r12 = lo;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // mult        $v1, $t0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // addiu       $a0, $t4, 0x60
    ctx->r4 = ADD32(ctx->r12, 0X60);
    // sb          $a0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r4;
    // addiu       $a0, $t1, 0x2
    ctx->r4 = ADD32(ctx->r9, 0X2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // mflo        $a2
    ctx->r6 = lo;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // mult        $a1, $t0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // addiu       $v1, $a2, 0x60
    ctx->r3 = ADD32(ctx->r6, 0X60);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // addiu       $v1, $t1, 0x3
    ctx->r3 = ADD32(ctx->r9, 0X3);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // mflo        $t0
    ctx->r8 = lo;
    // addiu       $v1, $t0, 0x60
    ctx->r3 = ADD32(ctx->r8, 0X60);
    // jr          $ra
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    return;
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
;}
