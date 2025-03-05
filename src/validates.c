/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:16:56 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/05 20:09:50 by jeff             ###   ########.fr       */
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
			ft_errors(-2);
		i++;
	}
	if (ft_duplicate_numbers(av + 1))
		ft_errors(-3);
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
			ft_errors(-2);
		}
		i++;
	}
	if (ft_duplicate_numbers(numbers))
	{
		ft_free_split(numbers);
		ft_errors(-3);
	}
	// VALIDATE INT_MAX AND INT_MIN
}