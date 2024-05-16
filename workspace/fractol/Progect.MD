### TODO ####
//como lidar com conversao height float values
//se tenho altura e largura diff float


### do inicio #################
parcel info
->use some kind of printf flag finder that will implement flags in arguments. maybe reuse pipex flag
->flags will change structure that will add variation to pixel production
->create these structures //mos just have to be malloc colour has more into it

-->pixel production controll //used to change 
	--size of the image
	--vibration
	--loop (kepp running) 
	--resolution (add blur)
	--auto zoom
	--colour scheme //user may controll scheme, saturation, brightness, contrast, hue, etc
	--change speed// so an variable can be used to dynamic change number of interations and window change spee

->pixel production output
	--axix pos
	--colour (linked list)
	--zoom (change dinamicly lots of variables (see functions for them))

->mlx structure
	-mlx
	-mlx window
	-mlx image
	-mlx key
	-mlx mouse
	-mlx hook
	-mlx loop //
	-mlx pixel //center
	-mlx color //scheme
	-mlx xpm

mlxinitiate();
iniciate mlx
whait for change
->{whells zoom, esq/cross exit}
->//{zoom follow mouse, arrow keys move, shift "make colour range shift"}
Open fractol //this here can be tested alot with img/pixel put internat picture

fractall_caller();
->function that can loop or not depending on signal ??loop allways
	if struct changed
	//open while indefinitly
	//calculate the fractal();, // keep loop for collor change
	//if new calculations with new values
		////my_pixel_put(buffer, struct); new pixels buffer 
		////pass pixels into window
		////pass window
	//update_struct(); if(color/pos change)

//foo//update_struct(); depending on what is activated change position and clours (liked list next)
//foo//pixell production (given the output of fractall change pixels colout)

update struct with new values
//foo//change collor to into next -> have liked structures for colour change next (change colour)
//flag//function that vibrates image with colour and axis shit (change colour and pos_dinamic)
//pos//check how possition is passed into program with signals (pos dinamic)
fractoll_calulations()

deal errors and prints
free all
return

-----------------
need to have min 3 sets
find way to imprve to run fast
save moves, dinamic resolution, 
see more downpage there alot of theory


_________________

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

