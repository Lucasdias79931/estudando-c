#include <stdio.h>
#include <stdbool.h>

typedef enum {
    Janeiro = 1,
    Fevereiro = 2,
    Marco = 3,
    Abril = 4,
    Maio = 5,
    Junho = 6,
    Julho = 7,
    Agosto = 8,
    Setembro = 9,
    Outubro = 10,
    Novembro = 11,
    Dezembro = 12
} Mes;

char* mes(Mes mes_ano){
    switch (mes_ano) {
        case Janeiro:
            return "Janeiro";
        case Fevereiro:
            return "Fevereiro";
        case Marco:
            return "Março";
        case Abril:
            return "Abril";
        case Maio:
            return "Maio";
        case Junho:
            return "Junho";
        case Julho:
            return "Julho";
        case Agosto:
            return "Agosto";
        case Setembro:
            return "Setembro";
        case Outubro:
            return "Outubro";
        case Novembro:
            return "Novembro";
        case Dezembro:
            return "Dezembro";
        
    }
}

int main() {
    while (true) {
        Mes mes_ano;
        printf("\nDigite o número do mês no intervalo de [1,12]: ");
        scanf("%i", &mes_ano);
        
        if ( !(mes_ano >= 1 && mes_ano <= 12) ) {
            printf("\nNúmero fora do intervalo de meses!\n");
            continue;
        }

        printf("\nMês {%i: %s}\n", mes_ano, mes(mes_ano));
        break;
    }

    return 0;
}
