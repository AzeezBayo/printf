#include "main.h"

/**
 * print_string - prints specifier %c
 * @ap: variadic parameter
 * Return: character printed
 */
int print_string(va_list ap)
{
	char *s = va_arg(ap, char *);
	int count = 0;
	int i;

	if (s == NULL)
		return (-1);
	while (s[i])
	{
		count = write(1, &s[i], 1);
		i += 1;

	}
	return (count);
}
