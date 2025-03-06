/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:10:49 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/06 14:04:49 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*free_and_error.c*/

#include "push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}

void	ft_stack_free(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

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
	// DELETE THIS FUNCTION. USE JUST ERROR RETURN
}
