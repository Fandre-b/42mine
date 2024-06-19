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

unsigned int set_colour(double val, int colour) //DONT need this
{
	int r;
	int g;
	int b;

	if (val == 1 || colour != 0)
		return (0xFFFFFF);
	r = val * 255 * 2;
	g = 0;
	b = 0;
	// r = (val) * ((colour >> 16) & 0xFF);
	// g = (val) * ((colour >> 8) & 0xFF);
	// b = (val) * ((colour >> 0) & 0xFF);
	return ((r << 16) | (g << 8) | b);
}

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
		fraction = (double)i / (f->info.maxi);
		f->info.palette[i] = generate_rainbow(fraction);
		i++;
	}
	f->info.palette[f->info.maxi -1] = 0;
}

void	my_own_set(t_fractol *f, int color)
{
	int		i;
	double	fraction;

	i = 0;
	while (i < f->info.maxi)
	{
		fraction = (double)i / (f->info.maxi - 1);
		f->info.palette[i] = set_colour(fraction, color);
		i++;
	}
	f->info.palette[f->info.maxi -1] = 0;
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
	f->info.palette[f->info.maxi -1] = 0;
}

void	set_color_dual(t_fractol *f, int col1, int col2) //DONT need this
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;

	color1 = 0x000000;
	color2 = col1;
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
		if (col2 < 0)
			color2 = 0xFFFFFF;
		else
			color2 = col2;
		i += j;
	}
	f->info.palette[f->info.maxi -1] = 0;
}

void	set_color_multi(t_fractol *f, int *colors, int num_colors) //DONT need this
{
    int		i;
    int		j;
    double	fraction;
    int		color1;
    int		color2;
    int		segment_size;

    segment_size = f->info.maxi / num_colors;
    i = 0;
    while (i < f->info.maxi)
    {
        color1 = colors[i / segment_size];
        color2 = colors[(i / segment_size + 1) % num_colors];
        j = 0;
        while (j < segment_size)
        {
            fraction = (double)j / segment_size;
            f->info.palette[i + j] = interpolate(color1, color2, fraction);
            j++;
        }
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
	int i;
	int temp;

	i = 0;
	f = param;
	temp = f->info.palette[1];
	while (i < f->info.maxi - 1)
	{
		f->info.palette[i] = f->info.palette[i + 1];
		i++;
	}
	f->info.palette[f->info.maxi - 2] = temp;
	f->info.update = 2;
	get_colours(f);
	return (0);
}