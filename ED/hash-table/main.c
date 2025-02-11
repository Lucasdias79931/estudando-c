#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100


// Estrutura
typedef struct Node
{
    char *key;
    char *value;
    struct Node *next;
}Node;


typedef struct Hash
{
    Node *list[MAX_SIZE];
}Hash;


//funções

unsigned int hashcode(char *key) {
    unsigned int hash = 5381; 
    int c;

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) ^ c;  
    }

    return hash % MAX_SIZE;
}


Node *createNode(char *key, char *value){
    Node *newNode = malloc(sizeof(Node));
    if(!newNode)return NULL;
    newNode->key = malloc(sizeof(char) * strlen(key) + 1);
    newNode->value = malloc(sizeof(char) * strlen(value) + 1);
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    return newNode;
} 

void insertNode(Hash *hash, char *key, char *value) {
    unsigned int index = hashcode(key);

    Node *newNode = createNode(key, value);
    if (!newNode) {
        printf("Erro ao alocar memória\n");
        return;
    }

    if (!hash->list[index]) {
        hash->list[index] = newNode;
    } else {
        Node *node = hash->list[index];
        while (node->next) {
            node = node->next;
        }
        node->next = newNode;
    }
}

char *search(Hash *hash, char *key){
    unsigned int index = hashcode(key);

    struct Node *node = hash->list[index];

    while(node){
        if(strcmp(node->key, key) == 0){
            return node->value;
        }
        node = node->next;
    }

    return "";
}


int main(){
    Hash *hash = malloc(sizeof(Hash));
    
    insertNode(hash, "sandman", "Neil Gaiman");
    insertNode(hash, "Harry Potter", "J.K.R.");

    printf("\n{Harry Potter:%s}\n",search(hash, "Harry Potter"));
}




