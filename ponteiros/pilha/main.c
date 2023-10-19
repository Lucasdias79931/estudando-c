#include <stdio.h>
#include <stdlib.h>

void push(int element, int *top, int *size){
    int i=0;

    if(top == size){
        int new_size = (*size==0) ? 1 : (*size +1);
        int *new_stack = (int *)malloc(new_size * sizeof(int));

        if(new_stack == NULL){
            printf("\nFalha na alocação de memória");
            return;    
        }

        
    }

   
}

int main(){







    return 0;
}

