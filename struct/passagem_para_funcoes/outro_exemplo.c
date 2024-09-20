#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
    int vecto[5];
    int lenArray;
    int numAleatorio;

}Array;





// Essa função faz uma copia da struct Array, logo não altera a struct original
void modificando_por_valor(Array array, int value, int aleatorio){
    array.numAleatorio = aleatorio;
    for(int i = 0; i < array.lenArray; i++){
        array.vecto[i] = value;
    }

  
}

// Nessa função a struct 'Array' é passada por referência por ponteiro, logo a struct original sofre alteração
void modificando_por_referencia(Array *array, int value, int aleatorio){
    for(int i = 0; i < array->lenArray; i++){
        array->vecto[i] = value;
    }
    array->numAleatorio = aleatorio;
    
}

void printArray(Array array){
    printf("\nNúmero aleatório:%i",array.numAleatorio);
    printf("\n{");
    for(int i = 0; i < array.lenArray; i++){
        printf("%i",array.vecto[i]);

        if(i < array.lenArray - 1)printf(", ");
    }
    printf("}\n");
}

int main(){

    Array Array = {.vecto = {1,3,4,5,6}, .lenArray = 5, .numAleatorio = 0};

    printf("\nAntes de passar pela função (passando por valor)");

    printArray(Array);

    modificando_por_valor(Array, 10, 15);


    printf("\nDepois de passar pela função 'passando por valor'");
    printArray(Array);

    
    printf("\nAntes de passar pela função 'passando por referência");
    printArray(Array);

    modificando_por_referencia(&Array, 10, 15);

    printf("\nDepois de passar pela função 'passando por referência'");
    printArray(Array);
    return 0;
}