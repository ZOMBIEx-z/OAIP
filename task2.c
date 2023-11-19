#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int readNaturalNumberLessThan100() {
    int number;
    bool validInput = false;

    while (!validInput) {
        printf("Enter a natural number less than 100: ");
        if (scanf("%d", &number) == 1) {
            if (number > 0 && number < 100) {
                validInput = true;
            }
            else {
                printf("Invalid value. Enter the number again.\n");
            }
        }
        else {
            printf("Incorrect input. Enter the number again.\n");
            // Очистка буфера после некорректного ввода
            while (getchar() != '\n');
        }
    }

    return number;
}

double readRealNumber() {
    double number;
    bool validInput = false;

    while (!validInput) {
        printf("Enter a real number: ");
        if (scanf("%lf", &number) == 1) {
            validInput = true;
        }
        else {
            printf("Incorrect input. Enter the number again.\n");
            // Очистка буфера после некорректного ввода
            while (getchar() != '\n');
        }
    }

    return number;
}


int main()
{
    double list1[100];
    char line;
    printf("How do you want to fill array (r-random, other-from keyboard): ");
    line = getchar();
    int size = readNaturalNumberLessThan100();

    if (line == 'r') {
        for (int i = 0; i < size; i++) {
            list1[i] = rand();
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            list1[i] = readRealNumber();
        }
    }


    int index_last_even = -1;
    for (int i = size - 1; i > -1; i -= 1) {
        if ((int)list1[i] % 2 == 0) {
            index_last_even = i;
            break;
        }
    }

    for (int i = 0; i < index_last_even+1; i += 1) {
        printf("%i ",(int)list1[i]);
    }


    return 0;
}
