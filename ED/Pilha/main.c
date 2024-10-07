#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>




typedef struct  Data
{
    char *book;
}Data;

typedef struct Node
{
    Data *data;
    struct Node *next;
}Node;

typedef struct Stack
{
    Node *base;
    Node *top;
}Stack;

bool isEmpty(Stack *stack);
Data *createData(char *book);
void initializeStack(Stack *stack);
void push(Stack *stack, Data *data);
char *pop(Stack *stack);
void reverse(Stack *stack);
void print(Stack *stack);
char *peek(Stack *stack);
int size(Stack *stack);
void clear(Stack *stack);
int search(Stack *stack, char* item);
Stack *copyStack(Stack *stack);
Stack *mergeStack(Stack *stackOne, Stack *stackTwo);
Node *iterate(Stack *stack,int index);

int main(){

    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if(stack == NULL)exit(1);

   
    initializeStack(stack);

    push(stack,createData("sandman"));
    push(stack,createData("ana"));
    push(stack,createData("paulo"));
    
    //printf("\nposicao do livro 'paulo':%i ",search(stack,"paulo"));

   /* printf("\ntamanho depois de 3 push:%d\n",size(stack));
    printf("\n livro do topo:%s",peek(stack));

    reverse(stack);
    
    printf("\n livro do topo depois de usar o reverse:%s\n",peek(stack));

    clear(stack);
    printf("\nStack depois de de clear:%d",size(stack));*/
    

    
    //copiar pilha:
    /*Stack *newStack = copyStack(stack);
    printf("\nStack original!\n");
    print(stack);
    printf("\n");
    printf("\nnew stack");
    print(newStack);
    printf("\n");*/
    
    /*
    Stack *stackTwo = (Stack *) malloc(sizeof(Stack));
    initializeStack(stackTwo);
    
    push(stackTwo,createData("black hole"));
    push(stackTwo,createData("batman"));
    push(stackTwo,createData("Demolidor"));
    


    printf("\nStack One");
    print(stack);
    printf("\n");
    printf("\nStack Two");
    print(stackTwo);

    
    Stack *stackThree = mergeStack(stack,stackTwo);
    printf("\n");
    printf("\nStack One after merge");
    print(stackThree);
    printf("\n");
    */

    
    printf("\ninterando a partir da base até o top");
    int i = 0;
    for(i = 0; i< size(stack);i++){
        Node *current = iterate(stack,i);

        printf("\nNode %d, Book:%s",i+1,current->data->book);
    }

    
    return 0;
}

Node *iterate(Stack *stack,int index){
    if(stack->base == NULL) return NULL;
    
    if(index < 0 || index > size(stack))return NULL;
    int tam =0;

    
    Node *current = stack->base;
    
    while(index != tam){
        current = current->next;
        tam++;
    }
    
    return current;
    
}


Stack *mergeStack(Stack *stackOne, Stack *stackTwo){
    if(stackOne->base == NULL || stackTwo->base == NULL){
        printf("\nUma das listas ou as duas são nulas");
        return NULL;
    }
    Stack *newStack = (Stack *)malloc(sizeof(Stack));

    
    if(newStack == NULL){
        printf("\nErro de alocacao!");
    }else{
        printf("\nSucesso na alocação!");
    }

    initializeStack(newStack);
    
    Node *currentStackOrigin = stackOne->base;
    while (currentStackOrigin != NULL)
    {
        push(newStack,createData(currentStackOrigin->data->book));
        currentStackOrigin = currentStackOrigin->next;
    }

    currentStackOrigin = stackTwo->base;
    while (currentStackOrigin != NULL)
    {
        push(newStack,createData(currentStackOrigin->data->book));
        currentStackOrigin = currentStackOrigin->next;
    }

    return newStack;
    
}

Stack *copyStack(Stack *stack){

    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    
    if(newStack == NULL){
        printf("\nErro de alocacao!");
    }else{
        printf("\nSucesso na alocação!");
    }

    initializeStack(newStack);
    
    Node *currentStackOrigin = stack->base;
    while (currentStackOrigin != NULL)
    {
        push(newStack,createData(currentStackOrigin->data->book));
        currentStackOrigin = currentStackOrigin->next;
    }
    
        


   


    return newStack;
}


