/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:01:54 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/06 20:55:54 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm(t_push_swap *data)
{
	ft_section_stack(data);
	ft_three_numbers(data);
	ft_set_position_a(data);
	ft_set_position_b(data);
	ft_set_target(data->stack_b);

	ft_printf("size_a: %d\n", data->size_a);
	ft_printf("A -");
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	ft_print_position(data->stack_a);
	ft_print_upper(data->stack_a);
	ft_printf("size_b: %d\n", data->size_b);
	ft_printf("B -");
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_position(data->stack_b);
	ft_print_upper(data->stack_b);
}

void	ft_section_stack(t_push_swap *data)
{
	while (data->size_a > 3)
		ft_pb(data);
}

void	ft_set_position_a(t_push_swap *data)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = data->stack_a;
	while (tmp)
	{
		tmp->position = i;
		if (i < (data->size_a / 2))
			tmp->upper = 1;
		else
			tmp->upper = 0;
		tmp = tmp->next;
		i++;
	}
}

void	ft_set_position_b(t_push_swap *data)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = data->stack_b;
	while (tmp)
	{
		tmp->position = i;
		if (i < (data->size_b / 2))
			tmp->upper = 1;
		else
			tmp->upper = 0;
		tmp = tmp->next;
		i++;
	}
}

void	ft_set_target(t_stack *stack_b)
{

}
