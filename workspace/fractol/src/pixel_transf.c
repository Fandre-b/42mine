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


void zoom_image(t_fractol *fractol, float zoom_factor) {
    int new_width = fractol->img.size[0] * zoom_factor;
    int new_height = fractol->img.size[1] * zoom_factor;

    void *new_img = mlx_new_image(fractol->mlx, new_width, new_height);

	while (i < new_height)
		while (j < new_width)
            int old_x = x / zoom_factor;
            int old_y = y / zoom_factor;

            int color = mlx_get_pixel_color(fractol->img.img, old_x, old_y);
            mlx_put_pixel_to_image(new_img, x, y, color);
        }
    }

    mlx_destroy_image(fractol->mlx, fractol->img.img);
    fractol->img.img = new_img;
    fractol->img.size[0] = new_width;
    fractol->img.size[1] = new_height;
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