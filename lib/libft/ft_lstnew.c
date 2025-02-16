/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:36:33 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/15 19:21:33 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *) ft_calloc (1, sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}
