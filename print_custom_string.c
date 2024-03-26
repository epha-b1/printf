#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_custom_string - Print a string with special handling for non-printable characters
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int print_custom_string(char *str)
{
    int count = 0;

    for (; *str != '\0'; ++str)
    {
        if (*str < 32 || *str >= 127)
        {
            char hex[5];
            sprintf(hex, "\\x%02X", (unsigned char)(*str));
            count += write(1, hex, 4);
        }
        else
        {
            count += write(1, str, 1);
        }
    }

    fflush(stdout);

    return count;
}
