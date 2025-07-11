#include <stdio.h>
#include <stdarg.h>
#include "fn-protos.h"

void print_colored(Color color, char *format, ...) {
    char *color_code;

    switch (color) {
        case COLOR_RED:
            color_code = "\033[0;31m";
            break;
        case COLOR_GREEN:
            color_code = "\033[0;32m";
            break;
        case COLOR_YELLOW:
            color_code = "\033[0;33m";
            break;
        default:
            color_code = "\033[0m";  /* Reset */
    }

    printf("%s", color_code);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\033[0m");  /* Reset color */
}
