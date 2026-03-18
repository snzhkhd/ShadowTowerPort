#include "recomp.h"
#include "disable_warnings.h"

void sub_8006A94C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA0($v0)
    ctx->r2 = MEM_W(0XCA0, ctx->r2);
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // addiu       $s1, $s1, 0xCB9
    ctx->r17 = ADD32(ctx->r17, 0XCB9);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $s3, $s1, -0x1
    ctx->r19 = ADD32(ctx->r17, -0X1);
    // andi        $s2, $v0, 0x3
    ctx->r18 = ctx->r2 & 0X3;
L_8006A980:
    // jal         0x800692C4
    // nop

    sub_800692C4(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8006A9F8
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x4
        ctx->r2 = ctx->r16 & 0X4;
        goto L_8006A9F8;
    }
    // andi        $v0, $s0, 0x4
    ctx->r2 = ctx->r16 & 0X4;
    // beq         $v0, $zero, L_8006A9C4
    if (ctx->r2 == 0) {
        // andi        $v0, $s0, 0x2
        ctx->r2 = ctx->r16 & 0X2;
        goto L_8006A9C4;
    }
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9DC($v0)
    ctx->r2 = MEM_W(0X9DC, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8006A9C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006A9C0;
    }
    // nop

    // lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(0X0, ctx->r17);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // jalr        $v0
    // addiu       $a1, $a1, 0x6178
    ctx->r5 = ADD32(ctx->r5, 0X6178);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // addiu       $a1, $a1, 0x6178
    ctx->r5 = ADD32(ctx->r5, 0X6178);
    after_1:
L_8006A9C0:
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
L_8006A9C4:
    // beq         $v0, $zero, L_8006A980
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006A980;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x9D8($v0)
    ctx->r2 = MEM_W(0X9D8, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8006A980
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006A980;
    }
    // nop

    // lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(0X0, ctx->r19);
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // jalr        $v0
    // addiu       $a1, $a1, 0x6170
    ctx->r5 = ADD32(ctx->r5, 0X6170);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // addiu       $a1, $a1, 0x6170
    ctx->r5 = ADD32(ctx->r5, 0X6170);
    after_2:
    // j           L_8006A980
    // nop

    goto L_8006A980;
    // nop

L_8006A9F8:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xCA0($v0)
    ctx->r2 = MEM_W(0XCA0, ctx->r2);
    // nop

    // sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    return;
;}
