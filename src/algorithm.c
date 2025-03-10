/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:01:54 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/10 17:05:21 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm(t_push_swap *data)
{
	t_stack	*best_cheap;

	ft_section_stack(data);
	ft_three_numbers(data);
	while (data->stack_b)
	{
		// ft_print_stack(data->stack_a);
		ft_set_values(data);
		best_cheap = ft_find_best_cheap(data);
		ft_rotate_both(data, best_cheap);
		ft_rotate_a(data, best_cheap);
		ft_rotate_b(data, best_cheap);
		// ft_printf("size_a: %d\n", data->size_a);
	}
}

void	ft_rotate_both(t_push_swap *data, t_stack *best_cheap)
{
	while (data->stack_a != best_cheap->target && data->stack_b != best_cheap)
	{
		if (best_cheap->target->upper == 1 && best_cheap->upper == 1)
			ft_rr(data);
		else if(best_cheap->target->upper == 0 && best_cheap->upper == 0)
			ft_rrr(data);
		else if ((best_cheap->target->upper == 0 && best_cheap->upper == 1) ||
				(best_cheap->target->upper == 1 && best_cheap->upper == 0))
			break ;
	}
}

void	ft_rotate_a(t_push_swap *data, t_stack *best_cheap)
{
	while (data->stack_a)
	{
		if (data->stack_a->value == best_cheap->target->value)
			break ;
		if (best_cheap->target->upper == 1)
			ft_ra(data);
		else
			ft_rra(data);
	}
}

void	ft_rotate_b(t_push_swap *data, t_stack *best_cheap)
{
	while (data->size_b != 0)
	{
		if (data->stack_b->cheap == 1)
		{
			ft_pa(data);
			break ;
		}
		if (best_cheap->upper == 1)
			ft_rb(data);
		else
			ft_rrb(data);
	}
}

t_stack	*ft_find_best_cheap(t_push_swap *data)
{
	t_stack	*best_cheap;

	best_cheap = data->stack_b;
	while (best_cheap)
	{
		if (best_cheap->cheap == 1)
			return (best_cheap);
		best_cheap = best_cheap->next;
	}
	return (NULL);
}
