#include "main.h"
/**
 * _printf - Print anything on the string
 * @format: A set of characters with conversion specifiers
 * Return: The number of
 */
int _printf(const char *format, ...)
{
	int i, j, n = 0;
	va_list list;
	char *s;

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i]  == '%')
		{
			if (format[i + 1] == 'c')
			{
				n += _putchar(va_arg(list, int));
				i++;
			}
			else if (format[i + 1] == 's')
			{
				s = va_arg(list, char *);
				j = 0;
				while (s[j] != '\0')
				{
					n += _putchar(s[j]);
					j++;
				}
				i++;
			}
			else if (format[i + 1]  == '%')
				n += _putchar(37);
		}
		else
			n += _putchar(format[i]);
	}
	va_end(list);
	return (n);
}
