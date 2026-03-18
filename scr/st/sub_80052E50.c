#include "recomp.h"
#include "disable_warnings.h"

void sub_80052E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a2, $v0, -0x51F8
    ctx->r6 = ADD32(ctx->r2, -0X51F8);
    // subu        $v1, $t2, $a2
    ctx->r3 = SUB32(ctx->r10, ctx->r6);
    // lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t4
    ctx->r12 = hi;
    // srl         $a1, $t4, 5
    ctx->r5 = S32(U32(ctx->r12) >> 5);
    // slti        $v0, $a1, 0x20
    ctx->r2 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_80052E94
    if (ctx->r2 == 0) {
        // addiu       $v1, $a2, -0x3710
        ctx->r3 = ADD32(ctx->r6, -0X3710);
        goto L_80052E94;
    }
    // addiu       $v1, $a2, -0x3710
    ctx->r3 = ADD32(ctx->r6, -0X3710);
    // lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(0X1, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_80052F28
    // sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    goto L_80052F28;
    // sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
L_80052E94:
    // slti        $v0, $a1, 0x30
    ctx->r2 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // beq         $v0, $zero, L_80052EB8
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x2F
        ctx->r4 = ADD32(0, 0X2F);
        goto L_80052EB8;
    }
    // addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // addiu       $v1, $a2, -0x3710
    ctx->r3 = ADD32(ctx->r6, -0X3710);
    // lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(0X2, ctx->r3);
    // subu        $t1, $a0, $a1
    ctx->r9 = SUB32(ctx->r4, ctx->r5);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_80052ED0
    // sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    goto L_80052ED0;
    // sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
L_80052EB8:
    // addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // addiu       $v1, $a2, -0x3710
    ctx->r3 = ADD32(ctx->r6, -0X3710);
    // lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(0X3, ctx->r3);
    // subu        $t1, $a0, $a1
    ctx->r9 = SUB32(ctx->r4, ctx->r5);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
L_80052ED0:
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $t1, $v0, L_80052F28
    if (ctx->r9 == ctx->r2) {
        // nop
    
        goto L_80052F28;
    }
    // nop

    // addu        $t3, $v0, $zero
    ctx->r11 = ADD32(ctx->r2, 0);
L_80052EE4:
    // addu        $a3, $t2, $zero
    ctx->r7 = ADD32(ctx->r10, 0);
    // addiu       $a2, $t2, 0x30
    ctx->r6 = ADD32(ctx->r10, 0X30);
    // addiu       $t0, $t2, 0x60
    ctx->r8 = ADD32(ctx->r10, 0X60);
L_80052EF0:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_80052EF0
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_80052EF0;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // bne         $t1, $t3, L_80052EE4
    if (ctx->r9 != ctx->r11) {
        // addiu       $t2, $t2, 0x30
        ctx->r10 = ADD32(ctx->r10, 0X30);
        goto L_80052EE4;
    }
    // addiu       $t2, $t2, 0x30
    ctx->r10 = ADD32(ctx->r10, 0X30);
L_80052F28:
    // jr          $ra
    // sb          $zero, 0x22($t2)
    MEM_B(0X22, ctx->r10) = 0;
    return;
    // sb          $zero, 0x22($t2)
    MEM_B(0X22, ctx->r10) = 0;
;}
