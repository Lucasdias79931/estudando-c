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







typedef struct List
{   
    char nome[30];
    struct List *next; 
}List;

void reverese(List **init);
void addLivro(List **ini, char *string);

void printList(List *ini);

int len(List *ini);

void delet(List **ini, char *string);

void update(List **ini, char *nome, char *newTitulo);

void freeMemory(List **ini);

int main(){
    List *livro = NULL;
    int tam = sizeof(titulos)/sizeof(titulos[0]);
    char *string;
    int i = 0;

    int opcao;

    /*do {
        printf("\nMenu:\n");
        printf("1. Adicionar livro\n");
        printf("2.\n");
        printf("3. Atualizar livro\n");
        printf("4. Imprimir lista de livros\n");
        printf("5. Imprimir tamanho da lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
              
                i = 0;
                while (i == 0) {
                    printf("\ndigite: ");
                    string = (char *)malloc(30 * sizeof(char)); // Alocação corrigida
                    if (string == NULL) {
                        printf("Erro ao alocar memória.\n");
                        return 1; // Saia do programa se a alocação falhar
                    }
                    fgets(string, 20, stdin);
                    // Adicione seu código para addLivro aqui
                    addLivro(&livro,string);
                    printf("\n0 para sair: ");
                    scanf("%d", &i);
                    getchar(); // Limpa o buffer de entrada
                }
                
                break;
            case 2:
               
                break;
            case 3:
               
                break;
            case 4:
                printList(livro);
                break;
             case 5:
                printf("\nTamanho:%d",len(livro));
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);*/
   



    addLivro(&livro,"sandman");
    addLivro(&livro,"sqlserver");
    addLivro(&livro,"ubunto");
    printList(livro);

    reverese(&livro);

    printList(livro);



    return 0;
}

void reverese(List **init){
    if((*init)==NULL) return;

    List *prev = NULL;
    List *current = *init;
    List *next_node = NULL;

    while (current != NULL){
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    
    *init = prev;
    
}

void freeMemory(List **ini){
    List *atual = *ini;
    List *anterior = NULL;

    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->next;
        free(anterior);
    }
    
    *ini = NULL;
}

void update(List **ini, char *titulo, char *newTitulo){
    List *aux = *ini;

    if(aux == NULL){
        printf("Lista vazia!");
        return;
    }

    if(strcmp(aux->nome,titulo)==0){
        strcpy(aux->nome,newTitulo);
        printf("\nAtualizado!");
        return;
    }

    while (aux != NULL && strcmp(aux->nome,titulo)!=0)
    {
        aux = aux->next;
    }

    if(aux != NULL){
        strcpy(aux->nome,newTitulo);
        printf("\nAtualizado!");
        return;
    }

    printf("\nItem não encontrado na lista!");
    


}



void delet(List **ini, char *string) {
    List *atual = *ini;
    List *anterior = NULL;

    if (atual == NULL) {
        printf("\nErro de alocação!");
        return;
    }

    if (strcmp(atual->nome, string) == 0) {
        *ini = atual->next;
        free(atual);
        printf("\nDeletado!");
        return;
    }

    while (atual != NULL && strcmp(atual->nome, string) != 0) {
        anterior = atual;
        atual = atual->next;
    }

    if (atual != NULL) {
        anterior->next = atual->next;
        free(atual);
        printf("\nDeletado!");
        return;
    }

    printf("\nItem não encontrado!");
}


int len(List *ini){
    int element =0;
    

    if(ini  == NULL){
        
        return element;
    }

    while (ini  != NULL)
    {
       element++;
       ini = ini ->next;
    }

    

    return element;
}


void printList(List *ini){
   
    int element = 0;

    if(ini == NULL){
        
        printf("\nLista vazia!");
    }
    
    while (ini !=NULL){
       printf("\n%s",ini ->nome);
       printf("\nPosicao:%d\n",element);
       element++;
       ini = ini ->next;
       
    }
    
}

void addLivro(List **ini, char *string){
    List *atual = (List *)malloc(sizeof(List));

    if(atual == NULL){
        printf("\nErro de alocação!");
        return;
    }

    strcpy(atual->nome,string);
    atual->next = NULL;


    if(*ini == NULL){
       
        *ini = atual;
        printf("\nGravado com sucesso");
    }else{

        int no = 1;
        

        List *aux = *ini;                                                        
                                                                               
        while (aux->next != NULL) {

            aux = aux->next;
            printf("\nNo: %d",no);
            no++;
        }

        aux->next = atual;
        
        printf("\nGravado com sucesso");

       
    }
}