#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Adiciona um titulo ao array de titulos
void addTitle(char ***titles, int *lenTitles, char *title) {
    int sizeTitle = strlen(title) + 1;

    if (*lenTitles != 0) {
        *titles = realloc(*titles, sizeof(char*) * (*lenTitles + 1));
        (*lenTitles)++;
        (*titles)[*lenTitles - 1] = (char *)malloc(sizeof(char) * sizeTitle);
        strcpy((*titles)[*lenTitles - 1], title);
    } else {
        *titles = malloc(sizeof(char*));
        (*titles)[0] = (char *)malloc(sizeof(char) * sizeTitle);
        (*lenTitles)++;
        strcpy((*titles)[0], title);
    }
}

void pullFromFile(char *File, char ***Title, int *lenTitle){
    FILE *file;
    
    char nameFile[100];
    char livro[50];
    
    strcpy(nameFile, File);
    strcat(nameFile,".txt");

    file = fopen(nameFile, "r");

    if(file != NULL){
        fgets(livro,sizeof(livro),file);
        while (fgets(livro,sizeof(livro),file))
        {
            addTitle(Title,lenTitle,livro);
        }
        
    }else{
        perror("\nErro ao abrir o arquivo.\n");
    }

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





