#include "recomp.h"
#include "disable_warnings.h"

void CdCheckStatus(uint8_t* rdram, recomp_context* ctx) 
{
  //  printf("CdCheckStatus\n");
    //int a1 = ctx->r4;
    //uint8_t* a2 = (uint8_t*)ctx->r5;
    //// 1. Имитируем, что диск готов
    // // По смещению 0 в статусе обычно лежит "Ready" (например 0x01 или 0x02)
    //uint32_t* regs = (uint32_t*)GET_PTR(0x801E6178);    //g_CdStatusRegisters
    //regs[0] = 0x01; // Успех / Ready

    //// 2. Если игра просит скопировать статус в массив a2
    //if (a2) {
    //    // Копируем наш "фейковый" статус в память игры
    //    for (int i = 0; i < 8; i++) a2[i] = ((uint8_t*)regs)[i];
    //}
    ctx->r2 = 0;
    return; // Возвращаем 0 (статус ОК)



    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // addiu       $s1, $s1, 0xD20
    ctx->r17 = ADD32(ctx->r17, 0XD20);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_8006BA6C:
    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    VSync(rdram, ctx);
    goto after_0;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_0:
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
    // nop

    // addiu       $v1, $v1, 0x4B0
    ctx->r3 = ADD32(ctx->r3, 0X4B0);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_8006BAD4
    if (ctx->r3 != 0) {
        // addiu       $s0, $zero, -0x1
        ctx->r16 = ADD32(0, -0X1);
        goto L_8006BAD4;
    }
    // addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // lw          $v0, -0x8($s1)
    ctx->r2 = MEM_W(-0X8, ctx->r17);
    // nop

    // bltz        $v0, L_8006BABC
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_8006BABC;
    }
    // nop

    // jal         0x80077104
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    VSync(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_1:
    // lw          $v1, -0x4($s1)
    ctx->r3 = MEM_W(-0X4, ctx->r17);
    // nop

    // addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8006BAD0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8006BAD0;
    }
    // nop

L_8006BABC:
    // jal         0x8006B6C0
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sub_8006B6C0(rdram, ctx);
    goto after_2;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // lw          $s0, -0x1C($s1)
    ctx->r16 = MEM_W(-0X1C, ctx->r17);
    // j           L_8006BAD4
    // nop

    goto L_8006BAD4;
    // nop

L_8006BAD0:
    // lw          $s0, -0x8($s1)
    ctx->r16 = MEM_W(-0X8, ctx->r17);
L_8006BAD4:
    // bne         $s2, $zero, L_8006BAE4
    if (ctx->r18 != 0) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_8006BAE4;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // bgtz        $s0, L_8006BA6C
    if (SIGNED(ctx->r16) > 0) {
        // nop
    
        goto L_8006BA6C;
    }
    // nop

L_8006BAE4:
    // jal         0x80068C98
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    CdReady(rdram, ctx);
    goto after_3;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_3:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
