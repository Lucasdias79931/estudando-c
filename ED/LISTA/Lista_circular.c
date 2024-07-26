#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct  Data {
    char *book;
    int year;
} Data;

typedef struct No {
    struct No *previous;
    Data *data;
    struct No *next;
} No;

typedef struct End {
    struct No *previous;
    struct No *end;
} End;

Data *createBook(const char *book, int year);
bool isEmpty(No *List);
void push(No **ini, Data *data, End **end);
void print(No *ini);

int main() {
    No *bookList = NULL;
    End *endList = NULL;

    push(&bookList, createBook("Tolstoi", 1886), &endList);
    push(&bookList, createBook("the witchr", 1986), &endList);
    push(&bookList, createBook("harry potter", 2007), &endList);
    push(&bookList, createBook("the wolves", 1886), &endList);
    push(&bookList, createBook("It", 1886), &endList);

    print(bookList);

    return 0;
}

bool isEmpty(No *List) {
    return List == NULL;
}

void print(No *ini) {
    if (isEmpty(ini)) {
        printf("\nThe list is Empty!");
    } else {
        No *current = ini;
        do {
            printf("\nBook: %s\nYear: %d", current->data->book, current->data->year);
            current = current->next;
        } while (current != ini);
    }
}

void push(No **ini, Data *data, End **end) {
    No *newBook = (No *)malloc(sizeof(No));

    if (newBook == NULL) {
        printf("\nMemory allocation error in push!");
        return;
    }

    newBook->previous = NULL;
    newBook->data = data;
    newBook->next = NULL;

    if (isEmpty(*ini)) {
        *ini = newBook;
        *end = (End *)malloc(sizeof(End)); 
        (*end)->previous = newBook;
        (*end)->end = newBook;
        printf("\nNew book added successfully!");
    } else {
        (*end)->end->next = newBook;
        newBook->previous = (*end)->end;
        (*end)->end = newBook;
        printf("\nNew book added successfully!");
    }
}

Data *createBook(const char *book, int year) {
    Data *newBook = (Data *)malloc(sizeof(Data));

    if (newBook == NULL) {
        printf("\nMemory allocation error in create!");
        return NULL;
    }

    newBook->book = (char *)malloc(strlen(book) + 1);
    if (newBook->book == NULL) {
        free(newBook); 
        return NULL;
    }
    strcpy(newBook->book, book);
    newBook->year = year;

    return newBook;
}
