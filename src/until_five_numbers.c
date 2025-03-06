/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   until_five_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:52:36 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/06 01:11:24 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*until_five_numbers.c*/

#include "push_swap.h"

void	ft_three_numbers(t_push_swap *data)
{
	int	top;
	int	middle;
	int	botton;

	ft_printf("Entrou three_numbers_a\n");
	top = data->stack_a->value;
	middle = data->stack_a->next->value;
	botton = data->stack_a->next->next->value;
	if (top > middle && middle > botton && botton < top)
	{
		ft_ra(data);
		ft_sa(data);
	}
	else if (top < middle && middle > botton && botton < top)
		ft_rra(data);
	else if (top > middle && middle < botton && botton < top)
		ft_ra(data);
	else if (top < middle && middle > botton && botton > top)
	{
		ft_rra(data);
		ft_sa(data);
	}
	else if (top > middle && middle < botton && botton > top)
		ft_sa(data);
}

int	ft_next_min(t_stack *stack, int min)
{
	int		next_min_value;
	t_stack	*tmp;

	tmp = stack;
	next_min_value = INT_MAX;
	while (tmp)
	{
		if (next_min_value > tmp->value && tmp->value > min)
			next_min_value = tmp->value;
		tmp = tmp->next;
	}
	return (next_min_value);
}

int	ft_min(t_stack *stack)
{
	int		min_value;
	t_stack	*tmp;

	tmp = stack;
	min_value = stack->value;
	while (tmp)
	{
		if (min_value > tmp->value)
			min_value = tmp->value;
		tmp = tmp->next;
	}
	return (min_value);
}

void	ft_four_or_five_numbers(t_push_swap *data)
{
	int	min;
	int	next_min;
	int	flag_min_send;

	flag_min_send = 0;
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	min = ft_min(data->stack_a);
	next_min = ft_next_min(data->stack_a, min);
	while (data->size_a > 3)
	{
		if (data->stack_a->value == min)
		{
			ft_pb(data);
			flag_min_send= 1;
		}
		else if (data->stack_a->value == next_min && flag_min_send == 1)
			ft_pb(data);
		else
			ft_ra(data);
	}
	ft_three_numbers(data);
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
}

void	ft_until_five_numbers(t_push_swap *data)
{
	if (data->size_a == 2)
	{
		puts("entrou");
		if (data->stack_a > data->stack_a->next)
			ft_sa(data);
	}
	else if (data->size_a == 3)
		ft_three_numbers(data);
	else
		ft_four_or_five_numbers(data);
}
