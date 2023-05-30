<<<<<<< HEAD
u#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**

_printf - Printf function

@format: format.

Return: Printed chars.
*/
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
{
print_buffer(buffer, &buff_ind);
}
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
{
va_end(list);
return (-1);
}
printed_chars += printed;
}
}

print_buffer(buffer, &buff_ind);

va_end(list);

return (printed_chars);
}

/**

print_buffer - Prints the contents of the buffer if it exists

@buffer: Array of chars

@buff_ind: Index at which to add next char, represents the length.
*/
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
{
write(1, &buffer[0], *buff_ind);
}

*buff_ind = 0;
=======
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
>>>>>>> origin/master
}
