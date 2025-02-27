/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   until_five_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:52:36 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/27 14:45:30 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*until_five_numbers.c*/

#include "push_swap.h"

void	ft_three_numbers(t_push_swap *data)
{
	int	top;
	int	middle;
	int	botton;

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

	ft_printf("Tamanho da stack a em four_or_five_number entrada: %d\n", data->size_a);
	ft_printf("Tamanho da stack b em four_or_five_number entrada: %d\n", data->size_b);
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	min = ft_min(data->stack_a);
	next_min = ft_next_min(data->stack_a, min);
	while (data->size_a > 3)
	{
		if (data->stack_a->value == min || data->stack_a->value == next_min)
			ft_pb(data);
		else
			ft_ra(data);
	}
	ft_three_numbers(data);
	ft_pa(data); // GOHORSE
	ft_pa(data); // GOHORSE
	ft_printf("Tamanho da stack a em four or five number: %d\n", data->size_a);
	ft_printf("Tamanho da stack b em four or five number: %d\n", data->size_b);
	ft_printf("Aqui joga tudo de stack b para stack a desordenado\n");
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	/*
	*/
	//while (data->size_b > 0)
	//	ft_pa(data);
	//if (data->stack_a->value > data->stack_a->next->value)
	//	ft_sa(data);
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	//ft_printf("min: %d\n", min);
	//ft_printf("min_next: %d\n", next_min);
	ft_printf("Saiu sort 5num\n");
}

void	ft_until_five_numbers(t_push_swap *data)
{
	if (data->size_a == 2)
	{
		if (data->stack_a > data->stack_a->next)
			ft_sa(data);
	}
	else if (data->size_a == 3)
		ft_three_numbers(data);
	else
		ft_four_or_five_numbers(data);
}
