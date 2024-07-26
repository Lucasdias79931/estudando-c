#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;

    struct Node* left;
    struct Node* right;
}Node;

Node* insert(Node *root, int data){
    Node *temp =(Node *)malloc(sizeof(Node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL){
        return temp;
    }else{
        Node *current = root;
        Node *parent =NULL;

        while (1)
        {
            parent = current;
            if( data < parent->data){
                current = current->left;

                if(current == NULL){
                    parent->left = temp;
                    return root;
                }
            }else{
                current = current->right;

                if(current == NULL){
                    parent->right = temp;
                    return root;
                }
            }
        }
        
    }

    return root;
}


int main(){
    int i;
    int array[14] = {
        34,84,15,0,2,99,79,9,88,89,18,31,39,100,101
    };
    Node *root = NULL;

    for(i = 0; i<13; i++ ){
        root = insert(root, array[i]);
        printf("\nInserted: %d", array[i]);
    }

    int temp = search(root, 88);
    if(temp){
        printf("\n[%d] Found.\n",temp->data);

    }else{
        printf("\n[x] (%d) Not found.",i);
    }

    return 0;
}
