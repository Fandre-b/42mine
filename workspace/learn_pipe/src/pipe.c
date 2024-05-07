//quero ler arg 
//./program input cmd output

#include "pipex.h"

int main(int argc, char **argv)
{
    pid_t id;
    int fd_pipe[2];
    int fd_file[2];
    char *cmd[3];
    char *line;

    cmd[0] = "/bin/which";
    cmd[1] = "cat";
    cmd[2] = NULL;

    if (argc < 3)
        return (1);
    fd_file[0] = open(argv[1], O_RDONLY, 0777);
    fd_file[1] = open(argv[argc - 1], O_WRONLY | O_CREAT, 0777);

    pipe(fd_pipe);
    id = fork();
    if (id == 0)
    {
        close(fd_pipe[0]);
        close(fd_file[1]);
        dup2(fd_file[0], 0);
        close(fd_file[0]);
        dup2(fd_pipe[1], 1);
        close(fd_pipe[1]);
        if(execve(cmd[0], cmd, NULL) == -1)
        {
            perror("Error: ");
            exit(1);
        }
    }
    else
    {
        line = NULL;
        wait(NULL);
        close(fd_file[0]);
        close(fd_file[1]);
        close(fd_pipe[1]);
        while (get_next_line(fd_pipe[0], &line) == 1)
        {
            write(1, line, ft_strlen( ));
            printf("parent read: %s\n", line);
        }
        close(fd_pipe[0]);
        //close(fd_pipe[0]);
        //close(fd_error[0]);
        //close(fd_error[1]);
    }
    return (0);
}
