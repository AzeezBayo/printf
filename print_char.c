#include "main.h"

/**
 * print_char - prints specifier %c
 * @ap: variadic parameter
 * Return: character printed
 */
int print_char(va_list ap)
{
	char c = (char)va_arg(ap, int);
	int count = 0;

	if (c)
	{
		count = write(1, &c, 1);
		return (count);
	}
	return (0);
}
