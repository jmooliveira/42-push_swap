/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:35 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/10 16:29:26 by jemorais         ###   ########.fr       */
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
	if (data->stack_b)
		data->stack_b->prev = NULL;
	tmp->next = data->stack_a;
	if (data->stack_a)
		data->stack_a->prev = tmp;
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
	if (data->stack_a)
		data->stack_a->prev = NULL;
	tmp->next = data->stack_b;
	if (data->stack_b)
		data->stack_b->prev = tmp;
	data->stack_b = tmp;
	data->size_b++;
	data->size_a--;
	ft_printf("pb\n");
}
