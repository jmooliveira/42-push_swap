/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:36:09 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/10 15:10:47 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (true);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	ft_finish_rotation(t_push_swap *data)
{
	int		min;
	t_stack	*nav;

	min = INT_MAX;
	nav = data->stack_a;
	while (nav)
	{
		if (nav->value < min)
			min = nav->value;
		nav = nav->next;
	}
	while (data->stack_a->value != min)
	{
		ft_ra(data);
	}
}

t_stack	*ft_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_section_stack(t_push_swap *data)
{
	while (data->size_a > 3)
		ft_pb(data);
}

t_stack	*ft_node_min(t_stack *stack)
{
	long		node_value;
	t_stack		*tmp;
	t_stack		*min_node;

	tmp = stack;
	node_value = LONG_MAX;
	while (tmp)
	{
		if (tmp->value < node_value)
		{
			min_node = tmp;
			node_value = tmp->value;
		}
		tmp = tmp->next;
	}
	return (min_node);
}
