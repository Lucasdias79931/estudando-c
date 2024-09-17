#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100


// Estrutura
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


//funções

unsigned hashcode(char *key);

Node *createNode(char *key, char *value);

void insertNode(Hash *hash, char *key, char *value);

char *search(Hash *hash, char *key);


//Dados para teste


//dados para teste
const char *titulos[] = {
    "Dom Quixote", "O Senhor dos Anéis", "O Pequeno Príncipe", "Harry Potter e a Pedra Filosofal",
    "Cem Anos de Solidão", "1984", "Orgulho e Preconceito", "Crime e Castigo", "A Montanha Mágica",
    "O Conde de Monte Cristo", "A Metamorfose", "A Divina Comédia", "O Alquimista", "A Revolução dos Bichos",
    "O Apanhador no Campo de Centeio", "O Nome da Rosa", "O Hobbit", "Lolita", "O Código Da Vinci",
    "As Crônicas de Nárnia", "Os Miseráveis", "Guerra e Paz", "Ensaio Sobre a Cegueira", "O Estrangeiro",
    "O Lobo da Estepe", "O Retrato de Dorian Gray", "Os Irmãos Karamazov", "Memórias Póstumas de Brás Cubas",
    "O Grande Gatsby", "A Insustentável Leveza do Ser", "A Menina que Roubava Livros", "A Redoma de Vidro",
    "O Velho e o Mar", "O Morro dos Ventos Uivantes", "A Sangue Frio", "A Estrada", "O Cemitério",
    "O Homem Invisível", "Duna", "O Iluminado", "O Médico e o Monstro", "O Prisioneiro de Zenda",
    "O Poderoso Chefão", "A Guerra dos Tronos", "As Vinhas da Ira", "A Cor Púrpura", "O Sol é para Todos",
    "Moby Dick", "O Velho Homem e o Mar", "A Máquina do Tempo", "O Senhor das Moscas", "A Casa dos Espíritos",
    "O Conto da Aia", "Os Pilares da Terra", "O Sol Também se Levanta", "A Peste", "A Náusea",
    "A Longa Viagem a Um Pequeno Planeta Hostil", "Neuromancer", "O Pintassilgo", "O Amor nos Tempos do Cólera",
    "O Apanhador no Campo de Centeio", "O Mestre e Margarida", "A Revolta de Atlas", "1984", "Fahrenheit 451",
    "Admirável Mundo Novo", "O Estrangeiro", "O Processo", "A Revolução dos Bichos", "O Velho e o Mar",
    "A Metamorfose", "Cem Anos de Solidão", "O Retrato de Dorian Gray", "O Lobo da Estepe", "O Médico e o Monstro",
    "O Grande Gatsby", "Crime e Castigo", "Os Miseráveis", "Dom Quixote", "A Divina Comédia", "O Hobbit",
    "A Sangue Frio", "O Nome da Rosa", "O Apanhador no Campo de Centeio", "Guerra e Paz", "Ensaio Sobre a Cegueira",
    "O Alquimista", "A Insustentável Leveza do Ser", "A Menina que Roubava Livros", "O Código Da Vinci", "Duna",
    "O Prisioneiro de Zenda", "O Conto da Aia", "O Sol é para Todos", "O Senhor dos Anéis", "O Pequeno Príncipe",
    "1984", "O Poderoso Chefão", "As Crônicas de Nárnia", "O Sol Também se Levanta", "A Máquina do Tempo",
    "O Velho Homem e o Mar", "O Amor nos Tempos do Cólera", "A Guerra dos Tronos", "O Processo", "Fahrenheit 451",
    "A Náusea", "A Revolta de Atlas"
};


int main(){
    Hash hash;
    
    insertNode(&hash, "stephen king", "it a coisa");
    insertNode(&hash, "stephen king", "cemitério");
    insertNode(&hash, "stephen king", "cujo");
    insertNode(&hash, "j.k.", "harry potter e a pedra filosofal");
    insertNode(&hash, "j.k.", "harry potter e a camara secreta");
    insertNode(&hash, "j.k.", "harry potter e o enigma do principe");
    insertNode(&hash, "j.k.", "harry potter e as reliquias da morte");
    

    printf("\n{%s:%s)\n", "j.k", search(&hash,"j.k"));

    return 0;
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



Node *createNode(char *key, char *value){
    Node *newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

unsigned hashcode(char *key){
    unsigned long hash = 5381;
    unsigned c;

    while (c = *key++ )
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % MAX_SIZE;
    
}
