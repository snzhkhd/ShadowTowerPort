#include "recomp.h"
#include "disable_warnings.h"

void InvSquareRoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // mtc2        $a0, $30
    gte_mtc2(ctx, 4, 30);
    // nop

    // nop

    // mfc2        $v0, $31
    ctx->r2 = gte_mfc2(ctx, 31);
    // addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // beq         $v0, $at, L_800747D8
    if (ctx->r2 == ctx->r1) {
        // nop
    
        goto L_800747D8;
    }
    // nop

    // beq         $v0, $zero, L_800747D8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800747D8;
    }
    // nop

    // andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // addiu       $t1, $zero, 0x1F
    ctx->r9 = ADD32(0, 0X1F);
    // sub         $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // sra         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9) >> 1;
    // addi        $t3, $t2, -0x18
    ctx->r11 = ADD32(ctx->r10, -0X18);
    // bltz        $t3, L_800747A4
    if (SIGNED(ctx->r11) < 0) {
        // nop
    
        goto L_800747A4;
    }
    // nop

    // sllv        $t4, $a0, $t3
    ctx->r12 = S32(ctx->r4) << (ctx->r11 & 31);
    // b           L_800747B0
    // addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    goto L_800747B0;
L_800747A4:
    // addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // sub         $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // srav        $t4, $a0, $t3
    ctx->r12 = S32(ctx->r4) >> (ctx->r11 & 31);
L_800747B0:
    // addi        $t4, $t4, -0x40
    ctx->r12 = ADD32(ctx->r12, -0X40);
    // sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12) << 1;
    // lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // lh          $t5, 0x20F4($t5)
    ctx->r13 = MEM_HS(0X20F4, ctx->r13);
    // sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jr          $ra
    // nop

    return;
    // nop

L_800747D8:
    // jr          $ra
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
;}
