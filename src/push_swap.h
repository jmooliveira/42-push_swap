/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:26:38 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/06 00:39:12 by jeff             ###   ########.fr       */
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

// valgrind --leak-check=full ./push_swap 3 2 1

//# define SPLIT false
# define FAILLURE_ALLOCATION -1
# define FAILLURE_INVALID_ARGUMENT -2
# define FAILLURE_DUPLICATED_ARGUMENT -3
# define FAILLURE_OUT_OF_RANGE -4

# define FAILLURE_FEW_ARGUMENTS -10

// struct stacks and datas
typedef struct s_stack
{
	int				value;
	int				position;
	int				upper;
	int				price;
	int				cheap;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;
}	t_push_swap;

// validates.c
void		ft_validate_string(char **numbers);
bool		ft_validate_number(char *str);
bool		ft_duplicate_numbers(char **numbers);
bool		ft_validate_args(int ac, char **av);

// init
void		ft_init_push_swap_strings(char **numbers);
void		ft_init_push_swap_args(char **av, int ac);
void		add_data_to_stack(t_push_swap *data, int value);
t_push_swap	*ft_init(void);

// free_memory.c
void		ft_stack_free(t_stack **stack);
void		ft_free_split(char **split);

// CHECK
int			ft_errors(int error);
void		ft_print_stack(t_stack *stack);

// push_swap
void		ft_push_swap(t_push_swap *data);
bool		ft_is_sorted(t_stack *stack);
bool		ft_is_rev_sorted(t_stack *stack);
int			ft_next_min(t_stack *stack, int min);
int			ft_min(t_stack *stack);

void		ft_until_five_numbers(t_push_swap *data);
void		ft_four_or_five_numbers(t_push_swap *data);
void		ft_three_numbers(t_push_swap *data);
int			ft_median(t_stack *stack, int size);
// void		ft_three_numbers_b(t_push_swap *data);
// void		ft_four_or_five_numbers_b(t_push_swap *data);
// void		ft_until_five_numbers_b(t_push_swap *data);
void		ft_finish_rotation(t_push_swap *data);

// quicksort
// void		ft_quicksort(t_push_swap *data);
// void		ft_partition(t_push_swap *data, int pivot_value);
// void		ft_quicksort_b(t_push_swap *data);
// void		ft_partition_b(t_push_swap *data, int pivot_value);

// operations
void		ft_sa(t_push_swap *data);
void		ft_sb(t_push_swap *data);
void		ft_ss(t_push_swap *data);
void		ft_pa(t_push_swap *data);
void		ft_pb(t_push_swap *data);
void		ft_ra(t_push_swap *data);
void		ft_rb(t_push_swap *data);
void		ft_rr(t_push_swap *data);
void		ft_rra(t_push_swap *data);
void		ft_rrb(t_push_swap *data);
void		ft_rrr(t_push_swap *data);

#endif
