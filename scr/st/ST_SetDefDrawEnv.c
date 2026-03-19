#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void ST_SetDefDrawEnv(uint8_t* rdram, recomp_context* ctx) 
{
    DRAWENV* env = (DRAWENV*)GET_PTR(ctx->r4);
    int x = (int)ctx->r5;
    int y = (int)ctx->r6;
    int w = (int)ctx->r7;
    // Читаем 5-й аргумент со стека
    int h = (int)MEM_W(16, ctx->r29);

    if (env) {
        printf("[HLE GPU] SetDefDrawEnv(env=0x%08X, x=%d, y=%d, w=%d, h=%d)\n", ctx->r4, x, y, w, h);
        SetDefDrawEnv(env, x, y, w, h);

    }
    ctx->r2 = ctx->r4;
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x28
//    ctx->r29 = ADD32(ctx->r29, -0X28);
//    // sw          $s2, 0x18($sp)
//    MEM_W(0X18, ctx->r29) = ctx->r18;
//    // lw          $s2, 0x38($sp)
//    ctx->r18 = MEM_W(0X38, ctx->r29);
//    // sw          $s1, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r17;
//    // addu        $s1, $a0, $zero
//    ctx->r17 = ADD32(ctx->r4, 0);
//    // sw          $s3, 0x1C($sp)
//    MEM_W(0X1C, ctx->r29) = ctx->r19;
//    // addu        $s3, $a1, $zero
//    ctx->r19 = ADD32(ctx->r5, 0);
//    // sw          $s4, 0x20($sp)
//    MEM_W(0X20, ctx->r29) = ctx->r20;
//    // addu        $s4, $a2, $zero
//    ctx->r20 = ADD32(ctx->r6, 0);
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // sw          $ra, 0x24($sp)
//    MEM_W(0X24, ctx->r29) = ctx->r31;
//    // jal         0x80077DA8
//    // addu        $s0, $a3, $zero
//    ctx->r16 = ADD32(ctx->r7, 0);
//    GetVideoMode(rdram, ctx);
//    goto after_0;
//    // addu        $s0, $a3, $zero
//    ctx->r16 = ADD32(ctx->r7, 0);
//    after_0:
//    // addiu       $v1, $zero, 0x1
//    ctx->r3 = ADD32(0, 0X1);
//    // sh          $s3, 0x0($s1)
//    MEM_H(0X0, ctx->r17) = ctx->r19;
//    // sh          $s4, 0x2($s1)
//    MEM_H(0X2, ctx->r17) = ctx->r20;
//    // sh          $s0, 0x4($s1)
//    MEM_H(0X4, ctx->r17) = ctx->r16;
//    // sh          $zero, 0xC($s1)
//    MEM_H(0XC, ctx->r17) = 0;
//    // sh          $zero, 0xE($s1)
//    MEM_H(0XE, ctx->r17) = 0;
//    // sh          $zero, 0x10($s1)
//    MEM_H(0X10, ctx->r17) = 0;
//    // sh          $zero, 0x12($s1)
//    MEM_H(0X12, ctx->r17) = 0;
//    // sb          $zero, 0x19($s1)
//    MEM_B(0X19, ctx->r17) = 0;
//    // sb          $zero, 0x1A($s1)
//    MEM_B(0X1A, ctx->r17) = 0;
//    // sb          $zero, 0x1B($s1)
//    MEM_B(0X1B, ctx->r17) = 0;
//    // sb          $v1, 0x16($s1)
//    MEM_B(0X16, ctx->r17) = ctx->r3;
//    // beq         $v0, $zero, L_80079668
//    if (ctx->r2 == 0) {
//        // sh          $s2, 0x6($s1)
//        MEM_H(0X6, ctx->r17) = ctx->r18;
//        goto L_80079668;
//    }
//    // sh          $s2, 0x6($s1)
//    MEM_H(0X6, ctx->r17) = ctx->r18;
//    // j           L_8007966C
//    // slti        $v0, $s2, 0x121
//    ctx->r2 = SIGNED(ctx->r18) < 0X121 ? 1 : 0;
//    goto L_8007966C;
//    // slti        $v0, $s2, 0x121
//    ctx->r2 = SIGNED(ctx->r18) < 0X121 ? 1 : 0;
//L_80079668:
//    // slti        $v0, $s2, 0x101
//    ctx->r2 = SIGNED(ctx->r18) < 0X101 ? 1 : 0;
//L_8007966C:
//    // sb          $v0, 0x17($s1)
//    MEM_B(0X17, ctx->r17) = ctx->r2;
//    // addu        $v0, $s1, $zero
//    ctx->r2 = ADD32(ctx->r17, 0);
//    // addiu       $v1, $zero, 0xA
//    ctx->r3 = ADD32(0, 0XA);
//    // sh          $s3, 0x8($v0)
//    MEM_H(0X8, ctx->r2) = ctx->r19;
//    // sh          $s4, 0xA($v0)
//    MEM_H(0XA, ctx->r2) = ctx->r20;
//    // sh          $v1, 0x14($v0)
//    MEM_H(0X14, ctx->r2) = ctx->r3;
//    // sb          $zero, 0x18($v0)
//    MEM_B(0X18, ctx->r2) = 0;
//    // lw          $ra, 0x24($sp)
//    ctx->r31 = MEM_W(0X24, ctx->r29);
//    // lw          $s4, 0x20($sp)
//    ctx->r20 = MEM_W(0X20, ctx->r29);
//    // lw          $s3, 0x1C($sp)
//    ctx->r19 = MEM_W(0X1C, ctx->r29);
//    // lw          $s2, 0x18($sp)
//    ctx->r18 = MEM_W(0X18, ctx->r29);
//    // lw          $s1, 0x14($sp)
//    ctx->r17 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // jr          $ra
//    // addiu       $sp, $sp, 0x28
//    ctx->r29 = ADD32(ctx->r29, 0X28);
//    return;
//    // addiu       $sp, $sp, 0x28
//    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
