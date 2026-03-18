#include "recomp.h"
#include "disable_warnings.h"

void SpuSetVoiceAttr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(0X4, ctx->r16);
    // lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // addiu       $s5, $s5, 0xDDC
    ctx->r21 = ADD32(ctx->r21, 0XDDC);
    // sltiu       $s2, $s1, 0x1
    ctx->r18 = ctx->r17 < 0X1 ? 1 : 0;
L_8007123C:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // sllv        $v0, $v0, $s4
    ctx->r2 = S32(ctx->r2) << (ctx->r20 & 31);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // beq         $v1, $zero, L_80071778
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80071778;
    }
    // nop

    // bne         $s2, $zero, L_80071268
    if (ctx->r18 != 0) {
        // sll         $s3, $s4, 3
        ctx->r19 = S32(ctx->r20) << 3;
        goto L_80071268;
    }
    // sll         $s3, $s4, 3
    ctx->r19 = S32(ctx->r20) << 3;
    // andi        $v0, $s1, 0x10
    ctx->r2 = ctx->r17 & 0X10;
    // beq         $v0, $zero, L_80071280
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80071280;
    }
    // nop

L_80071268:
    // sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20) << 4;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(0X14, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $a0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r4;
L_80071280:
    // bne         $s2, $zero, L_80071290
    if (ctx->r18 != 0) {
        // andi        $v0, $s1, 0x40
        ctx->r2 = ctx->r17 & 0X40;
        goto L_80071290;
    }
    // andi        $v0, $s1, 0x40
    ctx->r2 = ctx->r17 & 0X40;
    // beq         $v0, $zero, L_8007129C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007129C;
    }
    // nop

L_80071290:
    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // nop

    // sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
L_8007129C:
    // bne         $s2, $zero, L_800712AC
    if (ctx->r18 != 0) {
        // andi        $v0, $s1, 0x20
        ctx->r2 = ctx->r17 & 0X20;
        goto L_800712AC;
    }
    // andi        $v0, $s1, 0x20
    ctx->r2 = ctx->r17 & 0X20;
    // beq         $v0, $zero, L_800712DC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800712DC;
    }
    // nop

L_800712AC:
    // lhu         $a1, 0x0($s5)
    ctx->r5 = MEM_HU(0X0, ctx->r21);
    // lhu         $a3, 0x16($s0)
    ctx->r7 = MEM_HU(0X16, ctx->r16);
    // srl         $a0, $a1, 8
    ctx->r4 = S32(U32(ctx->r5) >> 8);
    // andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // srl         $a2, $a3, 8
    ctx->r6 = S32(U32(ctx->r7) >> 8);
    // jal         0x80071890
    // andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    sub_80071890(rdram, ctx);
    goto after_0;
    // andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_0:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD40($a0)
    ctx->r4 = MEM_W(0XD40, ctx->r4);
    // sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
L_800712DC:
    // bne         $s2, $zero, L_800712EC
    if (ctx->r18 != 0) {
        // andi        $v0, $s1, 0x1
        ctx->r2 = ctx->r17 & 0X1;
        goto L_800712EC;
    }
    // andi        $v0, $s1, 0x1
    ctx->r2 = ctx->r17 & 0X1;
    // beq         $v0, $zero, L_800713BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800713BC;
    }
    // nop

L_800712EC:
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // bne         $s2, $zero, L_80071308
    if (ctx->r18 != 0) {
        // andi        $a1, $v0, 0x7FFF
        ctx->r5 = ctx->r2 & 0X7FFF;
        goto L_80071308;
    }
    // andi        $a1, $v0, 0x7FFF
    ctx->r5 = ctx->r2 & 0X7FFF;
    // andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
    // beq         $v0, $zero, L_80071374
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80071374;
    }
    // nop

