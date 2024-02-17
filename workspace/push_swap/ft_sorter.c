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

#include "push_swap.h"

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
    ft_push_top(stack_a, &stack_b);
    in_order_traversal(stack_a, binary_tree->prev);  // visita arvore à esquerda
    return ;
}

//enquanto addiciono nos à BST faço push