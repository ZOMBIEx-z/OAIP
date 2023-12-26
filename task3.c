#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void shift(int *array, int k) {
    int size;
    for (size = 0; array[size] != 0; size += 1);

    int *temp = (int *) malloc(size * sizeof(int));

    for (int i = 0; i < size; i += 1) {
        temp[(i + k) % size] = array[i];
    }

    for (int i = 0; i < size; i += 1) {
        array[i] = temp[i];
    }

    free(temp);
}

int main() {

    int size;

    printf("size of array: ");
    scanf("%d", &size);

    int **array = (int **) malloc(size * sizeof(int *));

    int k;

    for (int i = 0; i < size; i += 1) {
        int j = 0;
        while (true) {

            array[i] = (int *) realloc(array[i], (j + 1) * sizeof(int));
            printf("Enter the value of array[%d][%d]: ", i, j);
            scanf("%d", &k);

            array[i][j] = k;
            j += 1;
            if (k == 0) {
                break;
            }

        }
    }
    printf("How many positions to the left should the elements of each line be shifted? 3");
    scanf("%d", &k);


    for (int i = 0; i < size; i += 1) {
        shift(array[i], k);
    }
/*
    int i = 0;

loop_begin:
    if (i >= size) {
        goto loop_end;
    }

    shift(array[i], k);

    i += 1;

    goto loop_begin;

loop_end:
*/

    for (int i = 0; i < size; i += 1) {
        for (int j = 0; array[i][j] != 0; j += 1) {

            printf("%d ", array[i][j]);


        }
        printf("\n");
    }

    for (int i = 0; i < size; i += 1) {
        free(array[i]);
    }

    free(array);

    return 0;
}
