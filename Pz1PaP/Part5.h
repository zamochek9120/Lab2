#include <omp.h>
#include <windows.h>
#include <iostream>
#include <intrin.h>
class Pz {
public:
    static const int N = 256;
    static void mul_ijk(int c[][N], int a[][N], int b[][N])
    {
        int i, j, k;
        memset(c, 0, N * N * sizeof(int));
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                for (k = 0; k < N; k++)
                    c[i][k] += a[i][k] * b[k][j];

        }
    }
    static void mul_ikj(int c[][N], int a[][N], int b[][N])
    {
        int i, j, k;
        memset(c, 0, N * N * sizeof(int));
        for (i = 0; i < N; i++)
        {
            for (k = 0; k < N; k++)
                for (j = 0; j < N; j++)
                    c[i][k] += a[i][k] * b[k][j];

        }
    }
    static void mul_jik(int c[][N], int a[][N], int b[][N])
    {
        int i, j, k;
        memset(c, 0, N * N * sizeof(int));
        for (j = 0; j < N; j++)
        {
            for (i = 0; i < N; i++)
                for (k = 0; k < N; k++)
                    c[i][k] += a[i][k] * b[k][j];

        }
    }
    static void mul_jki(int c[][N], int a[][N], int b[][N])
    {
        int i, j, k;
        memset(c, 0, N * N * sizeof(int));
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < N; k++)
                for (i = 0; i < N; i++)
                    c[i][k] += a[i][k] * b[k][j];

        }
    }
    static void mul_kij(int c[][N], int a[][N], int b[][N])
    {
        int i, j, k;
        memset(c, 0, N * N * sizeof(int));
        for (k = 0; k < N; k++)
        {
            for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    c[i][k] += a[i][k] * b[k][j];

        }
    }
    static void mul_kji(int c[][N], int a[][N], int b[][N])
    {
        int i, j, k;
        memset(c, 0, N * N * sizeof(int));
        for (k = 0; k < N; k++)
        {
            for (j = 0; j < N;j++)
                for (i = 0; i < N; i++)
                    c[i][k] += a[i][k] * b[k][j];

        }
    }
};
int Part5() {
    double time_omp = 0.0;
    LONGLONG ll_min = LLONG_MAX;

    for (int i = 0; i < 500; i++) {
        int r[4];
        __cpuid(r, 0);
        LONGLONG ll_cur = __rdtsc();
        double start_omp = omp_get_wtime();
        // Операції, які ви вимірюєте
        __cpuid(r, 0);
        ll_cur = __rdtsc() - ll_cur;
        double end_omp = omp_get_wtime();

        time_omp += (end_omp - start_omp);

        if (ll_cur < ll_min) {
            ll_min = ll_cur;
        }
    }

    printf("omp_get_wtime : ll_cur = %I64d time = %lg\n", ll_min, time_omp);

    DWORD tick_min = 0xFFFFFFFF;
    LONGLONG ll_cur = 0;

    for (int i = 0; i < 500; i++) {
        int r[4];
        __cpuid(r, 0);
        ll_cur = __rdtsc();
        DWORD tick_cur = GetTickCount();
        // Операції, які ви вимірюєте
        __cpuid(r, 0);
        ll_cur = __rdtsc() - ll_cur;

        if (ll_cur < ll_min) {
            ll_min = ll_cur;
        }

        if (tick_cur < tick_min) {
            tick_min = tick_cur;
        }
    }

    printf("GetTickCount : tick_min = %d time = %I64d\n", tick_min, ll_min);

    return 0;
}
int Part6() {
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
    int count = 0, s = 0;
    DWORD tick_cur = GetTickCount();
    while (GetTickCount() - tick_cur < 2000)
    {
        count++;
        std::cout << "F\n";
        Pz::mul_ijk(c, a, b);
    }
    printf("mul_ijk : c[0][0] = %d c[99][99], count = %d\n", c[99][99], count);
    return -1;
}
