#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
int printcharacter(va_list args);
int printstring(va_list args);
int (*check_character_string(const char *next, int A))(va_list)
{
	int j;
	print_t options[] = {
		{"c", printcharacter},
		{"s", printstring},
		{"d", printinteger},
		{NULL, NULL}};
	for (j = 0; options[j].type != '\0'; j++)
	{
		if (options[j].type[0] == next[A])
			return ((options[j].f));
	}
	return (NULL);
}
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i = 0;
	unsigned int length = 0;
	va_start(args, format);
	if ((!format) || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				i = i + 1;
				length++;
			}
			else if (check_character_string(format, i + 1) != '\0')
			{
				length += check_character_string(format, i + 1)(args);
				i = i + 1;
			}
			else
			{
				_putchar(format[i]);
				length++;
			}
		}
		else
		{
			_putchar(format[i]);
			length++;
		}
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
	int num,
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
		putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		print(n / 10);
	}
	return (EXIT_SUCCESS);
}