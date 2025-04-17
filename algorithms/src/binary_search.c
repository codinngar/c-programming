#include "../include/binary_search.h"

int binarySearch(int array[], int size, int target) {
    int l = 0;
    int r = size - 1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (array[m] == target)
            return m;
        else if (array[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}
