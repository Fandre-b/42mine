/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:25:53 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/24 12:36:33 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	t_list	*temp;

	if (!lst || !del || !f)
		return (NULL);
	new_lst = NULL;
	temp = lst;
	while (temp)
	{
		new_elem = ft_lstnew(f(temp->content));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			del(new_elem);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		temp = temp->next;
	}
	return (new_lst);
}
