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

    f->info.maxi = (int) MAXI;// * (1 + pow((f->info.s_zoom), 0.12));
    f->info.radius.x = (4.0f / 2) / f->info.s_zoom;
    f->info.radius.y = (3.0f / 2) / f->info.s_zoom;
	f->info.step.x = (f->info.radius.x * 2) / WIDTH;
	f->info.step.y = (f->info.radius.y * 2) / HEIGHT;
	create_step_array(f);
	my_own_set(f, 0x448EE4); // if there is no colour, pick first of the array.
	//set_color_mono(f, 0x448EE4); // TODO create array for colours to be chosed from
	//set_color_dual(f, 0xFF0000, 0x00FF00); //DONT need this
	//set_rainbow(f); //DONT need this
	start = clock();
	if (f->info.update == 1)
		map_values(f);
	end = clock();
    if(f->info.update == 2)
	{
        get_colours(f);
	}
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time %f with maxi = %d\n", cpu_time_used, f->info.maxi);
	return ;
}

int	actualfractol(t_complex c, t_fractol *f, double threshold)
{
	static int i;
	static t_complex z;
	static double old_zx;

	i = 0;
	z.x = 0;
	z.y = 0;
	while (++i < f->info.maxi && z.x <= threshold && z.x >= -threshold)
	{
		if ((z.x * z.x + z.y * z.y) > 4.0)
			break ;
		old_zx = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = (2 * old_zx * z.y) + c.y;
	}
	return (i);
}

int	burnship(t_complex c, t_fractol *f, double threshold)
{
	static int i;
	static t_complex z;
	static double old_zx;

	i = 0;
	z.x = 0;
	z.y = 0;
	while (++i < f->info.maxi && z.x <= threshold && z.x >= -threshold)
	{
		if ((z.x * z.x + z.y * z.y) > 4.0)
			break ;
		old_zx = z.x;
		z.x = fabs((z.x * z.x) - (z.y * z.y) + c.x);
		z.y = fabs((2 * old_zx * z.y) + c.y);
	}
	return (i);
}

int	julia(t_complex c, t_fractol *f, double threshold)
{
	static int i;
	static t_complex z;
	static double old_zx;

	i = 0;
	z = c;
	c.x = -0.8;
	c.y = 0.156;
	while (++i < f->info.maxi && z.x <= threshold && z.x >= -threshold)
	{
		if ((z.x * z.x + z.y * z.y) > 4.0)
			break ;
		old_zx = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = (2 * old_zx * z.y) + c.y;
	}
	return (i);
}

int animate_image(void *param) // DONT need this one
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
	//static int colour;
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
			// TODO this actual fractol function will be replaced by variable function.
            // colour = f->info.palette[f->info.array[j * WIDTH + i] - 1];
			// my_pixel_put(&f->img, i, j, colour);
			// my_pixel_put(&f->img, i, j, f->info.palette[actualfractol(val, f, 2.0f)]);
		}
    }
	// mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
    f->info.update = 2;
    return ;
}
