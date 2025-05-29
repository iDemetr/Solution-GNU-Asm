#include <stdio.h>
#ifdef _MSC_VER
#include <intrin.h>
#else
#include <cpuid.h>
#endif

int check_sse() {
    unsigned int eax, ebx, ecx, edx;

#ifdef _MSC_VER
    int cpuInfo[4];
    __cpuid(cpuInfo, 1);
    ecx = cpuInfo[2];
    edx = cpuInfo[3];
#else
    __cpuid(1, eax, ebx, ecx, edx);
#endif

    // SSE поддерживается, если установлен бит 25 регистра EDX
    return (edx & (1 << 25)) != 0;
}

int check_avx() {
    unsigned int eax, ebx, ecx, edx;

#ifdef _MSC_VER
    int cpuInfo[4];
    __cpuid(cpuInfo, 1);
    ecx = cpuInfo[2];
#else
    __cpuid(1, eax, ebx, ecx, edx);
#endif

    // Проверяем, что бит 28 регистра ECX установлен (AVX поддерживается)
    // и что ОС поддерживает XSAVE/XRESTORE (бит 27 ECX)
    if ((ecx & (1 << 28)) == 0 || (ecx & (1 << 27)) == 0) {
        return 0;
    }

    // Проверяем, что ОС действительно поддерживает использование AVX (XGETBV)
#ifdef _MSC_VER
    unsigned long long xcrFeatureMask = _xgetbv(0);
#else
    unsigned int xcrLow, xcrHigh;
    __asm__ volatile (
        "xgetbv"
        : "=a" (xcrLow), "=d" (xcrHigh)
        : "c" (0)
    );
    unsigned long long xcrFeatureMask = ((unsigned long long)xcrHigh << 32) | xcrLow;
#endif

    // Проверяем, что XMM и YMM state поддерживаются ОС (биты 1 и 2)
    return (xcrFeatureMask & 0x6) == 0x6;
}

int checkAVXorSSE() {
    if (check_sse()) {
        printf("SSE поддерживается\n");
    } else {
        printf("SSE не поддерживается\n");
    }

    if (check_avx()) {
        printf("AVX поддерживается\n");
    } else {
        printf("AVX не поддерживается\n");
    }

    return 0;
}