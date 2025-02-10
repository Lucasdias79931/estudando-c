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

typedef struct List{
    struct No *previous;
    struct No *end;
    int size;
}List;


