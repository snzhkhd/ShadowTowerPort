#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "PsyX/PsyX_render.h"
#include "psx/libetc.h"

void ClearOTagR(uint8_t* rdram, recomp_context* ctx) 
{

    uint32_t ot_addr = ctx->r4;
    int n = (int)ctx->r5;
    uint32_t* ot = (uint32_t*)GET_PTR(ot_addr);
    if (ot && n > 0) {
        // Правильно — как в оригинале:
        // ClearOTag заполняет список, потом ot[0] = dword_8007625C & 0xFFFFFF
        for (int i = n - 1; i >= 1; i--)
            ot[i] = (ot_addr + (i - 1) * 4) & 0x00FFFFFF;

        // Читаем dword_8007625C как делает оригинал
        uint32_t terminator = MEM_W(0, 0x80087D80) & 0x00FFFFFF;
        ot[0] = terminator;
    }

    ctx->r2 = 0;

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lbu         $v0, 0x7CC2($v0)
//    ctx->r2 = MEM_BU(0X7CC2, ctx->r2);
//    // addiu       $sp, $sp, -0x20
//    ctx->r29 = ADD32(ctx->r29, -0X20);
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // addu        $s0, $a0, $zero
//    ctx->r16 = ADD32(ctx->r4, 0);
//    // sw          $s1, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r17;
//    // addu        $s1, $a1, $zero
//    ctx->r17 = ADD32(ctx->r5, 0);
//    // sltiu       $v0, $v0, 0x2
//    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
//    // bne         $v0, $zero, L_80079F94
//    if (ctx->r2 != 0) {
//        // sw          $ra, 0x18($sp)
//        MEM_W(0X18, ctx->r29) = ctx->r31;
//        goto L_80079F94;
//    }
//    // sw          $ra, 0x18($sp)
//    MEM_W(0X18, ctx->r29) = ctx->r31;
//    // lui         $a0, 0x8001
//    ctx->r4 = S32(0X8001 << 16);
//    // addiu       $a0, $a0, 0x4244
//    ctx->r4 = ADD32(ctx->r4, 0X4244);
//    // addu        $a1, $s0, $zero
//    ctx->r5 = ADD32(ctx->r16, 0);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7CBC($v0)
//    ctx->r2 = MEM_W(0X7CBC, ctx->r2);
//    // nop
//
//    // jalr        $v0
//    // addu        $a2, $s1, $zero
//    ctx->r6 = ADD32(ctx->r17, 0);
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_0;
//    // addu        $a2, $s1, $zero
//    ctx->r6 = ADD32(ctx->r17, 0);
//    after_0:
//L_80079F94:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7CB8($v0)
//    ctx->r2 = MEM_W(0X7CB8, ctx->r2);
//    // addu        $a0, $s0, $zero
//    ctx->r4 = ADD32(ctx->r16, 0);
//    // lw          $v0, 0x2C($v0)
//    ctx->r2 = MEM_W(0X2C, ctx->r2);
//    // nop
//
//    // jalr        $v0
//    // addu        $a1, $s1, $zero
//    ctx->r5 = ADD32(ctx->r17, 0);
//    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
//    goto after_1;
//    // addu        $a1, $s1, $zero
//    ctx->r5 = ADD32(ctx->r17, 0);
//    after_1:
//    // lui         $a2, 0xFF
//    ctx->r6 = S32(0XFF << 16);
//    // ori         $a2, $a2, 0xFFFF
//    ctx->r6 = ctx->r6 | 0XFFFF;
//    // addu        $v0, $s0, $zero
//    ctx->r2 = ADD32(ctx->r16, 0);
//    // lui         $a1, 0x8008
//    ctx->r5 = S32(0X8008 << 16);
//    // addiu       $a1, $a1, 0x7D80
//    ctx->r5 = ADD32(ctx->r5, 0X7D80);
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // addiu       $v1, $v1, 0x7D6C
//    ctx->r3 = ADD32(ctx->r3, 0X7D6C);
//    // and         $v1, $v1, $a2
//    ctx->r3 = ctx->r3 & ctx->r6;
//    // lui         $a0, 0x400
//    ctx->r4 = S32(0X400 << 16);
//    // or          $v1, $v1, $a0
//    ctx->r3 = ctx->r3 | ctx->r4;
//    // sw          $v1, 0x0($a1)
//    MEM_W(0X0, ctx->r5) = ctx->r3;
//    // and         $a1, $a1, $a2
//    ctx->r5 = ctx->r5 & ctx->r6;
//    // sw          $a1, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r5;
//    // lw          $ra, 0x18($sp)
//    ctx->r31 = MEM_W(0X18, ctx->r29);
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
