/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:08:14 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/13 21:08:00 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#ifndef BUFFER_SIZE
# define FOPEN_MAX 16
#endif

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

/* typedef struct s_infofd
{
	int		fd;
	char	*extra_buff;
	s_infofd	*next;
}	t_infofd;

typedef struct s_temp_buffer
{
	char	*buffer;
	s_temp_buffer	*next;
}	t_temp_buffer;
 */
//functions

char  *ft_strnjoin(char *old_str, char *str_add, int size);
int		ft_strchr_index(char *str, char c);
char	*ft_clearbuffer(void *str, int size);
char *get_next_line(int fd);
char	*ft_process_buffer(int fd, char *new_str, char *buffer);
char    *ft_memshift(void *str, int n_shift);

#endif