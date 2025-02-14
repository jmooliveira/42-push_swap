/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:26:38 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/14 17:28:46 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../lib/includes/libft.h"
# include "../lib/includes/ft_printf.h"

# define SPLIT false
# define FAILLURE_ALLOCATION -1
# define FAILLURE_INVALID_ARGUMENT -2
# define FAILLURE_DUPLICATED_ARGUMENT -3

# define FAILLURE_FEW_ARGUMENTS -10

typedef struct s_stack
{
	int	position;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
	int		stack_len;
}	t_push_swap;

//
int		ft_errors(int error);
void	ft_validate(char **numbers);
bool	ft_validate_number(char *str);
void	ft_free_split(char **split);
bool	ft_duplicate_numbers(char **numbers);

#endif
