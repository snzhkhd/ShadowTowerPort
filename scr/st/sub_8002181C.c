#include "recomp.h"
#include "disable_warnings.h"

void sub_8002181C(uint8_t* rdram, recomp_context* ctx) 
{
   
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x6CD6($s0)
    ctx->r2 = MEM_BU(0X6CD6, ctx->r16);
    // nop

    // beq         $v0, $zero, L_800218C4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xE0
        ctx->r2 = ADD32(0, 0XE0);
        goto L_800218C4;
    }
    
  
    // addiu       $v0, $zero, 0xE0
    ctx->r2 = ADD32(0, 0XE0);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // addiu       $v1, $zero, 0x7C23
    ctx->r3 = ADD32(0, 0X7C23);
    // addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x6CD8($s0)
    ctx->r2 = MEM_BU(0X6CD8, ctx->r16);
    // addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // lbu         $v1, 0x6CDA($s0)
    ctx->r3 = MEM_BU(0X6CDA, ctx->r16);
    // lbu         $a0, 0x6CDE($s0)
    ctx->r4 = MEM_BU(0X6CDE, ctx->r16);
    // lbu         $a1, 0x6CE2($s0)
    ctx->r5 = MEM_BU(0X6CE2, ctx->r16);
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // ori         $v0, $v0, 0x1E
    ctx->r2 = ctx->r2 | 0X1E;
    // sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // jal         0x80021518
    // sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    sub_80021518(rdram, ctx);
    goto after_0;
    // sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // sh          $zero, 0x6CE2($s0)
    MEM_H(0X6CE2, ctx->r16) = 0;
    // sh          $zero, 0x6CDE($s0)
    MEM_H(0X6CDE, ctx->r16) = 0;
    // sh          $zero, 0x6CDA($s0)
    MEM_H(0X6CDA, ctx->r16) = 0;
    // sb          $zero, 0x6CD6($s0)
    MEM_B(0X6CD6, ctx->r16) = 0;
L_800218C4:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
