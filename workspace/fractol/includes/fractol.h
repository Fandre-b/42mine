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


struct s_constructer
{
	int *cplx_size; //
	float **axis_center;
	//int colour_range[2];
	int update;
	// int loop_colour;
	// int loop_zoom;
	int zoom_multiplier;
}         t_constructer;

// --complexplane size //1
// --axis_center //1
// --colour range //2
// --update
// --loop_colour
// --loop_zoom
// --zoom multiplier

struct fractal_func_map {
    const char *name;
    fractal_func func;
};

typedef struct s_production 
{
	update_image;
	// --size of the image ()
	// --vibration (wanted this to slightly shift the image to give a wavy effect)
	// --shift loop (kepp running) //bool
	// --auto zoom (bool)
	// --resolution (add blur)
	// --colour scheme //user may controll scheme, saturation, brightness, contrast, hue, etc
	// --change speed// so an variable can be used to dynamic change number of interations and window change spee
} 				t_production;

typedef struct s_complex 
{
    float x;
    float y;
} 				t_complex;

typedef struct	s_data //data structure for the image
{
	char	*addr;
	void	*img;
	int		bpp;
	int		len_line;
	int		endian;
	float	*matrix; //here or in fractol struct
	int		size[2];
	float 	zoom;
}				t_data;

typedef struct s_fractol //data structure for the fractal
{
	char *name;
	void *mlx;
	void *win;
	t_data img;
	//t_constructer cons;

	//interation MAXI
}               t_fractol;


void	init_mlx(t_fractol *fractol);
int		main(void);
int handle_key(int keycode, void *param);
int handle_mouse(int x, int y, void *param);
int animate_image(void *param);
void my_pixel_put(t_data *img, int x, int y,int colour);
unsigned int colour_convert(float *colour_grad);
int handle_close(void *param);
void zoom_image(t_fractol *fractol, float zoom_factor);



#endif
