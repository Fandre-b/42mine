/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:16:43 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/06 10:56:04 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// int main(void)
// {
//     t_list *list = ["Node 1","Node 2", "Node 3"] 

//     ft_lstadd_front(&list, node1);
//     ft_lstadd_front(&list, node2);
//     ft_lstadd_front(&list, node3);

//     t_list *current = list;
//     while (current != NULL)
//     {
//         printf("%s\n", (char *)current->content);
//         current = current->next;
//     }

//     ft_lstclear(&list, free);

//     return 0;
// }
