#include "main.h"
int(*get_function(const char *fmt))(va_list)
{
    int i;
    print_t print[] = {
        {"c", printcharacter},
        {"s", printstring},
        {NULL, NULL}};
    for (i = 0; print[i].type; i++)
     if (*fmt == print[i].type[0])
        {
            return (print[i].f);
        }
        return (NULL);
}