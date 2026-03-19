#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void GetTPage(uint8_t* rdram, recomp_context* ctx) 
{
    int tp = (int)ctx->r4; // Texture Page color mode (0:4-bit, 1:8-bit, 2:15-bit)
    int abr = (int)ctx->r5; // Semi-transparency mode (0, 1, 2, 3)
    int x = (int)ctx->r6; // X-coordinate in VRAM (0-1023)
    int y = (int)ctx->r7; // Y-coordinate in VRAM (0-511)

    // 2. Вызываем Psy-X. 
    // Это чистая математика (упаковка бит), она вернет u_short.
    u_short result = GetTPage(tp, abr, x, y);

    // 3. Записываем результат в r2 (v0).
    ctx->r2 = (uint32_t)result;

    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// andi        $v0, $a0, 0x3
    //ctx->r2 = ctx->r4 & 0X3;
    //// sll         $v0, $v0, 7
    //ctx->r2 = S32(ctx->r2) << 7;
    //// andi        $a1, $a1, 0x3
    //ctx->r5 = ctx->r5 & 0X3;
    //// sll         $a1, $a1, 5
    //ctx->r5 = S32(ctx->r5) << 5;
    //// or          $v0, $v0, $a1
    //ctx->r2 = ctx->r2 | ctx->r5;
    //// andi        $v1, $a3, 0x100
    //ctx->r3 = ctx->r7 & 0X100;
    //// sra         $v1, $v1, 4
    //ctx->r3 = S32(ctx->r3) >> 4;
    //// or          $v0, $v0, $v1
    //ctx->r2 = ctx->r2 | ctx->r3;
    //// andi        $a2, $a2, 0x3FF
    //ctx->r6 = ctx->r6 & 0X3FF;
    //// sra         $a2, $a2, 6
    //ctx->r6 = S32(ctx->r6) >> 6;
    //// or          $v0, $v0, $a2
    //ctx->r2 = ctx->r2 | ctx->r6;
    //// andi        $a3, $a3, 0x200
    //ctx->r7 = ctx->r7 & 0X200;
    //// sll         $a3, $a3, 2
    //ctx->r7 = S32(ctx->r7) << 2;
    //// jr          $ra
    //// or          $v0, $v0, $a3
    //ctx->r2 = ctx->r2 | ctx->r7;
    //return;
    //// or          $v0, $v0, $a3
    //ctx->r2 = ctx->r2 | ctx->r7;
;}
