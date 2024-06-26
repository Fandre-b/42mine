/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:58:04 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 22:58:04 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_stack **stack_a)
{
	int	burn_variable;

	if (!*stack_a)
		return ;
	while (!ft_issorted(*stack_a, &burn_variable))
	{
		if ((*stack_a)->value > (*stack_a)->prev->value)
			ra(stack_a, 1, 1);
		else if ((*stack_a)->next->value > (*stack_a)->prev->value)
			rra(stack_a, 1, 1);
		else if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a, 1, 1);
	}
	return ;
}

void	ft_getstack_info(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	int		index_a;
	int		index_b;
	t_stack	*temp;

	index_b = 0;
	temp = *stack_b;
	while (temp)
	{
		temp->target = ft_getstack_index(*stack_a, temp->value);
		index_a = temp->target;
		if (index_a <= (a) / 2)
			temp->rot[0] = index_a;
		else if (index_a > (a) / 2)
			temp->rot[0] = -(a - index_a);
		if (index_b <= b / 2)
			temp->rot[1] = index_b;
		else if (index_b > b / 2)
			temp->rot[1] = -(b - index_b);
		temp = temp->next;
		index_b++;
	}
	return ;
}

void	ft_getnode_cheapest(t_stack *stack, int **rotator)
{
	int		temp_val;
	int		*rot;
	int		total_rot;
	t_stack	*temp;

	total_rot = 2147483647;
	temp = stack;
	while (temp)
	{
		rot = temp->rot;
		if (ft_abs(rot[0] - rot[1]) < ft_abs(rot[0]) + ft_abs(rot[1]))
			temp_val = ft_max(ft_abs(rot[0]), ft_abs(rot[1]));
		else
			temp_val = ft_abs(rot[0]) + ft_abs(rot[1]);
		if (temp_val < total_rot)
		{
			total_rot = temp_val;
			*rotator = rot;
		}
		temp = temp->next;
	}
	return ;
}

void	ft_push_prep(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	int		rr_mov;
	int		rrr_mov;

	rr_mov = 0;
	rrr_mov = 0;
	if (a > 0 && b > 0)
		rr_mov = ft_min(a, b);
	else if (a < 0 && b < 0)
		rrr_mov = ft_max(a, b);
	if (a > rr_mov)
		ra(stack_a, (a - rr_mov), 1);
	else if (a < rrr_mov)
		rra(stack_a, -(a - rrr_mov), 1);
	if (b > rr_mov)
		rb(stack_b, (b - rr_mov), 1);
	else if (b < rrr_mov)
		rrb(stack_b, -(b - rrr_mov), 1);
	rr(stack_a, stack_b, ft_abs(rr_mov), 1);
	rrr(stack_a, stack_b, ft_abs(rrr_mov), 1);
	return ;
}

void	ft_sorter_push3(t_stack **stack_a)
{
	int		size_a;
	int		*rotator;
	int		size_b;
	t_stack	*stack_b;

	size_a = ft_getstack_size(*stack_a);
	stack_b = NULL;
	if (size_a > 3)
		pb(stack_a, &stack_b, size_a - 3, 1);
	ft_sort3(stack_a);
	size_b = ft_getstack_size(stack_b);
	while (stack_b)
	{
		ft_getstack_info(stack_a, &stack_b, size_a - size_b, size_b);
		ft_getnode_cheapest(stack_b, &rotator);
		ft_push_prep(stack_a, &stack_b, rotator[0], rotator[1]);
		pa(stack_a, &stack_b, 1, 1);
		size_b--;
	}
	if (!ft_issorted(*stack_a, &size_b) && size_b <= size_a / 2)
		ra(stack_a, size_b + 1, 1);
	else
		rra(stack_a, size_a - size_b - 1, 1);
	return ;
	ft_lstdel(stack_b);
}
