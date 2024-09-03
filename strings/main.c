#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void Capitalize(char *str) {
    if (str == NULL || strlen(str) == 0) return; 
    
    str[0] = toupper(str[0]);  
    
    for (int i = 1; i < strlen(str); i++) {
        str[i] = tolower(str[i]);  
    }
}

int count(const char *str, const char *substr){
    if(strlen(substr) > strlen(str))return 0;

    int occurrence = 0;
    int sizeSub = strlen(substr);

    int i = 0;
    for (i = 0; i <= strlen(str) - sizeSub; i++) {
        // Verifica se a substring atual coincide com a substring procurada
        if (strncmp(&str[i], substr, sizeSub) == 0) {
            occurrence++;
            i += sizeSub - 1; // Avança para evitar contagens sobrepostas
        }
    }

    return occurrence;
}

void reverse(char *str){
    int size = strlen(str);

    int i = 0, j = 0;

    for(i = 0, j = size-1; j >= i; i++, j--){
        char aux = str[i];
        str[i] = str[j];
        str[j] = aux;
    }



}

// como strlen funciona
int len(const char *str){
    int len = 0;
    while (*str)
    {
        len++;
        *str++;
    }
    return len;
    
}



int main() {
   /* char *palavra = join("lucas dos santos dias", "-");
    printf("\n%s\n", palavra);
    */
    
    /*char str[] = "aNA";
    Capitalize(str);

    printf("\n%s\n",str);*/

    /*char str[] = "lucas dos santos dias lucas dias santos    lulucascas dos santos dias";
    printf("\n%d\n",count(str,"lucas"));*/
    /*char str[] = "lucas";
    
    printf("\n%i\n",len(str));*/
    return 0;
}
