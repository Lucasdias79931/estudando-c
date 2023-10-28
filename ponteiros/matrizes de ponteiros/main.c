#include <stdio.h>
#include <stdlib.h>

//string por string
void display_array(char *q[], int size);

// caractere de cada vez
void put_display_array(char *q[], int size);




int main(){
    
   char *matrix[]={
        "lucas",
        "rita",
        "josé",
        "fabricio"
    };

   

    int size = sizeof(matrix) / sizeof(matrix[0]);

    put_display_array( matrix, size);
    display_array( matrix, size);

    
    
    return 0;
}





void put_display_array(char *q[], int size) {
    for (int i = 0; i < size; i++) {

        char *currentString = q[i];

        while (*currentString) {
            putchar(*currentString);
            currentString++;
        }
        printf("\n");
    }
    printf("\n");
}

void display_array(char *q[], int size){
    printf("\n");
    int i = 0;
    while(i<size){
        printf("\n%s", q[i]);
        i++;
    }
     printf("\n");

}