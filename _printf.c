#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
int printcharacter(va_list args);
int printstring(va_list args);
int printinteger(va_list args);

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int j;
	int length = 0;
	print_t print[] = {
		{"c", printcharacter},
		{"s", printstring},
		{"i", printinteger},
		{NULL, NULL}};
	va_start(args, format);
	if ((format) == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while(format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			j = 0;
			while (print[j].type != NULL)
			{
				if (format[i + 1] == print[j].type)
				{
					length = length + print[j].f(args);
					i++;
				}
				j++;
			}
		}
		else if (format[i] == '%' && format[i + 1] == '%')

		{
			_putchar('%');
			i++;
			length = length + 1;
		}
		else
		{ _putchar(format[i]);
		i++;
		}
		i++;
	}

	va_end(args);
	return (length);
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
	return (EXIT_SUCCESS);
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
	return (EXIT_SUCCESS);
}
