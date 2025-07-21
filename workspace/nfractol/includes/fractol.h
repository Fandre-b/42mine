// #include <libft.h>
#include <mlx.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1280
# define HEIGHT 800
# define MAXI 60
# define PI 3.142

typedef struct s_complex 
{
    float x;
    float y;
} 				t_complex;

typedef struct s_constr 
{
	struct s_constr	*backup;
	int update;
	float s_zoom;
	float escape;
	int inter;
	t_complex values[(int) 1280];
	t_complex pos;
	t_complex start;
	t_complex radius;
	t_complex step;
} 				t_constr; 

typedef struct	s_data //data structure for the image
{
	char	*addr;
	void	*img;
	int		bpp;
	int		len_line;
	int		endian;
	int		size[2];
	float	*matrix; //here or in fractol struct
	float 	zoom;
}				t_data;

typedef struct s_fractol //data structure for the fractal
{
	char *name;
	void *mlx;
	void *win;
	t_data img;
	t_constr constr;
}               t_fractol;

//main
void	init_mlx(t_fractol *fractol);
int		main(void);
//utils main
void parcel_args(t_fractol *fractol);
void my_pixel_put(t_data *img, int x, int y,int colour);
//draw map functions
float	actualfractol(t_complex coord, int maxi, float threshold);
void    map_pixels(t_fractol *fractol);
//// void    partial_map(t_fractol *fractol, t_complex shift)
void	recalc_vals(t_fractol *fractol);
//colour functions
unsigned int colour_convert(float *colour_grad);
int animate_image(void *param);
int animate_image2(void *param);
//events
int handle_key(int keycode, void *param);
int handle_mouse(int button, int x, int y, void *param);
//events utils
int handle_close(void *param);
void    reset_fractol(t_fractol *fractol);
void    move_img(int keycode, t_fractol *fractol);
void    zoom_times(int times, t_fractol *fractol);
void mouse_zoom(int button, int x, int y, t_fractol *fractol);

#endif
