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

void	exe_cmd_child(int input_fd, int output_fd, int *fd_error, char **cmd, char **envp)
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
	if (cmd[0] && access(cmd[0], F_OK | X_OK) != 0)
	{
		write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
		write(STDERR_FILENO, ": Command not found\n", 21);
	}
	if (!cmd[0])
		write(2, "Empty Command pipes nothing\n", 28);
	if (execve(cmd[0], cmd, envp) == -1)
		exit(ENOENT);
	exit(0);
}

void	exe_cmd_parent(int input_fd, int output_fd, int *fd_error)
{
	int		status;
	char	*error;

	close(fd_error[1]);
	wait(&status);
	if (WIFEXITED(status) && WEXITSTATUS(status) == ENOENT)
	{
		error = NULL;
		while (get_next_line(fd_error[0], &error) > 0)
		{
			write(STDERR_FILENO, error, ft_strlen(error));
			free (error);
		}
	}
	close(fd_error[0]);
	if (input_fd != STDIN_FILENO)
		close(input_fd);
	if (output_fd != STDOUT_FILENO)
		close(output_fd);
}

// 	int		status;
// 	char	*error;

// 	close(fd_error[1]);
// 	wait(&status);
// 	if (WIFEXITED(status) && WEXITSTATUS(status) == ENOENT)
// 	{
	
int	execute_command(int input_fd, int output_fd, char **cmd, char **envp)
{
	pid_t	pid;
	int		fd_error[2];

	if (pipe(fd_error) == -1)
		return (perror("pipe failed"), -1);
	pid = fork();
	if (pid == -1)
		return (perror("fork failed"), -1);
	if (0 == pid)
		exe_cmd_child(input_fd, output_fd, fd_error, cmd, envp);
	else
		exe_cmd_parent(input_fd, output_fd, fd_error);
	return (ENOENT);
}
