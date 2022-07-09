#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
int printcharacter(va_list args);
int printstring(va_list args);
int printinteger(va_list args);
int printfloat(va_list args);
int _printf(const char *format, ...)
{
unsigned int i;
unsigned int count = 0;
va_list(args);
va_start(args, format);
if (!*format)
{
return(-1);
}
while (*format)
{
print_t print[] = {
{"c", printcharacter},
{"s", printstring},
{"i", printinteger},
{"d", printfloat },
{NULL, NULL}
};
if (*format == '%' && *(format+1)!='%' )
{
format++;
for (i = 0; print[i].type; i++)
{
if (*format == print[i].type[0])
{
return (print[i].f)(args);
}else if (*format != print[i].type[0])
{
_putchar (*(format));
count+=2;
}
}
}else if (*format == '%' && *(format + 1) == '%')
{
format++;
_putchar('%');
count++;
}
else 
{
_putchar(*format);
count++;
}
format++;
}
va_end(args);
return(count);
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
		str = "null";
	}
	while (str[i])
		{
			putchar(str[i]);
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
/**
 *
 */
int printinteger(va_list args)
{
	int num = 0;
	num = va_arg(args, int);
	if (num / 10 != 0)
	{
		if (num > 0)
		{
			_putchar(num % 10 + '0');
		}
		else
		{
			_putchar(-num % 10 + '0');
		}
	}
	else if ((num / 10 == 0) && (num % 10 != 0) && (num > 0))
	{
		_putchar(num % 10 + '0');
	}
	else if ((num / 10 == 0) && (num % 10 != 0) && (num <= 0))

	{
		_putchar('-');
		_putchar(-num % 10 + '0');
	}
	return (1);
}
/**
 *
 */
int printfloat(va_list args)
{
	int n;
	n = va_arg(args, double);
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		_putchar(n / 10);
	}
	return (1);
}
