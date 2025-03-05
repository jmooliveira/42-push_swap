/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:18:47 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/05 19:56:43 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*push_swap.c*/

#include "push_swap.h"

		void	ft_push_swap(t_push_swap *data)
		{
			ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
			ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
			if (ft_is_sorted(data->stack_a))
			{
				ft_printf("sorted\n"); // SAI
				return ;
			}
			else
				ft_printf("no sorted\n"); // SAI
			// ft_printf("data->size_a: %d\n", data->size_a); // APENAS VERIFICA O TAMANHO DA STACK_A
			if (data->size_a == 1)
				return ;
			else if (data->size_a <= 5)
				ft_until_five_numbers_a(data);
			else
			{
				ft_printf("algorithm\n");
				//ft_algorithm(data);
			}
			// ft_finish_rotation(data); //// verificar no final
			ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
			ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
		}
		