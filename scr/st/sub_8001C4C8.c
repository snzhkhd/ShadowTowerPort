#include "recomp.h"
#include "disable_warnings.h"

void sub_8001C4C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $t3, $v0, -0x70D8
    ctx->r11 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0x128($a2)
    ctx->r3 = MEM_W(0X128, ctx->r6);
    // lw          $v0, 0x248($t3)
    ctx->r2 = MEM_W(0X248, ctx->r11);
    // nop

    // subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    // bgez        $a0, L_8001C4F0
    if (SIGNED(ctx->r4) >= 0) {
        // nop
    
        goto L_8001C4F0;
    }
    // nop

    // addiu       $a0, $a0, 0x7FF
    ctx->r4 = ADD32(ctx->r4, 0X7FF);
L_8001C4F0:
    // lw          $v1, 0x130($a2)
    ctx->r3 = MEM_W(0X130, ctx->r6);
    // lw          $v0, 0x250($t3)
    ctx->r2 = MEM_W(0X250, ctx->r11);
    // nop

    // subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x1EA($a2)
    ctx->r2 = MEM_HU(0X1EA, ctx->r6);
    // sra         $v1, $a0, 11
    ctx->r3 = S32(ctx->r4) >> 11;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2) >> 16;
    // bgez        $a1, L_8001C51C
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $t0, $v1, $t2
        ctx->r8 = ADD32(ctx->r3, ctx->r10);
        goto L_8001C51C;
    }
    // addu        $t0, $v1, $t2
    ctx->r8 = ADD32(ctx->r3, ctx->r10);
    // addiu       $a1, $a1, 0x7FF
    ctx->r5 = ADD32(ctx->r5, 0X7FF);
L_8001C51C:
    // lhu         $v0, 0x1EE($a2)
    ctx->r2 = MEM_HU(0X1EE, ctx->r6);
    // sra         $v1, $a1, 11
    ctx->r3 = S32(ctx->r5) >> 11;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2) >> 16;
    // lbu         $v0, 0x1E8($a2)
    ctx->r2 = MEM_BU(0X1E8, ctx->r6);
    // nop

    // bne         $v0, $zero, L_8001C5A8
    if (ctx->r2 != 0) {
        // addu        $a3, $v1, $t1
        ctx->r7 = ADD32(ctx->r3, ctx->r9);
        goto L_8001C5A8;
    }
    // addu        $a3, $v1, $t1
    ctx->r7 = ADD32(ctx->r3, ctx->r9);
    // lw          $v0, 0x1F0($a2)
    ctx->r2 = MEM_W(0X1F0, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0x1F8($a2)
    ctx->r2 = MEM_W(0X1F8, ctx->r6);
    // nop

    // mult        $v0, $a3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(0X1F4, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // lw          $v0, 0x1FC($a2)
    ctx->r2 = MEM_W(0X1FC, ctx->r6);
    // nop

    // mult        $v0, $a3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // subu        $v1, $a0, $v1
    ctx->r3 = SUB32(ctx->r4, ctx->r3);
    // lw          $v0, 0x200($a2)
    ctx->r2 = MEM_W(0X200, ctx->r6);
    // lw          $a0, 0x204($a2)
    ctx->r4 = MEM_W(0X204, ctx->r6);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // mflo        $t5
    ctx->r13 = lo;
    // subu        $v0, $a1, $t5
    ctx->r2 = SUB32(ctx->r5, ctx->r13);
    // bgtz        $v1, L_8001C5A0
    if (SIGNED(ctx->r3) > 0) {
        // addu        $v0, $v0, $a0
        ctx->r2 = ADD32(ctx->r2, ctx->r4);
        goto L_8001C5A0;
    }
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // bgez        $v0, L_8001C5A8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8001C5A8;
    }
    // nop

L_8001C5A0:
    // j           L_8001C604
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    goto L_8001C604;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_8001C5A8:
    // lw          $a0, 0x12C($a2)
    ctx->r4 = MEM_W(0X12C, ctx->r6);
    // lw          $v1, 0x24C($t3)
    ctx->r3 = MEM_W(0X24C, ctx->r11);
    // lw          $v0, 0x208($a2)
    ctx->r2 = MEM_W(0X208, ctx->r6);
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // bgez        $a0, L_8001C5D0
    if (SIGNED(ctx->r4) >= 0) {
        // sh          $v0, 0x1EC($a2)
        MEM_H(0X1EC, ctx->r6) = ctx->r2;
        goto L_8001C5D0;
    }
    // sh          $v0, 0x1EC($a2)
    MEM_H(0X1EC, ctx->r6) = ctx->r2;
    // addiu       $a0, $a0, 0x7FF
    ctx->r4 = ADD32(ctx->r4, 0X7FF);
L_8001C5D0:
    // subu        $v0, $t0, $t2
    ctx->r2 = SUB32(ctx->r8, ctx->r10);
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // subu        $v0, $a3, $t1
    ctx->r2 = SUB32(ctx->r7, ctx->r9);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) >> 11;
    // nop

    // mult        $a0, $a0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // mflo        $a0
    ctx->r4 = lo;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_8001C604:
    // jr          $ra
    // nop

    return;
    // nop

;}
