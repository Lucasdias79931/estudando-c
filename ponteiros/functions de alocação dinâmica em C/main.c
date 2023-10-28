#include <stdio.h>
#include <stdlib.h>

void novaFraze(char *q, char **new) {
    int size = 0;
    while (*q) {
        size++;
        q++;
    }
    
    // Alocar memória para a nova string
    *new = (char *)malloc((size + 1) * sizeof(char));

    if (!(*new)) {
        printf("\nFalha na alocação");
        exit(1);
    }
    
    // Reinicializar q para copiar os caracteres novamente
    q -= size;

    // Copiar os caracteres da string original para a nova string
    int i = 0;
    while (*q) {
        (*new)[i] = *q;
        i++;
        q++;
    }
    (*new)[i] = '\0'; // Adicionar o caractere nulo ao final da nova string
    printf("\n tamanho do novo arrey: %d\n", i);
}

int main() {
    char *s;
    char *new;
    s = (char *)malloc(80 * sizeof(char)); // Alocar 80 bytes

    if (!s) {
        printf("\nFalha na alocação");
        exit(1);
    }

    printf("\nDigite:\n");

    fgets(s, 80, stdin); // Usar 80 como tamanho do buffer

    novaFraze(s, &new); // Passar um ponteiro para new

    free(s);
    

    

    free(new);

    return 0;
}
