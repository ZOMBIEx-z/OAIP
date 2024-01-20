#include <stdio.h>
#include <malloc.h>

int len(char* line) {
    int i;
    for (i = 0; line[i] != '\0'; i += 1);
    return i;
}

void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void qs(char** s_arr, int first, int last) {
    int i = first, j = last, x = len(s_arr[(first + last) / 2]);

    do {
        while (len(s_arr[i]) < x) i++;
        while (len(s_arr[j]) > x) j--;

        if(i <= j) {
            if (len(s_arr[i]) > len(s_arr[j])) swap(&s_arr[i], &s_arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        qs(s_arr, i, last);
    if (first < j)
        qs(s_arr, first, j);
}

int main(int argc, char **argv) {

    int size = argc - 1;

    char** list =  (char**) malloc(sizeof(char*) * size);

    for (int i = 1; i < argc; i += 1) {
        int j = len(argv[i]);
        list[i - 1] = (char*) malloc(sizeof(char) * j);
        for (int k = 0; k < j; k += 1) {
            list[i - 1][k] = argv[i][k];
        }
    }

    for (int i = 0; i < size; i += 1) {
        for (int j = 0; j < len(list[i]); j += 1){
            printf("%c", list[i][j]);
        }
        printf(" ");
    }
    printf("\n");

    qs(list, 0, size-1);

    for (int i = 0; i < size; i += 1) {
        for (int j = 0; j < len(list[i]); j += 1){
            printf("%c", list[i][j]);
        }
        printf(" ");
    }
    printf("\n");

    for (int i = 0; i < size; i += 1) {
        free(list[i]);
    }
    free(list);

    return 0;
}