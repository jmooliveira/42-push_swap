/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:18:47 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/18 17:40:15 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (true);
	tmp = stack;
	while(tmp->next)
	{
		if(tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

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
	else if(top < middle && middle > botton && botton < top)
		ft_rra(data);
	else if(top > middle && middle < botton && botton < top)
		ft_ra(data);
	else if(top < middle && middle > botton && botton > top)
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
	while(tmp)
	{
		if(next_min_value > tmp->value && tmp->value > min)
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
	while(tmp)
	{
		if(min_value > tmp->value)
			min_value = tmp->value;
		tmp = tmp->next;
	}
	return (min_value);
}

void	ft_four_or_five_numbers(t_push_swap *data)
{
	int	min;
	int next_min;

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
	while (data->size_b > 0)
		ft_pa(data);
	if (data->stack_a->value > data->stack_a->next->value)
		ft_sa(data);
	ft_printf("min: %d\n", min);
	ft_printf("min_next: %d\n", next_min);
}

void	ft_until_five_numbers(t_push_swap *data)
{
	if (data->size_a == 2)
	{
		if(data->stack_a > data->stack_a->next)
			ft_sa(data);
	}
	else if (data->size_a == 3)
		ft_three_numbers(data);
	else
		ft_four_or_five_numbers(data);
}

void	ft_push_swap(t_push_swap *data)
{
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// DEVEM SAIR

	if (ft_is_sorted(data->stack_a))
	{
		ft_printf("sorted\n");
		return ;
	}
	else
		ft_printf("no sorted\n");
	ft_printf("data->size_a: %d\n", data->size_a); // APENAS VERIFICANDO O TAMANHO DA STACK_A
	if(data->size_a == 1)
		return ;
	else if(data->size_a <= 5)
		ft_until_five_numbers(data);
	else
		ft_printf("merge ou quick sort\n");

	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
}

	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_pb(data); // TESTE
	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B

	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_pb(data); // TESTE
	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_pb(data);
	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_pb(data);
	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_ra(data);
	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_rb(data);
	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_rr(data);
	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_rra(data);
	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_rrb(data);
	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_rrr(data);
	// ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	// ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	// ft_sa(data);
	// ft_print_stack(data->stack_a);
	// ft_print_stack(data->stack_b);
	// ft_sb(data);
	// ft_print_stack(data->stack_a);
	// ft_print_stack(data->stack_b);
	// ft_ss(data);
	// ft_print_stack(data->stack_a);
	// ft_print_stack(data->stack_b);
