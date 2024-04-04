#include "mlx.h"

# define WIDTH 800
# define LENGTH 800
# define MAXI 200

typedef struct {
    double x;
    double y;
} Point;

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
	Point coord;

	coord.x = 0;
	while(coord.x <= WIDHT)
	{
		coord.y = 0;
		while(coord.y <= LENGHT)
			map[coord.x][coord.y++] = actualfractol(coord, threshold, margin);
				//instead of using actual fractol, use function pointer
		coord.x++;
	}
	color_scheme(&map, color_mode); //change colours with images histogramming
	return (map);
}

double actualfractol(coord, threshold, margin)
{
	double i;
	double th_margin;
	double zx;
	double zy;

	zx = 0.0;
    zy = 0.0;
	th_margin = threshold - threshold * margin;
	//using int uses less resources.
	while (++i <= MAXI)
	{
		zx = (zx * zx) - (zy * zy) + coord.x;
		zy = (2*zx*zy) + coord.y;
		if (zx >= threshold)
			return (i / MAXI);
		if (zx >= th_margin)
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
