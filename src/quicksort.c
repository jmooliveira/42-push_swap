
/*quicksort.c*/

#include "push_swap.h"

void	ft_partition(t_push_swap *data, int pivot_value)
{
	int	i;
	int	size;

	i = 0;
	size = data->size_a;
	while(i < size)
	{
		if(data->stack_a->value < pivot_value)
			ft_pb(data);
		else
			ft_ra(data);
		i++;
	}
}

void	ft_partition_b(t_push_swap *data, int pivot_value)
{
	int	i;
	int	size;

	i = 0;
	size = data->size_b;
	while(i < size)
	{
		if(data->stack_b->value >= pivot_value)
			ft_pa(data);
		else
			ft_rb(data);
		i++;
	}
}

void	ft_quicksort_b(t_push_swap *data)
{
	t_stack	*pivot;
	int		pivot_value;

	// if (ft_is_sorted(data->stack_b))
	// 	return;
	if (data->size_b <= 1)
		return;
	pivot = data->stack_b;
	pivot_value = pivot->value;
	ft_partition_b(data, pivot_value);
	ft_quicksort(data);
	ft_quicksort_b(data);
	while(data->size_a > 0)
		ft_pb(data);
}

void	ft_quicksort(t_push_swap *data)
{
	t_stack *pivot;
	int		pivot_value;

	if (ft_is_sorted(data->stack_a))
		return;
	if(data->size_a <= 5)
	{
		ft_until_five_numbers(data);
		return;
	}
	pivot = data->stack_a;
	pivot_value = pivot->value;
	ft_partition(data, pivot_value);
	ft_quicksort(data);
	ft_quicksort_b(data);
	while(data->size_b > 0)
		ft_pa(data);
}
