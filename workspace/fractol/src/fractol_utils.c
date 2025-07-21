/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:07:21 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/13 17:07:21 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_pixel_put(t_data *img, int x, int y,int colour)
{//8 b
	int	offset;

	offset = (y * img->len_line) + (x * (img->bpp / 8));
    //line offset + inline pixel offset (8 bits per byte)
	*(unsigned int *) (img->addr + offset) = colour;
}

void	map_pixels(t_fractol *fractol, float **matrix)
{
	t_complex	coord;
	float		threshold;
	float		colour_grad;
    t_complex range;
    float margin;
	
    margin = 0.0f;
    range.x = 4.0f;
    range.y = 4.0f;
    //0 ate 800
    //para cada passar x/y * x.step/y.step
	threshold = 2.0f; //hip(range.x, range.y); //TODO
	coord.x = -2.0f;
	colour_grad = -1.0f;
	while(coord.x <= range.x / 2)
	{
		coord.y = -2.0f;
		while(coord.y <= range.y / 2) // && hip(coord.x, coord.y) <= threshold)
		{
			colour_grad = actualfractol(coord, 2.0f, margin);
            //matrix = colour_grad
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
	// float th_margin;
	t_complex z;
    float old_zx = z.x;


	i = 0;
	z.x = -1.0f;
    z.y = -1.0f;
	// th_margin = threshold - threshold * margin; 
	while (++i <= MAXI && z.x <= 2.0f && z.x >= -2.0f)
	{
		z.x = (z.x * z.x) - (z.y * z.y) + coord.x;
		z.y = (2 * old_zx * z.y) + coord.y;
		if ((threshold > 0 && z.x >= threshold) || (threshold < 0 && z.x <= threshold))
			return ((float) (i / MAXI));
		// if ((th_margin > 0 && z.x >= th_margin) || (th_margin < 0 && z.x <= th_margin))
		// 	return (1.0f);
        else
            return(1.0f);
	}
	if (i == MAXI)
		return (0.0f);
	return (0.0f);
}



// update2_image() TODO
// {////this is for latter when i add loops
//     //i can pass 1 or 2 to recalculate and update
//     //or to update only colours
//     //controll structure to be update in signal management

//         //order by change is: 
//         //axis position or complex plane range (new matrix)
//         ////auto zoom f.e.
//         //colour shift or colour range (new img.img update (change colours))
//         ////loop_colour or colour_shift
//     if (fractol->img.update == 1)
//     {//recalculate fractol and render pixels
//         //signal that new render is to be made after updates
//         //or set update to 2, next mlx loop will call update_image again
//     }
//     else if (fractol->img.update == 2)
//     {//render pixels with new colours
//         //signal that new render is to be made after updates
//         //set update to 0
//     }
//     else if (fractol->img.loops)
//     {
//         if (fractol->img.loop_colour)
            
//         //check in structure for loops and call functions acordingly
//         //call zoom function //for dynamic vars
//         ////call fractol function for pixel render with my_pixel_put
//         //call colour function  with my_pixel_put
//     }
//     else
//         return
//     //img2window
// }