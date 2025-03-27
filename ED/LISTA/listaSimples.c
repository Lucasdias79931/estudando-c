#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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







typedef struct Node{
    int data;
    Node *next;
}Node;


typedef struct List{
    Node *head;
    Node *end;
    int size;
}List;

//inicializa uma lista
List *initialize(int *data){
    List *list = malloc(sizeof(List));
    if(!list)return NULL;
    
    list->head = NULL;
    list->end = NULL;
    list->size = 0;

    if(data){
        list->head = malloc(sizeof(Node));
        if(!list->head){
            free(list);
            return NULL;
        }

        

        list->end = list->head;
        list->head->data = *data;
        list->head->next = NULL;
        list->size = 1;    
    }

    return list;
}

// inverte a lista original 
void reverse(List *list){
    if(!list || !list->head) return;

    if(list->size < 2)return;

    Node *current = list->head; 
    Node *next = NULL;
    Node *prev = NULL;
    list->end = current;

    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        
    }

    list->head = prev;
}


void push(List *list, int data){
    Node *newNode = malloc(sizeof(Node));
    if(!newNode){
        printf("Erro em alocação de Node!\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->next = NULL;

    if(list->end == NULL){
        list->head = newNode;
        list->end = list->head;
    }else{
        list->end->next = newNode;
        list->end = newNode;
    }

    list->size += 1;

}

List *mergList(List *l1, List *l2){
    if(!l1 || !l2) return NULL;
    if(!l1->end || !l2->end) return NULL;

    List *l3 = malloc(sizeof(List));

    Node *current = l1->head;
    while(current){
        push(l3, current->data);
        current = current->next;
    }

    current = l2->head;

    while(current){
        push(l3, current->data);
        current = current->next;
    }

    return l3;
}


