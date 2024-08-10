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



int main() {
   /* char *palavra = join("lucas dos santos dias", "-");
    printf("\n%s\n", palavra);
    */
    
    /*char str[] = "aNA";
    Capitalize(str);

    printf("\n%s\n",str);*/
    return 0;
}
