#include <stdio.h>
#include <stdlib.h>
#include <string.h>




// pode ser declarada assim, porém, toda vez que for declarar uma variavel do tipo 'Alucno' tera que escrever assim: struct Aluno variavel:


/*
struct Aluno{
    char nome[50];
    int idade;
    char curso[50];
};

*/

//pode ser feito usando 'typedef', daí não irá precisar usar no 'struct' toda vez que declarar uma variavel. ex.: Aluno variavel

typedef struct{
    char nome[50];
    int idade;
    char curso[50];
}Aluno;




int main(){
    Aluno aluno;

    strcpy(aluno.curso, "Sistemas de Informação");
    aluno.idade = 20;
    strcpy(aluno.nome, "Lucas");  

    // Exibir os valores para verificar
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("Curso: %s\n", aluno.curso);
}



