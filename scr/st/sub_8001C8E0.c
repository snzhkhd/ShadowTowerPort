#include "recomp.h"
#include "disable_warnings.h"

void sub_8001C8E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s1, $zero, 0x3F
    ctx->r17 = ADD32(0, 0X3F);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sb          $zero, 0x6100($v0)
    MEM_B(0X6100, ctx->r2) = 0;
L_8001C914:
    // lbu         $a0, -0x1($s0)
    ctx->r4 = MEM_BU(-0X1, ctx->r16);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $a0, $v0, L_8001C994
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_8001C994;
    }
    // nop

    // lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(0X1, ctx->r16);
    // nop

    // beq         $v1, $s3, L_8001C93C
    if (ctx->r3 == ctx->r19) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_8001C93C;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $v1, $v0, L_8001C994
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8001C994;
    }
    // nop

L_8001C93C:
    // beq         $a0, $s3, L_8001C958
    if (ctx->r4 == ctx->r19) {
        // nop
    
        goto L_8001C958;
    }
    // nop

    // lhu         $a0, 0x22($s0)
    ctx->r4 = MEM_HU(0X22, ctx->r16);
    // jal         0x8001C88C
    // nop

    sub_8001C88C(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // beq         $v0, $zero, L_8001C994
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001C994;
    }
    // nop

L_8001C958:
    // lbu         $v0, 0x6100($s2)
    ctx->r2 = MEM_BU(0X6100, ctx->r18);
    // nop

    // sltiu       $v0, $v0, 0xC
    ctx->r2 = ctx->r2 < 0XC ? 1 : 0;
    // beq         $v0, $zero, L_8001C9A8
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0x3F
        ctx->r3 = ADD32(0, 0X3F);
        goto L_8001C9A8;
    }
    // addiu       $v1, $zero, 0x3F
    ctx->r3 = ADD32(0, 0X3F);
    // lbu         $v0, 0x6100($s2)
    ctx->r2 = MEM_BU(0X6100, ctx->r18);
    // subu        $v1, $v1, $s1
    ctx->r3 = SUB32(ctx->r3, ctx->r17);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sh          $v1, 0x6104($v0)
    MEM_H(0X6104, ctx->r2) = ctx->r3;
    // lbu         $v0, 0x6100($s2)
    ctx->r2 = MEM_BU(0X6100, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8001C998
    // sb          $v0, 0x6100($s2)
    MEM_B(0X6100, ctx->r18) = ctx->r2;
    goto L_8001C998;
    // sb          $v0, 0x6100($s2)
    MEM_B(0X6100, ctx->r18) = ctx->r2;
L_8001C994:
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8001C998:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s1, $v0, L_8001C914
    if (ctx->r17 != ctx->r2) {
        // addiu       $s0, $s0, 0xD4
        ctx->r16 = ADD32(ctx->r16, 0XD4);
        goto L_8001C914;
    }
    // addiu       $s0, $s0, 0xD4
    ctx->r16 = ADD32(ctx->r16, 0XD4);
L_8001C9A8:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
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
