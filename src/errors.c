/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:33:49 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/17 14:59:14 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*errors.c*/

#include "push_swap.h"

int	ft_errors(int error)
{
	if (error == -1)
		ft_putstr_fd("Error: Memory split allocation failed\n", STDERR_FILENO);
	else if (error == -2)
		ft_putstr_fd("Error: Invalid Number\n", STDERR_FILENO);
	else if (error == -3)
		ft_putstr_fd("Error: Duplicated number\n", STDERR_FILENO);
	else if (error == -4)
		ft_putstr_fd("Error: Number out of range\n", STDERR_FILENO);
	else if (error == -10)
		ft_putstr_fd("Few Args\n ./push_swap <arguments>\n", STDERR_FILENO);
	else
		ft_putstr_fd("Error: Unexpected error\n", STDERR_FILENO);
	exit(2);
}
