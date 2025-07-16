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


typedef struct Node{
    void *data;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct Tree
{
    Node *root;
    Type type;
}Tree;

Tree *createTree(Type type){
    Tree *tree = malloc(sizeof(Tree));
    
    if(tree == NULL){
        fprintf(stderr, "Error in allocation memory for a new tree\nExiting...");
        exit(1);
    }

    tree->type = type;
    tree->root->left = NULL;
    tree->root->right = NULL;
    tree->root->data = NULL;
    return tree;
}

/*
    In 'compare', case return 0 is left case 1 is right
*/
const short int compare(const void *data1, const void *data2, const Type type){

}

void insert(Node **root, const void *data, const Type type){
    Node *node = NULL;

}



int main(){

}