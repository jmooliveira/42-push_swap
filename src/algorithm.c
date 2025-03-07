/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:01:54 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/07 19:20:06 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm(t_push_swap *data)
{
	ft_section_stack(data);
	ft_three_numbers(data);
	ft_set_position_a(data);
	ft_set_position_b(data);
	ft_set_target(data);
	ft_price_a(data);
	ft_price_b(data);
	ft_cheap(data);

	ft_printf("size_a: %d\n", data->size_a);
	ft_printf("A -");
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	ft_print_position(data->stack_a);
	ft_print_upper(data->stack_a);
	ft_print_price(data->stack_a);

	ft_printf("size_b: %d\n", data->size_b);
	ft_printf("B -");
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_position(data->stack_b);
	ft_print_upper(data->stack_b);
	ft_print_target(data->stack_b);
	ft_print_price(data->stack_b);
	ft_print_price_target(data->stack_b);
	ft_print_cheap(data->stack_b);
}

void	ft_cheap(t_push_swap *data)
{
	t_stack	*tmp_b;
	t_stack	*cheapest;
	int		minus;

	tmp_b = data->stack_b;
	minus = INT_MAX;
	while (tmp_b)
	{
		if (tmp_b->price < minus)
		{
			minus = tmp_b->price;
			cheapest = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	cheapest->cheap = 1;
}

void	ft_price_a(t_push_swap *data)
{
	t_stack	*tmp;
	int		i;

	tmp = data->stack_a;
	i = 0;
	while (tmp)
	{
		if (tmp->upper == 1)
		{
			tmp->price = i;
			i++;
		}
		if (tmp->upper == 0)
		{
			i--;
			tmp->price = i;
		}
		tmp = tmp->next;
	}
}

void	ft_price_b(t_push_swap *data)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = data->stack_b;
	while (tmp)
	{
		if (tmp->upper == 1)
		{
			tmp->price = i + tmp->target->price;
			i++;
		}
		if (tmp->upper == 0)
		{
			i--;
			tmp->price = i + tmp->target->price;
		}
		tmp = tmp->next;
	}
}

void	ft_section_stack(t_push_swap *data)
{
	while (data->size_a > 3)
		ft_pb(data);
}

void	ft_set_position_a(t_push_swap *data)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = data->stack_a;
	while (tmp)
	{
		tmp->position = i;
		if (i < (data->size_a / 2 + 1))
			tmp->upper = 1;
		else
			tmp->upper = 0;
		tmp = tmp->next;
		i++;
	}
}

void	ft_set_position_b(t_push_swap *data)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = data->stack_b;
	while (tmp)
	{
		tmp->position = i;
		if (i < (data->size_b / 2 + 1))
			tmp->upper = 1;
		else
			tmp->upper = 0;
		tmp = tmp->next;
		i++;
	}
}

void	ft_set_target(t_push_swap *data)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*node_min;
	long	max;

	node_min = ft_node_min(data->stack_a);
	tmp_b = data->stack_b;
	while (tmp_b)
	{
		max = LONG_MAX;
		tmp_a = data->stack_a;
		while (tmp_a)
		{
			if (tmp_a->value > tmp_b->value && tmp_a->value < max)
			{
				tmp_b->target = tmp_a;
				max = tmp_a->value;
			}
			tmp_a = tmp_a->next;
		}
		if (max == LONG_MAX)
			tmp_b->target = node_min;
		tmp_b = tmp_b->next;
	}
}

t_stack	*ft_node_min(t_stack *stack)
{
	long		node_value;
	t_stack		*tmp;
	t_stack		*min_node;

	tmp = stack;
	node_value = LONG_MAX;
	while (tmp)
	{
		if (node_value > tmp->value)
		{
			min_node = tmp;
			node_value = tmp->value;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

// int	ft_max(t_stack *stack)
// {
// 	int		max_value;
// 	t_stack	*tmp;

// 	tmp = stack;
// 	max_value = stack->value;
// 	while (tmp)
// 	{
// 		if (max_value < tmp->value)
// 			max_value = tmp->value;
// 		tmp = tmp->next;
// 	}
// 	return (max_value);
// }
