#include <stdlib.h>

static void sort(int array[], int leftHalf[], int rightHalf[], int leftSize, int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (leftHalf[i] <= rightHalf[j]) {
            array[k++] = leftHalf[i++];
        } else {
            array[k++] = rightHalf[j++];
        }
    }

    while (i < leftSize) {
        array[k++] = leftHalf[i++];
    }

    while (j < rightSize) {
        array[k++] = rightHalf[j++];
    }
}

void mergeSort(int array[], int size) {
    if (size == 1) return;

    int mid = size / 2;
    int leftSize = mid;
    int rightSize = size - mid;

    size /= 2;

    int *leftHalf = malloc(leftSize * sizeof(*leftHalf));
    int *rightHalf = malloc(rightSize * sizeof(*rightHalf));

    for (int i = 0; i < leftSize; i++) {
        leftHalf[i] = array[i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightHalf[i] = array[i + mid];
    }

    mergeSort(leftHalf, leftSize);
    mergeSort(rightHalf, rightSize);

    sort(array, leftHalf, rightHalf, leftSize, rightSize);

    free(leftHalf);
    free(rightHalf);
}
