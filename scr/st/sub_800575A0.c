#include "recomp.h"
#include "disable_warnings.h"

void sub_800575A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x8007C910
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    PadGetState_0(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v1, $v1, -0x2E80
    ctx->r3 = ADD32(ctx->r3, -0X2E80);
    // sb          $v0, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x15($v1)
    ctx->r2 = MEM_BU(0X15, ctx->r3);
    // nop

    // andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80057674
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_80057674;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x2854
    ctx->r2 = ADD32(ctx->r2, 0X2854);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_800575E8;
    jr_addend_800575E8 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_800575E8 >> 2) {
        case 0: goto L_800575F0; break;
        case 1: goto L_80057608; break;
        case 2: goto L_80057654; break;
        case 3: goto L_80057674; break;
        case 4: goto L_80057674; break;
        case 5: goto L_80057674; break;
        case 6: goto L_80057620; break;
        default: switch_error(__func__, 0x800575E8, 0x80012854);
    }
    // nop

L_800575F0:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r3;
    // j           L_80057674
    // sb          $v1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r3;
    goto L_80057674;
    // sb          $v1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r3;
L_80057608:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r3;
    // j           L_80057674
    // nop

    goto L_80057674;
    // nop

L_80057620:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v1, $v0, -0x2E80
    ctx->r3 = ADD32(ctx->r2, -0X2E80);
    // lbu         $v0, 0x17($v1)
    ctx->r2 = MEM_BU(0X17, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80057658
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80057658;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, 0x16($v1)
    ctx->r2 = MEM_BU(0X16, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80057658
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80057658;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // sb          $zero, 0x17($v1)
    MEM_B(0X17, ctx->r3) = 0;
    // jal         0x800574C0
    // nop

    sub_800574C0(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_80057654:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80057658:
    // addiu       $v1, $v0, -0x2E80
    ctx->r3 = ADD32(ctx->r2, -0X2E80);
    // lbu         $v0, 0x16($v1)
    ctx->r2 = MEM_BU(0X16, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80057674
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80057674;
    }
    // nop

    // sb          $zero, 0x16($v1)
    MEM_B(0X16, ctx->r3) = 0;
    // sb          $zero, 0xE($v1)
    MEM_B(0XE, ctx->r3) = 0;
L_80057674:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
