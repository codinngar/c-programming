#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

struct DynamicArray;

struct DynamicArray *createDynamicArray(void);
void push(struct DynamicArray *dynamicArray, int data);
void pop(struct DynamicArray *dynamicArray);
void destroyDynamicArray(struct DynamicArray *dynamicArray);

#endif
