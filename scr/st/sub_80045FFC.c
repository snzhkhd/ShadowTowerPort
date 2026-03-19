#include "recomp.h"
#include "disable_warnings.h"

void ProcessAssetLoadQueue(uint8_t* rdram, recomp_context* ctx) 
{
 //   printf("ProcessAssetLoadQueue\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $s0, -0x7428($v0)
    ctx->r16 = MEM_W(-0X7428, ctx->r2);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $v1, $v0, L_8004624C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004624C;
    }
    // nop

    // lbu         $v1, 0x10($s0)
    ctx->r3 = MEM_BU(0X10, ctx->r16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8004624C
    if (ctx->r3 != ctx->r2) {
        // addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
        goto L_8004624C;
    }
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // lw          $s1, 0x20($s0)
    ctx->r17 = MEM_W(0X20, ctx->r16);
    // sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
L_80046048:
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // subu        $v1, $v0, $s4
    ctx->r3 = SUB32(ctx->r2, ctx->r20);
    // lh          $v0, 0xA($s0)
    ctx->r2 = MEM_HS(0XA, ctx->r16);
    // lhu         $s3, 0xA($s0)
    ctx->r19 = MEM_HU(0XA, ctx->r16);
    // beq         $v0, $zero, L_80046100
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80046100;
    }
    // nop

    // lh          $a0, 0x8($s0)
    ctx->r4 = MEM_HS(0X8, ctx->r16);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // sll         $s2, $a3, 1
    ctx->r18 = S32(ctx->r7) << 1;
    // slt         $v0, $v1, $s2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
    // beq         $v0, $zero, L_800460E4
    if (ctx->r2 == 0) {
        // addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
        goto L_800460E4;
    }
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_80046090
    if (ctx->r4 != 0) {
        // nop
    
        goto L_80046090;
    }
    // nop

    // break       7
    do_break(2147770508);
L_80046090:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_800460A8
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800460A8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_800460A8
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_800460A8;
    }
    // nop

    // break       6
    do_break(2147770532);
L_800460A8:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // sra         $s2, $v0, 1
    ctx->r18 = S32(ctx->r2) >> 1;
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // beq         $v0, $zero, L_8004620C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004620C;
    }
    // nop

    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // jal         0x80079D0C
    // sh          $s2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r18;
    LoadImage(rdram, ctx);
    goto after_0;
    // sh          $s2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r18;
    after_0:
    // lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(0X6, ctx->r16);
    // subu        $v0, $s3, $s2
    ctx->r2 = SUB32(ctx->r19, ctx->r18);
    // sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // j           L_8004620C
    // sh          $v1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r3;
    goto L_8004620C;
    // sh          $v1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r3;
L_800460E4:
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // jal         0x80079D0C
    // sh          $s3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r19;
    LoadImage(rdram, ctx);
    goto after_1;
    // sh          $s3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r19;
    after_1:
    // addu        $s4, $s4, $s2
    ctx->r20 = ADD32(ctx->r20, ctx->r18);
    // addu        $s1, $s1, $s2
    ctx->r17 = ADD32(ctx->r17, ctx->r18);
    // j           L_80046048
    // sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    goto L_80046048;
    // sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
L_80046100:
    // slti        $v0, $v1, 0x10
    ctx->r2 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80046210
    if (ctx->r2 != 0) {
        // addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
        goto L_80046210;
    }
    // addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(0X0, ctx->r17);
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    // bne         $a1, $v0, L_8004616C
    if (ctx->r5 != ctx->r2) {
        // nop
    
        goto L_8004616C;
    }
    // nop

    // lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(0X2, ctx->r17);
    // lhu         $v0, 0xA($s1)
    ctx->r2 = MEM_HU(0XA, ctx->r17);
    // nop

    // bne         $v1, $v0, L_8004616C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004616C;
    }
    // nop

    // lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(0X4, ctx->r17);
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // bne         $a0, $v0, L_8004616C
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_8004616C;
    }
    // nop

    // lhu         $v1, 0x6($s1)
    ctx->r3 = MEM_HU(0X6, ctx->r17);
    // lhu         $v0, 0xE($s1)
    ctx->r2 = MEM_HU(0XE, ctx->r17);
    // nop

    // bne         $v1, $v0, L_8004616C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004616C;
    }
    // nop

    // beq         $a0, $zero, L_8004616C
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8004616C;
    }
    // nop

    // bne         $v1, $zero, L_800461A8
    if (ctx->r3 != 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_800461A8;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8004616C:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // jal         0x80045FB8
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    sub_80045FB8(rdram, ctx);
    goto after_2;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    after_2:
    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_8004618C:
    // addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // beq         $v0, $zero, L_8004618C
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
        goto L_8004618C;
    }
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // j           L_8004624C
    // nop

    goto L_8004624C;
    // nop

L_800461A8:
    // bne         $a1, $v0, L_800461E0
    if (ctx->r5 != ctx->r2) {
        // addiu       $s4, $s4, 0x10
        ctx->r20 = ADD32(ctx->r20, 0X10);
        goto L_800461E0;
    }
    // addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(0X2C, ctx->r16);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    // jalr        $v1
    // sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
    goto after_5;
    // sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    after_5:
    // jal         0x80015848
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    NextCdTask(rdram, ctx);
    goto after_6;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // j           L_8004624C
    // nop

    goto L_8004624C;
    // nop

L_800461E0:
    // sh          $a2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r6;
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // j           L_80046048
    // sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    goto L_80046048;
    // sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
L_8004620C:
    // addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
L_80046210:
    // lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(0X28, ctx->r16);
    // jal         0x80015A94
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_80015A94(rdram, ctx);
    goto after_7;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_7:
    // jal         0x80045FB8
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80045FB8(rdram, ctx);
    goto after_8;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // jal         0x80079A60
    // nop

    ST_DrawSync(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_80046238:
    // addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_10;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_10:
    // beq         $v0, $zero, L_80046238
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
        goto L_80046238;
    }
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_8004624C:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
