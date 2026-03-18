#include "recomp.h"
#include "disable_warnings.h"

void sub_8003DBE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // addu        $s5, $s6, $zero
    ctx->r21 = ADD32(ctx->r22, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // addiu       $s3, $v0, -0x7000
    ctx->r19 = ADD32(ctx->r2, -0X7000);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // jal         0x80078AB4
    // sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    memset_recomp(rdram, ctx);
    goto after_0;
    // sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_0:
    // andi        $v1, $s7, 0xFFFF
    ctx->r3 = ctx->r23 & 0XFFFF;
    // beq         $v1, $zero, L_8003E340
    if (ctx->r3 == 0) {
        // addiu       $s4, $sp, 0x10
        ctx->r20 = ADD32(ctx->r29, 0X10);
        goto L_8003E340;
    }
    // addiu       $s4, $sp, 0x10
    ctx->r20 = ADD32(ctx->r29, 0X10);
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // beq         $v1, $v0, L_8003DCE4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003DCE4;
    }
    // nop

    // slti        $v0, $v1, 0x21
    ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // beq         $v0, $zero, L_8003DCA4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_8003DCA4;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // beq         $v1, $v0, L_8003DCE4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003DCE4;
    }
    // nop

    // slti        $v0, $v1, 0x9
    ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // beq         $v0, $zero, L_8003DC84
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
        goto L_8003DC84;
    }
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // beq         $v1, $v0, L_8003DD60
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
        goto L_8003DD60;
    }
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // j           L_8003DE24
    // nop

    goto L_8003DE24;
    // nop

L_8003DC84:
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // beq         $v1, $v0, L_8003DCE4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003DCE4;
    }
    // nop

    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // beq         $v1, $v0, L_8003DCE4
    if (ctx->r3 == ctx->r2) {
        // andi        $v1, $s7, 0xFFFF
        ctx->r3 = ctx->r23 & 0XFFFF;
        goto L_8003DCE4;
    }
    // andi        $v1, $s7, 0xFFFF
    ctx->r3 = ctx->r23 & 0XFFFF;
    // j           L_8003DE24
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    goto L_8003DE24;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_8003DCA4:
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // beq         $v1, $v0, L_8003DCE4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003DCE4;
    }
    // nop

    // slti        $v0, $v1, 0x61
    ctx->r2 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
    // beq         $v0, $zero, L_8003DCCC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x40
        ctx->r2 = ADD32(0, 0X40);
        goto L_8003DCCC;
    }
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // beq         $v1, $v0, L_8003DCE4
    if (ctx->r3 == ctx->r2) {
        // andi        $v1, $s7, 0xFFFF
        ctx->r3 = ctx->r23 & 0XFFFF;
        goto L_8003DCE4;
    }
    // andi        $v1, $s7, 0xFFFF
    ctx->r3 = ctx->r23 & 0XFFFF;
    // j           L_8003DE24
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    goto L_8003DE24;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_8003DCCC:
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // beq         $v1, $v0, L_8003DCE4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003DCE4;
    }
    // nop

    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // bne         $v1, $v0, L_8003DE20
    if (ctx->r3 != ctx->r2) {
        // andi        $v1, $s7, 0xFFFF
        ctx->r3 = ctx->r23 & 0XFFFF;
        goto L_8003DE20;
    }
    // andi        $v1, $s7, 0xFFFF
    ctx->r3 = ctx->r23 & 0XFFFF;
L_8003DCE4:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lhu         $a0, 0xB6($v1)
    ctx->r4 = MEM_HU(0XB6, ctx->r3);
    // lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a0, 0x6666
    ctx->r4 = S32(0X6666 << 16);
    // ori         $a0, $a0, 0x6667
    ctx->r4 = ctx->r4 | 0X6667;
    // lh          $v0, 0x7C($v1)
    ctx->r2 = MEM_HS(0X7C, ctx->r3);
    // mfhi        $a3
    ctx->r7 = hi;
    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // mult        $a1, $a0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0xE2($v1)
    ctx->r2 = MEM_HU(0XE2, ctx->r3);
    // nop

    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // mfhi        $a2
    ctx->r6 = hi;
    // lui         $a0, 0x8080
    ctx->r4 = S32(0X8080 << 16);
    // ori         $a0, $a0, 0x8081
    ctx->r4 = ctx->r4 | 0X8081;
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a1, $a1, 31
    ctx->r5 = S32(ctx->r5) >> 31;
    // srl         $a0, $a3, 4
    ctx->r4 = S32(U32(ctx->r7) >> 4);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sra         $v0, $a2, 5
    ctx->r2 = S32(ctx->r6) >> 5;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // mfhi        $t0
    ctx->r8 = hi;
    // j           L_8003DDD0
    // addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    goto L_8003DDD0;
    // addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
