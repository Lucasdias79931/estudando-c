#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];

char check();
void init_matrix();
void get_player_move();
void get_computer_move();
void disp_matrix();

int main() {
    char done;
    printf("Este é o jogo-da-velha\n");
    printf("Você vai jogar contra o computador\n");

    done = ' ';
    init_matrix();

    do {
        disp_matrix();
        get_player_move();
        done = check();
        if (done != ' ' || done == 'D') break;
        disp_matrix();  // Display the board after the player's move
        get_computer_move();
        done = check();
    } while (done == ' ');

    if (done == 'X') {
        printf("\nVocê ganhou!\n");
    } else if (done == 'O') {
        printf("\nEu ganhei!!!\n");
    } else {
        printf("\nEmpate!\n");
    }

    disp_matrix();

    return 0;
}

void init_matrix() {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matrix[i][j] = ' ';
        }
    }
}

void get_player_move() {
    int x, y;
    printf("Digite as coordenadas para o X (linha e coluna, separadas por espaço): ");
    scanf("%d %d", &x, &y);
    x--;
    y--;

    if (x < 0 || x >= 3 || y < 0 || y >= 3 || matrix[x][y] != ' ') {
        printf("Posição inválida, tente novamente.\n");
        get_player_move();
    } else {
        matrix[x][y] = 'X';
    }
}

void get_computer_move() {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matrix[i][j] == ' ') {
                matrix[i][j] = 'O';
                return;
            }
        }
    }
}

void disp_matrix() {
    int t;

    for (t = 0; t < 3; t++) {
        printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
        if (t != 2) printf("\n--- | --- | ---\n");
    }

    printf("\n");
}

char check() {
    int i;

    for (i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2] && matrix[i][0] != ' ') {
            return matrix[i][0];
        }
    }

    for (i = 0; i < 3; i++) {
        if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i] && matrix[0][i] != ' ') {
            return matrix[0][i];
        }
    }

    if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] && matrix[0][0] != ' ') {
        return matrix[0][0];
    }

    if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0] && matrix[0][2] != ' ') {
        return matrix[0][2];
    }

    // Check for a draw (no winner)
    for (i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == ' ') {
                return ' ';
            }
        }
    }

    return 'D'; // Draw
}
