/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:25:39 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/14 14:25:39 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp, &f->img.len_line, &f->img.endian);
	return ;
}

int    main(void)
{
	t_fractol	*f;
    
	f = (t_fractol *) malloc (sizeof(t_fractol));
	if (!f)
		return(write(2, "fail", 5), 1);
	f->name = "Mardelbrot";
	init_mlx(f);
    parcel_args(f);
	create_val_array(f);
	recalc_vals(f);
    mlx_key_hook(f->win, handle_key, f);
    mlx_mouse_hook(f->win, handle_mouse, f);
	mlx_hook(f->win, 17, 0, handle_close, f);
	//mlx_loop_hook(f->mlx, animate_image, f);
    mlx_loop(f->mlx);
    return (0) ;
}
