#include <stdio.h>
#include <stdlib.h>



int main(){

    float x = 2, y = 0;
    int *q = &x;
    y = *q;

    printf("\n\n%f\n\n", y);

    return 0;
}