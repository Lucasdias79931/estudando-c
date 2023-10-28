#include <stdio.h>
#include <stdlib.h>





int main(){
    
    int x, *p, **q;

    q = &p;
    p = &x;

    x=250;
    *p = 35;
    **q = 215;
    
    printf("\n\n%d\n\n", **q);
    
    
    
    
    
    
    
    
    
    
    return 0;
}