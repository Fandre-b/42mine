/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:32:44 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/15 16:32:44 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	actualfractol(t_complex coord, int maxi, float threshold)
{
	int i;
	t_complex z;
	float old_zx;
	float real_diff;
	float comp;

	i = 0;
	z.x = 0;
	z.y = 0;
	real_diff = 1.0f;
	comp = (1.0f) / (maxi * 100); //
	//comp = (1.0f) * exp(-maxi / 10); // 
	while (++i <= maxi && z.x <= threshold && z.x >= -threshold)
	{
		old_zx = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + coord.x;
		z.y = (2 * old_zx * z.y) + coord.y;
		real_diff = (z.x - old_zx) / old_zx;
		if (real_diff < comp && real_diff > -comp)
		{
			printf("real_diff %d\n", i);
			return (0.0f);
		}
	}
	if (i - 1 == maxi)
		return (0.0f);
	else if (z.x >= threshold || z.x <= -threshold)
		return ((float)i / maxi);
	return (1.0f);
}

// void    map_pixels(t_fractol *fractol)
// {//TODO make zoom allways pair mux8 and reuse addrs
// //para minimizar pixel_gen.
// 	t_constr info;
// 	float value;
// 	int idx[2];

// 	info = fractol->constr;
// 	idx[1] = -1;
// 	while(++idx[1] < HEIGHT)
// 	{
// 		info.start.x = fractol->constr.start.x;
// 		idx[0] = -1;
// 		while (++idx[0] < WIDTH)
// 		{
// 			value = actualfractol(info.start, info.inter, info.escape);
// 			my_pixel_put(&fractol->img, idx[0], idx[1], colour_convert(&value));
// 			info.start.x += info.step.x;
// 		}
// 		info.start.y += info.step.y;
// 	}
// 	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
// 	return ;
// }

void    map_pixels(t_fractol *fractol)
{//TODO make zoom allways pair mux8 and reuse addrs
//para minimizar pixel_gen.
	t_constr info;
	t_complex coord;
	float value;
	int idx[2];

	info = fractol->constr;
	idx[1] = -1;
	while(++idx[1] < HEIGHT)
	{
		idx[0] = -1;
		while (++idx[0] < WIDTH)
		{
			coord.x = info.values[idx[0]].x;
			coord.y = info.values[idx[1]].y;
			value = actualfractol(coord, info.inter, info.escape);
			my_pixel_put(&fractol->img, idx[0], idx[1], colour_convert(&value));
		}
		info.start.y += info.step.y;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	return ;
}

// void    partial_map(t_fractol *fractol, t_complex shift)
// {
// 	// t_complex idx;
// 	t_complex   start;
// 	t_complex   end;
// 	// int     times

// 	// time = ftactol
// 	// se shift pos
// 	//     start = start + shift
// 	// else
// 	//     end = shift
// 	// shiftar a matriz signal dependent
// 	// gerar novos valores
// 	while (info.start.y < end.y)
// 	{
// 		while (info.start.x < end.x)
// 		{
// 			value = actualfractol(start, info.escape);
// 			my_pixel_put(&fractol->img, idx[0], idx[1], colour_convert(&value));
// 			info.start.x += info.step.x;
// 		}
// 		info.start.y += info.step.y;
// 	}
// 	return ;
// }

void	recalc_vals(t_fractol *fractol)
{
    t_constr    info;
	int i;
	clock_t start, end;
	double cpu_time_used;

	i = -1;
	info = fractol->constr;
	if (info.update == 0)
		return ;
    info.inter = (int) 60 * (1 + pow((info.s_zoom), 0.2));
    info.radius.x = (3.5f / 2) / info.s_zoom;
    info.radius.y = (3.0f / 2) / info.s_zoom;
    info.escape = 2.0f;
	info.start.x = info.pos.x - info.radius.x;
	info.start.y = info.pos.y - info.radius.y;
    info.step.x = info.radius.x * 2 / WIDTH;
    info.step.y = info.radius.y * 2 / HEIGHT;
	while (++i < fmax(HEIGHT, WIDTH))
	{
		info.values[i].x = info.start.x + (i * info.step.x);
		info.values[i].y = info.start.y + (i * info.step.y);
	}
    fractol->constr = info;
	start = clock();
	if (info.update == 1)
		map_pixels(fractol);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("time %f\n", cpu_time_used);
	printf("inter %d\n", info.inter);
	//if (info.update == 2)	
	info.update = 0;
	fractol->constr = info;
	return ;
}

