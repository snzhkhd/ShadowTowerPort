#include "recomp.h"
#include "disable_warnings.h"

void sub_8005F894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
L_8005F7E0:
    // nop

L_8005F890:
    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_8005FD90
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005FD90;
    }
    // nop

    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // beq         $v0, $zero, L_8005F8D0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005F8D0;
    }
    // nop

    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lhu         $v0, 0x2DC($s2)
    ctx->r2 = MEM_HU(0X2DC, ctx->r18);
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    // andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
L_8005F8D0:
    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_8005FD34
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8005FD34;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lhu         $v1, 0xA($s2)
    ctx->r3 = MEM_HU(0XA, ctx->r18);
    // nop

    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // bne         $v1, $v0, L_8005FD1C
    if (ctx->r3 != ctx->r2) {
        // sh          $zero, 0x4($s4)
        MEM_H(0X4, ctx->r20) = 0;
        goto L_8005FD1C;
    }
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    // lhu         $v1, 0x2DC($s2)
    ctx->r3 = MEM_HU(0X2DC, ctx->r18);
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // beq         $v0, $zero, L_8005FA88
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005FA88;
    }
    // nop

    // lhu         $v0, 0x2E2($s2)
    ctx->r2 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $v1, 0x2E0($s2)
    ctx->r3 = MEM_HU(0X2E0, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // lhu         $a0, 0x13A($v0)
    ctx->r4 = MEM_HU(0X13A, ctx->r2);
    // lbu         $v1, 0x10A($s3)
    ctx->r3 = MEM_BU(0X10A, ctx->r19);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lbu         $a1, 0x11A($v0)
    ctx->r5 = MEM_BU(0X11A, ctx->r2);
    // andi        $v1, $v1, 0x7F
    ctx->r3 = ctx->r3 & 0X7F;
    // sltu        $v0, $v1, $a1
    ctx->r2 = ctx->r3 < ctx->r5 ? 1 : 0;
    // bne         $v0, $zero, L_8005FCB4
    if (ctx->r2 != 0) {
        // subu        $v1, $v1, $a1
        ctx->r3 = SUB32(ctx->r3, ctx->r5);
        goto L_8005FCB4;
    }
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // andi        $v1, $v1, 0x7F
    ctx->r3 = ctx->r3 & 0X7F;
    // lhu         $v0, 0x10A($s3)
    ctx->r2 = MEM_HU(0X10A, ctx->r19);
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // andi        $v0, $v0, 0xFF80
    ctx->r2 = ctx->r2 & 0XFF80;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sh          $v0, 0x10A($s3)
    MEM_H(0X10A, ctx->r19) = ctx->r2;
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // andi        $v1, $v1, 0x80
    ctx->r3 = ctx->r3 & 0X80;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // lhu         $v0, 0x2E2($s2)
    ctx->r2 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $v1, 0x2E0($s2)
    ctx->r3 = MEM_HU(0X2E0, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // nop

    // addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // lbu         $v0, 0x156($v1)
    ctx->r2 = MEM_BU(0X156, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, 0x156($v1)
    MEM_B(0X156, ctx->r3) = ctx->r2;
    // lhu         $v1, 0x2E2($s2)
    ctx->r3 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // nop

    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // lbu         $v0, 0x156($v0)
    ctx->r2 = MEM_BU(0X156, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8005FC98
    if (ctx->r2 != 0) {
        // addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
        goto L_8005FC98;
    }
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // j           L_8005FA6C
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    goto L_8005FA6C;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
L_8005FA48:
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // nop

    // sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
L_8005FA6C:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005FA48
    if (ctx->r2 != 0) {
        // sll         $v0, $s0, 1
        ctx->r2 = S32(ctx->r16) << 1;
        goto L_8005FA48;
    }
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
    // j           L_8005FC88
    // nop

    goto L_8005FC88;
    // nop

L_8005FA88:
    // lw          $v0, 0x2DC($s2)
    ctx->r2 = MEM_W(0X2DC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // beq         $v0, $zero, L_8005FB84
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x2
        ctx->r2 = ctx->r3 & 0X2;
        goto L_8005FB84;
    }
    // andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // beq         $v0, $zero, L_8005FAA8
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x11D
        ctx->r5 = ADD32(0, 0X11D);
        goto L_8005FAA8;
    }
    // addiu       $a1, $zero, 0x11D
    ctx->r5 = ADD32(0, 0X11D);
    // addiu       $a1, $zero, 0x11C
    ctx->r5 = ADD32(0, 0X11C);
L_8005FAA8:
    // lhu         $v0, 0x2E2($s2)
    ctx->r2 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $v1, 0x2E0($s2)
    ctx->r3 = MEM_HU(0X2E0, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $a0, 0x0($v0)
    ctx->r4 = MEM_HS(0X0, ctx->r2);
    // nop

    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // andi        $v1, $v1, 0x80
    ctx->r3 = ctx->r3 & 0X80;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // addu        $a0, $a1, $s3
    ctx->r4 = ADD32(ctx->r5, ctx->r19);
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // andi        $v1, $v1, 0x80
    ctx->r3 = ctx->r3 & 0X80;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // lhu         $a0, 0x2E2($s2)
    ctx->r4 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $v1, 0x2E0($s2)
    ctx->r3 = MEM_HU(0X2E0, ctx->r18);
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // j           L_8005FB64
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    goto L_8005FB64;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_8005FB44:
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // nop

    // sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8005FB64:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005FB44
    if (ctx->r2 != 0) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_8005FB44;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // j           L_8005FC88
    // nop

    goto L_8005FC88;
    // nop

L_8005FB84:
    // lhu         $v0, 0x2E2($s2)
    ctx->r2 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $v1, 0x2E0($s2)
    ctx->r3 = MEM_HU(0X2E0, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lui         $a0, 0x5555
    ctx->r4 = S32(0X5555 << 16);
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
    // addu        $a1, $v0, $s5
    ctx->r5 = ADD32(ctx->r2, ctx->r21);
    // lbu         $v0, 0x11B($a1)
    ctx->r2 = MEM_BU(0X11B, ctx->r5);
    // ori         $a0, $a0, 0x5556
    ctx->r4 = ctx->r4 | 0X5556;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lbu         $v1, 0x140($a1)
    ctx->r3 = MEM_BU(0X140, ctx->r5);
    // lbu         $v0, 0x13F($a1)
    ctx->r2 = MEM_BU(0X13F, ctx->r5);
    // mfhi        $a0
    ctx->r4 = hi;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // nop

    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // bne         $v1, $zero, L_8005FC04
    if (ctx->r3 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8005FC04;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
L_8005FC04:
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x2($a2)
    ctx->r3 = MEM_HU(0X2, ctx->r6);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8005FCB4
    if (ctx->r2 == 0) {
        // subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
        goto L_8005FCB4;
    }
    // subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // sh          $v0, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r2;
    // lbu         $v0, 0x13F($a1)
    ctx->r2 = MEM_BU(0X13F, ctx->r5);
    // nop

    // sb          $v0, 0x140($a1)
    MEM_B(0X140, ctx->r5) = ctx->r2;
    // lhu         $a0, 0x2E2($s2)
    ctx->r4 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $v1, 0x2E0($s2)
    ctx->r3 = MEM_HU(0X2E0, ctx->r18);
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // j           L_8005FC70
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    goto L_8005FC70;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_8005FC50:
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // nop

    // sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8005FC70:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005FC50
    if (ctx->r2 != 0) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_8005FC50;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
L_8005FC88:
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r2;
L_8005FC98:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lhu         $v0, 0x2DC($s2)
    ctx->r2 = MEM_HU(0X2DC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // j           L_8005FCBC
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
    goto L_8005FCBC;
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
L_8005FCB4:
    // jal         0x80057D34
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    sub_80057D34(rdram, ctx);
    goto after_2;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_2:
L_8005FCBC:
    // beq         $s1, $zero, L_8005FD38
    if (ctx->r17 == 0) {
        // addiu       $s0, $s6, -0x2E80
        ctx->r16 = ADD32(ctx->r22, -0X2E80);
        goto L_8005FD38;
    }
    // addiu       $s0, $s6, -0x2E80
    ctx->r16 = ADD32(ctx->r22, -0X2E80);
    // lhu         $a1, 0x2E2($s2)
    ctx->r5 = MEM_HU(0X2E2, ctx->r18);
    // nop

    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // addiu       $v1, $a0, 0x4
    ctx->r3 = ADD32(ctx->r4, 0X4);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_8005FD38
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8005FD38;
    }
    // nop

    // blez        $a0, L_8005FD00
    if (SIGNED(ctx->r4) <= 0) {
        // addiu       $v0, $a1, -0x1
        ctx->r2 = ADD32(ctx->r5, -0X1);
        goto L_8005FD00;
    }
    // addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // j           L_8005FD38
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
    goto L_8005FD38;
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
L_8005FD00:
    // lhu         $v1, 0x2E0($s2)
    ctx->r3 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // blez        $v0, L_8005FD34
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8005FD34;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // j           L_8005FD34
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
    goto L_8005FD34;
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
L_8005FD1C:
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lhu         $v0, 0x2DC($s2)
    ctx->r2 = MEM_HU(0X2DC, ctx->r18);
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    // andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
L_8005FD34:
    // addiu       $s0, $s6, -0x2E80
    ctx->r16 = ADD32(ctx->r22, -0X2E80);
L_8005FD38:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8005FD64
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005FD64;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // sb          $zero, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = 0;
    // sh          $v0, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r2;
L_8005FD64:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_8005FF80
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005FF80;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // sb          $zero, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = 0;
    // j           L_8005FF80
    // sh          $zero, 0xA($s2)
    MEM_H(0XA, ctx->r18) = 0;
    goto L_8005FF80;
    // sh          $zero, 0xA($s2)
    MEM_H(0XA, ctx->r18) = 0;
L_8005FD90:
    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // bne         $v0, $zero, L_8005F7E0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005F7E0;
    }
    // nop

    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8005FDF8
    if (ctx->r2 == 0) {
        // addiu       $s0, $s6, -0x2E80
        ctx->r16 = ADD32(ctx->r22, -0X2E80);
        goto L_8005FDF8;
    }
    // addiu       $s0, $s6, -0x2E80
    ctx->r16 = ADD32(ctx->r22, -0X2E80);
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // bne         $v0, $zero, L_8005FDEC
    if (ctx->r2 != 0) {
        // sh          $zero, 0xC($s4)
        MEM_H(0XC, ctx->r20) = 0;
        goto L_8005FDEC;
    }
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // lhu         $v1, 0x2E2($s2)
    ctx->r3 = MEM_HU(0X2E2, ctx->r18);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // blez        $v0, L_8005FDF8
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8005FDF8;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // j           L_8005FDF8
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
    goto L_8005FDF8;
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
L_8005FDEC:
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
    // addiu       $s0, $s6, -0x2E80
    ctx->r16 = ADD32(ctx->r22, -0X2E80);
L_8005FDF8:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_8005FE68
    if (ctx->r2 == 0) {
        // addiu       $v1, $s6, -0x2E80
        ctx->r3 = ADD32(ctx->r22, -0X2E80);
        goto L_8005FE68;
    }
    // addiu       $v1, $s6, -0x2E80
    ctx->r3 = ADD32(ctx->r22, -0X2E80);
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lhu         $a0, 0x2E0($s2)
    ctx->r4 = MEM_HU(0X2E0, ctx->r18);
    // addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_8005FE5C
    if (ctx->r2 != ctx->r3) {
        // sh          $zero, 0xC($s0)
        MEM_H(0XC, ctx->r16) = 0;
        goto L_8005FE5C;
    }
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // lhu         $a0, 0x2E2($s2)
    ctx->r4 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8005FE64
    if (ctx->r3 == 0) {
        // addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_8005FE64;
    }
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // j           L_8005FE64
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
    goto L_8005FE64;
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
L_8005FE5C:
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
L_8005FE64:
    // addiu       $v1, $s6, -0x2E80
    ctx->r3 = ADD32(ctx->r22, -0X2E80);
L_8005FE68:
    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_8005FF80
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005FF80;
    }
    // nop

    // lhu         $a0, 0x2E2($s2)
    ctx->r4 = MEM_HU(0X2E2, ctx->r18);
    // sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // lhu         $v1, 0x2E0($s2)
    ctx->r3 = MEM_HU(0X2E0, ctx->r18);
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8005FEC4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005FEC4;
    }
    // nop

    // jal         0x80057D34
    // nop

    sub_80057D34(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // j           L_8005FF80
    // nop

    goto L_8005FF80;
    // nop

L_8005FEC4:
    // lhu         $v0, 0x2DC($s2)
    ctx->r2 = MEM_HU(0X2DC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8005FF00
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_8005FF00;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // lhu         $v1, 0x13A($v0)
    ctx->r3 = MEM_HU(0X13A, ctx->r2);
    // j           L_8005FF18
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    goto L_8005FF18;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
L_8005FF00:
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
L_8005FF18:
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lbu         $s1, 0x11D($v0)
    ctx->r17 = MEM_BU(0X11D, ctx->r2);
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lhu         $v1, 0x2DC($s2)
    ctx->r3 = MEM_HU(0X2DC, ctx->r18);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r2;
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // beq         $s1, $s7, L_8005FF80
    if (ctx->r17 == ctx->r23) {
        // sh          $v1, 0x2DC($s2)
        MEM_H(0X2DC, ctx->r18) = ctx->r3;
        goto L_8005FF80;
    }
    // sh          $v1, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r3;
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // addiu       $a1, $s1, 0x258
    ctx->r5 = ADD32(ctx->r17, 0X258);
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // addiu       $s0, $s0, -0x7378
    ctx->r16 = ADD32(ctx->r16, -0X7378);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_10;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_10:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_11;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // addu        $s7, $s1, $zero
    ctx->r23 = ADD32(ctx->r17, 0);
L_8005FF80:
    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // jal         0x8002E310
    // nop

    sub_8002E310(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // lbu         $a0, 0x2E4($s2)
    ctx->r4 = MEM_BU(0X2E4, ctx->r18);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_8005FFA8
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005FFA8;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_8005FFA8:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_8005F890
    recomp_vram_call(rdram, ctx, 0x8005F890);
    return;
    // sb          $v0, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = ctx->r2;
    // jal         0x8005F4FC
    // nop

    sub_8005F4FC(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(0X4, ctx->r18);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // jal         0x80058C24
    // nop

    PadStartCom(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
;}
