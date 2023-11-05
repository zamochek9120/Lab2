#pragma once
#include <windows.h>
#include <omp.h>
#include <windows.h>
#include <iostream>
#include <intrin.h>
typedef enum {
	INTEL, AMD, OTHER
} ProcessorType;
ProcessorType DefineProcessorType() {
	ProcessorType Type = OTHER;
	CHAR INTELName[13] = "GenuineIntel";
	CHAR AMDName[13] = "AuthenticAMD";
	CHAR ProcessorName[13];
	ProcessorName[12] = 0;
	INT Regs[4];
	__cpuid(Regs, 0);
	memcpy(ProcessorName, &Regs[1], 4);
	memcpy(ProcessorName + 4, &Regs[3], 4);
	memcpy(ProcessorName + 8, &Regs[2], 4);
	if (memcmp(INTELName, ProcessorName, 12) == 0)
		Type = INTEL;
	else
	{
		if (memcmp(AMDName, ProcessorName, 12) == 0)
			Type = AMD;

	}
	return Type;
}
void Part1() {
	ProcessorType Type;
	Type = DefineProcessorType();
	switch (Type)
	{
	case INTEL:
		printf(("ProcessorType: INTEL\n")); break;
	case AMD:
		printf(("ProcessorType: AMD\n")); break;
	case OTHER:
		printf(("ProcessorType: OTHER\n")); break;

	}
}
typedef enum {
	SSESUPPORT, SSE2SUPPORT, SSE3SUPPORT, SSSE3SUPPORT,
	SSE41SUPPORT, SSE42SUPPORT, AVXSUPPORT, AVX2SUPPORT,
	AVX512SUPPORT
};
unsigned MaxFun(unsigned* ExtFun) {
	int regs[4];
	__cpuidex(regs, 0, 0);
	int res = regs[0];
	__cpuidex(regs, 0x80000000, 0);
	if (ExtFun) *ExtFun = regs[0];
	return res;
}
bool check_properties(uint32_t fun, uint32_t index, uint32_t bit) {
	uint32_t r[4];
	uint32_t mask = 1 << bit;
	__cpuidex((int*)r, fun, 0);
	return (r[index] & mask) == mask;
}
unsigned SIMDSupport() {
	bool AVX512, AVX, SSE, b;
	unsigned maska = 0;
	unsigned max_fun = MaxFun(0);
	// Перевірка можливості використання команд XSAVE, XRESTOR, XGETBV:
	if (max_fun >= 1) {


			b = check_properties(1, 2, 26) && check_properties(1, 2, 27);
		if (b) {
			unsigned long long res = _xgetbv(0);
			int flags1 = 7 + (7 << 5), flags2 = 7, flags3 = 3;
			AVX512 = (res & flags1) == flags1;
			AVX = (res & flags2) == flags2;
			SSE = (res & flags3) == flags3;
			if (max_fun >= 7 && AVX512) {
				// AVX512
				b = check_properties(7, 1, 16);
				if (b) maska |= (1 << AVX512SUPPORT);
			}
			if (AVX) {
				if (max_fun >= 7) {
					// AVX2
					b = check_properties(7, 1, 5);
					if (b) maska |= 1 << AVX2SUPPORT;
				}
				if (max_fun >= 1) {
					// AVX
					b = check_properties(1, 2, 28);
					if (b) maska |= 1 << AVXSUPPORT;
				}
			}
			if (SSE) {
				b = check_properties(1, 2, 20);
				if (b) maska |= 1 << SSE42SUPPORT;
				b = check_properties(1, 2, 19);
				if (b) maska |= 1 << SSE41SUPPORT;
				b = check_properties(1, 2, 9);
				if (b) maska |= 1 << SSSE3SUPPORT;
				b = check_properties(1, 2, 0);
				if (b) maska |= 1 << SSE3SUPPORT;
				b = check_properties(1, 3, 26);

					if (b) maska |= 1 << SSE2SUPPORT;
				b = check_properties(1, 3, 25);
				if (b) maska |= 1 << SSESUPPORT;
			}
		}
	}
	return maska;
}
int Pz2_Part5() {
	unsigned supportedSIMD = SIMDSupport();

	if (supportedSIMD & (1 << SSESUPPORT)) {
		std::cout << "SSE is supported." << std::endl;
	}

	if (supportedSIMD & (1 << SSE2SUPPORT)) {
		std::cout << "SSE2 is supported." << std::endl;
	}

	if (supportedSIMD & (1 << SSE3SUPPORT)) {
		std::cout << "SSE3 is supported." << std::endl;
	}

	if (supportedSIMD & (1 << SSSE3SUPPORT)) {
		std::cout << "SSSE3 is supported." << std::endl;
	}

	if (supportedSIMD & (1 << SSE41SUPPORT)) {
		std::cout << "SSE4.1 is supported." << std::endl;
	}

	if (supportedSIMD & (1 << SSE42SUPPORT)) {
		std::cout << "SSE4.2 is supported." << std::endl;
	}

	if (supportedSIMD & (1 << AVXSUPPORT)) {
		std::cout << "AVX is supported." << std::endl;
	}

	if (supportedSIMD & (1 << AVX2SUPPORT)) {
		std::cout << "AVX2 is supported." << std::endl;
	}

	if (supportedSIMD & (1 << AVX512SUPPORT)) {
		std::cout << "AVX-512 is supported." << std::endl;
	}

	return 0;
}
