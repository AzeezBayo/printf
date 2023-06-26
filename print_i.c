#include "main.c"
#include <string.h>
#include <stdio.h>

/**
 * print_int - prints int using _putchar
 * @n: integer
 * Return: int
 */
int print_int(va_list n)
{
	int a, p10 = 1, len = 0, i, j;
	unsigned int resul, resul1;

	a = va_arg(n, int);

	if (a < 0)
	{
		len = len + _putchar('-');
		resul = a * -1;
	}
	else
		resul = a;
	resul1 = resul;

	for (i = 0; resul1 > 9; i++)
	{
		p10 *= 10;
		resul1 /= 10;
	}
	j = 0;
	while (j <= 0)
	{
		len = len + _putchar(resul / p10 + '0');
		resul = resul % p10;
		p10 = p10 / 10;
		j++;
	}
	return (len);
}
