#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
    char key[20];
    int value;

}Dic;

// Essa função faz uma copia da struct dic, logo não altera a struct original
void modificando_por_valor(Dic dic, char key[], int value){
    strcpy(dic.key,key);
    dic.value = value;

  
}

// Nessa função a struct 'dic' é passada por referência por ponteiro, logo a struct original sofre alteração
void modificando_por_referencia(Dic *dic, char key[], int value){
    strcpy(dic->key,key);
    dic->value = value;
    
}

int main(){

    Dic dic = {.key = "", .value = 0};

    printf("\nAntes de passar pela função (passando por valor)");
    printf("\nAutor:%s\nBooks:%i\n",dic.key,dic.value);
    modificando_por_valor(dic, "stephen king", 1);


    printf("\nDepois de passar pela função 'passando por valor'");
    printf("\nAutor:%s\nBooks:%i\n",dic.key,dic.value);

    
    printf("\nAntes de passar pela função 'passando por referência");
    printf("\nAutor:%s\nBooks:%i\n",dic.key,dic.value);

    modificando_por_referencia(&dic, "stephen king", 1);

    printf("\nDepois de passar pela função 'passando por referência'");
    printf("\nAutor:%s\nBooks:%i\n",dic.key,dic.value);
    return 0;
}