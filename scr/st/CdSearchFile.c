#include "recomp.h"
#include "disable_warnings.h"
#include <string>

void CdSearchFile(uint8_t* rdram, recomp_context* ctx) 
{

    // CdSearchFile(CdlFILE* fp, char* name)
    uint8_t* fp = (uint8_t*)GET_PTR(ctx->r4);
    const char* name = (const char*)GET_PTR(ctx->r5);

    printf("[CD] CdSearchFile '%s'\n", name);

    CdFile found;
    if (KFCD_FindFile(name, &found)) {
        // CdlFILE structure:
        // 0-3:  CdlLOC pos (MSF + mode)
        // 4-7:  size
        // 8-23: name

        // Конвертируем LBA в MSF
        int lba = found.lba + 150; // +150 для lead-in
        int m = lba / (75 * 60);
        int s = (lba % (75 * 60)) / 75;
        int f = lba % 75;

        fp[0] = (uint8_t)((m / 10) * 16 + (m % 10)); // BCD minutes
        fp[1] = (uint8_t)((s / 10) * 16 + (s % 10)); // BCD seconds
        fp[2] = (uint8_t)((f / 10) * 16 + (f % 10)); // BCD frames
        fp[3] = 0x02; // mode 2

        *(uint32_t*)(fp + 4) = found.size;
        strncpy((char*)(fp + 8), name, 16);

        printf("[CD] Found: LBA=%d size=%d MSF=%02X:%02X:%02X\n",
            found.lba, found.size, fp[0], fp[1], fp[2]);
        ctx->r2 = ctx->r4; // возвращаем указатель на fp (успех)
    }
    else {
        printf("[CD] File not found: '%s'\n", name);
        ctx->r2 = 0; // NULL = не найден
    }


//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lw          $v1, 0xCF4($v1)
//    ctx->r3 = MEM_W(0XCF4, ctx->r3);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x9F0($v0)
//    ctx->r2 = MEM_W(0X9F0, ctx->r2);
//    // addiu       $sp, $sp, -0x50
//    ctx->r29 = ADD32(ctx->r29, -0X50);
//    // sw          $s6, 0x48($sp)
//    MEM_W(0X48, ctx->r29) = ctx->r22;
//    // addu        $s6, $a0, $zero
//    ctx->r22 = ADD32(ctx->r4, 0);
//    // sw          $s3, 0x3C($sp)
//    MEM_W(0X3C, ctx->r29) = ctx->r19;
//    // addu        $s3, $a1, $zero
//    ctx->r19 = ADD32(ctx->r5, 0);
//    // sw          $ra, 0x4C($sp)
//    MEM_W(0X4C, ctx->r29) = ctx->r31;
//    // sw          $s5, 0x44($sp)
//    MEM_W(0X44, ctx->r29) = ctx->r21;
//    // sw          $s4, 0x40($sp)
//    MEM_W(0X40, ctx->r29) = ctx->r20;
//    // sw          $s2, 0x38($sp)
//    MEM_W(0X38, ctx->r29) = ctx->r18;
//    // sw          $s1, 0x34($sp)
//    MEM_W(0X34, ctx->r29) = ctx->r17;
//    // beq         $v1, $v0, L_8006AA84
//    if (ctx->r3 == ctx->r2) {
//        // sw          $s0, 0x30($sp)
//        MEM_W(0X30, ctx->r29) = ctx->r16;
//        goto L_8006AA84;
//    }
//    // sw          $s0, 0x30($sp)
//    MEM_W(0X30, ctx->r29) = ctx->r16;
//    // jal         0x8006AD1C
//    // nop
//
//    CdCheckISO9660(rdram, ctx);
//    goto after_0;
//    // nop
//
//    after_0:
//    // beq         $v0, $zero, L_8006ACD4
//    if (ctx->r2 == 0) {
//        // addu        $v0, $zero, $zero
//        ctx->r2 = ADD32(0, 0);
//        goto L_8006ACD4;
//    }
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x9F0($v0)
//    ctx->r2 = MEM_W(0X9F0, ctx->r2);
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // sw          $v0, 0xCF4($at)
//    MEM_W(0XCF4, ctx->r1) = ctx->r2;
//L_8006AA84:
//    // lb          $v1, 0x0($s3)
//    ctx->r3 = MEM_BS(0X0, ctx->r19);
//    // addiu       $v0, $zero, 0x5C
//    ctx->r2 = ADD32(0, 0X5C);
//    // beq         $v1, $v0, L_8006AAA4
//    if (ctx->r3 == ctx->r2) {
//        // addu        $v0, $zero, $zero
//        ctx->r2 = ADD32(0, 0);
//        goto L_8006AAA4;
//    }
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    // j           L_8006ACD4
//    // nop
//
//    goto L_8006ACD4;
//    // nop
//
//L_8006AA9C:
//    // j           L_8006AB2C
//    // sb          $zero, 0x10($sp)
//    MEM_B(0X10, ctx->r29) = 0;
//    goto L_8006AB2C;
//    // sb          $zero, 0x10($sp)
//    MEM_B(0X10, ctx->r29) = 0;
//L_8006AAA4:
//    // sb          $zero, 0x10($sp)
//    MEM_B(0X10, ctx->r29) = 0;
//    // addiu       $a0, $zero, 0x1
//    ctx->r4 = ADD32(0, 0X1);
//    // addu        $s0, $s3, $zero
//    ctx->r16 = ADD32(ctx->r19, 0);
//    // addu        $s2, $zero, $zero
//    ctx->r18 = ADD32(0, 0);
//    // addiu       $s5, $zero, 0x5C
//    ctx->r21 = ADD32(0, 0X5C);
//    // addiu       $s4, $zero, -0x1
//    ctx->r20 = ADD32(0, -0X1);
//L_8006AABC:
//    // lb          $v0, 0x0($s0)
//    ctx->r2 = MEM_BS(0X0, ctx->r16);
//    // lbu         $v1, 0x0($s0)
//    ctx->r3 = MEM_BU(0X0, ctx->r16);
//    // beq         $v0, $s5, L_8006AAF8
//    if (ctx->r2 == ctx->r21) {
//        // addiu       $s1, $sp, 0x10
//        ctx->r17 = ADD32(ctx->r29, 0X10);
//        goto L_8006AAF8;
//    }
//    // addiu       $s1, $sp, 0x10
//    ctx->r17 = ADD32(ctx->r29, 0X10);
//    // addiu       $a1, $zero, 0x5C
//    ctx->r5 = ADD32(0, 0X5C);
//L_8006AAD0:
//    // beq         $v1, $zero, L_8006AB30
//    if (ctx->r3 == 0) {
//        // slti        $v0, $s2, 0x8
//        ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
//        goto L_8006AB30;
//    }
//    // slti        $v0, $s2, 0x8
//    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
//    // addiu       $s0, $s0, 0x1
//    ctx->r16 = ADD32(ctx->r16, 0X1);
//    // sb          $v1, 0x0($s1)
//    MEM_B(0X0, ctx->r17) = ctx->r3;
//    // lb          $v0, 0x0($s0)
//    ctx->r2 = MEM_BS(0X0, ctx->r16);
//    // lbu         $v1, 0x0($s0)
//    ctx->r3 = MEM_BU(0X0, ctx->r16);
//    // bne         $v0, $a1, L_8006AAD0
//    if (ctx->r2 != ctx->r5) {
//        // addiu       $s1, $s1, 0x1
//        ctx->r17 = ADD32(ctx->r17, 0X1);
//        goto L_8006AAD0;
//    }
//    // addiu       $s1, $s1, 0x1
//    ctx->r17 = ADD32(ctx->r17, 0X1);
//    // lb          $v0, 0x0($s0)
//    ctx->r2 = MEM_BS(0X0, ctx->r16);
//    // nop
//
//L_8006AAF8:
//    // beq         $v0, $zero, L_8006AB30
//    if (ctx->r2 == 0) {
//        // slti        $v0, $s2, 0x8
//        ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
//        goto L_8006AB30;
//    }
//    // slti        $v0, $s2, 0x8
//    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
//    // addiu       $s0, $s0, 0x1
//    ctx->r16 = ADD32(ctx->r16, 0X1);
//    // sb          $zero, 0x0($s1)
//    MEM_B(0X0, ctx->r17) = 0;
//    // jal         0x8006AFE0
//    // addiu       $a1, $sp, 0x10
//    ctx->r5 = ADD32(ctx->r29, 0X10);
//    sub_8006AFE0(rdram, ctx);
//    goto after_1;
//    // addiu       $a1, $sp, 0x10
//    ctx->r5 = ADD32(ctx->r29, 0X10);
//    after_1:
//    // addu        $a0, $v0, $zero
//    ctx->r4 = ADD32(ctx->r2, 0);
//    // beq         $a0, $s4, L_8006AA9C
//    if (ctx->r4 == ctx->r20) {
//        // nop
//    
//        goto L_8006AA9C;
//    }
//    // nop
//
//    // addiu       $s2, $s2, 0x1
//    ctx->r18 = ADD32(ctx->r18, 0X1);
//    // slti        $v0, $s2, 0x8
//    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
//    // bne         $v0, $zero, L_8006AABC
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_8006AABC;
//    }
//    // nop
//
//L_8006AB2C:
//    // slti        $v0, $s2, 0x8
//    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
//L_8006AB30:
//    // bne         $v0, $zero, L_8006AB64
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_8006AB64;
//    }
//    // nop
//
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x9E4($v0)
//    ctx->r2 = MEM_W(0X9E4, ctx->r2);
//    // nop
//
//    // blez        $v0, L_8006ACD0
//    if (SIGNED(ctx->r2) <= 0) {
//        // addu        $a1, $s3, $zero
//        ctx->r5 = ADD32(ctx->r19, 0);
//        goto L_8006ACD0;
//    }
//    // addu        $a1, $s3, $zero
//    ctx->r5 = ADD32(ctx->r19, 0);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x3C10
//    ctx->r4 = ADD32(ctx->r4, 0X3C10);
//    // jal         0x80078AD4
//    // addu        $a2, $s2, $zero
//    ctx->r6 = ADD32(ctx->r18, 0);
//    printf(rdram, ctx);
//    goto after_2;
//    // addu        $a2, $s2, $zero
//    ctx->r6 = ADD32(ctx->r18, 0);
//    after_2:
//    // j           L_8006ACD4
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    goto L_8006ACD4;
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//L_8006AB64:
//    // lb          $v0, 0x10($sp)
//    ctx->r2 = MEM_BS(0X10, ctx->r29);
//    // nop
//
//    // bne         $v0, $zero, L_8006AB94
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_8006AB94;
//    }
//    // nop
//
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x9E4($v0)
//    ctx->r2 = MEM_W(0X9E4, ctx->r2);
//    // nop
//
//    // blez        $v0, L_8006ACD0
//    if (SIGNED(ctx->r2) <= 0) {
//        // addu        $a1, $s3, $zero
//        ctx->r5 = ADD32(ctx->r19, 0);
//        goto L_8006ACD0;
//    }
//    // addu        $a1, $s3, $zero
//    ctx->r5 = ADD32(ctx->r19, 0);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // j           L_8006ACC8
//    // addiu       $a0, $a0, 0x3C2C
//    ctx->r4 = ADD32(ctx->r4, 0X3C2C);
//    goto L_8006ACC8;
//    // addiu       $a0, $a0, 0x3C2C
//    ctx->r4 = ADD32(ctx->r4, 0X3C2C);
//L_8006AB94:
//    // jal         0x8006B084
//    // sb          $zero, 0x0($s1)
//    MEM_B(0X0, ctx->r17) = 0;
//    sub_8006B084(rdram, ctx);
//    goto after_3;
//    // sb          $zero, 0x0($s1)
//    MEM_B(0X0, ctx->r17) = 0;
//    after_3:
//    // bne         $v0, $zero, L_8006ABCC
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_8006ABCC;
//    }
//    // nop
//
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x9E4($v0)
//    ctx->r2 = MEM_W(0X9E4, ctx->r2);
//    // nop
//
//    // blez        $v0, L_8006ACD4
//    if (SIGNED(ctx->r2) <= 0) {
//        // addu        $v0, $zero, $zero
//        ctx->r2 = ADD32(0, 0);
//        goto L_8006ACD4;
//    }
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // jal         0x80078AD4
//    // addiu       $a0, $a0, 0x3C44
//    ctx->r4 = ADD32(ctx->r4, 0X3C44);
//    printf(rdram, ctx);
//    goto after_4;
//    // addiu       $a0, $a0, 0x3C44
//    ctx->r4 = ADD32(ctx->r4, 0X3C44);
//    after_4:
//    // j           L_8006ACD4
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    goto L_8006ACD4;
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//L_8006ABCC:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x9E4($v0)
//    ctx->r2 = MEM_W(0X9E4, ctx->r2);
//    // nop
//
//    // slti        $v0, $v0, 0x2
//    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
//    // bne         $v0, $zero, L_8006ABF8
//    if (ctx->r2 != 0) {
//        // addu        $s2, $zero, $zero
//        ctx->r18 = ADD32(0, 0);
//        goto L_8006ABF8;
//    }
//    // addu        $s2, $zero, $zero
//    ctx->r18 = ADD32(0, 0);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x3C60
//    ctx->r4 = ADD32(ctx->r4, 0X3C60);
//    // jal         0x80078AD4
//    // addiu       $a1, $sp, 0x10
//    ctx->r5 = ADD32(ctx->r29, 0X10);
//    printf(rdram, ctx);
//    goto after_5;
//    // addiu       $a1, $sp, 0x10
//    ctx->r5 = ADD32(ctx->r29, 0X10);
//    after_5:
//    // addu        $s2, $zero, $zero
//    ctx->r18 = ADD32(0, 0);
//L_8006ABF8:
//    // lui         $v0, 0x801E
//    ctx->r2 = S32(0X801E << 16);
//    // addiu       $v0, $v0, 0x61B0
//    ctx->r2 = ADD32(ctx->r2, 0X61B0);
//    // addiu       $s0, $v0, -0x8
//    ctx->r16 = ADD32(ctx->r2, -0X8);
//    // addu        $s3, $v0, $zero
//    ctx->r19 = ADD32(ctx->r2, 0);
//    // addu        $s1, $zero, $zero
//    ctx->r17 = ADD32(0, 0);
//L_8006AC0C:
//    // lui         $v0, 0x801E
//    ctx->r2 = S32(0X801E << 16);
//    // addu        $v0, $v0, $s1
//    ctx->r2 = ADD32(ctx->r2, ctx->r17);
//    // lb          $v0, 0x61B0($v0)
//    ctx->r2 = MEM_BS(0X61B0, ctx->r2);
//    // nop
//
//    // beq         $v0, $zero, L_8006ACAC
//    if (ctx->r2 == 0) {
//        // addu        $a0, $s3, $zero
//        ctx->r4 = ADD32(ctx->r19, 0);
//        goto L_8006ACAC;
//    }
//    // addu        $a0, $s3, $zero
//    ctx->r4 = ADD32(ctx->r19, 0);
//    // jal         0x8006ACFC
//    // addiu       $a1, $sp, 0x10
//    ctx->r5 = ADD32(ctx->r29, 0X10);
//    sub_8006ACFC(rdram, ctx);
//    goto after_6;
//    // addiu       $a1, $sp, 0x10
//    ctx->r5 = ADD32(ctx->r29, 0X10);
//    after_6:
//    // beq         $v0, $zero, L_8006AC94
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8006AC94;
//    }
//    // nop
//
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x9E4($v0)
//    ctx->r2 = MEM_W(0X9E4, ctx->r2);
//    // nop
//
//    // slti        $v0, $v0, 0x2
//    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
//    // bne         $v0, $zero, L_8006AC5C
//    if (ctx->r2 != 0) {
//        // nop
//    
//        goto L_8006AC5C;
//    }
//    // nop
//
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x3C80
//    ctx->r4 = ADD32(ctx->r4, 0X3C80);
//    // jal         0x80078AD4
//    // addiu       $a1, $sp, 0x10
//    ctx->r5 = ADD32(ctx->r29, 0X10);
//    printf(rdram, ctx);
//    goto after_7;
//    // addiu       $a1, $sp, 0x10
//    ctx->r5 = ADD32(ctx->r29, 0X10);
//    after_7:
//L_8006AC5C:
//    // lw          $v0, 0x0($s0)
//    ctx->r2 = MEM_W(0X0, ctx->r16);
//    // lw          $v1, 0x4($s0)
//    ctx->r3 = MEM_W(0X4, ctx->r16);
//    // lw          $a0, 0x8($s0)
//    ctx->r4 = MEM_W(0X8, ctx->r16);
//    // lw          $a1, 0xC($s0)
//    ctx->r5 = MEM_W(0XC, ctx->r16);
//    // sw          $v0, 0x0($s6)
//    MEM_W(0X0, ctx->r22) = ctx->r2;
//    // sw          $v1, 0x4($s6)
//    MEM_W(0X4, ctx->r22) = ctx->r3;
//    // sw          $a0, 0x8($s6)
//    MEM_W(0X8, ctx->r22) = ctx->r4;
//    // sw          $a1, 0xC($s6)
//    MEM_W(0XC, ctx->r22) = ctx->r5;
//    // lw          $v0, 0x10($s0)
//    ctx->r2 = MEM_W(0X10, ctx->r16);
//    // lw          $v1, 0x14($s0)
//    ctx->r3 = MEM_W(0X14, ctx->r16);
//    // sw          $v0, 0x10($s6)
//    MEM_W(0X10, ctx->r22) = ctx->r2;
//    // sw          $v1, 0x14($s6)
//    MEM_W(0X14, ctx->r22) = ctx->r3;
//    // j           L_8006ACD4
//    // addu        $v0, $s0, $zero
//    ctx->r2 = ADD32(ctx->r16, 0);
//    goto L_8006ACD4;
//    // addu        $v0, $s0, $zero
//    ctx->r2 = ADD32(ctx->r16, 0);
//L_8006AC94:
//    // addiu       $s0, $s0, 0x18
//    ctx->r16 = ADD32(ctx->r16, 0X18);
//    // addiu       $s3, $s3, 0x18
//    ctx->r19 = ADD32(ctx->r19, 0X18);
//    // addiu       $s2, $s2, 0x1
//    ctx->r18 = ADD32(ctx->r18, 0X1);
//    // slti        $v0, $s2, 0x40
//    ctx->r2 = SIGNED(ctx->r18) < 0X40 ? 1 : 0;
//    // bne         $v0, $zero, L_8006AC0C
//    if (ctx->r2 != 0) {
//        // addiu       $s1, $s1, 0x18
//        ctx->r17 = ADD32(ctx->r17, 0X18);
//        goto L_8006AC0C;
//    }
//    // addiu       $s1, $s1, 0x18
//    ctx->r17 = ADD32(ctx->r17, 0X18);
//L_8006ACAC:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x9E4($v0)
//    ctx->r2 = MEM_W(0X9E4, ctx->r2);
//    // nop
//
//    // blez        $v0, L_8006ACD0
//    if (SIGNED(ctx->r2) <= 0) {
//        // addiu       $a1, $sp, 0x10
//        ctx->r5 = ADD32(ctx->r29, 0X10);
//        goto L_8006ACD0;
//    }
//    // addiu       $a1, $sp, 0x10
//    ctx->r5 = ADD32(ctx->r29, 0X10);
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x3C8C
//    ctx->r4 = ADD32(ctx->r4, 0X3C8C);
//L_8006ACC8:
//    // jal         0x80078AD4
//    // nop
//
//    printf(rdram, ctx);
//    goto after_8;
//    // nop
//
//    after_8:
//L_8006ACD0:
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//L_8006ACD4:
//    // lw          $ra, 0x4C($sp)
//    ctx->r31 = MEM_W(0X4C, ctx->r29);
//    // lw          $s6, 0x48($sp)
//    ctx->r22 = MEM_W(0X48, ctx->r29);
//    // lw          $s5, 0x44($sp)
//    ctx->r21 = MEM_W(0X44, ctx->r29);
//    // lw          $s4, 0x40($sp)
//    ctx->r20 = MEM_W(0X40, ctx->r29);
//    // lw          $s3, 0x3C($sp)
//    ctx->r19 = MEM_W(0X3C, ctx->r29);
//    // lw          $s2, 0x38($sp)
//    ctx->r18 = MEM_W(0X38, ctx->r29);
//    // lw          $s1, 0x34($sp)
//    ctx->r17 = MEM_W(0X34, ctx->r29);
//    // lw          $s0, 0x30($sp)
//    ctx->r16 = MEM_W(0X30, ctx->r29);
//    // jr          $ra
//    // addiu       $sp, $sp, 0x50
//    ctx->r29 = ADD32(ctx->r29, 0X50);
//    return;
//    // addiu       $sp, $sp, 0x50
//    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
