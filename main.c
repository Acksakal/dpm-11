#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE      20
#define INITIAL_SIZE  10

void print_array(int *, int);
void delete_number(int *, int *, int);
void insert_number(int *, int *, int, int);
void remove_duplicates(int *, int *);
void sort_ascending(int *, int, int);

int main() {
    srand(time(NULL));
    puts("Pls. enter 10 numbers to fill the array: ");
    int nums[MAX_SIZE] = {0};
    int count;
    for (count = 0; count < INITIAL_SIZE;) {
	printf("Array element No.%d = ", count + 1);
	if (scanf("%d", &nums[count]) == 1)
	    count++;
	else {
	    printf("Invalid input. Please enter a valid number.\n");

	    /* flush the input buffer up to the newline */
	    int ch;
	    while ((ch = getchar()) != '\n' && ch != EOF);
	}
    }
    
    int choice;
    while (1) {        
	print_array(nums, count);
	puts("\nChoose an operation:");
	puts("1. Insert a number to the array");
	puts("2. Delete a number from the array");
	puts("3. Remove duplicates from the array");
	puts("4. Sort the array in ascending order");
/*	puts("4. Sort the array in ascending order");
	puts("5. Merge another array");
	puts("6. Merge another array and sort the resulting");
	puts("0. Exit"); */

	printf("Enter your choice: ");
	if (scanf("%d", &choice) != 1) {
	    puts("Invalid input. Exiting.");
	    break;
	}

	if (choice == 0) break;

	int num;
	switch(choice) {	    
	    case 1: {
		int pos;
		printf("Enter a number to insert and its position in the array: ");
		scanf("%d%d", &num, &pos);
		insert_number(nums, &count, num, pos);
		break;
	    }
	    case 2: {
		printf("Enter number to delete: ");
		scanf("%d", &num);
		delete_number(nums, &count, num);
		break;
	    }
	    case 3: {
		remove_duplicates(nums, &count);
		break;
	    }
	    case 4: {     
		sort_ascending(nums, count, 1);
		break;
	    }
 	}
    }
    
    return 0;
}
