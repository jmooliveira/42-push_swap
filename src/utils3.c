
/* utils3.c */

#include "push_swap.h"

void	ft_rrr(t_push_swap *data);

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d -> ", stack->value);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}