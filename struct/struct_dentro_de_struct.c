#include <stdio.h>
#include <stdlib.h>
#include <string.h>







//pode ser feito usando 'typedef', daí não irá precisar usar no 'struct' toda vez que declarar uma variavel. ex.: Aluno variavel



typedef struct{
    char matricula[10];
    char nome_curso[10];
    int semestre;
}Curso;

typedef struct{
    char nome[50];
    int idade;
    Curso curso;
}Aluno;






int main(){
    Aluno aluno;

    strcpy(aluno.curso.matricula, "123456789");
    strcpy(aluno.curso.nome_curso, "SISTEMAS DE INFORMAÇÃO");  
    aluno.curso.semestre = 2;
    
    // Preencher os dados do aluno
    aluno.idade = 20;
    strcpy(aluno.nome, "Lucas");  

    // Exibir os valores para verificar
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("Matrícula: %s\n", aluno.curso.matricula);
    printf("Curso: %s\n", aluno.curso.nome_curso);
    printf("Semestre: %d\n", aluno.curso.semestre);
}



