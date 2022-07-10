#include "main.h"
#include <stdarg.h>
/**
 * get_function - fun
 * @s: char to define fun
 * @li: va_list
 * Return: int
 */
int get_function(const char s, va_list args)
{
	int i = 0, count = 0;
	print_t print[] = {
		{'c', printcharacter},
		{'s', printstring},
		{'d', printint},
		{'i', printint},
		{'%', printpercent}};
	while (print[i].c != 0)
	{
		if (print[i].c == s)
		{
			count = count + print[i].f(args);
			return (count);
		}
		i++;
	}
	return (0);
}
