/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:08:40 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/20 14:13:14 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char 	*new_str;
	static char buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 16 || read(fd, 0, 0) < 0)
		return (NULL);
	new_str = NULL;
	new_str = ft_process_buffer(fd, new_str, buffer);
	if (!new_str)
	{
		ft_clearbuffer(buffer, BUFFER_SIZE + 1);
		if (new_str)
			free(new_str);
		return (NULL);

	}
    return (new_str);
}

char	*ft_process_buffer(int fd, char *new_str, char *buffer)
{
	int	count;
	int	newline_pos;
	
	count = 1;
	while (count > 0 || buffer[0] != '\0')
	{	
		newline_pos = ft_strchr_index(buffer, '\n');
		if (newline_pos >= 0 && buffer[0] != '\0') //criar while para isto
		{
			new_str = ft_strnjoin(new_str, buffer, newline_pos + 1);
			buffer = ft_memshift(buffer, newline_pos + 1);
			break ;
		}
		new_str = ft_strnjoin(new_str, buffer, BUFFER_SIZE);
		buffer = ft_clearbuffer(buffer, BUFFER_SIZE + 1); //no fim de cada ciclo limpar
		count = read (fd, buffer, BUFFER_SIZE); // count no inicio
	}
	if (count == -1 || (count == 0 && !new_str))
	{
		ft_clearbuffer(buffer, BUFFER_SIZE + 1);
		if (new_str)
			free(new_str);
		return (NULL);
	}
	return (new_str);
}
/* char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *new_str = NULL;
    int count;
    int newline_pos;

    while ((newline_pos = ft_strchr_index(buffer, '\n')) == -1) //add count -1
    {
        count = read(fd, buffer, BUFFER_SIZE);
        if (count <= 0)
        {
            if (count == 0)
                new_str = ft_strnjoin(new_str, buffer, ft_strchr_index(buffer, '\0'));
            ft_clearbuffer(buffer, BUFFER_SIZE + 1);
            return (new_str);
        }
        buffer[count] = '\0';
        new_str = ft_strnjoin(new_str, buffer, count);
    }
    new_str = ft_strnjoin(new_str, buffer, newline_pos);
    ft_memshift(buffer, newline_pos + 1);
    return (new_str);
} */

/* int	main(void)
{
	int	fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	
	printf("%s\n//////////\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n//////////\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n//////////\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n//////////\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n//////////\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n//////////\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n//////////\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n//////////\n", str);
	free(str);
	return (0);
} */


/*
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


