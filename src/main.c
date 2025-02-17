/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:20:39 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/17 21:08:08 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*main.c*/

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**numbers;

	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		if (!numbers)
			ft_errors(-1);
		ft_validate_string(numbers);
		ft_init_push_swap_strings(numbers);
		// TRATAR PARA 1 NUMERO EM STR
		// TRATAR INT_MIN E INT_MAX
	}
	else if (ac > 2)
	{
		ft_validate_args(ac, &av[1]);
		ft_init_push_swap_args(&av[1], ac);
		// TRATAR PARA 1 NUMERO EM ARGS
		// TRATAR INT_MIN E INT_MAX
	}
	if (ac == 1)
		ft_errors(-10);
	ft_printf("\nTHAT'S ALL FOLKS!\n");
	return (EXIT_SUCCESS);
}
