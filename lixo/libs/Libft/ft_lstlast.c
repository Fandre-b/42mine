/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:18:19 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 17:55:20 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>

// int main(void)
// {
//     t_list *list = ["Node 1","Node 2", "Node 3", "Node 4" ] 

//     t_list *last = ft_lstlast(list);

//     printf("The last element in the list is: %s\n", (char *)last->content);

//     ft_lstclear(&list, free);

//     return 0;
// }
