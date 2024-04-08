#include "fractol.h" 

int main(void)
{
	void	*img;
	void	*mlx;
	int threshold = 2; //temp
	int margin = 5; //temp

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
	map_pixels(threshold, margin);
	return;
}

double **map_pixels(threshold, margin)
{
	double map[WIDHT][LENGHT];
	t_complex coord;

	coord.x = 0;
	while(coord.x <= WIDHT)
	{
		coord.y = 0;
		while(coord.y <= LENGHT)
			colour = actualfractol(coord, threshold, margin);
				//instead of using actual fractol, use function pointer
				//maybe just print the pixel
		coord.x++;
	}
	color_scheme(&map, color_mode); //change colours with images histogramming
	return (map);
}

double actualfractol(t_complex coord, double threshold, double margin)
{
	double i;
	double th_margin;
	t_complex z;

	z.x = 0.0;
    z.y = 0.0;
	i = 0;
	th_margin = threshold - threshold * margin; //might not be necessaty
	//using int uses less resources.
	while (++i <= MAXI)
	{
		z.x = (z.x * z.x) - (z.y * z.y) + coord.x;
		z.y = (2*z.x*z.y) + coord.y;
		if (z.x >= threshold)
			return (i / MAXI);
		if (z.x >= th_margin)
			return (1);
		i++;
	}
	if (i == MAXI)
		return (0);
	//this way i can return max value for borther, min inside and have float for outside
}

	// z = z^2 + cxy
	// z^2 = (zx + zy)^2 = zx^2 + 2*zx*zy + zy^2
	// zy^2 = (val*i) = -val
	// 2*zx*zy = 2zx*val*i
	//for each pixel discover if it goes out of bounds
	//so if i had 800x800 i had to run fractol calculations 640k times 1 for each pixel? YES
	//map pixels for nmb of interations needed to converge to inf
	//then remap those pixels to colour, using threshholded value
	//mlx just picks up this map and prints it
	//so image stroct would have **matix, resolution, 
		//mlx
		//initialize window, intialize pixels
		//set pixels
		//whait for instructios
			//set actions
			//set mouse position as 0,0
			//
}
