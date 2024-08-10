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

char* join(const char* string, const char *sub) {
    int len_string = strlen(string);
    int len_sub = strlen(sub);
    int total_len = len_string + (len_sub * len_string) + 1; // +1 para o null terminator

    char *current = (char *)malloc(total_len);
    if (current == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    char *ptr = current;
    for (int i = 0; i < len_string; i++) {
        strcpy(ptr, sub);
        ptr += len_sub;
        *ptr++ = string[i];
    }
    strcpy(ptr, sub); // Adiciona o sub no final

    return current;
}

int main() {
   /* char *palavra = join("lucas dos santos dias", "-");
    printf("\n%s\n", palavra);
    */
    
    /*char str[] = "aNA";
    Capitalize(str);

    printf("\n%s\n",str);*/
    return 0;
}
