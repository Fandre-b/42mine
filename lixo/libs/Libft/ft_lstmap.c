/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:19:03 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 17:49:36 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	new_lst = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			new_elem = ft_lstnew(f(lst->content));
			if (new_elem)
				ft_lstadd_back(&new_lst, new_elem);
			else
			{
				ft_lstclear(&new_lst, (*del));
				return (new_lst);
			}
			lst = lst->next;
		}
	}
	return (new_lst);
}
