#include "recomp.h"
#include "disable_warnings.h"

void sub_80049AAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $a2, $v0, L_80049B60
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_80049B60;
    }
    // nop

    // slti        $v0, $a2, 0x2
    ctx->r2 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80049AD4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80049AD4;
    }
    // nop

    // beq         $a2, $zero, L_80049AF4
    if (ctx->r6 == 0) {
        // nop
    
        goto L_80049AF4;
    }
    // nop

    // j           L_80049CCC
    // nop

    goto L_80049CCC;
    // nop

L_80049AD4:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $a2, $v0, L_80049BD4
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_80049BD4;
    }
    // nop

    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $a2, $v0, L_80049C54
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_80049C54;
    }
    // nop

    // j           L_80049CCC
    // nop

    goto L_80049CCC;
    // nop

L_80049AF4:
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // nop

    // sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // nop

    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(0X6, ctx->r4);
    // nop

    // sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // nop

    // sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(0XA, ctx->r4);
    // nop

    // sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(0XC, ctx->r4);
    // nop

    // sh          $v0, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xE($a0)
    ctx->r2 = MEM_HU(0XE, ctx->r4);
    // nop

    // sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x10($a0)
    ctx->r2 = MEM_HU(0X10, ctx->r4);
    // j           L_80049CCC
    // sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
    goto L_80049CCC;
    // sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
L_80049B60:
    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // nop

    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // nop

    // sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(0XA, ctx->r4);
    // nop

    // sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // nop

    // sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(0X6, ctx->r4);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x10($a0)
    ctx->r2 = MEM_HU(0X10, ctx->r4);
    // nop

    // sh          $v0, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xE($a0)
    ctx->r2 = MEM_HU(0XE, ctx->r4);
    // nop

    // sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(0XC, ctx->r4);
    // j           L_80049CC4
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    goto L_80049CC4;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80049BD4:
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // nop

    // sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(0X6, ctx->r4);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // nop

    // sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(0XA, ctx->r4);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(0XC, ctx->r4);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xE($a0)
    ctx->r2 = MEM_HU(0XE, ctx->r4);
    // nop

    // sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x10($a0)
    ctx->r2 = MEM_HU(0X10, ctx->r4);
    // j           L_80049CC4
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    goto L_80049CC4;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80049C54:
    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // nop

    // sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(0XA, ctx->r4);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // nop

    // sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(0X6, ctx->r4);
    // nop

    // sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x10($a0)
    ctx->r2 = MEM_HU(0X10, ctx->r4);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xE($a0)
    ctx->r2 = MEM_HU(0XE, ctx->r4);
    // nop

    // sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(0XC, ctx->r4);
L_80049CC4:
    // nop

    // sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
L_80049CCC:
    // jr          $ra
    // nop

    return;
    // nop

;}
