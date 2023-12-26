#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void shell_sort(int *array, int size) {
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                if (array[j] > 0 && array[j + s] > 0 && array[j] % 2 == 0 && array[j + s] % 2 == 0) {
                    int temp = array[j];
                    array[j] = array[j + s];
                    array[j + s] = temp;
                }

            }
        }
    }
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

int getIntegerFromUseri(int i) {
    char input[100];

    printf("Enter an integer value of list[%d]: ", i);
    scanf("%s", input);
    while (!isNumber(input)) {
        printf("Error! Enter an integer value of matrix[%d]: ", i);
        scanf("%s", input);

    }

    return atoi(input);
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

    printf("How do you want to fill array (r-random, other-from keyboard): ");
    char line[100];
    fgets(line, sizeof(line), stdin);

    int size_x = getIntegerFromUser();

    int* list;
    do {
        list = (int*) malloc(sizeof(int) * size_x);
    } while (list == NULL);


    if (line[0] == 'r') {
        for (int i = 0; i < size_x; i++) {
                list[i] = -10000 + rand() % 20000;
        }
    } else {
        for (int i = 0; i < size_x; i++) {
                list[i] = getIntegerFromUseri(i);
        }
    }

    shell_sort(list, size_x);

    for (int i = 0; i < size_x; i += 1) {
            printf("%d ", list[i]);

    }

    free(list);

    return 0;
}
