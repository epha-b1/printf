#include "shell.h"


char *read_userInput(void)
{
    char *userInput = NULL;
    size_t bufsize = 0;

    if (getline(&userInput, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        perror("read_userInput");
        exit(EXIT_FAILURE);
    }

    return userInput;
}