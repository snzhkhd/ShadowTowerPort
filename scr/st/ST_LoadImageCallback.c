#include "recomp.h"
#include "disable_warnings.h"
#include "PsyX/PsyX_render.h"
#include "psx/libgte.h"
#include "psx/libgpu.h"

void ST_LoadImageCallback(uint8_t* rdram, recomp_context* ctx) 
{
    RECT16* rect = (RECT16*)GET_PTR(ctx->r4);
    u_long* p = (u_long*)GET_PTR(ctx->r5);

    printf("[LoadImage] x=%d y=%d w=%d h=%d\n",
        rect->x, rect->y, rect->w, rect->h);

    if (rect->w > 1024) {
        // PS1 wrap-around: данные льются линейно в VRAM
        uint16_t* src = (uint16_t*)p;
        int total = (int)rect->w * (int)rect->h;
        int cur_x = rect->x;
        int cur_y = rect->y;
        int offset = 0;

        ////debug
        //static bool once = false;
        //if (!once) 
        //{
        //    once = true;
        //    GR_SaveVRAM("vram_after_wrap.png", 0, 0, 1024, 512, 0);
        //    printf("[DUMP] saved after first wrap upload\n");
        //}

        //printf("[WRAP] src first bytes: %04X %04X %04X %04X (total=%d)\n",
        //    src[0], src[1], src[2], src[3],
        //    (int)rect->w * (int)rect->h);

        while (offset < total) {
            int chunk = 1024 - cur_x; // до конца строки VRAM
            if (chunk > total - offset)
                chunk = total - offset;
            if (chunk <= 0) break;

            GR_CopyVRAM(src + offset, 0, 0, chunk, 1, cur_x, cur_y);
            GR_UpdateVRAM();
            offset += chunk;
            cur_x += chunk;
            if (cur_x >= 1024) {
                cur_x = 0;
                cur_y++;
            }
        }
        printf("[LoadImageCallback] total=%d pixels uploaded, end=(%d,%d)\n",
            total, cur_x, cur_y);
    }
    else {
        // Обычная загрузка
        LoadImage(rect, p);
        GR_UpdateVRAM();
    }
    ctx->r2 = 0;

    return;


//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x30
//    ctx->r29 = ADD32(ctx->r29, -0X30);
//    // sw          $s1, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r17;
//    // addu        $s1, $a0, $zero
//    ctx->r17 = ADD32(ctx->r4, 0);
//    // sw          $s2, 0x18($sp)
//    MEM_W(0X18, ctx->r29) = ctx->r18;
//    // addu        $s2, $a1, $zero
//    ctx->r18 = ADD32(ctx->r5, 0);
//    // sw          $ra, 0x28($sp)
//    MEM_W(0X28, ctx->r29) = ctx->r31;
//    // sw          $s5, 0x24($sp)
//    MEM_W(0X24, ctx->r29) = ctx->r21;
//    // sw          $s4, 0x20($sp)
//    MEM_W(0X20, ctx->r29) = ctx->r20;
//    // sw          $s3, 0x1C($sp)
//    MEM_W(0X1C, ctx->r29) = ctx->r19;
//    // jal         0x8007C070
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    sub_8007C070(rdram, ctx);
//    goto after_0;
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    after_0:
//    // lh          $a1, 0x4($s1)
//    ctx->r5 = MEM_HS(0X4, ctx->r17);
//    // lhu         $v1, 0x4($s1)
//    ctx->r3 = MEM_HU(0X4, ctx->r17);
//    // bltz        $a1, L_8007B368
//    if (SIGNED(ctx->r5) < 0) {
//        // addu        $s5, $zero, $zero
//        ctx->r21 = ADD32(0, 0);
//        goto L_8007B368;
//    }
//    // addu        $s5, $zero, $zero
//    ctx->r21 = ADD32(0, 0);
//    // addu        $a0, $v1, $zero
//    ctx->r4 = ADD32(ctx->r3, 0);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lh          $v0, 0x7CC4($v0)
//    ctx->r2 = MEM_HS(0X7CC4, ctx->r2);
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lhu         $v1, 0x7CC4($v1)
//    ctx->r3 = MEM_HU(0X7CC4, ctx->r3);
//    // slt         $v0, $v0, $a1
//    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
//    // beq         $v0, $zero, L_8007B36C
//    if (ctx->r2 == 0) {
//        // nop
//    
//        goto L_8007B36C;
//    }
//    // nop
//
//    // j           L_8007B36C
//    // addu        $a0, $v1, $zero
//    ctx->r4 = ADD32(ctx->r3, 0);
//    goto L_8007B36C;
//    // addu        $a0, $v1, $zero
//    ctx->r4 = ADD32(ctx->r3, 0);
//L_8007B368:
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//L_8007B36C:
//    // lh          $a1, 0x6($s1)
//    ctx->r5 = MEM_HS(0X6, ctx->r17);
//    // lhu         $v1, 0x6($s1)
//    ctx->r3 = MEM_HU(0X6, ctx->r17);
//    // bltz        $a1, L_8007B3A4
//    if (SIGNED(ctx->r5) < 0) {
//        // sh          $a0, 0x4($s1)
//        MEM_H(0X4, ctx->r17) = ctx->r4;
//        goto L_8007B3A4;
//    }
//    // sh          $a0, 0x4($s1)
//    MEM_H(0X4, ctx->r17) = ctx->r4;
//    // addu        $a0, $v1, $zero
//    ctx->r4 = ADD32(ctx->r3, 0);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lh          $v0, 0x7CC6($v0)
//    ctx->r2 = MEM_HS(0X7CC6, ctx->r2);
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lhu         $v1, 0x7CC6($v1)
//    ctx->r3 = MEM_HU(0X7CC6, ctx->r3);
//    // slt         $v0, $v0, $a1
//    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
//    // beq         $v0, $zero, L_8007B3AC
//    if (ctx->r2 == 0) {
//        // sll         $v0, $a0, 16
//        ctx->r2 = S32(ctx->r4) << 16;
//        goto L_8007B3AC;
//    }
//    // sll         $v0, $a0, 16
//    ctx->r2 = S32(ctx->r4) << 16;
//    // j           L_8007B3A8
//    // addu        $a0, $v1, $zero
//    ctx->r4 = ADD32(ctx->r3, 0);
//    goto L_8007B3A8;
//    // addu        $a0, $v1, $zero
//    ctx->r4 = ADD32(ctx->r3, 0);
//L_8007B3A4:
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//L_8007B3A8:
//    // sll         $v0, $a0, 16
//    ctx->r2 = S32(ctx->r4) << 16;
//L_8007B3AC:
//    // lh          $v1, 0x4($s1)
//    ctx->r3 = MEM_HS(0X4, ctx->r17);
//    // sra         $v0, $v0, 16
//    ctx->r2 = S32(ctx->r2) >> 16;
//    // mult        $v1, $v0
//    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
//    // sh          $a0, 0x6($s1)
//    MEM_H(0X6, ctx->r17) = ctx->r4;
//    // mflo        $a2
//    ctx->r6 = lo;
//    // addiu       $v1, $a2, 0x1
//    ctx->r3 = ADD32(ctx->r6, 0X1);
//    // srl         $v0, $v1, 31
//    ctx->r2 = S32(U32(ctx->r3) >> 31);
//    // addu        $v1, $v1, $v0
//    ctx->r3 = ADD32(ctx->r3, ctx->r2);
//    // sra         $a0, $v1, 1
//    ctx->r4 = S32(ctx->r3) >> 1;
//    // bgtz        $a0, L_8007B3E0
//    if (SIGNED(ctx->r4) > 0) {
//        // sra         $s0, $v1, 5
//        ctx->r16 = S32(ctx->r3) >> 5;
//        goto L_8007B3E0;
//    }
//    // sra         $s0, $v1, 5
//    ctx->r16 = S32(ctx->r3) >> 5;
//    // j           L_8007B51C
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    goto L_8007B51C;
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//L_8007B3E0:
//    // addu        $v1, $s0, $zero
//    ctx->r3 = ADD32(ctx->r16, 0);
//    // sll         $v0, $v1, 4
//    ctx->r2 = S32(ctx->r3) << 4;
//    // subu        $s0, $a0, $v0
//    ctx->r16 = SUB32(ctx->r4, ctx->r2);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7DC8($v0)
//    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
//    // addu        $s4, $v1, $zero
//    ctx->r20 = ADD32(ctx->r3, 0);
//    // lw          $v0, 0x0($v0)
//    ctx->r2 = MEM_W(0X0, ctx->r2);
//    // lui         $v1, 0x400
//    ctx->r3 = S32(0X400 << 16);
//    // and         $v0, $v0, $v1
//    ctx->r2 = ctx->r2 & ctx->r3;
//    // bne         $v0, $zero, L_8007B440
//    if (ctx->r2 != 0) {
//        // lui         $a0, 0xA000
//        ctx->r4 = S32(0XA000 << 16);
//        goto L_8007B440;
//    }
//    // lui         $a0, 0xA000
//    ctx->r4 = S32(0XA000 << 16);
//    // lui         $s3, 0x400
//    ctx->r19 = S32(0X400 << 16);
//L_8007B410:
//    // jal         0x8007C0A4
//    // nop
//
//    sub_8007C0A4(rdram, ctx);
//    goto after_1;
//    // nop
//
//    after_1:
//    // bne         $v0, $zero, L_8007B51C
//    if (ctx->r2 != 0) {
//        // addiu       $v0, $zero, -0x1
//        ctx->r2 = ADD32(0, -0X1);
//        goto L_8007B51C;
//    }
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7DC8($v0)
//    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
//    // nop
//
//    // lw          $v0, 0x0($v0)
//    ctx->r2 = MEM_W(0X0, ctx->r2);
//    // nop
//
//    // and         $v0, $v0, $s3
//    ctx->r2 = ctx->r2 & ctx->r19;
//    // beq         $v0, $zero, L_8007B410
//    if (ctx->r2 == 0) {
//        // lui         $a0, 0xA000
//        ctx->r4 = S32(0XA000 << 16);
//        goto L_8007B410;
//    }
//    // lui         $a0, 0xA000
//    ctx->r4 = S32(0XA000 << 16);
//L_8007B440:
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lw          $v1, 0x7DC8($v1)
//    ctx->r3 = MEM_W(0X7DC8, ctx->r3);
//    // lui         $v0, 0x400
//    ctx->r2 = S32(0X400 << 16);
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lw          $v1, 0x7DC4($v1)
//    ctx->r3 = MEM_W(0X7DC4, ctx->r3);
//    // lui         $v0, 0x100
//    ctx->r2 = S32(0X100 << 16);
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7DC4($v0)
//    ctx->r2 = MEM_W(0X7DC4, ctx->r2);
//    // beq         $s5, $zero, L_8007B474
//    if (ctx->r21 == 0) {
//        // nop
//    
//        goto L_8007B474;
//    }
//    // nop
//
//    // lui         $a0, 0xB000
//    ctx->r4 = S32(0XB000 << 16);
//L_8007B474:
//    // sw          $a0, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r4;
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lw          $v1, 0x7DC4($v1)
//    ctx->r3 = MEM_W(0X7DC4, ctx->r3);
//    // lw          $v0, 0x0($s1)
//    ctx->r2 = MEM_W(0X0, ctx->r17);
//    // nop
//
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lw          $v1, 0x7DC4($v1)
//    ctx->r3 = MEM_W(0X7DC4, ctx->r3);
//    // lw          $v0, 0x4($s1)
//    ctx->r2 = MEM_W(0X4, ctx->r17);
//    // addiu       $s0, $s0, -0x1
//    ctx->r16 = ADD32(ctx->r16, -0X1);
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // addiu       $v0, $zero, -0x1
//    ctx->r2 = ADD32(0, -0X1);
//    // beq         $s0, $v0, L_8007B4CC
//    if (ctx->r16 == ctx->r2) {
//        // nop
//    
//        goto L_8007B4CC;
//    }
//    // nop
//
//    // addiu       $a0, $zero, -0x1
//    ctx->r4 = ADD32(0, -0X1);
//L_8007B4B0:
//    // lw          $v1, 0x0($s2)
//    ctx->r3 = MEM_W(0X0, ctx->r18);
//    // addiu       $s2, $s2, 0x4
//    ctx->r18 = ADD32(ctx->r18, 0X4);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7DC4($v0)
//    ctx->r2 = MEM_W(0X7DC4, ctx->r2);
//    // addiu       $s0, $s0, -0x1
//    ctx->r16 = ADD32(ctx->r16, -0X1);
//    // bne         $s0, $a0, L_8007B4B0
//    if (ctx->r16 != ctx->r4) {
//        // sw          $v1, 0x0($v0)
//        MEM_W(0X0, ctx->r2) = ctx->r3;
//        goto L_8007B4B0;
//    }
//    // sw          $v1, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r3;
//L_8007B4CC:
//    // beq         $s4, $zero, L_8007B518
//    if (ctx->r20 == 0) {
//        // lui         $v1, 0x400
//        ctx->r3 = S32(0X400 << 16);
//        goto L_8007B518;
//    }
//    // lui         $v1, 0x400
//    ctx->r3 = S32(0X400 << 16);
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7DC8($v0)
//    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
//    // ori         $v1, $v1, 0x2
//    ctx->r3 = ctx->r3 | 0X2;
//    // sw          $v1, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r3;
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7DCC($v0)
//    ctx->r2 = MEM_W(0X7DCC, ctx->r2);
//    // lui         $a0, 0x100
//    ctx->r4 = S32(0X100 << 16);
//    // sw          $s2, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r18;
//    // sll         $v0, $s4, 16
//    ctx->r2 = S32(ctx->r20) << 16;
//    // lui         $v1, 0x8008
//    ctx->r3 = S32(0X8008 << 16);
//    // lw          $v1, 0x7DD0($v1)
//    ctx->r3 = MEM_W(0X7DD0, ctx->r3);
//    // ori         $v0, $v0, 0x10
//    ctx->r2 = ctx->r2 | 0X10;
//    // sw          $v0, 0x0($v1)
//    MEM_W(0X0, ctx->r3) = ctx->r2;
//    // lui         $v0, 0x8008
//    ctx->r2 = S32(0X8008 << 16);
//    // lw          $v0, 0x7DD4($v0)
//    ctx->r2 = MEM_W(0X7DD4, ctx->r2);
//    // ori         $a0, $a0, 0x201
//    ctx->r4 = ctx->r4 | 0X201;
//    // sw          $a0, 0x0($v0)
//    MEM_W(0X0, ctx->r2) = ctx->r4;
//L_8007B518:
//    // addu        $v0, $zero, $zero
//    ctx->r2 = ADD32(0, 0);
//L_8007B51C:
//    // lw          $ra, 0x28($sp)
//    ctx->r31 = MEM_W(0X28, ctx->r29);
//    // lw          $s5, 0x24($sp)
//    ctx->r21 = MEM_W(0X24, ctx->r29);
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
//    // addiu       $sp, $sp, 0x30
//    ctx->r29 = ADD32(ctx->r29, 0X30);
//    return;
//    // addiu       $sp, $sp, 0x30
//    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
