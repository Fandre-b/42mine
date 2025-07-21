/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:25:19 by fandre-b          #+#    #+#             */
/*   Updated: 2024/05/17 15:25:19 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    create_step_array(t_fractol *f)
{
    int i;
    float *array;
    t_complex start;
    t_complex step;

    start.x = f->info->pos.x - f->info->radius.x;
    start.y = f->info->pos.y - f->info->radius.y;
    step.x = (f->info->radius.x * 2) / WIDTH;
    step.y = (f->info->radius.y * 2) / HEIGHT;
    array = (float *) malloc (sizeof(float) * (WIDHT + HEIGHT));
    if (!array)
        return ;
    i = -1;
    while (++i < WIDHT)
        array[i] = start.x + step.x * i;
    while (i - WIDHT < HEIGHT)
    {
        array[i] = start.y + step.y * (i - WIDHT);
        i++;
    }
    f->info->step_array = array;
    return ;    
}

create_val_array()
{
    float *array;
    
    array = (float *) malloc (sizeof(float) * (WIDHT * HEIGHT));
    if (!array)
        return ;
    f->info.array = array;
    return;
}

void map_values(t_fractol *f)
{
    int i;
    int j;
    t_complex val; 
    t_info info; 

    info = f->info;
	j = -1;
	while(++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
        {
            val.x = f->info.step_array[i];
            val.y = f->info.step_array[WIDTH + j];
            info.array[j * WIDTH + i] = actualfractol(val, f);
            //my_put_pixel(&addr_img, i, j, set_colour(array[j * WIDTH + i]))
        }
    }
    f->info.array = array;
    f->info.update = 2;
    return ;
}

void parcel_args(t_fractol *f)
{
    t_constr    *info;

	info = (t_constr *) malloc (sizeof(t_constr));
    if (!f->info.backup)
		return ;
    info->s_zoom = 1.0f;
    info->inter = MAXI;
    info->pos.x = -0.5f;
    info->pos.y = 0.0f;
    info->radius.x = 3.5f / 2;
    info->radius.y = 3.0f / 2;
    info->escape = 2.0f;
    info->update = 1;
	f->info = *info; //guarda copia
    f->info.backup = info; //guarda pointer de backup

    return ;
}

void	recalc_vals(t_fractol *f)
{
	clock_t start, end;
	double cpu_time_used;

	if (f->info.update == 0)
		return ;
    f->info.inter = (int) 60 * (1 + pow((f->info.s_zoom), 0.2));
    f->info.radius.x = (3.5f / 2) / f->info.s_zoom;
    f->info.radius.y = (3.0f / 2) / f->info.s_zoom;
	create_step_array(f);
	start = clock();
	if (f->info.update == 1)
		map_pixels(f);
    if(f->info.update == 2)
        get_colours(f); //colour);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("time %f\n", cpu_time_used);
	printf("inter %d\n", f->info.inter);
	return ;
}

void get_colours(t_fractol *f) //, unsigned int colour)
{
    int i;
    int j;
    t_complex val; 
    t_info *info;

    info = f->info;
	j = -1;
	while(++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
        {
            val = set_colour(info.array[j * WIDTH + i]);
            my_put_pixel(&fractol->img, i, j, val)
        }
    }
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
    f->info.update = 0;
    return ;
}

set_colour(float val)
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