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
	
va_start(args, format);
	while (*format)
	{
		if (*format !='%')
		{
			putchar(*format);
			format++;
		}
		else
		{
			format++;
			switch (*format)
			{
			case'c':
				
				printcharacter(args);
				format++;
				break;
			case'd':
				
				printinteger(args);
				format++;
				break;
			case's':
				printstring(args);
				format++;
				break;
			
			default:
				format--;
				putchar(*format);
				format++;
				break;
			}
		}
	}
	
return(1);
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
