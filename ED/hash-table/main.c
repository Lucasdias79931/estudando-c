#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct 
{
    char *key;
    char *value;
    struct Node *next;
}Node;


typedef struct 
{
    Node *list[MAX_SIZE];
}Hash;

unsigned hashcode(char *key){
    unsigned long hash = 5381;
    unsigned c;

    while (c = *key++ )
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % MAX_SIZE;
    
}

Node *createNode(char *key, char *value){
    Node *newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

void insertNode(Hash *hash, char *key, char *value){
     unsigned index = hashcode(key);
     Node *node = hash->list[index];

     if(node == NULL){
        hash->list[index] = createNode(key,value);
     }else{
        while (node)
        {
            if(node->next == NULL){
                node->next = createNode(key,value);
                break;
            }
            node = node->next;
        }
        
     }
}

char *search(Hash *hash, char *key){
    unsigned int index = hashcode(key);
    Node *node = hash->list[index];
    while (node)
    {
        if(strcmp(key, node->key) == 0){
            return node->value;
        }
        node = node->next;
    }

    return "";
    
}