#include <stdio.h>
#include <stdlib.h>
#include <string.h>




// Adiciona um titulo ao array de titulos
// passo um array triplo como parametro para ser possivel modificar o tamanho do meu arrey duplo '**titles'
void addTitle(char ***titles, int *lenTitles, char *newTitle) {
    int sizeNewTitle = strlen(newTitle) + 1;


    //como o *lentitles só vai ser igual a zero na primeir vez, deixei a condição '*lenTitles != 0' no primeir 'if'
    if (*lenTitles != 0) {

        *titles = realloc(*titles, sizeof(char*) * (*lenTitles + 1));
        (*lenTitles)++;
        (*titles)[*lenTitles - 1] = (char *)malloc(sizeof(char) * sizeNewTitle );
        strcpy((*titles)[*lenTitles - 1], newTitle);
    } else {
        //aloca a primeira posição da matriz
        *titles = malloc(sizeof(char*));

        //aloca o vetor individual apontado pela primeira posição da matriz
        //a lógica é a mesma na parte de cima
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


void bsort(char ***titles, int len){
    for(int i = 0; i < len -1; i++){
        for(int j = i + 1; j < len; j++){
            if(strcmp((*titles)[i],(*titles)[j]) > 0){
                char *swap = (*titles)[i];
                (*titles)[i] = (*titles)[j];
                (*titles)[j] = swap;
            }
        }
    }
}

int main() {
    char **titles = NULL; //matriz dinamica
    int lenTitles = 0;

  
    //passo o endereço do meu ponteiro duplo que será apontado pelo ponteiro triplo da função
    pullFromFile("livros_com_quantidades",&titles,&lenTitles);

    for (int i = 0; i < lenTitles; i++) {
        printf("\n%s",titles[i]);
        
    }


    printf("\n");

    //depois de organizar

    printf("############organizando com bSort###################");

    bsort(&titles,lenTitles);

    for (int i = 0; i < lenTitles; i++) {
        printf("\n%s",titles[i]);
        
    }
    
    
    

    return 0;
}





