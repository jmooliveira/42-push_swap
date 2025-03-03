
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
	int		pivot_value;
	ft_printf("entrou quick_sort_b:\n");
	ft_printf("tamanho da stack_a em quick_sort_b: %d\n", data->size_a);
	ft_printf("tamanho da stack_b em quick_sort_b: %d\n", data->size_b);
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	if (ft_is_rev_sorted(data->stack_b) || data->size_b <= 1)
		return;
	if(data->size_b <= 5)
	{
		ft_printf("antes de entrar em until_five_numbers_b \n");
		ft_until_five_numbers_b(data);
		return;
	}
	if(data->size_b > 5)
	{
		pivot_value = ft_median(data->stack_b, data->size_b);
		ft_partition_b(data, pivot_value);
		ft_quicksort_b(data);
	}
	ft_printf("tamanho da stack_a em quick_sort_b saida: %d\n", data->size_a);
	ft_printf("tamanho da stack_b em quick_sort_b saida: %d\n", data->size_b);
	ft_quicksort(data);
	while(data->size_b > 0)
	{
		ft_pa(data);
		ft_ra(data);
	}
}

void	ft_sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	ft_median(t_stack *stack, int size)
{
	int	*array;
	int	i;
	int	median;

	ft_printf("Size na mediana: %d\n", size); //
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (0);
	i = 0;
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	ft_sort_array(array, size);
	median = array[(size / 2)];
	ft_printf("Posicao mediana: %d\n", (size/2)); //
	ft_printf("Mediana: %d\n", median); //
	free(array);
	return (median);
}

void	ft_quicksort(t_push_swap *data)
{
	int		pivot_value;
	ft_printf("tamanho da stack_a em quick_sort inicio: %d\n", data->size_a);
	ft_printf("tamanho da stack_b em quick_sort inicio: %d\n", data->size_b);
	ft_print_stack(data->stack_b); // VERIFICA OS VALORES EM B
	ft_print_stack(data->stack_a); // VERIFICA OS VALORES EM A
	if (ft_is_sorted(data->stack_a))
		return;
	if(data->size_a <= 5)
	{
		ft_printf("antes de entrar em until_five_numbers\n");
		ft_until_five_numbers(data);
		return;
	}
	if(data->size_a > 5)
	{
		pivot_value = ft_median(data->stack_a, data->size_a); // AJUSTAR
		ft_partition(data, pivot_value);
		ft_quicksort(data);
	}
	ft_printf("tamanho da stack_a em quick_sort saida: %d\n", data->size_a);
	ft_printf("tamanho da stack_b em quick_sort saida: %d\n", data->size_b);
	ft_quicksort_b(data);
	while(data->size_b > 0)
	{
		ft_pa(data);
		// ft_ra(data);
	}
}
