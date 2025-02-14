/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:20:39 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/14 17:58:47 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**numbers;
	long	num;
	int		i;

	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		if (!numbers)
			ft_errors(-1);
		ft_validate(numbers);
		// push_swap
		ft_free_split(numbers);
	}
	else if (ac > 2)
	{
		i = 1;
		while (i < ac)
		{
			if (!ft_validate_number(av[i]))
				ft_errors(-2);
			num = ft_atoi(av[i]);
			if (num < INT_MIN || num > INT_MAX)
				ft_errors(-4);
			if (ft_duplicate_numbers(av + 1))
				ft_errors(-3);
			i++;
		}
		// push_swap
	}
	if (ac == 1)
		ft_errors(-10);
	return (EXIT_SUCCESS);
}
