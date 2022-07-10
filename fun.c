#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * printstring - print a string
 * @args: the String to print 
 *
 * Return: i int 
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
	return (i);
}
/**
 * printcharacter - print a char
 * @args: the char a print 
 *
 * Return: i int 
 */
int printcharacter(va_list args)
{

	_putchar(va_arg(args, int));

	return (1);
}
/**
 * printpercent - print percent
 * @args: argument type va_list 
 *
 * Return: i int 
 */
int printpercent(va_list args)
{    
	(void)args;
	_putchar('%');
/** unsigned int to binnary "%b"*/





	return (1);
}
