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
    r = (val) * 250;
	rgb = (r << 16) | (g << 8) | b;
	return (rgb);
}