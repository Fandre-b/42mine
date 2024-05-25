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
    t_fractol *f;
 
    // printf("keycode: %d\n", keycode);
    f = (t_fractol *)param;
    if(keycode == 65307)
    {
        //exit_free(f);
        mlx_destroy_window(f->mlx, f->win);
        exit(0);
    }
    if (keycode == 65361 || keycode == 65363 || keycode == 65362 || keycode == 65364)
        move_img(keycode, f);
    if (keycode == 44 || keycode == 46)
        zoom_times(keycode, f);
    if (keycode == 114) //(r)
        reset_fractol(f); //recalls parcel_args
    // if (keycode == 99) //(c) //TODO upgrade colour palet and 
        //change_palete(1, f);
    //if (keycode >= 49 && keycode <= 57) //(1-9)
        //change_palete(keycode - 48, f);
    // if (keycode == 108) //(l)
        //f->loop_colour = 1;
    // if (keycode == 107) //(k)
        //f->loop_zoom = 1;
    return 0;
}
int handle_mouse(int button, int x, int y, void *param)
{
    t_fractol *f;
 
    f = (t_fractol *)param;
    if(button == 4 || button == 5) //up down
        mouse_zoom(button, x, y, f);
    if(button == 3) 
    {
        f->info.pos.x += f->info.step.x * (x - WIDTH / 2);
        f->info.pos.y += f->info.step.y * (y - HEIGHT / 2);
        f->info.update = 1;
        recalc_vals(f);
    }
    // if button 4 print coord
    return 0;
}

int handle_close(void *param)
{
    t_fractol *f = (t_fractol *)param;
    //free(f); and exit
    mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
    exit(0);
}

//////////////////
//////////////////      NEW FILE
//////////////////
//////////////////

void    reset_fractol(t_fractol *f)
{
    t_info *info;

	info = f->info.backup;
    info->array = f->info.array;
    info->step_array = f->info.step_array;
    f->info = *info;
    f->info.backup = info;
    f->info.update = 1;
    recalc_vals(f);
}

void    zoom_times(int keycode, t_fractol *f)
{
    double zoom_dir;

    zoom_dir = (45.0f - (double) keycode);
    if (zoom_dir > 0)
        f->info.s_zoom *= 1.2f;
    else if (zoom_dir < 0)
        f->info.s_zoom /= 1.2f;
    f->info.update = 1;
    recalc_vals(f);
    return ;
}

void    move_img(int keycode, t_fractol *f)
{
    if(keycode == 65361 || keycode == 65363) //left or right
        f->info.pos.x += 40.0f * f->info.step.x * (double) (keycode - 65362);
    else if(keycode == 65362 || keycode == 65364) //up or down
        f->info.pos.y += 40.0f * f->info.step.y * (double) (keycode - 65363);
    f->info.update = 1;
    recalc_vals(f);
    return ;
}

void mouse_zoom(int button, int x, int y, t_fractol *f)
{
    t_complex   val;
    
    button = (4 - button);
    val.x = f->info.step_array[x];
    val.y = f->info.step_array[WIDTH + y];
    if (button == 0)
        f->info.s_zoom *= 1.2f;
    else if (button < 0)
        f->info.s_zoom /= 1.2f;
    recalc_vals(f);
    f->info.pos.x = val.x + (WIDTH / 2 - x) * f->info.step.x;
    f->info.pos.y = val.y + (HEIGHT / 2 - y) * f->info.step.y;
    f->info.update = 1;
    recalc_vals(f);
    return ;
}


//loops
//