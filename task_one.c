#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - a function that produces output according to a format
 * @format: a pointer to a format string containing conversion specifiers
 * @count - count the number of character printed
 * @c - character
 * @s - string
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
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
				break;
				case 's':
					count += printf("%s", va_arg(args, char *));
				break;
				case '%':
					putchar('%');
					count++;
				break;
			default:
					break;
			}

		} else
			{
				putchar(*format);
				count++;
			}
		format++;
	}
	va_end(args);
	return (count);
}
