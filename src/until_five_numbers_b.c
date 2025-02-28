/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   until_five_numbers_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:52:36 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/28 19:07:16 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*until_five_numbers.c*/

#include "push_swap.h"

void	ft_three_numbers_b(t_push_swap *data)
{
	int	top;
	int	middle;
	int	botton;

	ft_printf("Entrou three_numbers_b\n");
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	top = data->stack_b->value;
	middle = data->stack_b->next->value;
	botton = data->stack_b->next->next->value;
	if (top > middle && middle < botton && botton < top)
	{
		ft_rrb(data);
		ft_sb(data);
	}
	else if (top < middle && middle > botton && botton < top)
		ft_sb(data);
	else if (top > middle && middle < botton && botton > top)
		ft_rrb(data);
	else if (top < middle && middle < botton && botton > top)
	{
		ft_rb(data);
		ft_sb(data);
	}
	else if (top < middle && middle > botton && botton > top)
		ft_rb(data);
	ft_printf("saida three_numbers_b\n");
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
}
int	ft_second_max(t_stack *stack, int max)
{
	int		next_max_value;
	t_stack	*tmp;

	tmp = stack;
	next_max_value = INT_MIN;
	while (tmp)
	{
		if (next_max_value < tmp->value && tmp->value < max)
			next_max_value = tmp->value;
		tmp = tmp->next;
	}
	return (next_max_value);
}

int	ft_max(t_stack *stack)
{
	int		max_value;
	t_stack	*tmp;

	tmp = stack;
	max_value = stack->value;
	while (tmp)
	{
		if (max_value < tmp->value)
			max_value = tmp->value;
		tmp = tmp->next;
	}
	return (max_value);
}

void	ft_four_or_five_numbers_b(t_push_swap *data)
{
	int	max;
	int	next_max;
	int	flag_max_send;

	// ft_printf("Tamanho da stack a em four_or_five_number_b entrada: %d\n", data->size_a);
	// ft_printf("Tamanho da stack b em four_or_five_number_b entrada: %d\n", data->size_b);
	flag_max_send = 0;
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	max = ft_max(data->stack_b);
	next_max = ft_next_min(data->stack_b, max);
	while (data->size_b > 3)
	{
		if (data->stack_b->value == max)
		{
			ft_pa(data);
			flag_max_send = 1;
		}
		else if(data->stack_b->value == next_max && flag_max_send == 1)
			ft_pa(data);
		// else
		// 	ft_rb(data);
	}
	ft_three_numbers_b(data);

	// ft_ra(data); // GOHORSE
	// ft_ra(data); // GOHORSE
	// ft_printf("Tamanho da stack a em four or five number_b: %d\n", data->size_a);
	// ft_printf("Tamanho da stack b em four or five number_b: %d\n", data->size_b);
	// ft_printf("Aqui joga tudo de stack a para stack b desordenado\n");
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
	// ft_printf("Saiu sort_b num\n");
}

void	ft_until_five_numbers_b(t_push_swap *data)
{
	ft_printf("entrou em until_five_numbers_b \n");
	if (data->size_b == 2)
	{
		if (data->stack_b > data->stack_b->next)
			ft_sb(data);
	}
	else if (data->size_b == 3)
		ft_three_numbers_b(data);
	else
		ft_four_or_five_numbers_b(data);
}
