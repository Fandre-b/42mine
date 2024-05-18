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

void parcel_args(t_fractol *f)
{
    t_info    *info;

	info = (t_info *) malloc (sizeof(t_info));
    if (!f->info.backup)
		return ;
    info->s_zoom = 1.0f;
    info->maxi = MAXI;
    info->pos.x = -0.5f;
    info->pos.y = 0.0f;
    info->radius.x = 3.5f / 2;
    info->radius.y = 3.0f / 2;
    info->threshold = 2.0f;
    info->update = 1;
	f->info = *info; //guarda copia
    f->info.backup = info; //guarda pointer de backup
    return ;
}

void my_pixel_put(t_data *img, int x, int y, int colour)
{//8 b
	int	offset;

	offset = (y * img->len_line) + (x * (img->bpp / 8));
    //line offset + inline pixel offset (8 bits per byte)
	*(unsigned int *) (img->addr + offset) = colour;
}

void create_val_array(t_fractol *f)
{   
    f->info.array = (float *) malloc (sizeof(float) * (WIDTH * HEIGHT));
    if (!f->info.array)
        return ;
    f->info.step_array = (float *) malloc (sizeof(float) * (WIDTH + HEIGHT));
    if (!f->info.step_array)
        return ;
    return;
}

void    create_step_array(t_fractol *f)
{
    int i;
    t_complex start;
    t_complex step;

    start.x = f->info.pos.x - f->info.radius.x;
    start.y = f->info.pos.y - f->info.radius.y;
    step.x = (f->info.radius.x * 2) / WIDTH;
    step.y = (f->info.radius.y * 2) / HEIGHT;
    i = -1;
    while (++i < WIDTH)
    {
        f->info.step_array[i] = start.x + step.x * (float) i;
    }
    while (i - WIDTH < HEIGHT)
    {
        f->info.step_array[i] = start.y + step.y * (float) (i - WIDTH);
        i++;
    }
    return ;    
}
