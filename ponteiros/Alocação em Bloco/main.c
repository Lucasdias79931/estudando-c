#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#define SIZEBLOCK 10

typedef struct Data {
    char book[50];
    char autor[50];
    int ano;
} Data;

typedef struct Node {
    Data *data[SIZEBLOCK];
    struct Node *next;
    int cont;
} Node;

typedef struct {
    Node *baseBlock;
    Node *topBlock;
} List;

void initList(List *list) {
    list->baseBlock = NULL;
    list->topBlock = NULL;
}

void push(List *list, Data *data) {
    if (list == NULL || data == NULL) {
        perror("ERROR!");
        return;
    }

    // Verifica se a lista está vazia
    if (list->baseBlock == NULL) {
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            perror("ERROR In newNode!");
            return;
        }
        newNode->cont = 0;
        newNode->next = NULL;

        // Atualiza o bloco base e topo
        list->baseBlock = newNode;
        list->topBlock = newNode;
    }

    // Verifica se o bloco atual está cheio
    if (list->topBlock->cont < SIZEBLOCK) {
        list->topBlock->data[list->topBlock->cont++] = data;
    } else {
        // Cria um novo bloco
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            perror("ERROR In newNode!");
            return;
        }
        newNode->cont = 0;
        newNode->next = NULL;

        // Adiciona o novo bloco ao final da lista
        list->topBlock->next = newNode;
        list->topBlock = newNode;

        // Adiciona o dado no novo bloco
        list->topBlock->data[list->topBlock->cont++] = data;
    }
}

// Função para liberar a memória de toda a lista
void freeList(List *list) {
    Node *current = list->baseBlock;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}