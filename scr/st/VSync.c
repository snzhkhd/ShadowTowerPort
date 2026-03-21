#include "recomp.h"
#include "disable_warnings.h"

#include "PsyX/PsyX_public.h"
#include "gte/PsyX_GTE.h"
#include "PsyX/PsyX_render.h"
#include "audio/PsyX_SPUAL.h"
#include "psx/libetc.h"
#include <chrono>
#include <SDL2/SDL_timer.h>


static auto g_lastFrameTime = std::chrono::steady_clock::now();
const double FRAME_INTERVAL = 1.0 / 24.0;

static auto g_lastSeqTime = std::chrono::steady_clock::now();
static double g_seqAccumulator = 0.0;
const double SEQ_TICK_INTERVAL = 1.0 / 50.0; // 60Hz


static auto g_lastAdsrUpdateTime = std::chrono::steady_clock::now();


void SEQ_Update(uint8_t* rdram, recomp_context* ctx)
{
    auto now = std::chrono::steady_clock::now();
    double elapsed = std::chrono::duration<double>(now - g_lastSeqTime).count();
    g_lastSeqTime = now;
    g_seqAccumulator += elapsed;

    while (g_seqAccumulator >= SEQ_TICK_INTERVAL)
    {
    //    KF_SsSeqCalledTbyT(rdram, ctx);
        PsyX_Update_ADSR((float)SEQ_TICK_INTERVAL);
        g_seqAccumulator -= SEQ_TICK_INTERVAL;
    }
}




