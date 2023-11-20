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

void readRealNumber(bool a, double list[100], int size) {
    double number;
    bool validInput = false;

    // a = 0 заполнен по убыванию
    // a = 1 заполнен по возрасланию

    while (!validInput) {
        printf("Enter a real number: ");

        if (scanf("%lf", &number) == 1) {
            validInput = true;
        } else {
            printf("Incorrect input.\n");
            // Очистка буфера после некорректного ввода
            while (getchar() != '\n');
        }
    }

    list[0] = number;

    for (int i = 1; i < size; i += 1) {

        validInput = false;

        while (!validInput) {
            printf("Enter a real number: ");

            if (scanf("%lf", &number) == 1){
                if (a == 0 && list[i - 1] >= number) {
                    validInput = true;
                } else if (a == 1 && list[i - 1] <= number) {
                    validInput = true;
                } else {
                    printf("Incorrect input.\n");
                    // Очистка буфера после некорректного ввода
                    while (getchar() != '\n');
                    continue;
                }
            } else {
                printf("Incorrect input.\n");
                // Очистка буфера после некорректного ввода
                while (getchar() != '\n');
            }
        }

        list[i] = number;

    }

}


int main()
{
    double list1[100];
    double list2[100];

    int size1 = readNaturalNumberLessThan100();
    int size2 = readNaturalNumberLessThan100();

    int t1, t2;

    readRealNumber(0, list1, size1);
    printf("end of first array\n");
    readRealNumber(1, list2, size2);


    int i, j;
    for (i = 0, j = size2 - 1; -1 < i && i < size1 && -1 < j && j < size2;) {
        if ((int)list1[i] > (int)list2[j]){
            printf("%i ", (int)list1[i]);
            i += 1;
        }
        else {
            printf("%i ", (int)list2[j]);
            j -= 1;
        }
    }


    for (;i < size1; i += 1) {
        printf("%i ", (int)list1[i]);
    }

    for (;j > -1; j -= 1) {
        printf("%i ", (int)list2[j]);
    }


    return 0;
}
