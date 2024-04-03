/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:52:08 by mpais-go          #+#    #+#             */
/*   Updated: 2024/03/28 14:20:30 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	keymoves(int keycode, t_map *map)
{
	static int	i;

	if (keycode == 'w' || keycode == 65362)
		move_up(map, &i);
	else if (keycode == 'a' || keycode == 65361)
		move_left(map, &i);
	else if (keycode == 's' || keycode == 65364)
		move_down(map, &i);
	else if (keycode == 'd' || keycode == 65363)
		move_right(map, &i);
	if (keycode == 65307)
		end_game(map);
	if (map->nbr_c == map->player.colected)
	{
		put_image_to_window(*map, map->images.exit,
			map->og_exit[1], map->og_exit[0]);
		map->flag_exit = 1;
	}
	if (map->flag_exit 
		&& map->matrix[map->player.pos_ply[0]][map->player.pos_ply[1]] == 'E')
		end_game_msg(*map, "Congrats, you won!\n");
	if (map->matrix[map->player.pos_ply[0]][map->player.pos_ply[1]] == 'G')
		end_game_msg(*map, "Game Over\n");
	print_n_moves(map);
	return (0);
}

void	complete_images(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			img_to_window(map, x, y);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac < 2)
		return (1);
	get_map(av[1], &map);
	if (validate_map(&map))
	{
		map.mlx_ptr = mlx_init();
		if (!map.mlx_ptr)
			return (0);
		map.win_ptr = mlx_new_window (map.mlx_ptr,
				50 * map.width, 50 * map.height, "Pacman");
		if (!map.win_ptr)
			return (0);
		window_xpm_to_img(&map);
		complete_images(&map);
		mlx_key_hook(map.win_ptr, keymoves, &map);
		mlx_loop_hook(map.mlx_ptr, enemy_jumps, &map);
		mlx_hook(map.win_ptr, 17, 0, exit_button, &map);
		mlx_loop(map.mlx_ptr);
	}
	free_matrix(map.matrix);
	return (1);
}
