#include "ARRAYS.h"
#include <stdio.h>




void printArr(int arr[], int len) {
    if (len < 1) return;

    printf("\n{");

    for (int i = 0; i < len; i++) {
        printf("%i", arr[i]);
        if (i < len - 1) {
            printf(",");
        }
    }
    printf("}");
}



void inverte(int arr[], int len) {
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        int aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    }
}


int Maior(int arr[], int len) {
    int maior = arr[0];
   

    for (int i = 1; i < len; i++) {
        if (maior < arr[i]) {
            
            maior = arr[i];
        }
    }

    return maior;
}


int segundoMaior(int arr[], int len) {
    int maior = arr[0];
    int segundo = maior;

    for (int i = 1; i < len; i++) {
        if (maior < arr[i]) {
            segundo = maior;
            maior = arr[i];
        }
    }

    return segundo;
}
