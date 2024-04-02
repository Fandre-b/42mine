/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:33:34 by mpais-go          #+#    #+#             */
/*   Updated: 2024/03/28 14:20:35 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	aux1_window_xpm_to_img(t_map *map, int x, int y)
{
	map->images.exit = mlx_xpm_file_to_image(map->mlx_ptr, EXIT, &x, &y);
	map->images.upac[0] = mlx_xpm_file_to_image(map->mlx_ptr, UPAC_O, &x, &y);
	map->images.upac[1] = mlx_xpm_file_to_image(map->mlx_ptr, UPAC_C, &x, &y);
	map->images.rpac[0] = mlx_xpm_file_to_image(map->mlx_ptr, RPAC_O, &x, &y);
	map->images.rpac[1] = mlx_xpm_file_to_image(map->mlx_ptr, RPAC_C, &x, &y);
	map->images.dpac[0] = mlx_xpm_file_to_image(map->mlx_ptr, DPAC_O, &x, &y);
	map->images.dpac[1] = mlx_xpm_file_to_image(map->mlx_ptr, DPAC_C, &x, &y);
	map->images.lpac[0] = mlx_xpm_file_to_image(map->mlx_ptr, LPAC_O, &x, &y);
	map->images.lpac[1] = mlx_xpm_file_to_image(map->mlx_ptr, LPAC_C, &x, &y);
	map->images.enemy[0] = mlx_xpm_file_to_image(map->mlx_ptr, ENEMY_U, &x, &y);
	map->images.enemy[1] = mlx_xpm_file_to_image(map->mlx_ptr, ENEMY_D, &x, &y);
	map->images.brdsglwall = mlx_xpm_file_to_image(map->mlx_ptr, BRDSGLWALL, 
			&x, &y);
	map->images.nobrdwall = mlx_xpm_file_to_image(map->mlx_ptr, NOBRDWALL, 
			&x, &y);
	map->images.uvert = mlx_xpm_file_to_image(map->mlx_ptr, UVERT, &x, &y);
	map->images.rvert = mlx_xpm_file_to_image(map->mlx_ptr, RVERT, &x, &y);
	map->images.dvert = mlx_xpm_file_to_image(map->mlx_ptr, DVERT, &x, &y);
	map->images.lvert = mlx_xpm_file_to_image(map->mlx_ptr, LVERT, &x, &y);
	map->images.floor = mlx_xpm_file_to_image(map->mlx_ptr, FLOOR, &x, &y);
}

void	aux2_window_xpm_to_img(t_map *map, int x, int y)
{
	map->images.necorner = mlx_xpm_file_to_image(map->mlx_ptr, NECORNER, 
			&x, &y);
	map->images.secorner = mlx_xpm_file_to_image(map->mlx_ptr, SECORNER, 
			&x, &y);
	map->images.socorner = mlx_xpm_file_to_image(map->mlx_ptr, SOCORNER, 
			&x, &y);
	map->images.nocorner = mlx_xpm_file_to_image(map->mlx_ptr, NOCORNER, 
			&x, &y);
	map->images.dblvrtwall = mlx_xpm_file_to_image(map->mlx_ptr, DBLVRTWALL, 
			&x, &y);
	map->images.dblhrzwall = mlx_xpm_file_to_image(map->mlx_ptr, DBLHRZWALL, 
			&x, &y);
	map->images.collect = mlx_xpm_file_to_image(map->mlx_ptr, COLLECTIBLE,
			&x, &y);
	map->images.uwall = mlx_xpm_file_to_image(map->mlx_ptr, UWALL,
			&x, &y);
	map->images.rwall = mlx_xpm_file_to_image(map->mlx_ptr, RWALL,
			&x, &y);
	map->images.dwall = mlx_xpm_file_to_image(map->mlx_ptr, DWALL,
			&x, &y);
	map->images.lwall = mlx_xpm_file_to_image(map->mlx_ptr, LWALL, 
			&x, &y);
}

void	window_xpm_to_img(t_map *map)
{
	int	x;
	int	y;

	x = 50;
	y = 50;
	aux1_window_xpm_to_img(map, x, y);
	aux2_window_xpm_to_img(map, x, y);
}

int	put_image_to_window(t_map map, void *image, int x, int y)
{
	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, image, 
		x * 50, y * 50);
	return (1);
}

void	img_to_window(t_map *map, int x, int y)
{
	char	current;

	current = map->matrix[y][x];
	if (current == '1')
		auxfinalwall_img_to_window(*map, x, y);
	else if (current == 'E')
	{
		map->og_exit[0] = y;
		map->og_exit[1] = x;
	}
	else if (current == 'C')
		put_image_to_window (*map, map->images.collect, x, y);
	else if (current == 'G')
		put_image_to_window (*map, map->images.enemy[0], x, y);
	else if (current == 'P')
		put_image_to_window (*map, map->images.upac[0], x, y);
}
