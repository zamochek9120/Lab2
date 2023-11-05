#pragma once
#include <windows.h>
#include <omp.h>
#include <windows.h>
#include <iostream>
#include <intrin.h>
#include <chrono>
const int size = 250;
const int totalElements = size * size;
int8_t computeSumOfAbsoluteValues(int8_t* y, int8_t* z, int n) {
    int8_t sum = 0;
    for (int i = 0; i < n; i++) {
        sum += std::abs(y[i]) + std::abs(z[i]);
    }
    return sum;
}
int16_t computeSumOfAbsoluteValues(int16_t* y, int16_t* z, int n) {
    int16_t sum = 0;
    for (int i = 0; i < n; i++) {
        sum += std::abs(y[i]) + std::abs(z[i]);
    }
    return sum;
}
int32_t computeSumOfAbsoluteValues(int32_t* y, int32_t* z, int n) {
    int32_t sum = 0;
    for (int i = 0; i < n; i++) {
        sum += std::abs(y[i]) + std::abs(z[i]);
    }
    return sum;
}
int64_t computeSumOfAbsoluteValues(int64_t* y, int64_t* z, int n) {
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
        sum += std::abs(y[i]) + std::abs(z[i]);
    }
    return sum;
}
float computeSumOfAbsoluteValues(float* y, float* z, int n) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        sum += std::abs(y[i]) + std::abs(z[i]);
    }
    return sum;
}
double computeSumOfAbsoluteValues(double* y, double* z, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += std::abs(y[i]) + std::abs(z[i]);
    }
    return sum;
}
void int8() {
    int8_t y[totalElements]; // Оголошуємо масив розміром 4096x4096
    int8_t z[totalElements];

    // Ініціалізуємо ваші масиви `y` і `z` за потребою

    auto start = std::chrono::high_resolution_clock::now(); // Початок вимірювання часу

    int8_t result = computeSumOfAbsoluteValues(y, z, totalElements);

    auto finish = std::chrono::high_resolution_clock::now(); // Завершення вимірювання часу

    std::chrono::duration<double> elapsed = finish - start; // Обчислюємо час виконання в секундах

    std::cout << "Sum of absolute values: " << static_cast<int>(result) << std::endl;
    std::cout << "Time elapsed for int8:  " << elapsed.count() << " second." << std::endl;

}
void int16() {
    int16_t y[totalElements]; // Оголошуємо масив розміром 4096x4096
    int16_t z[totalElements];

    // Ініціалізуємо ваші масиви `y` і `z` за потребою

    auto start = std::chrono::high_resolution_clock::now(); // Початок вимірювання часу

    int16_t result = computeSumOfAbsoluteValues(y, z, totalElements);

    auto finish = std::chrono::high_resolution_clock::now(); // Завершення вимірювання часу

    std::chrono::duration<double> elapsed = finish - start; // Обчислюємо час виконання в секундах

    std::cout << "Sum of absolute values: " << static_cast<int>(result) << std::endl;
    std::cout << "Time elapsed for int16: " << elapsed.count() << " second." << std::endl;
}
void int32() {
    int32_t y[totalElements]; // Оголошуємо масив розміром 4096x4096
    int32_t z[totalElements];

    // Ініціалізуємо ваші масиви `y` і `z` за потребою

    auto start = std::chrono::high_resolution_clock::now(); // Початок вимірювання часу

    int32_t result = computeSumOfAbsoluteValues(y, z, totalElements);

    auto finish = std::chrono::high_resolution_clock::now(); // Завершення вимірювання часу

    std::chrono::duration<double> elapsed = finish - start; // Обчислюємо час виконання в секундах

    std::cout << "Sum of absolute values: " << result << std::endl;
    std::cout << "Time elapsed for int32: " << elapsed.count() << " seconds." << std::endl;
}
void int64() {
    int64_t y[totalElements]; // Оголошуємо масив розміром 4096x4096
    int64_t z[totalElements];

    // Ініціалізуємо ваші масиви `y` і `z` за потребою

    auto start = std::chrono::high_resolution_clock::now(); // Початок вимірювання часу

    int64_t result = computeSumOfAbsoluteValues(y, z, totalElements);

    auto finish = std::chrono::high_resolution_clock::now(); // Завершення вимірювання часу

    std::chrono::duration<double> elapsed = finish - start; // Обчислюємо час виконання в секундах

    std::cout << "Sum of absolute values: " << result << std::endl;
    std::cout << "Time elapsed for int64: " << elapsed.count() << " seconds." << std::endl;
}
void f() {
    float y[totalElements]; // Оголошуємо масив розміром 4096x4096
    float z[totalElements];

    // Ініціалізуємо ваші масиви `y` і `z` за потребою

    auto start = std::chrono::high_resolution_clock::now(); // Початок вимірювання часу

    float result = computeSumOfAbsoluteValues(y, z, totalElements);

    auto finish = std::chrono::high_resolution_clock::now(); // Завершення вимірювання часу

    std::chrono::duration<double> elapsed = finish - start; // Обчислюємо час виконання в секундах

    std::cout << "Sum of absolute values: " << result << std::endl;
    std::cout << "Time elapsed for rloat: " << elapsed.count() << " seconds." << std::endl;
}
void d() {
    double y[totalElements]; // Оголошуємо масив розміром 4096x4096
    double z[totalElements];

    // Ініціалізуємо ваші масиви `y` і `z` за потребою

    auto start = std::chrono::high_resolution_clock::now(); // Початок вимірювання часу

    double result = computeSumOfAbsoluteValues(y, z, totalElements);

    auto finish = std::chrono::high_resolution_clock::now(); // Завершення вимірювання часу

    std::chrono::duration<double> elapsed = finish - start; // Обчислюємо час виконання в секундах

    std::cout << "Sum of absolute values: " << result << std::endl;
    std::cout << "Time elapsed for double: " << elapsed.count() << " seconds." << std::endl;
}
void test() {
    
    int8(); // Виклик вашої функції
    int16(); // Виклик вашої функції
    int32();
    int64();
    f();
    d();
}