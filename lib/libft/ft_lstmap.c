/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:40:57 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/15 20:56:31 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*n_list;
	t_list	*new_element;

	if (!lst || !f || !del)
		return (NULL);
	n_list = NULL;
	while (lst)
	{
		new_element = ft_lstnew(f(lst->value));
		if (!new_element)
		{
			ft_lstclear(&n_list, del);
			return (NULL);
		}
		ft_lstadd_back(&n_list, new_element);
		lst = lst->next;
	}
	return (n_list);
}
