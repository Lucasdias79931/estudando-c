#include <stdio.h>
#include <stdlib.h>



int imprime(int matriz[][4]){
    int i=0, j=0;
    for(i = 0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%3d ", matriz[i][j]);
            
        }
        printf("\n");
    }

}

int main(){

    int j=0, i=0, matriz[3][4];

    for(i = 0;i<3;i++){
        for(j=0;j<4;j++){
            matriz[i][j] = (i*4)+j+1;
        }
    }

    imprime(matriz);



    return 0;
}