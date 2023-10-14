#include <stdio.h>
#include <stdlib.h>

void imprime(int *var){
    *var = 59;
    printf("\nDentro da function: %d", *var);
}

void imprimeParemetro(int var){
    var = 35;
    printf("\nDentro da function 2: %d", var);
}


int main() {
    int i[1]={1}, *ptr = i;




    printf("\n\n\n%d\n\n\n", *ptr);
    imprime(ptr);
    printf("\n\n\n%d\n\n\n", *ptr);
    imprimeParemetro(i);
    printf("\n\n\n%d\n\n\n", *ptr);
    
    
    
    
    
    /*int var = 0;
    int *ptr2 = &var; 

    printf("\nFora da function: %d", var); 
    imprime(ptr2); 
    printf("\nFora da function: %d", var); 
    printf("\n");
    imprimeParemetro(var);
    printf("\nFora da function: %d", var); 
    printf("\n");
*/
    return 0;
}



/*


    char hello[] = "hello world";
    char *ptr;
    ptr = hello;

    int var = 0;
    int ptr2 = var;
*/