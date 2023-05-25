#include "shell.h"
#include <stdbool.h>
/**
 * executeCommand- Execute the command using execve
 * @command: The command to execute
 * Return: Return 1 in case of any error
 */


int executeCommand(char *command) {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
       char** args = malloc(sizeof(char*) * 4);
        args[0] = "/bin/sh";
        args[1] = "-c";
        args[2] = command;
        args[3] = NULL;

        execve(args[0], args, environ);
        
        perror("execve");
        _exit(EXIT_FAILURE);
    } else {
        
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            return -1;
        }
        if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS) {
            return 0;
        } else {
            return -1;
        }
    }
}