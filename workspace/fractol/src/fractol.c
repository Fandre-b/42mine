/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:14:37 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/13 17:08:30 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	map_pixels(t_complex range, float margin, t_fractol *fractol);
void	init_mlx(t_fractol *fractol);
float	actualfractol(t_complex coord, double threshold, double margin);





void	init_mlx(t_fractol *fractol)
{
	int width;
	int height;
	
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->name = "Mardelbrot";
	fractol->img.img  = mlx_xpm_file_to_image(fractol->mlx, "fractal_broccoli.xpm", &width, &height);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	//fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bpp, &fractol->img.len_line, &fractol->img.endian);
	fractol->img.size [0] = width;
	fractol->img.size [1] = height;
	return ;
}

// int foo()
// {

// }




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
	fractol->name = "Mardelbrot";
	init_mlx(fractol);
	mlx_key_hook(fractol->win, handle_key, fractol);
    mlx_mouse_hook(fractol->win, handle_mouse, fractol);
	mlx_hook(fractol->win, 17, 0, handle_close, fractol);
	mlx_loop_hook(fractol->mlx, animate_image, fractol);
	mlx_loop(fractol->mlx);
	return (0);
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
