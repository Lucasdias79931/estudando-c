#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



int buscaDC(int vet[], int size, int value){
    if(value < 0 || value >= size) return 0;

    int left = 0, right = size - 1;
    int mid;

    while (left <= right) {
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

void cBSort(char vet[]){
    int size = strlen(vet);
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


void strBSort(char *vet[], int size) {
    int i, j;
    char *aux;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (strcmp(vet[i], vet[j]) > 0) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

int main(){

    char vetor[] = {'e','d','c','b','a','\0'};
    int i = 0;

    cBSort(vetor);
    

    printf("\n{");
    for(i = 0; i < strlen(vetor); i++){

        printf("%c",vetor[i]);

        if(i < strlen(vetor) - 1) printf(",");
    }
    printf("}\n");

    
    return 0;
}