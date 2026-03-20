#include "recomp.h"
#include "disable_warnings.h"

void sub_80016294(uint8_t* rdram, recomp_context* ctx) 
{
    //const char* name = (const char*)GET_PTR(ctx->r5);
    //printf("sub_80016294    <%s>\n", name);
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x8B8
    ctx->r29 = ADD32(ctx->r29, -0X8B8);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x8B0($sp)
    MEM_W(0X8B0, ctx->r29) = ctx->r31;
    // sw          $s1, 0x8AC($sp)
    MEM_W(0X8AC, ctx->r29) = ctx->r17;
    // sw          $s0, 0x8A8($sp)
    MEM_W(0X8A8, ctx->r29) = ctx->r16;
    // addiu       $t0, $v0, 0x7ECC
    ctx->r8 = ADD32(ctx->r2, 0X7ECC);
    // lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(0X0, ctx->r8);
    // lb          $a2, 0x4($t0)
    ctx->r6 = MEM_BS(0X4, ctx->r8);
    // sw          $v1, 0x868($sp)
    MEM_W(0X868, ctx->r29) = ctx->r3;
    // sb          $a2, 0x86C($sp)
    MEM_B(0X86C, ctx->r29) = ctx->r6;
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // addiu       $s0, $sp, 0x868
    ctx->r16 = ADD32(ctx->r29, 0X868);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x7424
    ctx->r2 = ADD32(ctx->r2, -0X7424);
    // jal         0x80078A64
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    strcat_recomp(rdram, ctx);
    goto after_0;
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // jal         0x80078A64
    // addiu       $a1, $a1, 0x7ED4
    ctx->r5 = ADD32(ctx->r5, 0X7ED4);
    strcat_recomp(rdram, ctx);
    goto after_1;
    // addiu       $a1, $a1, 0x7ED4
    ctx->r5 = ADD32(ctx->r5, 0X7ED4);
    after_1:
L_800162F4:
    // addiu       $a0, $sp, 0x850
    ctx->r4 = ADD32(ctx->r29, 0X850);
    // jal         0x8006AA24
    // addiu       $a1, $sp, 0x868
    ctx->r5 = ADD32(ctx->r29, 0X868);
    CdSearchFile(rdram, ctx);
    goto after_2;
    // addiu       $a1, $sp, 0x868
    ctx->r5 = ADD32(ctx->r29, 0X868);
    after_2:
    // beq         $v0, $zero, L_800162F4
    if (ctx->r2 == 0) {
        // addiu       $a2, $zero, 0x800
        ctx->r6 = ADD32(0, 0X800);
        goto L_800162F4;
    }
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    // lwl         $v0, 0x853($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X853, ctx->r29);
    // lwr         $v0, 0x850($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X850, ctx->r29);
    // nop

    // swl         $v0, 0x7($s1)
    do_swl(rdram, 0X7, ctx->r17, ctx->r2);
    // swr         $v0, 0x4($s1)
    do_swr(rdram, 0X4, ctx->r17, ctx->r2);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // lw          $v0, 0x854($sp)
    ctx->r2 = MEM_W(0X854, ctx->r29);
    // jal         0x80015FF4
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;

    sub_80015FF4(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    after_3:
    // lhu         $a0, 0x10($sp)
    ctx->r4 = MEM_HU(0X10, ctx->r29);
    // nop

    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // jal         0x800152D0
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;

    sub_800152D0(rdram, ctx);
    goto after_4;
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    after_4:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lhu         $a2, 0x10($sp)
    ctx->r6 = MEM_HU(0X10, ctx->r29);
    // addiu       $a1, $sp, 0x12
    ctx->r5 = ADD32(ctx->r29, 0X12);
    // sw          $a0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r4;
    // jal         0x80014D2C
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);

    sub_80014D2C(rdram, ctx);
    goto after_5;
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_5:
    // lw          $ra, 0x8B0($sp)
    ctx->r31 = MEM_W(0X8B0, ctx->r29);
    // lw          $s1, 0x8AC($sp)
    ctx->r17 = MEM_W(0X8AC, ctx->r29);
    // lw          $s0, 0x8A8($sp)
    ctx->r16 = MEM_W(0X8A8, ctx->r29);
    // addiu       $sp, $sp, 0x8B8
    ctx->r29 = ADD32(ctx->r29, 0X8B8);
    // jr          $ra
    // nop

    return;
    // nop

;}
