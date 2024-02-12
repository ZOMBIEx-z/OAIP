#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void shellSort(int *arr, int size_arr) {

    int tmp = size_arr;
    for (int i = 0; i < size_arr; i += 1) {
        if (arr[i] > 0 && arr[i] % 2 == 0) {
            arr[tmp] = arr[i];
            tmp += 1;
        }
    }
/*
    for (int i = 0; i < size_arr * 2; i += 1) {
        printf("%d ", arr[i]);

    }
    printf("\n");
*/

    int start = size_arr;
    int end = tmp - 1;

    int size = end - start + 1;
    int gap = 1;

    while (gap < size / 3) {
        gap = gap * 3 + 1;
    }

    while (gap > 0) {
        for (int i = start + gap; i <= end; ++i) {
            int temp = arr[i];
            int j = i;

            while (j >= start + gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }

        gap /= 3;
    }

    /*
    for (int i = 0; i < size_arr * 2; i += 1) {
        printf("%d ", arr[i]);

    }
    printf("\n");
*/

    tmp = size_arr;
    for (int i = 0; i < size_arr; i += 1) {
        if (arr[i] > 0 && arr[i] % 2 == 0) {
            arr[i] = arr[tmp];
            tmp += 1;
        }
    }

}


bool isNumber(const char *str) {
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

    int *list;
    do {
        list = (int *) malloc(sizeof(int) * size_x * 2);
    } while (list == NULL);


    if (line[0] == 'r') {
        for (int i = 0; i < size_x; i++) {
            list[i] = -10 + rand() % 20;
        }
    } else {
        for (int i = 0; i < size_x; i++) {
            list[i] = getIntegerFromUseri(i);
        }
    }

    for (int i = 0; i < size_x; i += 1) {
        printf("%d ", list[i]);

    }
    printf("\n");

    shellSort(list, size_x);

    for (int i = 0; i < size_x; i += 1) {
        printf("%d ", list[i]);

    }

    free(list);

    return 0;
}
