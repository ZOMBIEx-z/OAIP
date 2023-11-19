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
                printf("Invalid value.\n");
            }
        }
        else {
            printf("Incorrect input.\n");
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
            printf("Incorrect input.\n");
            // Очистка буфера после некорректного ввода
            while (getchar() != '\n');
        }
    }

    return number;
}


int main()
{
    double list1[100];
    double list2[100];
    
    int size1 = readNaturalNumberLessThan100();
    int size2 = readNaturalNumberLessThan100();

        for (int i = 0; i < size1; i++) {
            list1[i] = readRealNumber();
        }

        printf("end of first array\n");

        for (int i = 0; i < size2; i++) {
            list2[i] = readRealNumber();
        }

    int i, j;
    for (i = 0, j = size2 - 1; i < size1 || j > -1;) {
        if ((int)list1[i] > (int)list2[j]){
            printf("%i ", (int)list1[i]);
            i += 1;
        }
        else {
            printf("%i ", (int)list2[j]);
            j -= 1;
        }
    }

    return 0;
}
