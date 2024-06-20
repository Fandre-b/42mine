/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:34:23 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/15 16:34:23 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	interpolate(int startcolor, int endcolor, double fraction)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = ((startcolor >> 16) & 0xFF);
	start_rgb[1] = ((startcolor >> 8) & 0xFF);
	start_rgb[2] = ((startcolor >> 0) & 0xFF);
	end_rgb[0] = ((endcolor >> 16) & 0xFF);
	end_rgb[1] = ((endcolor >> 8) & 0xFF);
	end_rgb[2] = ((endcolor >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * fraction + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * fraction + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * fraction + start_rgb[2];
	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}

int		generate_rainbow(double fraction)
{
	int r;
	int g;
	int b;

	r = (int) (sin(2.0 * PI * fraction) * 127.5) + 127.5;
	g = (int) (sin(2.0 * PI * fraction + 2.0 * PI / 3.0) * 127.5) + 127.5;
	b = (int) (sin(2.0 * PI * fraction + 4.0 * PI / 3.0) * 127.5) + 127.5;
	return ((r << 16) | (g << 8) | b);
}
void	set_rainbow (t_fractol *f) //DONT need this
{
	int		i;
	double	fraction;

	i = 0;
	while (i < f->info.maxi)
	{
		fraction = (double)i / 7;
		f->info.palette[i] = generate_rainbow(fraction);
		i++;
	}
	f->info.palette[f->info.maxi -1] = 0;
}

void	set_colour_array(t_fractol *f, int number)
{
	int		i;
	double	fraction;

	i = 0;
	while (i < number)
	{
		fraction = (double)i / (number + 1);
		f->info.colours[i] = generate_rainbow(fraction);
		i++;
	}
	return;
}

void	set_color_mono(t_fractol *f, int color)
{
	static int		i;
	static int		j;
	static double	fraction;
	static int		color1;
	static int		color2;

	color1 = 0x000000;
	color2 = color;
	i = 0;
	while (i < f->info.maxi)
	{
		j = 0;
		while (j < f->info.maxi / 2)
		{
			fraction = (double)j / (f->info.maxi / 2);
			f->info.palette[i + j] = interpolate(color1, color2, fraction);
			j++;
		}
		color1 = color2;
		color2 = 0xFFFFFF;
		i += j;
	}
	f->info.palette[f->info.maxi - 1] = 0;
}

void get_colours(t_fractol *f)
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
			colour = f->info.palette[f->info.array[j * WIDTH + i] - 1];
			my_pixel_put(&f->img, i, j, colour);
        }
    }
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
    f->info.update = 0;
    return ;
}

int psicadelic(void *param) //just a swapper of palletes, and easy to implement
{
	t_fractol *f;

	f = param;
	rotate_colours(f->info.palette, f->info.maxi);
	f->info.update = 2;
	get_colours(f);
	return (0);
}

int rotate_colours(int *array, int size)
{
	int i;
	int temp;

	i = 0;
	temp = array[0];
	while (i < size - 1)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[size - 1] = temp;
	return (0);
}
