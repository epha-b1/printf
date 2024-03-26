#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * handle_flags - Handle flag characters for non-custom conversion specifiers
 * @flag: Flag character to handle ('+', ' ', '#')
 * @num: The numeric value associated with the conversion specifier
 * @count: Pointer to the count variable to update
 *
 * Return: None
 */
void handle_flags(char flag, int num, int *count)
{
    char buffer[20];

    switch (flag)
    {
        case '+':
            if (num >= 0)
                *count += write(1, "+", 1);
            break;
        case ' ':
            if (num >= 0)
                *count += write(1, " ", 1);
            break;
        case '#':
            sprintf(buffer, "#%d", num);
            *count += write(1, buffer, strlen(buffer));
            break;
        default:
            fprintf(stderr, "Error: Unknown flag character '%c'\n", flag);
            break;
    }
}
