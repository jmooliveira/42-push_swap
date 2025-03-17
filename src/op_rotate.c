/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:39 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/10 15:08:13 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*op_rotate.c */

#include "push_swap.h"

void	ft_ra(t_push_swap *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (data->size_a < 2)
		return ;
	tmp = data->stack_a;
	data->stack_a = data->stack_a->next;
	data->stack_a->prev = NULL;
	last = ft_last_node(data->stack_a);
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	ft_printf("ra\n");
}

void	ft_rb(t_push_swap *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (data->size_b < 2)
		return ;
	tmp = data->stack_b;
	data->stack_b = data->stack_b->next;
	data->stack_b->prev = NULL;
	last = ft_last_node(data->stack_b);
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	ft_printf("rb\n");
}

void	ft_rr(t_push_swap *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (data->size_a < 2 || data->size_b < 2)
		return ;
	tmp = data->stack_a;
	data->stack_a = data->stack_a->next;
	data->stack_a->prev = NULL;
	last = ft_last_node(data->stack_a);
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	tmp = data->stack_b;
	data->stack_b = data->stack_b->next;
	data->stack_b->prev = NULL;
	last = ft_last_node(data->stack_b);
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	ft_printf("rr\n");
}
