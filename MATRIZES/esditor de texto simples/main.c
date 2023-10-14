#include <stdio.h>
#include <stdlib.h>

#define max 100
#define len 80

char text[max][len];


int main(){
    
    register int t, i, j;

    printf("Digite uma linha vazia para sair.\n");
    
    for(t=0;t<max;t++){
        printf("%d: ",t);
        gets(text[t]);
        if(!*text[t])break;
    }
    for(i=0;i<t;i++){

        for(j=0;text[i][j];j++){
            putchar(text[i][j]);
            putchar('\n');
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    return 0;

}