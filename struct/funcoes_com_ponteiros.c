#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo as estruturas usando typedef
typedef struct {
    char *matricula;
    char *nome_curso;
    int semestre;
} Curso;

typedef struct {
    char *nome;
    int idade;
    Curso *curso;
} Aluno;

// Funções para inicializar, preencher e liberar memória
void inicializarAluno(Aluno **aluno);
void preencherAluno(Aluno *aluno, const char *nome, int idade, const char *matricula, const char *nome_curso, int semestre);
void liberarMemoria(Aluno *aluno);

int main() {
    Aluno *aluno = NULL;  // Inicialize o ponteiro aluno como NULL
    
    inicializarAluno(&aluno);
    preencherAluno(aluno, "Lucas", 20, "123456789", "SISTEMAS DE INFORMAÇÃO", 3);

    // Exibir os valores para verificar
    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);
    printf("Matrícula: %s\n", aluno->curso->matricula);
    printf("Curso: %s\n", aluno->curso->nome_curso);
    printf("Semestre: %d\n", aluno->curso->semestre);

    // Libera a memória alocada
    liberarMemoria(aluno);

    return 0;
}

void inicializarAluno(Aluno **aluno) {
    if (*aluno != NULL) {
        return;
    }

    *aluno = (Aluno *)malloc(sizeof(Aluno));
    // Verifica se a alocação foi feita com sucesso
    if (*aluno == NULL) {
        printf("\nErro de alocação de memória em aluno!");
        exit(1);
    }
    
    // Inicializar campos de Aluno
    (*aluno)->nome = NULL;
    (*aluno)->idade = 0;
    (*aluno)->curso = (Curso *)malloc(sizeof(Curso));
    // Verifica se a alocação foi feita com sucesso
    if ((*aluno)->curso == NULL) {
        printf("\nErro de alocação de memória em curso!");
        free(*aluno);
        exit(1);
    }
    
    // Inicializar campos de Curso
    (*aluno)->curso->matricula = NULL;
    (*aluno)->curso->nome_curso = NULL;
    (*aluno)->curso->semestre = 0;
}


void preencherAluno(Aluno *aluno, const char *nome, int idade, const char *matricula, const char *nome_curso, int semestre) {
    if (aluno == NULL) return;

    // Aloca memória e preenche os campos da estrutura Curso
    aluno->curso->matricula = (char *)malloc((strlen(matricula) + 1) * sizeof(char));
    strcpy(aluno->curso->matricula, matricula);
    
    aluno->curso->nome_curso = (char *)malloc((strlen(nome_curso) + 1) * sizeof(char));
    strcpy(aluno->curso->nome_curso, nome_curso);
    aluno->curso->semestre = semestre;

    // Aloca memória e preenche os campos da estrutura Aluno
    aluno->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(aluno->nome, nome);
    aluno->idade = idade;
}

void liberarMemoria(Aluno *aluno) {
    if (aluno != NULL) {
        if (aluno->curso != NULL) {
            if (aluno->curso->matricula != NULL) {
                free(aluno->curso->matricula);
            }
            if (aluno->curso->nome_curso != NULL) {
                free(aluno->curso->nome_curso);
            }
            free(aluno->curso);
        }
        if (aluno->nome != NULL) {
            free(aluno->nome);
        }
        free(aluno);
    }
}
