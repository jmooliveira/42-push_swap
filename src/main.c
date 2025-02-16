/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:20:39 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/15 20:29:47 by jeff             ###   ########.fr       */
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
		ft_init_push_swap_strings(numbers); // ESTOU AQUI
		ft_free_split(numbers);
	}
	else if (ac > 2)
	{
		ft_validate_args(&av[1], ac);
		ft_init_push_swap_args(av[1]); // ESTOU AQUI
	}
	if (ac == 1)
		ft_errors(-10);
	ft_printf("\nTHAT'S ALL FOLKS!\n");
	return (EXIT_SUCCESS);
}
