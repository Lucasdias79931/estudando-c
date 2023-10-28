#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void table(int p[4][10]);
void show(int p[4][10]);

int main() {
    int (*p)[10];  // Declara um ponteiro para uma matriz 4x10

    p = malloc(4 * sizeof(int[10]));

    if (!p) {
        printf("\nFalha na solicitação de memória");
        return 1;
    }

    table(p);
    show(p);

    free(p); // Libera a memória alocada

    return 0;
}

void show(int p[4][10]) {
    printf("\n%10s %10s %10s %10s\n", "N", "N²", "N³", "N⁴");
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 4; i++) {
            printf("%10d ", p[i][j]);
        }
        printf("\n");
    }
}

void table(int p[4][10]) {
    for (int j = 0; j < 10; j++) {
        int N = j + 1;
        for (int i = 0; i < 4; i++) {
            p[i][j] = pwr(N, i + 1);
        }
    }
}

int pwr(int a, int b) {
    int t = 1;
    for (; b; b--) t = t * a;
    return t;
}
