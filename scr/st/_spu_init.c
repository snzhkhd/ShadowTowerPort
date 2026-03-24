#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libspu.h"


void _spu_init(uint8_t* rdram, recomp_context* ctx) 
{
    SpuInit();
    printf("_spu_init\n");
    return;


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD50($a0)
    ctx->r4 = MEM_W(0XD50, ctx->r4);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lui         $v1, 0xB
    ctx->r3 = S32(0XB << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xD5C($at)
    MEM_W(0XD5C, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xD60($at)
    MEM_W(0XD60, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $zero, 0xD58($at)
    MEM_H(0XD58, ctx->r1) = 0;
    // sh          $zero, 0x180($v0)
    MEM_H(0X180, ctx->r2) = 0;
    // sh          $zero, 0x182($v0)
    MEM_H(0X182, ctx->r2) = 0;
    // jal         0x8006C77C
    // sh          $zero, 0x1AA($v0)
    MEM_H(0X1AA, ctx->r2) = 0;
    _spu_Fw1ts(rdram, ctx);
    goto after_0;
    // sh          $zero, 0x1AA($v0)
    MEM_H(0X1AA, ctx->r2) = 0;
    after_0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // nop

    // sh          $zero, 0x180($v0)
    MEM_H(0X180, ctx->r2) = 0;
    // sh          $zero, 0x182($v0)
    MEM_H(0X182, ctx->r2) = 0;
    // lhu         $v0, 0x1AE($v0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // beq         $v0, $zero, L_8006BD74
    if (ctx->r2 == 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8006BD74;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006BD2C:
    // sltiu       $v0, $v1, 0xF01
    ctx->r2 = ctx->r3 < 0XF01 ? 1 : 0;
    // bne         $v0, $zero, L_8006BD54
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006BD54;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x3E50
    ctx->r4 = ADD32(ctx->r4, 0X3E50);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a1, $a1, 0x3E60
    ctx->r5 = ADD32(ctx->r5, 0X3E60);
    printf(rdram, ctx);
    goto after_1;
    // addiu       $a1, $a1, 0x3E60
    ctx->r5 = ADD32(ctx->r5, 0X3E60);
    after_1:
    // j           L_8006BD78
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    goto L_8006BD78;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8006BD54:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // nop

    // lhu         $v0, 0x1AE($v0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // bne         $v0, $zero, L_8006BD2C
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8006BD2C;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006BD74:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8006BD78:
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // addiu       $a1, $a1, -0x7A58
    ctx->r5 = ADD32(ctx->r5, -0X7A58);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xD64($at)
    MEM_W(0XD64, ctx->r1) = ctx->r2;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xD68($at)
    MEM_W(0XD68, ctx->r1) = ctx->r2;
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xD6C($at)
    MEM_W(0XD6C, ctx->r1) = ctx->r2;
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // sh          $v1, 0x1AC($v0)
    MEM_H(0X1AC, ctx->r2) = ctx->r3;
    // ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // sh          $zero, 0x184($v0)
    MEM_H(0X184, ctx->r2) = 0;
    // sh          $zero, 0x186($v0)
    MEM_H(0X186, ctx->r2) = 0;
    // sh          $v1, 0x18C($v0)
    MEM_H(0X18C, ctx->r2) = ctx->r3;
    // sh          $v1, 0x18E($v0)
    MEM_H(0X18E, ctx->r2) = ctx->r3;
    // sh          $zero, 0x198($v0)
    MEM_H(0X198, ctx->r2) = 0;
    // sh          $zero, 0x19A($v0)
    MEM_H(0X19A, ctx->r2) = 0;
L_8006BDDC:
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0xA
    ctx->r2 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // bne         $v0, $zero, L_8006BDDC
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
        goto L_8006BDDC;
    }
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // bne         $s0, $zero, L_8006BEE4
    if (ctx->r16 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8006BEE4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, 0xD80
    ctx->r4 = ADD32(ctx->r4, 0XD80);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // addiu       $v1, $zero, 0x200
    ctx->r3 = ADD32(0, 0X200);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v1, 0xD58($at)
    MEM_H(0XD58, ctx->r1) = ctx->r3;
    // sh          $zero, 0x190($v0)
    MEM_H(0X190, ctx->r2) = 0;
    // sh          $zero, 0x192($v0)
    MEM_H(0X192, ctx->r2) = 0;
    // sh          $zero, 0x194($v0)
    MEM_H(0X194, ctx->r2) = 0;
    // sh          $zero, 0x196($v0)
    MEM_H(0X196, ctx->r2) = 0;
    // sh          $zero, 0x1B0($v0)
    MEM_H(0X1B0, ctx->r2) = 0;
    // sh          $zero, 0x1B2($v0)
    MEM_H(0X1B2, ctx->r2) = 0;
    // sh          $zero, 0x1B4($v0)
    MEM_H(0X1B4, ctx->r2) = 0;
    // sh          $zero, 0x1B6($v0)
    MEM_H(0X1B6, ctx->r2) = 0;
    // jal         0x8006BF24
    // addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sub_8006BF24(rdram, ctx);
    goto after_2;
    // addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x3FFF
    ctx->r6 = ADD32(0, 0X3FFF);
    // addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

L_8006BE54:
    // sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
    // sh          $a1, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r5;
    // sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x18
    ctx->r2 = SIGNED(ctx->r4) < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_8006BE54
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
        goto L_8006BE54;
    }
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // sh          $s1, 0x188($v0)
    MEM_H(0X188, ctx->r2) = ctx->r17;
    // jal         0x8006C77C
    // sh          $s0, 0x18A($v0)
    MEM_H(0X18A, ctx->r2) = ctx->r16;
    _spu_Fw1ts(rdram, ctx);
    goto after_3;
    // sh          $s0, 0x18A($v0)
    MEM_H(0X18A, ctx->r2) = ctx->r16;
    after_3:
    // jal         0x8006C77C
    // nop

    _spu_Fw1ts(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x8006C77C
    // nop

    _spu_Fw1ts(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x8006C77C
    // nop

    _spu_Fw1ts(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // nop

    // sh          $s1, 0x18C($v0)
    MEM_H(0X18C, ctx->r2) = ctx->r17;
    // jal         0x8006C77C
    // sh          $s0, 0x18E($v0)
    MEM_H(0X18E, ctx->r2) = ctx->r16;
    _spu_Fw1ts(rdram, ctx);
    goto after_7;
    // sh          $s0, 0x18E($v0)
    MEM_H(0X18E, ctx->r2) = ctx->r16;
    after_7:
    // jal         0x8006C77C
    // nop

    _spu_Fw1ts(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // jal         0x8006C77C
    // nop

    _spu_Fw1ts(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // jal         0x8006C77C
    // nop

    _spu_Fw1ts(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006BEE4:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD40($a0)
    ctx->r4 = MEM_W(0XD40, ctx->r4);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, 0xD74($at)
    MEM_W(0XD74, ctx->r1) = ctx->r3;
    // ori         $v1, $zero, 0xC000
    ctx->r3 = 0 | 0XC000;
    // sh          $v1, 0x1AA($a0)
    MEM_H(0X1AA, ctx->r4) = ctx->r3;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xD78($at)
    MEM_W(0XD78, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xD7C($at)
    MEM_W(0XD7C, ctx->r1) = 0;
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
