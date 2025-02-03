#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura de um nó da lista
typedef struct No {
    void *data;
    struct No *next;
    struct No *prev;
} No;

typedef struct linkedList {
    No *ini;
    No *end;
    short int sizeList;
} linkedList;






linkedList *initialize() {
    linkedList *newList = malloc(sizeof(linkedList));
    if (!newList) {
        fprintf(stderr, "Erro ao alocar memória para a lista.\n");
        exit(1);
    }

    newList->ini = NULL;
    newList->end = NULL;
    newList->sizeList = 0;

    return newList;
}

void append(linkedList *list, void *data) {
    if (!list || !data) {
        fprintf(stderr, "Erro: Lista ou dado inválido.\n");
        exit(1);
    }

    No *newNode = malloc(sizeof(No));
    if (!newNode) {
        fprintf(stderr, "Erro ao alocar memória para o nó.\n");
        exit(1);
    }

    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = data;

    if (list->sizeList == 0) {
        list->ini = newNode;
        list->end = newNode;
    } else {
        newNode->prev = list->end;
        list->end->next = newNode;
        list->end = newNode;
    }

    list->sizeList++;  
}

int main(){


    return 0;
}