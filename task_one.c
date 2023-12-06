#include <stdio.h>
#include  <stdarg.h>

/**
 * _printf - a function that produces output according to a format
 * @count - count the number of character printed
 * @c - character
 * Return: 0
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
				case 'c': {
						  char c = (char) va_arg(args, int);
						  putchar (c);
						  count++;
					  }
						  break;
			case 's': {
					  const char *s = va_arg(args, const char *);
					  while (*s != '\0')
					  {
						  putchar(*s);
						  s++;
						  count++;
				 	  }
					  break;
				  }
			case '%':
				  putchar('%');
				  count++;
				  break;
			case 'd':
				  case 'i': {
						    int num = va_arg(args, int);
						    printf("%d", num);
						    count++;
						    break;
					    }
				 case 'u': {
						   unsigned int num = va_arg(args, unsigned int);
						   printf("%u", num);
						   count++;
						    break;
					   }
				  case 'o': {
						    unsigned int num = va_arg(args, unsigned int);
						    printf("%o", num);
						    count++;
						    break;
					    }
				 case 'x':
					     case 'X': {
							       unsigned int num = va_arg(args, unsigned int);
							       printf("%x", num);
							       count++;
							        break;
						       }
					     case 'p': {
							       void *ptr = va_arg(args, void *);
							       printf("%p", ptr);
							       count++;
							       break;
						       }
				              default:
						        putchar('%');
							putchar(*format);
							count += 2;
							break;
			}

		} else {
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return count;
}
