#include "main.h"

/**
 * print_number_u - prints unsigned integers
 * @num: unsigned integer
 * Return: number of printed digits
 */
int print_number_u(unsigned int num)
{
long digit, base = 1, count = 0;
if (num == 0)
{
_putchar('0');
return (1);
}
digit = num / 10;
while (num / base != 0)
{
base = base * 10;
digit = digit / 10;
}
base = base / 10;
while (base > 0)
{
_putchar((num / base)  +'0');
num = num - ((num / base) *base);
base = base / 10;
count++;
}
return (count);
}

/**
 * print_u - Prints unsigned integers
 * @args: Argument to print
 * Return: Length of printed number
 */
int print_u(va_list args)
{
	unsigned int num;
	int count;

	num = va_arg(args, unsigned int);

	count = print_number_u(num);
	return (count);
}

/**
 * print_o - Prints octals
 * @args: Argument to print
 * Return: length of printed number
 */
int print_o(va_list args)
{
	unsigned int number;
	int len, i;
	long result[50];

	number = va_arg(args, unsigned int);
	if (number == 0)
	{
		print_number_u(0);
		return (1);
	}
	for (len = 0; number > 0; len++)
	{
		result[len] = number % 8;
		number = number / 8;
	}
	for (i = len - 1; i >= 0; i--)
		print_number_u(result[i]);
	return (len);
}

/**
 * print_x - Prints hexadecimals
 * Description: This function prints hexadecimals
 * @args: Argument to print
 * Return: length of @args
 */
int print_x(va_list args)
{
	unsigned int number;
	int len, i, result[32];

	number = va_arg(args, unsigned int);
	if (number == 0)
	{
		print_number_u(0);
		return (1);
	}
	for (len = 0; number > 0; len++)
	{
		result[len] = number % 16;
		number = number / 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (result[i] >= 10)
			_putchar(result[i] + 87);
		else
			_putchar(result[i] + 48);
	}
	return (len);
}

/**
 * print_X - Prints hexadecimals in uppercase
 * Description: This function prints hexadecimals in uppsercase
 * @args: Argument to print
 * Return: length of @args
 */
int print_X(va_list args)
{
	unsigned int number;
	int len, i, result[32];

	number = va_arg(args, unsigned int);
	if (number == 0)
	{
		print_number_u(0);
		return (1);
	}
	for (len = 0; number > 0; len++)
	{
		result[len] = number % 16;
		number = number / 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (result[i] >= 10)
			_putchar(result[i] + 55);
		else
			print_number_u(result[i]);
	}
	return (len);
}
