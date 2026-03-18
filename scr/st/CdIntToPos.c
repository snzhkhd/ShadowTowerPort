#include "recomp.h"
#include "disable_warnings.h"

void CdIntToPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x1B4E
    ctx->r3 = S32(0X1B4E << 16);
    // ori         $v1, $v1, 0x81B5
    ctx->r3 = ctx->r3 | 0X81B5;
    // addiu       $a0, $a0, 0x96
    ctx->r4 = ADD32(ctx->r4, 0X96);
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // lui         $a1, 0x8888
    ctx->r5 = S32(0X8888 << 16);
    // ori         $a1, $a1, 0x8889
    ctx->r5 = ctx->r5 | 0X8889;
    // mfhi        $v1
    ctx->r3 = hi;
    // sra         $a3, $v1, 3
    ctx->r7 = S32(ctx->r3) >> 3;
    // sra         $v1, $a0, 31
    ctx->r3 = S32(ctx->r4) >> 31;
    // subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // mult        $a3, $a1
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $t1, 0x6666
    ctx->r9 = S32(0X6666 << 16);
    // ori         $t1, $t1, 0x6667
    ctx->r9 = ctx->r9 | 0X6667;
    // sll         $a1, $a3, 2
    ctx->r5 = S32(ctx->r7) << 2;
    // addu        $a1, $a1, $a3
    ctx->r5 = ADD32(ctx->r5, ctx->r7);
    // sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5) << 4;
    // mfhi        $a2
    ctx->r6 = hi;
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // mult        $a0, $t1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $a3, 31
    ctx->r3 = S32(ctx->r7) >> 31;
    // addu        $t0, $a2, $a3
    ctx->r8 = ADD32(ctx->r6, ctx->r7);
    // sra         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8) >> 5;
    // subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // sll         $v1, $t0, 4
    ctx->r3 = S32(ctx->r8) << 4;
    // subu        $v1, $v1, $t0
    ctx->r3 = SUB32(ctx->r3, ctx->r8);
    // mfhi        $a1
    ctx->r5 = hi;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // mult        $a3, $t1
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $a0, 31
    ctx->r3 = S32(ctx->r4) >> 31;
    // sra         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) >> 2;
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // sll         $a2, $a1, 4
    ctx->r6 = S32(ctx->r5) << 4;
    // sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5) << 2;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // mfhi        $t3
    ctx->r11 = hi;
    // addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // sra         $v1, $a3, 31
    ctx->r3 = S32(ctx->r7) >> 31;
    // mult        $t0, $t1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sb          $a2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r6;
    // sra         $a0, $t3, 2
    ctx->r4 = S32(ctx->r11) >> 2;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // sll         $a1, $a0, 4
    ctx->r5 = S32(ctx->r4) << 4;
    // sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // addu        $a1, $a1, $a3
    ctx->r5 = ADD32(ctx->r5, ctx->r7);
    // sra         $v1, $t0, 31
    ctx->r3 = S32(ctx->r8) >> 31;
    // sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $a0, $t1, 2
    ctx->r4 = S32(ctx->r9) >> 2;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // sll         $a1, $a0, 4
    ctx->r5 = S32(ctx->r4) << 4;
    // sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // jr          $ra
    // sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    return;
    // sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
;}
