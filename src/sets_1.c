/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:16:37 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/10 15:16:29 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_values(t_push_swap *data)
{
	ft_set_position_a(data);
	ft_set_position_b(data);
	ft_set_target(data);
	ft_set_price_a(data);
	ft_set_price_b(data);
	ft_set_cheap(data);
}

void	ft_set_cheap(t_push_swap *data)
{
	t_stack	*tmp_b;
	t_stack	*cheapest;
	long	minus;

	tmp_b = data->stack_b;
	minus = LONG_MAX;
	while (tmp_b)
	{
		if (tmp_b->price < minus)
		{
			minus = tmp_b->price;
			cheapest = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	cheapest->cheap = 1;
}

void	ft_set_target(t_push_swap *data)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*node_min;
	long	max;

	node_min = ft_node_min(data->stack_a);
	tmp_b = data->stack_b;
	while (tmp_b)
	{
		max = LONG_MAX;
		tmp_a = data->stack_a;
		while (tmp_a)
		{
			if (tmp_a->value > tmp_b->value && tmp_a->value < max)
			{
				tmp_b->target = tmp_a;
				max = tmp_a->value;
			}
			tmp_a = tmp_a->next;
		}
		if (max == LONG_MAX)
			tmp_b->target = node_min;
		tmp_b = tmp_b->next;
	}
}
