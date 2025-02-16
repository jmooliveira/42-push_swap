/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:37:49 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/15 20:50:04 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->value);
		temp = temp->next;
	}
}
