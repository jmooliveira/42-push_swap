#include "push_swap.h"

bool	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (true);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	ft_is_rev_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (true);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	ft_finish_rotation(t_push_swap *data)
{
	int	min;
	t_stack		*nav;
	
	min = INT_MAX;
	nav = data->stack_a;
	while (nav)
	{
		if (nav->value < min)
			min = nav->value;
		nav = nav->next;
	}
	while (data->stack_a->value != min)
	{
		ft_ra(data);
	}
}

void	ft_print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	ft_printf("Stack (frente): ");
	while (stack)
	{
		ft_printf("%d -> ", stack->value);
		stack = stack->next;
	}
	ft_printf("NULL\n");
	tmp = stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	ft_printf("Stack (trás): ");
	while (tmp)
	{
		ft_printf("%d -> ", tmp->value);
		tmp = tmp->prev;
	}
	ft_printf("NULL\n");
}