L_8003DD60:
    // addiu       $a0, $s3, -0xD8
    ctx->r4 = ADD32(ctx->r19, -0XD8);
    // lhu         $v1, 0xB6($a0)
    ctx->r3 = MEM_HU(0XB6, ctx->r4);
    // lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // lh          $v0, 0x7A($a0)
    ctx->r2 = MEM_HS(0X7A, ctx->r4);
    // mfhi        $t0
    ctx->r8 = hi;
    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a2, 0x8080
    ctx->r6 = S32(0X8080 << 16);
    // lhu         $v0, 0xDC($a0)
    ctx->r2 = MEM_HU(0XDC, ctx->r4);
    // ori         $a2, $a2, 0x8081
    ctx->r6 = ctx->r6 | 0X8081;
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // mfhi        $a3
    ctx->r7 = hi;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // mult        $v1, $a2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // srl         $a0, $t0, 4
    ctx->r4 = S32(U32(ctx->r8) >> 4);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sra         $a1, $a1, 31
    ctx->r5 = S32(ctx->r5) >> 31;
    // sra         $v0, $a3, 5
    ctx->r2 = S32(ctx->r7) >> 5;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // mfhi        $t1
    ctx->r9 = hi;
    // addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
L_8003DDD0:
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addiu       $v0, $zero, 0x65
    ctx->r2 = ADD32(0, 0X65);
    // jal         0x80078AC4
    // subu        $s0, $v0, $a0
    ctx->r16 = SUB32(ctx->r2, ctx->r4);
    rand_recomp(rdram, ctx);
    goto after_1;
    // subu        $s0, $v0, $a0
    ctx->r16 = SUB32(ctx->r2, ctx->r4);
    after_1:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // bgez        $v0, L_8003DE0C
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003DE0C;
    }
    // nop

    // addiu       $v0, $v0, 0x7FFF
    ctx->r2 = ADD32(ctx->r2, 0X7FFF);
L_8003DE0C:
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8003E1AC
    if (ctx->r2 != 0) {
        // lui         $a0, 0x22B6
        ctx->r4 = S32(0X22B6 << 16);
        goto L_8003E1AC;
    }
    // lui         $a0, 0x22B6
    ctx->r4 = S32(0X22B6 << 16);
    // andi        $v1, $s7, 0xFFFF
    ctx->r3 = ctx->r23 & 0XFFFF;
