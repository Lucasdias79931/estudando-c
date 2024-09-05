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

// Busca binária. Usar somente se o vetor estiver ordenado
void removeNameB(char nomes[][10], int len, const char nomeParaRemover[]) {
    if(len < 1) return;

    int esquerda = 0;
    int direita = len - 1;

    while(esquerda <= direita){
        int mid = (esquerda + direita) / 2;

        if(strcmp(nomes[mid], nomeParaRemover) == 0){
            strcpy(nomes[mid], "");  // Limpa a string
            return;
        } else if(strcmp(nomes[mid], nomeParaRemover) < 0){
            esquerda = mid + 1;
        } else {
            direita = mid - 1;
        }
    }

    return;
}


int main() {
    char nomes[][10] = {"xela", "bernado","claudio","aline","ziery"};
 
    int size = sizeof(nomes) / sizeof(nomes[0]);

   
   

    printf("Nomes atuais:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", nomes[i]);
    }

    char nomeParaRemover[] = "xela";
    removeName(nomes, &size, nomeParaRemover);

    printf("\nNomes após a remoção:\n");
    for (int i = 0; i < size; i++) {
       if(strcmp(nomes[i],"") != 0) printf("%s\n", nomes[i]);
    }

    return 0;
}
