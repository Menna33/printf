#include "main.h"
/**
 * _printf - Entry point
 * @format:..
 * Return: integer
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	va_list args;
	sp_t conv[] = {
		{"c", _printf_char},
		{"s", _printf_str},
		{"%", _printf_percent},
		{"i", printf_int},
		{"d", printf_dec},
		{"b", binary},
		{NULL, NULL}
	};
	int i, j;
	int len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			len++;
			write(1, &format[i], 1);
		}
		else
		{
			i++;
			j = 0;
			while (j < 6)
			{
				if (format[i] == conv[j].sp[0])
				{
					len = len + conv[j].f(args);
					break;
				}
				j++;
			}
			if (j == 6)
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				len = len + 2;
			}

		}
		i++;
	}
	va_end(args);
	return (len);
}
