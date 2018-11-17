/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikovalen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:00:57 by ikovalen          #+#    #+#             */
/*   Updated: 2018/10/29 15:06:30 by ikovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	c2;
	size_t			i;

	tmp = (unsigned char *)s;
	c2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == c2)
			return (tmp + i);
		i++;
	}
	return (NULL);
}
