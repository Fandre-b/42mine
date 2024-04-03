/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:05:20 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 17:50:15 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
// #include <stdio.h>

// int main(void)
// {
//     t_list *node = ft_lstnew(ft_memdup("Hello, World!", 14));

//     if (node)
//     {
//         printf("Node content: %s\n", (char *)node->content);

//         free(node->content);
//         free(node);
//     }
//     else
//     {
//         printf("Failed to create a new node.\n");
//     }

//     return 0;
// }