#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h> 
#include <stdbool.h> 
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <time.h>
#include <wchar.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("Loren.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("//////////\n");
	free(str);
	str = get_next_line(fd);
	printf("//////////\n");
	free(str);
	/* str = get_next_line(fd);
	printf("//////////\n");
	free(str);
	str = get_next_line(fd);
	printf("//////////\n");
	free(str);
	str = get_next_line(fd);
	printf("//////////\n");
	free(str);
	str = get_next_line(fd);
	printf("//////////\n");
	free(str);
	str = get_next_line(fd);
	printf("//////////\n");
	free(str);
	str = get_next_line(fd);
	printf("//////////\n");
	free(str); */
	return (0);
}