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

# define WIDTH 1080
# define HEIGHT 720
# define MAXI 60
# define PI 3.142

typedef struct s_complex 
{
    double x;
    double y;
} 				t_complex;

typedef struct	s_data //data structure for the image
{
	char	*addr;
	void	*img;
	int		bpp;
	int		len_line;
	int		endian;
	int		size[2];
	double	*matrix; //here or in f struct
	double 	zoom;
}				t_data;

typedef struct s_info 
{
	struct s_info	*backup;
	int update;
	int maxi;
	double s_zoom;
	double threshold;
	t_complex start_pos; //different sets start at diff places
	t_complex pos; //central value, maybe it aint needed?
	t_complex radius; 
	t_complex step;
	t_complex c;
	double 	*step_array;
	int		*array;
	int		*palette;
	int	(*loop_func)(void *);
} 				t_info; 

typedef struct s_fractol //data structure for the fractal
{
	char *name;
	void *mlx;
	void *win;
	t_complex resolution;
	t_data img;
	t_info info;
}               t_fractol;

// //main
// void	init_mlx(t_fractol *f);
// int		main(void);
// int psicadelic(void *param);
// //utils main
// void parcel_args(t_fractol *f);
// void my_pixel_put(t_data *img, int x, int y,int colour);
// void init_struct(t_fractol *f);
// void    create_step_array(t_fractol *f);


// //draw map functions
// int	actualfractol(t_complex c, t_fractol *f, double threshold);
// void map_values(t_fractol *f);
// //// void    partial_map(t_fractol *f, t_complex shift);
// void	recalc_vals(t_fractol *f);
// //colour functions
// void get_colours(t_fractol *f); //, unsigned int colour);
// void	set_color_mono(t_fractol *f, int color);
// void	set_color_dual(t_fractol *f, int color1, int color2);
// void	set_rainbow (t_fractol *f);

// unsigned int set_colour(double val, int colour);
// void	my_own_set(t_fractol *f, int color);
// //events
// int handle_key(int keycode, void *param);
// int handle_mouse(int button, int x, int y, void *param);
// //events utils
// int handle_close(void *param);
// void    reset_fractol(t_fractol *f);
// void    move_img(int keycode, t_fractol *f);
// void    zoom_times(int times, t_fractol *f);
// void mouse_zoom(int button, int x, int y, t_fractol *f);

// int animate_image(void *param);

//colour value generation
unsigned int set_colour(double val, int colour);
int	interpolate(int startcolor, int endcolor, double fraction);
int		generate_rainbow(double fraction);
//colour pallet generation
void	set_rainbow (t_fractol *f);
void	my_own_set(t_fractol *f, int color);
void	set_color_mono(t_fractol *f, int color);
void	set_color_dual(t_fractol *f, int col1, int col2);
void	set_color_multi(t_fractol *f, int *colors, int num_colors);
//colours control
void get_colours(t_fractol *f); //, unsigned int colour);
//animation
int psicadelic(void *param);

void map_values(t_fractol *f);
void	recalc_vals(t_fractol *f);
int animate_image(void *param);
//fractal set calculations
int	actualfractol(t_complex c, t_fractol *f, double threshold);
int	burnship(t_complex c, t_fractol *f, double threshold);
int	julia(t_complex c, t_fractol *f, double threshold);
//
//structures initializations
void init_std_info(t_fractol *f);
void my_pixel_put(t_data *img, int x, int y, int colour);
void init_struct(t_fractol *f);
void    create_step_array(t_fractol *f);

void	init_mlx(t_fractol *f);
int    main(void);
//event handles
int handle_key(int keycode, void *param);
int handle_mouse(int button, int x, int y, void *param);
int handle_close(void *param);
//events utils
void    reset_fractol(t_fractol *f);
void    zoom_times(int keycode, t_fractol *f);
void    move_img(int keycode, t_fractol *f);
void mouse_zoom(int button, int x, int y, t_fractol *f);



#endif
