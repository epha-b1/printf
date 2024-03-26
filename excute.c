#include "shell.h"


void execute_cmd(char *userInput)
{
    pid_t pid;
    int i = 0;
     int status;
    char *args[256];

    userInput[strlen(userInput) - 1] = '\0'; 

    char *token = strtok(userInput, " ");
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; 

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // check the command in the PATH
        char *path = getenv("PATH");
        char *dir;
        char cmd[256];
        int found = 0;

        //search command in the PATH
        dir = strtok(path, ":");
        while (dir != NULL)
        {
            snprintf(cmd, sizeof(cmd), "%s/%s", dir, args[0]);
            if (access(cmd, X_OK) == 0)
            {
                //excute if the cmd is found
                found = 1;
                execve(cmd, args, NULL);
                perror(cmd);
                exit(EXIT_FAILURE);
            }
            dir = strtok(NULL, ":");
        }

        //handle if the cmd is not found
        if (!found)
        {
            fprintf(stderr, "%s: command not found\n", args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }
}