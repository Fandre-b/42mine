/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:46:36 by fandre-b          #+#    #+#             */
/*   Updated: 2024/06/06 10:46:36 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    parcel_args(t_fractol *f, char *argv, int argc)
{
    int i;

    i = 1;
    i += parcel_nameset(&argv[i++], argc);
    while(i < argc)
    {
        if (ft_strcmp(f->name) == "JULIA")
        {
            f->info.c.x = ft_atod(argv[i++]);
            f->info.c.y = ft_atod(argv[i++]);
        }
        if (ft_strcmp(argv[i]) == "-c")
            i += parcel_colours(&argv[++i]);
        if (ft_strcmp(argv[i]) == "-i")
            f->info.maxi = ft_atoi(argv[++i]);
        if (ft_strcmp(argv[i]) == "-r")
            parcel_resulution(argv[++i]);
        i++;
    }
}

int parcel_nameset(t_fractol *f, char *argv, int argc)
{
    int i;

    i = 1;
    f->name = argv[i++];
    while (ft_strcmp(f->name) == "J" && i < 4)
    {
        f->info.c.x = ft_atod(argv[i++]);
        f->info.c.y = ft_atod(argv[i++]);
        f->name = "set_julia" //TODO names inside an array, so i can swap with handles
        f->info.start.x = -1.5;
        f->info.start.y =  -1.5;
        f->info.radius.x = 3.0;
        f->info.radius.y = 3.0;
    }
    if (ft_strcmp(f->name) == "M")
    {
        f->name = "set_mandelbrot"
        f->info.start.x = -2.5;
        f->info.start.y = -1.0;
        f->info.radius.x = 3.5;
        f->info.radius.y = 2.0;
    }
    if (ft_strcmp(f->name) == "B")
    {
        f->name = "set_burnship"
        f->info.start.x = -2.5;
        f->info.start.y = -2;
        f->info.radius.x = 4.0;
        f->info.radius.y = 3.0;
    }
    else
        f->name == NULL;
    return (i);
}

int     parcel_colours(char *argv, int argc) 
{
    int i;

    i = 0;
    while(ft_strcmp(argv[i]) != "-c" && ft_strcmp(argv[i]) != "-r" \
    && ft_strcmp(argv[i]) != "-i")
        i++;
    f->info.colours_pallete = (int) malloc (sizeof(int) * i);
    f->info.nmb_colour = i;
    while(i-- >= 0)
        colours_pallete[i] = atoih(argv[i]); //TODO atoih
    return (f->info.nmb_colour);
}

int     parcel_resulution(t_fractol *f, char *argv) //DONT need this
{
    int i;
    char *val;

    i = 0;
    while(argv[i] != 'x')
        i++;
    strnjoin(val, argv, i);
    if (val)
        f->resulution.x = atod(val);
    argv += agrv + i;
    while(argv[i])
        i++;
    strnjoin(val, argv, i);
    if (val)
        f->resulution.x = atod(val);
    free (val);
}
