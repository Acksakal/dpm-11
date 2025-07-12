#include <stdio.h>

int binary_search(int *arr, size_t len, int value);
/* void print_array(int *arr, size_t len); */

int main() {

    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    size_t len = sizeof(nums) / sizeof(*nums);
    int target_value;
    printf("Enter the number: ");
    scanf("%d", &target_value);
    int index = binary_search(nums, len, target_value);

    printf("%d\n", index);
    
    return 0;
}

int binary_search(int *arr, size_t len, int value) {
    size_t low = 0;
    size_t high = len;
    size_t m;
    
    do {
	m = (low + high) / 2;
	if (value == arr[m])
	    return m;
	else if (value > arr[m])
	    low = m + 1;
	else
	    high = m;
    } while (low < high);
    
    return -1;
}

/*
void print_array(int *arr, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf("%d ", arr[i]);
    printf("\n");
}
*/
