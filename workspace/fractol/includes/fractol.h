// #include <libft.h>
#include <mlx.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define MAXI 200
# define M_PI 3.14159265358979323846f


typedef struct s_complex 
{
    float x;
    float y;
} 				t_complex;

typedef struct	s_data 
{
	char	*addr;
	void	*img;
	int		bpp;
	int		len_line;
	int		endian;
}				t_data;

typedef struct s_fractol
{
	char *name;
	void *mlx;
	void *win;
	t_data img;
	//interation MAXI
}               t_fractol;

#endif
