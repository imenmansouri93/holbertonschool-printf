#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
int printcharacter(va_list args);
int printstring(va_list args);
int _printf(const char *format, ...)
{
va_list args;
const char *p;
int count = 0;
if (format == NULL)
{
return (-1);
}
va_start(args, format);
for (p = format; *p ; p++)
{
if (*p == '%' && *p + 1 == '%')
{
_putchar(*p), count++;
continue;
}
else if(*p == '%' && *p + 1 != '%')
switch (*++p)
{
case 'c':
count += printcharacter(args);
break;
case 's':
count += printstring(args);
break;
case '%':
_putchar('%'); count++;
break;
default:
_putchar('%'), _putchar(*p), count += 2;
break;
}
}
return (count);
}

/**
 * printstring
 */
int printstring(va_list args)
{
    char *str;
    int i = 0;
    str = va_arg(args, char *);
    if (str == NULL)
    {
        str = "(null)";
    }
    while (*str)
    {
        putchar(*str);
        i++;
    }
    return (i);
}
/**
 * printchracter
 */
int printcharacter(va_list args)
{
    int x = 0;
    x = va_arg(args, int);
    _putchar(x);
	return (1);
}

