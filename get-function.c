#include "main.h"
#include <stdarg.h>
int get_function(const char s, va_list li)
{
	int i = 0,
	print_t print[] = {
		{'c', printcharacter},
		{'s', printstring}
       
	};
	while(print[i].c != 0)
	{
		if (print[i].c == s)
		{
	      return(print[i].f(li));
		}
		i++;
	}
	return(0);
}
