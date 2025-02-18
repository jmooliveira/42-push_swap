/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:52 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/18 16:13:28 by jemorais         ###   ########.fr       */
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
	data->len_stack = 0;
	return (data);
}

void	add_data_to_stack(t_push_swap *data, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = data->stack_a;
	data->stack_a = new_node;
	data->size_a++;
	data->len_stack++;
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
	ft_push_swap(data); // ---------ESTOU AQUI----------
	ft_stack_free(&data->stack_a);
	ft_stack_free(&data->stack_b);
	free(data);
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
	ft_push_swap(data); // ---------ESTOU AQUI----------
	ft_stack_free(&data->stack_a);
	ft_stack_free(&data->stack_b);
	free(data);
}
