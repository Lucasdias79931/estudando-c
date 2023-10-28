#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check(char *a, char *b, int (*cmp)(const char *, const char *));


int main() {
    char s1[80], s2[80];
    int (*p)(const char *, const char *);

    p = strcmp;

    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);

    check(s1, s2, p);
    

    return 0;
}


void check(char *a, char *b, int (*cmp)(const char *, const char *)){
    printf("\ntestando igualdade\n");
    if(!(*cmp)(a,b)){
        printf("igual\n");
    }else{
        printf("diferente\n");
    }
}