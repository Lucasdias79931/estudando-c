
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct 
{
    char *name;
    int idade;
    struct pessoa *next;
}pessoa;

pessoa* inicializar(){
    pessoa *pess = (pessoa *)malloc(sizeof(pessoa));
    
    pess->name = (char *)malloc(sizeof(char)*6);
    strcpy(pess->name,"branco");
    pess->idade = 0;
    pess->next = NULL;
    
    return pess;

}




int main(){
    pessoa *pess = inicializar();

    printf("nome:%s\nidade:%d\n%p",pess->name,pess->idade,pess->next);

    return 0;
}