L_8003DE20:
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_8003DE24:
    // beq         $v1, $v0, L_8003DFBC
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x21
        ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
        goto L_8003DFBC;
    }
    // slti        $v0, $v1, 0x21
    ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // beq         $v0, $zero, L_8003DE9C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
        goto L_8003DE9C;
    }
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // beq         $v1, $v0, L_8003E09C
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x8
        ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
        goto L_8003E09C;
    }
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_8003DE68
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
        goto L_8003DE68;
    }
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // beq         $v1, $zero, L_8003E1A8
    if (ctx->r3 == 0) {
        // slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
        goto L_8003E1A8;
    }
    // slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8003E0A0
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003E0A0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_8003E09C
    if (ctx->r3 == ctx->r2) {
        // lui         $a0, 0x22B6
        ctx->r4 = S32(0X22B6 << 16);
        goto L_8003E09C;
    }
    // lui         $a0, 0x22B6
    ctx->r4 = S32(0X22B6 << 16);
    // j           L_8003E1B0
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
    goto L_8003E1B0;
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
L_8003DE68:
    // beq         $v1, $v0, L_8003DF60
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x11
        ctx->r2 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
        goto L_8003DF60;
    }
    // slti        $v0, $v1, 0x11
    ctx->r2 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
    // beq         $v0, $zero, L_8003DE88
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_8003DE88;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // beq         $v1, $v0, L_8003DF60
    if (ctx->r3 == ctx->r2) {
        // lui         $a0, 0x22B6
        ctx->r4 = S32(0X22B6 << 16);
        goto L_8003DF60;
    }
    // lui         $a0, 0x22B6
    ctx->r4 = S32(0X22B6 << 16);
    // j           L_8003E1B0
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
    goto L_8003E1B0;
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
L_8003DE88:
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // beq         $v1, $v0, L_8003DF60
    if (ctx->r3 == ctx->r2) {
        // lui         $a0, 0x22B6
        ctx->r4 = S32(0X22B6 << 16);
        goto L_8003DF60;
    }
    // lui         $a0, 0x22B6
    ctx->r4 = S32(0X22B6 << 16);
    // j           L_8003E1B0
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
    goto L_8003E1B0;
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
L_8003DE9C:
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // beq         $v1, $v0, L_8003E034
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x101
        ctx->r2 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
        goto L_8003E034;
    }
    // slti        $v0, $v1, 0x101
    ctx->r2 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
    // beq         $v0, $zero, L_8003DEE4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x60
        ctx->r2 = ADD32(0, 0X60);
        goto L_8003DEE4;
    }
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // beq         $v1, $v0, L_8003DFBC
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x61
        ctx->r2 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
        goto L_8003DFBC;
    }
    // slti        $v0, $v1, 0x61
    ctx->r2 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
    // beq         $v0, $zero, L_8003DED0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x40
        ctx->r2 = ADD32(0, 0X40);
        goto L_8003DED0;
    }
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // beq         $v1, $v0, L_8003DFBC
    if (ctx->r3 == ctx->r2) {
        // lui         $a0, 0x22B6
        ctx->r4 = S32(0X22B6 << 16);
        goto L_8003DFBC;
    }
    // lui         $a0, 0x22B6
    ctx->r4 = S32(0X22B6 << 16);
    // j           L_8003E1B0
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
    goto L_8003E1B0;
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
L_8003DED0:
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // beq         $v1, $v0, L_8003DF1C
    if (ctx->r3 == ctx->r2) {
        // lui         $a0, 0x22B6
        ctx->r4 = S32(0X22B6 << 16);
        goto L_8003DF1C;
    }
    // lui         $a0, 0x22B6
    ctx->r4 = S32(0X22B6 << 16);
    // j           L_8003E1B0
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
    goto L_8003E1B0;
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
L_8003DEE4:
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // beq         $v1, $v0, L_8003E130
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x401
        ctx->r2 = SIGNED(ctx->r3) < 0X401 ? 1 : 0;
        goto L_8003E130;
    }
    // slti        $v0, $v1, 0x401
    ctx->r2 = SIGNED(ctx->r3) < 0X401 ? 1 : 0;
    // beq         $v0, $zero, L_8003DF08
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x200
        ctx->r2 = ADD32(0, 0X200);
        goto L_8003DF08;
    }
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // beq         $v1, $v0, L_8003E000
    if (ctx->r3 == ctx->r2) {
        // lui         $a0, 0x22B6
        ctx->r4 = S32(0X22B6 << 16);
        goto L_8003E000;
    }
    // lui         $a0, 0x22B6
    ctx->r4 = S32(0X22B6 << 16);
    // j           L_8003E1B0
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
    goto L_8003E1B0;
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
L_8003DF08:
    // addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // beq         $v1, $v0, L_8003E194
    if (ctx->r3 == ctx->r2) {
        // lui         $a0, 0x22B6
        ctx->r4 = S32(0X22B6 << 16);
        goto L_8003E194;
    }
    // lui         $a0, 0x22B6
    ctx->r4 = S32(0X22B6 << 16);
    // j           L_8003E1B0
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
    goto L_8003E1B0;
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
L_8003DF1C:
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // addiu       $s0, $s2, -0x70D8
    ctx->r16 = ADD32(ctx->r18, -0X70D8);
    // lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(0X2C, ctx->r16);
    // nop

    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // bne         $v0, $zero, L_8003DF50
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
        goto L_8003DF50;
    }
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    // sh          $v0, 0x19E($s0)
    MEM_H(0X19E, ctx->r16) = ctx->r2;
    // ori         $v0, $v1, 0x80
    ctx->r2 = ctx->r3 | 0X80;
    // j           L_8003E064
    // sh          $zero, 0x19C($s0)
    MEM_H(0X19C, ctx->r16) = 0;
    goto L_8003E064;
    // sh          $zero, 0x19C($s0)
    MEM_H(0X19C, ctx->r16) = 0;
