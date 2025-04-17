int* mergeSort(int array[], int size) {
    if (size == 1) return array;

    int mid = size / 2;
    int leftSize = mid;
    int rightSize = size - mid;

    int leftHalf[leftSize];
    int rightHalf[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftHalf[i] = array[i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightHalf[i] = array[i + mid];
    }

    mergeSort(leftHalf, leftSize);
    mergeSort(rightHalf, rightSize);
}
