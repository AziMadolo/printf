#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - It produces the output according to the format.
 * @char: string of character
 * @*format: It is character sring.
 *
 * Return: It returns the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char current;

	int num_chars_printed = 0;
	va_start(args, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		current = format[i];
		if (current == '%')
		{
			current = format[++i];
			switch (current)
			{
				case 'c':
					num_chars_printed + fprintf(stdout, "%c", va_arg(args, int));
					break;

				case 's':
					num_chars_printed += fprintf(stdout, "%s", va_arg(args, const char*));
					break;

				case '%':
					num_chars_printed += fprintf(stdout, "%c", current);
					break;

				default:
					break;
			}
		}
		else
		{
			num_chars_printed += fprintf(stdout, "%c", current);
		}
	}

	va_end(args);
	return (num_chars_printed);
}
