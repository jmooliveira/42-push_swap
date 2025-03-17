/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:18:47 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/13 19:23:54 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*push_swap.c*/

#include "push_swap.h"

void	ft_push_swap(t_push_swap *data)
{
	if (ft_is_sorted(data->stack_a))
		return ;
	if (data->size_a == 1)
		return ;
	else if (data->size_a <= 5)
		ft_until_five_numbers(data);
	else
		ft_algorithm(data);
	ft_finish_rotation(data);
}
