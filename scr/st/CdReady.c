#include "recomp.h"
#include "disable_warnings.h"

void CdReady(uint8_t* rdram, recomp_context* ctx) 
{
    printf("CdReady\n");


    // a1 = mode (0=wait, 1=poll)
    // a2 = result buffer
    uint8_t* result_buf = ctx->r5 ? (uint8_t*)GET_PTR(ctx->r5) : nullptr;

    // Заполняем статус если буфер передан
    if (result_buf) {
        result_buf[0] = 0x02; // status: complete
    }

    ctx->r2 = 0; // 0 = команда завершена
    return;


    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// addiu       $sp, $sp, -0x18
    //ctx->r29 = ADD32(ctx->r29, -0X18);
    //// sw          $ra, 0x10($sp)
    //MEM_W(0X10, ctx->r29) = ctx->r31;
    //// jal         0x80069AA0
    //// nop

    //CD_ready(rdram, ctx);
    //goto after_0;
    //// nop

    //after_0:
    //// lw          $ra, 0x10($sp)
    //ctx->r31 = MEM_W(0X10, ctx->r29);
    //// addiu       $sp, $sp, 0x18
    //ctx->r29 = ADD32(ctx->r29, 0X18);
    //// jr          $ra
    //// nop

    //return;
    //// nop

;}
