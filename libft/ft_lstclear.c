/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:25:53 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/23 17:26:37 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!del || !lst)
    		return ;
	temp = *lst;
	while(*lst)
    {
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
    }
}
/*
int	main()
{
	//Esta versao esta errada porque adiciono identa;ao extra
	//na verdade eh uma linked list de uma linked list
	t_list	*node;
	t_list  **lst;
	
	lst = (t_list **)malloc(sizeof(t_list *));
	if (!lst)
		return 1;
	*lst = ft_lstnew(ft_strdup("Hello,"));
	ft_lstadd_back(lst, ft_lstnew(ft_strdup(" World!")));
	node = *lst;
	while (node)
	{
		printf("node conteudo - %s\n", (char *)node->content);
		printf("Edr conteudo - %p\n", node->content);
		printf("Edr node - %p\n", node);
		node = node->next;
	}
	//printf("%s\n", (char *)node->content);
	printf("Edr null node - %p\n", node);
	ft_lstclear(lst, free);
	//free (lst);
}*/

int	main()
{
	t_list	*head;
	
	head = ft_lstnew(ft_strdup("Hello,"));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup(" World!")));
	t_list *node = head;
	while (node)
	{
		printf("node content - %s\n", (char *)node->content);
		printf("Addr content - %p\n", node->content);
		printf("Addr node - %p\n", node);
		node = node->next;
	}
	printf("Edr null node - %p\n", node);

	ft_lstclear(&head, free);
}