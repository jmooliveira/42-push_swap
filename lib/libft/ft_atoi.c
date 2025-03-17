/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:27:29 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/10 10:52:16 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_atoi(const char *nptr)
{
	long	ascii_to_int;
	int		i;
	int		signal;

	if (!nptr)
		return (0);
	ascii_to_int = 0;
	i = 0;
	signal = 1;
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t'
			|| nptr[i] == '\n' || nptr[i] == '\r'
			|| nptr[i] <= '\v' || nptr[i] <= '\f'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ascii_to_int = ascii_to_int * 10 + (nptr[i] - '0');
		i++;
	}
	return (ascii_to_int * signal);
}

// int	main(void)
// {
// 	char	*nbr = "2147483647";

// 	printf("%d\n", ft_atoi(nbr));
// 	printf("%d\n", atoi(nbr));
// }
