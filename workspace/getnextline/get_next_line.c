/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:08:40 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/13 21:21:52 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char 	*new_str;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd <= 0 || fd > 16 || read(fd, 0, 0) < 0)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_str)
		return (NULL);
	new_str = ft_strchr(buffer, '\n');
	process_buffer(fd, new_str, buffer);
	return (new_str);
}

char	*process_buffer(int fd, char *new_str, char *buffer)
{
	int	count;
	
	count = 1;
	while (count > 0)
	{	
		ft_clearbuffer(buffer);
		count = read (fd, buffer, BUFFER_SIZE);
		if (count == 0)
			ft_strnjoin(new_str, "\n", 1);
		else if (ft_strchr(buffer, '\n'))
		{
			ft_strnjoin(new_str, buffer, ft_strchr(buffer, '\n') - buffer); 
			break ;
		}
		else
			ft_strnjoin(new_str, buffer, count);
	}
	return (new_str);
}

/* int	main(void)
{
	int	fd;
	char	*str;

	fd = open("Loren.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
		str = get_next_line(fd);
	printf("%s", str);
		str = get_next_line(fd);
	printf("%s", str);
		str = get_next_line(fd);
	printf("%s", str);
		str = get_next_line(fd);
	printf("%s", str);
		str = get_next_line(fd);
	printf("%s", str);
	return (0);
} 


char *Find_or_create_node(t_list **head, int fd) 
{
    t_list *r_node;

    if (!*head) 
    {
        r_node = Create_node(head, fd);
        return (r_node);
    } 
    r_node = *head;
    while (r_node->next) 
    {
        r_node = r_node->next;
        if (r_node->fd == fd) 
            return (r_node);
    }

    r_node = Create_node(head, fd);
    return (r_node);
}*/


