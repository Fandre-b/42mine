/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:27:23 by fandre-b          #+#    #+#             */
/*   Updated: 2024/04/03 20:27:23 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	//t_data	img;

	mlx = mlx_init();
	if (!mlx)
		return (0);
	mlx_win = mlx_new_window(mlx, HEIGHT, WIDTH, "Hello world!");
	if (!mlx_win)
		return (0);
    (void)mlx_win;
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_loop(mlx);
}
