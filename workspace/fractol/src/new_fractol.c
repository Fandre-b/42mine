/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:34:55 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/13 13:34:55 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol *fractol)
{
	int width;
	int height;
	
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->name = "Mardelbrot";
	//|vv|vv| temp use or image
    fractol->img.img  = mlx_xpm_file_to_image(fractol->mlx, "fractal_broccoli.xpm", &width, &height);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	//by then create img.addr addr is first ptr to imag pixel
    //fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bpp, &fractol->img.len_line, &fractol->img.endian);
	fractol->img.size [0] = width;
	fractol->img.size [1] = height;
	return ;
}

main()
{
    t_fractol *fractol;
    
    fractol = (t_fractol *) malloc (sizeof(t_fractol));
    if (!fractol)
        return(write(2, "fail", 5), 1);
    init_mlx(fractol);
    fractol->name = "Mardelbrot";
    //parcell args //TODO dependendo das flags tem ativacoes na estrutura contruct
    //render_fractol(fractol); // cria a matrix dos valores do fractoll //TODO
    mlx_key_hook(fractol->win, handle_key, fractol);
    mlx_mouse_hook(fractol->win, handle_mouse, fractol);
    mlx_hook(fractol->win, 17, 0, handle_close, fractol);
    mlx_loop_hook(fractol->mlx, update_image(args), fractol);
    mlx_loop(fractol->mlx);
    return (0);
}

// parcel_argms
// {
//     //read flags and pre-set the construct fractoll structure
//     //zoom scale (for complex plane and Interations number) ***
//     //colour range (linked list?)

//     //loop_colour
//     //loop_zoom
// }

fractol_caller()
{
    float   **matrix;
    // void    *func;  //TODO var: actual fractol function

    matrix = (float **)malloc(sizeof(float *) * WIDTH);
    while (i < HEIGHT)
        matrix[i] = (float *)malloc(sizeof(float) * HEIGHT);
    fractoll->img->matrix = matrix;
    if(fractol->img.update == 1)
        //actualfractol(fractol, float **matrix)
        //for now will do just shifts and zoom
        //fill_matrix()
    else if (fractol->img.update == 2)
        fill the img with the new colours
        //fill_colours(t_fractol fractol, float *matrix) //TODO

}

void    fill_matrix()
{
    //recolher zoom
    //complex plane x/y * zoom
    //matrix [-W/2;W/2]/[-H/2;H/2]
    x_step = cplx_w * zoom / WIDHT
    y_step = cplx_h * zoom / HEIGHT

    //callc pixel_step
    //

}


update_image() TODO
{
//this is to deal with loops latter and will be the one to call fractoll caller
}

//need to check how is fractal window. when i do zoom i change this window range or what