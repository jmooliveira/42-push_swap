/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:33:49 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/14 17:20:27 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_errors(int error)
{
	if (error == -1)
		ft_putstr_fd("Error: Memory split allocation failed\n", STDERR_FILENO);
	if (error == -2)
		ft_putstr_fd("Error: Number invalid\n", STDERR_FILENO);
	if (error == -3)
		ft_putstr_fd("Error: Number duplicated\n", STDERR_FILENO);
	if (error == -4)
		ft_putstr_fd("Error: Number 'put nbr' out of range\n", STDERR_FILENO);
	if (error == -10)
		ft_putstr_fd("Few Args\n ./push_swap <arguments>\n", STDERR_FILENO);
	exit(2);
}
