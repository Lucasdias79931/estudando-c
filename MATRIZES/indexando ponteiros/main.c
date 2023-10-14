#include <stdio.h>
#include <stdlib.h>

int num[10][10];

int main(int j){
    
    int *p, t;
    p = &num[j][0];
    
    for(t=0;t<10;t++){
        printf("%d ", *(p+t));
    }
    
    
    
    
    
    
    
    
    return 0;
}