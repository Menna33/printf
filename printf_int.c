#include "main.h"
/**
 * printf_int - prints integer
 * @args: argument to print
 * Return: number of characters printed
 */
int printf_int(va_list args)
{

int num, digit, base = 1, count = 0;
num = va_arg(args, int);
if(num == 0)
{
_putchar('0');
return(1);  
}
if (num < 0)
{
num = -1 * num;
_putchar('-');
count++;
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
 * printf_dec - prints decimal number
 * @args: argument to print
 * Return: number of characters printed
 */
int printf_dec(va_list args)
{

int num, digit, base = 1, count = 0;
num = va_arg(args, int);
if(num == 0)
{
_putchar('0');
return(1);  
}
if (num < 0)
{
num = -1 * num;
_putchar('-');
count++;
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
