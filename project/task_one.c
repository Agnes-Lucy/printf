#include <stdio.h>
#include <stdarg.h>

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
					count += putchar(va_arg(args, int));
				break;
				case 's':
					count += printf("%s", va_arg(args, char *));
				break;
				case '%':
					 count += putchar('%');
				break;
			default:
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
