/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:27:29 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/14 17:56:58 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	long	ascii_to_int;
	int		i;
	int		signal;

	if (!nptr)
		return (0);
	ascii_to_int = 0;
	i = 0;
	signal = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		ascii_to_int = ascii_to_int * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)ascii_to_int * signal);
}

// int	main(void)
// {
// 	char	*nbr = "2147483647";

// 	printf("%d\n", ft_atoi(nbr));
// 	printf("%d\n", atoi(nbr));
// }
