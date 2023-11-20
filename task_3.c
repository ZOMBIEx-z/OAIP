#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isNumber(const char* str) {
    int i = 0;

    // Учет знака числа
    if (str[0] == '-' || str[0] == '+') {
        i = 1;
    }

    // Проверка каждого символа на цифру
    for (; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }

    return true;
}

int readNaturalNumberLessThan100() {
    char input[100];

    while (true) {
        printf("Enter a number: ");
        fgets(input, sizeof(input), stdin);

        // Удаление символа новой строки из ввода
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        if (isNumber(input) && atoi(input) <= 100) {
            return atoi(input);
        }
        else {
            printf("You entered the wrong number. Try again.\n");
        }
    }
}

int getIntegerFromUser(int i, int j) {
    char input[100];

    printf("Enter an integer value of matrix[%d][%d]: ", i, j);
    scanf("%s", input);
    while (!isNumber(input)) {
        printf("Error! Enter an integer value of matrix[%d][%d]: ", i, j);
        scanf("%s", input);

    }

    return atoi(input);
}

int main() {
    int matrix[100][100];

    printf("How do you want to fill array (r-random, other-from keyboard): ");

    char line[100];
    fgets(line, sizeof(line), stdin);

    int size = readNaturalNumberLessThan100();

    if (line[0] == 'r') {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = -1000 + rand() % 2000;
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = getIntegerFromUser(i, j);
            }
        }
    }

int max = matrix[0][0];

for (int i = 0; i < size - size / 2; i++) {
    for (int j = i; j < size - i; j++) {
        if(matrix[i][j] > max) {
            max = matrix[i][j];
        }
    }
}
printf("The maximum element in the first area is: %d", max);
        return 0;
}
