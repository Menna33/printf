#include "main.h"
/**
 * _printf_percent - Entry point
 * @args:..
 * Return: integer
 */
int _printf_percent(va_list args __attribute__((unused)))
{
	return (write(1, "%", 1));
}
/**
 * _printf_char - Entry point
 * @args:..
 * Return: integer.
 */
int _printf_char(va_list args);
int _printf_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}
/**
 * _printf_str - print string
 * @args:..
 * Return: integer.
 */
int _printf_str(va_list args);
int _printf_str(va_list args)
{
	char *str = va_arg(args, char*);
	int i = 0;
	int len = 0;

	if (str == NULL)
	{
		return (-1);
	}
	else
	{
		while (str[i] != '\0')
		{
			len++;
			i++;
		}
		if (len == 0)
		{
			return (0);
		}
		write(1, str, len);
	}
	return (len);
}
