#include <stdio.h>
#include <math.h>

int two_crystal_balls(int *, int);

int main() {

    int a[] = {0,0,0,0,0,0,1,1,1};
    size_t len = sizeof(a) / sizeof(*a);

    int broken = two_crystal_balls(a, len);

    printf("%d\n", broken);
    
    return 0;
}

int two_crystal_balls(int *arr, int len) {
    int jmp_amount = (int)floor(sqrt(len));

    int i = jmp_amount;
    for (; i < len; i += jmp_amount) {
	printf("%d\n", i);
	if (arr[i]) {
	    break;
	}
    }

    i -= jmp_amount;

    for (int j = 0; j < jmp_amount && i < len; ++j, ++i) {
	printf("%d and %d\n", i, j);
	if (arr[i]) {
	    return i;
	}
    }

    return -1;
}
