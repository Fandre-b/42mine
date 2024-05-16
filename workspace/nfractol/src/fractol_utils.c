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

void parcel_args(t_fractol *fractol) //argc argv
{
    t_constr    *info;

	info = (t_constr *) malloc (sizeof(t_constr));
    if (!fractol->constr.backup)
		return ;
    //info = fractol->constr;
    info->s_zoom = 1.0f;     //info->s_zoom VARIABLE
    info->inter = 100;       //magnification - will increase this value
    info->pos.x = -0.5f; //info->s_zoom move and mouse - changes this
    info->pos.y = 0.0f; //info->s_zoom move and mouse 
    info->range.x = 3.5f;    //info->s_zoom - will modify this value
    info->range.y = 3.0f;    //info->s_zoom
    // info->start.x = -2.0f;   //info->s_zoom move - will modify this value
    // info->start.y = -2.0f;   //info->s_zoom move
    info->step.x = info->range.x / WIDTH; //info->s_zoom - will modify this value
    info->step.y = info->range.y / HEIGHT;
    //escape = hip(range.x / 2, range.y / 2)
    info->escape = 4.0f; //info->s_zoom inscrises
    info->update = 1;
	fractol->constr = *info;
    fractol->constr.backup = info;	
	//*fractol->constr.backup = fractol->constr;

    return ;
}



void my_pixel_put(t_data *img, int x, int y, int colour)
{//8 b
	int	offset;

	offset = (y * img->len_line) + (x * (img->bpp / 8));
    //line offset + inline pixel offset (8 bits per byte)
	*(unsigned int *) (img->addr + offset) = colour;
}

int map_pixels_wrapper(void *param)
{
    t_fractol *fractol = (t_fractol *)param;
    map_pixels(fractol);
    return (0);
}
