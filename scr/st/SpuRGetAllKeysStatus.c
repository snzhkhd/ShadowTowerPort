#include "recomp.h"
#include "disable_warnings.h"

void SpuRGetAllKeysStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // bgez        $a0, L_8006BB54
    if (SIGNED(ctx->r4) >= 0) {
        // slti        $v0, $a0, 0x18
        ctx->r2 = SIGNED(ctx->r4) < 0X18 ? 1 : 0;
        goto L_8006BB54;
    }
    // slti        $v0, $a0, 0x18
    ctx->r2 = SIGNED(ctx->r4) < 0X18 ? 1 : 0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // slti        $v0, $a0, 0x18
    ctx->r2 = SIGNED(ctx->r4) < 0X18 ? 1 : 0;
L_8006BB54:
    // beq         $v0, $zero, L_8006BB7C
    if (ctx->r2 == 0) {
        // slti        $v0, $a1, 0x18
        ctx->r2 = SIGNED(ctx->r5) < 0X18 ? 1 : 0;
        goto L_8006BB7C;
    }
    // slti        $v0, $a1, 0x18
    ctx->r2 = SIGNED(ctx->r5) < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_8006BB68
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006BB68;
    }
    // nop

    // addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
L_8006BB68:
    // bltz        $a1, L_8006BC10
    if (SIGNED(ctx->r5) < 0) {
        // addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
        goto L_8006BC10;
    }
    // addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_8006BB84
    if (ctx->r2 == 0) {
        // addu        $a3, $a0, $zero
        ctx->r7 = ADD32(ctx->r4, 0);
        goto L_8006BB84;
    }
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
L_8006BB7C:
    // j           L_8006BC10
    // addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    goto L_8006BC10;
    // addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
L_8006BB84:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a3, $a1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_8006BC10
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8006BC10;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // addu        $a2, $a3, $a2
    ctx->r6 = ADD32(ctx->r7, ctx->r6);
L_8006BBA4:
    // sll         $a0, $a3, 4
    ctx->r4 = S32(ctx->r7) << 4;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xDAC($v1)
    ctx->r3 = MEM_W(0XDAC, ctx->r3);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sllv        $v0, $t0, $a3
    ctx->r2 = S32(ctx->r8) << (ctx->r7 & 31);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(0XC, ctx->r4);
    // beq         $v1, $zero, L_8006BBE8
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8006BBE8;
    }
    // nop

    // beq         $v0, $zero, L_8006BBE0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006BBE0;
    }
    // nop

    // j           L_8006BBFC
    // sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    goto L_8006BBFC;
    // sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
L_8006BBE0:
    // j           L_8006BBFC
    // sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    goto L_8006BBFC;
    // sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
L_8006BBE8:
    // beq         $v0, $zero, L_8006BBF8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006BBF8;
    }
    // nop

    // j           L_8006BBFC
    // sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    goto L_8006BBFC;
    // sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
L_8006BBF8:
    // sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
L_8006BBFC:
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // slt         $v0, $a3, $a1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8006BBA4
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8006BBA4;
    }
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006BC10:
    // jr          $ra
    // nop

    return;
    // nop

;}
