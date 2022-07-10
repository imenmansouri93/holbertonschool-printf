#include "main.h"
#include <stdarg.h>
/**
 * get_function - fun
 * @s: char to define fun
 * @li: va_list
 * Return: int
 */
int get_function(const char s, va_list li)
{
	int i = 0, count = 0;
	print_t print[] = {
		{'c', printcharacter},
		{'s', printstring}};
	while (print[i].c != 0)
	{
		if (print[i].c == s)
		{
			count = count + print[i].f(li);
			return (count);
		}
		i++;
	}
	return (0);
}
