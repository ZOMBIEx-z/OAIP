#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int min(int* arr, int size) {
    if (size == 0) {
        return -1; // Возвращаем -1, если массив пустой
    } else {
        int min_element = arr[0]; // Предполагаем, что первый элемент - минимальный
        for (int i = 1; i < size; i++) {
            if (arr[i] < min_element) {
                min_element = arr[i]; // Если находим элемент меньше текущего минимального, обновляем его
            }
        }
        return min_element;
    }
}

void InsertionSort(int **arr, int size_x, int size_y)
{
    int* newElement;
    int location;

    for (int i = 1; i < size_x; i++)
    {
        newElement = arr[i];
        location = i - 1;
        while(location >= 0 && min(arr[location], size_y) > min(newElement, size_y))
        {
            arr[location+1] = arr[location];
            location = location - 1;
        }
        arr[location+1] = newElement;
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

int getIntegerFromUseri(int i, int j) {
    char input[100];

    printf("Enter an integer value of matrix[%d][%d]: ", i, j);
    scanf("%s", input);
    while (!isNumber(input)) {
        printf("Error! Enter an integer value of matrix[%d][%d]: ", i, j);
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
    int size_y = getIntegerFromUser();


    int** list;
    do {
        list = (int**) malloc(sizeof(int*) * size_x);
    } while (list == NULL);


    for (int i = 0; i < size_x; i += 1) {
        do {
            list[i] = (int*) malloc(sizeof(int) * size_y);
        } while (list[i] == NULL);
    }

    if (line[0] == 'r') {
        for (int i = 0; i < size_x; i++) {
            for (int j = 0; j < size_y; j += 1) {
                list[i][j] = -10000 + rand() % 20000;
            }
        }
    } else {
        for (int i = 0; i < size_x; i++) {
            for (int j = 0; j < size_y; j += 1) {
                list[i][j] = getIntegerFromUseri(i, j);
            }
        }
    }

    InsertionSort(list, size_x, size_y);

    for (int i = 0; i < size_x; i += 1) {
        for (int j = 0; j < size_y; j += 1) {
            printf("%d ", list[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size_x; i += 1) {
        free(list[i]);
    }
    free(list);

    return 0;
}
