#include "pipex.h"

int    execute_command(pid_t input_fd, pid_t output_fd, char **cmd)
{
	pid_t pid;
	int fd_error[2];
	char *line;

	pid = fork();
	if (pid == -1)
		return (perror("fork failed"), -1);
	if (pipe(fd_error) == -1)
		return (perror("pipe failed"), -1);
	if (0 == pid)
	{
        pritnf("inside child process\n")
		close(fd_error[0]);
		dup2(fd_error[1], STDERR_FILENO);
		close(fd_error[1]);
		if (input_fd != STDIN_FILENO)
		{
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}
		if (output_fd != STDOUT_FILENO)
		{
			dup2(output_fd, STDOUT_FILENO);
			close(output_fd);
		}
        if (execve(cmd[0], cmd, NULL) == -1) 
        {
            perror("execve");
            exit(EXIT_FAILURE);  // Terminate the child process if execve fails
        }
	}
	else
	{
        pritnf("inside parent process\n")
		line = NULL;
		wait(NULL);
		close(fd_error[1]);
		while (get_next_line(fd_error[0], &line) > 0)
			write(STDOUT_FILENO, line, ft_strlen(line));
		close(fd_error[0]);
	}
	return (0);
}

char	*ft_witch(char *first_cmd)
{
	char *cmd[3];
	int fd_which[2];
	char *line;
	char *path;

	path = NULL;
	cmd[0] = "/bin/witch";
	cmd[1] = first_cmd;
	cmd[2] = NULL;
	if (pipe(fd_which) == -1)
		return (perror("pipe failed"), NULL);
	execute_command(STDIN_FILENO, fd_which[1], cmd);
	close(fd_which[1]);
	while (get_next_line(fd_which[0], &line) > 0)
	{
		printf("from witch: %s \n", line);
		path = ft_strnjoin(path, line, ft_strlen(line));
	}
	close(fd_which[0]);
	if (!path)
		return (perror("cmd path not found"), path);
	return (path);
}