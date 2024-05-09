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
	int i;
	int	j;

	i = 0;
	while (info->arg_cmd[i])
	{
		j = 0;
		while (info->arg_cmd[i][j] != NULL)
			free(info->arg_cmd[i][j++]);
		free(info->arg_cmd[i][j]);
		free(info->arg_cmd[i++]);
	}
	free((info->arg_cmd[i++]));
	free((info->arg_cmd));
	free(info);
	return ;
}

int	pipe_arg_cmd(t_info *info)//TOdo: fix
{
	int     fd[2];
	int     input_fd;
	int		n;

	n = -1;
	input_fd = info->fd[0];
	while (info->arg_cmd[++n] != NULL)
	{
		if ((info->arg_cmd[n + 1] != NULL && info->arg_cmd[n + 1][0] == NULL))
			n++;
		if (info->arg_cmd[n + 1] != NULL)
		{
			pipe(fd);
			if (execute_command(input_fd, fd[1], info->arg_cmd[n], info->envp) == -1)
				return (-1);
			//close(fd[1]); exe will close
			input_fd = fd[0];
		}
		if (info->arg_cmd[n + 1] == NULL)
		{
			if (execute_command(input_fd, info->fd[1], info->arg_cmd[n], info->envp) == -1)
				return (-1);
			close(info->fd[0]);
		}
	}
	return (0);
}

void	print_struct(char *str, t_info *info)
{
	int i;

	printf("\n  ---%s---\n", str);
	printf("fd: %d, %d\n", info->fd[0], info->fd[1]);
	printf("here_doc: %d\n", info->here_doc);
	printf("\n    //COMANDS//\n");
	while (info->arg_cmd && info->arg_cmd[i] != NULL)
	{
		printf(" ->cmd%d: ", i);
		print_cmds("", info->arg_cmd[i++]);
	}
	if (info->arg_cmd[i] == NULL)
		printf("cmd%d: ->NULL<-\n", i);
	printf("-------------\n\n");
	return ;
}

void	print_cmds(char *str, char **matrix)
{
	int j;

	printf("%s\n", str);
	j = 0;
	while (matrix[j] != NULL)
	{
		printf("arg%d: | %s |\n", j,  matrix[j]);
		j++;
	}
	if (matrix[j] == NULL)
		printf("arg%d:|NULL|\n\n", j);
	return ;
}

int main(int argc, char **argv, char **envp)
{
	t_info	*info;

	if (argc < 4)
		return (-1);
	info = (t_info *) malloc(sizeof(t_info));
	if (!info)
		return (perror("malloc struct failed"), -1);
	info->envp = envp;
	if (parcel_argv(argc, argv, info) == -1)
		return (1);
	//print_struct("struct info", info);
	if (parcel_open_fd(argc, argv, info) == -1)
		return (1);
	pipe_arg_cmd(info);
	free_info(info);
	return (0);
}
