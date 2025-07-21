/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:55:38 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/12 20:55:38 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_key(int keycode, void *param)
{
    t_fractol *fractol;
 
    fractol = (t_fractol *)param;
    //check arrow keys and move the axis //change pos
    //shift shifts colours rotate colours
    //+ and - zoom in and out //change range
    //r resets the fractal structure //recall parcel_args
    //all before set update to 1(recalc fractol) or 2(colours)
    //esc closes the window
    //loop changes does not set update (or to 3) (they will be called in update_image)
    printf("keycode %d\n", keycode);
    if(keycode == 17 || keycode == 65307)
    {
        mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
        exit(0);
    }
    if (keycode == 126)
    {
        // Move the fractal up
        mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
        exit(0);
    }
    // else if (keycode == KEY_DOWN)
    // {
    //     // Move the fractal down
    //     fractol->y_offset += MOVE_AMOUNT;
    // }
    // Handle other keys...
    // Handle the key press event
    // keycode contains the code of the key that was pressed
    // param is the same pointer that you passed to mlx_key_hook
    // ...
    return 0;
}

int handle_mouse(int button, int x, int y, void *param)
{
    t_fractol *fractol;
 
    fractol = (t_fractol *)param;
    //zoom //change zoom and pos
    //set update in structure to 1
    if(x == 4 || y == 5) //up down
    {
        //fractol->zoom /*= ZOOM_FACTOR;
        exit(0);
        fractol->img.img = mlx_xpm_file_to_image(fractol->mlx, "fractal_broccoli.xpm", &fractol->img.size[0], &fractol->img.size[1]);
        fractol = (t_fractol *)param;
    }
    // Handle the mouse event
    // x and y are the coordinates of the mouse
    // param is the same pointer that you passed to mlx_mouse_hook
    // ...
    return 0;
}

int handle_close(void *param)
{//cross also exists
    t_fractol *fractol = (t_fractol *)param;
    //free(fractol); and exit
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
    exit(0);
}