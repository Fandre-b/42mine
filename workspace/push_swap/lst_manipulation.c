#include "push_swap.h"
#include <stdlib.h>

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

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
} 					t_stack;

void	ft_swap(t_stack **stack)
{
	t_stack *first;
    t_stack *second;

    if (*stack_a && (*stack_a)->next)
    {
		//checks for existence of nodes in the stack
        first = *stack_a;
        second = (*stack_a)->next;
		if (second->next) //lida com 3th elem se existir
			second->next->prev = first;
		second->prev = first->prev;
		first->next = second->next;
		second->next = first;
		first->prev = second;
		*stack_a = second;
		second = first;
    }
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
	ft_push_top(stack_b, stack_b);
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

void    rra(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate(stack_a);
	return ;
}

void    rrb(t_stack **stack_a, t_stack **stack_b)
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