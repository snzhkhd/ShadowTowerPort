#include "recomp.h"
#include "disable_warnings.h"

void CD_sync(uint8_t* rdram, recomp_context* ctx) 
{
    printf("-->CD_sync\n");
    //// a1 = mode (0=wait, 1=poll)
    //// a2 = result buffer
    //uint8_t* result_buf = ctx->r5 ? (uint8_t*)GET_PTR(ctx->r5) : nullptr;

    //// Заполняем статус если буфер передан
    //if (result_buf) {
    //    result_buf[0] = 0x02; // status: complete
    //}

    ctx->r2 = 0; // 0 = команда завершена
    return;



    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x80077104
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    VSync(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // addiu       $fp, $fp, 0xA00
    ctx->r30 = ADD32(ctx->r30, 0XA00);
    // lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // addiu       $s4, $s4, 0xA80
    ctx->r20 = ADD32(ctx->r20, 0XA80);
    // lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // addiu       $s2, $s2, 0xCB8
    ctx->r18 = ADD32(ctx->r18, 0XCB8);
    // addiu       $s5, $s2, 0x1
    ctx->r21 = ADD32(ctx->r18, 0X1);
    // addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // addiu       $v0, $v0, 0x3C0
    ctx->r2 = ADD32(ctx->r2, 0X3C0);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, 0x6188($at)
    MEM_W(0X6188, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x3B84
    ctx->r2 = ADD32(ctx->r2, 0X3B84);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $zero, 0x618C($at)
    MEM_W(0X618C, ctx->r1) = 0;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->r2;
L_800698A0:
    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    VSync(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_1:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lw          $v1, 0x6188($v1)
    ctx->r3 = MEM_W(0X6188, ctx->r3);
    // nop

    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_800698EC
    if (ctx->r3 != 0) {
        // nop
    
        goto L_800698EC;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, 0x618C($v0)
    ctx->r2 = MEM_W(0X618C, ctx->r2);
    // nop

    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, 0x618C($at)
    MEM_W(0X618C, ctx->r1) = ctx->r2;
    // lui         $v0, 0x3C
    ctx->r2 = S32(0X3C << 16);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80069954
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80069954;
    }
    // nop

L_800698EC:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078A3C
    // addiu       $a0, $a0, 0x3AFC
    ctx->r4 = ADD32(ctx->r4, 0X3AFC);
    sub_80078A3C(rdram, ctx);
    goto after_2;
    // addiu       $a0, $a0, 0x3AFC
    ctx->r4 = ADD32(ctx->r4, 0X3AFC);
    after_2:
    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(0X1, ctx->r18);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // lw          $a1, 0x6190($a1)
    ctx->r5 = MEM_W(0X6190, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lbu         $v0, 0x9F9($v0)
    ctx->r2 = MEM_BU(0X9F9, ctx->r2);
    // addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(0X0, ctx->r2);
    // lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(0X0, ctx->r4);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a0, $a0, 0x3B0C
    ctx->r4 = ADD32(ctx->r4, 0X3B0C);
    printf(rdram, ctx);
    goto after_3;
    // addiu       $a0, $a0, 0x3B0C
    ctx->r4 = ADD32(ctx->r4, 0X3B0C);
    after_3:
    // jal         0x8006A1FC
    // nop

    CD_flush(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // j           L_80069958
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80069958;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80069954:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80069958:
    // bne         $v0, $zero, L_80069A70
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80069A70;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // jal         0x80077468
    // nop

    CheckCallback(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // beq         $v0, $zero, L_80069A10
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80069A10;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA0($v0)
    ctx->r2 = MEM_W(0XCA0, ctx->r2);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $s1, $v0, 0x3
    ctx->r17 = ctx->r2 & 0X3;
L_80069988:
    // jal         0x800692C4
    // nop

    sub_800692C4(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80069A00
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x4
        ctx->r2 = ctx->r16 & 0X4;
        goto L_80069A00;
    }
    // andi        $v0, $s0, 0x4
    ctx->r2 = ctx->r16 & 0X4;
    // beq         $v0, $zero, L_800699CC
    if (ctx->r2 == 0) {
        // andi        $v0, $s0, 0x2
        ctx->r2 = ctx->r16 & 0X2;
        goto L_800699CC;
    }
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9DC($v0)
    ctx->r2 = MEM_W(0X9DC, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800699C8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800699C8;
    }
    // nop

    // lbu         $a0, 0x0($s5)
    ctx->r4 = MEM_BU(0X0, ctx->r21);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // jalr        $v0
    // addiu       $a1, $a1, 0x6178
    ctx->r5 = ADD32(ctx->r5, 0X6178);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_7;
    // addiu       $a1, $a1, 0x6178
    ctx->r5 = ADD32(ctx->r5, 0X6178);
    after_7:
L_800699C8:
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
L_800699CC:
    // beq         $v0, $zero, L_80069988
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80069988;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9D8($v0)
    ctx->r2 = MEM_W(0X9D8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80069988
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80069988;
    }
    // nop

    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // jalr        $v0
    // addiu       $a1, $a1, 0x6170
    ctx->r5 = ADD32(ctx->r5, 0X6170);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_8;
    // addiu       $a1, $a1, 0x6170
    ctx->r5 = ADD32(ctx->r5, 0X6170);
    after_8:
    // j           L_80069988
    // nop

    goto L_80069988;
    // nop

L_80069A00:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA0($v0)
    ctx->r2 = MEM_W(0XCA0, ctx->r2);
    // nop

    // sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
L_80069A10:
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // nop

    // andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // beq         $a2, $s3, L_80069A2C
    if (ctx->r6 == ctx->r19) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_80069A2C;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $a2, $v0, L_80069A68
    if (ctx->r6 != ctx->r2) {
        // nop
    
        goto L_80069A68;
    }
    // nop

L_80069A2C:
    // sb          $s3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r19;
    // addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0x6170
    ctx->r4 = ADD32(ctx->r4, 0X6170);
    // beq         $a1, $zero, L_80069A60
    if (ctx->r5 == 0) {
        // addiu       $v1, $zero, 0x7
        ctx->r3 = ADD32(0, 0X7);
        goto L_80069A60;
    }
    // addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80069A48:
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // bne         $v1, $a3, L_80069A48
    if (ctx->r3 != ctx->r7) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80069A48;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80069A60:
    // j           L_80069A70
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    goto L_80069A70;
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_80069A68:
    // beq         $s6, $zero, L_800698A0
    if (ctx->r22 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800698A0;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80069A70:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
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
    // jr          $ra
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
