#include "recomp.h"
#include "disable_warnings.h"


void PlayerInteract(uint8_t* rdram, recomp_context* ctx) 
{
    //for (int i = 0; i < 64 && g_watchSlot < 0; i++) {
    //    if (MEM_B(0, 0x801CAE2A + i * 0x30) == 2) {
    //        g_watchSlot = i;
    //        printf("[WATCH] tracking item %d\n", i);
    //    }
    //}


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // addiu       $s1, $v0, -0x51F8
    ctx->r17 = ADD32(ctx->r2, -0X51F8);
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // addiu       $s3, $zero, 0x3F
    ctx->r19 = ADD32(0, 0X3F);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // addiu       $s6, $v0, 0x5920
    ctx->r22 = ADD32(ctx->r2, 0X5920);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // addiu       $s4, $v0, -0x70D8
    ctx->r20 = ADD32(ctx->r2, -0X70D8);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // addiu       $s5, $v0, 0x5948
    ctx->r21 = ADD32(ctx->r2, 0X5948);
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // addiu       $s0, $s1, 0x18
    ctx->r16 = ADD32(ctx->r17, 0X18);
    // sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
L_80053AF0:
    static uint8_t prevStates[64] = {};
    uint8_t curState = MEM_B(0x0A, ctx->r16);
    int idx = (ctx->r16 - 0x801CAE20) / 0x30;
    if (idx >= 0 && idx < 64 && prevStates[idx] != curState) {
        printf("[ITEM-%d] state %d -> %d\n", idx, prevStates[idx], curState);
        prevStates[idx] = curState;
    }
   
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80053CF8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80053CF8;
    }
    // nop

    // lbu         $v1, 0x14($s0)
    ctx->r3 = MEM_BU(0X14, ctx->r16);
    // lbu         $v0, 0x4($s6)
    ctx->r2 = MEM_BU(0X4, ctx->r22);
    // nop

    // bne         $v1, $v0, L_80053CF8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80053CF8;
    }
    // nop

    // lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(0X0, ctx->r17);
    // lw          $v0, -0x10($s0)
    ctx->r2 = MEM_W(-0X10, ctx->r16);
    // sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // lw          $v1, 0x248($s4)
    ctx->r3 = MEM_W(0X248, ctx->r20);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, -0x8($s0)
    ctx->r2 = MEM_W(-0X8, ctx->r16);
    // lw          $v1, 0x250($s4)
    ctx->r3 = MEM_W(0X250, ctx->r20);
    // mflo        $a0
    ctx->r4 = lo;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x7810
    ctx->r2 = ADD32(ctx->r2, 0X7810);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5) << 1;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // jal         0x800746C4
    // addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    after_0:
    // lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(0XA, ctx->r16);
    // sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_80053CF8
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_80053CF8;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x2738
    ctx->r2 = ADD32(ctx->r2, 0X2738);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_80053B9C;
    jr_addend_80053B9C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop


    switch (jr_addend_80053B9C >> 2) {
        case 0: goto L_80053CF8; break;
        case 1: goto L_80053BA4; break;
        case 2: goto L_80053CF8; break;
        case 3: goto L_80053CE8; break;
        case 4: goto L_80053CF8; break;
        default: 
        {
            
            switch_error(__func__, 0x80053B9C, 0x80012738);
        }
            
            
    }
    // nop

   
