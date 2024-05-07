#include <unistd.h>
#include <sys/wait.h>

void execute_command(int input_fd, int output_fd, char *command[]) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        //fd = open(filename, O_RDONLY, 0666)
        if (input_fd != STDIN_FILENO) {
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }
        if (output_fd != STDOUT_FILENO) {
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
        }
        execve(command[0], command, NULL);
        perror("execve");
        exit(1);
    }
}

int main() {
    char **commands[] = {
        (char *[]) { "/bin/ls", "-l", "/", NULL },
        (char *[]) { "/bin/grep", "etc", NULL },
        (char *[]) { "/bin/wc", "-l", NULL },
        NULL
    };
    int input_fd = STDIN_FILENO;
    int fd[2];

    for (int i = 0; commands[i] != NULL; i++) {
        if (commands[i + 1] != NULL) {
            // Not the last command, so create a pipe for output
            if (pipe(fd) == -1) {
                perror("pipe");
                return 1;
            }
            execute_command(input_fd, fd[1], commands[i]);
            close(fd[1]);
            input_fd = fd[0];  // Output of this command is input of next command
        } else {
            // Last command, so output to STDOUT
            execute_command(input_fd, STDOUT_FILENO, commands[i]);
        }
    }

    // Wait for all child processes to finish
    while (wait(NULL) > 0);

    return 0;
}