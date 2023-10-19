#include <stdio.h>
#include <string.h>

void removeName(char nomes[][10], int *numNomes, const char nomeParaRemover[]) {
    int i;
    for (i = 0; i < *numNomes; i++) {
        if (strcmp(nomes[i], nomeParaRemover) == 0) {
            // Quando encontramos o nome para remover, deslocamos os elementos subsequentes para preencher o espaço
            for (int j = i; j < *numNomes - 1; j++) {
                strcpy(nomes[j], nomes[j + 1]);
            }
            (*numNomes)--;
            break;  // Uma vez que o nome foi encontrado e removido, podemos sair do loop
        }
    }
}

int main() {
    char nomes[][10] = {"lucas", "rita", "josé"};
    int numNomes = 3;

    printf("Nomes atuais:\n");
    for (int i = 0; i < numNomes; i++) {
        printf("%s\n", nomes[i]);
    }

    char nomeParaRemover[] = "rita";
    removeName(nomes, &numNomes, nomeParaRemover);

    printf("\nNomes após a remoção:\n");
    for (int i = 0; i < numNomes; i++) {
        printf("%s\n", nomes[i]);
    }

    return 0;
}
