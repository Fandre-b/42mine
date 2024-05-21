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

int	input_gnl(t_info *info)
{
	char	*line;
	int		n_error;

	n_error = 1;
	line = NULL;
	while (n_error)
	{
		n_error = get_next_line(STDIN_FILENO, &line);
		if (n_error <= 0)
		{
			errno = n_error;
			break ;
		}
		if (ft_strstr(line, info->limiter) != NULL)
		{
			write(info->fd[1], line, ft_strstr(line, info->limiter) - line);
			free (line);
			break ;
		}
		write(info->fd[1], line, ft_strlen(line));
		free (line);
	}
	if (close(info->fd[1] == -1))
		return (perror("close failed"), errno);
	return (errno);
}

char	*get_path(char *cmd, char **envp)
{
	char	*temp;
	char	*paths;
	int		i_perm[2];

	i_perm[1] = -1;
	paths = NULL;
	temp = NULL;
	while (*envp != NULL && paths == NULL)
		paths = ft_strstr(*envp++, "PATH=");
	if (paths != NULL)
		paths = paths + 5;
	while (paths && *paths != '\0' && i_perm[1] != 0)
	{
		i_perm[0] = 0;
		free (temp);
		while (paths[i_perm[0]] && paths[i_perm[0]] != ':')
			i_perm[0]++;
		temp = ft_strnjoin(ft_strnjoin(NULL, paths, i_perm[0]++), "/", 1);
		temp = ft_strnjoin(temp, cmd, ft_strlen(cmd));
		i_perm[1] = access(temp, F_OK | X_OK);
		paths += i_perm[0];
	}
	if (i_perm[1] == 0)
		return (free (cmd), temp);
	return (free (temp), cmd);
}

int	parcel_argv(int argc, char **argv, t_info *info)
{
	int	i;

	if (argc > 4 && (ft_strstr(argv[1], "here_doc") - argv[1]) == 0)
		info->here_doc = 1;
	else if (argc > 3)
		info->here_doc = 0;
	else
		return (perror("Short on arguments"), -1);
	i = (argc - (2 + info->here_doc));
	info->cmd = (char ***) malloc(i * sizeof(char **));
	if (!info->cmd)
		return (perror("Malloc cmd failed"), errno);
	i = -1;
	while (++i + 3 + info->here_doc < argc)
	{
		info->cmd[i] = ft_split(argv[i + 2 + info->here_doc], ' ');
		if (info->cmd[i][0] && access(info->cmd[i][0], F_OK | X_OK) != 0)
			info->cmd[i][0] = get_path(info->cmd[i][0], info->envp);
		rejoin_quoted_args(info->cmd[i]);
	}
	info->cmd[i] = NULL;
	return (0);
}

int	parcel_open_fd(int argc, char **argv, t_info *info)
{
	if (info->here_doc)
	{
		info->limiter = argv[2];
		if (-1 == pipe(info->fd))
			return (perror("pipe failed"), errno);
		if (0 != input_gnl(info))
			return (perror("GNL failed"), errno);
		info->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (-1 == info->fd[1])
			return (perror("open output failed"), errno);
	}
	else
	{
		info->limiter = NULL;
		info->fd[0] = open(argv[1], O_RDONLY, 0666);
		if (-1 == info->fd[0])
			return (perror("open input failed"), errno);
		info->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (-1 == info->fd[1])
			return (perror("open output failed"), errno);
	}
	return (0);
}
