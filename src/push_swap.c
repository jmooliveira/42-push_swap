/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:18:47 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/10 16:54:57 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*push_swap.c*/

#include "push_swap.h"

void	ft_push_swap(t_push_swap *data)
{
	// ft_printf("Stack_A entrada:\n");
	// ft_printf("size_a: %d\n", data->size_a);
	// ft_print_stack(data->stack_a);
	// ft_print_stack(data->stack_b);

	if (ft_is_sorted(data->stack_a))
		return ;
	if (data->size_a == 1)
		return ;
	else if (data->size_a <= 5)
		ft_until_five_numbers(data);
	else
		ft_algorithm(data);
	ft_finish_rotation(data);

	// ft_printf("Stack_A saída:\n");
	// ft_printf("size_a: %d\n", data->size_a);
	// ft_print_stack(data->stack_a);
	// ft_print_stack(data->stack_b);
}
