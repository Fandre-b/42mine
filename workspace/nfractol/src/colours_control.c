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
	val = ((*colour_grad)); //(contraste)
    if(val == 0.0f)
        return (0x000000);
    r = (val) * 250;
	// if (val > 0.5f)
	// 	r = (val - 0.5f)/0.5f * 250;
	// else if (val < 0.5f)
	// 	b = (val)/0.5f * 250;
	rgb = (r << 16) | (g << 8) | b;
	//printf("%d\n", rgb);
	return (rgb);
}

///////////////////////////////
///////////////////////////////
///////////////////////////////

int animate_image(void *param)
{
	t_fractol *fractol;
    int *img_data;
    int bits_per_pixel;
    int size_line;
    int endian;

    fractol = (t_fractol *)param;
    img_data = (int *)mlx_get_data_addr(fractol->img.img, &bits_per_pixel, &size_line, &endian);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int pixel_index = y * size_line / 4 + x;
            int color = img_data[pixel_index];
            img_data[pixel_index] = color;
            // Shift the color channels to create a waving effect
            int r = (color >> 16) & 0xFF;
            int g = (color >> 8) & 0xFF;
            int b = color & 0xFF;
            r = (r + 2) % 256;
            //g = (g + 8) % 256;
            // b = (b + 2) % 256;
            if (color != 0x000000)
                color = (r << 16) | (g << 8) | b;
            img_data[pixel_index] = color;
        }
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	return (0);
}

int animate_image2(void *param)
{
	t_fractol *fractol;
    int *img_data;
    int bits_per_pixel;
    int size_line;
    int endian;

    fractol = (t_fractol *)param;
    img_data = (int *)mlx_get_data_addr(fractol->img.img, &bits_per_pixel, &size_line, &endian);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int pixel_index = y * size_line / 4 + x;
            int color = img_data[pixel_index];
            img_data[pixel_index] = color;
            // Shift the color channels to create a waving effect
            int r = (color >> 16) & 0xFF;
            int g = (color >> 8) & 0xFF;
            int b = color & 0xFF;
            r = 20.0 + (int)(32.0 * (sin(r / 32.0 * 2 * PI)));
            // g = 16 + (int)(32 * (1 + sin(g / 32.0 * 2 * PI)));
            // b = 16 + (int)(32 * (1 + sin(b / 32.0 * 2 * PI)));
            if (color != 0x000000)
                color = (r << 16) | (g << 8) | b;
            img_data[pixel_index] = color;
        }
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	return (0);
}
