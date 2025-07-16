#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "fn-protos.h"

int *malloc_int_variadic(int count, ...) {
    int total_size = 0;

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        int size = va_arg(args, int);
        total_size += size;
    }

    va_end(args);

    int *chunk = malloc(total_size * sizeof(int));
    if (chunk == NULL) {
	fprintf_colored(stderr, COLOR_RED, "Warning: memory allocation failed!\n");
	return NULL;
    }
    return chunk;
}
