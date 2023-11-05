#pragma once
#include <iostream>
#include <immintrin.h> // Для використання SIMD інструкцій

const int complexArraySize = 4096 * 4096; // Розмір масиву комплексних чисел

// Структура, що представляє комплексне число (реальна та уявна частини)
struct Complex {
    float real;
    float imag;
};
void multiplyComplexNumbers(
    const Complex* y, const Complex* z, Complex* x, int size) {
    for (int i = 0; i < size; ++i) {
        x[i].real = y[i].real * z[i].real - y[i].imag * z[i].imag;
        x[i].imag = y[i].real * z[i].imag + y[i].imag * z[i].real;
    }
}
void multiplyComplexNumbersSIMD(
    Complex* result, const Complex* a, const Complex* b, int size) {
    for (int i = 0; i < size; i += 4) {
        __m128 a_real = _mm_loadu_ps(&a[i].real);
        __m128 a_imag = _mm_loadu_ps(&a[i].imag);
        __m128 b_real = _mm_loadu_ps(&b[i].real);
        __m128 b_imag = _mm_loadu_ps(&b[i].imag);

        // Виконуємо множення для реальних і уявних частин окремо
        __m128 result_real = _mm_sub_ps(_mm_mul_ps(a_real, b_real), _mm_mul_ps(a_imag, b_imag));
        __m128 result_imag = _mm_add_ps(_mm_mul_ps(a_real, b_imag), _mm_mul_ps(a_imag, b_real));

        // Зберігаємо результат у масив
        _mm_storeu_ps(&result[i].real, result_real);
        _mm_storeu_ps(&result[i].imag, result_imag);
    }
}

int Part8() {
    Complex* a = new Complex[complexArraySize];
    Complex* b = new Complex[complexArraySize];
    Complex* result = new Complex[complexArraySize];

    // Заповнюємо a та b даними за потреби

    // Вимірюємо час виконання обчислень з використанням SIMD
    clock_t startSIMD = clock();
    multiplyComplexNumbersSIMD(result, a, b, complexArraySize);
    clock_t endSIMD = clock();
    double cpu_time_used_SIMD = static_cast<double>(endSIMD - startSIMD) / CLOCKS_PER_SEC;
    std::cout << "Time with SIMD: " << cpu_time_used_SIMD << " seconds" << std::endl;

    // Вимірюємо час виконання обчислень без використання SIMD
    clock_t startNoSIMD = clock();
    multiplyComplexNumbers(result, a, b, complexArraySize);
    clock_t endNoSIMD = clock();
    double cpu_time_used_NoSIMD = static_cast<double>(endNoSIMD - startNoSIMD) / CLOCKS_PER_SEC;
    std::cout << "Time without SIMD: " << cpu_time_used_NoSIMD << " seconds" << std::endl;

    delete[] a;
    delete[] b;
    delete[] result;

    return 0;
}

// Функція для зрушення даних довжиною 512 біт на 1 біт з SIMD
const int arraySizeS = 512; // Розмір масиву
const int shiftAmount = 1; // Кількість бітів для зрушення

void shiftDataSIMD(__m512i* data, int size, int shift) {
    __m512i shiftMask = _mm512_set1_epi64(1 << shift);

    for (int i = 0; i < size; ++i) {
        data[i] = _mm512_srlv_epi64(data[i], shiftMask);
    }
}
void shiftDataWithoutSIMD(unsigned long long* data, int size, int shift) {
    for (int i = 0; i < size; ++i) {
        data[i] >>= shift;
    }
}

int Part9WithoutSIMD() {
    unsigned long long data[arraySizeS];

    // Заповнюємо масив `data` за потребою

    auto start = std::chrono::high_resolution_clock::now();
    shiftDataWithoutSIMD(data, arraySizeS, shiftAmount);
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Time without SIMD: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}

int Part9() {
    Part9WithoutSIMD();
    __m512i data[arraySizeS];

    // Заповнюємо масив `data` за потребою

    auto start = std::chrono::high_resolution_clock::now();
    shiftDataSIMD(data, arraySizeS, shiftAmount);
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Time with SIMD: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
