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


List * Listinit(){
    List *list = malloc(sizeof(List));
    if(!list)exit(1);

    list->end = NULL;
    list->ini = NULL;
    list->size = 0;
    return list;
}


void push(List *list, int number){
    if(!list) exit(1);

    No *newNode = malloc(sizeof(No));

    if(!newNode)exit(1);

    newNode->next = NULL;
    newNode->previous = NULL;
    newNode->number = number;


    if(list->size == 0){
        list->ini = newNode;
        list->end = list->ini;
        list->size++;
    }else{
        newNode->previous = list->end;
        list->end->next = newNode;
        list->end = newNode;
        list->size++;
    }
}

void printList(List *list){
    if(!list)printf("\n");

    No *current = list->ini;

    while (current)
    {
        printf("%d\n",current->number);
        current= current->next;
    }
    
}



int main(){
    List *numbers = Listinit();

    push(numbers, 5);
    push(numbers, 6);
    push(numbers, 7);
    push(numbers, 8);
    push(numbers, 9);
    push(numbers, 10);
    printf("Na ordem\n");
    printList(numbers);

    
}