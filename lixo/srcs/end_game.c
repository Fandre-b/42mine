/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:49:44 by mpais-go          #+#    #+#             */
/*   Updated: 2024/03/28 12:41:14 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	aux_destroy_images(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->images.brdsglwall);
	mlx_destroy_image(map->mlx_ptr, map->images.collect);
	mlx_destroy_image(map->mlx_ptr, map->images.dblhrzwall);
	mlx_destroy_image(map->mlx_ptr, map->images.dblvrtwall);
	mlx_destroy_image(map->mlx_ptr, map->images.dpac[0]);
	mlx_destroy_image(map->mlx_ptr, map->images.dpac[1]);
	mlx_destroy_image(map->mlx_ptr, map->images.dvert);
	mlx_destroy_image(map->mlx_ptr, map->images.dwall);
	mlx_destroy_image(map->mlx_ptr, map->images.enemy[0]);
	mlx_destroy_image(map->mlx_ptr, map->images.enemy[1]);
	mlx_destroy_image(map->mlx_ptr, map->images.exit);
	mlx_destroy_image(map->mlx_ptr, map->images.lpac[0]);
	mlx_destroy_image(map->mlx_ptr, map->images.lpac[1]);
	mlx_destroy_image(map->mlx_ptr, map->images.lvert);
	mlx_destroy_image(map->mlx_ptr, map->images.lwall);
	mlx_destroy_image(map->mlx_ptr, map->images.necorner);
	mlx_destroy_image(map->mlx_ptr, map->images.nobrdwall);
	mlx_destroy_image(map->mlx_ptr, map->images.nocorner);
	mlx_destroy_image(map->mlx_ptr, map->images.rpac[0]);
	mlx_destroy_image(map->mlx_ptr, map->images.rpac[1]);
	mlx_destroy_image(map->mlx_ptr, map->images.rvert);
	mlx_destroy_image(map->mlx_ptr, map->images.rwall);
	mlx_destroy_image(map->mlx_ptr, map->images.secorner);
	mlx_destroy_image(map->mlx_ptr, map->images.socorner);
}

void	destroy_images(t_map *map)
{
	aux_destroy_images(map);
	mlx_destroy_image(map->mlx_ptr, map->images.upac[0]);
	mlx_destroy_image(map->mlx_ptr, map->images.upac[1]);
	mlx_destroy_image(map->mlx_ptr, map->images.uvert);
	mlx_destroy_image(map->mlx_ptr, map->images.uwall);
	mlx_destroy_image(map->mlx_ptr, map->images.floor);
}

void	end_game(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	destroy_images(map);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	free_matrix(map->matrix);
	exit(0);
}

int	exit_button(t_map *map)
{
	end_game(map);
	return (0);
}

void	*end_game_msg(t_map map, char *msg)
{
	ft_putstr_fd(msg, 2);
	end_game(&map);
	return (NULL);
}
