#include <stdio.h>
#include <stdlib.h>
#include "static_array.h"

int* createStaticArray(size_t size) {
    int *sa = malloc(size * sizeof(*sa));
    
    if (sa == NULL) {
        fprintf(stderr, "Error while creating static array");
        exit(EXIT_FAILURE);
    }
    
    return sa;
}

void destroyStaticArray(int *sa) {
    if (sa) {
        free(sa);
    }
}