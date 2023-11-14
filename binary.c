#include "main.h"

/**
 * binary - print binary
 * @args:..
 * Return: integer
 */
int binary(va_list args);
int binary(va_list args)
{
	char *bin;
	int num = va_arg(args, int);
	int n = num;
	int nlen = 0;
	char temp;
	int i;

	if (num < 0)
	{
		num = -(num);
	}
	while (num != 0)
	{
		nlen++;
		num = num / 2;
	}
	bin = malloc((nlen + 1) * sizeof(char));
	if (bin == NULL)
	{
		return (-1);
	}
	else
	{
		i = 0;
		while (n != 0)
		{
			bin[i] = (n % 2) + '0';
			n = n / 2;
			i++;
		}
		bin[i] = '\0';
		for (i = 0; i < (nlen / 2); i++)
		{
			temp = bin[i];
			bin[i] = bin[nlen - i - 1];
			bin[nlen - i - 1] = temp;
		}
		for (i = 0; i < nlen; i++)
		{
			_putchar(bin[i]);
		}
		free(bin);
	}
	return (nlen);
}
