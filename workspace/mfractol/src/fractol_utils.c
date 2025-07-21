/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:35:45 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/15 16:35:45 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_pixel_put(t_data *img, int x, int y, int colour)
{
	int	offset;

	offset = (y * img->len_line) + (x * (img->bpp / 8));
	*(unsigned int *) (img->addr + offset) = colour;
}


void    create_step_array(t_fractol *f)
{
    int i;
    t_complex start;
    t_complex step;

    start.x = f->info.pos.x - f->info.radius.x;
    start.y = f->info.pos.y - f->info.radius.y;
    step = f->info.step;
    i = -1;
    while (++i < WIDTH)
        f->info.step_array[i] = start.x + step.x * (double) i;
    while (i - WIDTH < HEIGHT)
    {
        f->info.step_array[i] = start.y + step.y * (double) (i - WIDTH);
        i++;
    }
    return ;    
}
