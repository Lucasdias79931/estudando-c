#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>







int main(){
    char *s;
    int t=0;

    s = malloc(80);

    if(!s){
        printf("falha na solicitação de memória!\n");
        exit(1);
    }

    printf("\nDigite uma frase: ");

    gets(s);

    for(t = strlen(s)-1; t>0;t--) putchar(s[t]);

    free(s);
    return 0;
}