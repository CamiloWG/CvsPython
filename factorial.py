import timeit

def factorial_iterativo(n):
    factorial = 1
    for i in range(1, n + 1):
        factorial *= i
    return factorial

def factorial_recursivo(n):
    if n == 0:
        return 1
    else:
        return n * factorial_recursivo(n - 1)

n = int(input("Ingrese un número para calcular su factorial: "))

tiempo_iterativo_segundos = timeit.timeit(lambda: factorial_iterativo(n), number=1)
tiempo_iterativo_microsegundos = tiempo_iterativo_segundos * 1e6 
res_iterativo = factorial_iterativo(n);

# Calcular factorial de forma recursiva y medir tiempo
tiempo_recursivo_segundos = timeit.timeit(lambda: factorial_iterativo(n), number=1)
tiempo_recursivo_microsegundos = tiempo_recursivo_segundos * 1e6  
res_recursivo = factorial_recursivo(n)

print("Resultado del factorial de", n, "igual a: Recursivo =", res_recursivo, " Iterativo:", res_iterativo)
print(f"Factorial de {n} calculado de forma iterativa en {tiempo_iterativo_microsegundos:.6f} microsegundos.")
print(f"Factorial de {n} calculado de forma recursiva en {tiempo_recursivo_microsegundos:.6f} microsegundos.")
