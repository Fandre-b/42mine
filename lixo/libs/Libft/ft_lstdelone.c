/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:17:11 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 17:53:29 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
// #include <stdio.h>

// void custom_free(void *content)
// {
//     free(content);
// }

// int main(void)
// {
//     t_list *node = ["Node 1"];

//     printf("Node content before deletion: %s\n", (char *)node->content);

//     ft_lstdelone(node, custom_free);

//     printf("Node has been deleted.\n");

//     return 0;
// }