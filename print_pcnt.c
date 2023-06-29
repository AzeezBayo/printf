#include "main.h"

/**
 * print_pcnt - prints specifier %
 * @ap: variadic parameter
 * Return: character printed
 */
int print_pcnt(va_list ap)
{
	(void)ap;

	write(1, "%", 1);

	return (1);
}