L_8003DF50:
    // sh          $v0, 0x19C($s0)
    MEM_H(0X19C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    // j           L_8003E1A8
    // sh          $v0, 0x19E($s0)
    MEM_H(0X19E, ctx->r16) = ctx->r2;
    goto L_8003E1A8;
    // sh          $v0, 0x19E($s0)
    MEM_H(0X19E, ctx->r16) = ctx->r2;
L_8003DF60:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(0X2C, ctx->r4);
    // nop

    // andi        $v0, $v1, 0x18
    ctx->r2 = ctx->r3 & 0X18;
    // bne         $v0, $zero, L_8003DF88
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x4B
        ctx->r2 = ADD32(0, 0X4B);
        goto L_8003DF88;
    }
    // addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    // sh          $v0, 0x196($a0)
    MEM_H(0X196, ctx->r4) = ctx->r2;
    // j           L_8003DF9C
    // ori         $v0, $v1, 0x8
    ctx->r2 = ctx->r3 | 0X8;
    goto L_8003DF9C;
    // ori         $v0, $v1, 0x8
    ctx->r2 = ctx->r3 | 0X8;
L_8003DF88:
    // andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // beq         $v0, $zero, L_8003DFA8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x4B
        ctx->r2 = ADD32(0, 0X4B);
        goto L_8003DFA8;
    }
    // addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    // sh          $v0, 0x196($a0)
    MEM_H(0X196, ctx->r4) = ctx->r2;
    // ori         $v0, $v1, 0x10
    ctx->r2 = ctx->r3 | 0X10;
L_8003DF9C:
    // sh          $zero, 0x194($a0)
    MEM_H(0X194, ctx->r4) = 0;
    // j           L_8003E1A8
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    goto L_8003E1A8;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_8003DFA8:
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sh          $v0, 0x194($a0)
    MEM_H(0X194, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    // j           L_8003E1A8
    // sh          $v0, 0x196($a0)
    MEM_H(0X196, ctx->r4) = ctx->r2;
    goto L_8003E1A8;
    // sh          $v0, 0x196($a0)
    MEM_H(0X196, ctx->r4) = ctx->r2;
L_8003DFBC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(0X2C, ctx->r3);
    // nop

    // andi        $v0, $a0, 0x60
    ctx->r2 = ctx->r4 & 0X60;
    // bne         $v0, $zero, L_8003DFF0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
        goto L_8003DFF0;
    }
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
    // sh          $v0, 0x19A($v1)
    MEM_H(0X19A, ctx->r3) = ctx->r2;
    // ori         $v0, $a0, 0x60
    ctx->r2 = ctx->r4 | 0X60;
    // sh          $zero, 0x198($v1)
    MEM_H(0X198, ctx->r3) = 0;
    // j           L_8003E1A8
    // sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    goto L_8003E1A8;
    // sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
L_8003DFF0:
    // sh          $v0, 0x198($v1)
    MEM_H(0X198, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
    // j           L_8003E1A8
    // sh          $v0, 0x19A($v1)
    MEM_H(0X19A, ctx->r3) = ctx->r2;
    goto L_8003E1A8;
    // sh          $v0, 0x19A($v1)
    MEM_H(0X19A, ctx->r3) = ctx->r2;
L_8003E000:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // bgez        $v0, L_8003E014
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003E014;
    }
    // nop

    // addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
L_8003E014:
    // sra         $a0, $v0, 8
    ctx->r4 = S32(ctx->r2) >> 8;
    // jal         0x8003CF28
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    sub_8003CF28(rdram, ctx);
    goto after_3;
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    after_3:
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // jal         0x800582F0
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    sub_800582F0(rdram, ctx);
    goto after_4;
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_4:
    // j           L_8003E1AC
    // lui         $a0, 0x22B6
    ctx->r4 = S32(0X22B6 << 16);
    goto L_8003E1AC;
    // lui         $a0, 0x22B6
    ctx->r4 = S32(0X22B6 << 16);
