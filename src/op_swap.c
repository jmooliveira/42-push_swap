/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:44 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/17 09:49:36 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*op_swap.c */

#include "push_swap.h"

void	ft_sa(t_push_swap *data)
{
	t_stack	*tmp;

	if (data->size_a < 2)
		return ;
	tmp = data->stack_a->next;
	data->stack_a->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = data->stack_a;
	tmp->prev = NULL;
	tmp->next = data->stack_a;
	data->stack_a->prev = tmp;
	data->stack_a = tmp;
	ft_printf("sa\n");
}

void	ft_sb(t_push_swap *data)
{
	t_stack	*tmp;

	if (data->size_b < 2)
		return ;
	tmp = data->stack_b->next;
	data->stack_b->next = tmp->next;
	tmp->next = data->stack_b;
	data->stack_b = tmp;
	ft_printf("sb\n");
}
