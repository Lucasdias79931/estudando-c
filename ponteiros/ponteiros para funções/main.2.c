#include <stdio.h>
#include <stdbool.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}



void operar(int a, int b, int (*operation)(int, int)) {
    int resultado = operation(a, b);
    printf("Resultado: %d\n", resultado);
}

void display(int *a, int *b) {
    printf("Primeiro número: ");
    scanf("%d", a);
    printf("\nSegundo número: ");
    scanf("%d", b);
}



int main() {
    int a = 0, b = 0;
 

    display(&a, &b);
    bool oper =true;
    while (oper){
        char operacao;
        printf("Escolha uma operação (+, -, *, /, ou custom): ");
        scanf(" %c", &operacao);

        switch (operacao) {
            case '+':
            operar(a, b, add);
            oper = false;
            break;
        case '-':
            operar(a, b, subtract);
            oper = false;
            break;
        case '*':
            operar(a, b, multiply);
            oper = false;
            break;
        case '/':
            operar(a, b, divide);
            oper = false;
            break;
        
        default:
            printf("Operação inválida\n");
            
            
        }

       
    }
    

    return 0;
}
