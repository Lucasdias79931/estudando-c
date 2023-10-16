#include <stdio.h>
#include <stdlib.h>

#define size 5
int *tos, *p1, stack[size];

void push(int i);
int pop();
void imprime_pilha(int pilha[], int tamanho);

int main(){

    int value = 0;
    
    tos = stack; // faz o tos conter o topo da pilha
    p1 = stack; // inicializa p1

    do{
        printf("\nDigite o valor: ");
        scanf("%d", &value);
        if(value!=0){
            push(value);
        }else{
            printf("\n errr\n");
            printf("\nValor do topo é: %d\n", pop());
        }

    } while(value != -1);

    

    return 0;
}

void push(int i){
    p1++;
    if(p1 == (tos + size)){
        printf("\nEstouro da pilha\n\n");
        imprime_pilha(stack, size);
        exit(1);
    }

    *p1 = i;
    
}


int pop(){

    if(p1 == tos){
        printf("\nEstouro da pilha\n\n");
        imprime_pilha(stack, size);
        exit(1);
    }

    p1--;
    return *(p1 + 1);
}

void imprime_pilha(int pilha[], int tamanho){
    
    int j =0;
    printf("\n");
    for(j = 0;j<tamanho;j++){
        printf("[%d]--", pilha[j]);
    }
    printf("\n");
}










