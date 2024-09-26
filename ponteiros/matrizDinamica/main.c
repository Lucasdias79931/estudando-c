#include <stdio.h>
#include <stdlib.h>
#include <string.h>




// Adiciona um titulo ao array de titulos
void addTitle(char ***titles, int *lenTitles, char *newTitle) {
    int sizeNewTitle = strlen(newTitle) + 1;

    if (*lenTitles != 0) {
        *titles = realloc(*titles, sizeof(char*) * (*lenTitles + 1));
        (*lenTitles)++;
        (*titles)[*lenTitles - 1] = (char *)malloc(sizeof(char) * sizeNewTitle );
        strcpy((*titles)[*lenTitles - 1], newTitle);
    } else {
        *titles = malloc(sizeof(char*));
        (*titles)[0] = (char *)malloc(sizeof(char) * sizeNewTitle );
        (*lenTitles)++;
        strcpy((*titles)[0], newTitle);
    }
}

// passa o nome do arquivo, a matriz de titulos e o tamanho da matriz
void pullFromFile(char *File, char ***Title, int *lenTitle){
    //cria um ponteiro para um arquivo
    FILE *file;
    
    //contatena o nome passado pelo parametro com '.txt' e escreve no vetor de char 'nameFile'
    char nameFile[100];
    strcpy(nameFile, File);
    strcat(nameFile,".txt");


    //abre o arquivo no modo leitura
    file = fopen(nameFile, "r");

    if(file != NULL){
        //   cria vetor com 50 caractere e em seguida umsa fgets para ler a primeira linha do arquivo
        char livro[50];
        fgets(livro,sizeof(livro),file);
        
        //atribui linha ao vetor 'livro' enquanto estiver conteúdo no arquiv
        while (fgets(livro,sizeof(livro),file))
        {

            //add a linha na matriz
            addTitle(Title,lenTitle,livro);
        }
        
    }else{
        perror("\nErro ao abrir o arquivo.\n");
    }

    //fecha o arquivo
    fclose(file);
}

int main() {
    char **titles = NULL; //matriz dinamica
    int lenTitles = 0;

  

    pullFromFile("livros_com_quantidades",&titles,&lenTitles);

    for (int i = 0; i < lenTitles; i++) {
        printf("\n%s",titles[i]);
        
    }


    printf("\n");

    
    
    
    

    return 0;
}





