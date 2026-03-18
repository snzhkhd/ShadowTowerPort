#include "recomp.h"
#include "disable_warnings.h"

void sub_80031378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bgez        $v1, L_800313B4
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800313B4;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
L_800313B4:
    // sra         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2) >> 3;
    // sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4) << 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_80031400
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80031400;
    }
    // nop

    // lh          $v0, 0x0($s3)
    ctx->r2 = MEM_HS(0X0, ctx->r19);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(0X4, ctx->r19);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $s0, 0x0($v0)
    ctx->r16 = MEM_HS(0X0, ctx->r2);
    // j           L_8003142C
    // nop

    goto L_8003142C;
    // nop

L_80031400:
    // lhu         $v0, 0x2($s3)
    ctx->r2 = MEM_HU(0X2, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(0X8, ctx->r19);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $s0, -0x8($v0)
    ctx->r16 = MEM_HS(-0X8, ctx->r2);
L_8003142C:
    // lbu         $v0, 0x303($s3)
    ctx->r2 = MEM_BU(0X303, ctx->r19);
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // beq         $s0, $s1, L_80031468
    if (ctx->r16 == ctx->r17) {
        // sb          $v0, 0x303($s3)
        MEM_B(0X303, ctx->r19) = ctx->r2;
        goto L_80031468;
    }
    // sb          $v0, 0x303($s3)
    MEM_B(0X303, ctx->r19) = ctx->r2;
    // addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // addiu       $a2, $zero, 0xCA
    ctx->r6 = ADD32(0, 0XCA);
    // lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(0X14, ctx->r19);
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // ori         $a3, $s3, 0x300
    ctx->r7 = ctx->r19 | 0X300;
    // addiu       $v0, $v0, 0xC00
    ctx->r2 = ADD32(ctx->r2, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    sub_8002732C(rdram, ctx);
    goto after_0;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_0:
L_80031468:
    // lbu         $v0, 0x303($s3)
    ctx->r2 = MEM_BU(0X303, ctx->r19);
    // nop

    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // beq         $s0, $s1, L_8003163C
    if (ctx->r16 == ctx->r17) {
        // sb          $v0, 0x303($s3)
        MEM_B(0X303, ctx->r19) = ctx->r2;
        goto L_8003163C;
    }
    // sb          $v0, 0x303($s3)
    MEM_B(0X303, ctx->r19) = ctx->r2;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x76F8
    ctx->r2 = ADD32(ctx->r2, 0X76F8);
    // sll         $v1, $s0, 1
    ctx->r3 = S32(ctx->r16) << 1;
    // addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $s4, $v1, $v0
    ctx->r20 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x13F($s4)
    ctx->r2 = MEM_BU(0X13F, ctx->r20);
    // nop

    // beq         $v0, $zero, L_8003151C
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x4A
        ctx->r5 = ADD32(0, 0X4A);
        goto L_8003151C;
    }
    // addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // addiu       $s2, $s3, 0x300
    ctx->r18 = ADD32(ctx->r19, 0X300);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x3A($a0)
    ctx->r2 = MEM_HU(0X3A, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_1;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_1:
    // addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    // addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // addiu       $s1, $s3, 0x310
    ctx->r17 = ADD32(ctx->r19, 0X310);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // lbu         $a0, 0x140($s4)
    ctx->r4 = MEM_BU(0X140, ctx->r20);
    // lui         $s0, 0x300
    ctx->r16 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    sub_80027440(rdram, ctx);
    goto after_2;
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    after_2:
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    // addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // jal         0x80026ECC
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80026ECC(rdram, ctx);
    goto after_3;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_3:
    // addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // lbu         $a0, 0x13F($s4)
    ctx->r4 = MEM_BU(0X13F, ctx->r20);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    sub_80027440(rdram, ctx);
    goto after_4;
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    after_4:
L_8003151C:
    // lhu         $v0, 0x13C($s4)
    ctx->r2 = MEM_HU(0X13C, ctx->r20);
    // nop

    // beq         $v0, $zero, L_8003163C
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0xFA
        ctx->r5 = ADD32(0, 0XFA);
        goto L_8003163C;
    }
    // addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // addiu       $s1, $s3, 0x300
    ctx->r17 = ADD32(ctx->r19, 0X300);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x38($a0)
    ctx->r2 = MEM_HU(0X38, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_5;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_5:
    // lui         $a0, 0x2416
    ctx->r4 = S32(0X2416 << 16);
    // lhu         $v1, 0x13C($s4)
    ctx->r3 = MEM_HU(0X13C, ctx->r20);
    // ori         $a0, $a0, 0x8E19
    ctx->r4 = ctx->r4 | 0X8E19;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // addiu       $s0, $s3, 0x310
    ctx->r16 = ADD32(ctx->r19, 0X310);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // sra         $v1, $t0, 6
    ctx->r3 = S32(ctx->r8) >> 6;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v1, -0x7E62($at)
    MEM_H(-0X7E62, ctx->r1) = ctx->r3;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v1, $t2, 6
    ctx->r3 = S32(ctx->r10) >> 6;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $v0, -0x7E62($v0)
    ctx->r2 = MEM_HU(-0X7E62, ctx->r2);
    // lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v1, -0x7E78($at)
    MEM_H(-0X7E78, ctx->r1) = ctx->r3;
    // jal         0x80027440
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    sub_80027440(rdram, ctx);
    goto after_6;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    after_6:
    // addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // addiu       $a1, $zero, 0x153
    ctx->r5 = ADD32(0, 0X153);
    // addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // jal         0x80026ECC
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sub_80026ECC(rdram, ctx);
    goto after_7;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_7:
    // addiu       $a1, $zero, 0x15A
    ctx->r5 = ADD32(0, 0X15A);
    // addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E62($v1)
    ctx->r3 = MEM_HU(-0X7E62, ctx->r3);
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E78($a0)
    ctx->r4 = MEM_HU(-0X7E78, ctx->r4);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    sub_80027440(rdram, ctx);
    goto after_8;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    after_8:
    // addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // addiu       $a1, $zero, 0x16A
    ctx->r5 = ADD32(0, 0X16A);
    // addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // jal         0x80026ECC
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sub_80026ECC(rdram, ctx);
    goto after_9;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_9:
L_8003163C:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a1, $zero, 0xC6
    ctx->r5 = ADD32(0, 0XC6);
    // addiu       $a2, $zero, 0x26C
    ctx->r6 = ADD32(0, 0X26C);
    // jal         0x80029548
    // addiu       $a3, $zero, 0x22
    ctx->r7 = ADD32(0, 0X22);
    sub_80029548(rdram, ctx);
    goto after_10;
    // addiu       $a3, $zero, 0x22
    ctx->r7 = ADD32(0, 0X22);
    after_10:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
