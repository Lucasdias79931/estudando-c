#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void bubbleSort(int vet[], int size){
    int i = 0, j = 0;

    for(i = 0; i < size - 1; i++){
        for( j = i + 1; j < size; j++){
            if(vet[i] > vet[j]){
                int aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}





int main(){

    int vetor[] = {5, 4, 4, 3, 2, 1};
    int size = sizeof(vetor) / sizeof(vetor[0]);
    bubbleSort(vetor, size);

    int i = 0;

    printf("\n{");
    for(i = 0; i < size; i++){

        printf("%i",vetor[i]);

        if(i < size-1) printf(",");
    }
    printf("}\n");

    return 0;
}