#include "recomp.h"
#include "disable_warnings.h"


int countOTag(uint8_t* rdram, uint32_t otBase, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        uint32_t entry = MEM_W(0, otBase + i * 4);
        uint32_t nextLink = otBase + (i - 1) * 4;
        // если запись != просто ссылка на предыдущий — значит тут примитив
        if (i == 0) { if (entry != 0x00FFFFFF) count++; }
        else if (entry != (nextLink & 0x00FFFFFF)) count++;
    }
    return count;
}


void sub_80020A80(uint8_t* rdram, recomp_context* ctx) 
{
    //printf("[FEEDBACK-IN] AC=%08X B0=%08X B4=%08X B8=%08X BC=%08X C0=%08X C4=%08X C8=%08X CC=%08X D0=%08X D4=%08X D8=%08X\n",
    //    MEM_W(0, 0x801653AC), MEM_W(0, 0x801653B0), MEM_W(0, 0x801653B4),
    //    MEM_W(0, 0x801653B8), MEM_W(0, 0x801653BC), MEM_W(0, 0x801653C0),
    //    MEM_W(0, 0x801653C4), MEM_W(0, 0x801653C8), MEM_W(0, 0x801653CC),
    //    MEM_W(0, 0x801653D0), MEM_W(0, 0x801653D4), MEM_W(0, 0x801653D8));
   // printf("[STACK] ctx->r29=%08X v30_addr=%08X\n", ctx->r29, ctx->r29 + 0x10);


    //uint32_t structPtr = MEM_W(0, 0x80165394);
    //printf("[PRIM-ALLOC] dword_80165394=%08X [+0]=%08X [+4]=%08X [+8]=%08X [+C]=%08X\n",
    //    structPtr,
    //    MEM_W(0, structPtr),
    //    MEM_W(4, structPtr),
    //    MEM_W(8, structPtr),
    //    MEM_W(0xC, structPtr));

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x1028
    ctx->r29 = ADD32(ctx->r29, -0X1028);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sw          $ra, 0x1020($sp)
    MEM_W(0X1020, ctx->r29) = ctx->r31;
    // sw          $s3, 0x101C($sp)
    MEM_W(0X101C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x1018($sp)
    MEM_W(0X1018, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1014($sp)
    MEM_W(0X1014, ctx->r29) = ctx->r17;
    // sw          $s0, 0x1010($sp)
    MEM_W(0X1010, ctx->r29) = ctx->r16;
    // lw          $v0, 0x6DF4($v0)
    ctx->r2 = MEM_W(0X6DF4, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80020AD0
    if (ctx->r2 == 0) {
        // lui         $s2, 0x1F80
        ctx->r18 = S32(0X1F80 << 16);
        goto L_80020AD0;
    }
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x30C($v0)
    ctx->r2 = MEM_W(0X30C, ctx->r2);
    // j           L_80020AE4
    // sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
    goto L_80020AE4;
    // sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
L_80020AD0:
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x308($v0)
    ctx->r2 = MEM_W(0X308, ctx->r2);
    // nop

    // sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
L_80020AE4:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // addiu       $s0, $s0, -0x2F70
    ctx->r16 = ADD32(ctx->r16, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // sw          $v0, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = ctx->r2;
    // lw          $a0, 0xE4($v1)
    ctx->r4 = MEM_W(0XE4, ctx->r3);
    // lw          $a1, 0x304($v1)
    ctx->r5 = MEM_W(0X304, ctx->r3);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // sw          $a0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r4;
    // lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(0X8, ctx->r5);
    // lw          $a0, 0x304($v1)
    ctx->r4 = MEM_W(0X304, ctx->r3);
    // sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(0X4, ctx->r4);
    // addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // sh          $v0, 0x92($s2)
    MEM_H(0X92, ctx->r18) = ctx->r2;
    // lw          $a0, 0x31C($v1)
    ctx->r4 = MEM_W(0X31C, ctx->r3);
    // lw          $a1, 0x320($v1)
    ctx->r5 = MEM_W(0X320, ctx->r3);
    // lw          $a2, 0x324($v1)
    ctx->r6 = MEM_W(0X324, ctx->r3);
    // lw          $a3, 0x328($v1)
    ctx->r7 = MEM_W(0X328, ctx->r3);
    // lw          $t0, 0x32C($v1)
    ctx->r8 = MEM_W(0X32C, ctx->r3);
    // lw          $t1, 0x330($v1)
    ctx->r9 = MEM_W(0X330, ctx->r3);
    // lw          $t2, 0x334($v1)
    ctx->r10 = MEM_W(0X334, ctx->r3);
    // lw          $t3, 0x338($v1)
    ctx->r11 = MEM_W(0X338, ctx->r3);
    // lw          $t4, 0x33C($v1)
    ctx->r12 = MEM_W(0X33C, ctx->r3);
    // lw          $t5, 0x340($v1)
    ctx->r13 = MEM_W(0X340, ctx->r3);
    // lw          $t6, 0x344($v1)
    ctx->r14 = MEM_W(0X344, ctx->r3);
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sh          $v0, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r2;
    // sw          $a0, 0x1B0($s2)
    MEM_W(0X1B0, ctx->r18) = ctx->r4;
    // sw          $a1, 0x1B4($s2)
    MEM_W(0X1B4, ctx->r18) = ctx->r5;
    // sw          $a2, 0x1B8($s2)
    MEM_W(0X1B8, ctx->r18) = ctx->r6;
    // sw          $a3, 0x1BC($s2)
    MEM_W(0X1BC, ctx->r18) = ctx->r7;
    // sw          $t0, 0x1C0($s2)
    MEM_W(0X1C0, ctx->r18) = ctx->r8;
    // sw          $t1, 0x1C4($s2)
    MEM_W(0X1C4, ctx->r18) = ctx->r9;
    // sw          $t2, 0x1CC($s2)
    MEM_W(0X1CC, ctx->r18) = ctx->r10;
    // sw          $t3, 0x1D0($s2)
    MEM_W(0X1D0, ctx->r18) = ctx->r11;
    // sw          $t4, 0x1D4($s2)
    MEM_W(0X1D4, ctx->r18) = ctx->r12;
    // sw          $t5, 0x1D8($s2)
    MEM_W(0X1D8, ctx->r18) = ctx->r13;
    // sw          $t7, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r15;
    // sw          $t6, 0x1DC($s2)
    MEM_W(0X1DC, ctx->r18) = ctx->r14;
    // lw          $v0, 0x348($v1)
    ctx->r2 = MEM_W(0X348, ctx->r3);
    // jal         0x80078AC4
    // sw          $v0, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = ctx->r2;
    after_0:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // lbu         $a0, 0x6DFC($s0)
    ctx->r4 = MEM_BU(0X6DFC, ctx->r16);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // andi        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 & 0X2;
    // beq         $v0, $zero, L_80020BE4
    if (ctx->r2 == 0) {
        // sw          $v1, 0x6DF8($s0)
        MEM_W(0X6DF8, ctx->r16) = ctx->r3;
        goto L_80020BE4;
    }
    // sw          $v1, 0x6DF8($s0)
    MEM_W(0X6DF8, ctx->r16) = ctx->r3;
    // andi        $v0, $a0, 0x10
    ctx->r2 = ctx->r4 & 0X10;
    // beq         $v0, $zero, L_80020BD4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020BD4;
    }
    // nop

    // sra         $v1, $v1, 13
    ctx->r3 = S32(ctx->r3) >> 13;
    // addiu       $v0, $zero, -0x78
    ctx->r2 = ADD32(0, -0X78);
    // j           L_80020BE8
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_80020BE8;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80020BD4:
    // sra         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3) >> 11;
    // addiu       $v0, $zero, -0x60
    ctx->r2 = ADD32(0, -0X60);
    // j           L_80020BE8
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_80020BE8;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80020BE4:
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_80020BE8:
    // sb          $v0, 0x46($s2)
    MEM_B(0X46, ctx->r18) = ctx->r2;
    // sb          $v0, 0x45($s2)
    MEM_B(0X45, ctx->r18) = ctx->r2;
    // sb          $v0, 0x44($s2)
    MEM_B(0X44, ctx->r18) = ctx->r2;
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v1, 0x6DFC($v1)
    ctx->r3 = MEM_BU(0X6DFC, ctx->r3);
    // nop

    // andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // beq         $v0, $zero, L_80020C44
    if (ctx->r2 == 0) {
        // addiu       $s3, $zero, 0x6
        ctx->r19 = ADD32(0, 0X6);
        goto L_80020C44;
    }
    // addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // sll         $t4, $s3, 4
    ctx->r12 = S32(ctx->r19) << 4;
    // sll         $t5, $t8, 4
    ctx->r13 = S32(ctx->r24) << 4;
    // sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25) << 4;
    // ctc2        $t4, $21
    gte_ctc2(ctx, 12, 21);
    // ctc2        $t5, $22
    gte_ctc2(ctx, 13, 22);
    // ctc2        $t6, $23
    gte_ctc2(ctx, 14, 23);
    // j           L_80020CA0
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    goto L_80020CA0;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
L_80020C44:
    // andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // beq         $v0, $zero, L_80020C78
    if (ctx->r2 == 0) {
        // addiu       $s3, $zero, 0x2
        ctx->r19 = ADD32(0, 0X2);
        goto L_80020C78;
    }
    // addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // addu        $t9, $t8, $zero
    ctx->r25 = ADD32(ctx->r24, 0);
    // sll         $t4, $s3, 4
    ctx->r12 = S32(ctx->r19) << 4;
    // sll         $t5, $t8, 4
    ctx->r13 = S32(ctx->r24) << 4;
    // sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25) << 4;
    // ctc2        $t4, $21
    gte_ctc2(ctx, 12, 21);
    // ctc2        $t5, $22
    gte_ctc2(ctx, 13, 22);
    // ctc2        $t6, $23
    gte_ctc2(ctx, 14, 23);
    // j           L_80020CA0
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    goto L_80020CA0;
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
L_80020C78:
    // addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // addu        $t8, $s3, $zero
    ctx->r24 = ADD32(ctx->r19, 0);
    // addu        $t9, $s3, $zero
    ctx->r25 = ADD32(ctx->r19, 0);
    // sll         $t4, $s3, 4
    ctx->r12 = S32(ctx->r19) << 4;
    // sll         $t5, $t8, 4
    ctx->r13 = S32(ctx->r24) << 4;
    // sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25) << 4;
    // ctc2        $t4, $21
    gte_ctc2(ctx, 12, 21);
    // ctc2        $t5, $22
    gte_ctc2(ctx, 13, 22);
    // ctc2        $t6, $23
    gte_ctc2(ctx, 14, 23);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
L_80020CA0:
    // jal         0x8001C100
    // addiu       $a0, $a0, -0x6E90
    ctx->r4 = ADD32(ctx->r4, -0X6E90);

    sub_8001C100(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, -0x6E90
    ctx->r4 = ADD32(ctx->r4, -0X6E90);
    after_1:
    // jal         0x8001C264
    // lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);

    sub_8001C264(rdram, ctx);
    goto after_2;
    // lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    after_2:
    // jal         0x8001C60C
    // addiu       $s3, $s3, -0x4288
    ctx->r19 = ADD32(ctx->r19, -0X4288);

    sub_8001C60C(rdram, ctx);

    goto after_3;
    // addiu       $s3, $s3, -0x4288
    ctx->r19 = ADD32(ctx->r19, -0X4288);
    after_3:
    // lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(0X0, ctx->r19);
    // lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(0X4, ctx->r19);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(0X8, ctx->r19);
    // lw          $t5, 0xC($s3)
    ctx->r13 = MEM_W(0XC, ctx->r19);
    // lw          $t6, 0x10($s3)
    ctx->r14 = MEM_W(0X10, ctx->r19);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // addiu       $t8, $t8, -0x4288
    ctx->r24 = ADD32(ctx->r24, -0X4288);
    // lw          $t4, 0x14($t8)
    ctx->r12 = MEM_W(0X14, ctx->r24);
    // lw          $t5, 0x18($t8)
    ctx->r13 = MEM_W(0X18, ctx->r24);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // lw          $t6, 0x1C($t8)
    ctx->r14 = MEM_W(0X1C, ctx->r24);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // jal         0x8001CB88
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
   
    sub_8001CB88(rdram, ctx);


    goto after_4;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_4:
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // addiu       $s0, $s0, -0x2F70
    ctx->r16 = ADD32(ctx->r16, -0X2F70);
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lw          $v0, 0x6E08($v0)
    ctx->r2 = MEM_W(0X6E08, ctx->r2);
    // nop

    // sw          $v0, 0x3C4($s2)
    MEM_W(0X3C4, ctx->r18) = ctx->r2;
    // lbu         $t9, 0x64($v0)
    ctx->r25 = MEM_BU(0X64, ctx->r2);
    // lbu         $s3, 0x65($v0)
    ctx->r19 = MEM_BU(0X65, ctx->r2);
    // lbu         $t8, 0x66($v0)
    ctx->r24 = MEM_BU(0X66, ctx->r2);
    // sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25) << 4;
    // sll         $t5, $s3, 4
    ctx->r13 = S32(ctx->r19) << 4;
    // sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24) << 4;
    // ctc2        $t4, $13
    gte_ctc2(ctx, 12, 13);
    // ctc2        $t5, $14
    gte_ctc2(ctx, 13, 14);
    // ctc2        $t6, $15
    gte_ctc2(ctx, 14, 15);
    // addiu       $v1, $v0, 0x50
    ctx->r3 = ADD32(ctx->r2, 0X50);
    // lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(0X0, ctx->r3);
    // lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(0X4, ctx->r3);
    // ctc2        $t4, $16
    gte_ctc2(ctx, 12, 16);
    // ctc2        $t5, $17
    gte_ctc2(ctx, 13, 17);
    // lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(0X8, ctx->r3);
    // lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(0XC, ctx->r3);
    // lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(0X10, ctx->r3);
    // ctc2        $t4, $18
    gte_ctc2(ctx, 12, 18);
    // ctc2        $t5, $19
    gte_ctc2(ctx, 13, 19);
    // ctc2        $t6, $20
    gte_ctc2(ctx, 14, 20);
    // lh          $v0, 0x68($v0)
    ctx->r2 = MEM_HS(0X68, ctx->r2);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // sw          $v0, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->r2;
    // lw          $v0, 0x3C4($s2)
    ctx->r2 = MEM_W(0X3C4, ctx->r18);
    // lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // lh          $v0, 0x6A($v0)
    ctx->r2 = MEM_HS(0X6A, ctx->r2);
    // addiu       $s1, $s1, 0x7BCC
    ctx->r17 = ADD32(ctx->r17, 0X7BCC);
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    // jal         0x8001CDF8
    // sw          $v0, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r2;
    sub_8001CDF8(rdram, ctx);

    goto after_5;
    // sw          $v0, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r2;
    after_5:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // jal         0x8001F954
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    sub_8001F954(rdram, ctx);


    goto after_6;
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    after_6:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // jal         0x8001FD00
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    sub_8001FD00(rdram, ctx);


    goto after_7;
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    after_7:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // jal         0x80020164
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    sub_80020164(rdram, ctx);

    goto after_8;
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    after_8:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // jal         0x80020588
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    sub_80020588(rdram, ctx);


    goto after_9;
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    after_9:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // jal         0x8001D2A8
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    sub_8001D2A8(rdram, ctx);


    goto after_10;
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    after_10:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // jal         0x8001DB64
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;

    // printf("[SP-BEFORE] ");
    // for (int i = 0; i < 16; i++)
        // printf("%02X:%08X ", i * 4, MEM_W(0, 0x1F800000 + i * 4));
    // printf("\n");

    sub_8001DB64(rdram, ctx);

    // printf("[SP-AFTER] ");
    // for (int i = 0; i < 16; i++)
        // printf("%02X:%08X ", i * 4, MEM_W(0, 0x1F800000 + i * 4));
    // printf("\n");

    //otBase = MEM_W(0, 0x80165174); // текущий OTag
    //printf("after sub_8001DB64: %d prims\n", countOTag(rdram, otBase, 0x1000));
    goto after_11;
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    after_11:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // jal         0x8001E5A0
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    sub_8001E5A0(rdram, ctx);

    //otBase = MEM_W(0, 0x80165174); // текущий OTag
    //printf("after sub_8001E5A0: %d prims\n", countOTag(rdram, otBase, 0x1000));
    goto after_12;
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    after_12:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // jal         0x8001EEAC
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    sub_8001EEAC(rdram, ctx);

    //otBase = MEM_W(0, 0x80165174); // текущий OTag
    //printf("after sub_8001EEAC: %d prims\n", countOTag(rdram, otBase, 0x1000));
    goto after_13;
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    after_13:
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lw          $v1, 0x1B0($s2)
    ctx->r3 = MEM_W(0X1B0, ctx->r18);
    // lw          $a0, 0x1B4($s2)
    ctx->r4 = MEM_W(0X1B4, ctx->r18);
    // lw          $a1, 0x1BC($s2)
    ctx->r5 = MEM_W(0X1BC, ctx->r18);
    // lw          $a2, 0x1B8($s2)
    ctx->r6 = MEM_W(0X1B8, ctx->r18);
    // lw          $a3, 0x1C0($s2)
    ctx->r7 = MEM_W(0X1C0, ctx->r18);
    // lw          $t0, 0x1C4($s2)
    ctx->r8 = MEM_W(0X1C4, ctx->r18);
    // lw          $t1, 0x1CC($s2)
    ctx->r9 = MEM_W(0X1CC, ctx->r18);
    // lw          $t2, 0x1D0($s2)
    ctx->r10 = MEM_W(0X1D0, ctx->r18);
    // lw          $t3, 0x1D4($s2)
    ctx->r11 = MEM_W(0X1D4, ctx->r18);
    // lw          $t4, 0x1D8($s2)
    ctx->r12 = MEM_W(0X1D8, ctx->r18);
    // lw          $t5, 0x1DC($s2)
    ctx->r13 = MEM_W(0X1DC, ctx->r18);
    // lw          $t6, 0x1E0($s2)
    ctx->r14 = MEM_W(0X1E0, ctx->r18);
    // lw          $t7, 0x304($s0)
    ctx->r15 = MEM_W(0X304, ctx->r16);
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    // sw          $v1, 0x31C($s0)
    MEM_W(0X31C, ctx->r16) = ctx->r3;
    // sw          $a0, 0x320($s0)
    MEM_W(0X320, ctx->r16) = ctx->r4;
    // sw          $a1, 0x328($s0)
    MEM_W(0X328, ctx->r16) = ctx->r5;
    // sw          $a2, 0x324($s0)
    MEM_W(0X324, ctx->r16) = ctx->r6;
    // sw          $a3, 0x32C($s0)
    MEM_W(0X32C, ctx->r16) = ctx->r7;
    // sw          $t0, 0x330($s0)
    MEM_W(0X330, ctx->r16) = ctx->r8;
    // sw          $t1, 0x334($s0)
    MEM_W(0X334, ctx->r16) = ctx->r9;
    // sw          $t2, 0x338($s0)
    MEM_W(0X338, ctx->r16) = ctx->r10;
    // sw          $t3, 0x33C($s0)
    MEM_W(0X33C, ctx->r16) = ctx->r11;
    // sw          $t4, 0x340($s0)
    MEM_W(0X340, ctx->r16) = ctx->r12;
    // sw          $t5, 0x344($s0)
    MEM_W(0X344, ctx->r16) = ctx->r13;
    // sw          $t6, 0x348($s0)
    MEM_W(0X348, ctx->r16) = ctx->r14;
    // sw          $v0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r2;
    // lw          $v1, 0x304($s0)
    ctx->r3 = MEM_W(0X304, ctx->r16);
    // lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(0X14, ctx->r18);
    // nop

    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // lw          $ra, 0x1020($sp)
    ctx->r31 = MEM_W(0X1020, ctx->r29);
    // lw          $s3, 0x101C($sp)
    ctx->r19 = MEM_W(0X101C, ctx->r29);
    // lw          $s2, 0x1018($sp)
    ctx->r18 = MEM_W(0X1018, ctx->r29);
    // lw          $s1, 0x1014($sp)
    ctx->r17 = MEM_W(0X1014, ctx->r29);
    // lw          $s0, 0x1010($sp)
    ctx->r16 = MEM_W(0X1010, ctx->r29);
    // addiu       $sp, $sp, 0x1028
    ctx->r29 = ADD32(ctx->r29, 0X1028);
    // jr          $ra
    // nop



    //printf("[FEEDBACK-OUT] AC=%08X B0=%08X B4=%08X B8=%08X BC=%08X C0=%08X C4=%08X C8=%08X CC=%08X D0=%08X D4=%08X D8=%08X\n",
    //    MEM_W(0, 0x801653AC), MEM_W(0, 0x801653B0), MEM_W(0, 0x801653B4),
    //    MEM_W(0, 0x801653B8), MEM_W(0, 0x801653BC), MEM_W(0, 0x801653C0),
    //    MEM_W(0, 0x801653C4), MEM_W(0, 0x801653C8), MEM_W(0, 0x801653CC),
    //    MEM_W(0, 0x801653D0), MEM_W(0, 0x801653D4), MEM_W(0, 0x801653D8));
    return;
    // nop

;}