L_80071308:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80071374
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_80071374;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addu        $at, $at, $v0
    gpr jr_addend_80071338;
    jr_addend_80071338 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x3F00($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80071338 >> 2) {
        case 0: goto L_80071340; break;
        case 1: goto L_80071348; break;
        case 2: goto L_80071350; break;
        case 3: goto L_80071358; break;
        case 4: goto L_80071360; break;
        case 5: goto L_80071368; break;
        case 6: goto L_80071370; break;
        default: switch_error(__func__, 0x80071338, 0x80013F00);
    }
    // nop

L_80071340:
    // j           L_80071374
    // ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    goto L_80071374;
    // ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
L_80071348:
    // j           L_80071374
    // ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    goto L_80071374;
    // ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
L_80071350:
    // j           L_80071374
    // ori         $a0, $zero, 0xA000
    ctx->r4 = 0 | 0XA000;
    goto L_80071374;
    // ori         $a0, $zero, 0xA000
    ctx->r4 = 0 | 0XA000;
L_80071358:
    // j           L_80071374
    // ori         $a0, $zero, 0xB000
    ctx->r4 = 0 | 0XB000;
    goto L_80071374;
    // ori         $a0, $zero, 0xB000
    ctx->r4 = 0 | 0XB000;
L_80071360:
    // j           L_80071374
    // ori         $a0, $zero, 0xC000
    ctx->r4 = 0 | 0XC000;
    goto L_80071374;
    // ori         $a0, $zero, 0xC000
    ctx->r4 = 0 | 0XC000;
L_80071368:
    // j           L_80071374
    // ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    goto L_80071374;
    // ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
L_80071370:
    // ori         $a0, $zero, 0xE000
    ctx->r4 = 0 | 0XE000;
L_80071374:
    // beq         $a0, $zero, L_800713A4
    if (ctx->r4 == 0) {
        // nop
    
        goto L_800713A4;
    }
    // nop

    // lh          $v1, 0x8($s0)
    ctx->r3 = MEM_HS(0X8, ctx->r16);
    // nop

    // slti        $v0, $v1, 0x80
    ctx->r2 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_80071398
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80071398;
    }
    // nop

    // j           L_800713A4
    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    goto L_800713A4;
    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
L_80071398:
    // bgez        $v1, L_800713A4
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_800713A4;
    }
    // nop

    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800713A4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // or          $v0, $a1, $a0
    ctx->r2 = ctx->r5 | ctx->r4;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_800713BC:
    // bne         $s2, $zero, L_800713CC
    if (ctx->r18 != 0) {
        // andi        $v0, $s1, 0x2
        ctx->r2 = ctx->r17 & 0X2;
        goto L_800713CC;
    }
    // andi        $v0, $s1, 0x2
    ctx->r2 = ctx->r17 & 0X2;
    // beq         $v0, $zero, L_8007149C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007149C;
    }
    // nop

L_800713CC:
    // lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(0XA, ctx->r16);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // bne         $s2, $zero, L_800713E8
    if (ctx->r18 != 0) {
        // andi        $a1, $v0, 0x7FFF
        ctx->r5 = ctx->r2 & 0X7FFF;
        goto L_800713E8;
    }
    // andi        $a1, $v0, 0x7FFF
    ctx->r5 = ctx->r2 & 0X7FFF;
    // andi        $v0, $s1, 0x8
    ctx->r2 = ctx->r17 & 0X8;
    // beq         $v0, $zero, L_80071454
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80071454;
    }
    // nop

L_800713E8:
    // lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(0XE, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80071454
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_80071454;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addu        $at, $at, $v0
    gpr jr_addend_80071418;
    jr_addend_80071418 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x3F20($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80071418 >> 2) {
        case 0: goto L_80071420; break;
        case 1: goto L_80071428; break;
        case 2: goto L_80071430; break;
        case 3: goto L_80071438; break;
        case 4: goto L_80071440; break;
        case 5: goto L_80071448; break;
        case 6: goto L_80071450; break;
        default: switch_error(__func__, 0x80071418, 0x80013F20);
    }
    // nop

L_80071420:
    // j           L_80071454
    // ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    goto L_80071454;
    // ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
