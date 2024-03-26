#include "shell.h"


void Display(void)
{
    //display the prompt
    printf("$: ");
}

//to read user input 
void user_input(char *userInput, size_t size)
{
    //to read user input 
    getline(&userInput, &size, stdin);
}

//to execute a command 
void execute_cmd(char *userInput)
{
    //to execute a command 
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        char *args[] = {"/usr/bin/env", NULL};
        execve(args[0], args, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

int main(void)
{
    char userInput[256];

    while (1)
    {
        Display();
        user_input(userInput, sizeof(userInput));
        if (strcmp(userInput, "exit\n") == 0)
            break;
        else if (strcmp(userInput, "env\n") == 0)
            execute_cmd(userInput);
    }

    return 0;
}