#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>





typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;






void insertNode(Node **root, int data){
    Node *node = malloc(sizeof(Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    if(*root == NULL){
        *root = node;
    }else{
        Node *parent = NULL;
        Node *current = *root;
        while(true){
            parent = current;
            if(data < parent->data){
                current = current->left;
                
                if(current == NULL){
                    parent->left = node;
                    return;
                }
            }else{
                current = current->right;
                
                if(current == NULL){
                    parent->right = node;
                    return;
                }
            }
        }
    }
}

void inorder(Node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){

    srand(time(NULL));      // Inicializa o gerador de números aleatórios com base no tempo atual
    Node *root = NULL;
    
    
    for (int i = 0; i < 10; i++) {
        int num = (rand() % 21) - 10;  
        insertNode(&root,num);
    }

    inorder(root);

    return 0;
}


