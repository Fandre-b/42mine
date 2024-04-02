/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:18:44 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/05 17:58:17 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst-> next;
		count++;
	}
	return (count);
}
// #include <stdio.h>

// int main(void)
// {
//     t_list *list = ["Item 1","Item 2","Item 3","Item 4"];

//     int size = ft_lstsize(list);

//     printf("Size of the list: %d\n", size);

//     ft_lstclear(&list, free);

//     return 0;
// }
