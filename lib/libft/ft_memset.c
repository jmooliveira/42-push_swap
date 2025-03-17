/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:12:41 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/13 00:09:49 by jeff             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pt;

	i = 0;
	pt = s;
	while (i < n)
	{
		pt[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	str[255] = "\0";
// 	char	c;
// 	char	d;
// 	size_t	size;

// 	c = '-';
// 	d = '~';
// 	size = 255;
// 	printf("%s\n", str);
// 	ft_memset(str, c, size);
// 	printf("%s\n", str);
// 	memset(str, d, size);
// 	printf("%s\n", str);
// 	return (0);
// }
