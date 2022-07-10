#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
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
{    int x = 0;
	x = va_arg(args, int);
	_putchar(x);

	return (1);
}

