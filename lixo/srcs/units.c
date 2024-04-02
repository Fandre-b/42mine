/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   units.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:00:32 by mpais-go          #+#    #+#             */
/*   Updated: 2024/03/28 15:21:12 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	*ft_error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (NULL);
}

void	init_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->matrix[i][j] == 'P')
			{
				map->player.pos_ply[1] = j;
				map->player.pos_ply[0] = i;
				map->player.colected = 0;
				map->player.moves = 0;
				map->player.last_img = map->images.rpac[0];
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	flood_fill(int x, int y, char **mapa)
{
	if (mapa[y][x] == '1' || mapa[y][x] == 'G')
		return ;
	else 
		mapa[y][x] = '1';
	flood_fill(x + 1, y, mapa);
	flood_fill(x, y + 1, mapa);
	flood_fill(x - 1, y, mapa);
	flood_fill(x, y - 1, mapa);
}

void	free_matrix(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map && map[i])
		free(map[i++]);
	free(map);
}

void	print_n_moves(t_map *map)
{
	char	*number;
	char	*previous;
	char	*p_steps;
	char	*steps;

	number = ft_itoa(map->player.moves);
	steps = ft_strjoin("Number of moves: ", number);
	previous = NULL;
	p_steps = NULL;
	if (map->player.moves != 0)
	{
		previous = ft_itoa(map->player.moves - 1);
		p_steps = ft_strjoin("Number of moves: ", previous);
		mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 30, 0x2121DE, p_steps);
	}
	mlx_string_put(map->mlx_ptr, map->win_ptr, 30, 30, 0xFFFFFF, steps);
	free(number);
	free(steps);
	free(previous);
	free(p_steps);
}
