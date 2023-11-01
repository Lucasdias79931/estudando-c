#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char *p[MAX];
int spos = 0;
int rpos = 0;


void qstore(char *q);
char *qretrieve();
void enter();
void review();
void delete();

int main() {
    char s[80];
    int t = 0;
   
    for(t = 0; t < MAX; t++) p[t] = NULL;
    int i=0;
    for(;;){
        printf("\n I(inserir), (L)- Listar, (R)Remover,(S)sair: ");
        gets(s);

        *s = toupper(*s);

        switch (*s)
        {
        case 'I':
            
            enter();
            break;
        case 'L':
            
            review();
            break;
        case 'R':
            
            delete();
            break;
        case 'S':
            exit(0);
            break;
        
        default:
            
            printf("\nEscolha uma opção Válida");
            break;
        }
    }
 


   
   
   
   return 0;
}

/*insere um evento*/
void enter(){
    char s[256], *p;

    
        printf("\ninsira o evendo%d ", spos+1);
        fgets(s,256,stdin);
        
        if(*s == 0) return;
        
        p = malloc(strlen(s)+1);

        if(!p){
            printf("\nSem memória.\n");
            return;
        }

        strcpy(p,s);
        
        if(*p){
            qstore(p);
        }
        free(p); 
   
}


/*recupera um evento.*/
void review(){
    int t = 0;

    for(t = rpos; t<spos; t++){
        printf("\n%d. %s", t+1, p[t]);
    }
}

void delete(){
    char *p = qretrieve();

    if(p == NULL) return;
    printf("\n%s\n",p);
}



/* Insere um evento na fila*/

void qstore(char *q) {
    if (spos == MAX) {
        printf("\nLista cheia\n");
        return;
    }

    p[spos] = strdup(q);
    if (p[spos] == NULL) {
        printf("\nErro ao alocar memória para a string\n");
        return;
    }

    spos++;
}




char *qretrieve(){
    if(rpos == spos){
        printf("\nSem eventos.");
        return NULL;
    }

    rpos++;
    return p[rpos-1];
}




