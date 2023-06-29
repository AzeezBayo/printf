#include <stdio.h>

int _printf(const char *format, ...);
int (*find_function(const char *format))(va_list);

#include "main.h"
/**
  * find_function - that finds formats for _printf
  * calls the corresponding function.
  * @format: format (char, string, int, decimal)
  * Return: NULL or function associated ;
  */
int (*find_function(const char *format))(va_list)
{
	int i = 0;

	code_f find_f[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_pcnt},
		{NULL, NULL}};

	while (find_f[i].sc != NULL)
	{
		if (find_f[i].sc[0] == *format)
			return (find_f[i].f);
		i++;
	}
	return (NULL);
}
/**
  * _printf - function that produces output according to a format.
  * @format: format (char, string, int, decimal)
  * Return: size the output text;
  */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list), i, count, cprint = 0;

	count = 0;

	va_start(ap, format);

	if (format == NULL)
		return (-1);

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			cprint = write(1, &format[i], 1);
			count += cprint;
			i++;
			continue;
		}

		if (format[i] == '%')
		{
			f = find_function(&format[i + 1]);
			if (f != NULL)
			{
				cprint = f(ap);
				count += cprint;
				i += 2;
				continue;
			}
		}
		
		if (!format[i + 1] == '\0')
		{
			break;
		}

	}
	va_end(ap);
	return (count);
}
