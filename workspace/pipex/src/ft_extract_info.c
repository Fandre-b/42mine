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
	execute_command(fd_which[0], fd_which[1], cmd);
	close(fd_which[1]);
	while (get_next_line(fd_which[0], &line) > 0)
		path = ft_strnjoin(path, line, ft_strlen(line));
	close(fd_which[0]);
	return (path);
}

int	input_gnl(t_info *info)
{
	char	*line;
	int		n_error;

	n_error = 1;
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

int	parcel_argv(int argc, char **argv, t_info *info)
{
	int i;

	if (ft_strstr(argv[1], "here_doc") && argc > 4)
	{
		info->here_doc = 1;
		info->arg_cmd = (char ***) malloc((argc - 3) * sizeof(char **));
	}
	else if (argc > 3)
	{
		info->here_doc = 0;
		info->arg_cmd = (char ***) malloc((argc - 2) * sizeof(char **));
	}
	else
		return (perror("Short on arguments"), -1);
	if (!info->arg_cmd)
		return (perror("Malloc cmd failed"), -1);
	i = 0;
	while (++i + info->here_doc + 2 < argc)
	{
		info->arg_cmd[i - 1] = ft_split(argv[i + info->here_doc + 1], ' ');
		info->arg_cmd[i - 1][0] = ft_witch(info->arg_cmd[i - 1][0]);
	}
	info->arg_cmd[i - 1] = NULL;
	return (0);
}
