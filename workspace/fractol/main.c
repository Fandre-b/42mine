/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:15:40 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/12 18:15:40 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


libjpeg lib to xpm
    mlx_xpm_file_to_image(fractol->mlx, "output.xpm", &fractol->img.width, &fractol->img.height);


float	actualfractol(t_complex coord, double threshold, double margin)
{
	int i;
	float th_margin;
	t_complex z;

	z.x = 0.0f;
    z.y = 0.0f;
	i = 0;
	th_margin = threshold - threshold * margin; 	///////
	while (++i <= MAXI && z.x <= 2.0f && z.x >= -2.0f)
	{
		z.x = (z.x * z.x) - (z.y * z.y) + coord.x; 	//////
		z.y = (2*z.x*z.y) + coord.y;				///////
		if ((threshold > 0 && z.x >= threshold) || (threshold < 0 && z.x <= threshold))
			return ((float) (i / MAXI));
		if ((th_margin > 0 && z.x >= th_margin) || (th_margin < 0 && z.x <= th_margin))
			return (1.0f);
	}
	if (i == MAXI)
		return (0.0f);
	return (0.0f);
}

void my_pixel_put(t_data *img, int x, int y,int colour)
{
	int	offset;

	offset = (y * img->len_line) + (x + (img->bpp / 8));
	*(unsigned int *) (img->addr + offset) = colour;
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bpp, &fractol->img.len_line, &fractol->img.endian);
	return ;
}

unsigned int colour_convert(float *colour_grad)
{
	float val;
	int r;
	int g;
	int b;
	unsigned int rgb;

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