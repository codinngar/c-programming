#include "../include/dynamic_array.h"

#include <stdio.h>
#include <stdlib.h>

struct DynamicArray {
    int size;
    int numOfElements;
    int *array;
};

struct DynamicArray *createDynamicArray(void) {
    struct DynamicArray *dynamicArray = malloc(sizeof(*dynamicArray));

    if (dynamicArray == NULL) {
        fprintf(stderr, "Error while creating dynamic array");
        exit(EXIT_FAILURE);
    } else {
        dynamicArray->size = 1;
        dynamicArray->numOfElements = 0;
        dynamicArray->array = malloc(sizeof(int));
    }

    return dynamicArray;
}

static void growArray(struct DynamicArray *dynamicArray) {
    int *newArray = realloc(dynamicArray->array, (dynamicArray->size * 2) * sizeof(int));

    if (newArray == NULL) {
        fprintf(stderr, "Error while growing dynamic array");
        exit(EXIT_FAILURE);
    } else {
        dynamicArray->array = newArray;
        dynamicArray->size *= 2;
    }
}

static void shrinkArray(struct DynamicArray *dynamicArray) {
    int *newArray = realloc(dynamicArray->array, (dynamicArray->size / 2) * sizeof(int));

    if (newArray == NULL) {
        fprintf(stderr, "Error while shrinking dynamic array");
        exit(EXIT_FAILURE);
    } else {
        dynamicArray->array = newArray;
        dynamicArray->size /= 2;
    }
}

void push(struct DynamicArray *dynamicArray, int data) {
    if (dynamicArray->numOfElements == dynamicArray->size) {
        growArray(dynamicArray);
    }

    dynamicArray->array[dynamicArray->numOfElements++] = data;
}

void pop(struct DynamicArray *dynamicArray) {
    if (dynamicArray->numOfElements >= 1) {
        dynamicArray->array[--dynamicArray->numOfElements] = 0;
    }

    if (dynamicArray->numOfElements == (dynamicArray->size / 2) && dynamicArray->size > 1) {
        shrinkArray(dynamicArray);
    }
}

void destroyDynamicArray(struct DynamicArray *dynamicArray) {
    if (dynamicArray) {
        free(dynamicArray->array);
        free(dynamicArray);
    }
}
