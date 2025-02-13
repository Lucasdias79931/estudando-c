#include <stdio.h>
#include <stdlib.h>

void funcao(int **piParametro){
    printf("%d\n%d\n%d\n%d\n", &piParametro, piParametro, *piParametro, **piParametro);
    
}



int main(){
    int *piVariavel = malloc(sizeof(int));
    *piVariavel = 20;
    funcao(&piVariavel);
    return 0;
}