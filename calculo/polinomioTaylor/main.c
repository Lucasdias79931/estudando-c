#include <stdio.h>
#include <math.h>

int fatorial(int x) {
    if (x < 2) {
        return 1;
    }
    return x * fatorial(x - 1);
}

int main() {
    double X = 9.12;
    int a = 9;  // Ponto de expansão

    // Valor da função e das derivadas em X = 9
    double primitiva = sqrt(a);  // f(a) = sqrt(9)
    double derivada1 = 1 / (2 * sqrt(a));  // f'(a)
    double derivada2 = -1 / (4 * pow(a, 1.5));  // f''(a)
    double derivada3 = 3 / (8 * pow(a, 2.5));  // f'''(a)
    double derivada4 = -15 / (16 * pow(a, 3.5));  // f''''(a)

    // Polinômio de Taylor até a quarta ordem
    double resp = primitiva
                  + derivada1 * (X - a)
                  + (derivada2 * pow(X - a, 2)) / fatorial(2)
                  + (derivada3 * pow(X - a, 3)) / fatorial(3)
                  + (derivada4 * pow(X - a, 4)) / fatorial(4);

    printf("%f\n", resp);

    return 0;
}