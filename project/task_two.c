#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - a function that produces output according to a format
 * @format: a pointer to a format string containing conversion specifiers
 * @count - count the number of character printed
 * @c - character
 * Return: count
**/

int _printf(const char *format, ...)
{
	int count;
	va_list args;

	va_start(args, format);

	count = 0;

	while (*format != '\0')
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			int num = va_arg(args, int);

			count += printf("%d", num);
			 format++;
		} else
			{
				count += putchar(*format);
			}
		format++;
	}
	printf("\n");
	va_end(args);
	return (count);
}
