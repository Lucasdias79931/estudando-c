#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct No {
    char *str;
    struct No *left_child;
    struct No *right_child;
} No;

typedef struct BinaryTree {
    No *root;
} BinaryTree;

BinaryTree *initializeTree( char *str){
    BinaryTree *binaryTree = malloc(sizeof(binaryTree));
    
    if(!binaryTree){
        perror("\nError");
        return NULL;
    }

    binaryTree->root = malloc(sizeof(No));
    if(!binaryTree->root){
        free(binaryTree->root);
        free(binaryTree);

        perror("\nError");
        return NULL;
    }
    int sizeStr = strlen(str) + 1;
    binaryTree->root->str = malloc(sizeof(char) * sizeStr);
    if(!binaryTree->root->str){
        perror("\nError");
        
        free(binaryTree->root->str);
        free(binaryTree->root);
        free(binaryTree);
        return NULL;
    }
    strcpy(binaryTree->root->str, str);

    return binaryTree;
}
void insert_left(BinaryTree *binaryTree, char *str) {
    if (!binaryTree) {
        perror("\nErro: Árvore binária não inicializada");
        return;
    }
    
    if (!str) {
        printf("\nDado inválido!\n");
        perror("Erro");
        return;
    }
    
    int sizeStr = strlen(str) + 1;
    
    No *newNode = malloc(sizeof(No));
    if (!newNode) {
        perror("\nErro ao alocar memória para o novo nó");
        return;
    }
    
    newNode->str = malloc(sizeof(char) * sizeStr);
    if (!newNode->str) {
        perror("\nErro ao alocar memória para a string");
        free(newNode);
        return;
    }
    strcpy(newNode->str, str);
    newNode->left_child = NULL;
    newNode->right_child = NULL;
    
    if (!binaryTree->root) {
        binaryTree->root = newNode;
    } else {
        newNode->left_child = binaryTree->root->left_child;
        binaryTree->root->left_child = newNode;
    }
}

void insert_right(BinaryTree *binaryTree, char *str) {
    if (!binaryTree) {
        perror("\nErro: Árvore binária não inicializada");
        return;
    }
    
    if (!str) {
        printf("\nDado inválido!\n");
        perror("Erro");
        return;
    }
    
    int sizeStr = strlen(str) + 1;
    
    No *newNode = malloc(sizeof(No));
    if (!newNode) {
        perror("\nErro ao alocar memória para o novo nó");
        return;
    }
    
    newNode->str = malloc(sizeof(char) * sizeStr);
    if (!newNode->str) {
        perror("\nErro ao alocar memória para a string");
        free(newNode);
        return;
    }
    strcpy(newNode->str, str);
    newNode->left_child = NULL;
    newNode->right_child = NULL;
    
    if (!binaryTree->root) {
        binaryTree->root = newNode;
    } else {
        newNode->right_child = binaryTree->root->right_child;
        binaryTree->root->right_child = newNode;
    }
}

int main(){
    BinaryTree *binaryTree = initializeTree("a");
    if(!binaryTree){
        exit(1);
    }

    printf("%s\n", binaryTree->root->str);
}