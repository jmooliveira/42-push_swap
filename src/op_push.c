/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:35 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/04 13:01:24 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*op_push.c */

#include "push_swap.h"

void	ft_pa(t_push_swap *data)
{
	t_stack	*tmp;

	if (data->size_b == 0)
		return ;
	tmp = data->stack_b;
	data->stack_b = data->stack_b->next;
	tmp->next = data->stack_a;
	data->stack_a = tmp;
	data->size_a++;
	data->size_b--;
	ft_printf("pa\n");
}

void	ft_pb(t_push_swap *data)
{
	t_stack	*tmp;

	if (data->size_a == 0)
		return ;
	tmp = data->stack_a;
	data->stack_a = data->stack_a->next;
	tmp->next = data->stack_b;
	data->stack_b = tmp;
	data->size_b++;
	data->size_a--;
	ft_printf("pb\n");
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
