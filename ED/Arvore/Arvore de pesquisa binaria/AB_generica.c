#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef enum Type {
    Integer = 0,
    String,
    Char,
    Float,
    Double,
    Short_int
} Type;

typedef struct Node {
    void *data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree {
    Node *root;
    Type type;
} Tree;

Tree *createTree(Type type) {
    Tree *tree = malloc(sizeof(Tree));
    if (!tree) {
        fprintf(stderr, "Error allocating memory for tree\n");
        exit(1);
    }
    tree->type = type;
    tree->root = NULL;
    return tree;
}


short int compare(const void *data1, const void *data2, const Type type) {
    if (!data1 || !data2) {
        fprintf(stderr, "Data is NULL in compare\n");
        exit(1);
    }

    switch (type) {
        case Integer:
            return (*(int *)data1 - *(int *)data2);
        case String:
            return strcmp((const char *)data1, (const char *)data2);
        case Char:
            return (*(char *)data1 - *(char *)data2);
        case Float:
            return (*(float *)data1 > *(float *)data2) - (*(float *)data1 < *(float *)data2);
        case Double:
            return (*(double *)data1 > *(double *)data2) - (*(double *)data1 < *(double *)data2);
        case Short_int:
            return (*(short int *)data1 - *(short int *)data2);
        default:
            fprintf(stderr, "Unknown type in compare\n");
            exit(1);
    }
}

short int sizeData(const void *data, Type type) {
    switch (type) {
        case Integer:    return sizeof(int);
        case String:     return strlen((const char *)data) + 1;
        case Char:       return sizeof(char);
        case Float:      return sizeof(float);
        case Double:     return sizeof(double);
        case Short_int:  return sizeof(short int);
        default:
            fprintf(stderr, "Unknown type in sizeData\n");
            exit(1);
    }
}


void copyData(void **destineData, const void *originData, short int size) {
    *destineData = malloc(size);
    if (!*destineData) {
        fprintf(stderr, "Error allocating memory for data\n");
        exit(1);
    }
    memcpy(*destineData, originData, size);
}

void insert(Tree *tree, const void *data, Type type) {
    if (!tree || type != tree->type) {
        fprintf(stderr, "Tree is null or type mismatch\n");
        exit(1);
    }

    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Error allocating memory for node\n");
        exit(1);
    }

    copyData(&new_node->data, data, sizeData(data, type));
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
        return;
    }

    Node *current = tree->root;
    Node *parent = NULL;

    while (current) {
        parent = current;
        if (compare(data, current->data, type) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (compare(data, parent->data, type) < 0) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}
