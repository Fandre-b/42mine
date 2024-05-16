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

	i = 0;
	z.x = 0;
	z.y = 0;
	real_diff = 1.0f;
	if (hypot(coord.x, coord.y) > threshold)
		return (0.0f);
	while (++i <= maxi && z.x <= threshold && z.x >= -threshold)
	{
		old_zx = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + coord.x;
		z.y = (2 * old_zx * z.y) + coord.y;
		real_diff = fabs((z.x - old_zx) / old_zx);
		if (real_diff < 1.0f / (10 * maxi)) //* exp(-maxi / 10)) /
		{
			// printf("inter: %d\n", i);
			return (0.0f);
		}
	}
	if (i - 1 == maxi)
		return (0.0f);
	else if (z.x >= threshold || z.x <= -threshold)
		return ((float)((float)i / maxi));
	return (1.0f);
}

void    map_pixels(t_fractol *fractol)
{//
	t_complex start;
	t_constr info;
	float value;
	int idx[2];

	info = fractol->constr;
	start.y = info.pos.y - info.range.y / 2;
	idx[1] = -1;
	while(++idx[1] < HEIGHT)
	{
		start.x = info.pos.x - info.range.x / 2;
		idx[0] = -1;
		while (++idx[0] < WIDTH)
		{
			value = actualfractol(start, info.inter, info.escape);
			my_pixel_put(&fractol->img, idx[0], idx[1], colour_convert(&value));
			start.x += info.step.x;
		}
		start.y += info.step.y;
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
// 	while (start.y < end.y)
// 	{
// 		while (start.x < end.x)
// 		{
// 			value = actualfractol(start, info.escape);
// 			my_pixel_put(&fractol->img, idx[0], idx[1], colour_convert(&value));
// 			start.x += info.step.x;
// 		}
// 		start.y += info.step.y;
// 	}
// 	return ;
// }

void	recalc_vals(t_fractol *fractol)
{
    t_constr    info;

	info = fractol->constr;
	// info.update = 1;
    // info.s_zoom = ;     		Sao mudados     
    // info.pos.x = -0.5f; 		pelas funcoes
    // info.pos.y = 0.0f;
    info.inter += 20 * info.s_zoom;
    info.range.x = 3.5f * info.s_zoom;
    info.range.y = 3.0f * info.s_zoom;
    info.escape = 2.0f; //* info.s_zoom/10;
    info.step.x = info.range.x / WIDTH;
    info.step.y = info.range.y / HEIGHT;
    fractol->constr = info;
	if (info.update == 1)
		map_pixels(fractol);
	//if (info.update == 2)	
	info.update = 0;
	fractol->constr = info;
	return ;
}

