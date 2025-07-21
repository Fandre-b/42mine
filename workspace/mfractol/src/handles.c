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
 
    printf("keycode: %d\n", keycode);
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
    if (keycode == 99) //(c)
    {
        rotate_colours(f->info.colours, 7);
        set_color_mono(f, f->info.colours[0]);
        f->info.update = 2;
    }
    if (keycode == 108) //(l)
        change_loop(f);
    if (keycode == 121 || keycode == 117 || keycode == 105) 
        change_int(f, keycode);
    if (keycode == 112) //(p)
        change_palete(f);
    if (keycode == 102) //(f)
        change_fractol(f);
    recalc_vals(f);
    return (0);
}

void    change_loop(t_fractol *f)
{
    f->info.loop_mode++;
    f->info.loop_mode = f->info.loop_mode % 2;
    if (f->info.loop_mode == 0)
        f->info.loop_func = animate_image;
    if (f->info.loop_mode == 1)
        f->info.loop_func = psicadelic;
    f->info.update = 2;
    mlx_loop_hook(f->mlx, f->info.loop_func, f);
    return ;
}

void    change_palete(t_fractol *f)
{
    f->info.colour_mode++;
    f->info.colour_mode = f->info.colour_mode % 3;
    if (f->info.colour_mode == 0)
        set_color_mono(f, f->info.colours[0]);
    if (f->info.colour_mode == 1)
        set_color_mono(f, f->info.colours[0]);     
    if (f->info.colour_mode == 2)
        set_rainbow(f);
    f->info.update = 2;
}

void    change_int(t_fractol *f, int keycode)
{
    if (keycode == 121 && f->info.maxi > 10) // y
        f->info.maxi -= 10;
    if (keycode == 117) // i
        f->info.maxi = MAXI;
    if (keycode == 105) // u
        f->info.maxi += 10;
    free (f->info.palette);
    f->info.palette = (int *) malloc (sizeof(int) * (f->info.maxi));
    if (!f->info.palette)
        return ;
    f->info.backup->palette = f->info.palette;
    f->info.update = 1;
}

void    change_fractol(t_fractol *f)
{
    f->info.fractol_mode++;
    f->info.fractol_mode = f->info.fractol_mode % 3;
    if (f->info.fractol_mode == 0)
        f->info.fractol_set = actualfractol;
    if (f->info.fractol_mode == 1)
        f->info.fractol_set = julia;
    if (f->info.fractol_mode == 2)
        f->info.fractol_set = burnship;
    f->info.update = 1;
    recalc_vals(f);
    return ;

}

void back_up_fractol(t_fractol *f)
{
    *f->info.backup = f->info;
    return ;
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

    zoom_dir = (45.0f - (keycode));
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
        f->info.pos.x += 40.0f * f->info.step.x * (keycode - 65362);
    else if(keycode == 65362 || keycode == 65364) //up or down
        f->info.pos.y += 40.0f * f->info.step.y * (keycode - 65363);
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
