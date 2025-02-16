/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:26:38 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/15 20:59:11 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*push_swap.h*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // to remove

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../lib/includes/libft.h"
# include "../lib/includes/ft_printf.h"

//# define SPLIT false
# define FAILLURE_ALLOCATION -1
# define FAILLURE_INVALID_ARGUMENT -2
# define FAILLURE_DUPLICATED_ARGUMENT -3
# define FAILLURE_OUT_OF_RANGE -4

# define FAILLURE_FEW_ARGUMENTS -10

typedef struct s_stack
{
	int	value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;
	int		len_stack;
}	t_push_swap;

// validate
void	ft_validate_string(char **numbers);
bool	ft_validate_number(char *str);
bool	ft_duplicate_numbers(char **numbers);
int		ft_errors(int error);
void	ft_free_split(char **split);
bool	ft_validate_args(char **av, int ac);

//init
void    ft_init_push_swap_strings(char **numbers);
void    ft_init_push_swap_args(char **av);

// operations
void	ft_sa(t_push_swap *data);
void	ft_sb(t_push_swap *data);
void	ft_ss(t_push_swap *data);
void	ft_pa(t_push_swap *data);
void	ft_pb(t_push_swap *data);
void	ft_ra(t_push_swap *data);
void	ft_rb(t_push_swap *data);
void	ft_rr(t_push_swap *data);
void	ft_rra(t_push_swap *data);
void	ft_rrb(t_push_swap *data);
void	ft_rrr(t_push_swap *data);

#endif
