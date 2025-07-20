#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "print_utils.h"
#include "fn-protos.h"

#define MAX_SIZE      20
#define INITIAL_SIZE  10

int main() {
    srand(time(NULL));
    print_colored(COLOR_YELLOW, "Pls. enter 10 numbers to fill the array:\n");
    int nums[MAX_SIZE] = {0};
    int nums2[MAX_SIZE] = {0};
    int len = 0;
    take_user_input(nums, &len, INITIAL_SIZE);
    
    int choice;
    while (1) {   
	PRINT_ARRAY(nums, len);
	puts("\nChoose an operation:");
	puts("0. Exit the program");
	puts("1. Insert a number to the array");
	puts("2. Delete a number from the array");
	puts("3. Remove duplicates from the array");
	puts("4. Sort the array in ascending order");
	puts("5. Merge another array");
	puts("6. Find the max number");
	puts("7. Find a number");
	puts("8. Merge random sorted arrays");

	print_colored(COLOR_YELLOW, "Enter your choice: ");
	if (scanf("%d", &choice) != 1) {
	    puts("Invalid input. Exiting.");
	    break;
	}

	if (choice == 0) break;

	int num;
	switch(choice) {	    
	    case 1: {
		int pos;
		print_colored(COLOR_YELLOW, "Enter a number to insert and its position in the array: ");
		scanf("%d%d", &num, &pos);
		insert_number(nums, &len, num, pos);
		break;
	    }
	    case 2: {
		print_colored(COLOR_YELLOW, "Enter the number to delete: ");
		scanf("%d", &num);
		delete_number(nums, &len, num);
		break;
	    }
	    case 3: {
		remove_duplicates(nums, &len);
		break;
	    }
	    case 4: {     
		sort_ascending(nums, len, 1);
		break;
	    }
	    case 5: {
		print_colored(COLOR_YELLOW, "Pls. enter 10 numbers to fill the other array:\n");
		int len2 = 0;
		take_user_input(nums2, &len2, INITIAL_SIZE);
		PRINT_SECOND_ARRAY(nums2, len2);
		int *merged = malloc_int_variadic(2, len, len2);
		num = merge_sorted_arrays(nums, nums2, len, len2, merged);
		PRINT_MERGED_ARRAY(merged, num);
		free(merged);
		break;
	    }
	    case 6: {
		num = find_max(nums, len);
		print_colored(COLOR_GREEN, "Max num: %d\n", num);
		break;
	    }
	    case 7: {
		print_colored(COLOR_YELLOW, "Enter the number you want to find: ");
		scanf("%d", &num);
		num = find(nums, len, num);
		if (num > 0)
		    print_colored(COLOR_GREEN, "The number is found and its index: %d\n", num);
		/*  printf("The number is found and its index: %d\n", num); */
		else
		    print_colored(COLOR_RED, "The number is not found\n");
		break;
	    }
	    case 8: {
		while (1) {		  
		    int len3 = randint(5, 10);
		    int len4 = randint(7, 15);
		    int *arr3 = malloc(len3 * sizeof(int));
		    int *arr4 = malloc(len4 * sizeof(int));
		    fill_and_sort(arr3, len3, arr4, len4);
		    print_colored(COLOR_GREEN, "Below are the auto-generated sorted arrays for you to merge\n");
		    PRINT_RANDOM_ARRAY(arr3, len3);
		    PRINT_RANDOM_ARRAY(arr4, len4);
		    print_colored(COLOR_YELLOW, "Enter 1 for 'merging' OR 2 to re-generate\n");
		    scanf("%d", &num);
		    if (num == 1) {
			int *merged = malloc_int_variadic(2, len3, len4);
			num = merge_sorted_arrays(arr3, arr4, len3, len4, merged);
			PRINT_MERGED_ARRAY(merged, num);
			free(arr3);		     
			free(arr4);		     
			free(merged);		     
			break;
		    }
		    else if (num == 2) {
			free(arr3);
		        free(arr4);
			continue;
		    }
		}
	    }
 	}
    }
    
    return 0;
}
