/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:40:53 by fandre-b          #+#    #+#             */
/*   Updated: 2024/04/26 18:40:53 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	input_gnl(t_info *info) //[] have to pipegetnextline for cmd processes.
{
	char	*line;
	int		n_error;

	n_error = 1;
	line = NULL;
	while (n_error)
	{
		n_error = get_next_line(STDIN_FILENO, &line);
		if (n_error <= 0)
			break;
		if (ft_strstr(line, info->limiter) != NULL)
		{
			write(info->fd[1], line, ft_strstr(line, info->limiter) - line);
			free(line);
			break;
		}
		write(info->fd[1], line, ft_strlen(line));
		free(line);
	}
	close(info->fd[1]); //will be reopen with open outfile
	return (n_error);
}

int	parcel_open_fd(int argc, char **argv, t_info *info)
{
	if (info->here_doc)
	{
		info->limiter = argv[2];
		if (-1 == pipe(info->fd))
			return (perror("pipe failed"), -1);
		if (-1 == input_gnl(info))
			return (perror("GNL failed"), -1);
		info->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (info->fd[1] == -1)
			return (perror("open output failed"), -1);
	}
	else //since standart open for in/out dont need pipe
	{
		info->limiter = NULL;
		info->fd[0] = open(argv[1], O_RDONLY, 0666);
		if (info->fd[0] == -1)
			return (perror("open input failed"), -1);
		info->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (info->fd[1] == -1)
			return (perror("open output failed"), -1);
	}
	return (0);
}

char *get_path(char *cmd, char **envp)
{
	char *temp;
	char *paths;
	int perm;
	int i;

	perm = -1;
	paths = NULL;
	temp = NULL;
	while(*envp != NULL && paths == NULL)
		paths = ft_strstr(*envp++, "PATH=");
	if (paths != NULL)
		paths = paths + 5;
	while (paths && *paths != '\0' && perm != 0)
	{
		i = 0;
		free(temp);
		while (paths[i] && paths[i] != ':' && paths[i] != '\0')
			i++;
		temp = ft_strnjoin(ft_strnjoin(NULL, paths, i++), "/", 1);
		temp = ft_strnjoin(temp , cmd, ft_strlen(cmd));
		perm = access(temp, F_OK | X_OK);
		paths += i;
	}
	if (perm == 0)
		return (free(cmd), temp);
	return (free(temp), cmd);
}

int	parcel_argv(int argc, char **argv, t_info *info)
{
	int i;

	if ( argc > 4 && ft_strstr(argv[1], "here_doc"))
		info->here_doc = 1;
	else if (argc > 3)
		info->here_doc = 0;
	else
		return (perror("Short on arguments"), -1);
	i = (argc - (2 + info->here_doc));
	info->arg_cmd = (char ***) malloc( i * sizeof(char **));
	if (!info->arg_cmd)
		return (perror("Malloc cmd failed"), -1);
	i = 0;
	while (++i + info->here_doc + 2 < argc)
	{
		info->arg_cmd[i - 1] = ft_split(argv[i + info->here_doc + 1], ' ');
		print_cmds("cmd", info->arg_cmd[i - 1]);
		if (access(info->arg_cmd[i - 1][0], F_OK | X_OK) != 0)
			info->arg_cmd[i - 1][0] = get_path(info->arg_cmd[i - 1][0], info->envp);
		rejoin_quoted_args(info->arg_cmd[i - 1]);
	}
	info->arg_cmd[i - 1] = NULL;
	return (0);
}
