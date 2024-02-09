#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int q;
} Factorization;

Factorization* factorize_number(int number, int* count) {
    Factorization* factorizations = malloc(number * sizeof(Factorization));
    *count = 0;

    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            factorizations[*count].p = i;
            factorizations[*count].q = number / i;
            (*count)++;
        }
    }

    return factorizations;
}

void factorize_file(const char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int number;
    while (fscanf(file, "%d", &number) != EOF) {
        int count;
        Factorization* factorizations = factorize_number(number, &count);

        for (int i = 0; i < count; i++) {
            printf("%d = %d * %d\n", number, factorizations[i].p, factorizations[i].q);
        }

        free(factorizations);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }

    const char* file_path = argv[1];
    factorize_file(file_path);

    return 0;
}
