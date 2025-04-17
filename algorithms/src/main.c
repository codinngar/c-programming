#include <stdio.h>

#include "../include/merge_sort.h"

int main(void) {
    int array[] = {4, 12, 8, 90, 5, 3, 2, 68, 3};
    int size = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");

    mergeSort(array, size);

    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}