L_8003E034:
    // lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // addiu       $s0, $s2, -0x70D8
    ctx->r16 = ADD32(ctx->r18, -0X70D8);
    // lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(0X2C, ctx->r16);
    // nop

    // andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // bne         $v0, $zero, L_8003E08C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
        goto L_8003E08C;
    }
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x1770
    ctx->r2 = ADD32(0, 0X1770);
    // sh          $v0, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r2;
    // ori         $v0, $v1, 0x100
    ctx->r2 = ctx->r3 | 0X100;
    // sh          $zero, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = 0;
L_8003E064:
    // jal         0x8005A3A8
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    sub_8005A3A8(rdram, ctx);
    goto after_5;
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    after_5:
    // lhu         $v1, -0x70D8($s2)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r18);
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8003E1AC
    if (ctx->r2 == 0) {
        // lui         $a0, 0x22B6
        ctx->r4 = S32(0X22B6 << 16);
        goto L_8003E1AC;
    }
    // lui         $a0, 0x22B6
    ctx->r4 = S32(0X22B6 << 16);
    // j           L_8003E1AC
    // sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
    goto L_8003E1AC;
    // sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
L_8003E08C:
    // sh          $v0, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1770
    ctx->r2 = ADD32(0, 0X1770);
    // j           L_8003E1A8
    // sh          $v0, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r2;
    goto L_8003E1A8;
    // sh          $v0, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r2;
L_8003E09C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8003E0A0:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(0X2C, ctx->r4);
    // lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // bne         $v0, $zero, L_8003E1A8
    if (ctx->r2 != 0) {
        // andi        $v0, $v1, 0x7
        ctx->r2 = ctx->r3 & 0X7;
        goto L_8003E1A8;
    }
    // andi        $v0, $v1, 0x7
    ctx->r2 = ctx->r3 & 0X7;
    // beq         $v0, $zero, L_8003E11C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x258
        ctx->r2 = ADD32(0, 0X258);
        goto L_8003E11C;
    }
    // addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
    // lh          $v0, 0x190($a0)
    ctx->r2 = MEM_HS(0X190, ctx->r4);
    // nop

    // slti        $v0, $v0, 0xDC
    ctx->r2 = SIGNED(ctx->r2) < 0XDC ? 1 : 0;
    // bne         $v0, $zero, L_8003E1A8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003E1A8;
    }
    // nop

    // lh          $v0, 0x192($a0)
    ctx->r2 = MEM_HS(0X192, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8003E1A8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
        goto L_8003E1A8;
    }
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sh          $v0, 0x190($a0)
    MEM_H(0X190, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
    // sh          $v0, 0x192($a0)
    MEM_H(0X192, ctx->r4) = ctx->r2;
    // andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // beq         $v0, $zero, L_8003E100
    if (ctx->r2 == 0) {
        // ori         $v0, $v1, 0x4
        ctx->r2 = ctx->r3 | 0X4;
        goto L_8003E100;
    }
    // ori         $v0, $v1, 0x4
    ctx->r2 = ctx->r3 | 0X4;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_8003E100:
    // lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(0X2C, ctx->r4);
    // nop

    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // beq         $v0, $zero, L_8003E1A8
    if (ctx->r2 == 0) {
        // ori         $v0, $v1, 0x2
        ctx->r2 = ctx->r3 | 0X2;
        goto L_8003E1A8;
    }
    // ori         $v0, $v1, 0x2
    ctx->r2 = ctx->r3 | 0X2;
    // j           L_8003E1A8
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    goto L_8003E1A8;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_8003E11C:
    // sh          $v0, 0x192($a0)
    MEM_H(0X192, ctx->r4) = ctx->r2;
    // ori         $v0, $v1, 0x1
    ctx->r2 = ctx->r3 | 0X1;
    // sh          $zero, 0x190($a0)
    MEM_H(0X190, ctx->r4) = 0;
    // j           L_8003E1A8
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    goto L_8003E1A8;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_8003E130:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x23C($s0)
    ctx->r4 = MEM_W(0X23C, ctx->r16);
    // lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(0X2C, ctx->r16);
    // nop

    // ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // mfhi        $t5
    ctx->r13 = hi;
    // srl         $v1, $t5, 5
    ctx->r3 = S32(U32(ctx->r13) >> 5);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // bne         $a0, $v0, L_8003E184
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $zero, 0xDAC
        ctx->r2 = ADD32(0, 0XDAC);
        goto L_8003E184;
    }
    // addiu       $v0, $zero, 0xDAC
    ctx->r2 = ADD32(0, 0XDAC);
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // jal         0x800582F0
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    sub_800582F0(rdram, ctx);
    goto after_6;
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_6:
    // addiu       $v0, $zero, 0xDAC
    ctx->r2 = ADD32(0, 0XDAC);
