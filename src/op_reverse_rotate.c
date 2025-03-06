#include"push_swap.h"

/*op_reverse_rotate.c */

void	ft_rra(t_push_swap *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (data->size_a < 2)
		return;
	last = ft_last_node(data->stack_a);
	if (last->prev)
		last->prev->next = NULL;
	tmp = last;
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
	last = ft_last_node(data->stack_a);
	if (last->prev)
		last->prev->next = NULL;
	tmp = last;
	tmp->prev = NULL;
	tmp->next = data->stack_b;
	data->stack_b->prev = tmp;
	data->stack_b = tmp;;
	ft_printf("rrb\n");
}

void	ft_rrr(t_push_swap *data)
{
	if(data->size_a > 1)
		ft_rra(data);
	if(data->size_b > 1)
		ft_rrb(data);
	ft_printf("rrr\n");
}