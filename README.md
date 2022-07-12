
# Printf:

C uses printf() function to write from the input devices. This function has been declared in the header file called stdio.h . Any text written within the pair of quotes ("") is displayed as such by printf() function on the screen. However, this function is much more powerful than puts() in the sense that it can display all types of data on the screen by using different format specifiers within a pair of quotes

## _printf:
 A function that produces output according to a format
### Prototype: 
int _printf(const char *format, ...):
this function produces output under the control of a format string that specifies how arguments are converted for output. 

# Environment
 main.h: header file define prototypes, struct and libraries  
_putchar.c: file contains function that writes single chracter to stdout
fun.c: contains the functions to print:
- print-string: int printstring(va_list args)
- print-char: int printcharacter(va_list args)
- print-int&decimal: int printint(va_list args)
- print-reversstring: int reverseStr(va_list args)
get-function.c: contains the function: get_function(const char s, va_list args)
this function called by _printf and cheks for valid conversion specifier when it finds a % character . the get function will check for the right conversion specifier, it return the corresponding function.

_print.c: definition for _printf
## Usage/Examples
String: _printf("%s\n, Holberthon);
output: Holberthon
Character: _printf("%c\n, H);
output: H
Decimal: _printf("%d\n, 808);
output: 808
Integer: _printf("%i\n, 8);
output: 8
ReverseString: _printf("%r\n, Holberthon);
output: nohtrebloH
## Declaration int _printf(const char *format, ...)
_printf("my %s is %d", "number" 1024)
## Authors

- [@majdideveloper](https://github.com/majdideveloper)
- [@imenmansouri93](https://github.com/imenmansouri93)

