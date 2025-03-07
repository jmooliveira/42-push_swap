/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:16:56 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/07 19:40:05 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*validates.c*/

#include "push_swap.h"

bool	ft_validate_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_duplicate_numbers(char **numbers)
{
	int	i;
	int	j;


	ft_printf("//////////////////------///////////////////"); /////////
	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_atoi(numbers[i]) == ft_atoi(numbers[j]))
			return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	ft_validate_args(int ac, char **av)
{
	int		i;

	i = 0;
	while (i < ac - 1)
	{
		if (!ft_validate_number(av[i]))
			ft_error();
		i++;
	}
	if (ft_duplicate_numbers(av + 1))
	{
	ft_printf("/////////////////////////////////////"); /////////
		ft_error();

	}
	return (true);
	// VALIDATE INT_MAX AND INT_MIN
}

void	ft_validate_string(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (!ft_validate_number(numbers[i]))
		{
			ft_free_split(numbers);
			ft_error();
		}
		i++;
	}
	if (ft_duplicate_numbers(numbers))
	{
		ft_printf("////////////////////ttttttttttttt/////////////////////"); /////////
		ft_free_split(numbers);
		ft_error();
	}
	// VALIDATE INT_MAX AND INT_MIN
}
