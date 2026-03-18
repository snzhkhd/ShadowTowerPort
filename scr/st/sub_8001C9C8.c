#include "recomp.h"
#include "disable_warnings.h"

void sub_8001C9C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x2230
    ctx->r2 = ADD32(ctx->r2, 0X2230);
    // addiu       $v1, $v0, -0x1F20
    ctx->r3 = ADD32(ctx->r2, -0X1F20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s1, $zero, 0xEF
    ctx->r17 = ADD32(0, 0XEF);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $v0, 0x7
    ctx->r16 = ADD32(ctx->r2, 0X7);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sb          $zero, 0x7274($v1)
    MEM_B(0X7274, ctx->r3) = 0;
L_8001C9F8:
    // lhu         $v0, 0x3($s0)
    ctx->r2 = MEM_HU(0X3, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x118
    ctx->r2 = ctx->r2 < 0X118 ? 1 : 0;
    // beq         $v0, $zero, L_8001CA88
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001CA88;
    }
    // nop

    // lbu         $v0, -0x3($s0)
    ctx->r2 = MEM_BU(-0X3, ctx->r16);
    // lhu         $a0, 0x1($s0)
    ctx->r4 = MEM_HU(0X1, ctx->r16);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // jal         0x8001C88C
    // sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    sub_8001C88C(rdram, ctx);
    goto after_0;
    // sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    after_0:
    // bne         $v0, $zero, L_8001CA38
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xEC
        ctx->r2 = ADD32(0, 0XEC);
        goto L_8001CA38;
    }
    // addiu       $v0, $zero, 0xEC
    ctx->r2 = ADD32(0, 0XEC);
    // lbu         $v1, -0x2($s0)
    ctx->r3 = MEM_BU(-0X2, ctx->r16);
    // nop

    // bne         $v1, $v0, L_8001CA8C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8001CA8C;
    }
    // nop

L_8001CA38:
    // lbu         $v0, 0x7274($s2)
    ctx->r2 = MEM_BU(0X7274, ctx->r18);
    // nop

    // sltiu       $v0, $v0, 0x60
    ctx->r2 = ctx->r2 < 0X60 ? 1 : 0;
    // beq         $v0, $zero, L_8001CA9C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001CA9C;
    }
    // nop

    // lbu         $v0, -0x3($s0)
    ctx->r2 = MEM_BU(-0X3, ctx->r16);
    // nop

    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xEF
    ctx->r2 = ADD32(0, 0XEF);
    // lbu         $v1, 0x7274($s2)
    ctx->r3 = MEM_BU(0X7274, ctx->r18);
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // sh          $v0, 0x71B4($v1)
    MEM_H(0X71B4, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x7274($s2)
    ctx->r2 = MEM_BU(0X7274, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8001CA8C
    // sb          $v0, 0x7274($s2)
    MEM_B(0X7274, ctx->r18) = ctx->r2;
    goto L_8001CA8C;
    // sb          $v0, 0x7274($s2)
    MEM_B(0X7274, ctx->r18) = ctx->r2;
L_8001CA88:
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8001CA8C:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s1, $v0, L_8001C9F8
    if (ctx->r17 != ctx->r2) {
        // addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
        goto L_8001C9F8;
    }
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
L_8001CA9C:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
