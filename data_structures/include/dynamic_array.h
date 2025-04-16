#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

struct DA;

struct DA* createDynamicArray(void);
void push(struct DA *da, int data);
void pop(struct DA *da);
void destroyDynamicArray(struct DA * da);

#endif