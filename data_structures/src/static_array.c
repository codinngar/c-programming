#include "../include/static_array.h"

#include <stdio.h>
#include <stdlib.h>

int *createStaticArray(int size) {
    int *staticArray = malloc(size * sizeof(*staticArray));

    if (staticArray == NULL) {
        fprintf(stderr, "Error while creating static array");
        exit(EXIT_FAILURE);
    }

    return staticArray;
}

void destroyStaticArray(int *staticArray) {
    if (staticArray) {
        free(staticArray);
    }
}
