#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
   char *book;
} Data;

typedef struct Node {
    Data *data;
    struct Node *previous;
    struct Node *next;
} Node;

typedef struct {
    Node *ini;
    Node *end;
} List;

void initialize(List *list);
void push(List *list, Data *data);
Data *creatData(char *book);
int len(Node *ini);
char *Index(Node *list, int ID);
void bSort(List *list);

int main() {
    List *list = (List *)malloc(sizeof(List));
    initialize(list);
    
    push(list, creatData("Watchmen"));
    push(list, creatData("Sandman"));
    push(list, creatData("Maus"));
    push(list, creatData("Annie"));

    Node *current = list->ini;
    int cont = 1;
    while (current != NULL) {  
        printf("\nbook %i: %s", cont, current->data->book);
        current = current->next;
        cont++;
    }

    // Ordenando a lista
    bSort(list);

    
    current = list->ini;
    cont = 1;
    printf("\n\nLista ordenada:\n");
    while (current != NULL) { 
        printf("book %i: %s\n", cont, current->data->book);
        current = current->next;
        cont++;
    }

    return 0;
}

// Ordena de forma Crescente;
void bSort(List *list) {
    if (list == NULL || list->ini == NULL || list->end == NULL) return;

    Node *current = list->ini;

    while (current != list->end) {
        Node *next = current->next;
        while (next != NULL) {
            if (strcmp(current->data->book, next->data->book) > 0) {
                Data *aux = current->data;
                current->data = next->data;
                next->data = aux;
            }
            next = next->next;
        }
        current = current->next;
    }
}

void initialize(List *list) {
    if (list == NULL) {
        list->ini = NULL;
        list->end = NULL;
    }
}

int len(Node *ini){

    if(ini == NULL){
        return 0;
    }
    int tam = 0;

    while (ini != NULL)
    {
        tam++;
        ini = ini->next;    
    }

    return tam;
    
}

char *Index(Node *list, int ID){
    if(list == NULL){
        return NULL;
    }

    int id=0;
    while (list !=NULL)
    {   
        
        if(id == ID){
            return list->data->book;
        }else{
            list = list->next;
            id++;
        }

    }

    return NULL;
    
}

Data *creatData(char *book) {
    // Alocação de memória para a struct Data
    Data* newBook = (Data *)malloc(sizeof(Data));

    // Verificação se a alocação foi bem-sucedida
    if (newBook == NULL) {
        printf("\nErro na alocação de memória para novo livro!");
        return NULL; // Retornando NULL em caso de erro
    }
    
    newBook->book = (char *)malloc((strlen(book) + 1) * sizeof(char));

    // Verificação se a alocação foi bem-sucedida
    if (newBook->book == NULL) {
        printf("\nErro na alocação de memória para o nome do livro!");
        free(newBook); // Liberando a memória alocada para newBook
        return NULL; // Retornando NULL em caso de erro
    }

    // Copiando o nome do livro para newBook->book
    strcpy(newBook->book, book);

    return newBook;
}

void push(List *list, Data *data){
    if(!list){
        printf("\nLista não inicializada!");
        return;
    }

    Node *newNode = malloc(sizeof(Node));

    if(!newNode){
        printf("\nerro de alocação de memoria");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;
    

    if(list->end == NULL){
        list->ini = newNode;
        list->end = newNode;
    }else{
        newNode->previous = list->end;
        list->end->next = newNode;
        list->end = newNode;
    }

    
}