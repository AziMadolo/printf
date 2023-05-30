#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: List of arguments
 * Return: Number of chars printed
 */
int print_char(va_list types)
{
	char c = (char)va_arg(types, int);
	char buffer[2] = {0};

	buffer[0] = c;
	write(1, buffer, 1);
	return (1);
}

/************************* PRINT A STRING *************************/

/**
 * print_string - Prints a string
 * @types: List of arguments
 * Return: Number of chars printed
 */
int print_string(va_list types)
{
	char *str = va_arg(types, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}

	return (count);
}

/************************* PRINT PERCENT SIGN *************************/

/**
 * print_percent - Prints a percent sign
 * @types: List of arguments
 * Return: Number of chars printed
 */
int print_percent(va_list types)
{
	(void)types;
	write(1, "%", 1);
	return (1);
}

/************************* PRINT INT *************************/

/**
 * print_int - Print int
 * @types: List of arguments
 * Return: Number of chars printed
 */
int print_int(va_list types)
{
	int n = va_arg(types, int);
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	if (num / 10)
		count += print_int_recursive(num / 10);

	char digit = '0' + (num % 10);
	write(1, &digit, 1);
	count++;

	return (count);
}

/**
 * print_int_recursive - Helper function for printing integers recursively
 * @num: The number to be printed
 * Return: Number of chars printed
 */
int print_int_recursive(unsigned int num)
{
	int count = 0;

	if (num / 10)
		count += print_int_recursive(num / 10);

	char digit = '0' + (num % 10);
	write(1, &digit, 1);
	count++;

	return (count);
}

/************************* PRINT BINARY *************************/

/**
 * print_binary - Prints an unsigned number in binary format
 * @types: List of arguments
 * Return: Number of chars printed
 */
int print_binary(va_list types)
{
	unsigned int n = va_arg(types, unsigned int);
	int count = 0;
	char buffer[32];
	int i;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	for (i = 0; i < 32; i++)
		buffer[i] = '0';

	i = 0;
	while (n > 0)
	{
		buffer[i++] = '0' + (n % 2);
		n /= 2;
	}

	for (i = 31; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
		count++;
	}

	return (count)
}
