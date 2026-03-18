#include "recomp.h"
#include "disable_warnings.h"

void sub_8003BE10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $a0, 0x5994($v0)
    ctx->r4 = MEM_W(0X5994, ctx->r2);
    // lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // beq         $a0, $v0, L_8003BE48
    if (ctx->r4 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003BE48;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $v0, 0x24C($v1)
    ctx->r2 = MEM_W(0X24C, ctx->r3);
    // nop

    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003BE44
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8003BE44;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_8003BE48
    // sw          $v0, 0x2EC($v1)
    MEM_W(0X2EC, ctx->r3) = ctx->r2;
    goto L_8003BE48;
    // sw          $v0, 0x2EC($v1)
    MEM_W(0X2EC, ctx->r3) = ctx->r2;
L_8003BE44:
    // sw          $zero, 0x2EC($v1)
    MEM_W(0X2EC, ctx->r3) = 0;
L_8003BE48:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $a0, 0x59A0($v0)
    ctx->r4 = MEM_W(0X59A0, ctx->r2);
    // lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // beq         $a0, $v0, L_8003BE80
    if (ctx->r4 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003BE80;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $v0, 0x24C($v1)
    ctx->r2 = MEM_W(0X24C, ctx->r3);
    // nop

    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003BE7C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8003BE7C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_8003BE80
    // sw          $v0, 0x2F0($v1)
    MEM_W(0X2F0, ctx->r3) = ctx->r2;
    goto L_8003BE80;
    // sw          $v0, 0x2F0($v1)
    MEM_W(0X2F0, ctx->r3) = ctx->r2;
L_8003BE7C:
    // sw          $zero, 0x2F0($v1)
    MEM_W(0X2F0, ctx->r3) = 0;
L_8003BE80:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x5924($v0)
    ctx->r3 = MEM_BU(0X5924, ctx->r2);
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // bne         $v1, $v0, L_8003BEAC
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003BEAC;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lh          $v1, 0x178($a0)
    ctx->r3 = MEM_HS(0X178, ctx->r4);
    // addiu       $v0, $zero, 0x147
    ctx->r2 = ADD32(0, 0X147);
    // bne         $v1, $v0, L_8003BEAC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003BEAC;
    }
    // nop

    // sw          $zero, 0x2F0($a0)
    MEM_W(0X2F0, ctx->r4) = 0;
L_8003BEAC:
    // jr          $ra
    // nop

    return;
    // nop

;}