L_8003E184:
    // sh          $v0, 0x2DA($s0)
    MEM_H(0X2DA, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // j           L_8003E1A8
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    goto L_8003E1A8;
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
L_8003E194:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $zero, 0x189($v0)
    MEM_B(0X189, ctx->r2) = 0;
    // sb          $v1, 0x14F($v0)
    MEM_B(0X14F, ctx->r2) = ctx->r3;
L_8003E1A8:
    // lui         $a0, 0x22B6
    ctx->r4 = S32(0X22B6 << 16);
L_8003E1AC:
    // ori         $a0, $a0, 0x3CBF
    ctx->r4 = ctx->r4 | 0X3CBF;
L_8003E1B0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $t2, $v0, -0x70D8
    ctx->r10 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x20($t2)
    ctx->r2 = MEM_HU(0X20, ctx->r10);
    // addiu       $v1, $zero, 0x70
    ctx->r3 = ADD32(0, 0X70);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $v1
    ctx->r3 = hi;
    // sra         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) >> 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // addiu       $v1, $v1, 0x32
    ctx->r3 = ADD32(ctx->r3, 0X32);
    // mult        $v1, $a2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // nop

    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t0
    ctx->r8 = lo;
    // lui         $a3, 0x51EB
    ctx->r7 = S32(0X51EB << 16);
    // ori         $a3, $a3, 0x851F
    ctx->r7 = ctx->r7 | 0X851F;
    // mult        $a0, $a3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v0
    ctx->r2 = hi;
    // nop

    // nop

    // mult        $t0, $a3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t3
    ctx->r11 = hi;
    // addiu       $t1, $zero, 0x258
    ctx->r9 = ADD32(0, 0X258);
    // nop

    // mult        $v1, $t1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // sra         $a1, $v0, 5
    ctx->r5 = S32(ctx->r2) >> 5;
    // mflo        $v1
    ctx->r3 = lo;
    // lbu         $v0, 0x1C8($t2)
    ctx->r2 = MEM_BU(0X1C8, ctx->r10);
    // subu        $a2, $a1, $a0
    ctx->r6 = SUB32(ctx->r5, ctx->r4);
    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // nop

    // nop

    // mult        $v1, $a3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t1
    ctx->r9 = hi;
    // nop

    // nop

    // mult        $a2, $a3
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $t0, $t0, 31
    ctx->r8 = S32(ctx->r8) >> 31;
    // mfhi        $t4
    ctx->r12 = hi;
    // sra         $a0, $t3, 5
    ctx->r4 = S32(ctx->r11) >> 5;
    // subu        $a1, $a0, $t0
    ctx->r5 = SUB32(ctx->r4, ctx->r8);
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mflo        $a1
    ctx->r5 = lo;
    // sra         $a0, $t1, 5
    ctx->r4 = S32(ctx->r9) >> 5;
    // subu        $t1, $a0, $v1
    ctx->r9 = SUB32(ctx->r4, ctx->r3);
    // mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $a1, $a3
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t0
    ctx->r8 = hi;
    // nop

    // nop

    // mult        $v0, $a3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a2, $a2, 31
    ctx->r6 = S32(ctx->r6) >> 31;
    // sra         $v1, $t4, 5
    ctx->r3 = S32(ctx->r12) >> 5;
    // subu        $a2, $v1, $a2
    ctx->r6 = SUB32(ctx->r3, ctx->r6);
    // sra         $a1, $a1, 31
    ctx->r5 = S32(ctx->r5) >> 31;
    // sra         $v1, $t0, 5
    ctx->r3 = S32(ctx->r8) >> 5;
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $a0
    ctx->r4 = hi;
    // sra         $v1, $a0, 5
    ctx->r3 = S32(ctx->r4) >> 5;
    // subu        $t1, $v1, $v0
    ctx->r9 = SUB32(ctx->r3, ctx->r2);
    // lh          $v0, 0x19E($t2)
    ctx->r2 = MEM_HS(0X19E, ctx->r10);
    // nop

    // slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003E2F8
    if (ctx->r2 == 0) {
        // addu        $v1, $t1, $zero
        ctx->r3 = ADD32(ctx->r9, 0);
        goto L_8003E2F8;
    }
    // addu        $v1, $t1, $zero
    ctx->r3 = ADD32(ctx->r9, 0);
    // sh          $a2, 0x19E($t2)
    MEM_H(0X19E, ctx->r10) = ctx->r6;
L_8003E2F8:
    // lh          $v0, 0x196($t2)
    ctx->r2 = MEM_HS(0X196, ctx->r10);
    // nop

    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003E310
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003E310;
    }
    // nop

    // sh          $a1, 0x196($t2)
    MEM_H(0X196, ctx->r10) = ctx->r5;
