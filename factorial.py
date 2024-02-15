import time

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

# Pedir al usuario el número para calcular su factorial
n = int(input("Ingrese un número para calcular su factorial: "))

# Calcular factorial de forma iterativa y medir tiempo
inicio_iterativo = time.time()
res_iterativo = factorial_iterativo(n)
fin_iterativo = time.time()
tiempo_iterativo = (fin_iterativo - inicio_iterativo) / 1000

# Calcular factorial de forma recursiva y medir tiempo
inicio_recursivo = time.time()
res_recursivo = factorial_recursivo(n)
fin_recursivo = time.time()
tiempo_recursivo = (fin_recursivo - inicio_recursivo) / 1000

print("Resultado del factorial de", n, "igual a: Recursivo =", res_recursivo, " Iterativo:", res_iterativo)
print(f"Factorial de {n} calculado de forma iterativa en {tiempo_iterativo:.9f} milisegundos.")
print(f"Factorial de {n} calculado de forma recursiva en {tiempo_recursivo:.9f} milisegundos.")
