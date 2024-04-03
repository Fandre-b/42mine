/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:53:59 by mpais-go          #+#    #+#             */
/*   Updated: 2024/03/28 14:20:26 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	move_up(t_map *map, int *i)
{
	(*i)++;
	if (*i > 1)
		*i = 0;
	if (map->matrix[map->player.pos_ply[0] - 1][map->player.pos_ply[1]] != '1')
	{
		put_image_to_window(*map, map->images.floor,
			map->player.pos_ply[1], map->player.pos_ply[0]);
		map->player.pos_ply[0]--;
		map->player.moves++;
	}
	put_image_to_window(*map, map->images.upac[*i],
		map->player.pos_ply[1], map->player.pos_ply[0]);
	if (map->matrix[map->player.pos_ply[0]][map->player.pos_ply[1]] == 'C')
	{
		map->matrix[map->player.pos_ply[0]][map->player.pos_ply[1]] = 'J';
		map->player.colected++;
	}
}

void	move_left(t_map *map, int *i)
{
	(*i)++;
	if (*i > 1)
		*i = 0;
	if (map->matrix[map->player.pos_ply[0]][map->player.pos_ply[1] - 1] != '1')
	{
		put_image_to_window(*map, map->images.floor,
			map->player.pos_ply[1], map->player.pos_ply[0]);
		map->player.pos_ply[1]--;
		map->player.moves++;
	}
	put_image_to_window(*map, map->images.lpac[*i],
		map->player.pos_ply[1], map->player.pos_ply[0]);
	if (map->matrix[map->player.pos_ply[0]][map->player.pos_ply[1]] == 'C')
	{
		map->matrix[map->player.pos_ply[0]][map->player.pos_ply[1]] = 'J';
		map->player.colected++;
	}
}

void	move_down(t_map *map, int *i)
{
	(*i)++;
	if (*i > 1)
		*i = 0;
	if (map->matrix[map->player.pos_ply[0] + 1][map->player.pos_ply[1]] != '1')
	{
		put_image_to_window(*map, map->images.floor,
			map->player.pos_ply[1], map->player.pos_ply[0]);
		map->player.pos_ply[0]++;
		map->player.moves++;
	}
	put_image_to_window(*map, map->images.dpac[*i],
		map->player.pos_ply[1], map->player.pos_ply[0]);
	if (map->matrix[map->player.pos_ply[0]][map->player.pos_ply[1]] == 'C')
	{
		map->matrix[map->player.pos_ply[0]][map->player.pos_ply[1]] = 'J';
		map->player.colected++;
	}
}

void	move_right(t_map *map, int *i)
{
	(*i)++;
	if (*i > 1)
		*i = 0;
	if (map->matrix[map->player.pos_ply[0]][map->player.pos_ply[1] + 1] != '1')
	{
		put_image_to_window(*map, map->images.floor,
			map->player.pos_ply[1], map->player.pos_ply[0]);
		map->player.pos_ply[1]++;
		map->player.moves++;
	}
	put_image_to_window(*map, map->images.rpac[*i],
		map->player.pos_ply[1], map->player.pos_ply[0]);
	if (map->matrix[map->player.pos_ply[0]][map->player.pos_ply[1]] == 'C')
	{
		map->matrix[map->player.pos_ply[0]][map->player.pos_ply[1]] = 'J';
		map->player.colected++;
	}
}

int	enemy_jumps(t_map *map)
{
	int				x;
	int				y;
	static float	i;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->matrix[y][x] == 'G')
			{
				(i) += 0.00005;
				if (i > 2)
					i = 0;
				put_image_to_window(*map, map->images.enemy[(int)i], x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
