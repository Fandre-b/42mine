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

void	recalc_vals(t_fractol *f)
{
	clock_t start, end;
	double cpu_time_used;

    f->info.maxi = (int) 60;// * (1 + pow((f->info.s_zoom), 0.12));
    f->info.radius.x = (3.5f / 2) / f->info.s_zoom;
    f->info.radius.y = (3.0f / 2) / f->info.s_zoom;
	f->info.step.x = (f->info.radius.x * 2) / WIDTH;
	f->info.step.y = (f->info.radius.y * 2) / HEIGHT;
	create_step_array(f);
	start = clock();
	if (f->info.update == 1)
		map_values(f);
    if(f->info.update == 2)
	{
        get_colours(f);
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time: %f\n", cpu_time_used);
	printf("maxi %d\n", f->info.maxi);
	return ;
}

double	actualfractol(t_complex coord, t_fractol *f, double threshold)
{
	static int i;
	static t_complex z;
	static double old_zx;
	// static double real_diff;
	// static double comp;
//0.5f around an mandelbrot set is also in it
//i can only render top half of mandelbrot set

	i = -1;
	z.x = 0;
	z.y = 0;
	// comp = (1.0f) / (f->info.maxi * 1000); //
	//comp = 1e-6f/(exp(f->info.maxi));
	while (++i <= f->info.maxi && z.x <= threshold && z.x >= -threshold)
	{
		if ((z.x * z.x + z.y * z.y) > 4.0)
			break ;
		old_zx = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + coord.x;
		z.y = (2 * old_zx * z.y) + coord.y;
		// real_diff = (z.x - old_zx) / old_zx;
		// if (real_diff < comp && real_diff > -comp)
		// 	return (0.0f);
	}
	if (i - 1 == f->info.maxi)
		return (0.0f);
	else
		return ((double)i / f->info.maxi);
	// else if (z.x == threshold || z.x == -threshold)
	// 	return (1.0f);
	// else if (z.x >= threshold || z.x <= -threshold)
	// 	return ((double)i / f->info.maxi);
	// return (1.0f);
	//return (i + 1 - log(log2(abs(z))));
}

int animate_image(void *param)
{
	t_fractol *f;

	f = param;
	map_values(f);
	return (0);
}

void map_values(t_fractol *f)
{
    static int i;
    static int j;
    static t_complex val; 

	j = -1;
	while(++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
        {
            val.x = f->info.step_array[i];
			val.y = f->info.step_array[WIDTH + j];
            f->info.array[j * WIDTH + i] = actualfractol(val, f, f->info.threshold);
		}
    }
    f->info.update = 2;
    return ;
}

void get_colours(t_fractol *f) //, unsigned int colour)
{
    int i;
    int j;
	int colour;

	j = -1;
	while(++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
        {
			colour = set_colour(f->info.array[j * WIDTH + i]);
            my_pixel_put(&f->img, i, j, colour);
        }
    }
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
    f->info.update = 0;
    return ;
}
