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
	if (str[i] == '\0')
	{
		i++;
		return (1);

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
	return (1);
}
/**
 * printint - print a int
 * @args: the char a print
 *
 * Return: i int
 */
int printint(va_list args)
{
	int count = 0, rest = 1, n;
	unsigned int x;

	n = va_arg(args, int);
	x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
		++count;
	}
	while ((x / rest) > 9)
	{
		rest = rest * 10;
	}
	while (rest > 0)
	{
		_putchar(x / rest + '0');
		x = (x % rest);
		rest = rest / 10;
		++count;
	}
	return (count);
}
/**
 * reverseStr - prints the reversed string
 * @args: the char a print
 *
 * Return: i int
 */
int reverseStr(va_list args)

{
int n = 0, count = 0;
char *str;
str = va_arg(args, char *);
n = strlen(str) - 1;
while (n >= 0)
{
_putchar (*(str + n));
n--;
count ++;
}
return(count);
}
