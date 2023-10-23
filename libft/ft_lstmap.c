/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:25:53 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/23 17:50:25 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *newlst;
    t_list  *newelem;

    while(lst)
    {
        newelem = ft_lstnew(lst->content);
        if (newelem)
            ft_lstadd_back(&newlst, newelem);
        else
            ft_lstdelone(newelem, del);
            return (NULL);
        lst = lst->next;
    }
    return (newlst)
}