L_80071428:
    // j           L_80071454
    // ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    goto L_80071454;
    // ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
L_80071430:
    // j           L_80071454
    // ori         $a0, $zero, 0xA000
    ctx->r4 = 0 | 0XA000;
    goto L_80071454;
    // ori         $a0, $zero, 0xA000
    ctx->r4 = 0 | 0XA000;
L_80071438:
    // j           L_80071454
    // ori         $a0, $zero, 0xB000
    ctx->r4 = 0 | 0XB000;
    goto L_80071454;
    // ori         $a0, $zero, 0xB000
    ctx->r4 = 0 | 0XB000;
L_80071440:
    // j           L_80071454
    // ori         $a0, $zero, 0xC000
    ctx->r4 = 0 | 0XC000;
    goto L_80071454;
    // ori         $a0, $zero, 0xC000
    ctx->r4 = 0 | 0XC000;
L_80071448:
    // j           L_80071454
    // ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    goto L_80071454;
    // ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
L_80071450:
    // ori         $a0, $zero, 0xE000
    ctx->r4 = 0 | 0XE000;
L_80071454:
    // beq         $a0, $zero, L_80071484
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80071484;
    }
    // nop

    // lh          $v1, 0xA($s0)
    ctx->r3 = MEM_HS(0XA, ctx->r16);
    // nop

    // slti        $v0, $v1, 0x80
    ctx->r2 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_80071478
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80071478;
    }
    // nop

    // j           L_80071484
    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    goto L_80071484;
    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
L_80071478:
    // bgez        $v1, L_80071484
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80071484;
    }
    // nop

    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80071484:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // or          $v0, $a1, $a0
    ctx->r2 = ctx->r5 | ctx->r4;
    // sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_8007149C:
    // bne         $s2, $zero, L_800714AC
    if (ctx->r18 != 0) {
        // andi        $v0, $s1, 0x80
        ctx->r2 = ctx->r17 & 0X80;
        goto L_800714AC;
    }
    // andi        $v0, $s1, 0x80
    ctx->r2 = ctx->r17 & 0X80;
    // beq         $v0, $zero, L_800714B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800714B8;
    }
    // nop

L_800714AC:
    // lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(0X1C, ctx->r16);
    // jal         0x8006C5F4
    // ori         $a0, $s3, 0x3
    ctx->r4 = ctx->r19 | 0X3;
    _spu_FsetRXXa(rdram, ctx);
    goto after_1;
    // ori         $a0, $s3, 0x3
    ctx->r4 = ctx->r19 | 0X3;
    after_1:
L_800714B8:
    // bne         $s2, $zero, L_800714CC
    if (ctx->r18 != 0) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_800714CC;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_800714D8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800714D8;
    }
    // nop

L_800714CC:
    // lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(0X20, ctx->r16);
    // jal         0x8006C5F4
    // ori         $a0, $s3, 0x7
    ctx->r4 = ctx->r19 | 0X7;
    _spu_FsetRXXa(rdram, ctx);
    goto after_2;
    // ori         $a0, $s3, 0x7
    ctx->r4 = ctx->r19 | 0X7;
    after_2:
L_800714D8:
    // bne         $s2, $zero, L_800714F0
    if (ctx->r18 != 0) {
        // sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19) << 1;
        goto L_800714F0;
    }
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_80071504
    if (ctx->r2 == 0) {
        // sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19) << 1;
        goto L_80071504;
    }
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
L_800714F0:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $a0, 0x3A($s0)
    ctx->r4 = MEM_HU(0X3A, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $a0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r4;
L_80071504:
    // bne         $s2, $zero, L_8007151C
    if (ctx->r18 != 0) {
        // sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19) << 1;
        goto L_8007151C;
    }
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // and         $v0, $s1, $v0
    ctx->r2 = ctx->r17 & ctx->r2;
    // beq         $v0, $zero, L_80071530
    if (ctx->r2 == 0) {
        // sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19) << 1;
        goto L_80071530;
    }
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
L_8007151C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(0X3C, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $a0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r4;
L_80071530:
    // bne         $s2, $zero, L_80071540
    if (ctx->r18 != 0) {
        // andi        $v0, $s1, 0x800
        ctx->r2 = ctx->r17 & 0X800;
        goto L_80071540;
    }
    // andi        $v0, $s1, 0x800
    ctx->r2 = ctx->r17 & 0X800;
    // beq         $v0, $zero, L_800715AC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800715AC;
    }
    // nop

L_80071540:
    // lhu         $a1, 0x30($s0)
    ctx->r5 = MEM_HU(0X30, ctx->r16);
    // nop

    // sltiu       $v0, $a1, 0x80
    ctx->r2 = ctx->r5 < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_80071558
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80071558;
    }
    // nop

    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
