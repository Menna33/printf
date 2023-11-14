#include "main.h"
/**
 * reverse_str - reverse string
 * @args:..
 * Return: integer
 */
int reverse_str(va_list args);
int reverse_str(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;
	int j;

	while (str[i] != '\0')
	{
		i++;
	}
	for (j = i; j >= 0; j--)
	{
		write(1, &str[j], 1);
	}
	return (i);
}
