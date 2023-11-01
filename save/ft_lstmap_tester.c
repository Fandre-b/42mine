/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:35:43 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/24 12:38:28 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void *add_str(void *str)
{
    return (ft_strjoin((char *)str, ".txt"));
}

int main(void)
{
    t_list *lst;
    t_list *new_lst;

    lst = ft_lstnew(ft_strdup("One"));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Two")));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Three")));
    new_lst = ft_lstmap(lst, add_str, free);

    printf("Original List:\n");
    while (lst)
    {
        printf("%s\n", (char *)(lst->content));
        lst = lst->next;
    }

    printf("Modified List:\n");
    while (new_lst)
    {
        printf("%s\n", (char *)(new_lst->content));
        new_lst = new_lst->next;
    }

    ft_lstclear(&lst, free);
    ft_lstclear(&new_lst, free);

    return (0);
}
