#include <stdio.h>

int find(int *, int, int);

void delete_number(int *arr, int *len, int num_to_del) {
    int pos = find(arr, *len, num_to_del);
    if (pos == -1) {
	printf("Number %d not found in the array\n", num_to_del);
	return;
    }
    int i;
    for (i = pos; i < *len - 1; i++) {
	arr[i] = arr[i + 1];
    }
    
    (*len)--;
} 
