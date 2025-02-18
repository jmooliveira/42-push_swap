/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:18:47 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/18 17:53:45 by jemorais         ###   ########.fr       */
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

void	ft_push_swap(t_push_swap *data)
{
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	if (ft_is_sorted(data->stack_a))
	{
		ft_printf("sorted\n");
		return ;
	}
	else
		ft_printf("no sorted\n"); // SAI
	ft_printf("data->size_a: %d\n", data->size_a); // APENAS VERIFICANDO O TAMANHO DA STACK_A
	if (data->size_a == 1)
		return ;
	else if (data->size_a <= 5)
		ft_until_five_numbers(data);
	else
		ft_printf("merge ou quick sort\n");
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
}
