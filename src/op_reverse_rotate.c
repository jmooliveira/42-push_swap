#include"push_swap.h"

/*op_reverse_rotate.c */

void	ft_rra(t_push_swap *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (data->size_a < 2)
		return;

	last = data->stack_a;
	while (last->next)
		last = last->next;

	tmp = last;
	last->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = data->stack_a;
	data->stack_a->prev = tmp;
	data->stack_a = tmp;

	ft_printf("rra\n");
}

void	ft_rrb(t_push_swap *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (data->size_b < 2)
		return;

	last = data->stack_b;
	while (last->next)
		last = last->next;

	tmp = last;
	last->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = data->stack_a;
	data->stack_b->prev = tmp;
	data->stack_b = tmp;;
	ft_printf("rrb\n");
}

void	ft_rrr(t_push_swap *data)
{
	ft_rra(data);
	ft_rrb(data);
	ft_printf("rrr\n");
}