/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:39 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/04 13:00:41 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* utils2.c */

#include "push_swap.h"

void	ft_ra(t_push_swap *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (data->size_a < 2)
		return ;
	tmp = data-> stack_a;
	data->stack_a = data->stack_a->next;
	tmp->next = NULL;
	last = data->stack_a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	ft_printf("ra\n");
}

void	ft_rb(t_push_swap *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (data->size_b < 2)
		return ;
	tmp = data-> stack_b;
	data->stack_b = data->stack_b->next;
	tmp->next = NULL;
	last = data->stack_b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	ft_printf("rb\n");
}

void	ft_rr(t_push_swap *data)
{
	ft_ra(data);
	ft_rb(data);
	ft_printf("rr\n");
}
