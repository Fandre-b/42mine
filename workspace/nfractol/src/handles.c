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
 
    // printf("keycode: %d\n", keycode);
    fractol = (t_fractol *)param;
    if(keycode == 65307)
    {
        //exit_free(fractol);
        mlx_destroy_window(fractol->mlx, fractol->win);
        exit(0);
    }
    if (keycode == 65361 || keycode == 65363 || keycode == 65362 || keycode == 65364)
        move_img(keycode, fractol);
    if (keycode == 44 || keycode == 46)
        zoom_times(keycode, fractol);
    if (keycode == 114) //(r)
        reset_fractol(fractol); //recalls parcel_args
    // if (keycode == 99) //(c) //TODO upgrade colour palet and 
        //change_palete(1, fractol);
    //if (keycode >= 49 && keycode <= 57) //(1-9)
        //change_palete(keycode - 48, fractol);
    // if (keycode == 108) //(l)
        //fractol->loop_colour = 1;
    // if (keycode == 107) //(k)
        //fractol->loop_zoom = 1;
    return 0;
}
int handle_mouse(int button, int x, int y, void *param)
{
    t_fractol *fractol;
 
    // printf("button: %d\n", button);
    // printf("x: %d y: %d\n", x, y);
    fractol = (t_fractol *)param;
    if(button == 4 || button == 5) //up down
        mouse_zoom(button, x, y, fractol);
    if(button == 3) 
        mouse_zoom(button, x, y, fractol);
    // if button 4 print coord
    return 0;
}

int handle_close(void *param)
{
    t_fractol *fractol = (t_fractol *)param;
    //free(fractol); and exit
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
    exit(0);
}

//////////////////
//////////////////      NEW FILE
//////////////////
//////////////////

void    reset_fractol(t_fractol *fractol)
{
    t_constr *info;
    
	info = fractol->constr.backup;
    fractol->constr = *info;
    fractol->constr.backup = info;
    fractol->constr.update = 1;
    recalc_vals(fractol);
}

// static void	zoom(t_fractol *f, double zoom)
// {
// 	double	center_r;
// 	double	center_i;

// 	center_r = f->min_r - f->max_r;
// 	center_i = f->max_i - f->min_i;
// 	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
// 	f->min_r = f->max_r + zoom * center_r;
// 	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
// 	f->max_i = f->min_i + zoom * center_i;
// }//TODO

void    zoom_times(int keycode, t_fractol *fractol)
{
    float zoom_dir;

    zoom_dir = (45.0f - (float) keycode);//confusing
    if (zoom_dir > 0)
        fractol->constr.s_zoom *= 1.2f;
    else if (zoom_dir < 0)
        fractol->constr.s_zoom /= 1.2f;
    fractol->constr.update = 1;
    recalc_vals(fractol);
    return ;
}

void    move_img(int keycode, t_fractol *fractol)
{
    t_complex  shift;

    if(keycode == 65361 || keycode == 65363) //left or right
    {
        shift.x =  40.0f * fractol->constr.step.x * (float) (keycode - 65362);
        fractol->constr.pos.x += shift.x; // + fractol->constr.radius.x * 2;
    }
    else if(keycode == 65362 || keycode == 65364) //up or down
    {
        shift.y =  40.0f * fractol->constr.step.y * (float) (keycode - 65363);
        fractol->constr.pos.y += shift.y; // + fractol->constr.radius.y * 2;
    }
    //partial_map(fractol, shift); //TODO partial_map upgrade
    fractol->constr.update = 1;
    recalc_vals(fractol);
    return ;
}

void mouse_zoom(int button, int x, int y, t_fractol *fractol)
{
    t_constr info;
    
	info = fractol->constr;
    button = (4 - button);
    if (button == 0)
        fractol->constr.s_zoom *= 1.2f;
    else if (button < 0)
        fractol->constr.s_zoom /= 1.2f; //TODO reorganize main struct
    fractol->constr.pos.x += (x * info.step.x) - info.radius.x;
    fractol->constr.pos.y += (y * info.step.y) - info.radius.y;
    fractol->constr.update = 1;
    recalc_vals(fractol);
    return ;
}

//loops
//