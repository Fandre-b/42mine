/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:47:30 by fandre-b          #+#    #+#             */
/*   Updated: 2024/02/11 17:47:30 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
} 					t_stack;

void	ft_push_top(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*first;

	if(*stack_from)
	{
		first = *stack_from;
		if (first->next) //check se ha 2 elem
		{
			*stack_from = first->next;
			if (first->prev) //check se ha  mais que 2 elem
				first->next->prev = first->prev;
			else //aponta o prev, se for unico aponta null
				first->next->prev = NULL;
		}
		else
			*stack_from = NULL;
		ft_push(stack_to, first);
	}
	return ;
}

void	ft_rotate(t_stack **stack)
{
	t_stack *first;
    t_stack *last;

	if (*stack && (*stack)->prev) // se apenas 2, entao temos simples swap
	{
		first = *stack;
		last = (*stack)->prev;
		*stack = first ->next; //update the header list
        last->next = first;
        first->next = NULL;
	}
	return ;
}
/////////////////////////////////////////////

void in_order_traversal(t_stack **stack_a, t_stack *binary_tree)
{
    t_stack *stack_b;

    stack_b = NULL;
    if (!binary_tree || !stack_a)
        return;
    in_order_traversal(stack_a, binary_tree->next);  // começa pela arvore à direita (biggest value)
    //processamento de cada nó
    //poderia adicionar aqui uma forma de detectar posicao para rr ou rrr
    while(*stack_a && (*stack_a)->value != binary_tree->value)
        ft_rotate(stack_a);
    ft_push_top(stack_a, stack_b);
    in_order_traversal(stack_a, binary_tree->prev);  // visita arvore à esquerda
    return ;
}

//enquanto addiciono nos à BST faço push