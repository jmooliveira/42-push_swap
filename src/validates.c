/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:16:56 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/15 20:29:14 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*validates.c*/

#include "push_swap.h"

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
}

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

bool	ft_validate_args(char **av, int ac)
{
	int		i;
	long	num;

	i = 0;
	while(i < ac - 1)
	{
		if(!ft_validate_number(av[i]))
			ft_errors(-2);
		num = ft_atoi(av[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_errors(-4);
		i++;
	}
	if (ft_duplicate_numbers(av + 1)) // nao entendi o av + 1
		ft_errors(-3);
	return (true);
}