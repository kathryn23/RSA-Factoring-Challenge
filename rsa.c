#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int number) {
    if (number <= 1) {
        return 0;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

void factorize_number(int number) {
    int p = 0, q = 0;

    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            if (is_prime(i) && is_prime(number / i)) {
                p = i;
                q = number / i;
                break;
            }
        }
    }

    printf("%d=%d*%d\n", number, p, q);
}

void factorize_file(const char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int number;
    while (fscanf(file, "%d", &number) != EOF) {
        factorize_number(number);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: rsa <file>\n");
        return 1;
    }

    const char* file_path = argv[1];
    factorize_file(file_path);

    return 0;
}
