#include <stdio.h>

void take_user_input(int *arr, int *len, int initial_size) {
    while (*len < initial_size) {
	printf("Array element No.%d = ", *len + 1);
	if (scanf("%d", &arr[*len]) == 1)
	    (*len)++;
	else {
	    printf("Invalid input. Please enter a valid number.\n");

	    /* flush the input buffer up to the newline */
	    int ch;
	    while ((ch = getchar()) != '\n' && ch != EOF);
	}
    }
}
