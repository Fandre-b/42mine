/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:14:37 by fandre-b          #+#    #+#             */
/*   Updated: 2024/04/19 12:54:41 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	map_pixels(t_complex range, float margin, t_fractol *fractol);
void	init_mlx(t_fractol *fractol);
float	actualfractol(t_complex coord, double threshold, double margin);


int		main(void)
{
	t_fractol	*fractol;
	//t_complex	range;
	//float	margin;
	
	//range.x = -2.0f;
	//range.y = 2.0f;
	//margin = 0.0f;
	fractol = (t_fractol *) malloc (sizeof(t_fractol));
	if (!fractol)
		return(write(2, "fail", 5), 1);
	printf("ola\n");
	fractol->name = "Mardelbrot";
	init_mlx(fractol);
	//map_pixels(range, margin, fractol);
	mlx_loop(fractol->mlx);
	return (0);
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	printf("ola\n");
	//fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bpp, &fractol->img.len_line, &fractol->img.endian);
	return ;
}

unsigned int colour_convert(float *colour_grad)
{
	float val;
	int r;
	int g;
	int b;
	unsigned int rgb;

	//r = 0.5f * (1.0f + cos(2.0f * M_PI * (*val + 0.0f)));
	//g = 0.5f * (1.0f + cos(2.0f * M_PI * (*val + 0.33f)));
	//b = 0.5f * (1.0f + cos(2.0f * M_PI * (*val + 0.67f)));
	r = 0;
	g = 0;
	b = 0;
	val = *colour_grad;
	if (val > 0.5f)
		r = (val - 0.5f)/0.5f * 250;
	else if (val < 0.5f)
		g = (val)/0.5f * 250;
	rgb = (r << 16) | (g << 8) | b;
	printf("%d\n", rgb);
	return (rgb);
}

void my_pixel_put(t_data *img, int x, int y,int colour)
{
	int	offset;

	offset = (y* img->len_line) + (x + (img->bpp / 8));
	*(unsigned int *) (img->addr + offset) = colour;
}

void	map_pixels(t_complex range, float margin, t_fractol *fractol)
{
	t_complex	coord;
	float		threshold;
	float		colour_grad;
	

	threshold = 2.0f; //hip(range.x, range.y); //TODO
	coord.x = -2.0f;
	colour_grad = -1.0f;
	while(coord.x <= range.x)
	{
		coord.y = -2.0f;
		while(coord.y <= range.y) // && hip(coord.x, coord.y) <= threshold)
		{
			colour_grad = actualfractol(coord, threshold, margin);
			my_pixel_put(&fractol->img, coord.x*(WIDTH/2), coord.y*(HEIGHT/2), colour_convert(&colour_grad)); //TODO
			coord.y += range.y/HEIGHT;
		}
		coord.x += range.x/WIDTH;
	}
	//if (colour_grad == -1.0f) //is outside from the start
	return ;
}

float	actualfractol(t_complex coord, double threshold, double margin)
{
	int i;
	float th_margin;
	t_complex z;

	z.x = 0.0f;
    z.y = 0.0f;
	i = 0;
	th_margin = threshold - threshold * margin; 
	while (++i <= MAXI && z.x <= 2.0f && z.x >= -2.0f)
	{
		z.x = (z.x * z.x) - (z.y * z.y) + coord.x;
		z.y = (2*z.x*z.y) + coord.y;
		if ((threshold > 0 && z.x >= threshold) || (threshold < 0 && z.x <= threshold))
			return ((float) (i / MAXI));
		if ((th_margin > 0 && z.x >= th_margin) || (th_margin < 0 && z.x <= th_margin))
			return (1.0f);
	}
	if (i == MAXI)
		return (0.0f);
	return (0.0f);
}
