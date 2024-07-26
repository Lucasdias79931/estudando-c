#include <stdio.h>
#include <stdlib.h>

void putS(char *s) {
    printf("\n");
    for (int t = 0; s[t] != '\0'; t++) {
        putchar(s[t]);
    }
    printf("\n");
}

void putstr(char *s) {
    printf("\n");
    while (*s) {
        putchar(*s++);
    }
    printf("\n");
}

void imprimeNumeros(int *numeros, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("[%i]", numeros[i]);
    }
    printf("\n");
}

void imprime(int *numeros, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("[%i]", *(numeros + i));
    }
    printf("\n");
}

int main() {
    char matrix[] = "lucas dos santos dias";
    int numeros[] = {0, 1, 2, 3, 4, 5};
    int size = sizeof(numeros) / sizeof(int);

    putS(matrix);
    putstr(matrix);
    imprimeNumeros(numeros, size);
    imprime(numeros, size);

    return 0;
}
