#include <stdio.h>
#include <stdlib.h>

int main() {

    int size;

    printf("size of array: ");
    scanf("%d", &size);

    int *array = (int *) malloc(size * sizeof(int));

    for (int i = 0; i < size; i += 1) {
        printf("Enter the value of array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size; i += 1) {
        for (int j = i + 1; j < size; j += 1) {
            if (array[i] == array[j]) {
                for (int k = j; k < size; k += 1) {
                    array[k] = array[k + 1];
                }
                size -= 1;
                int *array = (int *) realloc(array, size * sizeof(int));
                j -= 1;
            }
        }
    }

    for (int i = 0; i < size; i += 1) {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}

