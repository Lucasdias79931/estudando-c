#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*

Escreva uma função recursiva que determine quantas
vezes um dígito K ocorre em um número natural N. Por
exemplo, o dígito 2 ocorre 3 vezes em 762021192.

*/

int ocorrencia(int n, int k){
    if(n == 0) return 0;

    return (n % 10 == k) + ocorrencia(n / 10, k);
}





int potencia(int base, int exp){
    if(exp == 0) return 1;

    return base * potencia(base, exp - 1);
}

int sumAllInArray(int array[], int size){
    //Trata caso size == 0
    if(size == 0) return 0;

    //base
    if(size == 1) return array[0];


    //passo recursivo
    return array[size - 1 ] + sumAllInArray(array, size - 1);
}

void reverseArray(int array[], int esq, int dir){
    if(esq < dir){
        int aux = array[esq];
        array[esq] = array[dir];
        array[dir] = aux;
        reverseArray(array, esq + 1, dir - 1);
    }
}


int main(){

    int base = 2, exp = 3;
    int array[] = {1,2,3,4,5};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Usando recursao. Potencia de %d elevado a %d = %d\n",base, exp, potencia(base,exp));

    printf("Usando recursao. Soma de todos os elementos do array:%d\n",sumAllInArray(array,size));

    printf("Usando recursao. Reversão do array\n");
    reverseArray(array,0, size -1);
    printf("Array depois da reversão\n");
    for(int i = 0; i < size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}