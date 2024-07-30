#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* join(const char* string, const char *sub) {
    int len_string = strlen(string);
    int len_sub = strlen(sub);
    int total_len = len_string + (len_sub * len_string) + 1; // +1 para o null terminator

    char *current = (char *)malloc(total_len);
    if (current == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    char *ptr = current;
    for (int i = 0; i < len_string; i++) {
        strcpy(ptr, sub);
        ptr += len_sub;
        *ptr++ = string[i];
    }
    strcpy(ptr, sub); // Adiciona o sub no final

    return current;
}

int main() {
    char *palavra = join("lucas dos santos dias", "asfdasdgfasdgasdfg");
    printf("\n%s\n", palavra);

    free(palavra); // Liberar a memória alocada
    return 0;
}
