#include "../include/dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

struct DA {
  int size;
  int elements;
  int *array;
};

struct DA *createDynamicArray(void) {
  struct DA *da = malloc(sizeof(*da));

  if (da == NULL) {
    fprintf(stderr, "Error while creating dynamic array");
    exit(EXIT_FAILURE);
  } else {
    da->size = 1;
    da->elements = 0;
    da->array = malloc(sizeof(int));
  }

  return da;
}

void growArray(struct DA *da) {
  int *newArray = realloc(da->array, (da->size * 2) * sizeof(int));

  if (newArray == NULL) {
    fprintf(stderr, "Error while growing dynamic array");
    exit(EXIT_FAILURE);
  } else {
    da->array = newArray;
    da->size *= 2;
  }
}

void shrinkArray(struct DA *da) {
  int *newArray = realloc(da->array, (da->size / 2) * sizeof(int));

  if (newArray == NULL) {
    fprintf(stderr, "Error while shrinking dynamic array");
    exit(EXIT_FAILURE);
  } else {
    da->array = newArray;
    da->size /= 2;
  }
}

void push(struct DA *da, int data) {
  if (da->elements == da->size) {
    growArray(da);
  }

  da->array[da->elements++] = data;
}

void pop(struct DA *da) {
  if (da->elements >= 1) {
    da->array[--da->elements] = 0;
  }

  if (da->elements == (da->size / 2) && da->size > 1) {
    shrinkArray(da);
  }
}

void destroyDynamicArray(struct DA *da) {
  if (da) {
    free(da->array);
    free(da);
  }
}
