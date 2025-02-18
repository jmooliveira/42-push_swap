/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:35 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/17 19:05:41 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* utils3.c */

#include "push_swap.h"

void	ft_rrr(t_push_swap *data)
{
	ft_rra(data);
	ft_rrb(data);
	ft_printf("rrr\n");
}

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d -> ", stack->value);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}
