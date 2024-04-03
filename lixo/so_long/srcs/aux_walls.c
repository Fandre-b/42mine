/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:20:11 by mpais-go          #+#    #+#             */
/*   Updated: 2024/03/26 14:21:20 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	auxwall1_img_to_window(t_map map, int x, int y)
{
	if ((x == 0 && y == 0) || (x == map.width - 1 && y == 0) || (x == 0 && y
			== map.height - 1) || (x == map.width -1 && y == map.height - 1))
		return (put_image_to_window (map, map.images.nobrdwall, x, y));
	else if (y == map.height - 1)
	{
		if (map.matrix[y - 1][x] == '1')
			return (put_image_to_window (map, map.images.nobrdwall, x, y));
		else
			return (put_image_to_window (map, map.images.uwall, x, y));
	}
	else if (x == 0)
	{
		if (map.matrix[y][x + 1] == '1')
			return (put_image_to_window (map, map.images.nobrdwall, x, y));
		else
			return (put_image_to_window (map, map.images.rwall, x, y));
	}
	else if (y == 0)
	{
		if (map.matrix[y + 1][x] == '1')
			return (put_image_to_window (map, map.images.nobrdwall, x, y));
		else
			return (put_image_to_window (map, map.images.dwall, x, y));
	}
	return (0);
}

int	auxwall2_img_to_window(t_map map, int x, int y)
{
	char	up;
	char	right;
	char	left;
	char	down;

	if (x == map.width - 1)
	{
		if (map.matrix[y][x - 1] == '1')
			return (put_image_to_window (map, map.images.nobrdwall, x, y));
		else
			return (put_image_to_window (map, map.images.lwall, x, y));
	}
	else
	{
		up = map.matrix[y - 1][x];
		right = map.matrix[y][x + 1];
		left = map.matrix[y][x - 1];
		down = map.matrix[y + 1][x];
		if (down == '1' && right == '1' && up == '1' && left == '1')
			return (put_image_to_window (map, map.images.nobrdwall, x, y));
		else if (down == '1' && right == '1' && up != '1' && left == '1')
			return (put_image_to_window (map, map.images.uwall, x, y));
	}
	return (0);
}

int	auxwall3_img_to_window(t_map map, int x, int y)
{
	char	up;
	char	right;
	char	left;
	char	down;

	up = map.matrix[y - 1][x];
	right = map.matrix[y][x + 1];
	left = map.matrix[y][x - 1];
	down = map.matrix[y + 1][x];
	if (down == '1' && right != '1' && up == '1' && left == '1')
		return (put_image_to_window (map, map.images.rwall, x, y));
	else if (down != '1' && right == '1' && up == '1' && left == '1')
		return (put_image_to_window (map, map.images.dwall, x, y));
	else if (down != '1' && right == '1' && up == '1' && left == '1')
		return (put_image_to_window (map, map.images.dwall, x, y));
	else if (down == '1' && right == '1' && up == '1' && left != '1')
		return (put_image_to_window (map, map.images.lwall, x, y));
	else if (down != '1' && right != '1' && up != '1' && left != '1')
		return (put_image_to_window (map, map.images.brdsglwall, x, y));
	else if (down != '1' && right != '1' && up == '1' && left != '1')
		return (put_image_to_window (map, map.images.dvert, x, y));
	else if (down != '1' && right != '1' && up != '1' && left == '1')
		return (put_image_to_window (map, map.images.rvert, x, y));
	return (0);
}

int	auxwall4_img_to_window(t_map map, int x, int y)
{
	char	up;
	char	right;
	char	left;
	char	down;

	up = map.matrix[y - 1][x];
	right = map.matrix[y][x + 1];
	left = map.matrix[y][x - 1];
	down = map.matrix[y + 1][x];
	if (down == '1' && right != '1' && up != '1' && left != '1')
		return (put_image_to_window (map, map.images.uvert, x, y));
	else if (down != '1' && right == '1' && up != '1' && left != '1')
		return (put_image_to_window (map, map.images.lvert, x, y));
	else if (down != '1' && right != '1' && up == '1' && left == '1')
		return (put_image_to_window (map, map.images.secorner, x, y));
	else if (down == '1' && right != '1' && up != '1' && left == '1')
		return (put_image_to_window (map, map.images.necorner, x, y));
	else if (down == '1' && right == '1' && up != '1' && left != '1')
		return (put_image_to_window (map, map.images.nocorner, x, y));
	else if (down != '1' && right == '1' && up == '1' && left != '1')
		return (put_image_to_window (map, map.images.socorner, x, y));
	else if (down == '1' && right != '1' && up == '1' && left != '1')
		return (put_image_to_window (map, map.images.dblvrtwall, x, y));
	return (0);
}

void	auxfinalwall_img_to_window(t_map map, int x, int y)
{
	int	flag;

	flag = auxwall1_img_to_window(map, x, y);
	if (!flag)
		auxwall2_img_to_window(map, x, y);
	if (!flag)
		auxwall3_img_to_window(map, x, y);
	if (!flag)
		auxwall4_img_to_window(map, x, y);
	if (!flag && (map.matrix[y + 1][x] != '1' && map.matrix[y][x + 1] == '1' 
		&& map.matrix[y - 1][x] != '1' && map.matrix[y][x - 1] == '1'))
		put_image_to_window (map, map.images.dblhrzwall, x, y);
}