L_80053BA4:
    // lb          $v1, 0xD($s0)
    ctx->r3 = MEM_BS(0XD, ctx->r16);
    // nop

    // slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;//0X4 ? 1 : 0;
    // beq         $v0, $zero, L_80053CD4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0x4); //ADD32(0, 0X4);
        goto L_80053CD4;
    }
  
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0x2);// ADD32(0, 0X4);
    // lw          $v0, -0x10($s0)
    ctx->r2 = MEM_W(-0X10, ctx->r16);
    // lw          $v1, -0xC($s0)
    ctx->r3 = MEM_W(-0XC, ctx->r16);
    // lw          $a0, -0x8($s0)
    ctx->r4 = MEM_W(-0X8, ctx->r16);
    // lw          $a1, -0x4($s0)
    ctx->r5 = MEM_W(-0X4, ctx->r16);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // lhu         $a0, 0xE($s2)
    ctx->r4 = MEM_HU(0XE, ctx->r18);
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    // sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // addiu       $v1, $v1, -0x200
    ctx->r3 = ADD32(ctx->r3, -0X200);
    // sh          $a0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r4;
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(0XE, ctx->r16);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
    // sh          $zero, 0x30($sp)
    MEM_H(0X30, ctx->r29) = 0;
    // jal         0x80048AD0
    // sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    sub_80048AD0(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    after_1:
    // lw          $v0, 0x2C($s5)
    ctx->r2 = MEM_W(0X2C, ctx->r21);
    // nop

    // addiu       $s2, $v0, -0x200
    ctx->r18 = ADD32(ctx->r2, -0X200);
    // blez        $s2, L_80053C5C
    if (SIGNED(ctx->r18) <= 0) {
        // nop
    
        goto L_80053C5C;
    }
    // nop

    // lh          $v0, 0xE($s0)
    ctx->r2 = MEM_HS(0XE, ctx->r16);
    // lw          $v1, -0xC($s0)
    ctx->r3 = MEM_W(-0XC, ctx->r16);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(0XE, ctx->r16);
    // slti        $a0, $a0, 0x100
    ctx->r4 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // beq         $a0, $zero, L_80053C94
    if (ctx->r4 == 0) {
        // sw          $v1, -0xC($s0)
        MEM_W(-0XC, ctx->r16) = ctx->r3;
        goto L_80053C94;
    }
    // sw          $v1, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r3;
    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // j           L_80053C94
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    goto L_80053C94;
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
L_80053C5C:
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(0XD, ctx->r16);
    // lhu         $v1, 0xE($s0)
    ctx->r3 = MEM_HU(0XE, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 17
    ctx->r3 = S32(ctx->r3) >> 17;
    // sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // lw          $v0, -0xC($s0)
    ctx->r2 = MEM_W(-0XC, ctx->r16);
    // lw          $a0, 0x2C($s5)
    ctx->r4 = MEM_W(0X2C, ctx->r21);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // sh          $v1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r3;
    // addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r2;
L_80053C94:
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // lw          $v1, 0x24C($s4)
    ctx->r3 = MEM_W(0X24C, ctx->r20);
    // lw          $a0, -0xC($s0)
    ctx->r4 = MEM_W(-0XC, ctx->r16);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v1, $zero, L_80053CB8
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80053CB8;
    }
    // nop

    // jal         0x80052E50
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80052E50(rdram, ctx);
    goto after_2;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
L_80053CB8:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x47
    ctx->r2 = ctx->r2 < 0X47 ? 1 : 0;
    // beq         $v0, $zero, L_80053CF8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80053CF8;
    }
    // nop

    // j           L_80053CF8
    // sh          $s2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r18;
    goto L_80053CF8;
    // sh          $s2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r18;
L_80053CD4:
    // bne         $v1, $v0, L_80053CF8
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_80053CF8;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    // j           L_80053CF8
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    goto L_80053CF8;
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_80053CE8:
    printf("PlayerInteract case 3 \n");
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x8005335C
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    PreviewPickUp(rdram, ctx);
    goto after_3;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
    // sb          $zero, 0x218($s4)
    MEM_B(0X218, ctx->r20) = 0;
L_80053CF8:
   
   

    // addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s3, $v0, L_80053AF0
    if (ctx->r19 != ctx->r2) {
        // addiu       $s1, $s1, 0x30
        ctx->r17 = ADD32(ctx->r17, 0X30);
        goto L_80053AF0;
    }
    // addiu       $s1, $s1, 0x30
    ctx->r17 = ADD32(ctx->r17, 0X30);
    // lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(0X54, ctx->r29);
    // lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(0X50, ctx->r29);
    // lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(0X4C, ctx->r29);
    // lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(0X48, ctx->r29);
    // lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(0X44, ctx->r29);
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
