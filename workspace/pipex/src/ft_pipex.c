/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:49:51 by fandre-b          #+#    #+#             */
/*   Updated: 2024/04/26 18:49:51 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_info(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	close_all();
	while (info->cmd[i])
	{
		j = 0;
		while (info->cmd[i][j] != NULL)
			free (info->cmd[i][j++]);
		free (info->cmd[i][j]);
		free (info->cmd[i++]);
	}
	free ((info->cmd[i++]));
	free ((info->cmd));
	free (info);
	return ;
}

int	pipe_arg_cmd(t_info *info)
{
	int		fd[2];
	int		n;
	int		status;

	n = -1;
	info->exe_fd[0] = info->fd[0];
	while (info->cmd[++n] != NULL)
	{
		if (info->cmd[n + 1] != NULL)
		{
			pipe(fd);
			info->exe_fd[1] = fd[1];
			status = execute_command(info, info->cmd[n]);
			info->exe_fd[0] = fd[0];
		}
		if (info->cmd[n + 1] == NULL)
		{
			info->exe_fd[1] = info->fd[1];
			status = execute_command(info, info->cmd[n]);
			close(info->fd[0]);
		}
	}
	return (status);
}

void	print_struct(char *str, t_info *info)
{
	int	i;

	printf("\n  ---%s---\n", str);
	printf("fd: %d, %d\n", info->fd[0], info->fd[1]);
	printf("here_doc: %d\n", info->here_doc);
	printf("\n    //COMANDS//\n");
	i = 0;
	while (info->cmd && info->cmd[i] != NULL)
	{
		printf(" ->cmd%d: ", i);
		print_cmds("", info->cmd[i++]);
	}
	if (info->cmd[i] == NULL)
		printf("cmd%d: ->NULL<-\n", i);
	printf("-------------\n\n");
	return ;
}

void	print_cmds(char *str, char **matrix)
{
	int	j;

	printf("%s\n", str);
	j = 0;
	while (matrix[j] != NULL)
	{
		printf("arg%d: | %s |\n", j, matrix[j]);
		j++;
	}
	if (matrix[j] == NULL)
		printf("arg%d: | NULL | \n\n", j);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;
	int		status;

	if (argc < 4)
		return (-1);
	info = (t_info *) malloc(sizeof(t_info));
	if (!info)
		return (perror("malloc struct failed"), -1);
	info->envp = envp;
	if (parcel_argv(argc, argv, info) == -1)
		return (1);
	if (parcel_open_fd(argc, argv, info) == -1)
		return (1);
	//print_struct("before", info);
	status = pipe_arg_cmd(info);
	free_info(info);
	return (status);
}
