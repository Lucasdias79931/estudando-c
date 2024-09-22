#include <stdio.h>
#include <stdlib.h>






int main(){
    const int origin = 0;
    int *ptrToOrigin = &origin;


    printf("\norigin antes de mudar via ponteiro:%i\n",*ptrToOrigin);
    *ptrToOrigin = 25;

    printf("\norigin depois de mudar via ponteiro:%i\n",*ptrToOrigin);

    printf("\n############################################################\n");

    printf("\n############### Manipulando Array ##########################\n");

    int integer[] = { 1, 2, 3, 4, 5};
    int lenArray = sizeof(integer) / integer[0];
    int *ptrToArr = &integer;


    printf("\nptrToArr Apontando para a posição %i do array 'integer' \nValor:%i", 0, *ptrToArr);
    //incrementando ptrToArray
    ptrToArr++;

    printf("\nptrToArr Apontando para a posição %i do array 'integer' \nValor:%i", 1, *ptrToArr);
    
    

    printf("\n############################################################\n");

    printf("\n############### Ponteiro constante para um Array ##########################\n");

    int inteiros[] = { 1, 2, 3, 4, 5};
    int lenVetor = sizeof(inteiros) / inteiros[0];
    const int *ptrToInt = &inteiros;


    printf("\nptrToInt Apontando para a posição %i do array 'inteiros' \nValor:%i", 0, *ptrToInt);
    //incrementando ptrToInt
    ptrToInt++;

    printf("\nptrToInt Apontando para a posição %i do array 'inteiros' \nValor:%i", 0, *ptrToInt);
    
    
    printf("\n");
    return 0;
}