/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:56:22 by mpais-go          #+#    #+#             */
/*   Updated: 2024/03/28 15:21:20 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*create_singleline(int fd)
{
	char	*temp;
	char	*line;
	char	*singleline;

	singleline = ft_calloc(1, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strjoin(singleline, line);
		free(line);
		free(singleline);
		singleline = temp;
	}
	return (singleline);
}

void	get_map(char *path, t_map *map)
{
	int		fd;
	char	*singleline;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_error_msg(ERROR_OPEN);
		return ;
	}
	singleline = create_singleline(fd);
	map->nbr_c = check_nl_and_tokens(singleline);
	if (!map->nbr_c)
	{
		free_matrix(map->matrix);
		exit(2);
	}
	map->matrix = ft_split(singleline, '\n');
	if (!map->matrix)
	{
		free_matrix(map->matrix);
		exit(2);
	}
	map->flag_exit = 0;
	free(singleline);
	close(fd);
}

void	create_copymap(t_map map, char **copymap)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map.height)
	{
		copymap[i] = malloc(sizeof(char) * (map.width + 1));
		j = -1;
		while (++j < map.width)
			copymap[i][j] = map.matrix[i][j];
	}
	copymap[i] = NULL;
}

int	validate_map(t_map *map)
{
	char	**copy;
	int		i;
	int		j;

	if (!is_rect(map) || !is_closed(*map))
		return (0);
	init_player(map);
	copy = malloc(sizeof(char *) * (map->height + 1));
	create_copymap(*map, copy);
	flood_fill(map->player.pos_ply[1], map->player.pos_ply[0], copy);
	for(int y = 0; y < map->height; y++)
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (copy[i][j] != '0' && copy[i][j] != '1' && copy[i][j] != 'G')
			{
				ft_error_msg(ERROR_FF);
				return (0);
			}
		}
	}
	free_matrix(copy);
	return (1);
}