L_80071558:
    // bne         $s2, $zero, L_8007156C
    if (ctx->r18 != 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_8007156C;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // andi        $v0, $s1, 0x100
    ctx->r2 = ctx->r17 & 0X100;
    // beq         $v0, $zero, L_80071580
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80071580;
    }
    // nop

L_8007156C:
    // lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(0X24, ctx->r16);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $v1, $v0, L_80071580
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80071580;
    }
    // nop

    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
L_80071580:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // sll         $a0, $s3, 1
    ctx->r4 = S32(ctx->r19) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // nop

    // andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // or          $v0, $a1, $a2
    ctx->r2 = ctx->r5 | ctx->r6;
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sh          $v1, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r3;
L_800715AC:
    // bne         $s2, $zero, L_800715BC
    if (ctx->r18 != 0) {
        // andi        $v0, $s1, 0x1000
        ctx->r2 = ctx->r17 & 0X1000;
        goto L_800715BC;
    }
    // andi        $v0, $s1, 0x1000
    ctx->r2 = ctx->r17 & 0X1000;
    // beq         $v0, $zero, L_800715F8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800715F8;
    }
    // nop

L_800715BC:
    // lhu         $a1, 0x32($s0)
    ctx->r5 = MEM_HU(0X32, ctx->r16);
    // nop

    // sltiu       $v0, $a1, 0x10
    ctx->r2 = ctx->r5 < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_800715D4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800715D4;
    }
    // nop

    // addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
L_800715D4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // sll         $a0, $s3, 1
    ctx->r4 = S32(ctx->r19) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5) << 4;
    // andi        $v0, $v0, 0xFF0F
    ctx->r2 = ctx->r2 & 0XFF0F;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
L_800715F8:
    // bne         $s2, $zero, L_80071608
    if (ctx->r18 != 0) {
        // andi        $v0, $s1, 0x2000
        ctx->r2 = ctx->r17 & 0X2000;
        goto L_80071608;
    }
    // andi        $v0, $s1, 0x2000
    ctx->r2 = ctx->r17 & 0X2000;
    // beq         $v0, $zero, L_800716B0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800716B0;
    }
    // nop

L_80071608:
    // lhu         $a1, 0x34($s0)
    ctx->r5 = MEM_HU(0X34, ctx->r16);
    // nop

    // sltiu       $v0, $a1, 0x80
    ctx->r2 = ctx->r5 < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_80071620
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80071620;
    }
    // nop

    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
L_80071620:
    // bne         $s2, $zero, L_80071634
    if (ctx->r18 != 0) {
        // addiu       $a2, $zero, 0x100
        ctx->r6 = ADD32(0, 0X100);
        goto L_80071634;
    }
    // addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    // andi        $v0, $s1, 0x200
    ctx->r2 = ctx->r17 & 0X200;
    // beq         $v0, $zero, L_80071684
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80071684;
    }
    // nop

L_80071634:
    // lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(0X28, ctx->r16);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // beq         $v1, $v0, L_80071678
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x6
        ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
        goto L_80071678;
    }
    // slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_8007165C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007165C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_80071670
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80071670;
    }
    // nop

    // j           L_80071684
    // nop

    goto L_80071684;
    // nop

