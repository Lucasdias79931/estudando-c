#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct mamifero{
    char *especie;
    char *estagio_evolucional;
    int olhos;
    int bracos;
    int pernas;
};

struct humano {
    struct mamifero ser_humano;
    char *cor;
    int olhos;
    
};

void especie(struct humano *Humano, char *especie){
    Humano->ser_humano.especie = especie;
}



int main() {
    struct humano *pessoas = malloc(5 * sizeof(struct humano)); 

    if (pessoas == NULL) {
        fprintf(stderr, "Erro na alocação de memória.\n");
        return 1;
    }

    especie(pessoas, "ser humano");
    printf("%s", pessoas->ser_humano.especie);

    free(pessoas);  


    return 0;
}
