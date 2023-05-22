# Simple Shell
## Description
This Shell program is a simple implementation of a command-line shell written in C.
It provides a basic shell environment where users can enter commands and execute them.
The program supports executing both built-in shell commands and external commands available in the system.
## Features
+ Interactive shell prompt: Users can enter commands at the shell prompt and execute them.
+ Support for built-in commands: The shell supports a few built-in commands, such as "exit", which allows users to exit the shell program.
+ Execution of external commands: The shell can execute external commands available in the system by forking a child process and invoking the execvp function.
+ Command-line arguments: Users can provide command-line arguments along with the command to be executed.
+ Basic error handling: The shell provides basic error handling for input reading, command execution, and forking processes.
## Usage
+ This `Simple Shell` was coded on an Ubuntu 20.04.01 LTS machine with `gcc` version 9.4.0.
+ Compile your code with gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
Compilation:
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
```
