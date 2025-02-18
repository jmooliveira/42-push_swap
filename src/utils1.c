/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:44 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/17 19:06:32 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* utils1.c */

#include "push_swap.h"

void	ft_sa(t_push_swap *data)
{
	t_stack	*tmp;

	if (data->size_a < 2)
		return ;
	tmp = data->stack_a->next;
	data->stack_a->next = tmp->next;
	tmp->next = data->stack_a;
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

void	ft_ss(t_push_swap *data)
{
	ft_sa(data);
	ft_sb(data);
	ft_printf("ss\n");
}

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
