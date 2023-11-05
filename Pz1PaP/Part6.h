#pragma once
#include <windows.h>
#include <omp.h>
#include <iostream>
#include <intrin.h>
#include <cmath>
#include <chrono>
void computeRoot(float* y, float* x, int n) {
    for (int i = 0; i < n; ++i) {
        x[i] = powf(y[i], 0.5);
    }
}
void computeRootDouble(double* y, double* x, int size) {
    for (int i = 0; i < size; ++i) {
        x[i] = std::pow(y[i], 0.5);
    }
}
void computeRootSIMD(float* y, float* x, int size) {
    for (int i = 0; i < size; i += 8) {
        __m256 y_values = _mm256_loadu_ps(&y[i]);
        __m256 result = _mm256_pow_ps(y_values, _mm256_set1_ps(0.5));
        _mm256_storeu_ps(&x[i], result);
    }
}
void computeRootDoubleSIMD(double* y, double* x, int size) {
    for (int i = 0; i < size; i += 4) {
        __m256d y_values = _mm256_loadu_pd(&y[i]);
        __m256d result = _mm256_pow_pd(y_values, _mm256_set1_pd(0.5));
        _mm256_storeu_pd(&x[i], result);
    }
}
const int arraySize = 4096 * 4096;

int Part7() {
    float* yFloat = new float[arraySize];
    float* xFloat = new float[arraySize];

    double* yDouble = new double[arraySize];
    double* xDouble = new double[arraySize];

    // Ініціалізація масивів з випадковими значеннями (просто для прикладу)
    for (int i = 0; i < arraySize; ++i) {
        yFloat[i] = static_cast<float>(rand()) / RAND_MAX; // Випадкові float
        yDouble[i] = static_cast<double>(rand()) / RAND_MAX; // Випадкові double
    }

    clock_t start, end;
    double cpu_time_used;

    // Без SIMD, float
    start = clock();
    computeRoot(yFloat, xFloat, arraySize);
    end = clock();
    cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time without SIMD (float): " << cpu_time_used << " seconds\n";

    // Без SIMD, double
    start = clock();
    computeRootDouble(yDouble, xDouble, arraySize);
    end = clock();
    cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time without SIMD (double): " << cpu_time_used << " seconds\n";

    // З SIMD, float
    start = clock();
    computeRootSIMD(yFloat, xFloat, arraySize);
    end = clock();
    cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time with SIMD (float): " << cpu_time_used << " seconds\n";

    // З SIMD, double
    start = clock();
    computeRootDoubleSIMD(yDouble, xDouble, arraySize);
    end = clock();
    cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time with SIMD (double): " << cpu_time_used << " seconds\n";

    delete[] yFloat;
    delete[] xFloat;
    delete[] yDouble;
    delete[] xDouble;

    return 0;
}




