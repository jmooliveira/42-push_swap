/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:26:38 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/10 17:05:47 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*push_swap.h*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../lib/includes/libft.h"
# include "../lib/includes/ft_printf.h"

// valgrind --leak-check=full --track-origins=yes ./push_swap 3 2 1

// struct stacks and datas
typedef struct s_stack
{
	int				value;
	int				position;
	int				upper;
	struct s_stack	*target;
	int				price;
	int				cheap;
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

// free_and_error.c
void		ft_free_stack(t_stack **stack);
void		ft_free_split(char **split);
void		ft_error(void);

// push_swap
void		ft_push_swap(t_push_swap *data);

// until_five_numbers
void		ft_until_five_numbers(t_push_swap *data);
void		ft_four_or_five_numbers(t_push_swap *data);
void		ft_three_numbers(t_push_swap *data);
int			ft_min(t_stack *stack);
int			ft_next_min(t_stack *stack, int min);

// utils.c
bool		ft_is_sorted(t_stack *stack);
void		ft_finish_rotation(t_push_swap *data);
t_stack		*ft_last_node(t_stack *stack);
void		ft_section_stack(t_push_swap *data);
t_stack		*ft_node_min(t_stack *stack);

// algorithm.c
void		ft_algorithm(t_push_swap *data);
t_stack		*ft_find_best_cheap(t_push_swap *data);
void		ft_rotate_a(t_push_swap *data, t_stack *best_cheap);
void		ft_rotate_b(t_push_swap *data, t_stack *best_cheap);
void		ft_rotate_both(t_push_swap *data, t_stack *best_cheap);

// sets_1.c
void		ft_set_values(t_push_swap *data);
void		ft_set_cheap(t_push_swap *data);
void		ft_set_target(t_push_swap *data);

// sets_2.c
void		ft_set_position_b(t_push_swap *data);
void		ft_set_position_a(t_push_swap *data);
void		ft_set_price_a(t_push_swap *data);
void		ft_set_price_b(t_push_swap *data);

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

/*SUPORT --------------------------------------------*/
void		ft_print_stack(t_stack *stack);
void		ft_print_position(t_stack *stack);
void		ft_print_upper(t_stack *stack);
void		ft_print_target(t_stack *stack);
void		ft_print_price(t_stack *stack);
void		ft_print_cheap(t_stack *stack);
void		ft_print_price_target(t_stack *stack);

#endif
