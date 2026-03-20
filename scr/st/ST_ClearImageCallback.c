#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h"
#include "psx/libgpu.h"


void ST_ClearImageCallback(uint8_t* rdram, recomp_context* ctx) 
{
    uint32_t rect_addr = ctx->r4;
    uint32_t color = ctx->r5;

    //  
    uint8_t r = color & 0xFF;
    uint8_t g = (color >> 8) & 0xFF;
    uint8_t b = (color >> 16) & 0xFF;

    //     RECT   
    RECT16* rect = (RECT16*)GET_PTR(rect_addr);

    if (rect) {
        /*printf("[HLE GPU] ClearImage(x=%d, y=%d, w=%d, h=%d, R=%d, G=%d, B=%d)\n",
            rect->x, rect->y, rect->w, rect->h, r, g, b);*/

            //      Psy-X (OpenGL)
        ClearImage(rect, r, g, b);
    }
    ctx->r2 = 0;

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x20
//    ctx->r29 = ADD32(ctx->r29, -0X20);
//    // addu        $t0, $a0, $zero
//    ctx->r8 = ADD32(ctx->r4, 0);
//    // sw          $ra, 0x1C($sp)
//    MEM_W(0X1C, ctx->r29) = ctx->r31;
//    // sw          $s2, 0x18($sp)
//    MEM_W(0X18, ctx->r29) = ctx->r18;
//    // sw          $s1, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r17;
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // lh          $v1, 0x4($t0)
//    ctx->r3 = MEM_HS(0X4, ctx->r8);
//    // lhu         $a0, 0x4($t0)
//    ctx->r4 = MEM_HU(0X4, ctx->r8);
//    // bltz        $v1, L_8007B128
//    if (SIGNED(ctx->r3) < 0) {
//        // addu        $t1, $a1, $zero
//        ctx->r9 = ADD32(ctx->r5, 0);
//        goto L_8007B128;
//    }
//    // addu        $t1, $a1, $zero
//    ctx->r9 = ADD32(ctx->r5, 0);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lh          $v0, 0x7CC4($v0)
//    ctx->r2 = MEM_HS(0X7CC4, ctx->r2);
//    // nop
//
//    // addiu       $v0, $v0, -0x1
//    ctx->r2 = ADD32(ctx->r2, -0X1);
//    // slt         $v0, $v0, $v1
//    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lhu         $v1, 0x7CC4($v1)
//    ctx->r3 = MEM_HU(0X7CC4, ctx->r3);
//    // bne         $v0, $zero, L_8007B12C
//    if (ctx->r2 != 0) {
//        // addiu       $v0, $v1, -0x1
//        ctx->r2 = ADD32(ctx->r3, -0X1);
//        goto L_8007B12C;
//    }
//    // addiu       $v0, $v1, -0x1
//    ctx->r2 = ADD32(ctx->r3, -0X1);
//    // j           L_8007B12C
//    // addu        $v0, $a0, $zero
//    ctx->r2 = ADD32(ctx->r4, 0);
//    goto L_8007B12C;
//    // addu        $v0, $a0, $zero
//    ctx->r2 = ADD32(ctx->r4, 0);
//L_8007B128:
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//L_8007B12C:
//    // lh          $v1, 0x6($t0)
//    ctx->r3 = MEM_HS(0X6, ctx->r8);
//    // lhu         $a0, 0x6($t0)
//    ctx->r4 = MEM_HU(0X6, ctx->r8);
//    // bltz        $v1, L_8007B168
//    if (SIGNED(ctx->r3) < 0) {
//        // sh          $v0, 0x4($t0)
//        MEM_H(0X4, ctx->r8) = ctx->r2;
//        goto L_8007B168;
//    }
//    // sh          $v0, 0x4($t0)
//    MEM_H(0X4, ctx->r8) = ctx->r2;
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lh          $v0, 0x7CC6($v0)
//    ctx->r2 = MEM_HS(0X7CC6, ctx->r2);
//    // nop
//
//    // addiu       $v0, $v0, -0x1
//    ctx->r2 = ADD32(ctx->r2, -0X1);
//    // slt         $v0, $v0, $v1
//    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lhu         $v1, 0x7CC6($v1)
//    ctx->r3 = MEM_HU(0X7CC6, ctx->r3);
//    // bne         $v0, $zero, L_8007B16C
//    if (ctx->r2 != 0) {
//        // addiu       $v1, $v1, -0x1
//        ctx->r3 = ADD32(ctx->r3, -0X1);
//        goto L_8007B16C;
//    }
//    // addiu       $v1, $v1, -0x1
//    ctx->r3 = ADD32(ctx->r3, -0X1);
//    // j           L_8007B16C
//    // addu        $v1, $a0, $zero
//    ctx->r3 = ADD32(ctx->r4, 0);
//    goto L_8007B16C;
//    // addu        $v1, $a0, $zero
//    ctx->r3 = ADD32(ctx->r4, 0);
//L_8007B168:
//    // addu        $v1, $zero, $zero
//    ctx->r3 = ADD32(0, 0);
//L_8007B16C:
//    // lhu         $v0, 0x0($t0)
//    ctx->r2 = MEM_HU(0X0, ctx->r8);
//    // nop
//
//    // andi        $v0, $v0, 0x3F
//    ctx->r2 = ctx->r2 & 0X3F;
//    // bne         $v0, $zero, L_8007B194
//    if (ctx->r2 != 0) {
//        // sh          $v1, 0x6($t0)
//        MEM_H(0X6, ctx->r8) = ctx->r3;
//        goto L_8007B194;
//    }
//    // sh          $v1, 0x6($t0)
//    MEM_H(0X6, ctx->r8) = ctx->r3;
//    // lhu         $v0, 0x4($t0)
//    ctx->r2 = MEM_HU(0X4, ctx->r8);
//    // nop
//
//    // andi        $v0, $v0, 0x3F
//    ctx->r2 = ctx->r2 & 0X3F;
//    // beq         $v0, $zero, L_8007B26C
//    if (ctx->r2 == 0) {
//        // lui         $v0, 0x5FF
//        ctx->r2 = S32(0X5FF << 16);
//        goto L_8007B26C;
//    }
//    // lui         $v0, 0x5FF
//    ctx->r2 = S32(0X5FF << 16);
//L_8007B194:
//    // lui         $a2, 0xFF
//    ctx->r6 = S32(0XFF << 16);
//    // ori         $a2, $a2, 0xFFFF
//    ctx->r6 = ctx->r6 | 0XFFFF;
//    // lui         $a0, 0xE4FF
//    ctx->r4 = S32(0XE4FF << 16);
//    // ori         $a0, $a0, 0xFFFF
//    ctx->r4 = ctx->r4 | 0XFFFF;
//    // lui         $a3, 0x3FF
//    ctx->r7 = S32(0X3FF << 16);
//    // lui         $a1, 0x801F
//    ctx->r5 = S32(0X801F << 16);
//    // addiu       $a1, $a1, -0x6698
//    ctx->r5 = ADD32(ctx->r5, -0X6698);
//    // lui         $s0, 0x801F
//    ctx->r16 = S32(0X801F << 16);
//    // addiu       $s0, $s0, -0x6670
//    ctx->r16 = ADD32(ctx->r16, -0X6670);
//    // and         $v0, $s0, $a2
//    ctx->r2 = ctx->r16 & ctx->r6;
//    // lui         $v1, 0x800
//    ctx->r3 = S32(0X800 << 16);
//    // or          $v0, $v0, $v1
//    ctx->r2 = ctx->r2 | ctx->r3;
//    // lui         $s1, 0xE300
//    ctx->r17 = S32(0XE300 << 16);
//    // lui         $s2, 0xE500
//    ctx->r18 = S32(0XE500 << 16);
//    // sw          $v0, 0x0($a1)
//    MEM_W(0X0, ctx->r5) = ctx->r2;
//    // lui         $v0, 0xE600
//    ctx->r2 = S32(0XE600 << 16);
//    // and         $a2, $t1, $a2
//    ctx->r6 = ctx->r9 & ctx->r6;
//    // lui         $v1, 0x6000
//    ctx->r3 = S32(0X6000 << 16);
//    // or          $a2, $a2, $v1
//    ctx->r6 = ctx->r6 | ctx->r3;
//    // sw          $v0, 0x10($a1)
//    MEM_W(0X10, ctx->r5) = ctx->r2;
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7DC8($v0)
//    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
//    // lui         $v1, 0xE100
//    ctx->r3 = S32(0XE100 << 16);
//    // sw          $s1, 0x4($a1)
//    MEM_W(0X4, ctx->r5) = ctx->r17;
//    // sw          $a0, 0x8($a1)
//    MEM_W(0X8, ctx->r5) = ctx->r4;
//    // sw          $s2, 0xC($a1)
//    MEM_W(0XC, ctx->r5) = ctx->r18;
//    // lw          $a0, 0x0($v0)
//    ctx->r4 = MEM_W(0X0, ctx->r2);
//    // srl         $v0, $t1, 31
//    ctx->r2 = S32(U32(ctx->r9) >> 31);
//    // sll         $v0, $v0, 10
//    ctx->r2 = S32(ctx->r2) << 10;
//    // or          $v0, $v0, $v1
//    ctx->r2 = ctx->r2 | ctx->r3;
//    // sw          $a2, 0x18($a1)
//    MEM_W(0X18, ctx->r5) = ctx->r6;
//    // andi        $a0, $a0, 0x7FF
//    ctx->r4 = ctx->r4 & 0X7FF;
//    // or          $a0, $a0, $v0
//    ctx->r4 = ctx->r4 | ctx->r2;
//    // sw          $a0, 0x14($a1)
//    MEM_W(0X14, ctx->r5) = ctx->r4;
//    // lw          $v0, 0x0($t0)
//    ctx->r2 = MEM_W(0X0, ctx->r8);
//    // ori         $a3, $a3, 0xFFFF
//    ctx->r7 = ctx->r7 | 0XFFFF;
//    // sw          $v0, 0x1C($a1)
//    MEM_W(0X1C, ctx->r5) = ctx->r2;
//    // lw          $v0, 0x4($t0)
//    ctx->r2 = MEM_W(0X4, ctx->r8);
//    // addiu       $a0, $zero, 0x3
//    ctx->r4 = ADD32(0, 0X3);
//    // sw          $a3, 0x0($s0)
//    MEM_W(0X0, ctx->r16) = ctx->r7;
//    // jal         0x8007B880
//    // sw          $v0, 0x20($a1)
//    MEM_W(0X20, ctx->r5) = ctx->r2;
//    sub_8007B880(rdram, ctx);
//    goto after_0;
//    // sw          $v0, 0x20($a1)
//    MEM_W(0X20, ctx->r5) = ctx->r2;
//    after_0:
//    // addiu       $a0, $zero, 0x4
//    ctx->r4 = ADD32(0, 0X4);
//    // or          $v0, $v0, $s1
//    ctx->r2 = ctx->r2 | ctx->r17;
//    // jal         0x8007B880
//    // sw          $v0, 0x4($s0)
//    MEM_W(0X4, ctx->r16) = ctx->r2;
//    sub_8007B880(rdram, ctx);
//    goto after_1;
//    // sw          $v0, 0x4($s0)
//    MEM_W(0X4, ctx->r16) = ctx->r2;
//    after_1:
//    // addiu       $a0, $zero, 0x5
//    ctx->r4 = ADD32(0, 0X5);
//    // lui         $v1, 0xE400
//    ctx->r3 = S32(0XE400 << 16);
//    // or          $v0, $v0, $v1
//    ctx->r2 = ctx->r2 | ctx->r3;
//    // jal         0x8007B880
//    // sw          $v0, 0x8($s0)
//    MEM_W(0X8, ctx->r16) = ctx->r2;
//    sub_8007B880(rdram, ctx);
//    goto after_2;
//    // sw          $v0, 0x8($s0)
//    MEM_W(0X8, ctx->r16) = ctx->r2;
//    after_2:
//    // or          $v0, $v0, $s2
//    ctx->r2 = ctx->r2 | ctx->r18;
//    // j           L_8007B2DC
//    // sw          $v0, 0xC($s0)
//    MEM_W(0XC, ctx->r16) = ctx->r2;
//    goto L_8007B2DC;
//    // sw          $v0, 0xC($s0)
//    MEM_W(0XC, ctx->r16) = ctx->r2;
//L_8007B26C:
//    // ori         $v0, $v0, 0xFFFF
//    ctx->r2 = ctx->r2 | 0XFFFF;
//    // lui         $v1, 0xFF
//    ctx->r3 = S32(0XFF << 16);
//    // ori         $v1, $v1, 0xFFFF
//    ctx->r3 = ctx->r3 | 0XFFFF;
//    // lui         $a2, 0x801F
//    ctx->r6 = S32(0X801F << 16);
//    // addiu       $a2, $a2, -0x6698
//    ctx->r6 = ADD32(ctx->r6, -0X6698);
//    // sw          $v0, 0x0($a2)
//    MEM_W(0X0, ctx->r6) = ctx->r2;
//    // lui         $v0, 0xE600
//    ctx->r2 = S32(0XE600 << 16);
//    // and         $v1, $t1, $v1
//    ctx->r3 = ctx->r9 & ctx->r3;
//    // lui         $a1, 0x200
//    ctx->r5 = S32(0X200 << 16);
//    // sw          $v0, 0x4($a2)
//    MEM_W(0X4, ctx->r6) = ctx->r2;
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7DC8($v0)
//    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
//    // or          $v1, $v1, $a1
//    ctx->r3 = ctx->r3 | ctx->r5;
//    // lw          $a0, 0x0($v0)
//    ctx->r4 = MEM_W(0X0, ctx->r2);
//    // srl         $v0, $t1, 31
//    ctx->r2 = S32(U32(ctx->r9) >> 31);
//    // sll         $v0, $v0, 10
//    ctx->r2 = S32(ctx->r2) << 10;
//    // sw          $v1, 0xC($a2)
//    MEM_W(0XC, ctx->r6) = ctx->r3;
//    // lui         $v1, 0xE100
//    ctx->r3 = S32(0XE100 << 16);
//    // or          $v0, $v0, $v1
//    ctx->r2 = ctx->r2 | ctx->r3;
//    // andi        $a0, $a0, 0x7FF
//    ctx->r4 = ctx->r4 & 0X7FF;
//    // or          $a0, $a0, $v0
//    ctx->r4 = ctx->r4 | ctx->r2;
//    // sw          $a0, 0x8($a2)
//    MEM_W(0X8, ctx->r6) = ctx->r4;
//    // lw          $v0, 0x0($t0)
//    ctx->r2 = MEM_W(0X0, ctx->r8);
//    // nop
//
//    // sw          $v0, 0x10($a2)
//    MEM_W(0X10, ctx->r6) = ctx->r2;
//    // lw          $v0, 0x4($t0)
//    ctx->r2 = MEM_W(0X4, ctx->r8);
//    // nop
//
//    // sw          $v0, 0x14($a2)
//    MEM_W(0X14, ctx->r6) = ctx->r2;
//L_8007B2DC:
//    // lui         $a0, 0x801F
//    ctx->r4 = S32(0X801F << 16);
//    // jal         0x8007B838
//    // addiu       $a0, $a0, -0x6698
//    ctx->r4 = ADD32(ctx->r4, -0X6698);
//    TriggerGpuDma(rdram, ctx);
//    goto after_3;
//    // addiu       $a0, $a0, -0x6698
//    ctx->r4 = ADD32(ctx->r4, -0X6698);
//    after_3:
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//    // lw          $ra, 0x1C($sp)
//    ctx->r31 = MEM_W(0X1C, ctx->r29);
//    // lw          $s2, 0x18($sp)
//    ctx->r18 = MEM_W(0X18, ctx->r29);
//    // lw          $s1, 0x14($sp)
//    ctx->r17 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // jr          $ra
//    // addiu       $sp, $sp, 0x20
//    ctx->r29 = ADD32(ctx->r29, 0X20);
//    return;
//    // addiu       $sp, $sp, 0x20
//    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
