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



// static int	interpolate(int startcolor, int endcolor, double fraction)
// {
// 	int	start_rgb[3];
// 	int	end_rgb[3];

// 	start_rgb[0] = ((startcolor >> 16) & 0xFF);
// 	start_rgb[1] = ((startcolor >> 8) & 0xFF);
// 	start_rgb[2] = ((startcolor >> 0) & 0xFF);
// 	end_rgb[0] = ((endcolor >> 16) & 0xFF);
// 	end_rgb[1] = ((endcolor >> 8) & 0xFF);
// 	end_rgb[2] = ((endcolor >> 0) & 0xFF);
// 	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * fraction + start_rgb[0];
// 	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * fraction + start_rgb[1];
// 	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * fraction + start_rgb[2];
// 	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
// }

/* set_color_mono:
*	Sets a monochromatic color scheme. Colors range from
*	black to the provided color, to white near the fractal
*	border.
*/
// void	set_color_mono(t_fractol *f, int color)
// {
// 	int		i;
// 	int		j;
// 	double	fraction;
// 	int		color1;
// 	int		color2;

// 	color1 = 0x000000;
// 	color2 = color;
// 	i = 0;
// 	while (i < MAX_ITERATIONS)
// 	{
// 		j = 0;
// 		while (j < MAX_ITERATIONS / 2)
// 		{
// 			fraction = (double)j / (MAX_ITERATIONS / 2);
// 			f->palette[i + j] = interpolate(color1, color2, fraction);
// 			j++;
// 		}
// 		color1 = color2;
// 		color2 = 0xFFFFFF;
// 		i += j;
// 	}
// 	f->palette[MAX_ITERATIONS -1] = 0;
// }

unsigned int set_colour(double val)
{
	int r;
	int g;
	int b;
	unsigned int rgb;

	r = 0;
	g = 0;
	b = 0;
    if(val == 0.0f)
        return (0x000000);
    r = (val) * 255;
	rgb = (r << 16) | (g << 8) | b;
	return (rgb);
}