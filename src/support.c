/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:50:55 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/13 19:06:12 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*SUPORT --------------------------------------------*/

#include "push_swap.h"

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
