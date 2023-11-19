#define _CRT_SECURE_NO_WARNINGS
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

bool isFloat(const char* str) {
    int i = 0;

    // Учет знака числа
    if (str[0] == '-' || str[0] == '+') {
        i = 1;
    }

    bool hasDot = false;

    // Проверка каждого символа на цифру или точку
    for (; i < strlen(str); i++) {
        if (str[i] == '.') {
            // Проверка наличия только одной точки
            if (hasDot) {
                return false;
            }
            hasDot = true;
        }
        else if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }

    return true;
}

double readRealNumber() {
    char input[100];

    while (true) {
        printf("Enter a fractional number: ");
        fgets(input, sizeof(input), stdin);

        // Удаление символа новой строки из ввода
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        if (isFloat(input)) {
            return atof(input);
        }
        else {
            printf("You entered an incorrect fractional number. Try again.\n");
        }
    }
}

int main()
{
    
    double list1[100];
    char line[100];
    printf("How do you want to fill array (r-random, other-from keyboard): ");
    fgets(line, sizeof(line), stdin);

    int size = readNaturalNumberLessThan100();

    

    if (line[0] == 'r') {
        for (int i = 0; i < size; i++) {
            list1[i] = rand();
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            list1[i] = readRealNumber();
        }
    }

    double min = list1[0];
    for (int i = 0; i < size; i += 1) {
        if (min > list1[i]) {
            min = list1[i];
        }
    }

    printf("min = %lf\n", min);

    int index1, index2;

    for (int i = 0; i < size; i += 1) {
        if (list1[i] > 0) {
            index1 = i;
            break;
        }
    }
    for (int i = size - 1; i > -1; i -= 1) {
        if (list1[i] > 0) {
            index2 = i;
            break;
        }
    }

    if (index1 == index2 || index2 - index1 == 1) {
        printf("the sum");
    }
    else {
        double sum = 0;
        for (int i = index1 + 1; i < index2; i += 1) {
            sum += list1[i];
        }
        printf("the sum is %lf", sum);
    }   
    return 0;
}
