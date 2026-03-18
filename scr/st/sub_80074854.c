#include "recomp.h"
#include "disable_warnings.h"

void sub_80074854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // mtc2        $t0, $9
    gte_mtc2(ctx, 8, 9);
    // mtc2        $t1, $10
    gte_mtc2(ctx, 9, 10);
    // mtc2        $t2, $11
    gte_mtc2(ctx, 10, 11);
    // nop

    // .word       0x4AA00428                   # INVALID     $s5, $zero, 0x428 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AA00428);
    // mfc2        $t3, $25
    ctx->r11 = gte_mfc2(ctx, 25);
    // mfc2        $t4, $26
    ctx->r12 = gte_mfc2(ctx, 26);
    // mfc2        $t5, $27
    ctx->r13 = gte_mfc2(ctx, 27);
    // add         $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // add         $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // mtc2        $v0, $30
    gte_mtc2(ctx, 2, 30);
    // nop

    // nop

    // mfc2        $v1, $31
    ctx->r3 = gte_mfc2(ctx, 31);
    // addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // and         $v1, $v1, $at
    ctx->r3 = ctx->r3 & ctx->r1;
    // addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // sub         $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // sra         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14) >> 1;
    // addi        $t3, $v1, -0x18
    ctx->r11 = ADD32(ctx->r3, -0X18);
    // bltz        $t3, L_800748B4
    if (SIGNED(ctx->r11) < 0) {
        // nop
    
        goto L_800748B4;
    }
    // nop

    // b           L_800748C0
    // sllv        $t4, $v0, $t3
    ctx->r12 = S32(ctx->r2) << (ctx->r11 & 31);
    goto L_800748C0;
    // sllv        $t4, $v0, $t3
    ctx->r12 = S32(ctx->r2) << (ctx->r11 & 31);
L_800748B4:
    // addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // sub         $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // srav        $t4, $v0, $t3
    ctx->r12 = S32(ctx->r2) >> (ctx->r11 & 31);
L_800748C0:
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
    // nop

    // mtc2        $t5, $8
    gte_mtc2(ctx, 13, 8);
    // mtc2        $t0, $9
    gte_mtc2(ctx, 8, 9);
    // mtc2        $t1, $10
    gte_mtc2(ctx, 9, 10);
    // mtc2        $t2, $11
    gte_mtc2(ctx, 10, 11);
    // nop

    // nop

    // .word       0x4B90003D                   # INVALID     $gp, $s0, 0x3D # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B90003D);
    // mfc2        $t0, $25
    ctx->r8 = gte_mfc2(ctx, 25);
    // mfc2        $t1, $26
    ctx->r9 = gte_mfc2(ctx, 26);
    // mfc2        $t2, $27
    ctx->r10 = gte_mfc2(ctx, 27);
    // srav        $t0, $t0, $t6
    ctx->r8 = S32(ctx->r8) >> (ctx->r14 & 31);
    // srav        $t1, $t1, $t6
    ctx->r9 = S32(ctx->r9) >> (ctx->r14 & 31);
    // srav        $t2, $t2, $t6
    ctx->r10 = S32(ctx->r10) >> (ctx->r14 & 31);
    // jr          $ra
    // nop

    return;
    // nop

;}
