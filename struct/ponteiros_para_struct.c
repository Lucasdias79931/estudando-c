#include <stdio.h>
#include <stdlib.h>
#include <string.h>







//pode ser feito usando 'typedef', daí não irá precisar usar no 'struct' toda vez que declarar uma variavel. ex.: Aluno variavel



typedef struct{
    char *matricula;
    char *nome_curso;
    int semestre;
}Curso;

typedef struct{
    char *nome;
    int idade;
    Curso *curso;
}Aluno;


int main(){

     // Aloca memória suficiente para Aluno
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

    // Verifica se a alocação foi feita com sucesso
    if (aluno == NULL) {
        printf("\nErro de alocação de memória em aluno!");
        exit(1);
    }

    // Aloca memória para curso que está dentro de aluno
    aluno->curso = (Curso *)malloc(sizeof(Curso));

    // Verifica se a alocação foi feita com sucesso
    if (aluno->curso == NULL) {
        printf("\nErro de alocação de memória em aluno->curso!");
        exit(1);
    }

    // Aloca memória e preenche os campos da estrutura Curso
    aluno->curso->matricula = (char *)malloc(10 * sizeof(char));
    strcpy(aluno->curso->matricula, "123456789");
    
    aluno->curso->nome_curso = (char *)malloc(50 * sizeof(char));
    strcpy(aluno->curso->nome_curso, "SISTEMAS DE INFORMAÇÃO");
    aluno->curso->semestre = 3;

    // Aloca memória e preenche os campos da estrutura Aluno
    aluno->nome = (char *)malloc(50 * sizeof(char));
    strcpy(aluno->nome, "Lucas");
    aluno->idade = 20;

    // Exibir os valores para verificar
    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);
    printf("Matrícula: %s\n", aluno->curso->matricula);
    printf("Curso: %s\n", aluno->curso->nome_curso);
    printf("Semestre: %d\n", aluno->curso->semestre);

    // Libera a memória alocada
    free(aluno->curso->matricula);
    free(aluno->curso->nome_curso);
    free(aluno->curso);
    free(aluno->nome);
    free(aluno);

    return 0;



    return 0;
}