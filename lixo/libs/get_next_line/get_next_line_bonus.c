/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:38:22 by mpais-go          #+#    #+#             */
/*   Updated: 2023/11/23 20:15:31 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			flag;
	int			flag2;

	flag = 0;
	flag2 = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		if (fd >= 0 && fd < FOPEN_MAX)
			ft_clean_buff(buffer[fd], &flag, &flag2);
		return (NULL);
	}
	line = NULL;
	flag2 = 1;
	while (!flag && (*buffer[fd] != 0 || read(fd, buffer[fd], BUFFER_SIZE) > 0))
	{
		line = ft_strjoin_gnl(line, buffer[fd]);
		ft_clean_buff(buffer[fd], &flag, &flag2);
	}
	return (line);
}
