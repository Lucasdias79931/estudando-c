#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 100

int stack[max];
int top = 0; // topo da pilha

void push(int i);
int pop();

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
    if (b == 0) {
        printf("Divisão por zero não é permitida.\n");
        exit(1);
    }
    return a / b;
}

void display(int *a, int *b) {
    printf("Primeiro número: ");
    scanf("%d", a);
    printf("\nSegundo número: ");
    scanf("%d", b);
}

void display2(int *a) {
    printf("Próximo número: ");
    scanf("%d", a);
}

int main() {
    int num1 = 0, num2 = 0;
    bool controle = true;
    char operacao;

    while (controle) {
        int i = 0;
        display(&num1, &num2);

        printf("Escolha uma operação (+, -, *, /, ou custom): ");
        scanf(" %c", &operacao);

        switch (operacao) {
            case '+':
                push(add(num1, num2);
                break;
            case '-':
                push(subtract(num1, num2));
                break;
            case '*':
                push(multiply(num1, num2));
                break;
            case '/':
                push(divide(num1, num2));
                break;
            default:
                printf("Operação inválida\n");
        }

        i++;
        if(i == 5) break;

    }
    return 0;
}

void push(int i) {
    if (top >= max) {
        printf("\npilha cheia");
        exit(1);
    }
    stack[top] = i;
    printf("\nresult: %i", i);
    top++;
}

int pop() {
    top--;
    if (top < 0) {
        printf("\npilha vazia\n");
        return 0;
    }
    return stack[top];
}
