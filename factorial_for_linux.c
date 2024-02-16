#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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

unsigned long long obtener_tiempo_us() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (unsigned long long)(tv.tv_sec) * 1000000 + (unsigned long long)(tv.tv_usec);
}

int main() {
    int n;
    printf("Ingrese un numero para calcular su factorial: ");
    scanf("%d", &n);

    unsigned long long inicio = obtener_tiempo_us();
    unsigned long long factorial_iter = factorial_iterativo(n);
    unsigned long long fin = obtener_tiempo_us();

    double tiempo_iterativo = (double)(fin - inicio);

    inicio = obtener_tiempo_us();
    unsigned long long factorial_rec = factorial_recursivo(n);
    fin = obtener_tiempo_us();

    double tiempo_recursivo = (double)(fin - inicio);

    printf("Factorial calculado de manera iterativa: %llu\n", factorial_iter);
    printf("Tiempo de ejecucion en microsegundos (iterativo): %.6f\n", tiempo_iterativo);
    printf("Factorial calculado de manera recursiva: %llu\n", factorial_rec);
    printf("Tiempo de ejecucion en microsegundos (recursivo): %.6f\n", tiempo_recursivo);

    return 0;
}
