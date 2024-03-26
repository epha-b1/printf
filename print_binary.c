#include "main.h"
#include <stdio.h>

/**
 * itoa_binary - Convert an unsigned int to binary string
 * @num: Unsigned int to convert
 * @buffer: Buffer to store the binary string
 */
void itoa_binary(unsigned int num, char *buffer)
{
    int i = 0;
    int j;

    if (num == 0)
    {
        buffer[i++] = '0';
        buffer[i] = '\0';
    }
    else
    {
        while (num != 0)
        {
            buffer[i++] = (num & 1) + '0';
            num >>= 1;
        }

        buffer[i] = '\0';


        for (j = 0; j < i / 2; ++j)
        {
            char temp = buffer[j];
            buffer[j] = buffer[i - j - 1];
            buffer[i - j - 1] = temp;
        }
    }
}
