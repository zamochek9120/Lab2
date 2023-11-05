// Pz1PaP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <omp.h>
#include "Part5.h"
#include "Pz2.h"
#include "Test.h"
#include "Part6.h"

#include "Part8.h"
void Part3() {
    Pz pz;
    int a[Pz::N][Pz::N]; // Створення двовимірного масиву розміром N x N
    int b[Pz::N][Pz::N]; // Створення двовимірного масиву розміром N x N
    int c[Pz::N][Pz::N];
    for (int i = 0; i < Pz::N; i++) {
        for (int j = 0; j < Pz::N; j++) {
            a[i][j] = rand() % 5;
            b[i][j] = rand() % 5;
        }
    }
    double time_min, time_cur;
    {time_min = FLT_MAX;
    for (int i = 0; i < 5; i++) {
        time_cur = omp_get_wtime();
        Pz::mul_ijk(c, a, b);
        // Pz::mul_ikj(c, a, b);
        time_cur = omp_get_wtime() - time_cur;
        if (time_cur < time_min)
            time_min = time_cur;

    }
    printf("mul_ijk : c[0][0] = %d c[N-1][N-1] = %d time = %lg\n",
        c[0][0], c[Pz::N - 1][Pz::N - 1], time_min);}
    for (int i = 0; i < 5; i++) {
        time_cur = omp_get_wtime();
        // Pz::mul_ijk(c, a, b);
        Pz::mul_ikj(c, a, b);
        time_cur = omp_get_wtime() - time_cur;
        if (time_cur < time_min)
            time_min = time_cur;

    }
    printf("mul_ikj : c[0][0] = %d c[N-1][N-1] = %d time = %lg\n",
        c[0][0], c[Pz::N - 1][Pz::N - 1], time_min);
    for (int i = 0; i < 5; i++) {
        time_cur = omp_get_wtime();

        Pz::mul_jik(c, a, b);
        time_cur = omp_get_wtime() - time_cur;
        if (time_cur < time_min)
            time_min = time_cur;

    }
    printf("mul_jik : c[0][0] = %d c[N-1][N-1] = %d time = %lg\n",
        c[0][0], c[Pz::N - 1][Pz::N - 1], time_min);
    for (int i = 0; i < 5; i++) {
        time_cur = omp_get_wtime();

        Pz::mul_jki(c, a, b);
        time_cur = omp_get_wtime() - time_cur;
        if (time_cur < time_min)
            time_min = time_cur;

    }
    printf("mul_jki : c[0][0] = %d c[N-1][N-1] = %d time = %lg\n",
        c[0][0], c[Pz::N - 1][Pz::N - 1], time_min);
    for (int i = 0; i < 5; i++) {
        time_cur = omp_get_wtime();

        Pz::mul_kij(c, a, b);
        time_cur = omp_get_wtime() - time_cur;
        if (time_cur < time_min)
            time_min = time_cur;

    }
    printf("mul_kij : c[0][0] = %d c[N-1][N-1] = %d time = %lg\n",
        c[0][0], c[Pz::N - 1][Pz::N - 1], time_min);
    for (int i = 0; i < 5; i++) {
        time_cur = omp_get_wtime();

        Pz::mul_kji(c, a, b);
        time_cur = omp_get_wtime() - time_cur;
        if (time_cur < time_min)
            time_min = time_cur;

    }
    printf("mul_kji : c[0][0] = %d c[N-1][N-1] = %d time = %lg\n",
        c[0][0], c[Pz::N - 1][Pz::N - 1], time_min);
}
int main()
{
 //   Part3();
   // Part5();
    //Part1();
    //Pz2_Part5();
    //test();
    //Part7();
   // Part8();
  //  Part9();
   // Part6();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
