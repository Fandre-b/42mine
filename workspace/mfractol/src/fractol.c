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

void	free_struct(t_fractol *f)
{
	free(f->info.backup);
	free(f->info.array);
	free(f->info.step_array);
	free(f->info.palette);
    free(f->info.colours);
	free(f);
	return ;
}

void	init_mlx(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->name);
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp, &f->img.len_line, &f->img.endian);
	return ;
}

void init_std_info(t_fractol *f)
{
    f->info.s_zoom = 1.0f;
    f->info.maxi = MAXI;
    f->info.pos.x = -0.5f;
    f->info.pos.y = 0.0f;
    f->info.radius.x = 3.5f / 2;
    f->info.radius.y = 3.0f / 2;
    f->info.threshold = 2.0f;
    f->info.update = 1;
    f->info.loop_mode = 0;
	f->info.loop_func = animate_image;
    f->info.colour_mode = 0;
    f->info.fractol_set = actualfractol;
    f->info.fractol_mode = 0;
    //NULL animate_image psicadelic
    return ;
}

void init_struct(t_fractol *f)
{
	init_mlx(f);
    init_std_info(f);
    //parcel_args(f);
	f->info.backup = (t_info *) malloc (sizeof(t_info));
    if (!f->info.backup)
		return ;
    f->info.array = (int *) malloc (sizeof(int) * (WIDTH * HEIGHT));
    if (!f->info.array)
        return ;
    f->info.step_array = (double *) malloc (sizeof(double) * (WIDTH + HEIGHT));
    if (!f->info.step_array)
        return ;
    f->info.palette = (int *) malloc (sizeof(int) * (f->info.maxi));
    if (!f->info.palette)
        return ;
    f->info.colours = (int *) malloc (sizeof(int) * 7);
    if (!f->info.colours)
        return ;
    *f->info.backup = f->info;
    return;
}

int    main(void)
{
	t_fractol	*f;
    
	f = (t_fractol *) malloc (sizeof(t_fractol));
	if (!f)
		return (1);
	f->name = "Mardelbrot";	
	init_struct(f);
	recalc_vals(f);
    mlx_key_hook(f->win, handle_key, f);
    mlx_mouse_hook(f->win, handle_mouse, f);
	mlx_hook(f->win, 17, 0, handle_close, f);
	mlx_loop_hook(f->mlx, f->info.loop_func, f);  // TODO normal(animate) or psicadelic
    mlx_loop(f->mlx);
    return (0) ;
}
