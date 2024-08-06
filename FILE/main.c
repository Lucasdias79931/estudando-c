#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(const char *fileName, char *data) {
    char *newFileName = malloc(strlen(fileName) + 5); // Aloca memória corretamente
    strcpy(newFileName, fileName); // Copia o nome do arquivo
    strcat(newFileName, ".txt"); // Adiciona a extensão

    FILE *arquivo = fopen(newFileName, "a"); // Abre o arquivo para escrita
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    // Aqui você pode escrever dados no arquivo
    fprintf(arquivo,"%s\n",data);
   

    fclose(arquivo); // Fecha o arquivo
    free(newFileName); // Libera a memória alocada
}

int main() {
   
    push("test","lucas dos santos dias");
    push("test","lucas dos santos dias");
    push("test","lucas dos santos dias");
    push("test","lucas dos santos dias");
    push("test","lucas dos santos dias");

    return 0;
}
