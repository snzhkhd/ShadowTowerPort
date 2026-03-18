#include "recomp.h"
#include "disable_warnings.h"

void sub_800159D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // lui         $v0, 0xE904
    ctx->r2 = S32(0XE904 << 16);
    // ori         $v0, $v0, 0x52D5
    ctx->r2 = ctx->r2 | 0X52D5;
    // multu       $s1, $v0
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // mfhi        $a2
    ctx->r6 = hi;
    // srl         $s0, $a2, 12
    ctx->r16 = S32(U32(ctx->r6) >> 12);
    // jal         0x80015914
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    sub_80015914(rdram, ctx);
    goto after_0;
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // lui         $a1, 0x1B4E
    ctx->r5 = S32(0X1B4E << 16);
    // ori         $a1, $a1, 0x81B5
    ctx->r5 = ctx->r5 | 0X81B5;
    // sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16) << 2;
    // addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3) << 4;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4) << 4;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // multu       $s1, $a1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // mfhi        $a2
    ctx->r6 = hi;
    // srl         $s0, $a2, 3
    ctx->r16 = S32(U32(ctx->r6) >> 3);
    // jal         0x80015914
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    sub_80015914(rdram, ctx);
    goto after_1;
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_1:
    // sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16) << 2;
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4) << 4;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // sb          $v0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r2;
    // jal         0x80015914
    // nop

    sub_80015914(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // sb          $zero, 0x3($s2)
    MEM_B(0X3, ctx->r18) = 0;
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
