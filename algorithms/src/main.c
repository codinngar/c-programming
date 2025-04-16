#include <stdio.h>
#include "binary_search.h"

int main(void) {
    int array[] = {1, 2, 3, 4};
    size_t size = 4;
    int target = 3;
    
    int index = binarySearch(array, size, target);
    
    printf("%d\n", index);
    
    return 0;
}
