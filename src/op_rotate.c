/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:39 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/06 01:14:30 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*op_rotate.c */

#include "push_swap.h"

void	ft_ra(t_push_swap *data)
{
	t_stack	*tmp;

	if (data->size_a < 2)
		return ;
	tmp = data-> stack_a;
	data->stack_a = data->stack_a->next;
	data->stack_a->prev = NULL;
	tmp->next = NULL;
	tmp->prev = data->stack_a->prev;
	data->stack_a->prev = tmp;
	ft_printf("ra\n");
}

void	ft_rb(t_push_swap *data)
{
	t_stack	*tmp;

	if (data->size_b < 2)
		return ;
	tmp = data-> stack_b;
	data->stack_b = data->stack_b->next;
	data->stack_b->prev = NULL;
	tmp->next = NULL;
	tmp->prev = data->stack_b->prev;
	data->stack_b->prev = tmp;
	ft_printf("rb\n");
}

void	ft_rr(t_push_swap *data)
{
	ft_ra(data);
	ft_rb(data);
	ft_printf("rr\n");
}
