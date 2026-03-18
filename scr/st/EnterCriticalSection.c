#include "recomp.h"
#include "disable_warnings.h"

void EnterCriticalSection(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // syscall     0
    recomp_syscall_handler(rdram, ctx, 0x80077E98);
    return;
    // jr          $ra
    // nop

    return;
    // nop

;}
