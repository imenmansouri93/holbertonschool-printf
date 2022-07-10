#include "main.h"
int get_function(const char c, va_list li)
{
	int i = 0,count = 0;
	print_t print[] = {
		{'c', printcharacter},
		{'s', printstring}
	};
	while(li[i].c != 0)
	{
		if (li[i].c == c)
		{
			count = count + li[i].f(li);
			return(count);
		}
		i++;
	}
	return(0);
}
