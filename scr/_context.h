#pragma once
#define _CRT_SECURE_NO_WARNINGS
//#include <SDL2/SDL.h>
#include <stdint.h>

//game global var
#define ADDR_G_ACTIVECDSTREAM 0x80088BD8
#define ADDR_G_CDTASKQUEUE    0x80088BD4


// main.cpp
extern uint8_t rdram[2 * 1024 * 1024];

typedef uint32_t gpr;

// Режимы округления для FPU
#define DEFAULT_ROUNDING_MODE 0

#define GET_PTR(addr) (&rdram[(addr) & 0x1FFFFF])

#define MEM_W(offset, base) (*(uint32_t*)GET_PTR((base) + (offset)))
#define MEM_H(offset, base) (*(uint16_t*)GET_PTR((base) + (offset)))
#define MEM_HU(offset, base) (*(uint16_t*)GET_PTR((base) + (offset)))
#define MEM_B(offset, base) (*(uint8_t*)GET_PTR((base) + (offset)))
#define MEM_BU(offset, base) (*(uint8_t*)GET_PTR((base) + (offset)))

#define MEM_HS(offset, base) ((int32_t)(int16_t)(*(uint16_t*)GET_PTR((base) + (offset))))
#define MEM_BS(offset, base) ((int32_t)(int8_t)(*(uint8_t*)GET_PTR((base) + (offset))))

#define WRITE_W(addr, val) (*(uint32_t*)GET_PTR(addr) = (val))
#define WRITE_H(addr, val) (*(uint16_t*)GET_PTR(addr) = (val))
#define WRITE_B(addr, val) (*(uint8_t*)GET_PTR(addr) = (val))

// Математика
#define ADD32(a, b) ((uint32_t)((int32_t)(a) + (int32_t)(b)))
#define SUB32(a, b) ((uint32_t)((int32_t)(a) - (int32_t)(b)))

#define S32(val) ((int32_t)(val))
#define S64(val) ((int64_t)(val))
#define S16(val) ((int16_t)(val))
#define S8(val) ((int8_t)(val))
#define SIGNED(val) ((int32_t)(val))

#define U32(val) ((uint32_t)(val))
#define U64(val) ((uint64_t)(val))
#define U16(val) ((uint16_t)(val))
#define U8(val)  ((uint8_t)(val))
// Контекст процессора MIPS с именованными регистрами
typedef struct recomp_context
{
    // Основные регистры (GPR)
    uint32_t r0;  // Всегда 0
    uint32_t r1;  // at
    uint32_t r2;  // v0
    uint32_t r3;  // v1
    uint32_t r4;  // a0
    uint32_t r5;  // a1
    uint32_t r6;  // a2
    uint32_t r7;  // a3
    uint32_t r8;  // t0
    uint32_t r9;  // t1
    uint32_t r10; // t2
    uint32_t r11; // t3
    uint32_t r12; // t4
    uint32_t r13; // t5
    uint32_t r14; // t6
    uint32_t r15; // t7
    uint32_t r16; // s0
    uint32_t r17; // s1
    uint32_t r18; // s2
    uint32_t r19; // s3
    uint32_t r20; // s4
    uint32_t r21; // s5
    uint32_t r22; // s6
    uint32_t r23; // s7
    uint32_t r24; // t8
    uint32_t r25; // t9
    uint32_t r26; // k0
    uint32_t r27; // k1
    uint32_t r28; // gp
    uint32_t r29; // sp (Stack Pointer)
    uint32_t r30; // fp
    uint32_t r31; // ra (Return Address)

    uint32_t lo;
    uint32_t hi;
    uint32_t pc;

    // Регистры GTE
    uint32_t cp2d[32];
    uint32_t cp2c[32];

    uint32_t cop0_status;

} recomp_context;

// 4. Тип для функций (используем псевдоним напрямую)
typedef void (*recomp_func_t)(uint8_t* rdram, recomp_context* ctx);
