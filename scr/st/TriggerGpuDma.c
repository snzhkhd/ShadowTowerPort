#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_public.h"
#include "PsyX/PsyX_render.h"
#include "gpu/PsyX_GPU.h"
#include "psx/libetc.h"
#include <string>

static int SaveCount = 0;
static int SaveTimer = 0;

void TriggerGpuDma(uint8_t* rdram, recomp_context* ctx) 
{

    //PsyX_BeginScene(); <- גûחûגאועסÿ ג BeginDraw2D ט RenderScene
    //printf("TriggerGpuDma\n");

    uint32_t madr = ctx->r4;
    calls_per_frame++;
    if (madr < 0x80000000 || madr >= 0x80200000) return;
    uint32_t cur_addr = madr;

    uint32_t* p_data = (uint32_t*)GET_PTR(madr);

    //int primCount = 0;
    //uint32_t cur = madr;
    //while (cur >= 0x80000000 && cur < 0x80200000) {
    //    uint32_t* p = (uint32_t*)GET_PTR(cur);
    //    uint32_t tag = p[0];
    //    uint8_t len = (tag >> 24) & 0xFF;
    //    if (len > 0) primCount++;
    //    uint32_t next = tag & 0x00FFFFFF;
    //    if (next == 0x00FFFFFF || next < 0x00010000) break;
    //    cur = next | 0x80000000;
    //}
    //printf("[TriggerGpuDma] addr=%08X prims=%d\n", madr, primCount);


    uint32_t first_word = p_data[0];
    uint32_t next_ptr = first_word & 0x00FFFFFF;
    uint8_t  top_byte = (first_word >> 24) & 0xFF;

    if (next_ptr >= 0x00010000 && next_ptr < 0x00200000 && top_byte < 0x20)
    {

        int max_iter = 1024;

        while (true)
        {
            uint32_t* cur = (uint32_t*)GET_PTR(cur_addr);
            uint32_t tag = cur[0];
            uint8_t  len = (tag >> 24) & 0xFF;
            uint32_t next = tag & 0x00FFFFFF;

            //// Validate PS1 RAM bounds
            //if (next >= 0x200000) {  // beyond 2MB PS1 RAM
            //    printf("[GPU] OTag corruption: addr=%06X, stopping\n", next);
            //    break;
            //}

            if (len > 0)
            {
                uint8_t code = (cur[1] >> 24) & 0xFF;

                if (code == 0x2E)
                {

                    uint16_t clut = (cur[3] >> 16) & 0xFFFF;
                    uint16_t tpage = (cur[5] >> 16) & 0xFFFF;
                    uint8_t u0 = cur[3] & 0xFF;
                    uint8_t v0 = (cur[3] >> 8) & 0xFF;
                    uint8_t u1 = cur[5] & 0xFF;
                    uint8_t v1 = (cur[5] >> 8) & 0xFF;
                    int16_t x0 = cur[2] & 0xFFFF;
                    int16_t y0 = cur[2] >> 16;
                }


                static uint8_t psyx_prim[256];
                memset(psyx_prim, 0, 256);

                // P_TAG (USE_EXTENDED_PRIM_POINTERS=0):
                *(uint32_t*)psyx_prim = ((uint32_t)len << 24) | 0x00FFFFFF;
                psyx_prim[4] = (cur[1] >> 0) & 0xFF; // r0
                psyx_prim[5] = (cur[1] >> 8) & 0xFF; // g0
                psyx_prim[6] = (cur[1] >> 16) & 0xFF; // b0
                psyx_prim[7] = (cur[1] >> 24) & 0xFF; // code 
                memcpy(psyx_prim + 8, &cur[2], (len - 1) * 4);


                ParsePrimitivesLinkedList((u_long*)psyx_prim, 0);

            }
            if (next == 0x00FFFFFF || next < 0x00010000) break;
            cur_addr = next | 0x80000000;
        }

        GR_UpdateVRAM();

        DrawAllSplits();

        //PsyX_EndScene(); <- גûחûגאועסÿ ג RenderEnd ט EndDraw2D
        
    }
    else if (top_byte == 0x00 && (first_word & 0xFF) <= 0x20)
    {
        uint32_t* packet_start = p_data + 1;

        ParsePrimitivesLinkedList((unsigned long*)packet_start, 1);
    }
    else
    {

        ParsePrimitivesLinkedList((unsigned long*)p_data, 1);
    }

    WRITE_W(0x1F8010A8, MEM_W(0, 0x1F8010A8) & ~0x01000000);
    WRITE_W(0x1F801814, 0x1C000000);
    ctx->r2 = 0;

    //SaveTimer++;
    ////     printf("VSync call\n");
    ////VSync(0);
    ////g_vsync_pending = false;

    //if (SaveTimer > 20 && SaveCount < 5)
    //{
    //    SaveTimer = 0;
    //    std::string str = "vram_debug_" + std::to_string(SaveCount) + ".png";
    //    GR_SaveVRAM(str.c_str(), 0, 0, 1024, 512, 0);
    //    SaveCount++;
    //    printf("[DEBUG] VRAM saved to vram_debug.png\n");
    //}


 //   printf("PsyX_EndScene\n");
    PsyX_EndScene();

    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// lui         $v1, 0x400
    //ctx->r3 = S32(0X400 << 16);
    //// lui         $v0, 0x8008
    //ctx->r2 = S32(0X8008 << 16);
    //// lw          $v0, 0x7DC8($v0)
    //ctx->r2 = MEM_W(0X7DC8, ctx->r2);
    //// ori         $v1, $v1, 0x2
    //ctx->r3 = ctx->r3 | 0X2;
    //// sw          $v1, 0x0($v0)
    //MEM_W(0X0, ctx->r2) = ctx->r3;
    //// lui         $v0, 0x8008
    //ctx->r2 = S32(0X8008 << 16);
    //// lw          $v0, 0x7DCC($v0)
    //ctx->r2 = MEM_W(0X7DCC, ctx->r2);
    //// nop

    //// sw          $a0, 0x0($v0)
    //MEM_W(0X0, ctx->r2) = ctx->r4;
    //// lui         $v0, 0x8008
    //ctx->r2 = S32(0X8008 << 16);
    //// lw          $v0, 0x7DD0($v0)
    //ctx->r2 = MEM_W(0X7DD0, ctx->r2);
    //// lui         $v1, 0x100
    //ctx->r3 = S32(0X100 << 16);
    //// sw          $zero, 0x0($v0)
    //MEM_W(0X0, ctx->r2) = 0;
    //// lui         $v0, 0x8008
    //ctx->r2 = S32(0X8008 << 16);
    //// lw          $v0, 0x7DD4($v0)
    //ctx->r2 = MEM_W(0X7DD4, ctx->r2);
    //// ori         $v1, $v1, 0x401
    //ctx->r3 = ctx->r3 | 0X401;
    //// jr          $ra
    //// sw          $v1, 0x0($v0)
    //MEM_W(0X0, ctx->r2) = ctx->r3;
    //return;
    //// sw          $v1, 0x0($v0)
    //MEM_W(0X0, ctx->r2) = ctx->r3;
;}
