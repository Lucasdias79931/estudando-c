#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float add(float *numero1, float *numero2){
    return *numero1 + *numero2;
    
}

float sub(float *numero1, float *numero2){
    return *numero1 - *numero2;
    
}

float dive(float *numero1, float *numero2){
    return *numero1 / *numero2;
    
}

float mult(float *numero1, float *numero2){
    return *numero1 * *numero2;
    
}

void numero(float *numero){

}

void operador(char *operador){
    
    
    while(true){
        printf("\nOperadores: + / * -");
        scanf("%c", operador);

        if(*operador=='+' || *operador=='-' || *operador=='*' || *operador=='/'){
            break;
        }else{
            printf("\noperador incorreto\n");
        }
    }

}



int main(){
   
    float *numero = malloc(1 * sizeof(float));
    char operador;

    printf("\n\n%f\n\n",sizeof(*numero));
    

 









    return 0;
}