L_8003E310:
    // lh          $v0, 0x19A($t2)
    ctx->r2 = MEM_HS(0X19A, ctx->r10);
    // nop

    // slt         $v0, $t1, $v0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003E328
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003E328;
    }
    // nop

    // sh          $t1, 0x19A($t2)
    MEM_H(0X19A, ctx->r10) = ctx->r9;
L_8003E328:
    // lh          $v0, 0x192($t2)
    ctx->r2 = MEM_HS(0X192, ctx->r10);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003E344
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003E344;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sh          $v1, 0x192($t2)
    MEM_H(0X192, ctx->r10) = ctx->r3;
L_8003E340:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8003E344:
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v0, 0x189($a2)
    ctx->r2 = MEM_BU(0X189, ctx->r6);
    // nop

    // beq         $v0, $zero, L_8003E3D0
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_8003E3D0;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lhu         $v1, 0x58($a2)
    ctx->r3 = MEM_HU(0X58, ctx->r6);
    // nop

    // beq         $v1, $v0, L_8003E3D4
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003E3D4;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $a0, 0x12($a2)
    ctx->r4 = MEM_HU(0X12, ctx->r6);
    // lhu         $v0, 0x16($a2)
    ctx->r2 = MEM_HU(0X16, ctx->r6);
    // nop

    // addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x7810
    ctx->r3 = ADD32(ctx->r3, 0X7810);
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // lhu         $a0, 0x14($a2)
    ctx->r4 = MEM_HU(0X14, ctx->r6);
    // lhu         $v1, 0x18($a2)
    ctx->r3 = MEM_HU(0X18, ctx->r6);
    // lbu         $v0, 0x22($a1)
    ctx->r2 = MEM_BU(0X22, ctx->r5);
    // nop

    // sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // bne         $v0, $zero, L_8003E3E0
    if (ctx->r2 != 0) {
        // addu        $t2, $a0, $v1
        ctx->r10 = ADD32(ctx->r4, ctx->r3);
        goto L_8003E3E0;
    }
    // addu        $t2, $a0, $v1
    ctx->r10 = ADD32(ctx->r4, ctx->r3);
    // lbu         $v0, 0x23($a1)
    ctx->r2 = MEM_BU(0X23, ctx->r5);
    // lbu         $v1, 0x22($a1)
    ctx->r3 = MEM_BU(0X22, ctx->r5);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $sp, $v1
    ctx->r3 = ADD32(ctx->r29, ctx->r3);
    // j           L_8003E3E0
    // sh          $v0, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r2;
    goto L_8003E3E0;
    // sh          $v0, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r2;
L_8003E3D0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8003E3D4:
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lhu         $t0, 0x12($v0)
    ctx->r8 = MEM_HU(0X12, ctx->r2);
    // lhu         $t2, 0x14($v0)
    ctx->r10 = MEM_HU(0X14, ctx->r2);
L_8003E3E0:
    // andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
    // beq         $a0, $zero, L_8003E3F0
    if (ctx->r4 == 0) {
        // addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
        goto L_8003E3F0;
    }
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
L_8003E3F0:
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $t0, $zero, 0x28A
    ctx->r8 = ADD32(0, 0X28A);
L_8003E3F8:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8003E464
    if (ctx->r2 == 0) {
        // addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
        goto L_8003E464;
    }
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // subu        $v0, $t0, $a1
    ctx->r2 = SUB32(ctx->r8, ctx->r5);
    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v0, $a1, 7
    ctx->r2 = S32(ctx->r5) << 7;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8003E440
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8003E440;
    }
    // nop

    // break       7
    do_break(2147738684);
