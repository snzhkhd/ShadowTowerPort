#include "recomp.h"
#include "disable_warnings.h"

void sub_8004BE80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // addiu       $s3, $v0, -0x5EC8
    ctx->r19 = ADD32(ctx->r2, -0X5EC8);
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // addu        $s5, $s3, $zero
    ctx->r21 = ADD32(ctx->r19, 0);
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // addiu       $s0, $s3, 0x30
    ctx->r16 = ADD32(ctx->r19, 0X30);
    // sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
L_8004BEBC:
    // lbu         $v1, -0x2B($s0)
    ctx->r3 = MEM_BU(-0X2B, ctx->r16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8004BFFC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004BFFC;
    }
    // nop

    // lbu         $v0, 0x6101($s5)
    ctx->r2 = MEM_BU(0X6101, ctx->r21);
    // lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(0X40, ctx->r16);
    // nop

    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // bne         $v0, $zero, L_8004BFFC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004BFFC;
    }
    // nop

    // lw          $v0, 0x6138($s5)
    ctx->r2 = MEM_W(0X6138, ctx->r21);
    // nop

    // beq         $s3, $v0, L_8004BFFC
    if (ctx->r19 == ctx->r2) {
        // andi        $v0, $v1, 0x10
        ctx->r2 = ctx->r3 & 0X10;
        goto L_8004BFFC;
    }
    // andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // beq         $v0, $zero, L_8004BF40
    if (ctx->r2 == 0) {
        // lui         $v0, 0x40
        ctx->r2 = S32(0X40 << 16);
        goto L_8004BF40;
    }
    // lui         $v0, 0x40
    ctx->r2 = S32(0X40 << 16);
    // lh          $v1, 0x3A($s0)
    ctx->r3 = MEM_HS(0X3A, ctx->r16);
    // lw          $v0, 0x6144($s5)
    ctx->r2 = MEM_W(0X6144, ctx->r21);
    // nop

    // beq         $v1, $v0, L_8004BFFC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004BFFC;
    }
    // nop

    // lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(0X44, ctx->r16);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(0X4C, ctx->r16);
    // nop

    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(0X48, ctx->r16);
    // lh          $v1, 0x3E($s0)
    ctx->r3 = MEM_HS(0X3E, ctx->r16);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // j           L_8004BFAC
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8004BFAC;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8004BF40:
    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // beq         $v0, $zero, L_8004BF90
    if (ctx->r2 == 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8004BF90;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x8004C934
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    sub_8004C934(rdram, ctx);
    goto after_0;
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(0X44, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(0X28, ctx->r29);
    // lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(0X4C, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(0X24, ctx->r29);
    // lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(0X48, ctx->r16);
    // j           L_8004BFAC
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8004BFAC;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8004BF90:
    // lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(0X44, ctx->r16);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(0X4C, ctx->r16);
    // nop

    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(0X48, ctx->r16);
L_8004BFAC:
    // nop

    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lhu         $v0, -0x2($s0)
    ctx->r2 = MEM_HU(-0X2, ctx->r16);
    // lhu         $v1, 0x1C($s1)
    ctx->r3 = MEM_HU(0X1C, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x1E($s1)
    ctx->r2 = MEM_HU(0X1E, ctx->r17);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(0X4, ctx->r17);
    // lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(0X8, ctx->r17);
    // lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(0XC, ctx->r17);
    // jal         0x8004A484
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    sub_8004A484(rdram, ctx);
    goto after_1;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_1:
    // bne         $v0, $s4, L_8004C014
    if (ctx->r2 != ctx->r20) {
        // addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
        goto L_8004C014;
    }
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_8004BFFC:
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addiu       $s0, $s0, 0xD4
    ctx->r16 = ADD32(ctx->r16, 0XD4);
    // slti        $v0, $s2, 0x40
    ctx->r2 = SIGNED(ctx->r18) < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_8004BEBC
    if (ctx->r2 != 0) {
        // addiu       $s3, $s3, 0xD4
        ctx->r19 = ADD32(ctx->r19, 0XD4);
        goto L_8004BEBC;
    }
    // addiu       $s3, $s3, 0xD4
    ctx->r19 = ADD32(ctx->r19, 0XD4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004C014:
    // lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(0X48, ctx->r29);
    // lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(0X44, ctx->r29);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
