#include "recomp.h"
#include "disable_warnings.h"

void sub_800631AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $s1, 0x34($v0)
    ctx->r17 = MEM_W(0X34, ctx->r2);
    // lbu         $s2, 0x33($v0)
    ctx->r18 = MEM_BU(0X33, ctx->r2);
    // jal         0x80015AD4
    // nop

    sub_80015AD4(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x80058C04
    // nop

    PadChkVsync(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s0, $v0, -0x2E80
    ctx->r16 = ADD32(ctx->r2, -0X2E80);
L_800631F8:
    // lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(0X4, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // bne         $v0, $zero, L_80063224
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80063224;
    }
    // nop

    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x80031D50
    // nop

    sub_80031D50(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // j           L_800631F8
    // nop

    goto L_800631F8;
    // nop

L_80063224:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // jal         0x80058C24
    // nop

    PadStartCom(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sw          $s1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r17;
    // sb          $s2, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r18;
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
