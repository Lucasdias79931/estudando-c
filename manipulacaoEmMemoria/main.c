#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int sizeVector = 10;
    int *vector = malloc(sizeof(int) * sizeVector);
    if(!vector){
        perror("ERROR");
        exit(1);
    }

    memset(vector, 0, sizeVector);
    
    printf("\n");
    for(int i = 0; i < sizeVector; i++){
        printf("%i ",vector[i]);
    }
    printf("\n");

    return 0;
}