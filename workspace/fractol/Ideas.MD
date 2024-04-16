
###
 So an fractol is the repetition of an strocture. Its is defined by some rule and falls out of bounds when this rule is not meet.
 f.e. mandelbrot set uses as rule the sum series Z = Z^2 + c <Z is the complex value and C the complex stating position>

 -Max number of permited interections sets how detailed the fractol will be. (so positive zoom could end in no fractol proprities.)
 -Zoom is to change values intreval, and there for also the Boundary limit. #TODO set as 2 for start
 -the Boundary would be directly proportional with the values range (zout = (max - min) * (max - min)) #TODO set as 4 for start
 --Altho range is usually -2 to 2 because of complex propreties
 -also the number of interations is inversly porpotional to the size of range #TODO

###

	the calculations will be repeated for each possible pixel, starting from center and do circular moves resolution dependent
		(0,0) is the top/left pixel
	the Boundary will be contrasted with center values, the rest will be interation dependent
	after that an colout tranformation will be done #TODO
		since im gettin float i can do gradient transformation.
		log (makes colour more predominant closer to the limit)

	after colour transf. convert colour to mlx formar 0xRRRGGGBBB (255 value)

###

mlx = mlx_init();												-- initializes 
mlx_win = mlx_new_window(mlx, LENGTH, WIDTH, "Hello world!");	-- creates the window
img = mlx_new_image(mlx, 1920, 1080);							-- creates the image
mlx_new_image													-- alocs image memmory
mlx_destroy_image												-- dealocs image memmory
mlx_put_image_to_window											-- puts the created image into the screen
mlx_get_color_value												-- tranforms an int RRRGGGBBB into 0xRRRGGGBBB
mlx_xpm_file_to_image											-- creates an image from an file
mlx_get_data_addr												-- reads image and gives out the values of this said image
mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color); 
																-- puts pixel into the image 
				(does it puts directly into the window or image first?)





###
In fractal visualization, colors are typically used to represent the number of iterations it takes for a point to escape to infinity under the fractal-generating function. This is often called the "escape time" algorithm.

The simplest way to color a fractal is to choose two colors and create a gradient between them, with one color representing a point that escapes quickly and the other color representing a point that escapes slowly. The color of each point on the fractal is then determined by its escape time.

However, there are many ways to enhance this basic coloring method to produce more visually interesting images:

- **Multiple gradients**: Instead of just transitioning between two colors, you can transition between multiple colors. For example, you could transition from red to green for points that escape quickly, and then from green to blue for points that escape slowly.

- **Color cycling**: Instead of mapping the escape time directly to a color, you can use the escape time as an index into a color palette, and cycle through the palette multiple times. This can create a "banding" effect that highlights the structure of the fractal.

- **Smooth coloring**: Instead of using the raw escape time to determine the color, you can use a smooth function of the escape time. This can eliminate the "banding" effect and create a smoother gradient of colors.

- **Histogram coloring**: Instead of mapping the escape time directly to a color, you can create a histogram of escape times, and use the histogram counts to determine the colors. This can ensure that all colors are used equally, and can highlight subtle features of the fractal.

###

The specific coloring method used can vary widely depending on the specific fractal being generated and the aesthetic choices of the programmer.

zoom will change the range (double) 

maybe run zoom in small inbetween steps

periodicity checking - if z value return to arroud an known z value we can say that its trapped within the boundry
 ###

Yes, there are data structures that are designed to efficiently handle intervals or ranges of values, such as Interval Trees and Segment Trees. These are particularly useful in computational geometry and similar fields where you often need to work with ranges of values.

An Interval Tree is a type of binary search tree where each node stores an interval (or range of values), and you can query the tree to find all intervals that overlap with a given interval. This can be useful for quickly finding all z values that are within a certain range, for example.

A Segment Tree is another type of binary tree used for storing intervals, or segments. It allows for faster querying (retrieval) of these intervals for a certain point or another interval.

intervall tree to find values

###

Use compiler optimizations: Most compilers have options to optimize your code. For example, in GCC, you can use the -O2 or -O3 option to enable various performance optimizations.

##

