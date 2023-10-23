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
    t_list  *new_lst;
    t_list  *new_elem;

    while(lst)
    {
        new_elem = ft_lstnew(lst->content);
        ft_lstiter(new_elem, void (*f)(void *))
        if (new_elem)
            ft_lstadd_back(&new_lst, new_elem);
        else
            ft_lstdelone(new_elem, del);
            return (NULL);
        lst = lst->next;
    }
    return (new_lst)
}

int main(void)
{
    t_list *lst;
    t_list *new_lst ,

    lst = ft_lstnew(ft_strdup("1"));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("2")));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("3")));
    ft_lstmap(lst, add_one, del);

    printf("Original List:\n");
    while (lst)
    {
        printf("%s\n", (char *)(lst->content));
        lst = lst->next;
    }

    printf("\nModified List (added 1 to each element):\n");
    while (new_lst)
    {
        printf("%d\n", *((int *)(new_lst->content)));
        new_lst = new_lst->next;
    }

    ft_lstclear(&lst, del);
    ft_lstclear(&new_lst, del);

    return (0);
}
