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

int	close_all(void)
{
	int	i;

	i = 2;
	while (++i < 250)
	{
		while (close(i) == -1)
		{
			if (errno == EBADF)
				break ;
			else if (errno != EINTR)
				return (errno);
		}
	}
	return (0);
}

void	exe_cmd_child(t_info *info, int *fd_error, char **cmd)
{
	dup2(fd_error[1], STDERR_FILENO);
	if (info->exe_fd[0] != STDIN_FILENO)
		dup2(info->exe_fd[0], STDIN_FILENO);
	if (info->exe_fd[1] != STDOUT_FILENO)
		dup2(info->exe_fd[1], STDOUT_FILENO);
	if (close_all() != 0)
		exit (errno);
	if (!cmd[0] || (cmd[0] && access(cmd[0], F_OK | X_OK) != 0))
	{
		write(STDERR_FILENO, "Command not found: ", 19);
		if (cmd[0])
			write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
		write(STDERR_FILENO, "\n", 1);
		exit(127);
	}
	if (execve(cmd[0], cmd, info->envp) == -1)
		exit(errno);
	exit(0);
}

int	exe_cmd_parent(t_info *info, int *fd_error)
{
	int		status;
	char	*error;

	wait(&status);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	error = NULL;
	if (close(fd_error[1]) == -1)
		return (perror("close failed"), errno);
	while (get_next_line(fd_error[0], &error) > 0)
	{
		//printf("expec: %s\n", error);
		write(STDERR_FILENO, error, ft_strlen(error));
		free (error);
	}
	if (close(fd_error[0]) == -1)
		return (perror("close failed"), errno);
	if (info->exe_fd[0] != STDIN_FILENO && close(info->exe_fd[0]) == -1)
		return (perror("close failed"), errno);
	if (info->exe_fd[1] != STDOUT_FILENO && close(info->exe_fd[1]) == -1)
		return (perror("close failed"), errno);
	return (status);
}

int	execute_command(t_info *info, char **cmd)
{
	pid_t	pid;
	int		fd_error[2];
	int		status;

	status = 0;
	if (pipe(fd_error) == -1)
		return (perror("pipe failed"), errno);
	pid = fork();
	if (pid == -1)
		return (perror("fork failed"), errno);
	if (0 == pid)
		exe_cmd_child(info, fd_error, cmd);
	else
		status = exe_cmd_parent(info, fd_error);
	return (status);
}
