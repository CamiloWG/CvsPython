#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

unsigned long long factorial_iterativo(int n) {
    unsigned long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

unsigned long long factorial_recursivo(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial_recursivo(n - 1);
}

int main() {
    int n;
    printf("Ingrese un numero para calcular su factorial: ");
    scanf("%d", &n);

    LARGE_INTEGER frecuencia;
    LARGE_INTEGER inicio;
    LARGE_INTEGER fin;

    QueryPerformanceFrequency(&frecuencia);
    QueryPerformanceCounter(&inicio);
    unsigned long long factorial_iter = factorial_iterativo(n);
    QueryPerformanceCounter(&fin);

    double tiempo_iterativo = (double)(fin.QuadPart - inicio.QuadPart) * 1000000 / frecuencia.QuadPart;

    QueryPerformanceCounter(&inicio);
    unsigned long long factorial_rec = factorial_recursivo(n);
    QueryPerformanceCounter(&fin);

    double tiempo_recursivo = (double)(fin.QuadPart - inicio.QuadPart) * 1000000 / frecuencia.QuadPart;

    printf("Factorial calculado de manera iterativa: %llu\n", factorial_iter);
    printf("Tiempo de ejecucion en microsegundos (iterativo): %.6f\n", tiempo_iterativo);
    printf("Factorial calculado de manera recursiva: %llu\n", factorial_rec);
    printf("Tiempo de ejecucion en microsegundos (recursivo): %.6f\n", tiempo_recursivo);

    return 0;
}
