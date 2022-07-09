#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
int _printf(const char *format, ...)
{
	int count;
	int (*function)(va_list);
	va_list (args);
	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			function = get_function(format);
			if (!format)
			{
				return (-1);
			}
			else if (function == NULL)
			{
				_putchar(*(format - 1));
				_putchar(*format);
				count += 1;
			}
		}
		else if (*format == '%' && *(format + 1) == '%')
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
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (1);
}
/**
 * printchracter
 */
int printcharacter(va_list args)
{
	_putchar(va_arg(args, int));

	return (1);
}
/**
 *
 */
