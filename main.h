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
    void (*f)(va_list args);
}print_t;

int _putchar(char c);
int _printf(const char *format, ...);
#endif
#ifdef MAIN_H
#define MAIN_H
#include<unistd.h>
int _putchar(char c);

#endif 
