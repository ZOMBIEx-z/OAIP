#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
            if (k == 100) {
                break;
            }

        }
    }

    for (int i = 0; i < size; i += 1) {
        int j = 0;
        int p;
        for (p = 0; array[i][p] != 100; p += 1);
        p += 1;
        while (array[i][j] != 100) {

            if (array[i][j] < 0) {
                for (int k = j; k < p - 1; k += 1) {
                    array[i][k] = array[i][k + 1];
                }
                p -= 1;
                array[i] = (int *) realloc(array[i], p * sizeof(int));
                j -= 1;
            }

            j +=1;
        }
    }

    for (int i = 0; i < size; i += 1) {
        for (int j = 0; array[i][j] != 100; j += 1) {

            printf("%d ", array[i][j]);


        }
        printf("100\n");
    }

    for (int i = 0; i < size; i += 1) {
        free(array[i]);
    }


    free(array);

    return 0;
}

