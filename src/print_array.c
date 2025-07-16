#include <stdio.h>

void print_array(int *arr, size_t length) {
    size_t i;
    printf("The resulting array: [");
    for (i = 0; i < length; i++) {	
	printf("%d%s", arr[i], i < length - 1 ? ", " : "]");
    }
    printf("\n");
}
