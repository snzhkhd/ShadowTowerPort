#include "recomp.h"
#include "disable_warnings.h"

void sub_80021654(uint8_t* rdram, recomp_context* ctx) 
{

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // addiu       $s2, $v0, -0x7E00
    ctx->r18 = ADD32(ctx->r2, -0X7E00);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // addiu       $s0, $v0, 0x5920
    ctx->r16 = ADD32(ctx->r2, 0X5920);
    // sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(0X4, ctx->r18);
    // lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(0X18, ctx->r16);
    // lh          $a2, 0x5920($v0)
    ctx->r6 = MEM_HS(0X5920, ctx->r2);
    // nop

    // bne         $a2, $zero, L_8002169C
    if (ctx->r6 != 0) {
        // subu        $a0, $a1, $v1
        ctx->r4 = SUB32(ctx->r5, ctx->r3);
        goto L_8002169C;
    }
    // subu        $a0, $a1, $v1
    ctx->r4 = SUB32(ctx->r5, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_80021800
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80021800;
    }
    // nop

L_8002169C:
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_800216C0
    if (ctx->r2 == 0) {
        // slti        $v0, $a0, 0x78
        ctx->r2 = SIGNED(ctx->r4) < 0X78 ? 1 : 0;
        goto L_800216C0;
    }
    // slti        $v0, $a0, 0x78
    ctx->r2 = SIGNED(ctx->r4) < 0X78 ? 1 : 0;
    // j           L_80021800
    // sw          $a1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r5;
    goto L_80021800;
    // sw          $a1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r5;
L_800216C0:
    // beq         $v0, $zero, L_8002170C
    if (ctx->r2 == 0) {
        // sll         $v1, $a0, 1
        ctx->r3 = S32(ctx->r4) << 1;
        goto L_8002170C;
    }
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
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
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x5E
    ctx->r2 = ADD32(0, 0X5E);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x7C23
    ctx->r2 = ADD32(0, 0X7C23);
    // andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // j           L_800217D8
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    goto L_800217D8;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_8002170C:
    // slti        $s1, $a0, 0xF0
    ctx->r17 = SIGNED(ctx->r4) < 0XF0 ? 1 : 0;
    // bne         $s1, $zero, L_80021720
    if (ctx->r17 != 0) {
        // addiu       $v1, $a0, -0x78
        ctx->r3 = ADD32(ctx->r4, -0X78);
        goto L_80021720;
    }
    // addiu       $v1, $a0, -0x78
    ctx->r3 = ADD32(ctx->r4, -0X78);
    // beq         $a2, $zero, L_8002178C
    if (ctx->r6 == 0) {
        // slti        $v0, $a0, 0x168
        ctx->r2 = SIGNED(ctx->r4) < 0X168 ? 1 : 0;
        goto L_8002178C;
    }
    // slti        $v0, $a0, 0x168
    ctx->r2 = SIGNED(ctx->r4) < 0X168 ? 1 : 0;
L_80021720:
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x120
    ctx->r6 = ADD32(0, 0X120);
    // addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x7BE3
    ctx->r2 = ADD32(0, 0X7BE3);
    // andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // jal         0x80021518
    // sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    sub_80021518(rdram, ctx);
    goto after_0;
    // sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_0:
    // bne         $s1, $zero, L_80021800
    if (ctx->r17 != 0) {
        // nop
    
        goto L_80021800;
    }
    // nop

    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // j           L_800217FC
    // addiu       $v0, $v0, -0xF0
    ctx->r2 = ADD32(ctx->r2, -0XF0);
    goto L_800217FC;
    // addiu       $v0, $v0, -0xF0
    ctx->r2 = ADD32(ctx->r2, -0XF0);
L_8002178C:
    // beq         $v0, $zero, L_800217F8
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0x168
        ctx->r3 = ADD32(0, 0X168);
        goto L_800217F8;
    }
    // addiu       $v1, $zero, 0x168
    ctx->r3 = ADD32(0, 0X168);
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x120
    ctx->r6 = ADD32(0, 0X120);
    // addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x7BE3
    ctx->r2 = ADD32(0, 0X7BE3);
    // andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
L_800217D8:
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // jal         0x80021518
    // sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    sub_80021518(rdram, ctx);
    goto after_1;
    // sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_1:
    // j           L_80021800
    // nop

    goto L_80021800;
    // nop

L_800217F8:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800217FC:
    // sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_80021800:
    // lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(0X4C, ctx->r29);
    // lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(0X48, ctx->r29);
    // lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(0X44, ctx->r29);
    // lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
