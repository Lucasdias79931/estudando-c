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

typedef struct TREE{
    Node *root;
    Type type;
    void *insert;
    void *compare;
}TREE;

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

void inorder(Node *root, Type type) {
    if (root) {
        inorder(root->left, type);

        switch (type) {
            case Integer:
                printf(" %d", *(int *)root->data);
                break;
            case String:
                printf(" %s", (char *)root->data);
                break;
            case Char:
                printf(" %c", *(char *)root->data);
                break;
            case Float:
                printf(" %f", *(float *)root->data);
                break;
            case Double:
                printf(" %f", *(double *)root->data); 
                break;
            case Short_int:
                printf(" %hd", *(short int *)root->data);
                break;
            default:
                fprintf(stderr, "error in type\n");
                return;
        }
        inorder(root->right, type);
    }
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
bool search(Tree *tree, void *value, Type type){
    if(tree == NULL || tree->root == NULL) return false;

    Node *current = tree->root;

    while(current){
        int cmp = compare(current->data, value, sizeData(value, type));

        if(cmp < 0){
            current = current->right;
        } else if(cmp > 0){
            current = current->left;
        } else {
            return true; 
            
        }
    }

    return false; 
    
}

void invert(Node **root){
    if(*root){
        
        Node *temp = (*root)->left;
        (*root)->left = (*root)->right;
        (*root)->right = temp;
        invert(&(*root)->left);
        invert(&(*root)->right);
    }
}

int main(){
    Tree *tree = createTree(Integer);

    for(int i = 5; i <= 20; i++){
        int final = i;
        if(i %2 == 0) final *=-1;
        
        insert(tree,&final,Integer);

    }

    
    
    printf("\n");
    inorder(tree->root, Integer);
    printf("\n");
    invert(&tree->root);
    inorder(tree->root, Integer);
    printf("\n");
}