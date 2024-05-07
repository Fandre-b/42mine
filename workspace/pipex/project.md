//TODO

//add ability to use ' and " and $ in the commands
//check strnjoin and sttindex char unify
//GNL that passes all stricts in francinette
//manage better closing files inside the fork
//manage better the error handling

__________________________________
 
 open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid


-perror and strerror
deal with errors, still confused
perror: prints a descriptive error message to stderr
strerror: returns a pointer to the textual representation of the current errno value
________________________________

access: checks if an file is accessible
Uses #include <unistd.h>
if (access("/path/to/file", F_OK) != -1)
    // file exists
what other flags i can use instead of F_OK
________________________________

execve: executes a program with arguments


uses #include <unistd.h>

#include <unistd.h>

char *argv[] = {"/bin/ls", "-l", NULL};
char *envp[] = {NULL};

if (execve(argv[0], argv, envp) == -1) {
    perror("execve");
}

first argument is the path and the rest are different commands to be ran.
envp is the environment variables

________________________________

wait: waits for a child process to finish - <sys/wait.h>
waitpid: waits for a specific child process to finish - <sys/wait.h>
fork: creates a child process - <unistd.h>
dup: duplicates a file descriptor - <unistd.h> 
dup2: duplicates a file descriptor to a specific number - <unistd.h>
pipe: creates a pipe for inter-process communication - <unistd.h>
________________________________  
perror: prints a descriptive error message to stderr with an string as prefix - <stdio.h>
strerror: returns a pointer to the textual representation of the current errno value - <string.h>
________________________________
open: opens a file - <fcntl.h>
access: checks if an file is accessible - <unistd.h>
close: closes a file - <unistd.h>
write: writes to a file - <unistd.h>
read: reads from a file - <unistd.h>
unlink: deletes a file - <unistd.h>

file descriptor: a number that represents an open file
file descriptors 0, 1, and 2 are reserved for standard input, standard output, and standard error
________________________________
execve: executes a program with arguments
________________________________
status = unlink("file.txt");
status = 0 se der delete ao ficheiro, outro val se der error


Parsing shell commands with quotes can be tricky because the behavior of the shell is different inside single quotes ('), double quotes ("), and outside of quotes. Here's a simplified plan for how you might do it:

Initialize an empty string to hold the current argument.
Initialize a variable to keep track of whether you're currently inside single quotes, double quotes, or outside of quotes.
Iterate over the characters in the command.
___________
If you encounter a single quote:
If you're currently inside single quotes, end the quoted section.
If you're currently outside of quotes, start a new quoted section.
If you're currently inside double quotes, add the single quote to the current argument.
___________
If you encounter a double quote:
If you're currently inside double quotes, end the quoted section.
If you're currently outside of quotes, start a new quoted section.
If you're currently inside single quotes, add the double quote to the current argument.
___________
If you encounter a space:
If you're currently inside quotes, add the space to the current argument.
If you're currently outside of quotes, end the current argument and start a new one.
If you encounter any other character, add it to the current argument.
Continue until you've processed all the characters in the command.

spaces do the argument seperation.
" and ' are used to set what are strings
if " add do nothing just delete " (shell was suposed to do the subs)