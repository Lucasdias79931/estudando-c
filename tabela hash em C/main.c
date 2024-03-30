#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define MAX_KEY_LEN 100  // Ajuste conforme necessário
#define MAX_VALUE_LEN 100 


typedef struct dict {
    char chave[MAX_KEY_LEN];
    char valor[MAX_VALUE_LEN]; // Defina o tamanho de valor apropriado
    struct dict *next;
} dict;

void limparBuffer();

void addLivros(dict **ini) ;
void delet(dict **ini, char *key, char *value );
void freeDictionary(dict *head);


void ler(dict *ini);

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    dict *Livro = NULL;

    int op =0;
    

    while (true)
    {
        printf("\n1 para listar : 2 para inserir: ");
        scanf("%i",&op);
        limparBuffer();
        
        
        switch (op)
        {
        case 1:
            ler(Livro);
            break;
        case 2:
            addLivros(&Livro);
            break;
        default:
            printf("\nDigito errado! digite 1 ou 2");
            break;
        }

        printf("\ns para sair: ");
        char var;
        scanf("%c",&var);
        limparBuffer();
        if(var == 's' || var == 'S')break;
    }
    
    freeDictionary(Livro);
    return 0;
}

void ler(dict *ini){
   if(ini !=NULL){
   
    while (ini != NULL) {
        printf("Nome: %s\nAutor: %s\n", ini->chave, ini->valor);
        ini = ini->next;
    }
    
   }else{
        printf("\nLista vázia!\n");
   }
    
}

void addLivros(dict **ini) {
    dict *novo = (dict *)malloc(sizeof(dict));
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];

    printf("\nDigite o nome do livro: ");
    fgets(key,MAX_KEY_LEN,stdin);
    limparBuffer(); 

    printf("\nDigite o nome do autor: ");
    fgets(value,MAX_VALUE_LEN,stdin);
 

    if (!novo) {
        printf("\nErro ao alocar memória para novo livro!\n");
        exit(1);  // Ou lide com o erro de forma mais elegante
    }

    strncpy(novo->chave, key, sizeof(novo->chave) - 1);
    novo->chave[sizeof(novo->chave) - 1] = '\0';  // Garanta a terminação nula

    strncpy(novo->valor, value, sizeof(novo->valor) - 1);
    novo->valor[sizeof(novo->valor) - 1] = '\0';
    
    if (*ini == NULL) {
        novo->next = NULL;
        *ini = novo;
    } else {
        dict *temp = *ini;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novo;
        novo->next = NULL;
    }
}

void delet(dict **ini, char *key, char *value ){


}

// Adicione uma função para liberar toda a estrutura do dicionário (implementação omitida por brevidade)
void freeDictionary(dict *head) {
    dict *temp;

    while (head != NULL)
    {   
        temp = head->next;
        free(head);
        head = temp;

    }
    
}



void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

