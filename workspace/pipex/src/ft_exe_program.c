/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:43:01 by fandre-b          #+#    #+#             */
/*   Updated: 2024/04/26 18:43:01 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe_cmd_child(int input_fd, int output_fd, int *fd_error,  char **cmd)
{
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
	execve(cmd[0], cmd, NULL);
	perror("execve");
    return ;
}

void	exe_cmd_parent(int *fd_error)
{
	char *line;

	wait(NULL);
	close(fd_error[1]);
	while (get_next_line(fd_error[0], &line) > 0)
		write(STDOUT_FILENO, line, ft_strlen(line));
	close(fd_error[0]);
    return ;
}

int    execute_command(pid_t input_fd, pid_t output_fd, char *cmd[])
{
	pid_t pid;
	int fd_error[2];

	pid = fork();
	if (pid == -1)
		return (perror("fork failed"), -1);
	if (pipe(fd_error) == -1)
		return (perror("pipe failed"), -1);
	if (0 == pid)
		exe_cmd_child(input_fd, output_fd, fd_error, cmd);
	else
		exe_cmd_parent(fd_error);
	return (0);
}
