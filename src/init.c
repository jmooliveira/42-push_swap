/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:52 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/06 00:34:11 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* init.c */

#include "push_swap.h"

t_push_swap	*ft_init(void)
{
	t_push_swap	*data;

	data = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!data)
		return (NULL);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	return (data);
}

void	add_data_to_stack(t_push_swap *data, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!data->stack_a)
		data->stack_a = new_node;
	else
	{
		last = data->stack_a;
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
	data->size_a++;
}


void	ft_init_push_swap_args(char **av, int ac)
{
	t_push_swap	*data;
	int			i;

	data = ft_init();
	if (!data)
		ft_errors(-11);
	i = 0;
	while (i < ac - 1)
	{
		add_data_to_stack(data, ft_atoi(av[i]));
		i++;
	}
	ft_push_swap(data);
	ft_stack_free(&data->stack_a);
	ft_stack_free(&data->stack_b);
	free(data);
	// VALIDATE INT_MAX AND INT_MIN
}

void	ft_init_push_swap_strings(char **numbers)
{
	t_push_swap	*data;
	int			i;

	data = ft_init();
	if (!data)
	{
		ft_free_split(numbers);
		ft_errors(-11);
	}
	i = 0;
	while (numbers[i])
	{
		add_data_to_stack(data, ft_atoi(numbers[i]));
		i++;
	}
	ft_free_split(numbers);
	ft_push_swap(data);
	ft_stack_free(&data->stack_a);
	ft_stack_free(&data->stack_b);
	free(data);
	// VALIDATE INT_MAX AND INT_MIN
}
