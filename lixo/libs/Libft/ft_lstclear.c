/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:05:45 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 17:52:40 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = NULL;
}
// #include <stdio.h>

// void custom_free(void *content)
// {
//     free(content);
// }

// int main(void)
// {
//     t_list *list = ["Node 1","Node 2", "Node 3"] 

//     printf("List before clearing:\n");
//     t_list *current = list;
//     while (current != NULL)
//     {
//         printf("%s\n", (char *)current->content);
//         current = current->next;
//     }

//     ft_lstclear(&list, custom_free);

//     printf("\nList after clearing:\n");
//     current = list;
//     if (current == NULL)
//     {
//         printf("The list is empty.\n");
//     }

//     return 0;
// }
