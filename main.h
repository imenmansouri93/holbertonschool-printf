#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>

/**
 * 
 *
 */

typedef struct print
{
    char *type;
    int (*f)(va_list args);
}print_t;

int _putchar(char c);
int _printf(const char *format, ...);
#endif 
