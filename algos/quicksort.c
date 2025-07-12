#include <stdio.h>

void print_array(int *arr, size_t len);
void quicksort(int *arr, size_t len);

int main() {

    int a[] = {20, 142, 17, 12, 15, 115, 46, 8};
    size_t len = sizeof(a) / sizeof(*a);

    quicksort(a, len);
    print_array(a, len);
    
    return 0;
}

void quicksort(int *arr, size_t len) {
    if (len <= 1) return;
    int pivot = arr[len - 1];
    int i = -1, j;
    for (j = 0; j < len - 1; j++) {
	if (arr[j] <= pivot) {
	    i++;
	    if (i != j) {
		arr[i] ^= arr[j];
		arr[j] ^= arr[i];
		arr[i] ^= arr[j];
	    }
/*		arr[i] ^= arr[j];
		arr[j] ^= arr[i];
		arr[i] ^= arr[j]; prikol! */
	}
    }
    int temp = arr[i+1];
    arr[i+1] = arr[len-1];
    arr[len-1] = temp;
    
    quicksort(arr, i + 1);
    quicksort(&arr[i+2], len - (i+2));
}

void print_array(int *arr, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf("%d ", arr[i]);
    printf("\n");
}