L_8007165C:
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // beq         $v1, $v0, L_80071680
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80071680;
    }
    // nop

    // j           L_80071684
    // nop

    goto L_80071684;
    // nop

L_80071670:
    // j           L_80071684
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_80071684;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80071678:
    // j           L_80071684
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    goto L_80071684;
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
L_80071680:
    // addiu       $a2, $zero, 0x300
    ctx->r6 = ADD32(0, 0X300);
L_80071684:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // sll         $a0, $s3, 1
    ctx->r4 = S32(ctx->r19) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(0XA, ctx->r4);
    // nop

    // andi        $v1, $v0, 0x3F
    ctx->r3 = ctx->r2 & 0X3F;
    // or          $v0, $a1, $a2
    ctx->r2 = ctx->r5 | ctx->r6;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sh          $v1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r3;
L_800716B0:
    // bne         $s2, $zero, L_800716C0
    if (ctx->r18 != 0) {
        // andi        $v0, $s1, 0x4000
        ctx->r2 = ctx->r17 & 0X4000;
        goto L_800716C0;
    }
    // andi        $v0, $s1, 0x4000
    ctx->r2 = ctx->r17 & 0X4000;
    // beq         $v0, $zero, L_8007172C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007172C;
    }
    // nop

L_800716C0:
    // lhu         $a1, 0x36($s0)
    ctx->r5 = MEM_HU(0X36, ctx->r16);
    // nop

    // sltiu       $v0, $a1, 0x20
    ctx->r2 = ctx->r5 < 0X20 ? 1 : 0;
    // bne         $v0, $zero, L_800716D8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800716D8;
    }
    // nop

    // addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
L_800716D8:
    // bne         $s2, $zero, L_800716EC
    if (ctx->r18 != 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_800716EC;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // andi        $v0, $s1, 0x400
    ctx->r2 = ctx->r17 & 0X400;
    // beq         $v0, $zero, L_80071708
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80071708;
    }
    // nop

L_800716EC:
    // lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(0X2C, ctx->r16);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_80071708
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
        goto L_80071708;
    }
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // bne         $v1, $v0, L_80071708
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80071708;
    }
    // nop

    // addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_80071708:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // sll         $a0, $s3, 1
    ctx->r4 = S32(ctx->r19) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(0XA, ctx->r4);
    // or          $v1, $a1, $a2
    ctx->r3 = ctx->r5 | ctx->r6;
    // andi        $v0, $v0, 0xFFC0
    ctx->r2 = ctx->r2 & 0XFFC0;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
L_8007172C:
    // bne         $s2, $zero, L_8007173C
    if (ctx->r18 != 0) {
        // andi        $v0, $s1, 0x8000
        ctx->r2 = ctx->r17 & 0X8000;
        goto L_8007173C;
    }
    // andi        $v0, $s1, 0x8000
    ctx->r2 = ctx->r17 & 0X8000;
    // beq         $v0, $zero, L_80071778
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80071778;
    }
    // nop

L_8007173C:
    // lhu         $a1, 0x38($s0)
    ctx->r5 = MEM_HU(0X38, ctx->r16);
    // nop

    // sltiu       $v0, $a1, 0x10
    ctx->r2 = ctx->r5 < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80071754
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80071754;
    }
    // nop

    // addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
L_80071754:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x8($v1)
    ctx->r2 = MEM_HU(0X8, ctx->r3);
    // nop

    // andi        $v0, $v0, 0xFFF0
    ctx->r2 = ctx->r2 & 0XFFF0;
    // or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
L_80071778:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // slti        $v0, $s4, 0x18
    ctx->r2 = SIGNED(ctx->r20) < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_8007123C
    if (ctx->r2 != 0) {
        // addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
        goto L_8007123C;
    }
    // addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // j           L_800717C4
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    goto L_800717C4;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_80071798:
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_800717C4:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80071798
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80071798;
    }
    // nop

    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
