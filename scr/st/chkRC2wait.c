#include "recomp.h"
#include "disable_warnings.h"

void chkRC2wait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // ori         $v0, $v0, 0x1120
    ctx->r2 = ctx->r2 | 0X1120;
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x4AA8($v0)
    ctx->r2 = MEM_W(-0X4AA8, ctx->r2);
    // andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8007F38C
    if (ctx->r2 == 0) {
        // lui         $v1, 0x1F80
        ctx->r3 = S32(0X1F80 << 16);
        goto L_8007F38C;
    }
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // ori         $v1, $v1, 0x1128
    ctx->r3 = ctx->r3 | 0X1128;
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // beq         $v0, $zero, L_8007F388
    if (ctx->r2 == 0) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_8007F388;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // j           L_8007F38C
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    goto L_8007F38C;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_8007F388:
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_8007F38C:
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // ori         $v0, $v0, 0x1124
    ctx->r2 = ctx->r2 | 0X1124;
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // bne         $v0, $zero, L_8007F3C4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007F3C4;
    }
    // nop

    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x4AA8($v0)
    ctx->r2 = MEM_W(-0X4AA8, ctx->r2);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lw          $v1, -0x4AA4($v1)
    ctx->r3 = MEM_W(-0X4AA4, ctx->r3);
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // j           L_8007F3D8
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    goto L_8007F3D8;
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
L_8007F3C4:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x4AA8($v0)
    ctx->r2 = MEM_W(-0X4AA8, ctx->r2);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lw          $v1, -0x4AA4($v1)
    ctx->r3 = MEM_W(-0X4AA4, ctx->r3);
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
L_8007F3D8:
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // jr          $ra
    // xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    return;
    // xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
;}
