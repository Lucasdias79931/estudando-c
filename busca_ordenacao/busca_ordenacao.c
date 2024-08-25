#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



int buscaDC(int vet[], int size, int value/*, int *interacoes*/){
    if(value < 0 || value >= size) return 0;

    int left = 0, right = size - 1;
    int mid;
   // (*interacoes) = 0;
    while (left <= right) {
     //   (*interacoes)++;
        mid = left + (right - left) / 2;

        if (vet[mid] == value) {
            return 1;  
        } else if (vet[mid] < value) {
            left = mid + 1;  
        } else {
            right = mid - 1;  
        }
    }

    return 0;  
}


void bubbleSort(int vet[], int size/*, int *interacoes*/){
    int i = 0, j = 0;
   // (*interacoes) = 0;

    for(i = 0; i < size - 1; i++){
        for( j = i + 1; j < size; j++){
            if(vet[i] > vet[j]){
           //     (*interacoes)++;
                int aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }


}

void cBSort(char vet[]/*, int *interacoes*/){
    int size = strlen(vet);
    int i = 0, j = 0;
  //  (*interacoes) = 0;

    // *interacoes = 0;
    for(i = 0; i < size - 1; i++){
        for( j = i + 1; j < size; j++){
        //    (*interacoes)++;
            if(vet[i] > vet[j]){
                int aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}


void strBSort(char *vet[], int size/*, int *interacoes*/) {
    int i, j;
    char *aux;
  //  (*interacoes) = 0;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
          //  (*interacoes)++;
            
            if (strcmp(vet[i], vet[j]) > 0) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

int main(){
    char *pessoas[] = {"zema", "xak", "paulo", "well", "paulo", "ana","nzambi", "perlo", "alien", "beto"};
    int sizePessoas = sizeof(pessoas) / sizeof(pessoas[0]);
    char vetor[] = {'e','d','c','b','a','\0'};
    int i = 0;
   // int interacoes = 0;
    //cBSort(vetor);
    

    /*printf("\n{");
    for(i = 0; i < strlen(vetor); i++){

        printf("%c",vetor[i]);

        if(i < strlen(vetor) - 1) printf(",");
    }
    printf("}\n");*/


    strBSort(pessoas, sizePessoas/*, &interacoes*/);
    printf("\n{");
    for(i = 0; i < sizePessoas; i++){

        printf("%s",pessoas[i]);
        

        if(i < sizePessoas - 1) printf(",");
    }
    printf("}\n");
  //  printf("\ninterações no algoritmo de ordenação:%i\n\n", interacoes); // aqui podemos observar o numerios de interações que o alg. precisou fazer para ordenar o vetor
    
    return 0;
}