L_8003E440:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8003E458
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003E458;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003E458
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003E458;
    }
    // nop

    // break       6
    do_break(2147738708);
L_8003E458:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // addu        $s6, $s6, $v0
    ctx->r22 = ADD32(ctx->r22, ctx->r2);
L_8003E464:
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slti        $v0, $a2, 0x3
    ctx->r2 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8003E3F8
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
        goto L_8003E3F8;
    }
    // addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $t0, $v0, -0x70D8
    ctx->r8 = ADD32(ctx->r2, -0X70D8);
    // addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // andi        $a0, $t2, 0xFFFF
    ctx->r4 = ctx->r10 & 0XFFFF;
L_8003E488:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8003E57C
    if (ctx->r2 == 0) {
        // addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
        goto L_8003E57C;
    }
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(0X2C, ctx->r8);
    // lui         $v1, 0x8
    ctx->r3 = S32(0X8 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8003E4B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003E4B8;
    }
    // nop

    // bne         $a2, $zero, L_8003E4B8
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8003E4B8;
    }
    // nop

    // sra         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) >> 2;
L_8003E4B8:
    // lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(0X2C, ctx->r8);
    // lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8003E4D8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8003E4D8;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $a2, $v0, L_8003E4D8
    if (ctx->r6 != ctx->r2) {
        // nop
    
        goto L_8003E4D8;
    }
    // nop

    // sra         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) >> 2;
L_8003E4D8:
    // lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(0X2C, ctx->r8);
    // lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8003E4F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003E4F4;
    }
    // nop

    // beq         $a2, $t1, L_8003E57C
    if (ctx->r6 == ctx->r9) {
        // nop
    
        goto L_8003E57C;
    }
    // nop

L_8003E4F4:
    // lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(0X0, ctx->r19);
    // lhu         $v1, 0x0($s4)
    ctx->r3 = MEM_HU(0X0, ctx->r20);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // bne         $a3, $zero, L_8003E510
    if (ctx->r7 != 0) {
        // addiu       $v0, $zero, 0x28A
        ctx->r2 = ADD32(0, 0X28A);
        goto L_8003E510;
    }
    // addiu       $v0, $zero, 0x28A
    ctx->r2 = ADD32(0, 0X28A);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8003E510:
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v0, $a1, 7
    ctx->r2 = S32(ctx->r5) << 7;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8003E548
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8003E548;
    }
    // nop

    // break       7
    do_break(2147738948);
L_8003E548:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8003E560
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003E560;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003E560
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003E560;
    }
    // nop

    // break       6
    do_break(2147738972);
L_8003E560:
    // mflo        $v1
    ctx->r3 = lo;
    // beq         $a2, $t1, L_8003E578
    if (ctx->r6 == ctx->r9) {
        // nop
    
        goto L_8003E578;
    }
    // nop

    // bne         $v1, $zero, L_8003E578
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8003E578;
    }
    // nop

    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8003E578:
    // addu        $s5, $s5, $v1
    ctx->r21 = ADD32(ctx->r21, ctx->r3);
L_8003E57C:
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // slti        $v0, $a2, 0x6
    ctx->r2 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_8003E488
    if (ctx->r2 != 0) {
        // addiu       $s4, $s4, 0x2
        ctx->r20 = ADD32(ctx->r20, 0X2);
        goto L_8003E488;
    }
    // addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // addu        $v1, $s6, $s5
    ctx->r3 = ADD32(ctx->r22, ctx->r21);
    // andi        $v0, $fp, 0xFFFF
    ctx->r2 = ctx->r30 & 0XFFFF;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // andi        $a1, $s7, 0xFFFF
    ctx->r5 = ctx->r23 & 0XFFFF;
    // lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(0X54, ctx->r29);
    // mflo        $t5
    ctx->r13 = lo;
    // jal         0x8003D788
    // sra         $a0, $t5, 12
    ctx->r4 = S32(ctx->r13) >> 12;
    sub_8003D788(rdram, ctx);
    goto after_7;
    // sra         $a0, $t5, 12
    ctx->r4 = S32(ctx->r13) >> 12;
    after_7:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(0X40, ctx->r29);
    // lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(0X3C, ctx->r29);
    // lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
