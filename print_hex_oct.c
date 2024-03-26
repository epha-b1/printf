#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int print_unsigned(unsigned int num);
int print_octal(unsigned int num);
int print_hex(unsigned int num, int uppercase);

/**
 * print_hex_oct - Handles %u, %o, %x, %X conversion specifiers
 * @format: Format string
 * @args: Variable argument list
 *
 * Return: Number of characters printed
 */
int print_hex_oct(const char *format, va_list args)
{
    int count = 0;
    const char *format_ptr;
    unsigned int num;

    for (format_ptr = format; *format_ptr != '\0'; ++format_ptr)
    {
        if (*format_ptr == '%' && (*(format_ptr + 1) == 'u' || *(format_ptr + 1) == 'o' || *(format_ptr + 1) == 'x' || *(format_ptr + 1) == 'X'))
        {
            switch (*(format_ptr + 1))
            {
                case 'u':
                    num = va_arg(args, unsigned int);
                    count += print_unsigned(num);
                    break;
                case 'o':
                    num = va_arg(args, unsigned int);
                    count += print_octal(num);
                    break;
                case 'x':
                case 'X':
                    num = va_arg(args, unsigned int);
                    count += print_hex(num, (*(format_ptr + 1) == 'X') ? 1 : 0);
                    break;
                default:
                    fprintf(stderr, "Error: Unknown conversion specifier '%c'\n", *(format_ptr + 1));
                    return (-1);
            }
            ++format_ptr;
        }
        else
        {
            count += write(1, format_ptr, 1);
        }
    }

    return (count);
}

/**
 * print_unsigned - Print an unsigned integer
 * @num: Unsigned int to print
 *
 * Return: Number of characters printed
 */
int print_unsigned(unsigned int num)
{
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "%u", num);
    return write(1, buffer, strlen(buffer));
}

/**
 * print_octal - Print an octal number
 * @num: Unsigned int to print in octal
 *
 * Return: Number of characters printed
 */
int print_octal(unsigned int num)
{
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "%o", num);
    return write(1, buffer, strlen(buffer));
}

/**
 * print_hex - Print a hexadecimal number
 * @num: Unsigned int to print in hexadecimal
 * @uppercase: Use uppercase letters (1) or not (0)
 *
 * Return: Number of characters printed
 */
int print_hex(unsigned int num, int uppercase)
{
    char buffer[20];
    snprintf(buffer, sizeof(buffer), (uppercase ? "%X" : "%x"), num);
    return write(1, buffer, strlen(buffer));
}
