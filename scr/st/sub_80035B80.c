#include "recomp.h"
#include "disable_warnings.h"

void sub_80035B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // ori         $v0, $zero, 0x834C
    ctx->r2 = 0 | 0X834C;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(0X0, ctx->r5);
    // lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(0X50, ctx->r29);
    // beq         $a1, $zero, L_80035BC0
    if (ctx->r5 == 0) {
        // nop
    
        goto L_80035BC0;
    }
    // nop

    // bne         $a0, $zero, L_80035BD0
    if (ctx->r4 != 0) {
        // sll         $v0, $a2, 2
        ctx->r2 = S32(ctx->r6) << 2;
        goto L_80035BD0;
    }
    // sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6) << 2;
L_80035BC0:
    // sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // j           L_80035CB0
    // sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    goto L_80035CB0;
    // sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80035BD0:
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(0X8, ctx->r5);
    // lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(0X34, ctx->r4);
    // addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(0XC, ctx->r2);
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7) << 3;
    // jal         0x80034760
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    sub_80034760(rdram, ctx);
    goto after_0;
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    after_0:
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // beq         $a3, $zero, L_80035CB0
    if (ctx->r7 == 0) {
        // nop
    
        goto L_80035CB0;
    }
    // nop

    // lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(0X4, ctx->r7);
    // nop

    // beq         $v0, $zero, L_80035C34
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80035C34;
    }
    // nop

L_80035C20:
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // lw          $v0, 0x48($v0)
    ctx->r2 = MEM_W(0X48, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80035C20
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80035C20;
    }
    // nop

L_80035C34:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
    // ori         $a2, $a2, 0xA8
    ctx->r6 = ctx->r6 | 0XA8;
    // addiu       $a1, $v0, 0x40C
    ctx->r5 = ADD32(ctx->r2, 0X40C);
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(0X4, ctx->r5);
    // sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // sw          $a0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r4;
    // lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(0X8, ctx->r5);
    // lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(0XC, ctx->r5);
    // sw          $v1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r3;
    // sw          $a0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r4;
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(0X14, ctx->r5);
    // sw          $v1, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r3;
    // sw          $a0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r4;
    // lw          $v1, 0x18($a1)
    ctx->r3 = MEM_W(0X18, ctx->r5);
    // lw          $a0, 0x1C($a1)
    ctx->r4 = MEM_W(0X1C, ctx->r5);
    // sw          $v1, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r3;
    // sw          $a0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r4;
    // lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(0X4, ctx->r7);
    // jal         0x80035260
    // nop

    sub_80035260(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lwc2        $0, 0x0($s1)
    gte_lwc2(rdram, ctx, 0, 17, 0);
    // lwc2        $1, 0x4($s1)
    gte_lwc2(rdram, ctx, 1, 17, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // swc2        $25, 0x0($s0)
    gte_swc2(rdram, ctx, 25, 16, 0);
    // swc2        $26, 0x4($s0)
    gte_swc2(rdram, ctx, 26, 16, 4);
    // swc2        $27, 0x8($s0)
    gte_swc2(rdram, ctx, 27, 16, 8);
L_80035CB0:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
