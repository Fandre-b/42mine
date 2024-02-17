/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:47:59 by fandre-b          #+#    #+#             */
/*   Updated: 2024/02/17 20:47:59 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Bubble Sort
Selection Sort
Insertion Sort
Shell Sort
Merge Sort
Quick Sort
Heap Sort
Radix Sort

(sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).*/
//sacar 3 4 5 11

void	ft_swap(t_stack **stack)
{
	t_stack *first;
    t_stack *second;

    if (*stack && (*stack)->next)
    {
		//checks for existence of nodes in the stack
        first = *stack;
        second = (*stack)->next;
		if (second->next) //lida com 3th elem se existir
			second->next->prev = first;
		second->prev = first->prev;
		first->next = second->next;
		second->next = first;
		first->prev = second;
		*stack = second;
		second = first;
    }
	return ;
}

void	ft_push(t_stack **lst, t_stack *new)
{
	t_stack *first;

	if (*lst)
	{
		first = *lst;
		*lst = new;
		first->prev = new;
		new->next = first;
		if (first->prev)
			new->prev = first->prev;
		else
			new->prev = first;
	}
	else
		*lst = new;
	return ;
}

void    sa(t_stack **stack_a)
{
    ft_swap(stack_a);
	return ;
}

void    sb(t_stack **stack_b)
{
    ft_swap(stack_b);
	return ;
}

void    ss(t_stack **stack_a, t_stack **stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
	return ;
}

//////////////////////

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

void    pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_top(stack_a, stack_b);
	return ;
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_top(stack_a, stack_b);
	return ;
}

//////////////////////

void	ft_rotate(t_stack **stack)
{
	t_stack *first;
    t_stack *last;

	if (*stack && (*stack)->prev) // se apenas 2, entao temos simples swap
	{
		first = *stack;
		last = (*stack)->prev;
		*stack = first ->next; //update the header list
		first->next = last->next;
		last->next = first;
		first->prev = last;
	}
	return ;
}

void    ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	return ;
}

void    rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	return ;
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	return ;
}


////////////////////////

void	ft_rev_rotate(t_stack **stack)
{
	t_stack *first;
    t_stack *last;

	if (*stack && (*stack)->prev) // se apenas 2, entao temos simples swap
	{
		first = *stack;
		last = (*stack)->prev;
		*stack = last; //update the header list
		last->prev->next = last->next;
		last->next = first;
	}
	return ;
}

void    rra(t_stack **stack_a)
{
	ft_rev_rotate(stack_a);
	return ;
}

void    rrb(t_stack **stack_b)
{
	ft_rev_rotate(stack_b);
	return ;
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	return ;
}