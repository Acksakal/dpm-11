#include <stdio.h>
#include <stdarg.h>

typedef enum {
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW
} Color;

void fprintf_colored(FILE *stream, Color color, char *format, ...) {
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
            color_code = "\033[0m";
    }

    fprintf(stream, "%s", color_code);

    va_list args;
    va_start(args, format);
    vfprintf(stream, format, args);
    va_end(args);

    fprintf(stream, "\033[0m");
}
