#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



void Display(void);
void user_input(char *userInput, size_t size);
void execute_cmd(char *userInput);
