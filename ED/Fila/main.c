#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Data {
    char *book;
} Data;

typedef struct Node {
    Data *data;
    struct Node *next;
} Node;

typedef struct Fila {
    int len;
    Node *front;
    Node *end;
} Fila;


Data *createData(char *book);
int len(Fila *fila);
void enqueue(Fila *fila, Data *data);
void destroyQueue(Fila *fila);
Fila *initializeQueue();
char *front(Fila *fila);
char *dequeue(Fila *fila);
bool isEmpty(Fila *queue);
void clear(Fila *fila);
void reverse(Fila *fila);
Fila *mergQueue(Fila *f1, Fila *f2);

int main() {
    Fila *books = initializeQueue(); // Aloca a memória para a fila
    Fila *authors = initializeQueue();
    
   

    enqueue(books, createData("sandman"));
    enqueue(books, createData("sandman"));
   

    /*if(front(books)){
        printf("\nPrimeiro livro:%s",front(books));
    }else{
        printf("\nFila vazia");
    }
    printf("\nTamanho da fila: %d\n", len(books));

    int cont = 0;

    while (cont<3)
    {
        printf("livro %d:%s",cont+1,dequeue(books));
        cont++;
    }
    
    clear(books);
    
    if(front(books)){
        printf("\nPrimeiro livro:%s",front(books));
    }else{
        printf("\nFila vazia");
    }
    printf("\nTamanho da fila: %d\n", len(books));*/


    enqueue(authors, createData("Niel Gaiman"));
    enqueue(authors, createData("Stephen King"));
   
    Fila *books_authors = mergQueue(books, authors);

    Node *current = books_authors->front;

    while(current){
        printf("\n%s", current->data->book);
        current = current->next;
    }

    destroyQueue(books);
    destroyQueue(authors);
    destroyQueue(books_authors);
    printf("\n");
    return 0;
}



void reverse(Fila *fila){
    if(!fila)return;
    if(!fila->end || !fila->end)return;

    Node *current = fila->front;
    Node *next = NULL;
    Node *prev = NULL;

    fila->end = fila->front;

    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    fila->front = prev;
}

void clear(Fila *fila){
    while (fila->front !=NULL)
    {
        Node *temp = fila->front;
        fila->front=fila->front->next;
        free(temp);
    }
    
}


bool isEmpty(Fila *fila){
    return fila == NULL;
}
char *dequeue(Fila *fila){
    if(fila->front == NULL)return NULL;

    Node *current = fila->front;
    
    char *book = fila->front->data->book;
    if (book == NULL) {
        printf("\nErro na alocação de memória para o livro!");
        return NULL;
    }
    

    if(fila->end == fila->front){
        fila->end = NULL;
        fila->front = NULL;

    }else{
        fila->front = fila->front->next;
    }

    fila->len--;

    
    free(current->data);
    free(current);
    
    return book;
}



char *front(Fila *fila){
    if(fila->front == NULL){
        return NULL;
    }

    int size = strlen(fila->front->data->book) + 1;
    char *data_front = malloc(sizeof(char) * size);

    if(!data_front){
        printf("Erro em alocação!\n");
        return NULL;
    }

    strcpy(data_front, fila->front->data->book);

    return data_front;
}

Fila *initializeQueue(){
    Fila *fila = malloc(sizeof(Fila));
    if(!fila){
        printf("Erro em alocação de memória para fila!\n");
        exit(1);
    }


    fila->front = NULL;
    fila->end = NULL;

    return fila;
}

void enqueue(Fila *fila, Data *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("\nErro na alocacao de um novo No");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (fila->front == NULL) {
        
        fila->front = newNode;
        fila->end = newNode;
    } else {
        
        fila->end->next = newNode;
        fila->end = newNode;
    }

    fila->len++;
}

int len(Fila *fila) {
    if (fila == NULL || fila->front == NULL) return 0;

    

    return fila->len;
}

Data *createData(char *book) {
    Data *newBook = malloc(sizeof(Data));

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

void destroyQueue(Fila *fila) {
    if (fila == NULL) return;

    Node *current = fila->front;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->data->book); // Libera a memória alocada para o nome do livro
        free(temp->data); // Libera a memória alocada para a estrutura Data
        free(temp); // Libera a memória alocada para o nó
    }

    free(fila); // Libera a memória alocada para a fila
}

Fila *mergQueue(Fila *f1, Fila *f2){
    if(!f1 || !f2)return NULL;
    if(!f1->front || !f1->front)return NULL;

    Fila *f3 = malloc(sizeof(Fila));
    if(!f3){
        printf("Erro ao tentar alocar memória para nova fila\n");
        return NULL;
    }

    Node *current = f1->front;

    while(current){
        enqueue(f3,createData(current->data->book));
        current = current->next;
    }

    current = f2->front;

    while(current){
        enqueue(f3,createData(current->data->book));
        current = current->next;
    }
    
    return f3;
}