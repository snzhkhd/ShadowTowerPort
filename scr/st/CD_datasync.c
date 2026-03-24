#include "recomp.h"
#include "disable_warnings.h"

void CD_datasync(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x80077104
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
   // VSync(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s4, 0x3C
    ctx->r20 = S32(0X3C << 16);
    // lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // addiu       $s3, $s3, 0xA00
    ctx->r19 = ADD32(ctx->r19, 0XA00);
    // lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // addiu       $s1, $s1, 0xCB8
    ctx->r17 = ADD32(ctx->r17, 0XCB8);
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0xA80
    ctx->r16 = ADD32(ctx->r16, 0XA80);
    // addiu       $v0, $v0, 0x3C0
    ctx->r2 = ADD32(ctx->r2, 0X3C0);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, 0x6188($at)
    MEM_W(0X6188, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x3C04
    ctx->r2 = ADD32(ctx->r2, 0X3C04);
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $zero, 0x618C($at)
    MEM_W(0X618C, ctx->r1) = 0;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // sw          $v0, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->r2;
L_8006A654:
    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
 //   VSync(rdram, ctx);
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
    // bne         $v1, $zero, L_8006A698
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8006A698;
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
    // slt         $v1, $s4, $v1
    ctx->r3 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // beq         $v1, $zero, L_8006A700
    if (ctx->r3 == 0) {
        // sw          $v0, 0x618C($at)
        MEM_W(0X618C, ctx->r1) = ctx->r2;
        goto L_8006A700;
    }
    // sw          $v0, 0x618C($at)
    MEM_W(0X618C, ctx->r1) = ctx->r2;
L_8006A698:
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
    // lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(0X0, ctx->r17);
    // lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(0X1, ctx->r17);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // lw          $a1, 0x6190($a1)
    ctx->r5 = MEM_W(0X6190, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lbu         $v0, 0x9F9($v0)
    ctx->r2 = MEM_BU(0X9F9, ctx->r2);
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
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
    // j           L_8006A704
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8006A704;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006A700:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006A704:
    // bne         $v0, $zero, L_8006A734
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8006A734;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCE4($v0)
    ctx->r2 = MEM_W(0XCE4, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8006A734
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8006A734;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // beq         $s2, $zero, L_8006A654
    if (ctx->r18 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8006A654;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A734:
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
    // jr          $ra
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