void VSync(uint8_t* rdram, recomp_context* ctx) 
{
    auto now = std::chrono::steady_clock::now();
    double elapsed = std::chrono::duration<double>(now - g_lastFrameTime).count();


    if (elapsed < FRAME_INTERVAL) 
    {
        int sleepMs = (int)((FRAME_INTERVAL - elapsed) * 1000.0);
        if (sleepMs > 1)
            //printf("SDL_Delay bypass\n");
            SDL_Delay(sleepMs);
    }

    g_lastFrameTime = std::chrono::steady_clock::now();


    uint32_t saved_r4 = ctx->r4;
    uint32_t saved_ra = ctx->r31;


//    SEQ_Update(rdram, ctx);

    ctx->r4 = saved_r4;
    ctx->r31 = saved_ra;

    g_vsync_pending = true;

    int mode = (int32_t)ctx->r4;
    ctx->r2 = VSync(mode == 0 ? 1 : mode);
    WRITE_W(0x1F801814, 0x1C000000);

    // Обновляем pad input для ST
    uint8_t* pad = (uint8_t*)GET_PTR(0x801CD130);
    if (pad[0] == 0x00 && pad[1] == 0x41) {
        uint16_t raw = *(uint16_t*)(pad + 2);
        uint16_t buttons = ~raw;

        uint32_t prev184 = MEM_W(0, 0x801CD184);
        MEM_W(0, 0x801CD184) = buttons;
        MEM_W(0, 0x801CD180) = buttons & ~prev184;

        // Также пишем в game pad
        uint32_t prev_pad = MEM_W(0, 0x80198F54);
        MEM_W(0, 0x80198F54) = buttons;
        // Edge detect для game pad тоже
        MEM_W(0, 0x80198F58) = buttons & ~prev_pad; // если есть такой адрес
    }



    static uint8_t prevState = 0xFF;
    uint8_t state = MEM_BU(0, 0x80199140);
    if (state != prevState) {
        printf("[STATE] changed %d → %d\n", prevState, state);
        prevState = state;
    }

    //MEM_W(0, 0x80199170) = 0x00040000;
    //MEM_W(0, 0x80199174) = 0x000419C0;
    //MEM_W(0, 0x80199178) = 0x0003F000;
//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x6A98($v0)
//    ctx->r2 = MEM_W(0X6A98, ctx->r2);
//    // lui         $a1, 0x8008
//    ctx->r5 = S32(0X8008 << 16);
//    // lw          $a1, 0x6A9C($a1)
//    ctx->r5 = MEM_W(0X6A9C, ctx->r5);
//    // addiu       $sp, $sp, -0x28
//    ctx->r29 = ADD32(ctx->r29, -0X28);
//    // sw          $ra, 0x20($sp)
//    MEM_W(0X20, ctx->r29) = ctx->r31;
//    // sw          $s1, 0x1C($sp)
//    MEM_W(0X1C, ctx->r29) = ctx->r17;
//    // sw          $s0, 0x18($sp)
//    MEM_W(0X18, ctx->r29) = ctx->r16;
//    // lw          $s0, 0x0($v0)
//    ctx->r16 = MEM_W(0X0, ctx->r2);
//L_80077128:
//    // lw          $v0, 0x0($a1)
//    ctx->r2 = MEM_W(0X0, ctx->r5);
//    // nop
//
//    // sw          $v0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r2;
//    // lw          $v1, 0x10($sp)
//    ctx->r3 = MEM_W(0X10, ctx->r29);
//    // lw          $v0, 0x0($a1)
//    ctx->r2 = MEM_W(0X0, ctx->r5);
//    // nop
//
//    // bne         $v1, $v0, L_80077128
//    if (ctx->r3 != ctx->r2) {
//        // nop
//    
//        goto L_80077128;
//    }
//    // nop
//
//    // lw          $v0, 0x10($sp)
//    ctx->r2 = MEM_W(0X10, ctx->r29);
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lw          $v1, 0x6AA0($v1)
//    ctx->r3 = MEM_W(0X6AA0, ctx->r3);
//    // nop
//
//    // subu        $v0, $v0, $v1
//    ctx->r2 = SUB32(ctx->r2, ctx->r3);
//    // bgez        $a0, L_80077174
//    if (SIGNED(ctx->r4) >= 0) {
//        // andi        $s1, $v0, 0xFFFF
//        ctx->r17 = ctx->r2 & 0XFFFF;
//        goto L_80077174;
//    }
//    // andi        $s1, $v0, 0xFFFF
//    ctx->r17 = ctx->r2 & 0XFFFF;
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7BD0($v0)
//    ctx->r2 = MEM_W(0X7BD0, ctx->r2);
//    // j           L_80077268
//    // nop
//
//    goto L_80077268;
//    // nop
//
//L_80077174:
//    // addiu       $v0, $zero, 0x1
//    ctx->r2 = ADD32(0, 0X1);
//    // beq         $a0, $v0, L_80077264
//    if (ctx->r4 == ctx->r2) {
//        // nop
//    
//        goto L_80077264;
//    }
//    // nop
//
//    // blez        $a0, L_800771A0
//    if (SIGNED(ctx->r4) <= 0) {
//        // nop
//    
//        goto L_800771A0;
//    }
//    // nop
//
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x6AA4($v0)
//    ctx->r2 = MEM_W(0X6AA4, ctx->r2);
//    // nop
//
//    // addiu       $v0, $v0, -0x1
//    ctx->r2 = ADD32(ctx->r2, -0X1);
//    // j           L_800771A8
//    // addu        $v0, $v0, $a0
//    ctx->r2 = ADD32(ctx->r2, ctx->r4);
//    goto L_800771A8;
//    // addu        $v0, $v0, $a0
//    ctx->r2 = ADD32(ctx->r2, ctx->r4);
//L_800771A0:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x6AA4($v0)
//    ctx->r2 = MEM_W(0X6AA4, ctx->r2);
//L_800771A8:
//    // blez        $a0, L_800771B4
//    if (SIGNED(ctx->r4) <= 0) {
//        // addu        $a1, $zero, $zero
//        ctx->r5 = ADD32(0, 0);
//        goto L_800771B4;
//    }
//    // addu        $a1, $zero, $zero
//    ctx->r5 = ADD32(0, 0);
//    // addiu       $a1, $a0, -0x1
//    ctx->r5 = ADD32(ctx->r4, -0X1);
//L_800771B4:
//    // jal         0x8007727C
//    // addu        $a0, $v0, $zero
//    ctx->r4 = ADD32(ctx->r2, 0);
//    sub_8007727C(rdram, ctx);
//    goto after_0;
//    // addu        $a0, $v0, $zero
//    ctx->r4 = ADD32(ctx->r2, 0);
//    after_0:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x6A98($v0)
//    ctx->r2 = MEM_W(0X6A98, ctx->r2);
//    // nop
//
//    // lw          $s0, 0x0($v0)
//    ctx->r16 = MEM_W(0X0, ctx->r2);
//    // lui         $a0, 0x8008
//    ctx->r4 = S32(0X8008 << 16);
//    // lw          $a0, 0x7BD0($a0)
//    ctx->r4 = MEM_W(0X7BD0, ctx->r4);
//    // addiu       $a1, $zero, 0x1
//    ctx->r5 = ADD32(0, 0X1);
//    // jal         0x8007727C
//    // addiu       $a0, $a0, 0x1
//    ctx->r4 = ADD32(ctx->r4, 0X1);
//    sub_8007727C(rdram, ctx);
//    goto after_1;
//    // addiu       $a0, $a0, 0x1
//    ctx->r4 = ADD32(ctx->r4, 0X1);
//    after_1:
//    // lui         $v0, 0x40
//    ctx->r2 = S32(0X40 << 16);
//    // and         $v0, $s0, $v0
//    ctx->r2 = ctx->r16 & ctx->r2;
//    // beq         $v0, $zero, L_80077228
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80077228;
//    }
//    // nop
//
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lw          $v1, 0x6A98($v1)
//    ctx->r3 = MEM_W(0X6A98, ctx->r3);
//    // nop
//
//    // lw          $v0, 0x0($v1)
//    ctx->r2 = MEM_W(0X0, ctx->r3);
//    // nop
//
//    // xor         $v0, $s0, $v0
//    ctx->r2 = ctx->r16 ^ ctx->r2;
//    // bltz        $v0, L_80077228
//    if (SIGNED(ctx->r2) < 0) {
//        // lui         $a0, 0x8000
//        ctx->r4 = S32(0X8000 << 16);
//        goto L_80077228;
//    }
//    // lui         $a0, 0x8000
//    ctx->r4 = S32(0X8000 << 16);
//L_80077210:
//    // lw          $v0, 0x0($v1)
//    ctx->r2 = MEM_W(0X0, ctx->r3);
//    // nop
//
//    // xor         $v0, $s0, $v0
//    ctx->r2 = ctx->r16 ^ ctx->r2;
//    // and         $v0, $v0, $a0
//    ctx->r2 = ctx->r2 & ctx->r4;
//    // beq         $v0, $zero, L_80077210
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_80077210;
//    }
//    // nop
//
//L_80077228:
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7BD0($v0)
//    ctx->r2 = MEM_W(0X7BD0, ctx->r2);
//    // lui         $a0, 0x8008
//    ctx->r4 = S32(0X8008 << 16);
//    // lw          $a0, 0x6A9C($a0)
//    ctx->r4 = MEM_W(0X6A9C, ctx->r4);
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // sw          $v0, 0x6AA4($at)
//    MEM_W(0X6AA4, ctx->r1) = ctx->r2;
//L_80077240:
//    // lw          $v0, 0x0($a0)
//    ctx->r2 = MEM_W(0X0, ctx->r4);
//    // lui         $at, 0x8008
//    ctx->r1 = S32(0X8008 << 16);
//    // sw          $v0, 0x6AA0($at)
//    MEM_W(0X6AA0, ctx->r1) = ctx->r2;
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lw          $v1, 0x6AA0($v1)
//    ctx->r3 = MEM_W(0X6AA0, ctx->r3);
//    // lw          $v0, 0x0($a0)
//    ctx->r2 = MEM_W(0X0, ctx->r4);
//    // nop
//
//    // bne         $v1, $v0, L_80077240
//    if (ctx->r3 != ctx->r2) {
//        // nop
//    
//        goto L_80077240;
//    }
//    // nop
//
//L_80077264:
//    // addu        $v0, $s1, $zero
//    ctx->r2 = ADD32(ctx->r17, 0);
//L_80077268:
//    // lw          $ra, 0x20($sp)
//    ctx->r31 = MEM_W(0X20, ctx->r29);
//    // lw          $s1, 0x1C($sp)
//    ctx->r17 = MEM_W(0X1C, ctx->r29);
//    // lw          $s0, 0x18($sp)
//    ctx->r16 = MEM_W(0X18, ctx->r29);
//    // jr          $ra
//    // addiu       $sp, $sp, 0x28
//    ctx->r29 = ADD32(ctx->r29, 0X28);
//    return;
//    // addiu       $sp, $sp, 0x28
//    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
