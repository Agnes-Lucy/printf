#include "main.h"
#include <stdio.h>

/**
 * _printf - Custom printf function with limited conversion specifiers
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int print_binary(unsigned int n);
int _printf(const char *format, ...)
{
	int count;
	va_list args;

	count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += putchar(va_arg(args, int));
				break;
				case 's':
					count += printf("%s", va_arg(args, char *));
				break;
				case '%':
					count += putchar('%');
				break;
				case 'b':
					count += print_binary(va_arg(args, unsigned int));
				break;

				default:
					count += putchar('%');
					count += putchar(*format);
				break;
			}
		} else
			{
				count += putchar(*format);
			}
		format++;
	}
	va_end(args);

	return (count);
}

/**
 * print_binary - Print binary representation of an unsigned integer
 * @n: Unsigned integer to be printed in binary
 *
 * Return: Number of characters printed
 */

int print_binary(unsigned int n)
{
	if (n == 0)
	{
		return (putchar('0'));
	}
	else if (n == 1)
	{
		return (putchar('1'));
	}
	else
	{
		return (print_binary(n / 2) + putchar('0' + n % 2));
	}
}
