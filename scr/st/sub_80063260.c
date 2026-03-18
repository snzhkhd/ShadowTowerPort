#include "recomp.h"
#include "disable_warnings.h"

void sub_80063260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sh          $v0, 0x2E6($s2)
    MEM_H(0X2E6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x2E8($s2)
    MEM_H(0X2E8, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x230
    ctx->r2 = ADD32(0, 0X230);
    // sh          $v0, 0x2EA($s2)
    MEM_H(0X2EA, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1EF
    ctx->r2 = ADD32(0, 0X1EF);
    // jal         0x80015AD4
    // sh          $v0, 0x2EC($s2)
    MEM_H(0X2EC, ctx->r18) = ctx->r2;
    sub_80015AD4(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x2EC($s2)
    MEM_H(0X2EC, ctx->r18) = ctx->r2;
    after_0:
    // lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // addiu       $s0, $s1, -0x7378
    ctx->r16 = ADD32(ctx->r17, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_1;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    sub_80014CFC(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_2:
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // ori         $a1, $a1, 0x2E6
    ctx->r5 = ctx->r5 | 0X2E6;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // ori         $a2, $a2, 0x2EA
    ctx->r6 = ctx->r6 | 0X2EA;
    // lw          $v0, -0x7378($s1)
    ctx->r2 = MEM_W(-0X7378, ctx->r17);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // jal         0x8003EC5C
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_3;
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // jal         0x80057A3C
    // sb          $zero, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = 0;
    sub_80057A3C(rdram, ctx);
    goto after_4;
    // sb          $zero, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = 0;
    after_4:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s0, $v0, -0x2E80
    ctx->r16 = ADD32(ctx->r2, -0X2E80);
L_80063304:
    // lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(0X4, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_80063328
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063328;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // j           L_800633AC
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    goto L_800633AC;
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
L_80063328:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_80063350
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063350;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
L_80063350:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_80063374
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063374;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_80063374:
    // jal         0x800164B4
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    sub_800164B4(rdram, ctx);
    goto after_8;
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    after_8:
    // jal         0x8002CEF8
    // nop

    sub_8002CEF8(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lbu         $a0, 0x2E4($s2)
    ctx->r4 = MEM_BU(0X2E4, ctx->r18);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_8006339C
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8006339C;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_8006339C:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_80063304
    // sb          $v0, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = ctx->r2;
    goto L_80063304;
    // sb          $v0, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = ctx->r2;
L_800633AC:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
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
