/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:25:39 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/14 14:25:39 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bpp, &fractol->img.len_line, &fractol->img.endian);
	return ;
}

int    main(void)
{
	t_fractol	*fractol;
    
	fractol = (t_fractol *) malloc (sizeof(t_fractol));
	if (!fractol)
		return(write(2, "fail", 5), 1);
	fractol->name = "Mardelbrot";
	init_mlx(fractol);
    parcel_args(fractol);
    map_pixels(fractol);
    mlx_key_hook(fractol->win, handle_key, fractol);
    mlx_mouse_hook(fractol->win, handle_mouse, fractol);
	mlx_hook(fractol->win, 17, 0, handle_close, fractol);
	//mlx_loop_hook(fractol->mlx, animate_image, fractol);
    mlx_loop(fractol->mlx);
    return (0) ;
}
