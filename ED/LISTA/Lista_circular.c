#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



typedef struct No {
    int number;
    struct No *previous;
    struct No *next;
} No;

typedef struct List{
    struct No *ini;
    struct No *end;
    int size;
}List;

List *initialize() {
    List *newList = malloc(sizeof(List));
    if (!newList) {
        perror("ERROR allocating Data");
        exit(1);
    }
    newList->ini = NULL;
    newList->end = NULL;
    newList->size = 0;
    return newList;
}

void push(List *list, int number) {
    if (!list) {
        perror("ERROR: List does not exist");
        exit(1);
    }

    No *newNode = malloc(sizeof(No));
    if (!newNode) {
        perror("ERROR allocating Data");
        exit(1);
    }

    newNode->number = number;

    if (list->size == 0) {
        
        newNode->next = newNode;
        newNode->previous = newNode;
        list->ini = newNode;
        list->end = newNode;
    } else {
        
        newNode->previous = list->end;
        newNode->next = list->ini;

        list->end->next = newNode;
        list->ini->previous = newNode;
        list->end = newNode;
    }

    list->size++; 
}





