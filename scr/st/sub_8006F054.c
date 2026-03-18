#include "recomp.h"
#include "disable_warnings.h"

void sub_8006F054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x79AC($v0)
    ctx->r2 = MEM_W(-0X79AC, ctx->r2);
    // lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(0X28, ctx->r29);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // beq         $v0, $v1, L_8006F190
    if (ctx->r2 == ctx->r3) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_8006F190;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v1, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = ctx->r3;
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_8006F188
    if (ctx->r2 == 0) {
        // sll         $v1, $a0, 16
        ctx->r3 = S32(ctx->r4) << 16;
        goto L_8006F188;
    }
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lh          $v1, -0x70E8($v1)
    ctx->r3 = MEM_HS(-0X70E8, ctx->r3);
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v1, $v0, L_8006F134
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $a2, 16
        ctx->r2 = S32(ctx->r6) << 16;
        goto L_8006F134;
    }
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lh          $v1, -0x70EC($v1)
    ctx->r3 = MEM_HS(-0X70EC, ctx->r3);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v1, $v0, L_8006F134
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $a3, 16
        ctx->r2 = S32(ctx->r7) << 16;
        goto L_8006F134;
    }
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lh          $v1, -0x70EA($v1)
    ctx->r3 = MEM_HS(-0X70EA, ctx->r3);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v1, $v0, L_8006F134
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $t0, 16
        ctx->r2 = S32(ctx->r8) << 16;
        goto L_8006F134;
    }
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lh          $v1, -0x70F2($v1)
    ctx->r3 = MEM_HS(-0X70F2, ctx->r3);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v1, $v0, L_8006F134
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8006F134;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lh          $v1, -0x7100($v1)
    ctx->r3 = MEM_HS(-0X7100, ctx->r3);
    // nop

    // bne         $v1, $v0, L_8006F134
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8006F134;
    }
    // nop

    // jal         0x80072794
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    sub_80072794(rdram, ctx);
    goto after_0;
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // j           L_8006F148
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8006F148;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006F134:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $s0, -0x68EE($at)
    MEM_H(-0X68EE, ctx->r1) = ctx->r16;
    // jal         0x800727D4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    _SsVmKeyOffNow(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006F148:
    // sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4) << 3;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $zero, -0x70D6($at)
    MEM_H(-0X70D6, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $zero, -0x70E2($at)
    MEM_H(-0X70E2, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // j           L_8006F194
    // sw          $zero, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = 0;
    goto L_8006F194;
    // sw          $zero, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = 0;
L_8006F188:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $zero, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = 0;
L_8006F190:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006F194:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
