#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char toUp(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

void task_1(char* line) {
    int size = 0;

    while (line[size] != '\0') {
        size++;
    }

    line[0] = toUp(line[0]);

    for (int i = 0; i < size - 1; i += 1) {
        if (line[i] == ' ' && line[i + 1] != ' ') {
            line[i + 1] = toUp(line[i + 1]);
        }
    }
}

char* task_2(char* S1, char* S2, int N1, int N2) {
    int len1 = 0;
    int len2 = 0;
    int i, j;

    // Подсчет длины строки S1
    while (S1[len1] != '\0') {
        len1++;
    }

    // Подсчет длины строки S2
    while (S2[len2] != '\0') {
        len2++;
    }

    // Проверка, чтобы N1 и N2 не превышали длины соответствующих строк
    if (N1 > len1)
        N1 = len1;
    if (N2 > len2)
        N2 = len2;

    // Выделение памяти для новой строки
    char* result = (char*) malloc(N1 + N2 + 1);

    // Копирование первых N1 символов из строки S1 в новую строку
    for (i = 0; i < N1; i++) {
        result[i] = S1[i];
    }

    // Копирование последних N2 символов из строки S2 в новую строку
    for (j = 0; j <= N2; j++) {
        result[N1 + j] = S2[len2 - N2 + j - 1];
    }

    // Добавление завершающего нулевого символа
    result[N1 + N2] = '\0';

    return result;
}


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

int getIntegerFromUser() {
    char input[100];

    printf("Enter a size of array: ");
    scanf("%s", input);
    while (!isNumber(input) || (atoi(input) < 0)) {
        printf("Error! Enter a size of array: ");
        scanf("%s", input);
    }

    return atoi(input);
}




int main() {

    printf("What do you want to do (1: task_1, other: task_2): ");
    char line[100];
    fgets(line, sizeof(line), stdin);

    if (line[0] == '1' && line[1] == '\n' && line[2] == '\0') {
        printf("Enter the line: ");
        char s[1000];

        fgets(s, 1000, stdin);

        task_1(s);

        printf("Result: %s\n", s);

    } else {

        printf("Enter the line s1: ");
        char s1[1000];
        fgets(s1, 1000, stdin);

        printf("Enter the line s2: ");
        char s2[1000];
        fgets(s2, 1000, stdin);

        printf("Enter the number n1: ");
        int n1;
        scanf("%i", &n1);

        printf("Enter the number n2: ");
        int n2;
        scanf("%i", &n2);

        char* result = task_2(s1, s2, n1, n2);

        printf("Result: %s\n", result);

        free(result);
    }

    return 0;
}
