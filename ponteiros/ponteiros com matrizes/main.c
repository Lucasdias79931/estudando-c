#include <stdio.h>
#include <stdlib.h>


void putS(char *s){
    
    register int t;

    printf("\n");
    for (int t = 0; s[t] != '\0'; t++) {
        putchar(s[t]);
    }
    printf("\n");
}



void putstr(char *s){
    printf("\n");
    while(*s){
        putchar(*s++);
    }
    printf("\n");
}

void imprimeNumeros(int *numeros, int size){
    register int i=0;
        printf("\n");
    while(i<size){
        printf("[%i]",*numeros++);
        i++;
    }
   
        printf("\n");
}

void imprime(int *numeros, int size){
   register int i=0;
        printf("\n");
    while(i<size){
        printf("[%i]",*(numeros + i));
        i++;
        *numeros++;
    }
   
        printf("\n");
}

int main(){
    
    char matrix[] = "lucas dos santos dias";
    
    int numeros[]={0,1,2,3,4,5};
    int size = sizeof(numeros)/sizeof(int);

    imprimeNumeros(numeros, size);

    return 0;
}