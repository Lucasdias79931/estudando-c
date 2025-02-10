#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
    Lista duplamente encadeada em que o dado de cada nó pode ser de diferentes tipos;




*/
typedef struct Data {
    void *data;
} Data;

typedef struct Node {
    Data *data;
    struct Node *previous;
    struct Node *next;
} Node;

typedef struct List {
    Node *ini;
    Node *end;
    int size;
} List;

// Inicializa uma lista com ou sem data inicial
List *initialize(Data *data);
// Cria um Data, passando um ponteiro `data` e o tamanho `size`
Data *createData(void *data, int size);
// Adiciona um nó à lista
void push(List *list, void *data);








// Tipos diferentes de dados
typedef struct Pessoa {
    char nome[50];
    short int idade;
} Pessoa;

typedef struct Book {
    char nome[50];
    short int ano;
} Book;


Pessoa *createPessoa(char *name, short int idade) {
    Pessoa *pessoa = malloc(sizeof(Pessoa));
    if (!pessoa) exit(1);
    strcpy(pessoa->nome, name);
    pessoa->idade = idade;
    return pessoa;
}

Book *createBook(char *nome, short int ano) {
    Book *book = malloc(sizeof(Book));
    if (!book) exit(1);
    strcpy(book->nome, nome);
    book->ano = ano;
    return book;
}






int main() {


    Pessoa *pessoa = createPessoa("lucas", 24);
    List *list = initialize(createData(pessoa, sizeof(Pessoa)));
    free(pessoa); // liberara para não ter vazamento de memória
    /*
        como o bloco de memoria apontado por pessoa foi copiado e retornado na função createDta, passada como parametro em initialize, pode dar free(pessoa), pois não usará mais;

        poderia liberar esse bloco dentro da função createData, MAS APENAS se tiver certesa que só passarar data alocada dinamicamente por parametro de createData;
    */
    
    pessoa = (Pessoa *)(list->ini->data->data);
    printf("\nfirst Item: nome:%s\tIdade:%d\n", pessoa->nome, pessoa->idade);

    Book *book = createBook("sandman",1973);
    push(list, createData(book, sizeof(Book)));
    free(book);

    book = (Book *)(list->ini->next->data->data);
    printf("\nseconde Item: nome:%s\tano:%d\n", book->nome, book->ano);

    return 0;
}

List *initialize(Data *data) {
    List *newList = malloc(sizeof(List));
    if (!newList) return NULL;
    
    if (data == NULL) {
        newList->ini = NULL;
        newList->end = NULL;
        newList->size = 0;
    } else {
        newList->ini = malloc(sizeof(Node));
        if (!newList->ini) {
            free(newList);
            return NULL;
        }
        newList->ini->data = data;
        newList->ini->previous = NULL;
        newList->ini->next = NULL;
        newList->end = newList->ini;
        newList->size = 1;
    }

    return newList;
}

Data *createData(void *data, int size) {
    Data *newData = malloc(sizeof(Data)); 
    if (!newData) {
        perror("ERROR allocating Data");
        return NULL;
    }

    newData->data = malloc(size); 
    if (!newData->data) {
        perror("ERROR allocating data memory");
        free(newData);
        return NULL;
    }

    memcpy(newData->data, data, size); 
    return newData;
}

void push(List *list, void *data) {
    if (!list) {
        printf("\nError in list!\n");
        exit(1);
    }

    if (!data) {
        printf("\nError in data!\n");
        exit(1);
    }

    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("\nError in newNode!\n");
        exit(1);
    }

    newNode->previous = NULL;
    newNode->next = NULL;
    newNode->data = data;
    
    if (list->size == 0) {
        list->ini = newNode;
        list->end = newNode;
        list->size = 1;
    } else {
        newNode->previous = list->end;
        list->end->next = newNode;
        list->end = newNode;
        list->size++;
    }
}