int search(Stack *stack, char* item){
    if(isEmpty(stack))return 1;
    
    
    int tam =  (- size(stack)) + 1;
    
    Node* current = stack->base;
    while(current != NULL){
        if(strcmp(current->data->book,item) == 0){
            return tam;
        }

        tam++;
        current = current->next;
    }

    return 1;
    

}


void clear(Stack *stack){
    if(isEmpty(stack)) return;

    while (stack->base != NULL)
    {
        char *temp = pop(stack);
    }
    
}

int size(Stack *stack){
    if(isEmpty(stack))return 0;
    int tam = 0;

    Node *current = stack->base;
    while (current != NULL)
    {
        tam++;
        current = current->next;
    }

    return tam;
      
    

}

char *peek(Stack *stack){
    if(stack->base == NULL)return NULL;

    return stack->top->data->book;
}

void print(Stack *stack){
    if(stack->base == NULL){
        printf("\nStack vazia!");
        return;
    }

    Node *current = stack->base;

    while(current != NULL){ 
        printf("\n%s",current->data->book);
        current = current->next;
    }
}

void reverse(Stack *stack){
    if(stack->base == NULL || stack->base == stack->top) return;

    Stack *aux = (Stack *)malloc(sizeof(Stack));
    if(aux == NULL){
        printf("\nErro de alocacao para stack auxiliar");
        return;
    }
    initializeStack(aux);
    while(stack->base != NULL)push(aux,createData(pop(stack)));

    
    while (aux->base != NULL){
        push(stack,aux->base->data);
        aux->base = aux->base->next;
    }
   
    
}




void initializeStack(Stack *stack){
    stack->base = NULL;
    stack->top = NULL;
}

bool isEmpty(Stack *stack){
    return stack->base == NULL;
}
Data *createData(char *book) {
    Data *newBook = (Data *)malloc(sizeof(Data));
   
    if (newBook == NULL) {
        printf("\nErro na alocação de memória para novo livro!");
        return NULL;
    }

    newBook->book = (char *)malloc((strlen(book) + 1) * sizeof(char));

    if (newBook->book == NULL) {
        printf("\nErro na alocação de memória para o nome do livro!");
        free(newBook);
        return NULL;
    }

    strcpy(newBook->book, book);

    return newBook;
}
void push(Stack *stack, Data *data){
    Node *newNode = (Node *) malloc(sizeof(Node));
    
   
    if(newNode == NULL){
        printf("\nErro na alocacao para um novo no");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(stack->base == NULL){
        stack->base = newNode;
        stack->top = newNode;
    }else{
        stack->top->next = newNode;
        stack->top = newNode;  
    }
    
}



char *pop(Stack *stack) {
    if (stack->top == NULL) // Verifica se a pilha está vazia
        return NULL;

    char *book = (char *)malloc((strlen(stack->top->data->book) + 1) * sizeof(char)); // Aloca memória para o livro
    if (book == NULL) {
        printf("\nErro na alocação de memória para o livro!");
        return NULL;
    }

    strcpy(book, stack->top->data->book); // Copia o livro

    Node *temp = stack->top;
    if (stack->top == stack->base) { // Caso haja apenas um nó na pilha
        stack->top = NULL;
        stack->base = NULL;
    } else {
        Node *current = stack->base;
        while (current->next != stack->top) {
            current = current->next;
        }
        current->next = NULL;
        stack->top = current;
    }

    free(temp->data->book);
    free(temp->data);
    free(temp);

    return book;
}




/*


 

push(item): Adiciona um elemento ao topo da pilha.
pop(): Remove e retorna o elemento no topo da pilha.
peek(): Retorna o elemento no topo da pilha sem removê-lo.
isEmpty(): Verifica se a pilha está vazia.
size(): Retorna o número de elementos na pilha.

clear(): Remove todos os elementos da pilha.
search(item): Retorna a posição do item na pilha (contando a partir do topo), ou -1 se o item não estiver na pilha.
isFull(): Verifica se a pilha está cheia (se for uma pilha com tamanho fixo).
copy(): Retorna uma cópia da pilha.
reverse(): Inverte a ordem dos elementos na pilha.
merge(stack): Combina duas pilhas em uma.
iterate(): Permite iterar sobre os elementos da pilha.





*/