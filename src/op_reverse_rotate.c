/*op_reverse_rotate.c */

#include"push_swap.h"

void	ft_rra(t_push_swap *data)
{
	t_stack	*last;
	t_stack	*s_last;

	if (data->size_a < 2)
		return ;
	last = data->stack_a;
	s_last = NULL;
	while (last->next)
	{
		s_last = last;
		last = last->next;
	}
	s_last->next = NULL;
	last->next = data->stack_a;
	data->stack_a = last;
	ft_printf("rra\n");
}

void	ft_rrb(t_push_swap *data)
{
	t_stack	*last;
	t_stack	*s_last;

	if (data->size_a < 2)
		return ;
	last = data->stack_a;
	s_last = NULL;
	while (last->next)
	{
		s_last = last;
		last = last->next;
	}
	s_last->next = NULL;
	last->next = data->stack_a;
	data->stack_a = last;
	ft_printf("rra\n");
}

void	ft_rrr(t_push_swap *data)
{
	ft_rra(data);
	ft_rrb(data);
	ft_printf("rrr\n");
}