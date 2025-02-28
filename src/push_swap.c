/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:18:47 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/28 18:00:51 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*push_swap.c*/

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

bool	ft_is_rev_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (true);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
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
		ft_printf("sorted\n"); // SAI
		return ;
	}
	else
		ft_printf("no sorted\n"); // SAI
	// ft_printf("data->size_a: %d\n", data->size_a); // APENAS VERIFICA O TAMANHO DA STACK_A
	if (data->size_a == 1)
		return ;
	else if (data->size_a <= 5)
		ft_until_five_numbers(data);
	else
	{
		ft_printf("quick sort\n");
		ft_quicksort(data);
	}
	// ft_finish_rotation(data); //// verificar no final
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
}
void	ft_finish_rotation(t_push_swap *data)
{
	int	min;
	int	pos_min;
	t_stack		*nav;

	min = INT_MAX;
	pos_min = 0;
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
