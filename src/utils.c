/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:36:09 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/10 10:31:21 by jemorais         ###   ########.fr       */
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

void	ft_finish_rotation(t_push_swap *data)
{
	int	min;
	t_stack		*nav;

	min = INT_MAX;
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

t_stack	*ft_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*SUPORT --------------------------------------------*/

void	ft_print_stack(t_stack *stack)
{
	ft_printf("Stack: ");
	while (stack)
	{
		ft_printf("%d -> ", stack->value);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}

void	ft_print_position(t_stack *stack)
{
	ft_printf("Position: ");
	while (stack)
	{
		ft_printf("%d -> ", stack->position);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}

void	ft_print_upper(t_stack *stack)
{
	ft_printf("Upper   : ");
	while (stack)
	{
		ft_printf("%d -> ", stack->upper);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}

void	ft_print_target(t_stack *stack)
{
	ft_printf("Target  : ");
	while (stack)
	{
		ft_printf("%d -> ", stack->target->value);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}

void	ft_print_price_target(t_stack *stack)
{
	ft_printf("Prc_tgt : ");
	while (stack)
	{
		ft_printf("%d -> ", stack->target->price);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}

void	ft_print_price(t_stack *stack)
{
	ft_printf("Price   : ");
	while (stack)
	{
		ft_printf("%d -> ", stack->price);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}

void	ft_print_cheap(t_stack *stack)
{
	ft_printf("Set_chp : ");
	while (stack)
	{
		ft_printf("%d -> ", stack->cheap);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}
