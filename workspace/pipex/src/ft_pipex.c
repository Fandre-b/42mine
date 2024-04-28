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
	free((info->arg_cmd[i]));
	free(info);
	return ;
}

void	pipe_arg_cmd(t_info *info)
{
	int     fd[2];
	int     input_fd;
	int		n;

	n = -1;
	input_fd = info->fd[0];
	while (info->arg_cmd[++n] != NULL)
	{
		if (info->arg_cmd[n + 1] != NULL)
		{
			pipe(fd);
			execute_command(input_fd, fd[1], info->arg_cmd[n]);
			//close(fd[1]); exe will close
			input_fd = fd[0];
		}
		if (info->arg_cmd[n + 1] == NULL)
			execute_command(input_fd, info->fd[1], info->arg_cmd[n]);
	}
	return ;
}

int main(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *) malloc(sizeof(t_info));
	if (!info)
		return (perror("malloc struct failed"), -1);
	//extract_info(argc, argv, info);
	parcel_argv(argc, argv, info);
	parcel_open_fd(argc, argv, info);
	pipe_arg_cmd(info);
	free_info(info);
	return (0);
}
