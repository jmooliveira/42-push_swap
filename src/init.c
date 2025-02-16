#include "push_swap.h"

t_push_swap *ft_init(void)
{
    t_push_swap *data;
    
    data = (t_push_swap *)malloc(sizeof(t_push_swap));
    if(!data)
        return (NULL);
    data->stack_a = NULL;
    data->stack_b = NULL;
    data->size_a = 0;
    data->size_b = 0;
    data->len_stack = 0;
    return (data);
}

void    ft_init_push_swap_strings(char **numbers)
{

}

void    ft_init_push_swap_args(char **av)
{
    
}