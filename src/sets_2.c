/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:16:34 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/10 15:16:50 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_position_a(t_push_swap *data)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = data->stack_a;
	while (tmp)
	{
		tmp->position = i;
		if (i < (data->size_a / 2 + 1))
			tmp->upper = 1;
		else
			tmp->upper = 0;
		tmp = tmp->next;
		i++;
	}
}

void	ft_set_position_b(t_push_swap *data)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = data->stack_b;
	while (tmp)
	{
		tmp->position = i;
		if (i < (data->size_b / 2 + 1))
			tmp->upper = 1;
		else
			tmp->upper = 0;
		tmp = tmp->next;
		i++;
	}
}

void	ft_set_price_a(t_push_swap *data)
{
	t_stack	*tmp;
	int		i;

	tmp = data->stack_a;
	i = 0;
	while (tmp)
	{
		if (tmp->upper == 1)
		{
			tmp->price = i;
			i++;
		}
		if (tmp->upper == 0)
		{
			i--;
			tmp->price = i;
		}
		tmp = tmp->next;
	}
}

void	ft_set_price_b(t_push_swap *data)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = data->stack_b;
	while (tmp)
	{
		if (tmp->upper == 1)
		{
			tmp->price = i + tmp->target->price;
			i++;
		}
		if (tmp->upper == 0)
		{
			i--;
			tmp->price = i + tmp->target->price;
		}
		tmp = tmp->next;
	}
}
