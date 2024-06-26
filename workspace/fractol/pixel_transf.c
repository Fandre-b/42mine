/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_transf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:46:57 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/12 20:46:57 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void my_pixel_put(t_data *img, int x, int y,int colour)
{
	int	offset;

	offset = (y* img->len_line) + (x + (img->bpp / 8));
	*(unsigned int *) (img->addr + offset) = colour;
}

int animate_image(void *param)
{
	t_fractol *fractol;
    int *img_data;
    int bits_per_pixel;
    int size_line;
    int endian;

    fractol = (t_fractol *)param;
    img_data = (int *)mlx_get_data_addr(fractol->img.img, &bits_per_pixel, &size_line, &endian);
    for (int y = 0; y < fractol->img.size[1]; y++) {
        for (int x = 0; x < fractol->img.size[0]; x++) {
            int pixel_index = y * size_line / 4 + x;
            int color = img_data[pixel_index];

            // Shift the color channels to create a waving effect
            int r = (color >> 16) & 0xFF;
            int g = (color >> 8) & 0xFF;
            int b = color & 0xFF;
            r = (r + 1) % 256;
            g = (g + 2) % 256;
            b = (b + 3) % 256;
            color = (r << 16) | (g << 8) | b;
            img_data[pixel_index] = color;
        }
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	return (0);
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