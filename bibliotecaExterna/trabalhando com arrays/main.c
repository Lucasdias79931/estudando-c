#include <stdio.h>
#include "ARRAYS.h"



int main() {
    int arr[] = {5, 2, 3, 6, 4, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    printf("\nArrey:");
    printArr(arr,len);
    printf("\nSegundo maior numero: %i\n", segundoMaior(arr, len));

    inverte(arr,len);
    printf("\nArrey invertido:");
    printArr(arr,len);

    return 0;
}
